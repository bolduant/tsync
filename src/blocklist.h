#include <stdio.h>
#include <stdlib.h>
#include <openssl/md5.h>

#define BLOCKSIZE 4096


typedef struct block{

  const char *data;
  block *next;

} f_block;

f_block *initBlock();
f_block *addBlock(fblock *p_block);

typedef struct {

    const char *f_path;
    f_block *blocklist;

} F_BLOCKLIST;
