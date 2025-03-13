#include <stdint.h>
#include <stdio.h>
#include "chip_agent.h"


int main(void) {

	struct agent chip = {0};
	agent_init(&chip);
	int element123 = agent_get_element123(&chip);
	printf("element123: %d\n", element123);
	
	return 0;
}