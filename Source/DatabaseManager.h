#pragma once

#include "pch.h"

#include "MES_TraceAPI.h"
#include <sql.h>
#include <sqlext.h>

class DatabaseManager {
private:
    SQLHENV hEnv = nullptr;
    SQLHDBC hDbc = nullptr;
    std::string connectionString;

public:
    DatabaseManager();
    ~DatabaseManager();

    bool connect(const std::string& connStr);
    void disconnect();
    
    /* Station API */
    std::string getPCBStatus(const std::string& pcbBarcode) const;
    int getPCBInstanceID(std::string serialNum) const;
    bool addStageResult(const StageResult& result) const;

    /* General API */
    // TODO
};