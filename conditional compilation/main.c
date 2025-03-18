#include <stdint.h>
#include <stdio.h>
#include "chip_agent.h"


int main(void) {

	struct chip_agent* network_chip = agent_create();
	agent_set(network_chip);
	agent_run_network(network_chip);
	agent_destroy(network_chip);



	return 0;
}