#include <stdio.h>
int main(int argc, char const *argv[])
{
	int arr[] = {[8] = 1};
	for (int i = 0; i < 9; ++i)
	{
		putchar(arr[i] + '0');
	}
	return 0;
}
