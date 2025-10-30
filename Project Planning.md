**ICT MES Automation Script**



**Background Info:**

* ICT runs a .bas file (Basic script) to test their PCBs
* They then go to MES to pass PCB, but Auto Sequence test requires Admin access to pass



**Goal:**

* Streamline test logging MES procedure for ICT, reduce workload for admin



**Features:**

* A .bat script that is called from the end of the .bas file
* The .bat script should:

&nbsp;	1. Ask the user to input the SN# (e.g. A0129-0017)

&nbsp;	2. Confirm that the number is correct (prompt user, since once it's 		   input it's annoying to undo)

&nbsp;	3. Ask user whether test passed or not. If failed, ask if user wants to 	   retry, and restart .bas if yes.

&nbsp;	4. If test passed, utilize MES\_TraceAPI to update MES database step 5

