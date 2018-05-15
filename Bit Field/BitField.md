#Bit Field
Bit Field is a struct contains serveral `int` or `unsigned int`, which can be given name to specific number of digits and operate them directly.

For example we have such an occation: we have a set of  4 LEDs, and we want to mark down the state(0 or 1 only) they are in, so we use 4 Bit Field, and 1 bit  for every one,  to contain these.
```
struct {
    unsigned int lt1: 1;
    unsigned int lt2: 1;
    unsigned int lt3: 1;
    unsigned int lt4: 1;
} LED;
```
Note that an `unsigned int` has 32 bits, and the 4 bit field above occupied only 4 bits. Actually, the rest bits are not gonna be able to visit, and the size of the struct is `sizeof(unsigned int)` .

However, if we have more or longer bit fields, that their sum exceed the size of an `unsigned int` , things change.
For example, we modifiy the above struct like this:
```
struct {
    unsigned int lt1: 14;
    unsigned int lt2: 14;
    unsigned int lt3: 14;
    unsigned int lt4: 14;
} LED;
```
It has totally *4 \* 14 = 56* bits, and *32 < 56 < 64*, so the size will be 8 byte(64 bits), as the size of a struct of bit field will accumulate quantizationally.
We should point out that the formula *4 \* 14 = 56* is not totally correct, for one bit field is not allowed to be stored in two "block" of `unsigned int` separately. 
The correct way to count the total size should be like this:
From the beginning, we assume sum = 0, than we inspect the first bit field, sum = 14; then the second, sum = 28; then the third, sum = 42 > 32, so let sum = 32 + 14 = 46; and the last, sum = 60. This is called **memory alignmemt** .

*PS: you can use an unnamed bit field with specific length to "fill" some "hole", and use an unnamed bit field with length = 0 to force the next bit field align to next `unsigned int` .*
*For example:*
```
struct {
    unsigned int lt1: 14;
    unsigned int lt2: 14;
    unsigned int    : 4;
    unsigned int lt3: 14;
    unsigned int 	: 0;
    unsigned int lt4: 14;
} LED;
```
*The new size will be 12 bytes.*
