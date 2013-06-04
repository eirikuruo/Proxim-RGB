#include <CapacitiveSensor.h>

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10 megohm between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50 kilohm - 50 megohm. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 * Best results are obtained if sensor foil and wire is covered with an insulator such as paper or plastic sheet
 */


CapacitiveSensor   cs_3_2 = CapacitiveSensor(3,2);        // 40 megohm resistor between pins 4 & 2, pin 2 is sensor pin, add wire, foil
CapacitiveSensor   cs_4_5 = CapacitiveSensor(4,5);        // 20 megohm resistor between pins 4 & 6, pin 6 is sensor pin, add wire, foil
CapacitiveSensor   cs_4_8 = CapacitiveSensor(4,8);        // 20 megohm resistor between pins 4 & 8, pin 8 is sensor pin, add wire, foil
CapacitiveSensor   cs_4_7 = CapacitiveSensor(4,7);      // 20 megohm resistor between pins 4 & 13, pin 8 is sensor pin, add wire, foil

void setup()                    
{

   //cs_3_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600);
   pinMode(6, OUTPUT); 
   pinMode(9, OUTPUT); 
   pinMode(11, OUTPUT);

}

void loop()                    
{
    long start = millis();
    long total1 =  cs_3_2.capacitiveSensor(100);
    long total2 =  cs_4_5.capacitiveSensor(30);
    long total3 =  cs_4_8.capacitiveSensor(30);
    long total4 =  cs_4_7.capacitiveSensor(30);
    long iGildi = 0;
    int iOnOff = 0;
    Serial.print(millis() - start);        // check on performance in milliseconds
    Serial.print("\t");                    // tab character for debug windown spacing

    Serial.print(total1);                  // print sensor output 1
    Serial.print("\t");
    Serial.print(total2);                  // print sensor output 2
    Serial.print("\t");
    Serial.print(total3);                // print sensor output 3
    Serial.print("\t");
    Serial.println(total4);                // print sensor output 4
    
    //Runa af if setningum sem gera capacitance merkið stöðugra 
    if(total1<15)
      iGildi=0;
    else if(total1>15&&total1<25)
      iGildi=10;
    else if(total1>25&&total1<50)
      iGildi=25;
     else if(total1>50&&total1<75)
      iGildi=50;
     else if(total1>75&&total1<100)
      iGildi=75;
     else if(total1>100&&total1<125)
      iGildi=100;
     else if(total1>125&&total1<150)
      iGildi=125;
     else if(total1>150&&total1<175)
      iGildi=150;
     else if(total1>175&&total1<200)
      iGildi=175;
     else if(total1>200&&total1<225)
      iGildi=200;
     else if(total1>225&&total1<250)
      iGildi=225;
     else if(total1>250)
      iGildi=255;
    //Runa af if setningum sem kveikja á og stilla LED  
    if(total2>1000)
      analogWrite(11, iGildi);
      
    if(total3>1000)
      analogWrite(9, iGildi);

    if(total4>1000)
      analogWrite(6, iGildi);

    delay(50);                             // arbitrary delay to limit data to serial port 
}

