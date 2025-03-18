#include "chip_c.h"



void snapdragon_init(struct snapdragon* me)
{
    /*do something to init*/
    me = me;
    return;
}

void snapdragon_shutdown(struct snapdragon* me)
{
    /*do something do shutdown*/
    me = me;
    return;
}

void snapdragon_set_registerI(struct snapdragon* me, int value)
{
    me->registerI = value;
}

void snapdragon_set_registerII(struct snapdragon* me, int value)
{
    me->registerII = value;
}
