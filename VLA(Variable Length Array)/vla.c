#include <stdio.h>
#include <string.h> 
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int arr[n];
	memset(arr, 0, sizeof(arr));
	int i;
	for(i = 0; i < n; i++){
		putchar(arr[i] + '0');
	}
	return 0;
}
