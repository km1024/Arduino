
#define MAX 80
#define LED 9
#define STEP 10

int brightness = 0;
int dir = 1;
int mode;
long last;
long now;

#define PULSE 1
#define FADE 2

void setup()
{
  pinMode(LED, OUTPUT);
  last = millis();
  mode = FADE;
}

void fade()
{
  analogWrite(LED, brightness);
  delay(50);
  
  if (dir == 1) {
    brightness += STEP;
    if (brightness >= MAX) {
      dir = 0;
    }
  } else {
    brightness--;
    if (brightness <= 0) {
      dir = 1;
    }
  }
}

void pulse()
{
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);
}

void loop()
{
  if (mode == PULSE)
  {
    pulse();
  } else {
    fade();
  }

  now = millis();
  
  if (now-last >= 10000)
  {
    last = now;
    if (mode == PULSE)
    {
      mode = FADE;
    } else {
      mode = PULSE;
    }
  }
}
