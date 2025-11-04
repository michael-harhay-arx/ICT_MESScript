#include <iostream>
#include <windows.h>
#include "MES_TraceAPI.h"

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
    
    // 1. Get PCB serial number
    std::string serialNum = "";
    std::string confirm = "";

    while (confirm != "y")
    {
        std::cout << "\nPlease input PCB serial number (e.g. A0129-0017): ";
        std::cin >> serialNum;
        std::cout << "Confirm serial number: \"" << serialNum << "\" [y/n] ";
        std::cin >> confirm;
    }
    
    // 2. Get test result
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

    // 3. Upload result to MES
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cout << "\n\nUploading result to MES...";

    MES_STATUS status = MES_OK;
    std::string connStr =
       "Driver={ODBC Driver 17 for SQL Server};"
       "Server=SERVER4\\SQLEXPRESS;"
       "Database=RD25001_DEV;"
       "Trusted_Connection=Yes;"
       "TrustServerCertificate=Yes;";

    status = MES_Connect(connStr.c_str());
    ERR_CHK(status, "Failed to connect to database.")

    // char pcbStatus[64] = {0};
    // status = MES_GetPCBStatus("TEST-0001", pcbStatus);
    // ERR_CHK(status, "Failed to get status.")

    MES_Disconnect();
    
    Sleep(3000);
    return 0;
}
