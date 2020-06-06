#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

int main() {
    mac *first = NULL;
    int flag;

    puts("Enter the MAC");
    puts("MAC represented as a1a2-b1b2-c1c2-d1d2-e1e2-f1f2");
    first = (mac*)malloc(sizeof(mac));
    setMac(first);
    printf("\n");
    printMac(first);
    puts("\n\n1 - status = broadcast packages source");
    puts("2 - status = specific address packages source");
    scanf("%d",&flag);
    if (flag == 1) {
        status_to_wide(first);
    } if (flag == 2) {
        status_to_certain(first);
    }
    puts("\nByte changed:\n");
    printMac(first);
    puts("\nPress ENTER to exit...");
    getchar();
    free(first);
    first = NULL;
    getchar();
}
