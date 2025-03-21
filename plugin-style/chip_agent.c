#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chip_agent.h"
#include "uthash.h"

#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 200809L  // Enable POSIX functions
#endif

struct chip_agent {
    void* chip_data;
    const ChipInterface* interface;
};

typedef struct {
    char* name;
    const ChipInterface* interface;
    UT_hash_handle hh;
} ChipRegistryEntry;

static ChipRegistryEntry* chip_registry = NULL;

void agent_register_chip(char* name, const ChipInterface* interface) {
    ChipRegistryEntry* entry = NULL;
    HASH_FIND_STR(chip_registry, name, entry);
    if (entry != NULL)
    {
        return;
    }

    entry = malloc(sizeof(ChipRegistryEntry));
    entry->name = strdup(name);
    entry->interface = interface;
    
    HASH_ADD_KEYPTR(hh, chip_registry, entry->name, strlen(name), entry);
}

struct chip_agent* agent_create(char* name) {
    ChipRegistryEntry* entry = NULL;
    HASH_FIND_STR(chip_registry, name, entry);
    if (entry == NULL)
    {
        return NULL;
    }

    struct chip_agent* agent = malloc(sizeof(struct chip_agent));
    agent->interface = entry->interface;
    agent->chip_data = malloc(entry->interface->data_size);
    return agent;
}

void agent_destroy(struct chip_agent* agent)
{
    if (agent == NULL)
    {
        return;
    }

    agent->interface->stop(agent->chip_data);
    agent->interface->shutdown(agent->chip_data);
    free(agent->chip_data);
    free(agent);
}

void agent_cleanup_registry(void)
{
    ChipRegistryEntry* entry, *tmp;
    HASH_ITER(hh, chip_registry, entry, tmp) {
        HASH_DEL(chip_registry, entry);
        free((char*)entry->name);
        free(entry);
    }
}


void agent_set(struct chip_agent* agent)
{
    if (agent == NULL)
    {
        return;
    }

    agent->interface->init(agent->chip_data);
    agent->interface->start(agent->chip_data);
}



void agent_run_network(struct chip_agent* agent)
{
    agent = agent; //supress compiler warning
    //implementation
    return;
}