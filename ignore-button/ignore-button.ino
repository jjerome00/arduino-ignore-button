//www.elegoo.com
//2016.12.08
/*
 * This is the one that works!
 * 
 */


int gDoorPin = 5;
int buttonPin = 9;
int buttonLEDPin = 10;

String msg = "seconds to wait: ";
int secondsToWait = 20;
int minutesToWaitInSeconds = 30 * 60;

void setup() 
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  
  pinMode(gDoorPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonLEDPin, OUTPUT);
  
  init();
}

void init() 
{
  digitalWrite(gDoorPin, HIGH);
  setButtonLED_ON();
  Serial.println("Hi - ready");
}

void loop() 
{
  if (digitalRead(buttonPin) == LOW)
  {
    Serial.println("button pressed");
    setButtonLED_OFF();

    startOpener();

    Serial.println(msg + secondsToWait);
    delay(secondsToWait * 1000);

    Serial.println("done - ready for more");
    setButtonLED_ON();
  }
}

void setButtonLED_ON() {
  digitalWrite(buttonLEDPin, HIGH);
}

void setButtonLED_OFF() {
  digitalWrite(buttonLEDPin, LOW);
}


void startOpener() {
  Serial.println("gDoor - activating");
  digitalWrite(gDoorPin, LOW);
  delay(500);
  digitalWrite(gDoorPin, HIGH);
}
