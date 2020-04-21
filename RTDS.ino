#include<Arduino.h>
const int dat_input[]={2,3,4,5};
volatile int sig_output[]={6,7};
//const int dat_input_D2=2,dat_input_D3=3,dat_input_D4=4,dat_input_D5=5;
//volatile int sig_output_D6=6,sig_output_D7=7;
void setup()
{
  for(int index=0;index<4;index++)
  {
    pinMode(dat_input[index],INPUT);
  }
    for(int index=0;index<2;index++)
  {
    pinMode(sig_output[index],OUTPUT);
  }
  Serial.begin(115200);
  
}
void loop()
{
  int in_sig[]={0,0,0,0};
  int count=0;
  for(int index=0;index<4;index++)
  {
    in_sig[index]=digitalRead(dat_input[index]);
  }
  //Checking the input status in Serial Monitor at Baud Rate of 115200
  Serial.println("Input Status");
  for(int index=0;index<4;index++)
  {
    Serial.print(index);
    Serial.println(in_sig[index]);
  }
  for(int index=0;index<4;index++)
  {
    if(in_sig[index]!=0)
    {
      count="revertout";
      break;
    }
  }
  if(count!="revertout")
  {
    for(int index=0;index<2;index++)
    {
      digitalWrite(sig_output[index],HIGH);
    }
    delay(3000);
    for(int index=0;index<2;index++)
    {
      digitalWrite(sig_output[index],LOW);
    }
    Serial.println("Execution DONE");//Checking Execution 
    
  }
}
