Compile the code with the build script 
```
chmod +x ./build.sh
./build.sh
```

It will create a executable with name executable

```
./executable
```

Place the input in input.txt
Obtain the output and errors in output.txt

Several Line should be in this format

```
begin process p1
recv p1 m1
send (p1,p2,p3,p4) m2 // no space between process name and , 
end process // no process name at last
```

And Also No blank line in between two process

Sample Input 1 // Deadlocked
```
begin process p1
recv p2 m2
send (p2) m1
end process
begin process p2
recv p1 m1
send (p1) m2
end process
```
Sample Output 1
```
Started Parsing
Parsing Completes
These processes are in deadlocked:
p1 waiting for p2
p2 waiting for p1
Execution Failed Contain DeadLock Or Some Message Received Which is Never Sent
```

Sample Input 2 // Non Deadlocked
```
begin process p1
send (p2) m1
recv p2 m2
send (p3) m3
end process
begin process p2
print x1
print x2
print x3
print x4
recv p1 m1
send (p1) m2
print x3
recv p3 m4
end process
begin process p3
recv p1 m3
print x1
send (p2) m4
end process
```
Sample Output 2
```
Started Parsing
Parsing Completes
ProcessName: p1 ClockValue: 1 MsgSent: m1 ToTheProcess: {p2,}
ProcessName: p2 ClockValue: 1 PrintingMsg: x1
ProcessName: p2 ClockValue: 2 PrintingMsg: x2
ProcessName: p2 ClockValue: 3 PrintingMsg: x3
ProcessName: p2 ClockValue: 4 PrintingMsg: x4
ProcessName: p2 ClockValue: 5 MsgReceived m1 FromProcess: p1
ProcessName: p2 ClockValue: 6 MsgSent: m2 ToTheProcess: {p1,}
ProcessName: p1 ClockValue: 7 MsgReceived m2 FromProcess: p2
ProcessName: p1 ClockValue: 8 MsgSent: m3 ToTheProcess: {p3,}
ProcessName: p3 ClockValue: 9 MsgReceived m3 FromProcess: p1
ProcessName: p2 ClockValue: 7 PrintingMsg: x3
ProcessName: p3 ClockValue: 10 PrintingMsg: x1
ProcessName: p3 ClockValue: 11 MsgSent: m4 ToTheProcess: {p2,}
ProcessName: p2 ClockValue: 12 MsgReceived m4 FromProcess: p3
```
