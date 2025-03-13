#include <stdio.h>
#include "chip_agent.h"
#ifdef CHIP_A
#include "chip_a.h"
#elif defined (CHIP_B)
#include "chip_b.h"
#else
#error "No chip defined for the project! Define CHIP_A or CHIP_B"
#endif


#ifdef CHIP_A
static struct chipA chip = {0};
#elif defined (CHIP_B)
static struct chipB chip = {0};
#include "chip_b.h"
#endif


void agent_init(struct agent* me)
{

    me->element123 = 0;
#ifdef CHIP_A
    init_chipA(&chip);
#elif defined (CHIP_B)
    init_chipB(&chip);
#endif

}

int agent_get_element123(struct agent* me)
{
#ifdef CHIP_A
    printf("chip A invoked!\n");
    int element1 = chipA_get_element1(&chip);
    int element2 = chipA_get_element2(&chip);
    me->element123 = element1*element2;
#elif defined (CHIP_B)
    printf("chip B invoked!\n");
    int elementA = chipB_get_elementA(&chip);
    int elementB = chipB_get_elementB(&chip);
    me->element123 = elementA+elementB;
#endif

    return me->element123;
}