#ifndef CHIP_AGENT_H
#define CHIP_AGENT_H


enum chips {
    QUALCOMM_DRAGONWING,
    QUALCOMM_SNAPDRAGON,
    MARVELL_LINKSTREET,
    UNKNOWN_CHIP
};

struct chip_agent* agent_create(void);
void agent_destroy(struct chip_agent* agent);

void agent_set(struct chip_agent* agent, enum chips chip);
void agent_run_network(struct chip_agent* agent);


#endif