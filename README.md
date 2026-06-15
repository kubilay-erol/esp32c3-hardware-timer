# ESP32-C3 Hardware Timer

A lightweight C++ class for managing precise, non-blocking delays on the ESP32-C3 by directly reading the hardware `SYSTIMER` registers. No framework overhead, no background RTOS dependencies.

## Features
* **Direct Register Access:** Bypasses `millis()` and talks directly to MMIO registers (`0x6001F00C`).
* **Multi-Channel:** Track up to 3 independent timing intervals simultaneously using a single class instance.
* **Microsecond Precision:** Subtraction happens before division, preventing premature truncation bugs.

## Example Usage

```cpp
#include "Time.h"

Time timer;

void setup() {
    timer.set_ref(0); // Start channel 0
    timer.set_ref(1); // Start channel 1
}

void loop() {
    // Channel 0 triggers every 2 seconds
    if (timer.is_delay_complete(2, 0)) { 
        toggleLED();
        timer.set_ref(0); 
    }

    // Channel 1 triggers every 10 seconds independently
    if (timer.is_delay_complete(10, 1)) {
        readSensor();
        timer.set_ref(1); 
    }
}
