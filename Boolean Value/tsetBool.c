#include <stdio.h>

_Bool isNum(char a){
	_Bool rtn;
	if(a >= '0' && a <= '9')
//		rtn = true;	not available, undeclare value "true"
		rtn = 1; 
	else
		rtn = 0;
	return rtn;
}

int main(int argc, char const *argv[])
{
	char myChar = getchar();
	if(isNum(myChar)){
		printf("Is Num\n");
	}
	else{
		printf("Not Num\n");
	}
	printf("%d", sizeof(_Bool));
	return 0;
}
