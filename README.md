# ArduinoCore-freertos(PortentaH7)

Based on https://github.com/stm32duino/Arduino_Core_STM32

## Usage

The project is still under development, you can install this package via Boards Manager in the future.

In this moment you need:

1. Install https://github.com/stm32duino/Arduino_Core_STM32
2. Find the sketchbook folder like that `/Users/username/Documents/Arduino`
3. `cd /hardware`
4. `git clone --branch PortentaH7 --depth 1 https://github.com/MRNIU/ArduinoCore-freertos.git MRNIU/stm32`
5. Open Arduino IDE
6. Now you can find M4 and M7 under `Tools->Board->ArduinoCore-freertos(PortentaH7) `
7. Select the core you need.

ps: if you see "dfu-util.sh: error=13, Permission denied", run use `chmod +x /Users/username/Library/Arduino15/packages/STM32/tools/STM32Tools/1.4.0/tools/macosx/dfu-util.sh`