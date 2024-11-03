#include <Gyver433.h>

// ПИТАНИЕ 5В

const int pinRX = 13; //D7

Gyver433_RX<pinRX, 20> rx;

void setup() {

  Serial.begin(115200);
  delay(300);
  Serial.println("Start 433mhz Receiver!");
  
  attachInterrupt(pinRX, isr, CHANGE);  // прерывание пина радио по CHANGE
}

IRAM_ATTR void isr(){
  rx.tickISR();
};

void loop() {
  if (rx.gotData()) {                   
    Serial.write(rx.buffer, rx.size); 
    Serial.println();
  }
}
