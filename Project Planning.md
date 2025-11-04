**ICT MES Automation Script**



**Background Info:**

* ICT runs a .bas file (Basic script) to test their PCBs
* They then go to MES to pass PCB, but Auto Sequence test requires Admin access to pass



**Goal:**

* Streamline test logging MES procedure for ICT, reduce workload for admin



**Features:**

* A .exe script will be called from the end of the .bas file (using command: execute "powershell scriptname.exe")
* The .exe should:

 	1. Ask the user to input the SN# (e.g. A0129-0017)

 	2. Confirm that the number is correct (prompt user, since once it's 		   input it's annoying to undo)

 	3. Ask user whether test passed or not. If failed, ask if user wants to 	   retry, and restart .bas if yes.

 	4. If test passed, utilize MES\_TraceAPI to update MES database step 5





**New notes from Marina/Alessandro:**

* Want to ask at beginning of test whether failed or not



**Compile command (WORKING):**

g++ -static -static-libgcc -static-libstdc++ -I "C:\\vcpkg\\installed\\x64-mingw-static\\include" -L "C:\\vcpkg\\installed\\x64-mingw-static\\lib" .\\DatabaseManager.cpp .\\MES\_TraceAPI.cpp .\\MES\_ICTScript.cpp -lfmt -lodbc32 -o MES\_ICTScript.exe

