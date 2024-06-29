CONFIGS = ./custom_boards/configs
OVERLAYS = ./custom_boards/overlays
BIN = ./build/zephyr/zephyr.bin

CFLAGS="-Wall" #-Wextra -Wpedantic -Werror <-- disabled due to zephyr having these itself
WRNS=-DCMAKE_CXX_FLAGS=$(CFLAGS)

console_sys:
	west build -p -b esp32_devkitc_wroom/esp32/procpu -- \
		-DDTC_OVERLAY_FILE=$(OVERLAYS)/esp32.overlay \
		-DEXTRA_CONF_FILE=$(CONFIGS)/esp32.conf $(WRNS)


sysbuild_esp32:
	west build -p --sysbuild -b esp32_devkitc_wroom/esp32/procpu -- \
		-DDTC_OVERLAY_FILE=$(OVERLAYS)/esp32.overlay $(WRNS)

clean: 
	rm -rf ./build/

flash:
	west flash --esp-device /dev/ttyUSB0

menu:
	west build -t menuconfig

ram_report:
	west build -t ram_report

rom_report:
	west build -t rom_report
