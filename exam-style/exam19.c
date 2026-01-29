/*
EXAM 01 – Programming in C

Implement the following functions and a main program.


A function that:

* receives as input a character array;
* asks the user to *“enter a string”* and stores the input into the array;
* the string must:

  * contain at least 4 characters;
  * consist only of uppercase letters (A–Z);
  * start and end with a vowel.
* If the string does not satisfy the requirements, it prints
  **“ERROR: the string does not meet the constraints”**.
* The request is repeated until the string is valid, with a maximum of **3 attempts**.
* The function returns **1** if a valid string is eventually entered, otherwise **0**.

Example of valid strings:
`EVA`, `ANNA`, `ELENA`, `OTTORE`, `ULISSE`, `ALESSIO`

---

A function that:

* receives a string as input;
* prints the indices and the corresponding characters of the string, formatted as shown in the example below;
* returns the total number of characters in the string.

Example output:

```
0: A
1: L
2: E
3: S
4: S
5: I
6: O
```

Example:

```
string: ALESSIO
-->
7 characters
```

---

A function that, using pointers and pointer arithmetic:

* receives a string and two output parameters (`minChar`, `maxChar`);
* stores in `minChar` the alphabetically smallest character in the string;
* stores in `maxChar` the alphabetically largest character in the string;
* does not return any value.

Examples:

```
string: ALESSIO  -->  minChar: A   maxChar: S
string: ULISSE   -->  minChar: E   maxChar: U
```

---

A function that:

* receives a string and a file name;
* writes all the vowels found in the string to the file, separated by commas;
* closes the file;
* returns the total number of characters written to the file (commas included).

Example:

```
string: ALESSIO
-->
file content: A,E,I,O
-->
7 characters
```

---

The `main` function:

* receives **exactly one** command-line argument: the name of a text file.
  If not, it prints
  **“ERROR 1: invalid number of parameters”**
  and terminates returning **1**.
* declares a character array of fixed size **30**.
* calls the function that reads and validates the string.
  If the function returns 0, it prints
  **“ERROR 2: maximum number of attempts reached”**
  and terminates returning **2**.
* calls the function that displays the string and then prints
  **“the string … contains … characters”**.
* calls the function that determines the alphabetically first and last characters and then prints
  **“the first character is …, the last character is …”**.
* calls the function that writes the vowels to the file and then prints
  **“… characters written to file …”**.
* terminates returning **0**.
  */


