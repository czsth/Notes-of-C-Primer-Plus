#FILE IO

###Sequential Access
|Function form|Description|
|-------------|-----------|
|`int fprintf ( FILE * stream, const char * format, ... )`|Omitted|
|`int fscanf ( FILE * stream, const char * format, ... )`|Omitted|
|`char * fgets ( char * str, int maxsize, FILE * stream )`|Get a string(shorter than (`maxsize` - 1))(`\0` for the last position) from `stream` to `str`. If shorter, put a `\n` afterwards.|
|`int fputs ( const char * str, FILE * stream )`|Notice: this function do not add a `\n` automatically as `puts()`.|
*Notice: `fgets()` works better with `fputs()` than mixed with those were not created for files such as `puts()` .* 

###Random Access
|Function form|Description|
|-------------|-----------|
|`int fseek ( FILE * stream, long int offset, int origin )`|reset the current stream to `offset` from `origin`|
|`long int ftell ( FILE * stream )`|return current position in file|

#####Appendix:
The `origin` argument in fseek():
| Constant | Reference position                   |
| -------- | ------------------------------------ |
| SEEK_SET | Beginning of file                    |
| SEEK_CUR | Current position of the file pointer |
| SEEK_END | End of file *                        |

