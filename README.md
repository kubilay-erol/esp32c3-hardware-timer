# ESP32-C3 Hardware Timer

A lightweight C++ class for managing precise, non-blocking delays on the ESP32-C3 by directly reading the hardware `SYSTIMER` registers. No framework overhead, no background RTOS dependencies.

## Features
* **Direct Register Access:** Bypasses `millis()` and talks directly to MMIO registers (`0x6001F00C`).
* **Multi-Channel:** Track up to 3 independent timing intervals simultaneously using a single class instance.
* **Microsecond Precision:** Subtraction happens before division, preventing premature truncation bugs.
