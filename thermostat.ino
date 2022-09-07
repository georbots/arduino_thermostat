#include <OneWire.h>
#include <DallasTemperature.h>
 
#define ONE_WIRE_BUS 2
 
OneWire oneWire(ONE_WIRE_BUS);
 
DallasTemperature sensors(&oneWire);



void setup(void)
{
  // start serial port
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  pinMode(8,OUTPUT);
  // Start up the library
  sensors.begin();
}
 
 
void loop(void)
{

  Serial.print(" Requesting temperatures...");
  sensors.requestTemperatures(); // 
  Serial.println("DONE");

  Serial.print("Temperature is: ");
  Serial.println(sensors.getTempCByIndex(0)); 
  Serial.print("RELAY is: ");
  Serial.println(digitalRead(8));

    if (sensors.getTempCByIndex(0)<10){
      digitalWrite(3,HIGH);//LEDs

      digitalWrite(4,LOW); 
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);

      digitalWrite(8,HIGH); //resistor relay
    }
    else if (sensors.getTempCByIndex(0)<=19){
      digitalWrite(4,HIGH);

      digitalWrite(3,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);

      digitalWrite(8,HIGH); //resistor relay
    }
    else if (sensors.getTempCByIndex(0)<=20){ 
      digitalWrite(5,HIGH);

      digitalWrite(4,LOW);
      digitalWrite(3,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);

      digitalWrite(8,LOW); //resistor relay
    }
    else if (sensors.getTempCByIndex(0)<=21){ 
      digitalWrite(6,HIGH);
      
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(3,LOW);
      digitalWrite(7,LOW);

      digitalWrite(8,LOW); //resistor relay
    }
    else if (sensors.getTempCByIndex(0)>21){ 
      digitalWrite(7,HIGH);

      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);

      digitalWrite(8,LOW); //resistor relay
      }
      
    delay(1000);

    
}
