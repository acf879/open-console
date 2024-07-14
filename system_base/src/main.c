#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>


// Does not need to reference anything just needs to be linked
#include "terminal.h"

int main() {
	printf("Hello World! %s\n", CONFIG_BOARD_TARGET);
	for (;;) {
        k_msleep(1000);
    }
    return 0;
}
