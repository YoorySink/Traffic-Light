int ledRed[] = {2, 5, 8};
int ledYellow[] = {3};
int ledGreen[] = {4, 7, 10};
int Button[] = {11, 12};
int jumlahLampu = 3;

void setup() {
  for (int i = 0; i < jumlahLampu; i++) {
    pinMode(ledGreen[i], OUTPUT);
    pinMode(ledYellow[i], OUTPUT);
    pinMode(ledRed[i], OUTPUT);
  }
  
  for (int j = 0; j < 2; j++) {
    pinMode(Button[j], INPUT_PULLUP);
  }
}

void kondisiAwal() {
  digitalWrite(ledRed[0], LOW);
  digitalWrite(ledYellow[0], LOW);
  digitalWrite(ledGreen[0], HIGH);

  for (int i = 1; i < jumlahLampu; i++) {
    digitalWrite(ledGreen[i], LOW);
    digitalWrite(ledYellow[i], LOW);
    digitalWrite(ledRed[i], HIGH);
  }
}

void kelapkelip(int i) {
  for (int k = 0; k < 3; k++) {
    digitalWrite(ledYellow[i], HIGH);
    delay(300);
    digitalWrite(ledYellow[i], LOW);
    delay(300);
  }
}

void interupt() {
  if (digitalRead(Button[0]) == LOW || digitalRead(Button[1]) == LOW) {
    digitalWrite(ledGreen[0], LOW);
    digitalWrite(ledRed[0], HIGH);

    for (int i = 1; i < jumlahLampu; i++) {
      digitalWrite(ledRed[i], LOW);
      digitalWrite(ledGreen[i], HIGH);
    }

    delay(5000);

    for (int i = 1; i < jumlahLampu; i++) {
      digitalWrite(ledGreen[i], LOW);
      digitalWrite(ledRed[i], HIGH);
    }

    digitalWrite(ledRed[0], LOW);
    kelapkelip(0);
    digitalWrite(ledYellow[0], HIGH);
    delay(2000);
    digitalWrite(ledYellow[0], LOW);
  }
}

void loop() {
  kondisiAwal();
  interupt();
}
