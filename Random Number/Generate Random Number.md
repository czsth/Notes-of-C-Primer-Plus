## Generate Random Number

```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){
    srand(time(NULL));
    int my_rand_num;
    my_rand_num = rand()	//generate an integer between 0~RAND_MAX
    
    return 0;
}
```

Notice: `RAND_MAX` is an integer defined in `stdlib.h` .