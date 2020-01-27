#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "blocklist.h"


void print_md5_sum(unsigned char* md) {
    int i;
    for(i=0; i <MD5_DIGEST_LENGTH; i++) {
            printf("%02x",md[i]);
    }
    printf("\n");
}

int main () {

    unsigned char **data = (unsigned char**) malloc(sizeof(unsigned char *)*2);

    for (int i=0; i<2; i++) {
        data[i] = (unsigned char*) malloc(sizeof(char [MD5_DIGEST_LENGTH]));
    }

    data[0][0] = 'z';
    data[0][1] = 'C';
    data[0][2] = 'i';

    data[1][0] = 'h';
    data[1][1] = 'u';
    data[1][2] = 'i';



    for (int j=0; j<2; j++) {
        for (int i=0; i<MD5_DIGEST_LENGTH; i++) {
            if (data[j][i] != 0) {
                printf("%c", data[j][i]);
            }
        }
        printf(":\t\t");
        for (int i=0; i<MD5_DIGEST_LENGTH; i++) {
            printf("%2X ", data[j][i]);
        }
        printf("\n");
    }

    free(data);

}
