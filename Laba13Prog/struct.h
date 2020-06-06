#ifndef LAB13_STRUCT_H
#define LAB13_STRUCT_H

typedef struct address {
    unsigned a1:4;
    unsigned a2:4;
    unsigned b1:4;
    unsigned b2:4;
    unsigned c1:4;
    unsigned c2:4;
    unsigned d1:4;
    unsigned d2:4;
    unsigned e1:4;
    unsigned e2:4;
    unsigned f1:4;
    unsigned f2:4;
} mac;

void setMac(mac *address);
void printMac(mac *address);
void status_to_wide(mac *address);
void status_to_certain(mac *address);
void printBin(int num);

#endif //LAB13_STRUCT_H
