#include "chip_core.h"

int main()
{
    /* 模擬系統啟動時，解析 DT 並向核心宣告設備存在 */
    struct chip_client* agent = agent_register_device("QUALCOMM_DRAGONWING");
	if (agent != NULL) {
        /* 設備已經在 register_device 內部自動 match 並 probe 完畢 */
        agent_run_network(agent);
        
        /* 模擬設備拔除或系統關機 */
        agent_unregister_device(agent);
    }
    return 0;
}