#include <stdio.h>
int main(int argc, char const *argv[])
{
	char ch;
	ch = getchar();		//for example: we input "hello" here
	putchar(ch);		//output 'h', and there is "ello" remain in the input steam
	fflush(stdin);		//"ello" was flushed!
	ch = getchar();		//as the stream is empty now, it requires input from stdin
	putchar(ch); 		//output the character you input last line
	
	return 0;
}
/*
*This may be a not proper example, as it was mentioned
*in  "cppreference.com" that "the fflush() to an input
*stream is undefined"
*/