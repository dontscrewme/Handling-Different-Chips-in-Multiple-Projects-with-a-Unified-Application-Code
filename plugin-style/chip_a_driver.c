#include <stdio.h>
#include <stdlib.h>
#include "chip_core.h"
#include "chip_a.h"

static int probe(struct chip_client* agent) {
    /* Driver 自行配置記憶體 */
    struct dragonwing_NPA7* chip = malloc(sizeof(struct dragonwing_NPA7));
    if (chip == NULL) {
        return -1;
    }

    dragonwing_NPA7_init(chip);
    /* 將配置好的記憶體綁定至核心 agent 結構中 */
    agent_set_drvdata(agent, chip);
    return 0;
}

static void my_remove(struct chip_client* agent) {
    /* 取回硬體物件指標 */
    struct dragonwing_NPA7* chip = agent_get_drvdata(agent);
    if (chip != NULL) {
        dragonwing_NPA7_shutdown(chip);
        /* Driver 自行釋放記憶體 */
        free(chip);
    }
}

static void start(struct chip_client* agent) {
    struct dragonwing_NPA7* chip = agent_get_drvdata(agent);
    if (!chip) return;
    dragonwing_NPA7_set_register1(chip, 1);
    dragonwing_NPA7_set_register2(chip, 1);
    printf("dragonwing_NPA7 starts!\n");
}

static void stop(struct chip_client* agent) {
    struct dragonwing_NPA7* chip = agent_get_drvdata(agent);
    if (!chip) return;

    dragonwing_NPA7_set_register1(chip, 0);
    dragonwing_NPA7_set_register2(chip, 0);
    printf("dragonwing_NPA7 stop!\n");
}

static const struct chip_driver CHIP_A_INTERFACE = {
    .probe = probe,
    .remove = my_remove,
    .start = start,
    .stop = stop
};

/* 模擬 Linux kernel 的 module_init() */
__attribute__((constructor))
static void chip_a_init_module(void)
{
    agent_register_driver("QUALCOMM_DRAGONWING", &CHIP_A_INTERFACE);
}

/* 模擬 Linux kernel 的 module_exit() */
__attribute__((destructor))
static void chip_a_exit_module(void)
{
    agent_unregister_driver("QUALCOMM_DRAGONWING");
}
