#include <stdio.h>
#include <stdlib.h>

main(int argc, char *argv[]){
    int intA=atoi(argv[1]);
    int i;
    for(i = 31; i >= 0;i--){
        printf("%d",(intA>>i)&0x00000001);
    }
    printf("\n");
    return intA;
}
