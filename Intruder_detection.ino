
//Improve version of the intruder detection system with OLED display
//Libraries needed:
//-Adafruit GFX, Adafruit SSD1306 and SPI
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
#define LED_Pin 7 //Green LED
#define echo_pins 10
#define trig_pins 11
#define wait_time 200

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int duration,distance;
void OLED_display(int distance);
void Emitting_pulses();
void Alert(int distance);

void setup() {
  Serial.begin(9600);
  //Set input and output pins for Ultrasonic sensor
  pinMode(LED_Pin,OUTPUT);
  pinMode(echo_pins,INPUT);
  pinMode(trig_pins,OUTPUT);
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.clearDisplay();
  delay(1000);
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.print("Hello world");
  display.display();
  delay(1000);
  display.clearDisplay();
}

void loop() {

    Emitting_pulses();
    //Finding distance based on the low and high pulse collected
    duration =pulseIn(echo_pins,HIGH);
    distance=(duration/29)/2;
    OLED_display(distance);
    Alert(distance);


}

void OLED_display(int distance){
  //Display distance in OLED screen
    display.clearDisplay();
    display.setCursor(0,0);
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.print(distance);
    Serial.println(distance);
    display.display();
}

void Emitting_pulses(){
  //Give low pulse before high pulse
    digitalWrite(trig_pins,LOW);
    delay(wait_time);
    digitalWrite(trig_pins,HIGH);
    delay(wait_time);
    digitalWrite(trig_pins,LOW);//Reset to not emit 
}

void Alert(int distance){
  if(distance<=50){
    digitalWrite(LED_Pin,HIGH);
  }else{
    digitalWrite(LED_Pin,LOW);
  }
}

  
