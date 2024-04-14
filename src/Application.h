#include "imgui.h"
#include <string>

class Application{
public:
    Application();
    ~Application();
    void Run();
    ImVec4 clear_color;
private:
    void upload();
    void add(int pinNum);
    int counter = 0;
    std::string command = R"(ls
            avr-g++ -c -Os -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10813 "-Ivendor/arduino/hardware/arduino/avr/cores/arduino" "-Ivendor/arduino/hardware/arduino/avr/variants/eightanaloginputs" "led.cpp" -o "led.o"
            avr-gcc -w -Os -mmcu=atmega328p   -o "led.elf" "led.o"  "vendor/core_arduino_avr_nano_cpu_atmega328old.a"
            avr-objcopy -j .text -j .data -O ihex led.elf led.hex
            avrdude -Cvendor/avrdude.conf -p atmega328p -D -Uflash:w:"led.hex" -v -v -b57600 -carduino -P /dev/ttyUSB0)";

    std::string strip = R"(
                        )";
};