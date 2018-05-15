##INPUT
|Function | Description |
|---------|-------------|
|`char * gets(char * des)`|get string from input device and store it in `des`. In normal cases, it returns `des`. If met with error or `EOF`, it returns `NULL`.|
|`char * fgets(char * des, int dessize, FILE * stream)`|get string from input devise and store it in `des`, if the size of string is larger than `dessize`, it gets `dessize - 1` character, else, it read until met with `\n`. Its return value is same as `gets()`.|

*Caution: `gets()` will drop the `\n` in the end of the string, while `fgets()` will not.*  

##OUTPUT
|Function | Description |
|---------|-------------|
|`int puts ( const char * str )`|On success, a non-negative value is returned. On error, the function returns EOF and sets the error indicator (ferror).|
|`int fputs ( const char * str, FILE * stream )`|Omitted|
*Caution: `puts()` usually automatically add an `\n` at the end of the string, while `fputs()` will not.* 