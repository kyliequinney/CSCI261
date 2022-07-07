For this lab, your tasks are as follows.  Provide the answers after each number.  Show your work for each step.

1a. Convert the decimal number 1,904,803,840 to 32-bit two's complement binary representation.
in binary:
1110001100010010000000000000000
swaped 1s and 0s to make 2s complement
01110001100010010000000000000000

1b. Represent the value in hexadecimal. 
Using the binary to convert to hex...
Last four: 0000 = 0
next four: 0000 = 0
next four: 0000 = 0
next four: 0000 = 0
next four: 1001 = 9
next four: 1000 = 8
next four: 0001 = 1
next four: 0111 = 7
listed in proper order:
71890000

2a. Convert the decimal number -1,047,986,176 to 32-bit two's complement binary representation.
in binary: 00111110011101110000000000000000
flipped 1s and 0s for 2s complement:
11000001100010010000000000000000

2b. Represent the value in hexadecimal.
Last four: 0000 = 0
next four: 0000 = 0
next four: 0000 = 0
next four: 0000 = 0
next four: 0111 = 7
next four: 0111 = 7
next four: 1110 = 14 = E
next four: 0011 = 3
In proper order:
3E770000

3a. Convert the decimal number 17.125 to 32-bit floating point precsision.
first bit is 0 bc it is positive
nect eight bits are the exponent which is subtracted from the bias
remaining bits are the mantissa
0 10000011 00010010000000000000000

3b. Represent the value in hexadecimal.
binary: 10001.0010
after decimal: 001 = 2
last four before the decimal: 0001 = 1
next: 0001 = 1 
11.2

4a. Convert the decimal number -17.125 to 32-bit floating point precision.
first bit is a one bc it is negative
next eight bits are the exponent subtracted from the bias
rest of the bits are the mantissa
1 10000011 00010010000000000000000 

4b. Represent the value in hexadecimal.
same as the positive value but with a negative sign
-11.2

5a. Convert the hexadecimal value 0xC3890000 to binary.
C= 1100
3= 0011
8= 1000
9= 1001
0= 0000
0= 0000
0= 0000
0= 0000
11000011100010010000000000000000

5b. Convert the binary to a signed decimal integer value using two's complement.
first bit = -2147483648
next add 1073741824 + 33554432 + 16777216 + 8388608 + 524288 + 65536
1133051904 - 2147483648 =
-1014431744

5c. Convert the binary to a floating point decimal value.
11000011100010010000000000000000 in decimal is 3280535552
which is 3.280535552x10^9 as a floating point decimal

6.  Using a terminal, perform the following steps.  List the commands used to perform the tasks:

- print the current directory you are in when the terminal opens
pwd

- move into the lab1b_folder directory
cd lab1b_folder

- list the contents of the directory
ls

- move into the data directory
cd data

- rename the misspelled file fil2.txt to be file2.txt
mv fil2.txt file2.txt

- copy file1.txt to be file3.txt
cp file1.txt file3.txt

- make a new file named file4.txt
ni file4.txt

- move to the parent directory
cd ..

- make a directory named bin
mkdir bin

- compile main.cpp into an executable
g++ main.cpp

- move the generated executable into the bin folder and rename it to be lab1b
mv main.cpp Z:\SET1\bin
mv main.cpp lab1b

- print the current directory you are currently in
pwd

- run the new executable from your current directory
.\a.exe

What to submit?
Submit this README.txt with the completed responses.
