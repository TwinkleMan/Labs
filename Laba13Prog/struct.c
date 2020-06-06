#include "struct.h"
#include <stdio.h>

void setMac(mac *address)
{
    unsigned short inp1,inp2;

    puts("Enter first octet (a1 a2, with the space):");
    scanf("%hx %hx",&inp1,&inp2);
    address->a1 = inp1;
    address->a2 = inp2;
    puts("Enter second octet (b1 b2, with the space):");
    scanf("%hx %hx",&inp1,&inp2);
    address->b1 = inp1;
    address->b2 = inp2;
    puts("Enter third octet (c1 c2, with the space):");
    scanf("%hx %hx",&inp1,&inp2);
    address->c1 = inp1;
    address->c2 = inp2;
    puts("Enter forth octet (d1 d2, with the space):");
    scanf("%hx %hx",&inp1,&inp2);
    address->d1 = inp1;
    address->d2 = inp2;
    puts("Enter fifth octet (e1 e2, with the space):");
    scanf("%hx %hx",&inp1,&inp2);
    address->e1 = inp1;
    address->e2 = inp2;
    puts("Enter sixth octet (f1 f2, with the space):");
    scanf("%hx %hx",&inp1,&inp2);
    address->f1 = inp1;
    address->f2 = inp2;
}

void printMac(mac *address)
{
    puts("HEX form:");
    printf("%x",address->a1);
    printf("%x-",address->a2);
    printf("%x",address->b1);
    printf("%x-",address->b2);
    printf("%x",address->c1);
    printf("%x-",address->c2);
    printf("%x",address->d1);
    printf("%x-",address->d2);
    printf("%x",address->e1);
    printf("%x-",address->e2);
    printf("%x",address->f1);
    printf("%x",address->f2);

    puts("\n\nbyte form:");
    printBin(address->a1);
    printf(" ");
    printBin(address->a2);
    printf(" ");
    printBin(address->b1);
    printf(" ");
    printBin(address->b2);
    printf(" ");
    printBin(address->c1);
    printf(" ");
    printBin(address->c2);
    printf(" ");
    printBin(address->d1);
    printf(" ");
    printBin(address->d2);
    printf(" ");
    printBin(address->e1);
    printf(" ");
    printBin(address->e2);
    printf(" ");
    printBin(address->f1);
    printf(" ");
    printBin(address->f2);
    printf(" ");
}

void printBin(int num)
{
    int i, v = 128;

    for (i = 1;i <=8;i++) {
        if (num >= v) {
            printf("%d",1);
            num -= v;
        }
        else {
            printf("%d",0);
        }
        v /= 2;
    }
}

void status_to_certain(mac *address)
{
    address->a2 &= ~(1 << 0);
}

void status_to_wide(mac *address)
{
    address->a2 |= (1 << 0);
}
