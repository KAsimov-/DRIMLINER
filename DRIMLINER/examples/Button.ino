#include <DRIMLINER.h>
#define BUTTON_PIN_1 1
#define BUTTON_PIN_2 2

buzzerModule buzzer;
buttonModule my1stbutton(BUTTON_PIN_1);
buttonModule my2ndbutton(BUTTON_PIN_2);

void setup() {
  // put your setup code here, to run once:
	my1stbutton.echoOn();
	my2ndbutton.echoOn();
}

void loop() {
  // put your main code here, to run repeatedly: 
  my1stbutton.check();
  delay(10);
  my2ndbutton.check();
  delay(1000);
}
