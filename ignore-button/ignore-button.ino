/* 2016.12.08
 * 
 * Use a garage door opener as a interactive display
 * 
 * External devices:
 * Button: with a separate LED control
 * Sound board: for ferry horn
 * Relay: handles pressing the "button" on the garage door opener
 * 
 * Usage:
 * 1. Button illuminates, indicating system is ready
 * 2. User presses button
 * 3. Arudino starts playing horn sound file, waits for sound to stop
 * 2. Arduino uses the Relay to press button on the garage door opener
 * 3. Arduino waits for a specified time (to ignore further button presses)
 * 4. After delay has elapased, button illuminates again, indicating it's ready
 * 
 */

int gDoorPin = 5;
int buttonPin = 9;
int buttonLEDPin = 10;
int musicPin = 3;

String msg = "seconds to wait: ";
int secondsToWait = 20;
int secondsHornSound = 6;

void setup() 
{
  Serial.begin(9600);
  
  pinMode(LED_BUILTIN, OUTPUT);  
  pinMode(gDoorPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonLEDPin, OUTPUT);
  pinMode(musicPin, OUTPUT);

  // Set initial state
  digitalWrite(gDoorPin, HIGH);
  digitalWrite(musicPin, HIGH);
  setAvailableIndicator_ON();
  
  Serial.println("Hello! Ready!");
}


void loop() 
{
  if (digitalRead(buttonPin) == LOW)
  {
    Serial.println("button pressed");
    setAvailableIndicator_OFF();

    Serial.println("garage door - activating");
    playHorn();

    // wait for sound to stop before moving ferry
    delay(secondsHornSound * 1000);
  
    startGarageDoorOpener();

    // do not allow further button presses until ferry has finished moving
    Serial.println(msg + secondsToWait);
    delay(secondsToWait * 1000);

    Serial.println("done: ready for more");
    setAvailableIndicator_ON();
  } 
}

void setAvailableIndicator_ON() {
  digitalWrite(buttonLEDPin, HIGH);
  digitalWrite(LED_BUILTIN, HIGH);
}

void setAvailableIndicator_OFF() {
  digitalWrite(buttonLEDPin, LOW);
  digitalWrite(LED_BUILTIN, LOW);
}

void playHorn() {
  Serial.println("playing horn");
  digitalWrite(musicPin, LOW);
  delay(200);
  digitalWrite(musicPin, HIGH);
}

void startGarageDoorOpener() {
  Serial.println("starting ferry");
  digitalWrite(gDoorPin, LOW);
  delay(500);
  digitalWrite(gDoorPin, HIGH);
}
