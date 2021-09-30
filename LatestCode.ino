/* This Code is Written by ZXERO Programming */

/* Below are the Libraries Required */
#include <OneWire.h>
#include <DallasTemperature.h>

float ctemp = 0.0;                              /* variable to store measured Celsius temperature */
float ftemp = 0.0;                              /* variable to store measured Celsius temperature */
int oneWireBus = 12;                            /* 1-wire Pin */
OneWire oneWire(oneWireBus);                    /* 1-wire instance on the oneWireBus pin */
DallasTemperature sensors(&oneWire);            /* give the OneWire instance as Parameter to DallasTemperature Library */

/* The Modified Code */
const int led2=2, led3=3, led4=4, led5=5, led6=6, led7=7, led8=8, led9=9;
const int heater=10;
const int fan=11;

void setup(void) {
  pinMode(LED_BUILTIN, OUTPUT);                 /* This Step Initisalises the LED_BUILTIN as Output */
  //digitalWrite(LED_BUILTIN, HIGH);            /*    This Makes Sure the LED is Turned OFF (Low) When the Program Starts */

  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(heater, OUTPUT);
  pinMode(fan, OUTPUT);
  
  Serial.begin(9600);                           /* This Step Initialises the Serial Monitor */
  Serial.println("Zxero Programing - 1-Wire Temperature Sensor"); /* This Prints a Message on the Serial Monitor */
  sensors.begin();                              /* This Starts Reading the Sensor */
}

 // repeat infinitely
void loop(void) {
  sensors.requestTemperatures();                /* Read the temperature of all 1-wire sensors connected to the 1-wire bus */
  ctemp = sensors.getTempCByIndex(0);           /* Get the Temperature of the First Sensor in Celcius (list starts with 0) */
  ftemp = sensors.getTempFByIndex(0);           /* Get the Temperature of the First Sensor in Fahranheit (list starts with 0) */
  Serial.print("Temp in C : ");             /* Prints Message without a Newline */
  Serial.print(ctemp);                         /* Print the Temperature with a Newline as it has ln after Serial.print in this line */
  Serial.print("  ||  Temp in F : ");
  Serial.println(ftemp);
  delay(1000);                                 /* Pause 1000 millisecond = 1 second */

  if(ctemp>1 && ctemp<=34.5) /* +2 Pin Code - Special Blink Code */
      {digitalWrite(led2, HIGH); delay(100); digitalWrite(led2, LOW); delay(200);
       digitalWrite(led2, HIGH); delay(100); digitalWrite(led2, LOW); delay(200);
       digitalWrite(led2, HIGH); delay(100); digitalWrite(led2, LOW); delay(200);
       digitalWrite(led2, HIGH); delay(100); digitalWrite(led2, LOW); delay(200);
       digitalWrite(led2, HIGH); delay(100); digitalWrite(led2, LOW); delay(200);
       digitalWrite(led2, HIGH); delay(100); digitalWrite(led2, LOW); delay(200);
       digitalWrite(led2, HIGH); delay(100); digitalWrite(led2, LOW); delay(200);
       digitalWrite(led2, HIGH); delay(100); digitalWrite(led2, LOW); delay(200);
       digitalWrite(led2, HIGH); delay(100); digitalWrite(led2, LOW); delay(200);
       digitalWrite(led2, HIGH); delay(100); digitalWrite(led2, LOW); delay(200);
       digitalWrite(led2, HIGH); delay(100); digitalWrite(led2, LOW); delay(200);
       digitalWrite(led2, HIGH); delay(100); digitalWrite(led2, LOW); delay(200);
       digitalWrite(led2, HIGH); delay(100); digitalWrite(led2, LOW); delay(200);
       digitalWrite(led2, HIGH); delay(100); digitalWrite(led2, LOW); delay(200);
       digitalWrite(led2, HIGH); delay(100); digitalWrite(led2, LOW); delay(200);
       digitalWrite(led2, HIGH); delay(100); digitalWrite(led2, LOW); delay(200);} else digitalWrite(led2, LOW);
  if(ctemp>40.0 && ctemp<=52.5) /* +9 Pin Code - Special Blink Code */
      {digitalWrite(led9, HIGH); delay(100); digitalWrite(led9, LOW); delay(200);
       digitalWrite(led9, HIGH); delay(100); digitalWrite(led9, LOW); delay(200);
       digitalWrite(led9, HIGH); delay(100); digitalWrite(led9, LOW); delay(200);
       digitalWrite(led9, HIGH); delay(100); digitalWrite(led9, LOW); delay(200);
       digitalWrite(led9, HIGH); delay(100); digitalWrite(led9, LOW); delay(200);
       digitalWrite(led9, HIGH); delay(100); digitalWrite(led9, LOW); delay(200);
       digitalWrite(led9, HIGH); delay(100); digitalWrite(led9, LOW); delay(200);
       digitalWrite(led9, HIGH); delay(100); digitalWrite(led9, LOW); delay(200);
       digitalWrite(led9, HIGH); delay(100); digitalWrite(led9, LOW); delay(200);
       digitalWrite(led9, HIGH); delay(100); digitalWrite(led9, LOW); delay(200);
       digitalWrite(led9, HIGH); delay(100); digitalWrite(led9, LOW); delay(200);
       digitalWrite(led9, HIGH); delay(100); digitalWrite(led9, LOW); delay(200);
       digitalWrite(led9, HIGH); delay(100); digitalWrite(led9, LOW); delay(200);
       digitalWrite(led9, HIGH); delay(100); digitalWrite(led9, LOW); delay(200);
       digitalWrite(led9, HIGH); delay(100); digitalWrite(led9, LOW); delay(200);
       digitalWrite(led9, HIGH); delay(100); digitalWrite(led9, LOW); delay(200);} else digitalWrite(led9, LOW);
  if(ctemp>34.5 && ctemp<=35.5) digitalWrite(led2, HIGH); else digitalWrite(led2, LOW); /* 2 Pin Code */
  if(ctemp>35.5 && ctemp<=36.0) digitalWrite(led3, HIGH); else digitalWrite(led3, LOW); /* 3 Pin Code */
  if(ctemp>36.0 && ctemp<=36.5) digitalWrite(led4, HIGH); else digitalWrite(led4, LOW); /* 4 Pin Code */
  if(ctemp>36.5 && ctemp<=37.0) digitalWrite(led5, HIGH); else digitalWrite(led5, LOW); /* 5 Pin Code */
  if(ctemp>37.0 && ctemp<=37.5) digitalWrite(led6, HIGH); else digitalWrite(led6, LOW); //Normal - 27 /* 6 Code */
  if(ctemp>37.5 && ctemp<=38.0) digitalWrite(led7, HIGH); else digitalWrite(led7, LOW); //Normal - 28 /* 7 Code */
  if(ctemp>38.0 && ctemp<=39.0) digitalWrite(led8, HIGH); else digitalWrite(led8, LOW); /* 8 Pin Code */
  if(ctemp>39.0 && ctemp<=40.0) digitalWrite(led9, HIGH); else digitalWrite(led9, LOW); /* 9 Pin Code */
  

  /* EGG requires 37.5 Degrees Celsius(or 99.5 Degrees Fahranheit)  --code-now-->  27.5 Degrees Celsius(or 81.5 Degrees Fahranheit) */
  if(ctemp<=37.50) digitalWrite(heater, LOW); else digitalWrite(heater, HIGH);
  if(ctemp<=37.50) digitalWrite(fan, LOW); else digitalWrite(fan, HIGH);
  delay(15000);


}
