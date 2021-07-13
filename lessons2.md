流水灯：// C++ code
//
int i=13;
int j=0;
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(0,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(7,OUTPUT);
}

void loop()
{
  for(i=13;i>5;i--)
  {
  digitalWrite(i, HIGH);
  delay(500); // Wait for 1000 millisecond(s)
  digitalWrite(i, LOW);
  }
  //delay(1000); // Wait for 1000 millisecond(s)
}


