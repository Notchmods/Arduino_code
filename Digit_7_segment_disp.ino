 //Arrays to display number 0-9
 int number_type[10][8]={
  {1,1,1,1,1,1,1,0},//0
  {0,0,1,0,1,0,0,0},//1
  {1,1,0,1,1,1,0,1},//2
  {0,1,1,1,1,1,0,1},//3
  {0,0,1,1,1,0,1,1},//4
  {0,1,1,1,0,1,1,1},//5
  {1,1,1,1,0,1,1,1},//6
  {0,0,1,1,1,1,0,0},//7
  {1,1,1,1,1,1,1,1},//8
  {0,1,1,1,1,1,1,1}};//9

int number=0;
 void setup() {
    Serial.begin(9600);
    // put your setup code here, to run once:
    pinMode(10,INPUT);//Button
    pinMode(2,OUTPUT);//pin E
    pinMode(3,OUTPUT);//pin D
    pinMode(4,OUTPUT);//pin C
    pinMode(5,OUTPUT);//pin DP
    pinMode(6,OUTPUT);//pin B
    pinMode(7,OUTPUT);//pin A
    pinMode(8,OUTPUT);//pin F
    pinMode(9,OUTPUT);//pin G
  }

  void loop() {
    //Read electrical signals from button connected to digital pin 10
    int button_state=digitalRead(10);
    //If button is pressed, increment the counter.
    if(button_state==1){
      number+=1;
      Serial.println(number);
      delay(1000);
      //Accounting for the limitations of the LED display
      if(number>9){
        number=0;
      }
    }
 
   numberdisp(number);
     
    
  }

//Display the number based on the array 
void numberdisp(int number){
  // put your main code here, to run repeatedly:
       digitalWrite(2,number_type[number][0]);
       digitalWrite(3,number_type[number][1]);
       digitalWrite(4,number_type[number][2]);
       digitalWrite(5,number_type[number][3]);
       digitalWrite(6,number_type[number][4]);
       digitalWrite(7,number_type[number][5]);
       digitalWrite(8,number_type[number][6]);
       digitalWrite(9,number_type[number][7]);
}
