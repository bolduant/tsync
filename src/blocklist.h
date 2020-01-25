#include <stdio.h>
#include <openssl/md5.h>

#define BLOCKSIZE 4096

typedef struct {

    const char *f_path;
    unsigned char **f_blocks;

} F_BLOCKLIST;


