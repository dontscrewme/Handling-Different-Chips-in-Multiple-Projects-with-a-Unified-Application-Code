#ifndef CHIP_AGENT_H
#define CHIP_AGENT_H

#include "chip_interface.h"


void agent_register_chip(char* name, const ChipInterface* interface);
void agent_cleanup_registry(void);

struct chip_agent* agent_create(char* name);
void agent_destroy(struct chip_agent* agent);

void agent_set(struct chip_agent* agent);
void agent_run_network(struct chip_agent* agent);


#endif