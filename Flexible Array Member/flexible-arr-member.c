#include <stdio.h>
#include <stdlib.h>

typedef struct flex {
    int foo;
    char boo;
    double flex[];
} Flex;

void creatFlex(Flex * myflex, int arrSize);
void freeFlex(Flex * myflex);

int main(int argc, char const *argv[]) {
    Flex * myflex;
    int size = 10;
    creatFlex(myflex, size);
    int i;
    for(i = 0; i < size; i++){
        myflex -> flex[i] = i;
    }
    for(i = 0; i < size; i++){
        printf("%lf\n", myflex -> flex[i]);
    }
    freeFlex(myflex);

    return 0;
}

void creatFlex(Flex * myflex, int arrSize){
    myflex = (Flex *)malloc(sizeof(Flex) + arrSize * sizeof(double));
}

void freeFlex(Flex * myflex){
    // free(myflex -> flex);    //Attention: this line is unnecessary. Compare with array pointor.
    free(myflex);
}
