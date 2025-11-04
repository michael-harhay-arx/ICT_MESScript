#include "pch.h"
#include "DatabaseManager.h"
#include <iostream>
#include <sqltypes.h>

DatabaseManager::DatabaseManager() {}

DatabaseManager::~DatabaseManager() {
    disconnect();
}

static void printSqlError(SQLSMALLINT handleType, SQLHANDLE handle)
{
    SQLCHAR sqlState[6] = {};
    SQLCHAR message[SQL_MAX_MESSAGE_LENGTH] = {};
    SQLINTEGER nativeError = 0;
    SQLSMALLINT textLength = 0;

    SQLRETURN ret;
    int i = 1;

    while ((ret = SQLGetDiagRecA(handleType, handle, i, sqlState, &nativeError,
        message, sizeof(message), &textLength)) != SQL_NO_DATA)
    {
        if (textLength == 0) break;

        std::cerr << "ODBC Error [" << sqlState << "] Native Error: "
            << nativeError << ", Message: " << message << std::endl;
        ++i;
    }
}

bool DatabaseManager::connect(const std::string& connStr) 
{
    connectionString = connStr;

    // Allocate environment handle
    ERR_CHK(SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv) != SQL_SUCCESS, "Failed to allocate ODBC environment handle.\n");

    // Set the ODBC version environment attribute
    SQLRETURN status = SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0);

    // Allocate connection handle
    ERR_CHK(SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc), "Failed to allocate ODBC connection handle.\n");

    // Connect to SQL Server
    SQLCHAR outConnStr[1024];
    SQLSMALLINT outConnStrLen;

    SQLRETURN ret = SQLDriverConnectA(
        hDbc,
        NULL,
        (SQLCHAR*)connStr.c_str(),
        SQL_NTS,
        outConnStr,
        sizeof(outConnStr),
        &outConnStrLen,
        SQL_DRIVER_NOPROMPT
    );

    if (!SQL_SUCCEEDED(ret))
    {
        std::cerr << "SQLDriverConnectA failed.\n";
        printSqlError(SQL_HANDLE_DBC, hDbc);
        return false;
    }
    std::cout << "Connected to SQL Server database.\n";
    return true;
}

std::string DatabaseManager::getPCBStatus(const std::string& pcbBarcode) const 
{
    SQLHSTMT hStmt = nullptr;
    std::string resultStr = "Error";
    SQLCHAR buffer[256] = {};

    SQLRETURN ret = SQL_ERROR;

    ret = SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt);
    if (!SQL_SUCCEEDED(ret))
    {
        std::cerr << "Failed to allocate statement handle";
        return resultStr;
    }

    const char* sql = "SELECT [OverallResult] FROM [MES].[OverallResults] WHERE Barcode = ?";
    ret = SQLPrepareA(hStmt, (SQLCHAR*)sql, SQL_NTS);
    if (!SQL_SUCCEEDED(ret))
    {
        std::cerr << "Failed to prepare SQL query";
        return resultStr;
    }

    const char* temp = pcbBarcode.c_str();
    ret = SQLBindParameter(hStmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 255, 0,
        (SQLPOINTER)temp, pcbBarcode.size(), NULL);
    if (!SQL_SUCCEEDED(ret))
    {
        std::cerr << "Failed to bind parameter";
        return resultStr;
    }

    ret = SQLExecute(hStmt);
    if (!SQL_SUCCEEDED(ret))
    {
        std::cerr << "SQLExecute failed.\n";
        return resultStr;
    }

    ret = SQLFetch(hStmt);
    if (SQL_SUCCEEDED(ret))
    {
        ERR_CHK(SQLGetData(hStmt, 1, SQL_C_CHAR, buffer, sizeof(buffer), NULL), "Failed to get data");
        resultStr = reinterpret_cast<char*>(buffer);
    }
    else
    {
        printSqlError(SQL_HANDLE_DBC, hStmt);
    }

    SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
    return resultStr;
}


bool DatabaseManager::addStageResult(const StageResult& result) const 
{
    SQLHSTMT hStmt;

    ERR_CHK(SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt), "Failed to allocate statement handle");

    const char* sql = "INSERT INTO [MES].[StageResult] (PCBInstance_ID, Stage, Result, Operator, AsseblyMethod, ElapsedTimeTicks) VALUES (?, ?, ?, ?, ?, ?)";
    ERR_CHK(SQLPrepareA(hStmt, (SQLCHAR*)sql, SQL_NTS), "Failed to prepare SQL query");
    
    ERR_CHK(SQLBindParameter(hStmt, 1, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 0, 0,
        (SQLPOINTER)&result.pcbID, 0, NULL),
        "Failed to bind pcbID parameter");

    ERR_CHK(SQLBindParameter(hStmt, 2, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 0, 0,
        (SQLPOINTER)&result.stage, 0, NULL),
        "Failed to bind stage parameter");

    std::string resultStr = result.pass ? "PASS" : "FAIL";
    ERR_CHK(SQLBindParameter(hStmt, 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 255, 0,
        (SQLPOINTER)resultStr.c_str(), 0, NULL),
        "Failed to bind result parameter");

    // TODO operator, assembly method, timeticks

    bool success = (SQLExecute(hStmt) == SQL_SUCCESS);

    SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
    return success;
}

void DatabaseManager::disconnect() 
{
    if (hDbc) 
    {
        ERR_CHK(SQLDisconnect(hDbc), "Failed to disconnect from SQL Server");
        ERR_CHK(SQLFreeHandle(SQL_HANDLE_DBC, hDbc), "Failed to free database handle");
        hDbc = nullptr;
    }
    if (hEnv) 
    {
        ERR_CHK(SQLFreeHandle(SQL_HANDLE_ENV, hEnv), "Failed to free environment handle");
        hEnv = nullptr;
    }
    std::cout << "Disconnected from SQL Server database.\n";
}
