#include "chip_b.h"


void init_chipB(struct chipB* me)
{
    me->elementA = 2;
    me->elementB = 2;
}

int chipB_get_elementA(struct chipB* me)
{
    return me->elementA;
}
int chipB_get_elementB(struct chipB* me)
{
    return me->elementB;
}
