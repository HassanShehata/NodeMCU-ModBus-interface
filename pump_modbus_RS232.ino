#include "ModbusMaster232.h" 
#include <SoftwareSerial.h>
// Instantiate ModbusMaster object as slave ID 1
  ModbusMaster232 node(1);

void setup()
{ 
  Serial.begin(115200); 
  node.begin(9600);  // Modbus RTU
  delay(100);
}

void loop()
{
  int Mdelay = 5000; 
  Serial.println("Connected "); 
  Serial.println("Modbus RTU Master Online");
  node.readHoldingRegisters(10000, 9); 
  Serial.print("[0] ");
  Serial.print(node.getResponseBuffer(5)); 
  node.clearResponseBuffer();
  delay(Mdelay);  
  delay(3000);
}

