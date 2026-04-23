#ifndef CHIP_CORE_H
#define CHIP_CORE_H

#include <stddef.h>

/* 提前宣告不透明結構 (Opaque pointer)，隱藏內部實作細節 */
struct chip_agent; 

typedef int (*ChipProbe)(struct chip_agent* agent);
typedef void (*ChipRemove)(struct chip_agent* agent);
typedef void (*ChipOp)(struct chip_agent* agent);

typedef struct {
    /* 刪除 data_size，框架不需知道硬體私有資料大小 */
    ChipProbe probe;
    ChipRemove remove;
    ChipOp start;
    ChipOp stop;
} ChipInterface;


/* ---------------------------------------------------------
 * 核心 API 宣告 (對應 Linux 的 i2c-core 提供的方法)
 * --------------------------------------------------------- */

void agent_register_chip(char* name, const ChipInterface* interface);
void agent_unregister_chip(char* name);

struct chip_agent* agent_create(char* name);
void agent_destroy(struct chip_agent* agent);

int agent_set(struct chip_agent* agent);
void agent_run_network(struct chip_agent* agent);

/* 新增：供 Driver 端設定與取得私有資料的 API (對應 dev_set_drvdata) */
void agent_set_drvdata(struct chip_agent* agent, void* data);
void* agent_get_drvdata(struct chip_agent* agent);

#endif /* CHIP_CORE_H */
