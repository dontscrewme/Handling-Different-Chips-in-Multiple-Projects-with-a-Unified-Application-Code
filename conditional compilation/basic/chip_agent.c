#include <stdio.h>
#include <stdlib.h>
#include "chip_agent.h"

#ifdef CHIP_A
#include "chip_a.h"
#elif defined(CHIP_B)
#include "chip_b.h"
#elif defined(CHIP_C)
#include "chip_c.h"
#else
#error "No chip defined!  Please define CHIP_A, CHIP_B, or CHIP_C during compilation."
#endif

struct chip_agent {

#ifdef CHIP_A
        struct dragonwing_NPA7 dragonwing_NPA7;
#elif defined(CHIP_B)
        struct link_street link_street;
#elif defined(CHIP_C)
        struct snapdragon snapdragon;
#endif
};

struct chip_agent* agent_create(void)
{
    struct chip_agent* agent = malloc(sizeof(struct chip_agent));
    if (agent == NULL)
    {
        return NULL;
    }

    return agent;
}


static void init_network_module(struct chip_agent* agent)
{
#ifdef CHIP_A
    dragonwing_NPA7_init(&agent->dragonwing_NPA7);
#elif defined(CHIP_B)
    link_street_init(&agent->link_street);
#elif defined(CHIP_C)
    snapdragon_init(&agent->snapdragon);
#endif

}

static void start_network_module(struct chip_agent* agent)
{
#ifdef CHIP_A
    printf("dragonwing_NPA7 network module starts\n");
    dragonwing_NPA7_set_register1(&agent->dragonwing_NPA7, 1);
    dragonwing_NPA7_set_register2(&agent->dragonwing_NPA7, 1);
#elif defined(CHIP_B)
    printf("MARVELL_LINKSTREET network module starts\n");
    link_street_set_registerA(&agent->link_street, 1);
    link_street_set_registerB(&agent->link_street, 1);
#elif defined(CHIP_C)
    printf("QUALCOMM_SNAPDRAGON network module starts\n");
    snapdragon_set_registerI(&agent->snapdragon, 1);
    snapdragon_set_registerII(&agent->snapdragon, 1);
#endif
}

static void stop_network_module(struct chip_agent* agent)
{
#ifdef CHIP_A
    dragonwing_NPA7_set_register1(&agent->dragonwing_NPA7, 0);
    dragonwing_NPA7_set_register2(&agent->dragonwing_NPA7, 0);
#elif defined(CHIP_B)
    link_street_set_registerA(&agent->link_street, 0);
    link_street_set_registerB(&agent->link_street, 0);
#elif defined(CHIP_C)
    snapdragon_set_registerI(&agent->snapdragon, 0);
    snapdragon_set_registerII(&agent->snapdragon, 0);
#endif
}

static void shutdown_network_module(struct chip_agent* agent)
{
#ifdef CHIP_A
    dragonwing_NPA7_shutdown(&agent->dragonwing_NPA7);
#elif defined(CHIP_B)
    link_street_shutdown(&agent->link_street);
#elif defined(CHIP_C)
    snapdragon_shutdown(&agent->snapdragon);
#endif
}


void agent_set(struct chip_agent* agent)
{
    if (agent == NULL)
    {
        return;
    }

    init_network_module(agent);
    start_network_module(agent);
}

void agent_destroy(struct chip_agent* agent)
{
    if (agent == NULL)
    {
        return;
    }

    stop_network_module(agent);
    shutdown_network_module(agent);

    free(agent);
}

void agent_run_network(struct chip_agent* agent)
{
    agent = agent; //suppress compiler warning
    //implementation
    return;
}