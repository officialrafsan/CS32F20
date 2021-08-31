int S0, S1, CIN;
int A[2], B[2];
int Y[2];

void setup()
{
  //INPUT
  pinMode(7, INPUT); //A[0]
  pinMode(6, INPUT); //A[1]
  pinMode(9, INPUT); //B[0]
  pinMode(8, INPUT); //B[1]
  
  //SWITCH
  pinMode(5, INPUT); //S0
  pinMode(4, INPUT); //S1
  pinMode(3, INPUT); //CIN

  //OUTPUT
  pinMode(10, OUTPUT); //S[0]
  pinMode(11, OUTPUT); //S[1]
  pinMode(12, OUTPUT); //COUT
}

void loop()
{
  Serial.begin(9600);
  S0 = digitalRead(5);
  S1 = digitalRead(4);
  CIN = digitalRead(3);

  A[0] = digitalRead(7);
  A[1] = digitalRead(6);
  B[0] = digitalRead(9);
  B[1] = digitalRead(8);
  for(int i=0; i<2;i++)
  {
    Y[i]=((S0&B[i])|(S1&(~B[i])));
  }
  FullAdder(A[0],A[1],Y[0],Y[1],CIN);
}
void FullAdder(int P1,int P2, int Q1, int Q2, int R1)
{
  int s1 = ((P1^Q1)^R1);//Sum 0
  int c1 = ((P1&Q1)|(R1&(P1^Q1)));//Carry 1
  int s2 = ((P2^Q2)^c1);//Sum 1
  int Cout = ((P2&Q2)|(c1&(P2^Q2)));//Carry Out
  digitalWrite(10,s1);
  digitalWrite(11,s2);
  digitalWrite(12,Cout);
}
