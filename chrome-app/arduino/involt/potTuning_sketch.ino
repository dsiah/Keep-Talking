const int lowA  = 10; 
const int highA = 60;

const int lowB  = 150;
const int highB = 200;

const int lowC  = 400;
const int highC = 450;

void setup() {
  Serial.begin(9600); // open a serial connection to your computer
}

void loop() {
  
  // input from agent
  int lock0 = analogRead(A0);
  int lock1 = analogRead(A1);
  int lock2 = analogRead(A2);
  int lock3 = analogRead(A3);
  int lock4 = analogRead(A4);
  int lock5 = analogRead(A5);
  
  // plot for expert
  int safeA = lock1 - lock4;
  int safeB = lock2 - lock3;
  int safeC = lock0 - lock5;

  // internal (not visible)
  int openA = (lowA < safeA && safeA < highA) ? 1 : 0;
  int openB = (lowB < safeB && safeB < highB) ? 1 : 0;
  int openC = (lowC < safeC && safeC < highC) ? 1 : 0;
  
  // display as string/number to expert
  int numOpen = openA + openB + openC; 

  Serial.print("safeA: ");
   Serial.print(safeA);
  Serial.print(", safeB: ");
   Serial.print(safeB);
  Serial.print(", safeC:");
   Serial.print(safeC);
  Serial.print("       ");
  Serial.print(", Safes Open:");
   Serial.println(numOpen);
  delay(2);
}


