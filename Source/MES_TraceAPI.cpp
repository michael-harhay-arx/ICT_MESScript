#include "pch.h"

// These defines ensure we export the symbols when building the DLL
#define MES_TRACE_API_EXPORTS
#define MES_TRACE_API_DLL

#include "MES_TraceAPI.h"
#include "DatabaseManager.h"

DatabaseManager dbManager; // Global instance to maintain the connection

MES_STATUS MES_Connect(const char* connectionString)
{
    try 
    {
        if (!connectionString || strlen(connectionString) == 0) 
        {
            return MES_INVALID_PARAM; // Invalid parameter
        }

        bool connected = dbManager.connect(connectionString);
        return connected ? MES_OK : MES_DB_CONNECTION_FAILED;
    }
    catch (const std::exception& e) 
    {
        // Log the error if needed, and return error code
        return MES_DB_CONNECTION_FAILED;
    }
}

MES_STATUS MES_GetPCBStatus(const char* pcbBarcode, char* pcbStatus)
{
    try 
    {
        if (!pcbBarcode || !pcbStatus) 
        {
            return MES_INVALID_PARAM;
        }

        std::string status = dbManager.getPCBStatus(pcbBarcode);
        if (status == "Error") 
        {
            return MES_DB_QUERY_FAILED;
        }

        strcpy_s(pcbStatus, 32, status.c_str());
        return MES_OK;
    }
    catch (const std::exception& e) 
    {
        return MES_DB_QUERY_FAILED;
    }
}

MES_STATUS MES_AddStageResult(StageResult* result)
{
    try 
    {
        if (!result) 
        {
            return MES_INVALID_PARAM;
        }

        bool success = dbManager.addStageResult(*result);
        return success ? MES_OK : MES_DB_QUERY_FAILED;
    }
    catch (const std::exception& e) 
    {
        return MES_DB_QUERY_FAILED; 
    }
}

void MES_Disconnect()
{
    try 
    {
        dbManager.disconnect();
    }
    catch (const std::exception& e) 
    {
        // Ignore disconnect errors
    }
}
