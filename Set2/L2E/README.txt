
Run the executable through the debugger.  Perform the following steps.  For each step, add the command that performs that task.

1a. Add a breakpoint inside the print_result() function.
b calculator_functions.cpp : 14

1b. What different in how we need to specify the breakpoint compared to L2D?
we have to specify the calculator_functions.cpp file and extension

2. Run the program, requesting to add 4 and 5
run
4 5
A

3a. Print the stack trace
bt

3b. What's different in how the stack trace is formed compared to L2D?
XXXXXXXXXXXXXXXXXXXX

4. Print the current stack frame
frame

5. Print all local variables and arguments within the scope of the current stack frame
info locals

6. Move up one level in the stack frame
up

7. Print all local variables and arguments within the scope of the current stack frame
info locals

8. Continue the program, requesting to subtract the values
run
4 5
S

9. Print the stack trace again
bt

10. Step through the program until we have moved out of the two lower stack frames
step

11. Print the stack trace again
bt

12. Kill the program
kill