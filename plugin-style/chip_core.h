#ifndef CHIP_CORE_H
#define CHIP_CORE_H

#include <stddef.h>

/* ---------------------------------------------------------
 * 結構與介面定義 (對應 Linux 的驅動與設備結構)
 * --------------------------------------------------------- */

typedef void (*ChipFunc)(void* chip);

typedef struct {
    size_t data_size;
    ChipFunc init;
    ChipFunc shutdown;
    ChipFunc start;
    ChipFunc stop;
} ChipInterface;

typedef void (*ChipRegisterCallback)(char* name, const ChipInterface* interface);

/* 提前宣告不透明結構 (Opaque pointer)，隱藏內部實作細節 */
struct chip_agent; 

/* ---------------------------------------------------------
 * 核心 API 宣告 (對應 Linux 的 i2c-core 提供的方法)
 * --------------------------------------------------------- */

void agent_register_chip(char* name, const ChipInterface* interface);
void agent_cleanup_registry(void);

struct chip_agent* agent_create(char* name);
void agent_destroy(struct chip_agent* agent);

void agent_set(struct chip_agent* agent);
void agent_run_network(struct chip_agent* agent);

#endif /* CHIP_CORE_H */
