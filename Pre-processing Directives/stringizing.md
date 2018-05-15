#Stringizing in Function-Like Macro
Just give the following example:
```
#include <stdio.h>
#define PSQR(x) printf("The square of " #x " is %d", ((x)*(x)))
#define PSQR_1(x) printf("The square of x is %d", ((x)*(x)))
int main(int argc, char * argv[]){
    int y = 5;
    
    PSQR(y);
    PSQR_1(y);
    
    return 0;
}
```
```
Output:
	The square of y is 25
	The square of x is 25
```
And note that `#define PSQR_1(x) printf("The square of "x" is %d", ((x)*(x)))` is illegal.
