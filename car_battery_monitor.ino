
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

const int BatteryPin = 34; 

int adc_read = 0;
float battery_voltage = 0;

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("Circuit Desolator"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() 
{
  adc_read = analogRead(BatteryPin);

  //using R1 = 5k and R2 = .650k
  
  battery_voltage = (adc_read*(3.3/4096)*(5.650))/0.650;
  Serial.println(battery_voltage);
  SerialBT.println(battery_voltage);
  
  delay(1000);
}
