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
    const struct chip_driver* interface;
    UT_hash_handle hh;
} ChipRegistryEntry;

static ChipRegistryEntry* chip_registry = NULL;

void chip_register_driver(const char* name, const struct chip_driver* interface) {
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

void chip_unregister_driver(const char* name) {
    ChipRegistryEntry* entry = NULL;
    HASH_FIND_STR(chip_registry, name, entry);
    if (entry != NULL) {
        HASH_DEL(chip_registry, entry);
        free((char*)entry->name);
        free(entry);
    }
}

struct chip_client {
    void* drvdata;
    void* dev_config; /* 模擬指向 device_node 的指標 */
    const struct chip_driver* interface;
};

void* chip_get_config(struct chip_client* agent) {
    return agent ? agent->dev_config : NULL;
}

void chip_set_drvdata(struct chip_client* agent, void* data) {
    if (agent) agent->drvdata = data;
}

void* chip_get_drvdata(struct chip_client* agent) {
    return agent ? agent->drvdata : NULL;
}

struct chip_client* chip_register_device(const char* name, void* dev_config) {
    ChipRegistryEntry* entry = NULL;
    HASH_FIND_STR(chip_registry, name, entry);
    if (entry == NULL)
    {
        return NULL;
    }

    struct chip_client* agent = malloc(sizeof(struct chip_client));
    agent->interface = entry->interface;
    agent->drvdata = NULL;
    agent->dev_config = dev_config; /* 綁定 DT 設定資料 */

    /* 核心自動觸發 probe，完成綁定 */
    if (agent->interface->probe(agent) != 0) {
        free(agent);
        return NULL;
    }

    /* 模擬硬體綁定後自動啟動 (根據實際需求決定是否在此呼叫 start) */
    agent->interface->start(agent);

    return agent;
}

void chip_unregister_device(struct chip_client* agent)
{
    if (agent == NULL)
    {
        return;
    }

    agent->interface->stop(agent);
    agent->interface->remove(agent);
    free(agent);
}

void chip_run_network(struct chip_client* agent)
{
    agent = agent; //supress compiler warning
    //implementation
    return;
}
