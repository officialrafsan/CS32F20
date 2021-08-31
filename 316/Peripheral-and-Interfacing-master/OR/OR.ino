void setup()
{
  
 pinMode(11,OUTPUT);
 pinMode (10,INPUT);
 pinMode (9,INPUT);

}

void loop()

{
  int dvalue1=digitalRead(10); 
  int dvalue2=digitalRead(9); 

  if (dvalue1==HIGH || dvalue2==HIGH)
  {
    digitalWrite(11,HIGH);
  }
  else 
  {
  digitalWrite(11,LOW);
  }
}  

