# include <SoftwareSerial.h>
# include <IRCom.h>

#include <SPI.h>
#include <SD.h>

# define rxPin 2
# define txPin 3

# define USERNAME "djbabai"

SoftwareSerial ir(rxPin,txPin);

File myFile;
int count=0;
void setup(){
  setIRpin(9);
 
  ir.begin(2400);
  Serial.begin(9600);//band_1
  //Serial.begin(115200);//band_2
}

void loop(){
    if(ir.available()>0) {
    receiverIR();
    }   
   else {
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
   


