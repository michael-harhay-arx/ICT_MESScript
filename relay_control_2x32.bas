!!!!    4    0    1 1751988484   0000                                         
dim RelayControl(15)
buffered reporting off|report is "/dev/tty"
load board
vacuum well a is 2,3
faon
powered  | cps
sps 5, 5 , 2 | rps 5, A,B | print A, B!|sps 5, 0, 2
wait 5

for X = 1 to 2
!**************************************************************
!!!!!!!!!!!KKKKKKKK        !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!!!!!!00000000                 FE RELAY CONTROL (K5 ON)
!!!!!!!!!!!87654321        !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
RLYMAP$ = "0000000100000000"
for I = 0 to 15  | RelayControl(I) = val(RLYMAP$[I+1;1])| next I
test "digital/relay_control_0"; RelayControl(*)

wait 7
RLYMAP$ = "0000001000000000"
for I = 0 to 15  | RelayControl(I) = val(RLYMAP$[I+1;1])| next I
test "digital/relay_control_0"; RelayControl(*)
rps 7, A,B
wait 7
RLYMAP$ = "0000010000000000"
for I = 0 to 15  | RelayControl(I) = val(RLYMAP$[I+1;1])| next I
test "digital/relay_control_0"; RelayControl(*)
rps 7, A,B
wait 7
RLYMAP$ = "0000100000000000"
for I = 0 to 15  | RelayControl(I) = val(RLYMAP$[I+1;1])| next I
test "digital/relay_control_0"; RelayControl(*)
rps 7, A,B
wait 7
RLYMAP$ = "0001000000000000"
for I = 0 to 15  | RelayControl(I) = val(RLYMAP$[I+1;1])| next I
test "digital/relay_control_0"; RelayControl(*)
rps 7, A,B
wait 7
RLYMAP$ = "0010000000000000"
for I = 0 to 15  | RelayControl(I) = val(RLYMAP$[I+1;1])| next I
test "digital/relay_control_0"; RelayControl(*)
rps 7, A,B
wait 7
RLYMAP$ = "0100000000000000"
for I = 0 to 15  | RelayControl(I) = val(RLYMAP$[I+1;1])| next I
test "digital/relay_control_0"; RelayControl(*)
rps 7, A,B
wait 7
RLYMAP$ = "10000000000000000"
for I = 0 to 15  | RelayControl(I) = val(RLYMAP$[I+1;1])| next I
test "digital/relay_control_0"; RelayControl(*)
rps 7, A,B
wait 7

RLYMAP$ = "0000000000000001"
for I = 0 to 15  | RelayControl(I) = val(RLYMAP$[I+1;1])| next I
test "digital/relay_control_0"; RelayControl(*)
rps 7, A,B
wait 7
RLYMAP$ = "0000000000000010"
for I = 0 to 15  | RelayControl(I) = val(RLYMAP$[I+1;1])| next I
test "digital/relay_control_0"; RelayControl(*)
rps 7, A,B
wait 7
RLYMAP$ = "0000000000000100"
for I = 0 to 15  | RelayControl(I) = val(RLYMAP$[I+1;1])| next I
test "digital/relay_control_0"; RelayControl(*)
rps 7, A,B
wait 7
RLYMAP$ = "0000000000001000"
for I = 0 to 15  | RelayControl(I) = val(RLYMAP$[I+1;1])| next I
test "digital/relay_control_0"; RelayControl(*)
rps 7, A,B
wait 7
RLYMAP$ = "0000000000010000"
for I = 0 to 15  | RelayControl(I) = val(RLYMAP$[I+1;1])| next I
test "digital/relay_control_0"; RelayControl(*)
rps 7, A,B
wait 7
RLYMAP$ = "0000000000100000"
for I = 0 to 15  | RelayControl(I) = val(RLYMAP$[I+1;1])| next I
test "digital/relay_control_0"; RelayControl(*)
rps 7, A,B
wait 7
RLYMAP$ = "0000000001000000"
for I = 0 to 15  | RelayControl(I) = val(RLYMAP$[I+1;1])| next I
test "digital/relay_control_0"; RelayControl(*)
rps 7, A,B
wait 7
RLYMAP$ = "0000000010000000"
for I = 0 to 15  | RelayControl(I) = val(RLYMAP$[I+1;1])| next I
test "digital/relay_control_0"; RelayControl(*)
rps 7, A,B
wait 7
RLYMAP$ = "0000000000000000"
for I = 0 to 15  | RelayControl(I) = val(RLYMAP$[I+1;1])| next I
test "digital/relay_control_0"; RelayControl(*)
rps 7, A,B
wait 2
!**************************************************************
!!!!!!!!!!!KKKKKKKK        !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!!!!!!00000000                 FE RELAY CONTROL (K5 ON)
!!!!!!!!!!!87654321        !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
RLYMAP$ = "0000000100000000"
for I = 0 to 15  | RelayControl(I) = val(RLYMAP$[I+1;1])| next I
test "digital/relay_control_1"; RelayControl(*)

wait 7
RLYMAP$ = "0000001000000000"
for I = 0 to 15  | RelayControl(I) = val(RLYMAP$[I+1;1])| next I
test "digital/relay_control_1"; RelayControl(*)
rps 7, A,B
wait 7
RLYMAP$ = "0000010000000000"
for I = 0 to 15  | RelayControl(I) = val(RLYMAP$[I+1;1])| next I
test "digital/relay_control_1"; RelayControl(*)
rps 7, A,B
wait 7
RLYMAP$ = "0000100000000000"
for I = 0 to 15  | RelayControl(I) = val(RLYMAP$[I+1;1])| next I
test "digital/relay_control_1"; RelayControl(*)
rps 7, A,B
wait 7
RLYMAP$ = "0001000000000000"
for I = 0 to 15  | RelayControl(I) = val(RLYMAP$[I+1;1])| next I
test "digital/relay_control_1"; RelayControl(*)
rps 7, A,B
wait 7
RLYMAP$ = "0010000000000000"
for I = 0 to 15  | RelayControl(I) = val(RLYMAP$[I+1;1])| next I
test "digital/relay_control_1"; RelayControl(*)
rps 7, A,B
wait 7
RLYMAP$ = "0100000000000000"
for I = 0 to 15  | RelayControl(I) = val(RLYMAP$[I+1;1])| next I
test "digital/relay_control_1"; RelayControl(*)
rps 7, A,B
wait 7
RLYMAP$ = "10000000000000000"
for I = 0 to 15  | RelayControl(I) = val(RLYMAP$[I+1;1])| next I
test "digital/relay_control_1"; RelayControl(*)
rps 7, A,B
wait 7

RLYMAP$ = "0000000000000001"
for I = 0 to 15  | RelayControl(I) = val(RLYMAP$[I+1;1])| next I
test "digital/relay_control_1"; RelayControl(*)
rps 7, A,B
wait 7
RLYMAP$ = "0000000000000010"
for I = 0 to 15  | RelayControl(I) = val(RLYMAP$[I+1;1])| next I
test "digital/relay_control_1"; RelayControl(*)
rps 7, A,B
wait 7
RLYMAP$ = "0000000000000100"
for I = 0 to 15  | RelayControl(I) = val(RLYMAP$[I+1;1])| next I
test "digital/relay_control_1"; RelayControl(*)
rps 7, A,B
wait 7
RLYMAP$ = "0000000000001000"
for I = 0 to 15  | RelayControl(I) = val(RLYMAP$[I+1;1])| next I
test "digital/relay_control_1"; RelayControl(*)
rps 7, A,B
wait 7
RLYMAP$ = "0000000000010000"
for I = 0 to 15  | RelayControl(I) = val(RLYMAP$[I+1;1])| next I
test "digital/relay_control_1"; RelayControl(*)
rps 7, A,B
wait 7
RLYMAP$ = "0000000000100000"
for I = 0 to 15  | RelayControl(I) = val(RLYMAP$[I+1;1])| next I
test "digital/relay_control_1"; RelayControl(*)
rps 7, A,B
wait 7
RLYMAP$ = "0000000001000000"
for I = 0 to 15  | RelayControl(I) = val(RLYMAP$[I+1;1])| next I
test "digital/relay_control_1"; RelayControl(*)
rps 7, A,B
wait 7
RLYMAP$ = "0000000010000000"
for I = 0 to 15  | RelayControl(I) = val(RLYMAP$[I+1;1])| next I
test "digital/relay_control_1"; RelayControl(*)
rps 7, A,B
wait 7
RLYMAP$ = "0000000000000000"
for I = 0 to 15  | RelayControl(I) = val(RLYMAP$[I+1;1])| next I
test "digital/relay_control_1"; RelayControl(*)
rps 7, A,B
wait 7

next X

