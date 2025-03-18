#include "chip_a.h"


void dragonwing_NPA7_init(struct dragonwing_NPA7* me)
{
    /*do something to init*/
    me = me;
    return;
}

void dragonwing_NPA7_shutdown(struct dragonwing_NPA7* me)
{
    /*do something do shutdown*/
    me = me;
    return;
}

void dragonwing_NPA7_set_register1(struct dragonwing_NPA7* me, int value)
{
    me->register1 = value;
}

void dragonwing_NPA7_set_register2(struct dragonwing_NPA7* me, int value)
{
    me->register2 = value;
}
