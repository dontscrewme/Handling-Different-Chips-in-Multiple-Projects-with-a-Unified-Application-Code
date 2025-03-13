
#ifndef _CHIP_B_H_
#define _CHIP_B_H_

struct chipB
{
    int elementA;
    int elementB;
};

void init_chipB(struct chipB* me);
int chipB_get_elementA(struct chipB* me);
int chipB_get_elementB(struct chipB* me);



#endif
