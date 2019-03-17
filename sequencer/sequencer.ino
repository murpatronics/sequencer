/*
  CV Step Sequencer
*/

const int STEPS = 4;
const int blnk = 10;

// current step
int stp = 0;
// bpm
int bpm = 20;
// sequencer input channels
int sqch[STEPS] = {A0, A1, A2, A3};
// input cv values
int icv [STEPS] = {0, 0, 0, 0};

unsigned long previousMs = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  readAllAnalog();
  bpm = map(icv[0], 0, 1023, 20,300);
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  readAllAnalog();
  unsigned long currentMs = millis();  
  unsigned long stepLength = 60000 / bpm;

  if ( currentMs - previousMs >= blnk)
  {
    digitalWrite(LED_BUILTIN, LOW);
  }

  if ( currentMs - previousMs >= stepLength)
  {
    previousMs = currentMs;
    if (stp == STEPS)
      stp = 0;
    stp++;
    printState();
    digitalWrite(LED_BUILTIN, HIGH);
  }

  delay(1);    // delay in between reads for stability
}

void printState()
{
  Serial.print("Step " + String(stp));
  Serial.print(" BPM " + String(bpm));
  for (int i = 0; i < STEPS; i++)
  {
    Serial.print(" cv" + String(icv[i]));
  }
  Serial.print("\n");
}

void readAllAnalog()
{
  for (int i = 0; i < STEPS; i++)
  {
    icv[i] = analogRead(sqch[i]);
  }
}

