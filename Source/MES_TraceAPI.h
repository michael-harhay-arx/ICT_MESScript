#pragma once

#ifdef __cplusplus
extern "C" {
#endif

// Define MESLIB_API based on build configuration
#if defined(_WIN32) && defined(MES_TRACE_API_DLL)
    #ifdef MES_TRACE_API_EXPORTS
        #define MESLIB_API __declspec(dllexport)
    #else
        #define MESLIB_API __declspec(dllimport)
    #endif
#else
    #define MESLIB_API
#endif

#include <string>

// Error codes
enum MES_STATUS 
{
    MES_OK = 0,
    MES_ERROR = -1,
    MES_INVALID_PARAM = -2,
    MES_DB_CONNECTION_FAILED = -3,
    MES_DB_QUERY_FAILED = -4
};

enum MES_AssemblyMethod
{
    None,
    Manual,
    Reflow,
    PNP
};

// Struct to hold stage result
typedef struct StageResult {
    int                 stage;
    int                 pcbID;
    bool                pass;
    char                opName[64];
    MES_AssemblyMethod  assemblyMethod;
    unsigned long       elapsedTimeTicks;
} StageResult;

MESLIB_API MES_STATUS MES_Connect(const char* connectionString);
MESLIB_API MES_STATUS MES_GetPCBStatus(const char* pcbBarcode, char *pcbStatus);
MESLIB_API MES_STATUS MES_AddStageResult(StageResult* result);
MESLIB_API void MES_Disconnect();

#ifdef __cplusplus
} // extern "C"
#endif

