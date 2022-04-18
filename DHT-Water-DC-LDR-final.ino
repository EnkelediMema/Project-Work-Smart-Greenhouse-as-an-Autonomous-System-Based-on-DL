

#include <DHT.h>

/* Uncomment according to your sensortype. */
#define DHT_SENSOR_TYPE DHT_TYPE_11
//#define DHT_SENSOR_TYPE DHT_TYPE_21
//#define DHT_SENSOR_TYPE DHT_TYPE_22

const int waterSens = A0; //define water sensor
const int ventilation = 9;//define led to pin 9
int waterVal; //define the water sensor value

const int pwm = 2;
const int in_1 = 3; const int in_2 = 5; int water=10;

int sensorPin = A2; 
int sensorValue;  
int limit = 300; 

 
#define DHTPIN A1     // Digital pin connected to the DHT sensor
#define DHTTYPE    DHT11     // DHT 11
DHT dht(DHTPIN, DHTTYPE);

#define LDRpin A3
int LDRValue = 0;





void setup( )
{

pinMode(pwm,OUTPUT);
  pinMode(in_1,OUTPUT);
  pinMode(in_2,OUTPUT);
  pinMode(water,OUTPUT);
  pinMode(ventilation, OUTPUT); //set led as an output
  pinMode(waterSens, INPUT);//set water sensor as an input
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(13, OUTPUT);//yell
  pinMode(11, OUTPUT);//red
  pinMode(4, OUTPUT); //buz
 Serial.begin(9600);
   dht.begin();
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
   //read temperature and humidity
  char t = dht.readTemperature();
  float h = dht.readHumidity();
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
  }
  
  
}







  

/*
 * Main program loop.
 */
void loop( )
{



    float temp = dht.readTemperature();
    float hum = dht.readHumidity();

    
    Serial.print("Current humidity = ");
    Serial.print(hum);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(temp); 
    Serial.println("C  ");
    
    delay(5000);//Wait 5 seconds before accessing sensor again.
 
   




    
    
   




if(temp >=27) {

 digitalWrite(ventilation,HIGH); //for clock wise motion
  delay(1000);
  digitalWrite(ventilation,LOW);
digitalWrite(in_1,HIGH); digitalWrite(in_2,LOW); analogWrite(pwm,130);
//delay for 3 sec Clock wise motion
Serial.println("Temperature High Ventilation Activated");

delay(1000);

//for break

digitalWrite(in_1,HIGH); digitalWrite(in_2,HIGH); delay(200);

//for anticlock wise

digitalWrite(in_1,LOW); digitalWrite(in_2,HIGH); delay(3000);

//for break

digitalWrite(in_1,HIGH); digitalWrite(in_2,HIGH); delay(200);

}

delay(1000);

 waterVal = analogRead(waterSens); //read the water sensor
 Serial.println("Water Detection analog value:");
 Serial.print(waterVal);
 Serial.println();
 delay(4000);//print the value of the water sensor to the serial monitor

 
 if (waterVal > 100)
 {
 digitalWrite(water,HIGH); 
 delay(1000);
  digitalWrite(water,LOW); 
}
 
 delay(1000); 

sensorValue = analogRead(sensorPin); 
 Serial.println("Moisture Analog Value : ");
 Serial.print(sensorValue);
  Serial.println();
  
  delay(1000); 

 if (sensorValue<limit) {
 digitalWrite(12, HIGH);
 Serial.println("Soil is wet enough");
 delay(1000);
   digitalWrite(12,LOW);
 }
 delay(1000); 


 if (sensorValue >limit)
 {
 digitalWrite(8, HIGH);
 Serial.println("Soil is dry  water pump activatet (Relay) ");
 delay(1000);
   digitalWrite(8,LOW);
 }
 delay(1000); 

 
  if (hum >90)
 {
 digitalWrite(13, HIGH);
 Serial.println("Hight humidity level !!!");
 delay(1000);
   digitalWrite(13,LOW);
 }
 delay(1000); 

LDRValue = analogRead(LDRpin);
 
  Serial.println("Sun light Expozure:");
   Serial.print(LDRValue);
    Serial.println();
  delay(1000);


  if (LDRValue>990)
 {
 digitalWrite(11, HIGH);
 digitalWrite(4, HIGH);
 Serial.println("Sun exposure too high !!!");
 delay(1000);
   digitalWrite(11,LOW);
   digitalWrite(4,LOW);
 }
 delay(1000); 
}
