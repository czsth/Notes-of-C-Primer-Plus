#include <stdio.h>

int main(int argc, char const *argv[]) {
    struct LED {
        unsigned int lt1: 14;
        unsigned int lt2: 14;
        unsigned int    : 4;
        unsigned int lt3: 14;
        unsigned int 	: 0;
        unsigned int lt4: 14;
    } led;
    printf("%d\n", sizeof(led));

    return 0;
}
