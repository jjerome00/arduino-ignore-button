//www.elegoo.com
//2016.12.08
/*
 * I believe this is the one that works!
 * 
 */


int gDoorPin = 5;
int buttonPin = 9;

String msg = "seconds to wait: ";
int secondsToWait = 20;
int minutesToWaitInSeconds = 30 * 60;

void setup() 
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(gDoorPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  
  digitalWrite(gDoorPin, HIGH);
  Serial.println("Hi - ready");
}

void loop() 
{
  if (digitalRead(buttonPin) == LOW)
  {
    Serial.println("button pressed");
    digitalWrite(LED_BUILTIN, HIGH);

    startOpener();

    Serial.println(msg + secondsToWait);
    delay(secondsToWait * 1000);

    Serial.println("done - ready for more");
    digitalWrite(LED_BUILTIN, LOW);
  }
}

void startOpener() {
  Serial.println("gDoor - activating");
  digitalWrite(gDoorPin, LOW);
  delay(500);
  digitalWrite(gDoorPin, HIGH);
}
