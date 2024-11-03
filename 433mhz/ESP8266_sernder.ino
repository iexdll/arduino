#include <Gyver433.h>

const int pinRX = 13; //D7
Gyver433_TX<pinRX> tx;

void setup() {
  Serial.begin(115200);
  delay(100);
  Serial.println("Start 433mhz Sender!");
}

char data[] = "Hello from #xx";
byte count = 0;                

void loop() {

  data[12] = (count / 10) + '0';
  data[13] = (count % 10) + '0';
  if (++count >= 100) count = 0;

  tx.sendData(data);

  Serial.println(data);

  delay(100);
}
