# include <SoftwareSerial.h>
# include <IRCom.h>

# define rxPin 2
# define txPin 3

# define USERNAME "Hello from band: 1"

SoftwareSerial ir(rxPin,txPin);

int count=0;
void setup(){
  setIRpin(9);
 
  ir.begin(2400);
  Serial.begin(115200);
  pinMode(13, OUTPUT);
  
}

void loop(){
    if(ir.available()>0) {
    receiverIR();
    digitalWrite(13,1);
   }   
   else {
    //delay(10);   
    digitalWrite(13,0);
    transmitIR();
   }
   delay(10);
}

void receiverIR(){
     char val = ir.read();
     if(val>0){
     Serial.print(val);
     
    }
}
void transmitIR(){
   ir.println(USERNAME);
 }


