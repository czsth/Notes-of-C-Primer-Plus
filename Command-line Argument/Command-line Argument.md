##Command-line Argument
```
#include <stdio.h>
int main(int argv, char *argc[]){
    //some code
    return 0;
}
```
In the program above, if we run it using `cmd` in Windows, we can pass some parameter.
For example(suppose the exe file above is `foo.exe`):
```
./foo Helo World
```
Then, usually, the arguments has the following value:
|Variable|value|
|------|-------|
|argc|3|
|argv[0]|"foo"|
|argv[1]|"Hello"|
|argv[2]|"World"|
|argv[n] (n > 3)|(undefined)|

*Notice: if you want to pass a string with internal space, use `""` .* 