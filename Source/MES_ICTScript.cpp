#include <iostream>
#include <windows.h>
#include "MES_TraceAPI.h"
#include <string>

#define ERR_CHK(status, msg)\
    if (status != MES_OK)\
    {\
        std::cout << msg;\
        return 0;\
    }

int main()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); // Blue
    std::cout << "\n=============== ICT MES Automation ===============\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // White
    
    // 1. Get operator name
    char operatorName[64] = "";
    std::cout << "\nPlease enter your name (e.g. Firstname Lastname): ";
    std::cin.getline(operatorName, 64);

    // 2. Get PCB serial number
    std::string serialNum = "";
    std::string confirm = "";

    while (confirm != "y")
    {
        std::cout << "\nPlease input PCB serial number (e.g. A0129-0017): ";
        std::cin >> serialNum;
        std::cout << "Confirm serial number: \"" << serialNum << "\" [y/n] ";
        std::cin >> confirm;
    }
    
    // 3. Get test result
    std::string testPass = "";
    
    while (testPass != "y" && testPass != "n")
    {
        std::cout << "\nDid the PCB pass all tests? [y/n] ";
        std::cin >> testPass;
    }
    
    if (testPass == "y")
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // Green
        std::cout << "Test result is: Pass";
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // Red
        std::cout << "Test result is: Fail";
    }

    // 4. Find corresponding PCBInstance_ID, given barcode
    int pcbID = 124;
    


    // 5. Connect to MES database
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cout << "\n\nUploading result to MES...\n";

    MES_STATUS status = MES_OK;
    std::string connStr =
       "Driver={ODBC Driver 17 for SQL Server};"
       "Server=SERVER4\\SQLEXPRESS;"
       "Database=RD25001_DEV;"
       "Trusted_Connection=Yes;"
       "TrustServerCertificate=Yes;";

    status = MES_Connect(connStr.c_str());
    ERR_CHK(status, "Failed to connect to database.\n");

    // 6. Upload result and check status
    StageResult result;
    result.pcbID = pcbID;
    result.stage = 5;
    result.pass = true;
    strcpy(result.opName, operatorName);
    result.assemblyMethod = None;
    result.elapsedTimeTicks = 0;

    status = MES_AddStageResult(&result);
    ERR_CHK(status, "Failed to add result to database.\n");

    // Get PCB status
    // char pcbStatus[64] = {0};
    // status = MES_GetPCBStatus("TEST-0003", pcbStatus);
    // ERR_CHK(status, "Failed to get status.\n")
    // std::cout << "PCB status: ";
    // std::cout << pcbStatus <<std::endl;

    MES_Disconnect();
    

    // 7. Clean up
    std::cout << "\n\nScript complete. Press Enter to exit...";
    std::cin.clear();
    std::cin.sync();
    std::cin.get();
    return 0;
}
