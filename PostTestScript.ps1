# Author: Michael Harhay
# Copyright: Arxtron Technologies Inc.. All Rights Reserved.
# Date: 2025/10/30
# Description: This script automates ICT's MES testing/QC process.


# ----------------------- Setup ----------------------- #



# ------------------ Main Execution ------------------- #


Write-Host "======== ICT MES Automation ========"


# 1. Ask user for PCB serial number
$serialNum = ""
while ($serialNum -eq "")
{
    $serialNum = Read-Host "`nPlease input PCB serial number (e.g. A0129-0017): "
}


# 2. Get test result, upload corresponding result to MES
$testPassed = ""
while ($testPassed -ne "n" -and $testPassed -ne "y")
{
    $testPassed = Read-Host "`nDid the PCB pass all tests? [y/n]"
}
if ($testPassed -eq "y")
{
    Write-Host "Passed." -ForegroundColor Green
}
else
{
    Write-Host "Failed." -ForegroundColor Red
}