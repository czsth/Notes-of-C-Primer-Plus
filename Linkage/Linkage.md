##Linkage
|Linkage|Scope|
|-------|-----|
|`no linkage`|code, function prototype|
|`internal linkage`|file|
|`external linkage`|file|

###Example
```
#include <stdio.h>
int x;				//external linkage
static int y;		//internal linkage
void foo(int b){	//no linkage
    int a;			//no linkage
}
int main(){
	int a;			//no linkage
    
	return 0;
}
```