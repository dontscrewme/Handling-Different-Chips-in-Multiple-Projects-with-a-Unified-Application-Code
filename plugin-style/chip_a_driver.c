#include <stdio.h>
#include <stdlib.h>
#include "chip_core.h"
#include "chip_a.h"


/* 定義驅動程式預期的屬性資料結構 (模擬 DT 中的 properties) */
struct chip_a_config {
    int default_reg1;
    int default_reg2;
};

static int probe(struct chip_client* agent) {
    /* Driver 自行配置記憶體 */
    struct dragonwing_NPA7* chip = malloc(sizeof(struct dragonwing_NPA7));
    if (chip == NULL) {
        return -1;
    }

    dragonwing_NPA7_init(chip);

    /* 模擬透過核心 API 讀取 DT 屬性 */
    struct chip_a_config* config = (struct chip_a_config*)chip_get_config(agent);
    if (config != NULL) {
        /* 根據傳入的設定檔修改硬體初始狀態 */
        dragonwing_NPA7_set_register1(chip, config->default_reg1);
        dragonwing_NPA7_set_register2(chip, config->default_reg2);
        printf("Probe with config: reg1=%d, reg2=%d\n", config->default_reg1, config->default_reg2);
    } else {
        /* 缺乏設定檔時的預設行為 */
        dragonwing_NPA7_set_register1(chip, 0);
        dragonwing_NPA7_set_register2(chip, 0);
    }
    /* 將配置好的記憶體綁定至核心 agent 結構中 */
    chip_set_drvdata(agent, chip);
    return 0;
}

static void my_remove(struct chip_client* agent) {
    /* 取回硬體物件指標 */
    struct dragonwing_NPA7* chip = chip_get_drvdata(agent);
    if (chip != NULL) {
        dragonwing_NPA7_shutdown(chip);
        /* Driver 自行釋放記憶體 */
        free(chip);
    }
}

static void start(struct chip_client* agent) {
    struct dragonwing_NPA7* chip = chip_get_drvdata(agent);
    if (!chip) return;
    dragonwing_NPA7_set_register1(chip, 1);
    dragonwing_NPA7_set_register2(chip, 1);
    printf("dragonwing_NPA7 starts!\n");
}

static void stop(struct chip_client* agent) {
    struct dragonwing_NPA7* chip = chip_get_drvdata(agent);
    if (!chip) return;

    dragonwing_NPA7_set_register1(chip, 0);
    dragonwing_NPA7_set_register2(chip, 0);
    printf("dragonwing_NPA7 stop!\n");
}

static const struct chip_driver chip_a_driver = {
    .probe = probe,
    .remove = my_remove,
    .start = start,
    .stop = stop
};

/* 模擬 Linux kernel 的 module_init() */
__attribute__((constructor))
static void chip_a_init_module(void)
{
    chip_register_driver("QUALCOMM_DRAGONWING", &chip_a_driver);
}

/* 模擬 Linux kernel 的 module_exit() */
__attribute__((destructor))
static void chip_a_exit_module(void)
{
    chip_unregister_driver("QUALCOMM_DRAGONWING");
}
