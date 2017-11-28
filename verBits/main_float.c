#include <stdio.h>
#include <stdlib.h>

union{
    float f;
    int i;
}mistery;

main(int argc, char *argv[]){
    float floatA=atof(argv[1]);
    mistery.f = floatA;
    int i;
    for(i = 31; i >= 0;i--){
        printf("%d",(mistery.i>>i)&0x00000001);
    }
    printf("\n");
    return floatA;
}
