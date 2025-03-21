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
} ChipInterface;

typedef void (*ChipRegisterCallback)(char* name, const ChipInterface* interface);

#endif