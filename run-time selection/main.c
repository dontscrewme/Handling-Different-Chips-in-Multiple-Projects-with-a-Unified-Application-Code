#include <stdint.h>
#include <stdio.h>
#include "chip_agent.h"


int main(void) {

	struct chip_agent* network_chip = agent_create();
	agent_set(network_chip, QUALCOMM_DRAGONWING);
	agent_run_network(network_chip);

	agent_set(network_chip, MARVELL_LINKSTREET);
	agent_run_network(network_chip);

	agent_destroy(network_chip);



	return 0;
}
