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