/*To see if it will be more fluent after adding fflush()*/
#include <stdio.h>
int main(int argc, char const *argv[])
{
	int i, j, k;
	for(i = 0; i < 1000; i++){
		for(j = 0; j < 100; j++){
			for(k = 0; k < j; k++){
				putchar('a');
				fflush(stdout);
			}
		putchar('\n');
		}
	}
	return 0;
}
