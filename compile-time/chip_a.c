#include "chip_a.h"


void init_chipA(struct chipA* me)
{
    me->element1 = 2;
    me->element2 = 2;
}

int chipA_get_element1(struct chipA* me)
{
    return me->element1;
}
int chipA_get_element2(struct chipA* me)
{
    return me->element2;
}
