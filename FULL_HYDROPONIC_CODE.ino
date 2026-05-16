const int ecPin = 36;   // VP pin

// Pump A pins (L298N Channel A)
const int pumpA_IN1 = 26;
const int pumpA_IN2 = 27;

// Pump B pins (L298N Channel B)
const int pumpB_IN1 = 32;
const int pumpB_IN2 = 33;

// Adjusted target range based on your actual mix testing
float lowEC = 0.50;
float highEC = 0.70;

// Temporary calibration placeholder
float ecSlope = 1.20;
float ecOffset = 0.00;

int samples = 20;
int mixDelay = 15000;          // 15 s after dosing
int betweenPumpsDelay = 5000;  // 5 s between A and B
int pumpTime = 1000;           // 1 s dosing per pump

float readEC() {
  long sum = 0;

  for (int i = 0; i < samples; i++) {
    sum += analogRead(ecPin);
    delay(10);
  }

  int raw = sum / samples;
  float voltage = raw * 3.3 / 4095.0;
  float ec = ecSlope * voltage + ecOffset;

  if (ec < 0) ec = 0;

  Serial.print("Raw: ");
  Serial.print(raw);
  Serial.print("  Voltage: ");
  Serial.print(voltage, 3);
  Serial.print(" V  EC: ");
  Serial.print(ec, 3);
  Serial.println(" mS/cm");

  return ec;
}

void pumpAOn() {
  digitalWrite(pumpA_IN1, HIGH);
  digitalWrite(pumpA_IN2, LOW);
}

void pumpAOff() {
  digitalWrite(pumpA_IN1, LOW);
  digitalWrite(pumpA_IN2, LOW);
}

void pumpBOn() {
  digitalWrite(pumpB_IN1, HIGH);
  digitalWrite(pumpB_IN2, LOW);
}

void pumpBOff() {
  digitalWrite(pumpB_IN1, LOW);
  digitalWrite(pumpB_IN2, LOW);
}

void allPumpsOff() {
  pumpAOff();
  pumpBOff();
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  analogReadResolution(12);

  pinMode(pumpA_IN1, OUTPUT);
  pinMode(pumpA_IN2, OUTPUT);
  pinMode(pumpB_IN1, OUTPUT);
  pinMode(pumpB_IN2, OUTPUT);

  allPumpsOff();

  Serial.println("Hydroponic EC control prototype started");
}

void loop() {
  float ec = readEC();

  if (ec < lowEC) {
    Serial.println("EC LOW -> dosing Nutrient A");
    pumpAOn();
    delay(pumpTime);
    pumpAOff();

    Serial.println("Waiting 5 seconds before dosing Nutrient B...");
    delay(betweenPumpsDelay);

    Serial.println("Dosing Nutrient B");
    pumpBOn();
    delay(pumpTime);
    pumpBOff();

    Serial.println("Dosing complete. Waiting for mixing...");
    delay(mixDelay);
  }
  else if (ec > highEC) {
    Serial.println("EC ABOVE RANGE -> do not dose");
    delay(3000);
  }
  else {
    Serial.println("EC WITHIN RANGE");
    delay(3000);
  }

  Serial.println("----------------------------");
}
