#include <dht.h>
#include <LiquidCrystal.h>

dht DHT;

// acceptable temperatures in Celsius.
// switching occurs when the temp range moves outside these temperatures;
// cooling starts at the degree above TEMP_MAX and stops when TEMP_MIN is reached
#define TEMP_MIN 20
#define TEMP_MAX 22

//digital pin for the temp sensor
#define DHT11_PIN 8

// digital pin for the relay
#define RELAY_PIN 13


//constants for the number of rows and columns in the LCD

const int numRows= 4;
const int numCols= 20;

boolean powerOn = false;
unsigned long startTime; 

//initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(){
  Serial.begin(9600);

  lcd.begin(numCols, numRows);
  lcd.print("Initializing....");
         
  startTime = millis();

  delay(1000);

}

void loop()
{

  lcd.clear();
  
  int chk = DHT.read11(DHT11_PIN);
 //lcd.print("Temp: ");
  lcd.setCursor(0,0);

 
 int tempC =  DHT.temperature;
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C  ");

  lcd.print(DHT.temperature *180.0/100.0 + 32.0);
  lcd.print((char)223);
  lcd.print("F ");
  
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");

  lcd.setCursor(0,2);
  lcd.print("min: ");
  lcd.print(TEMP_MIN);
  lcd.print((char)223);
  lcd.print("C");

  lcd.setCursor(10,2);
  lcd.print("max: ");
  lcd.print(TEMP_MAX);
  lcd.print((char)223);
  lcd.print("C");

  
  if (tempC > TEMP_MAX){
    if(! powerOn){
        
        // turn fridge on
        powerOn = true;
        startTime = millis();
    }
  }
  else if (tempC <= TEMP_MIN){
    if(powerOn){
      // turn fridge off
      powerOn = false;
      startTime = millis();

    }
  }

  lcd.setCursor(0,3);

  if(powerOn){
    lcd.print("Cooling ");
    digitalWrite(RELAY_PIN, HIGH);


  }else{
    lcd.print("Standby "); // power off
    digitalWrite(RELAY_PIN, LOW);

  }

for(int i=0; i<10; i++){
  //update time 10 times (seconds) before taking another reading (so LED screen isn't too blinky)
  
  long int seconds = (millis()-startTime)/1000;
  long int minutes = seconds / 60;
  seconds = seconds - minutes*60;

  lcd.setCursor(8,3);
  
  if(minutes>60){
    long int hours = minutes/60;
    minutes = minutes - hours*60;
    lcd.print(hours);
    lcd.print(":");
    if(minutes<10){
      lcd.print("0");
    }
  }


  lcd.print(minutes);
  lcd.print(":");
  if(seconds<10){
     lcd.print("0");
  }
 
  lcd.print(seconds);
  delay(1000);
  
}
  
}


