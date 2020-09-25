# ArduinoCore-freertos(AVR)

## Usage

The project is still under development, you can install this package via Boards Manager in the future.

In this moment you need:

1. Find the sketchbook folder like that `/Users/username/Documents/Arduino`
2. `cd /hardware`
3. `git clone --branch avr --depth 1 https://github.com/MRNIU/ArduinoCore-freertos.git MRNIU/avr`
4. Open Arduino IDE
5. Select the board you need at `Tools->Board->ArduinoCore-freertos(AVR)`.

## Example

```c++

// This file is a part of MRNIU/ArduinoCore-freertos (https://github.com/MRNIU/ArduinoCore-freertos).
//
// example.ino for MRNIU/ArduinoCore-freertos.

// The Serial will print A and B in two lins.

#include "FreeRTOS/include/FreeRTOS.h"
#include "FreeRTOS/include/task.h"
#include "FreeRTOS/include/semphr.h"

SemaphoreHandle_t xSerialSemaphore;
void println_A(void *argument);
void println_B(void *argument);

void println_A(void *argument) {
  if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE ){
    Serial.println("A");
    xSemaphoreGive( xSerialSemaphore );
  }
  vTaskDelay(1);
}

void println_B(void *argument) {
  if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE ){
    Serial.println("B");
    xSemaphoreGive( xSerialSemaphore );
  }
  vTaskDelay(1);
}

void setup() {
  Serial.begin(9600);
  if ( xSerialSemaphore == NULL ) {
    xSerialSemaphore = xSemaphoreCreateMutex();
    if ( ( xSerialSemaphore ) != NULL ) {
      xSemaphoreGive( ( xSerialSemaphore ) );
    }
  }
  xTaskCreate(println_A, "test_A", 128, NULL, 1, NULL);
  xTaskCreate(println_B, "test_B", 128, NULL, 1, NULL);
}

void loop() {
}
```

