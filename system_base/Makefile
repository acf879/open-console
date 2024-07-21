CONFIGS = ./custom_boards/configs
OVERLAYS = ./custom_boards/overlays
BIN = ./build/zephyr/zephyr.bin

CFLAGS="-Wall"
WRNS=-DCMAKE_CXX_FLAGS=$(CFLAGS)

base_esp32:
	west build -p -b esp32_devkitc_wroom/esp32/procpu -- \
		-DDTC_OVERLAY_FILE=$(OVERLAYS)/esp32.overlay \
		-DEXTRA_CONF_FILE=$(CONFIGS)/esp32.conf $(WRNS)

base_esp32s3:
	west build -p -b esp32s3_devkitc/esp32s3/procpu -- \
		-DDTC_OVERLAY_FILE=$(OVERLAYS)/esp32s3.overlay \
		-DEXTRA_CONF_FILE=$(CONFIGS)/esp32s3.conf $(WRNS)

sysbuild_esp32:
	west build -p --sysbuild -b esp32_devkitc_wroom/esp32/procpu -- \
		-DDTC_OVERLAY_FILE=$(OVERLAYS)/esp32.overlay $(WRNS)

sysbuild_esp32s3:
	west build -p --sysbuild -b esp32s3_devkitc/esp32s3/procpu -- \
		-DDTC_OVERLAY_FILE=$(OVERLAYS)/esp32s3.overlay $(WRNS)

clean: 
	rm -rf ./build/

flash_esp32:
	west flash --esp-device /dev/ttyUSB0

flash_esp32s3:
	west flash --esp-device /dev/ttyACM0

menu:
	west build -t menuconfig

ram_report:
	west build -t ram_report

rom_report:
	west build -t rom_report

monitor_esp32:
	./scripts/serial_port esp32

monitor_esp32s3:
	./scripts/serial_port esp32s3

generate_documentation:
	cd doc && ./scripts/generate_doc && cd ..

install_document_dependencies:
	cd doc && pip3 install -r ./requirements.txt && cd ..
