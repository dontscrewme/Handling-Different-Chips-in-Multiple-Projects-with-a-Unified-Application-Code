#ifndef CHIP_CORE_H
#define CHIP_CORE_H

#include <stddef.h>

/* 提前宣告不透明結構 (Opaque pointer)，隱藏內部實作細節 */
struct chip_client; 

struct chip_driver {
    int (*probe)(struct chip_client* agent);
    void (*remove)(struct chip_client* agent);
    void (*start)(struct chip_client* agent);
    void (*stop)(struct chip_client* agent);
};

void* chip_get_config(struct chip_client* agent);

/* 驅動端 (Driver) 註冊介面 */
void chip_register_driver(const char* name, const struct chip_driver* interface);
void chip_unregister_driver(const char* name);

/* 設備端 (Device) 註冊介面 (模擬設備樹或 i2c_board_info 實例化) */
struct chip_client* chip_register_device(const char* name, void* dev_config);
void chip_unregister_device(struct chip_client* agent);

void chip_run_network(struct chip_client* agent);

/* 新增：供 Driver 端設定與取得私有資料的 API (對應 dev_set_drvdata) */
void chip_set_drvdata(struct chip_client* agent, void* data);
void* chip_get_drvdata(struct chip_client* agent);

#endif /* CHIP_CORE_H */
