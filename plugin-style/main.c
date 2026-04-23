#include "chip_core.h"

int main()
{
    struct chip_agent* agent = agent_create("QUALCOMM_DRAGONWING");
	agent_set(agent);
    agent_run_network(agent);
    agent_destroy(agent);
	agent_cleanup_registry();
    return 0;
}