#include <stdio.h>

int main(int argc, char const *argv[]) {
    int *arr;
    arr = (int[10]){1, 2, 3};
    printf("%d\n", *arr);
    arr[2] = 1;
    int i;
    for(i = 0; i < 3; i++){
        printf("%d", arr[i]);
    }

    return 0;
}
