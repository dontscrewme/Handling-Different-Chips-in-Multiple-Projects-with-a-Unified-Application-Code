
#ifndef _CHIP_A_H_
#define _CHIP_A_H_

struct dragonwing_NPA7
{
    int register1;
    int register2;
};

void dragonwing_NPA7_init(struct dragonwing_NPA7* me);
void dragonwing_NPA7_shutdown(struct dragonwing_NPA7* me);
void dragonwing_NPA7_set_register1(struct dragonwing_NPA7* me, int value);
void dragonwing_NPA7_set_register2(struct dragonwing_NPA7* me, int value);




#endif
