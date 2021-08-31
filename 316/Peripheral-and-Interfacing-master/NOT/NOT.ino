void setup()
{
  
 pinMode(13,OUTPUT);
 pinMode (12,INPUT);
}

void loop()

{
  int dvalue=digitalRead(12); 
  if (dvalue==HIGH)
  {
    digitalWrite(13,LOW);
  }
  else 
  {
  digitalWrite(13,HIGH);
  }
}  
