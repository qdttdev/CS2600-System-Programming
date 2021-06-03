# CS2600 System Programming
### Homework 1 implemented in C
[HW_1](https://github.com/qdttdev/CS2600_System_Programming/tree/main/HW_1) is a program that plays the game Nim. Two players take turns removing marbles from the pile of 10-100 marbles, whoever takes the last marble loses.

### Homework 2 implemented in C
[HW_2](https://github.com/qdttdev/CS2600_System_Programming/tree/main/HW_2) is a sorting program. I implemented 5 sorting algorithms including Bubble Sort, Insertion Sort, Merge Sort, Quick Sort, and Selection Sort to sort this input file by a user-chosen column:
```
Sam, 15, banana
Julie, 23, grape
Scott, 12, kiwi
Lumi, 1, pumpkin
Caroline, 22, durian
```

### Homework 3 implemented in Shell Script Bash
[HW_3](https://github.com/qdttdev/CS2600_System_Programming/tree/main/HW_3) is a program that does exactly what Cal utility in Unix does. It can take different alternative inputs of dates such as: `5 2021` or `May 21`.

Sample run:
```
qdttdev@DESKTOP-3LNQCIN:~$ ./cal.sh Jun 21
        June, 2021
 Su Mo Tu We Th Fr Sa
        1  2  3  4  5
  6  7  8  9 10 11 12
 13 14 15 16 17 18 19
 20 21 22 23 24 25 26
 27 28 29 30
```

### Homework 4 implemented in Shell Script Bash
[HW_4](https://github.com/qdttdev/CS2600_System_Programming/tree/main/HW_4) is a simple program to practice the `mov` command. It focuses on the use of command line parameters and the understanding of if-else statements, as well as familiarizing with the shell script syntax.

Sample run:
```
qdttdev@DESKTOP-3LNQCIN:~$ ./move.sh src.txt des.txt
src.txt does not exist, please try again
qdttdev@DESKTOP-3LNQCIN:~$ touch src.txt
qdttdev@DESKTOP-3LNQCIN:~$ ./move.sh src.txt des.txt
move src.txt des.txt is performed successfully
qdttdev@DESKTOP-3LNQCIN:~$ ls
cal.sh  des.txt  des.txt.1  des.txt.2  des.txt.3  des.txt.4  move.sh
```
