#include "chip_core.h"

/* 必須與驅動程式約定好相同的結構定義 */
struct chip_a_config {
    int default_reg1;
    int default_reg2;
};

int main()
{

    /* 模擬從 DT 解析出來的硬體屬性 */
    struct chip_a_config dt_props = {
        .default_reg1 = 100,
        .default_reg2 = 200
    };
    /* 模擬系統啟動時，解析 DT 並向核心宣告設備存在 */
    struct chip_client* agent = agent_register_device("QUALCOMM_DRAGONWING", &dt_props);
	if (agent != NULL) {
        /* 設備已經在 register_device 內部自動 match 並 probe 完畢 */
        agent_run_network(agent);
        
        /* 模擬設備拔除或系統關機 */
        agent_unregister_device(agent);
    }
    return 0;
}