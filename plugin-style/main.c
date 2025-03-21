#include "chip_agent.h"
#include "chip_a_adapter.h"

int main()
{
    chip_a_adapter_register("QUALCOMM_DRAGONWING", &agent_register_chip);
    struct chip_agent* agent = agent_create("QUALCOMM_DRAGONWING");
	agent_set(agent);
    agent_run_network(agent);
    agent_destroy(agent);
	agent_cleanup_registry();
    return 0;
}