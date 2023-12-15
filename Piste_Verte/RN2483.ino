#include <TheThingsNetwork.h>
#include <TheThingsMessage.h>
#include <SoftwareSerial.h>

#define rxPin 10

#define txPin 11


#define debugSerial Serial
SoftwareSerial mySerial =  SoftwareSerial(rxPin, txPin);
#define loraSerial mySerial
// Replace REPLACE_ME with TTN_FP_EU868 or TTN_FP_US915
#define freqPlan TTN_FP_EU868

TheThingsNetwork ttn(loraSerial, debugSerial, freqPlan);

// Set your AppEUI and AppKey
const char *appEui = "6aadd25252dc20ea";
const char *appKey = "2827F5D8991A743B42BEB51F297AD80A";
//6aadd25252dc20ea for app EUI
//2827F5D8991A743B42BEB51F297AD80A key for join
devicedata_t data = api_DeviceData_init_default;

void setup()
{
  loraSerial.begin(57600);
  debugSerial.begin(9600);
  debugSerial.println("-- STATUS");
  ttn.showStatus();

  debugSerial.println("-- JOIN");
  ttn.join(appEui, appKey);  

  ttn.onMessage(message);

  // Select what fields to include in the encoded message
  data.has_level = true;
}

void loop()
{
  /*debugSerial.println("Device Information");
  debugSerial.println();
  ttn.showStatus();
  
  debugSerial.println();
  debugSerial.println("Use the EUI to register the device for OTAA");
  debugSerial.println("-------------------------------------------");
  debugSerial.println();
  */
  debugSerial.println("-- LOOP");

// Read the sensors
  
  // Encode the selected fields of the struct as bytes
  byte buffer[2];
  int val = analogRead(0);
  debugSerial.println("-- data");
  debugSerial.println(val);
  //data.level = analogRead(0);
  //debugSerial.println("-- data");
  //debugSerial.println(data.level);
  //size_t size;
  //TheThingsMessage::encodeDeviceData(&data, &buffer, &size);
  buffer[0] = val & 0xFF;
  buffer[1] = (val >> 8) & 0xFF;
  
  ttn.sendBytes(buffer, 2);
  delay(2000);
  
}

void message(const uint8_t *payload, size_t length, port_t port)
{
  //standard message always received on port 100 or more
  if (port >= 100)
  {
    appdata_t appData = api_AppData_init_default;
    TheThingsMessage::decodeAppData(&appData, payload, length);
  }
}
