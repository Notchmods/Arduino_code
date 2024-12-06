//Digital pins
int buttonpin=2; 
int LEDpin=3,LEDpin1=4,LEDpin2=8;

//Variables 
int pressed=0;
int on_or_off;
int current_reading;
int prev_state=1;
int delay_time=500;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//Open the serial port at 9600
  pinMode(LEDpin,OUTPUT);
  pinMode(buttonpin,INPUT);
}

void loop() {
    // put your main code here, to run repeatedly:
    pressed = digitalRead(buttonpin);
    //Press the button to turn the LED on and off
    if(pressed==1&&prev_state==0){
      on_or_off=!on_or_off;
    }
    prev_state=pressed;
    //Based on the on and off boolean determine whether the light should be on or off
    if(on_or_off==1){
      //Show light pattern
      Lightpattern();
      Serial.print("Pattern is on \n");
    }else{
      //Turn LED off
      digitalWrite(LEDpin,LOW);
      Serial.print("Off \n");
    }
}


//Light pattern
void Lightpattern(){
  digitalWrite(LEDpin2,LOW);
  digitalWrite(LEDpin,HIGH);
  delay(delay_time);
  digitalWrite(LEDpin1,HIGH);
  digitalWrite(LEDpin,LOW);
  delay(delay_time);
  digitalWrite(LEDpin2,HIGH);
  digitalWrite(LEDpin1,LOW);
  delay(delay_time);
}
