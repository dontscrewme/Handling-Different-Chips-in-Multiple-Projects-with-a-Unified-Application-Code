
#ifndef _CHIP_A_H_
#define _CHIP_A_H_

struct chipA
{
    int element1;
    int element2;
};

void init_chipA(struct chipA* me);
int chipA_get_element1(struct chipA* me);
int chipA_get_element2(struct chipA* me);



#endif
