
#ifndef _CHIP_B_H_
#define _CHIP_B_H_

struct link_street
{
    int registerA;
    int registerB;
};

void link_street_init(struct link_street* me);
void link_street_shutdown(struct link_street* me);
void link_street_set_registerA(struct link_street* me, int value);
void link_street_set_registerB(struct link_street* me, int value);



#endif
