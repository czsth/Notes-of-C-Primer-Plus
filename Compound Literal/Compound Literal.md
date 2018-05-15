#Compound Literal
Before C99, there is not such kind of things like "array(or struct) constant", 
so it is not convenient to deliver such a parameter to the function.

For example:
a compound literal of an array contain two integer is usually denoted as:
```
(int [<number>]){<number>, <number>...}
```
You can also use compound literal to create a struct constant, as in the example code.
Mind that we used desinated initilizer in example code.

Another example:
In former, the following code can be used only in initializing:
```
int arr[] = {1, 2, 3};
```
After `arr` is defined, there is no way to assign a whole set of value to it.

But now, after defining, you can still code like this:
```
int * arr;
arr = (int []){1, 2, 3};
```
*PS for Atom editor I am using:*
*1. in gcc-make-run, set compile command: `-std=c99`;*
*2. in linter, use `gcc` compiler( `g++` is default), and set compile command: `-std=c99` ;*

