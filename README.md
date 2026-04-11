# data-structure-benchmarks

Microbenchmark that measures fill, sequential access, and mid-point insert times for `std::vector`, a C-style `int*` array, and `std::list` at `TEST_SIZE = 1000`, printing the elapsed microseconds over the serial port.

## Platform

ESP32 (`esp32dev`) with the Arduino framework, built through PlatformIO.

## Build

```bash
pio run
pio run -t upload
pio device monitor -b 9600
```

## Example results

```
Vector filling time (uS) : 485
Array filling time (uS)  : 28
List filling time (uS)   : 12474
Vector access time (uS)  : 21
Array access time (uS)   : 17
List access time (uS)    : 38
Vector insert time (uS)  : 168518
List insert time (uS)    : 30847
```
