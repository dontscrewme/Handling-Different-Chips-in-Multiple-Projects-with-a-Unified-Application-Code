
#ifndef _CHIP_C_H_
#define _CHIP_C_H_

struct snapdragon
{
    int registerI;
    int registerII;
};

void snapdragon_init(struct snapdragon* me);
void snapdragon_shutdown(struct snapdragon* me);
void snapdragon_set_registerI(struct snapdragon* me, int value);
void snapdragon_set_registerII(struct snapdragon* me, int value);


#endif
