#stdarg.h
`stdarg.h` provided a way to pass variable number of arguments to a function.
See what was defined in the header first:

|Type|Description|
|---|---|
|va_list|holds the information needed by va_start, va_arg, va_end, and va_copy(typedef)|

|Macro|Description|
|---|---|
|va_start|enables access to variadic function arguments(function macro)|
|va_arg|accesses the next variadic function argument (function macro)|
|va_copy(C99)|makes a copy of the variadic function arguments (function macro)|
|va_end|ends traversal of the variadic function arguments (function macro)|

then an example:
```
#include <stdio.h>
#include <stdarg.h>

double sum(int n, ...);		/*the last argument before dots gives
							the totol number of arguments actually passed*/

int main(int argc, char * argv[]){
	double total;
	total = sum(3, 3.1, 3.2, 9.4);
	printf("%lf", total);

    return 0;
}

double sum(int n, ...){
    va_list li, licpy;
    va_start(li, lim);	// list initialize(or assignment maybe)
    va_copy(licpy, li);	/* a copy of li, because once read, 
    					no way to get the argument back again, 
    					unless using a copy */
    
    double sum;
    int i;	//loop var
    for(i = 0; i < n; i++){
        sum += va_arg(li, double);	/* note that no automatic type convertion 
        							will be done here, so if given a wrong type, 									the behavior of the macro is undefined */
    }
    return sum;
}
```
