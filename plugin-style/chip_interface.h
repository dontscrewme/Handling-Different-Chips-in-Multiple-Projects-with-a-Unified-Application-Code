#ifndef CHIP_INTERFACE_H
#define CHIP_INTERFACE_H
#include <stddef.h>


typedef void (*ChipFunc)(void* chip);

typedef struct {
    size_t data_size;
    ChipFunc init;
    ChipFunc shutdown;
    ChipFunc start;
    ChipFunc stop;
} struct chip_driver;

// 新增：用於記錄註冊資訊的資料結構
typedef struct {
    const char* name;
    const struct chip_driver* interface;
} ChipRegistryNode;

// 新增：利用連結器將此結構體強制放入名為 "chip_registry_sec" 的特定記憶體區段
#define REGISTER_CHIP(chip_name_str, interface_ptr) \
    __attribute__((used, section("chip_registry_sec"))) \
    static const ChipRegistryNode __chip_reg_node = { \
        .name = chip_name_str, \
        .interface = interface_ptr \
    }

#endif