#include <stdio.h>
#define SEPT_6
#define float_2_MyF(a) *((MyFloat*)(&(a)))

//Configuracion Litle Endian:
//El byte mas significativo queda en la direccion mas alta
typedef
struct myfloat {
    unsigned mantisa    :23;
    unsigned power      :8;
	unsigned sign       :1;
}MyFloat;

struct four_chars{
    unsigned char abcd0;
    unsigned char abcd1;
    unsigned char abcd2;
    unsigned char abcd3;
};

union UFloat{
	MyFloat MyF;
	struct four_chars FourChars;
};

typedef
struct Int{ //Litle endian
    unsigned byte0  :8;
    unsigned byte1  :8;
    unsigned byte2  :8;
    unsigned byte3  :8;
}Int;

union paraInt{
    Int IntV;
    struct four_chars FC;
};

void show_bits(int);

long main(){
    int intA = 2012026905;
    show_bits(intA);
    printf("\n");
    Int IntVar = *((Int*)(&intA));
    printf("IntVar=%d\n",*((int*)(&IntVar)));
    printf("byt0=%x\t",IntVar.byte0);
    printf("byt1=%x\t",IntVar.byte1);
    printf("byt2=%x\t",IntVar.byte2);
    printf("byt3=%x\n",IntVar.byte3);

    union paraInt union_paraInt;
    union_paraInt.IntV = IntVar;
    printf("byt0=%x\t",&(union_paraInt.FC.abcd0));
    printf("byt1=%x\t",&(union_paraInt.FC.abcd1));
    printf("byt2=%x\t",&(union_paraInt.FC.abcd2));
    printf("byt3=%x\n",&(union_paraInt.FC.abcd3));

#ifdef SEPT_6
    float floatA = 0.25;
    intA = *((int*)(&floatA));
    show_bits(intA);
    printf("\n");
    MyFloat MyF;
    printf("sizeof(MyF)=%d\n",(int)sizeof(MyF));
	printf("sizeof(unsigned char)=%d\n",(int)sizeof(unsigned char));
	printf("sizeof(struct four_chars)=%d\n",(int)sizeof(struct four_chars));
	MyF=float_2_MyF(floatA);
	union UFloat union_UFloat;
	union_UFloat.MyF = MyF;
	printf("%x\t",union_UFloat.FourChars.abcd0);
	printf("%x\t",union_UFloat.FourChars.abcd1);
	printf("%x\t",union_UFloat.FourChars.abcd2);
	printf("%x\n",union_UFloat.FourChars.abcd3);
    printf("%x\t",union_UFloat.MyF.sign);
	printf("%x\t",union_UFloat.MyF.power);
	printf("%x\n",union_UFloat.MyF.mantisa);
#endif // SEPT_6
    return 0;
}

void show_bits(int intTemp){
    int i;
    for((i = 8*sizeof(int)-1);i>=0;i--){
        printf("%d",(intTemp>>i)&0x00000001);
        //printf("%d\n",i);
    }
}
