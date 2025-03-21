#include <stdio.h>
#include "chip_interface.h"
#include "chip_a.h"


static void init(void* chip) {
    dragonwing_NPA7_init((struct dragonwing_NPA7*)chip);
}

static void shutdown(void* chip) {
    dragonwing_NPA7_shutdown((struct dragonwing_NPA7*)chip);
}

static void start(void* chip) {
    struct dragonwing_NPA7* c = (struct dragonwing_NPA7*)chip;
    dragonwing_NPA7_set_register1(c, 1);
    dragonwing_NPA7_set_register2(c, 1);
    printf("dragonwing_NPA7 starts!\n");
}

static void stop(void* chip) {
    struct dragonwing_NPA7* c = (struct dragonwing_NPA7*)chip;
    dragonwing_NPA7_set_register1(c, 0);
    dragonwing_NPA7_set_register2(c, 0);
    printf("dragonwing_NPA7 stop!\n");
}

const ChipInterface CHIP_A_INTERFACE = {
    .data_size = sizeof(struct dragonwing_NPA7),
    .init = init,
    .shutdown = shutdown,
    .start = start,
    .stop = stop
};

void chip_a_adapter_register(char* name, ChipRegisterCallback callback)
{
    if (callback == NULL)
    {
        return;
    }

    callback(name, &CHIP_A_INTERFACE);
}
