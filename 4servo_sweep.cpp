#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int pos = 0;

void setup() {
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
  servo4.attach(6);
}

void loop() {
  unsigned long startTime = millis();

  while (true) {
    for (pos = 0; pos <= 180; pos++) {
      if (millis() - startTime >= 2000) goto hold;  // إذا تجاوزنا ثانيتين ننتقل للتثبيت
      servo1.write(pos);
      servo2.write(pos);
      servo3.write(pos);
      servo4.write(pos);
      delay(15);
    }

    for (pos = 180; pos >= 0; pos--) {
      if (millis() - startTime >= 2000) goto hold;
      servo1.write(pos);
      servo2.write(pos);
      servo3.write(pos);
      servo4.write(pos);
      delay(15);
    }
  }

hold:
  servo1.write(90);
  servo2.write(90);
  servo3.write(90);
  servo4.write(90);

  while (true); // إيقاف التكرار
}

