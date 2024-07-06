#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>

#include "helper_functions.h"
#include "terminal.h"

int main() {
	printf("Hello World! %s\n", CONFIG_BOARD_TARGET);
	for (;;) {
        k_msleep(1000);
    }
    return 0;
}
