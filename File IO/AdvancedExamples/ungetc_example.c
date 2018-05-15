#include <stdio.h>
int main(int argc, char const *argv[])
{
	ungetc('a', stdin);
	char ch;
	ch = getchar();
	putchar(ch);
	return 0;
}