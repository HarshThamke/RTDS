int flag = 0;
int i = 0;
int a,b,c,d,e;
void setup() {
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(8,INPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);

  Serial.begin(9600);
  

}

void loop() 
{
  a = digitalRead(2);
  b = digitalRead(3);
  c = digitalRead(4);
  d = digitalRead(5);
  e = digitalRead(8);
  if (a == HIGH && b == HIGH && c == HIGH && d == HIGH && e == HIGH)
  {
    if(flag==0)
  {
  digitalWrite(7, HIGH);
  if(i==0)
  {
  digitalWrite(6, HIGH);
  i++;
  Serial.print(i);
  }
  delay(3000);
  flag=1;
  }
 }  
 else
 {
  digitalWrite(7, LOW);
  i=0;
 }
 if(flag==1)
 {
  digitalWrite(6,LOW);
 flag=0;
 }
}
