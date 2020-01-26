#include "blocklist.h"

f_block *initBlock() {

 	return (f_block *) malloc(sizeof(f_block));

}

f_block *addBlock(fblock *p_block) {

	f_block *new_block = initBlock();
	p_block->next = new_block;
	return new_block;

}
