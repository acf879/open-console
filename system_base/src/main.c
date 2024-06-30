/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>

#include <zephyr/kernel.h>
#include <zephyr/device.h>

const struct device* dev = DEVICE_DT_GET(DT_NODELABEL(spi2));

int main() {
    if (!device_is_ready(dev)) {
        return -1;
    }
	printf("Hello World! %s\n", CONFIG_BOARD_TARGET);

	return 0;
}
