#include "chip_b.h"


void link_street_init(struct link_street* me)
{
    /*do something do init*/
    me = me;
    return;
}
void link_street_shutdown(struct link_street* me)
{
   /*do something do shutdown*/
   me = me;
   return;
}

void link_street_set_registerA(struct link_street* me, int value)
{
    me->registerA = value;
}

void link_street_set_registerB(struct link_street* me, int value)
{
    me->registerB = value;
}