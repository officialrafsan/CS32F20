int a=0;
const int BUFFER_SIZE = 50;
char buf[BUFFER_SIZE];


void setup() {
  
  
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
Serial.begin(9600);
}

void loop() {
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  if(Serial.available()>0){
    a=Serial.readBytes(buf, BUFFER_SIZE);
    Serial.print("INPUT: ");
    for(int i = 0; i < a; i++){
      Serial.print(buf[i]);
    //Serial.println(a-48,DEC);
    if(buf[i]>=0){
      for(int j=9;j<=12;j++){
        if(j==9){
          digitalWrite(9,LOW);
          digitalWrite(10,LOW);
          digitalWrite(11,LOW);
          digitalWrite(12,HIGH);
          }
        if(j==10){
          digitalWrite(9,LOW);
          digitalWrite(10,LOW);
          digitalWrite(11,HIGH);
          digitalWrite(12,LOW);
          }
          
        if(j==11){
          digitalWrite(9,LOW);
          digitalWrite(10,HIGH);
          digitalWrite(11,LOW);
          digitalWrite(12,LOW);
          }
        
        if(j==12){
          digitalWrite(9,HIGH);
          digitalWrite(10,LOW);
          digitalWrite(11,LOW);
          digitalWrite(12,LOW);
          }
        
        
         
      
//      digitalWrite(9,HIGH);
//      digitalWrite(10,LOW);
//      digitalWrite(11,LOW);
//      digitalWrite(12,LOW);
              
        if(buf[i]=='0'){
          zero();}
        if(buf[i]=='1'){
          one();}
        if(buf[i]=='2'){
          two();}
        if(buf[i]=='3'){
          three();} 
        if(buf[i]=='4'){
          four();}
        if(buf[i]=='5'){
          five();}
        if(buf[i]=='6'){
          six();}
        if(buf[i]=='7'){
          seven();}
        if(buf[i]=='8'){
          eight();}
        if(buf[i]=='9'){
          nine();} 
      }          
}
}
}
}
void zero() {
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  delay(1000);
}
void one(){
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  delay(1000);
  
}

void two() {
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  delay(1000);
}

 void three() {
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  delay(1000);
  
 }

void four() {
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  delay(1000);
  
}

void five() {
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  delay(1000);
  
}

void six() {
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  delay(1000);
}

void seven() {
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  delay(1000);
  }

void eight() {
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  delay(1000);
  
}

void nine() {
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  delay(1000);
}
