# Advanced-String-Manipulation
Problem: Numerous problems, many from the field of mathematical recreation, involve operations on
numbers with a very large number of digits – far beyond the capability of the standard integer data types
used by computers.

The Assignment: Design, develop, and test an Object-Oriented C++ program to perform math operations
on very large integers.

Discussion: In C++, the largest 32-bit int value is 2,147,483,647 (10 digits), and the largest 64-bit long
long value is 9,223,372,036,854,775,807 (19 digits). Consequently, a value larger than these cannot be
stored or processed as a standard integer type in C++. Similarly, if the sum or product of two integers is
greater than either of these values, the result will overflow and be incorrect. Our goal in this assignment is
to be able to store and at least add integers with 50 or more digits. One way to store and manipulate very
large integers is to represent a single large integer as an array or vector of digits, and to store each
individual digit of the large integer value as an element of the array (or vector). Consider the following
issues when developing your solution to this problem.

 Define a class named LargeInt that holds the data for only one large integer value with as many
digits as the user needs (it must operate on any number of digits from 1 to at least 50). Use an array
or vector to hold the digits of the stored value. Include constructor(s) and methods to manage and
operate on the large integer value. The constructor(s) and input methods must accept input values
as strings containing only decimal digits. The only math operation that MUST be included is
unsigned addition. Be sure to include a method that will format the sum value for output as a
string. Each instance of the LargeInt class must include instance variables for ONLY ONE large
integer.

 Implement three objects of the LargeInt class within main().

 Input two large integers (as strings) from the user to initialize two of the LargeInt objects. These
values can have any number of digits from 1 up to at least 50. Initialize the third LargeInt object to
zero and then add the other two LargeInt values into it.

 Display the two input values and their sum. The three large integer values must be displayed rightaligned with each other in a single column.

 Repeat the process of inputting two large numbers, adding them together, and displaying the result
until the user opts to quit.

