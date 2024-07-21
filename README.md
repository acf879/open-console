# About Open-Console
Open-Console is exactly what it sounds like. An open-source community built console to allow the creation of games for consoles rather than just PCs. This project is inspired by older consoles and games that required extreme control over all systems due to the limited resources. This console however should have many more resources available but allows the user to have access to everything for the console. The RTOS system for the console is built on Zephyr RTOS which is a board agnostic RTOS so multiple designs for the console for several boards can exist simultaniously allowing flexibility for the developer.

# Guidelines
To keep the system as bug free as possible with the community the flags -Wall will be used to discover more errors. -Wextra, -Werror and -pendantic would be a great addition but as zephyr does not cleanly compile it will produce a bunch of warnings regardless of the systems clean code.

# Building Basic System
In the repositry the system_base folder is the folder to create the base of the system with the games being compiled in seperate folders.
In the system_base folder a Makefile exists to allow for ease of compiling the system rather than having to type out the west build commands.

```
cd system_base
```

In the Makefile several make options are available currently such as clean, base_esp32, base_esp32s3, flash, menu, ram_report, rom_report, monitor_esp32, monitor_esp32s3 sysbuild_esp32 and sysbuild_esp32s3. Clean deletes the build directory, base_* builds the consoles main system, flash flashes the device, ram_report shows the ram usage, rom report the rom usage and sysbuild_* builds the bootloader for mcuboot and monitor_* monitors the connection through minicom 

>[!TIP]
>West can be used for a serial connection instead of minicom as well

## What is planned to be implemented shortly
Currently there are plans on getting a micro usb connected with the board to act as long term storage to store games, adding a watchdog timer, adding a physics engine and showing a basic message on a monitor (currently there are plans only for hdmi but it would be nice to have display port be supported)

# Open-Console Setup
## Ubuntu specific setup
- Step 1 -- Upgrade and update package manager
```
sudo apt upgrade && sudo apt upgrade
```
- Step 2 -- Get and install dependencies

>[!NOTE]
>Ubuntu version lower than 22.04
```
wget https://apt.kitware.com/kitware-archive.sh
sudo bash kitware-archive.sh
sudo apt install --no-install-recommends git cmake ninja-build gperf \
  ccache dfu-util device-tree-compiler wget \
  python3-dev python3-pip python3-setuptools python3-tk python3-wheel xz-utils file \
  make gcc gcc-multilib g++-multilib libsdl2-dev libmagic1
sudo apt-get install doxygen
```
>[!NOTE]
>Ubuntu version 22.04 and above
```
sudo apt install --no-install-recommends git cmake ninja-build gperf \
  ccache dfu-util device-tree-compiler wget \
  python3-dev python3-pip python3-setuptools python3-tk python3-wheel xz-utils file \
  make gcc gcc-multilib g++-multilib libsdl2-dev libmagic1
```
## Fedora specific setup
- Step 1 -- Upgrade and update package manager
```
sudo dnf upgrade && sudo dnf update
```
- Step 2 -- Get and install dependencies
> [!WARNING]
> If a older version of cmake is preinstalled, a newer one needs to be used for zephyr. <br/>See https://docs.zephyrproject.org/latest/develop/getting_started/installation_linux.html#installation-linux for more information.

```
sudo dnf group install "Development Tools" "C Development Tools and Libraries"
sudo dnf install cmake ninja-build gperf dfu-util dtc wget which \
  python3-pip python3-tkinter xz file python3-devel SDL2-devel
sudo dnf install doxygen
```
## Common parts of the setup
- Step 3 -- Check dependency versions
```
cmake --version && python3 --version && dtc --version
```

- Step 4 -- Create zephyr base repositry
```
pip3 install --user -U west
echo 'export PATH=~/.local/bin:"$PATH"' >> ~/.bashrc
source ~/.bashrc
west init ~/zephyrproject
cd ~/zephyrproject
west update
west zephyr-export
pip3 install --user -r ~/zephyrproject/zephyr/scripts/requirements.txt
```
- Step 5 -- Install zephyr sdk
```
cd ~
wget https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v0.16.8/zephyr-sdk-0.16.8_linux-x86_64.tar.xz
wget -O - https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v0.16.8/sha256.sum | shasum --check --ignore-missing
tar xvf zephyr-sdk-0.16.8_linux-x86_64.tar.xz
cd zephyr-sdk-0.16.8
./setup.sh
sudo cp ~/zephyr-sdk-0.16.8/sysroots/x86_64-pokysdk-linux/usr/share/openocd/contrib/60-openocd.rules /etc/udev/rules.d
sudo udevadm control --reload
```
- Step 6 -- Adding our repositry
>[!TIP]
>When ssh is set up use this as it will not ask you to login after confirming the setup
```
git clone git@github.com:acf879/open-console.git
```
>[!TIP]
>If ssh is not setup use this link to clone the repo
```
git clone https://github.com/acf879/open-console.git
```
- Step 7 -- Folder structure
>[!CAUTION]
>Folder structures are very important for zephyr linking from the zephyr repositry to our repositry.
>The following folder structure was created for this repositry

```
~
├──zephyr-sdk-0.16.8
└──projects
    |
    ├──open-console-project
    .   ├──open-console
        |    └──.
        ├──bootloader
        |    └──.
        ├──modules
        |    └──.
        ├──tools
        |    └──.
        └──zephyr
             └──.
```

- Step 8 -- Configuring zephyr for our repositry

>[!IMPORTANT]
>In the directory containing the zephyr repositry edit the configuration file by doing the following command
```
nvim .west/config
```
>[!IMPORTANT]
>The config file should look like this
```
[manifest]
path = zephyr
file = west.yml

[zephyr]
base = zephyr
```
>[!IMPORTANT]
>Change file to look like the following
```
[manifest]
path = open-console
file = west.yml

[zephyr]
base = zephyr
```


- Step 9 -- Update to zephyr version
```
cd open-console && west update
```
