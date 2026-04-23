#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chip_core.h"
#include "uthash.h"

#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 200809L  // Enable POSIX functions
#endif

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

void agent_unregister_chip(char* name) {
    ChipRegistryEntry* entry = NULL;
    HASH_FIND_STR(chip_registry, name, entry);
    if (entry != NULL) {
        HASH_DEL(chip_registry, entry);
        free((char*)entry->name);
        free(entry);
    }
}

struct chip_agent {
    void* drvdata; /* 替代原先的 chip_data */
    const ChipInterface* interface;
};

void agent_set_drvdata(struct chip_agent* agent, void* data) {
    if (agent) agent->drvdata = data;
}

void* agent_get_drvdata(struct chip_agent* agent) {
    return agent ? agent->drvdata : NULL;
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
    agent->drvdata = NULL;
    return agent;
}

void agent_destroy(struct chip_agent* agent)
{
    if (agent == NULL)
    {
        return;
    }

    agent->interface->stop(agent);
    agent->interface->remove(agent);
    free(agent);
}

int agent_set(struct chip_agent* agent)
{
    if (agent == NULL)
    {
        return -1;
    }

    int ret = agent->interface->probe(agent);
    if (ret != 0) {
        /* probe 失敗，直接返回錯誤碼，不執行 start */
        return ret; 
    }

    agent->interface->start(agent);
    return 0;
}

void agent_run_network(struct chip_agent* agent)
{
    agent = agent; //supress compiler warning
    //implementation
    return;
}
