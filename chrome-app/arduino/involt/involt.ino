//INVOLT ARDUINO BASIC SKETCH
/*
  AUTO PINMODE
  Involt by default automatically adds pinMode to received
  pin data so you don't need to add pinMode output in setup for
  basic interactions. This mode is not recommended when
  mixing digital inputs and outputs.
*/

// Potentiameter Constants
const int lowA  = 10; 
const int highA = 60;

const int lowB  = 150;
const int highB = 200;

const int lowC  = 400;
const int highC = 450;

boolean autoPinMode = false;
/*
  DIRECT MODE
  Direct mode sends data from app to digital pins without storing
  it in involtDigital array and without additional code in void
  loop. It can be used for testing interaction with Arduino
  inside App. In direct mode digitalWrite/analogWrite is
  automatic only for values received from Involt.
*/
boolean directMode = false;
/*
  ARRAY FOR DIGITAL/PWM PINS
  IMPORTANT: You need to declare the beginning number of variables.
  Without the declared length there may occur problems when sending
  undeclared value to declared pin in void loop.
  Default is Arduino UNO total pin number +1. 
*/
int involtDigital[14] = {};
/*
  ARRAY FOR RECEIVED STRINGS
  You can save the received data as string if pin parameter of HTML 
  element is S0,S1 etc.
*/
String receivedString[] = {};
/*
  FUNCTION TRIGGER
  Used if something is received with fn HTML attribute.
*/
String fname;

void setup() {
  //Bitrate must remain same as in app.
  Serial.begin(57600);
  pinMode(5, OUTPUT);
}


void loop() {
  //receive data from your app, do not remove this line.
//  involtReceive();

//  involtSendString(6, "See you, Space Cowboy");
//  delay(2);

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

//  Serial.print("safeA: ");
//   Serial.print(safeA);
//  Serial.print(", safeB: ");
//   Serial.print(safeB);
//  Serial.print(", safeC:");
//   Serial.print(safeC);
//  Serial.print("       ");
//  Serial.print(", Safes Open:");
//   Serial.println(numOpen);
//  delay(2);
  involtSendString(13, String(safeA));
  delay(2);
  involtSendString(14, String(safeB));
  delay(2);
  involtSendString(15, String(safeC));
  delay(2);
  involtSendString(16, String(numOpen));
}

//----------------------
//INVOLT FUNCTIONS

String V = "V";
String A = "A";
String E = "E";

void involtSend(int pinNumber, int sendValue) {
  Serial.println(A + pinNumber + V + sendValue + E);
}

void involtSendString(int pinNumber, String sendString) {
  Serial.println(A + pinNumber + V + sendString + E);
}

void involtReceive() {

  String involt;
  int involtLen;
  int pin;
  int val;
  
  String pwm = "P";
  String dig = "D";
  String fn = "FN";
  
  if (Serial.available() > 0) {
    involt = Serial.readStringUntil('\n');
    involtLen = involt.length();

    if (involt.indexOf(fn) == 0) {
      fname = involt.substring(2, involtLen);
    }
    else if (involt.indexOf(dig) == 0 || involt.indexOf(pwm) == 0 ){
      pin = involt.substring(1, involt.indexOf(V)).toInt();
      val = involt.substring(involt.indexOf(V) + 1, involtLen).toInt();
      

      if (autoPinMode) {
        pinMode(pin, OUTPUT);
      };

      if (directMode) {
        if (involt.indexOf(dig) == 0) {
          digitalWrite(pin, val);
        }
        else if (involt.indexOf(pwm) == 0 ) {
          analogWrite(pin, val);
        };
      }
      else {
        involtDigital[pin] = val;
      };

    }
    else if(involt.indexOf("S") == 0){
       pin = involt.substring(1, involt.indexOf(V)).toInt();
       receivedString[pin] = involt.substring(involt.indexOf(V) + 1, involtLen);
    };
    
  };
};

