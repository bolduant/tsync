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

    F_BLOCKLIST my_blocklist;
    my_blocklist.f_path = "/home/tbol/pictures/Wallpaper_Slackline.jpg";

    //printf("Pfad: %s\n", my_blocklist.f_path);


    FILE *fp = fopen(my_blocklist.f_path, "rb");
    
    unsigned char buffer[BLOCKSIZE];

    
    int i=0;
    my_blocklist.f_blocks = (unsigned char**) malloc((i+1)*MD5_DIGEST_LENGTH);

    while ((fread(buffer,sizeof(unsigned char),BLOCKSIZE,fp)) > 0) {

        
        unsigned char hash[MD5_DIGEST_LENGTH];
        MD5(buffer, sizeof(buffer), hash);

        my_blocklist.f_blocks = (unsigned char**) realloc(my_blocklist.f_blocks, (i+1)*MD5_DIGEST_LENGTH);


        //my_blocklist.f_blocks[i] = hash;

        
        

        print_md5_sum((my_blocklist).f_blocks[i]);

        //printf("Block [%d]: ", i);
        //print_md5_sum(hash);
        i++;

    }
    
    printf("\n\n");

    fclose(fp);



    for (int j=0; j<i; j++) {
        print_md5_sum((my_blocklist).f_blocks[j]);
    }





    //Idee: Erst initialisieren mit malloc und dann stetig mit realloc erweitern.


    //      each 4K block needs 8 byte for md5 checksum
    //      size of file list:
    //          <x> Number of Bytes for File_Path (MAX 1KB)
    //        + <y> 8 * Number of 4k blocks

    /*      Example
                "/home/tbol/pictures/"  =>  43 byte
                8 * 142 blocks          =>  1136 byte
                -------------------------------------
                                            1179 byte 
                                            =========

                1179 bytes metadata for 579.838 bytes
    */

}






/*

    * Solange nicht am Ende des eingelesenen Files, lade nächsten 4K Block & erzeuge MD5 Hash 

        +-------------------------------------------------------------------------------------------------------------------------------+                   +-------------------------------+
        |                                                         Data                                                                  |           ->      |            Hash               |
        +-------------------------------------------------------------------------------------------------------------------------------+                   +-------------------------------+

    * Erzeuge neuen Speicher für Hash-Wert des Blocks
    * Schreibe Daten in den neuen Speicher des Blocks
    * Vergrößere Array und füge Adresse des neuen Speicherblocks hinzu


    +-------------------------------+
    |             Hash              |   
    +-------------------------------+
    |             Hash              |   
    +-------------------------------+

                    +

    +-------------------------------+
    |             Hash              |   
    +-------------------------------+
                


*/
