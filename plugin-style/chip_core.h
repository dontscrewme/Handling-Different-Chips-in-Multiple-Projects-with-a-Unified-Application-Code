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


/* 驅動端 (Driver) 註冊介面 */
void agent_register_driver(const char* name, const ChipInterface* interface);
void agent_unregister_driver(const char* name);

/* 設備端 (Device) 註冊介面 (模擬設備樹或 i2c_board_info 實例化) */
struct chip_agent* agent_register_device(const char* name);
void agent_unregister_device(struct chip_agent* agent);

void agent_run_network(struct chip_agent* agent);

/* 新增：供 Driver 端設定與取得私有資料的 API (對應 dev_set_drvdata) */
void agent_set_drvdata(struct chip_agent* agent, void* data);
void* agent_get_drvdata(struct chip_agent* agent);

#endif /* CHIP_CORE_H */
