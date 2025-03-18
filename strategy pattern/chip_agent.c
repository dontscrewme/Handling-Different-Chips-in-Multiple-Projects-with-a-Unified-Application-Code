#include <stdio.h>
#include <stdlib.h>
#include "chip_agent.h"
#include "chip_a.h"
#include "chip_b.h"
#include "chip_c.h"

struct chip_agent {
    enum chips current_chip;
    union
    {
        struct dragonwing_NPA7 dragonwing_NPA7;
        struct snapdragon snapdragon;
        struct link_street link_street;
    }base;
};

struct chip_agent* agent_create(void)
{
    struct chip_agent* agent = malloc(sizeof(struct chip_agent));
    if (agent == NULL)
    {
        return NULL;
    }

    agent->current_chip = UNKNOWN_CHIP;
    return agent;
}

static void init_network_module(struct chip_agent* agent)
{
    if (agent->current_chip == QUALCOMM_DRAGONWING)
    {
        dragonwing_NPA7_init(&agent->base.dragonwing_NPA7);
    }
    else if (agent->current_chip == QUALCOMM_SNAPDRAGON)
    {
        snapdragon_init(&agent->base.snapdragon);
    }
    else if (agent->current_chip == MARVELL_LINKSTREET)
    {
        link_street_init(&agent->base.link_street);
    }
    else
    {
        
    }
}

static void start_network_module(struct chip_agent* agent)
{
    if (agent->current_chip == QUALCOMM_DRAGONWING)
    {
        printf("dragonwing_NPA7 network module starts\n");
        dragonwing_NPA7_set_register1(&agent->base.dragonwing_NPA7, 1);
        dragonwing_NPA7_set_register2(&agent->base.dragonwing_NPA7, 1);
    }
    else if (agent->current_chip == QUALCOMM_SNAPDRAGON)
    {
        printf("QUALCOMM_SNAPDRAGON network module starts\n");
        snapdragon_set_registerI(&agent->base.snapdragon, 1);
        snapdragon_set_registerII(&agent->base.snapdragon, 1);
    }
    else if (agent->current_chip == MARVELL_LINKSTREET)
    {
        printf("MARVELL_LINKSTREET network module starts\n");
        link_street_set_registerA(&agent->base.link_street, 1);
        link_street_set_registerB(&agent->base.link_street, 1);
    }
    else
    {
        
    }
}

static void stop_network_module(struct chip_agent* agent)
{
    if (agent->current_chip == QUALCOMM_DRAGONWING)
    {
        dragonwing_NPA7_set_register1(&agent->base.dragonwing_NPA7, 0);
        dragonwing_NPA7_set_register2(&agent->base.dragonwing_NPA7, 0);
    }
    else if (agent->current_chip == QUALCOMM_SNAPDRAGON)
    {
        snapdragon_set_registerI(&agent->base.snapdragon, 0);
        snapdragon_set_registerII(&agent->base.snapdragon, 0);
    }
    else if (agent->current_chip == MARVELL_LINKSTREET)
    {
        link_street_set_registerA(&agent->base.link_street, 0);
        link_street_set_registerB(&agent->base.link_street, 0);
    }
    else
    {
        
    }
}

static void shutdown_network_module(struct chip_agent* agent)
{
    if (agent->current_chip == QUALCOMM_DRAGONWING)
    {
        dragonwing_NPA7_shutdown(&agent->base.dragonwing_NPA7);
    }
    else if (agent->current_chip == QUALCOMM_SNAPDRAGON)
    {
        snapdragon_shutdown(&agent->base.snapdragon);
    }
    else if (agent->current_chip == MARVELL_LINKSTREET)
    {
        link_street_shutdown(&agent->base.link_street);
    }
    else
    {
        
    }
}

void agent_set(struct chip_agent* agent, enum chips chip)
{
    if (agent == NULL)
    {
        return;
    }

    if (agent->current_chip != UNKNOWN_CHIP)
    {
        stop_network_module(agent);
        shutdown_network_module(agent);
    }

    agent->current_chip = chip;
    init_network_module(agent);
    start_network_module(agent);
}

void agent_destroy(struct chip_agent* agent)
{
    if (agent == NULL)
    {
        return;
    }

    free(agent);
}

void agent_run_network(struct chip_agent* agent)
{
    agent = agent; //supress compiler warning
    //implementation
    return;
}




