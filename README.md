# About Open-Console

# Building Basic System

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
