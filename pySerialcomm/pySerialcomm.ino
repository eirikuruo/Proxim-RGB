#include <CapacitiveSensor.h>

const unsigned int BAUD_RATE = 9600;
const unsigned int SERIAL_DELAY = 5;

CapacitiveSensor   cs_3_2 = CapacitiveSensor(3,2);        // 40 megohm resistor between pins 4 & 2, pin 2 is sensor pin, add wire, foil
CapacitiveSensor   cs_4_5 = CapacitiveSensor(4,5);        // 20 megohm resistor between pins 4 & 6, pin 6 is sensor pin, add wire, foil
CapacitiveSensor   cs_4_8 = CapacitiveSensor(4,8);        // 20 megohm resistor between pins 4 & 8, pin 8 is sensor pin, add wire, foil
CapacitiveSensor   cs_4_7 = CapacitiveSensor(4,7);      // 20 megohm resistor between pins 4 & 13, pin 8 is sensor pin, add wire, foil

void setup(){
Serial.begin(BAUD_RATE);
}
void loop() {
  const int MAX_VAR_NAME = 3;
  char var_name[MAX_VAR_NAME + 1];
  //int r1=1,g1=1,b1=1,v1=1;
   long v1 =  cs_3_2.capacitiveSensor(30);
   long r1 =  cs_4_5.capacitiveSensor(30);
   long g1 =  cs_4_8.capacitiveSensor(30);
   long b1 =  cs_4_7.capacitiveSensor(30);
      
   
  if (Serial.available()) {
    int i = 0;
    while (Serial.available() && i < MAX_VAR_NAME){
      const char c = Serial.read();
      if (c != -1 && c != '\n')
      var_name[i++] = c;
      delay(SERIAL_DELAY);
    }
    var_name[i] = 0;
    if (strlen(var_name) > 1 && (var_name[0] == 'r')){
        //Serial.print("R1");
        Serial.println(r1);
    }
    else if (strlen(var_name) > 1 && (var_name[0] == 'g')){
        //Serial.print("G1");
        Serial.println(g1);
    }
    else if (strlen(var_name) > 1 && (var_name[0] == 'b')){
        //Serial.print("B1");
        Serial.println(b1);
    }
    else if (strlen(var_name) > 1 && (var_name[0] == 'v')){
        //Serial.print("V1");
        Serial.println(v1);
    }
    else
      Serial.print(0);
  }
}
