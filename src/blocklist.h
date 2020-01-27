#include <stdio.h>
#include <stdlib.h>
#include <openssl/md5.h>

#define BLOCKSIZE 4096

typedef struct {
    char *path;
    unsigned char **hashlist;
} blocklist_t;

/**

                        F_BLOCKLIST
    +-------------------------------------------------------+
    |                                                       |
    |    "/path/to/file"                                    |
    |                                                       |
    |    +---+----------+                                   |
    |    | 1 |  <hash>  |                                   |
    |    +---+----------+                                   |
    |    | 2 |  <hash>  |                                   |
    |    +---+----------+                                   |
    |    |      ...     |                                   |
    |    +---+----------+                                   |
    |    | N |  <hash>  |                                   |
    |    +---+----------+                                   |
    |                                                       |
    +-------------------------------------------------------*
*/
