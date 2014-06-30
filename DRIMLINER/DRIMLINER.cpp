/****************************************************************************************************
-.    `             -.
:++++++-:+++++++/-`     -+++++++++++++++++++/`    ........    `hhymd+:/yMy/  ``   `oysmd+/.
yMMMMMM`/MMMMMMMMMMd+`  NMMMMMMMMMMMMho++hNo++  --`       .-`oyMMMMMMsomMmohsdd+o-odMMMMMh-
yMMMMMN-+hhhhdNMMMMMMd` NMMMMMNysso+. .::oN::: :   ` `- `   --sMMMMMMhy :/mMMMMMmyydMMMMMhd.
yMMMMMN`      `yMMMMMM/ NMMMMMy       +MMMMMMm..  .`:/`..-   /sMMMMMMhy  oNMMMMMMssdMMMMMy
yMMMMMN`       :MMMMMM+ NNNNNNy       +NNNNNNm`:   -.`  .`  .-`MMMMMMdM+  smNMMModNdMMMMMy
yMMMMMN`       :MMMMMM+ NNMMMMy       sMMNmMMM``-` .`   -  -- `MMMMMMdMM-   ./ -hMNdMMMMMy
yMMMMMN`       :MMMMMM+ NMMMMMy       :shmd-``   .- -  .``-   `MMMMMMdMMm`     /MMNdMMMMMy
yMMMMMN`       :MMMMMM+ NMMMMMy    `/ymMMdh       :+soos++    `MMMMMMdMMMy    -NMMNdMMMMMy
yMMMMMN`       :MMMMMM+ NMMMMMh  -shddmMo-s       /MMMMMMy    `MMMMMMdMMMM+  `mMMMmdMMMMMy
yMMMMMN`       :MMMMMM+ sMMMMMM` hMdMmd: /h`      /MMMMMMy    `MMMMMMyMMMMM:`+NMMM:dMMMMMy
yMMMMMN`    osshMMN+++. +MMMMMM- :hdmmMh:        `oMMMMMMy`   `MMMMMM:yMMMMNd::MMs dMMMMMy
yMMMMMN`    mMMMMMm     /MMMMMM:   -sNMMMd:      :dMMMMMMd+`  `MMMMMM:`NMh.+mMMMm` dMMMMMy
yMMMMMN`    mMMMMMm     /MMMMMM:     .dMMMMd+:sshd+MMMMMMssNyh:MMMMMM: /MMNmh//N:  dMMMMMy
yMMMMMN`    mMMMMMm     /MMMMMM:       oMNNNNmsNm`-MMMMMM+ oMo.MMMMMM:  ym+shhms   dMMMMMy
yMMMMMN`  `/MMMMMMm     /MMMMMM:      `oMdMMdMyNy -MMMMMM+ -M/`MMMMMM:  `dyyhsy`   dMMMMMy
yMMMMMMmdmMMMMMMMN:     /MMMMMM:        +mdmmhhNN--MMMMMM+`hMd/MMMMMM:   /ddd:     dMMMMMy
yMMMMMMMMMMMMMMdo`      /MMMMMM:         .  ``::+NymMMMMNsmh:/.MMMMMM:             dMMMMMy
-///:://::::-.          ./:::::`                 `mNhhdhmM:    ://///`             ://///-
:+`   //`

-----------------------------------------------DRIM--------------------------------------------------
Dream Realize Imagine Make
-----------------------------------------------------------------------------------------------------
Library for interfacing
DRIMLINER Shield for OPENCM9.04

Program written by Mingyu Kim
Board supported by Jeeho Ahn
- inquiries please email
mingyu@mingyu.co.kr

Library Version 1.5
For OPENCM IDE 1.0.1
Last Updated on Jun. 30. 2014

Clubs Participating in DRIMLINER Project
- KAsimov of Korea University
http://www.kasimov.co.kr/
- E.E.I of Ewha University

This library follows the Arduino Conventions
http://playground.arduino.cc/Code/Library#WhatArduinoWay

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
****************************************************************************************************/


#include "DRIMLINER.h"

////////////////////////////////////////////////////////////////////////
///////////////     C             D             S     //////////////////
////////////////////////////////////////////////////////////////////////

cdsModule::cdsModule(int pin, int range) {
	pin_number = pin;
	range_number = range;
}

cdsModule::cdsModule(int pin) {
	pin_number = pin;
	range_number = 20;
}

int cdsModule::read(void){
	pinMode(pin_number, INPUT_ANALOG);
	int temp = map(analogRead(pin_number), 0, 4095, 0, range_number);
	pinMode(pin_number, INPUT);
	return temp;
}

int cdsModule::check(void){
	pinMode(pin_number, INPUT_ANALOG);
	int temp = cdsModule::read();
	SerialUSB.print("light sensor at pin ");
	SerialUSB.print(pin_number);
	SerialUSB.print(" is reading : ");
	SerialUSB.println(temp);
	pinMode(pin_number, INPUT);
	return temp;
}




////////////////////////////////////////////////////////////////////////
///////////////    T        E         M         P     //////////////////
////////////////////////////////////////////////////////////////////////

temperatureModule::temperatureModule(int pin) {
	pin_number = pin;
}

float temperatureModule::read(void){
	pinMode(pin_number, INPUT_ANALOG);
	float temp = (((float)analogRead(pin_number) * 3300 / 4096)-400) / 19.5;
	pinMode(pin_number, INPUT);
	return temp;
}

float temperatureModule::check(void){
	float temp = temperatureModule::read();
	SerialUSB.print("temperature sensor at pin ");
	SerialUSB.print(pin_number);
	SerialUSB.print(" is reading : ");
	SerialUSB.println(temp);
	pinMode(pin_number, INPUT);
	return temp;
}




////////////////////////////////////////////////////////////////////////
///////////////    H        A         L         L     //////////////////
////////////////////////////////////////////////////////////////////////

hallModule::hallModule(int pin) {
	pin_number = pin;
}

int hallModule::read(void){
	pinMode(pin_number, INPUT_ANALOG);
	int temp = 23 + (((analogRead(pin_number) * 3300 / 4096) - 1691) / 1.3);
	pinMode(pin_number, INPUT);
	return temp;
}

int hallModule::check(void){
	int temp = hallModule::read();
	SerialUSB.print("hall sensor at pin ");
	SerialUSB.print(pin_number);
	SerialUSB.print(" is reading : ");
	SerialUSB.println(temp);
	return temp;
}



////////////////////////////////////////////////////////////////////////
///////////////    B     U     T     T     O     N    //////////////////
////////////////////////////////////////////////////////////////////////

int _button_pins[10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
int _debounce[10];
int _countup[10];
int _echo[10];
int _int_pin_number[10];
volatile long _last_press[10];

void echoMe(){
	for (int counter = 0; counter < 10; counter++){
		if (_echo[counter] > 0){
			SerialUSB.print("Pin");
			SerialUSB.print(_int_pin_number[counter]);
			SerialUSB.println(" Button On");
		}
	}
}

void event0(){
	if (micros() - _last_press[0] > _debounce[0]){
		_countup[0]++;
		_last_press[0] = micros();
		echoMe();
	}
}
void event1(){
	if (micros() - _last_press[1] > _debounce[1]){
		_countup[1]++;
		_last_press[1] = micros();
		echoMe();
	}
}
void event2(){
	if (micros() - _last_press[2] > _debounce[2]){
		_countup[2]++;
		_last_press[2] = micros();
		echoMe();
	}
}
void event3(){
	if (micros() - _last_press[3] > _debounce[3]){
		_countup[3]++;
		_last_press[3] = micros();
		echoMe();
	}
}
void event4(){
	if (micros() - _last_press[4] > _debounce[4]){
		_countup[4]++;
		_last_press[4] = micros();
		echoMe();
	}
}
void event5(){
	if (micros() - _last_press[5] > _debounce[5]){
		_countup[5]++;
		_last_press[5] = micros();
		echoMe();
	}
}
void event6(){
	if (micros() - _last_press[6] > _debounce[6]){
		_countup[6]++;
		_last_press[6] = micros();
		echoMe();
	}
}
void event7(){
	if (micros() - _last_press[7] > _debounce[7]){
		_countup[7]++;
		_last_press[7] = micros();
		echoMe();
	}
}
void event8(){
	if (micros() - _last_press[8] > _debounce[8]){
		_countup[8]++;
		_last_press[8] = micros();
		echoMe();
	}
}
void event9(){
	if (micros() - _last_press[9] > _debounce[9]){
		_countup[9]++;
		_last_press[9] = micros();
		echoMe();
	}
}

buttonModule::buttonModule(int pin){
	pin_number = pin;
	pinMode(pin_number, INPUT);

	for (int counter = 0; counter < 10; counter++){
		if (_button_pins[counter] < 0){
			_button_pins[counter] = pin_number;
			order_number = counter;
			//SerialUSB.print("Before me ");
			SerialUSB.print(order_number);
			_int_pin_number[order_number] = pin_number;
			//SerialUSB.println(" buttons are attached");
			break;
		}
	}

	switch (order_number){
	case 0:
		attachInterrupt(pin_number, event0, RISING);
		//SerialUSB.print("EVENT 0 attached to ");
		SerialUSB.println(pin_number);
		break;
	case 1:
		attachInterrupt(pin_number, event1, RISING);
		//SerialUSB.print("EVENT 1 attached to ");
		SerialUSB.println(pin_number);
		break;
	case 2:
		attachInterrupt(pin_number, event2, RISING);
		//SerialUSB.print("EVENT 2 attached to ");
		SerialUSB.println(pin_number);
		break;
	case 3:
		attachInterrupt(pin_number, event3, RISING);
		//SerialUSB.print("EVENT 3 attached to ");
		SerialUSB.println(pin_number);
		break;
	case 4:
		attachInterrupt(pin_number, event4, RISING);
		//SerialUSB.print("EVENT 4 attached to ");
		SerialUSB.println(pin_number);
		break;
	case 5:
		attachInterrupt(pin_number, event5, RISING);
		//SerialUSB.print("EVENT 5 attached to ");
		SerialUSB.println(pin_number);
		break;
	case 6:
		attachInterrupt(pin_number, event6, RISING);
		//SerialUSB.print("EVENT 6 attached to ");
		SerialUSB.println(pin_number);
		break;
	case 7:
		attachInterrupt(pin_number, event7, RISING);
		//SerialUSB.print("EVENT 7 attached to ");
		SerialUSB.println(pin_number);
		break;
	case 8:
		attachInterrupt(pin_number, event8, RISING);
		//SerialUSB.print("EVENT 8 attached to ");
		SerialUSB.println(pin_number);
		break;
	case 9:
		attachInterrupt(pin_number, event9, RISING);
		//SerialUSB.print("EVENT 9 attached to ");
		SerialUSB.println(pin_number);
		break;
	}
	_debounce[order_number] = 50 * 1000;
	_countup[order_number] = 0;
	_echo[order_number] = 1;
}


int buttonModule::timeSincePressed(void){
	return (micros() - _last_press[order_number]) / 1000;
}

int buttonModule::howManyTimes(void){
	return _countup[order_number];
}

void buttonModule::timesReset(void){
	_countup[order_number] = 0;
}

int buttonModule::read(void){
	return digitalRead(pin_number);
}

int buttonModule::check(void){
	SerialUSB.print("button at pin ");
	SerialUSB.print(pin_number);
	SerialUSB.print(" has been pressed ");
	SerialUSB.print(_countup[order_number]);
	SerialUSB.println(" times and");
	SerialUSB.print((micros() - _last_press[order_number]) / 1000000);
	SerialUSB.println(" seconds have passed since last pressed");
}

void buttonModule::debug(void){
	SerialUSB.print("button at pin ");
	SerialUSB.print(pin_number);
	SerialUSB.print(" is attached to event ");
	SerialUSB.println(order_number);
}

void buttonModule::setDebounce(int time){
	_debounce[order_number] = time * 1000;
}

void buttonModule::echoOn(void){
	_echo[order_number] = 1;
}

void buttonModule::echoOff(void){
	_echo[order_number] = 0;
}



////////////////////////////////////////////////////////////////////////
///////////////     L             E             D     //////////////////
////////////////////////////////////////////////////////////////////////


#define _pin_number 0
#define _interval 1
#define _duration 2
#define _start_time 3

int _LED_NUMBER[25][4];
volatile unsigned long _LED_LAST_TIME[25];
volatile bool _LED_LAST_STATUS[25];

void _LED_BLINK(){
	for (int counter = 0; counter < 25; counter++){
		if (_LED_NUMBER[counter][_pin_number] > -1){
			if ((micros() - _LED_NUMBER[counter][_start_time]) < _LED_NUMBER[counter][_duration]){
				if (micros() - _LED_LAST_TIME[counter] > _LED_NUMBER[counter][_interval]){
					if (!_LED_LAST_STATUS[counter]){
						//pinMode(_LED_NUMBER[counter][_pin_number], OUTPUT);
						digitalWrite(_LED_NUMBER[counter][_pin_number], HIGH);
						_LED_LAST_STATUS[counter] = true;
						_LED_LAST_TIME[counter] = micros();
					}
					else{
						digitalWrite(_LED_NUMBER[counter][_pin_number], LOW);
						//pinMode(_LED_NUMBER[counter][_pin_number], INPUT);
						_LED_LAST_STATUS[counter] = false;
						_LED_LAST_TIME[counter] = micros();
					}
				}
			}
			else if (!_LED_LAST_STATUS[counter]){
				digitalWrite(_LED_NUMBER[counter][_pin_number], 1);
			}
		}
		else { break; }
	}
}

//LED USES TIMER4
bool _has_led_init = false;
void _led_blink_init(void){
	for (int counter = 0; counter < 25; counter++){
		_LED_NUMBER[counter][_pin_number] = -1;
		_LED_NUMBER[counter][_interval] = -1;
		_LED_NUMBER[counter][_duration] = -1;
		_LED_NUMBER[counter][_start_time] = -1;
	}
	HardwareTimer timer(4);
	timer.pause();
	timer.setPeriod(0.1 * 100000);
	timer.setChannel1Mode(TIMER_OUTPUT_COMPARE);
	timer.setCompare(TIMER_CH1, 0);
	timer.attachInterrupt(1, _LED_BLINK);
	timer.refresh();
	timer.resume();
	_has_led_init = true;
}


ledModule::ledModule(int pin){
	pin_number = pin;
	pinMode(pin_number, OUTPUT);
	for (int counter = 0; counter < 25; counter++){
		if (_LED_NUMBER[counter][_pin_number] == -1){
			order_number = counter;
			break;
		}
	}
}

void ledModule::on(void){
	//pinMode(pin_number, OUTPUT);
	digitalWrite(pin_number, HIGH);
}

void ledModule::off(void){
	digitalWrite(pin_number, LOW);
	//pinMode(pin_number, INPUT);
}

void ledModule::blink(float interval, int duration){
	if (!_has_led_init)_led_blink_init();
	_LED_NUMBER[order_number][_pin_number] = pin_number;
	_LED_NUMBER[order_number][_interval] = int(interval * 1000000);
	_LED_NUMBER[order_number][_duration] = duration * 1000000;
	_LED_NUMBER[order_number][_start_time] = micros();
}



////////////////////////////////////////////////////////////////////////
///////////////     D             X             L     //////////////////
////////////////////////////////////////////////////////////////////////

Dynamixel Dxl(1);

ezDynamixel::ezDynamixel(int id){
	myID = id;
}

void ezDynamixel::begin(int baud){
	Dxl.begin(baud);
}

void ezDynamixel::resetSettings(void){
	ezDynamixel::setBaud(1);
	ezDynamixel::setReturnDelay(250);
	ezDynamixel::setCWLimit(0);
	ezDynamixel::setCCWLimit(1023);
	ezDynamixel::setTempLimit(70);
	ezDynamixel::setStatusReturn(2);

}

void ezDynamixel::setWheelMode(void){
	ezDynamixel::setCWLimit(0);
	ezDynamixel::setCCWLimit(0);
}

void ezDynamixel::setJointMode(void){
	ezDynamixel::setCWLimit(0);
	ezDynamixel::setCCWLimit(1023);
}

int ezDynamixel::readModelNumber(void){
	return Dxl.readWord(myID, P_MODEL_NUMBER_L);
}

int ezDynamixel::readFirmwareVersion(void){
	return Dxl.readByte(myID, P_VERSION);
}

void ezDynamixel::setID(int newID){
	Dxl.writeByte(myID, P_ID, newID);
}

void ezDynamixel::setBaud(int newBaud){
	Dxl.writeByte(myID, P_BAUD_RATE, newBaud);
}

void ezDynamixel::setReturnDelay(int newDelay){
	Dxl.writeByte(myID, P_RETURN_DELAY_TIME, newDelay);
}

void ezDynamixel::setCWLimit(int newLimit){
	Dxl.writeWord(myID, P_CW_ANGLE_LIMIT_L, newLimit);
}

void ezDynamixel::setCCWLimit(int newLimit){
	Dxl.writeWord(myID, P_CCW_ANGLE_LIMIT_L, newLimit);
}

void ezDynamixel::setTempLimit(int newTemp){
	Dxl.writeByte(myID, P_LIMIT_TEMPERATURE, newTemp);
}

void ezDynamixel::setLowVoltage(int newVolt){
	Dxl.writeByte(myID, P_DOWN_LIMIT_VOLTAGE, newVolt);
}

void ezDynamixel::setHighVoltage(int newVolt){
	Dxl.writeByte(myID, P_UP_LIMIT_VOLTAGE, newVolt);
}

void ezDynamixel::setStatusReturn(int newStat){
	Dxl.writeByte(myID, P_RETURN_LEVEL, newStat);
}

void ezDynamixel::setPosition(int newPosition){
	Dxl.writeWord(myID, P_GOAL_POSITION_L, newPosition);
}

void ezDynamixel::setSpeed(int newSpeed){
	Dxl.writeWord(myID, P_GOAL_SPEED_L, newSpeed);
}

void ezDynamixel::ledOn(void){
	Dxl.writeByte(myID, P_LED, 1);
}

void ezDynamixel::ledOff(void){
	Dxl.writeByte(myID, P_LED, 0);
}

void ezDynamixel::setTorqueLimit(int newLimit){
	Dxl.writeWord(myID, P_TORQUE_LIMIT_L, newLimit);
}

int ezDynamixel::readPosition(void){
	return Dxl.readWord(myID, P_PRESENT_POSITION_L);
}

int ezDynamixel::readSpeed(void){
	return Dxl.readWord(myID, P_PRESENT_SPEED_L);
}

int ezDynamixel::readLoad(void){
	return Dxl.readWord(myID, P_PRESENT_LOAD_L);
}

int ezDynamixel::readVoltage(void){
	return Dxl.readByte(myID, P_PRESENT_VOLTAGE);
}

int ezDynamixel::readTemperature(void){
	return Dxl.readByte(myID, P_PRESENT_TEMPERATURE);
}

int ezDynamixel::isItWorking(void){
	return Dxl.readByte(myID, P_REGISTERED_INSTRUCTION);
}

int ezDynamixel::isItMoving(void){
	return Dxl.readByte(myID, P_MOVING);
}

void ezDynamixel::lock(void){
	Dxl.writeByte(myID, 47, 1);
}

void ezDynamixel::unlock(void){
	Dxl.writeByte(myID, 47, 0);
}

void ezDynamixel::setPunch(int newPunch){
	Dxl.writeWord(myID, 48, newPunch);
}

int ezDynamixel::isError(void){
	return Dxl.readByte(myID, P_ALARM_SHUTDOWN);
}




////////////////////////////////////////////////////////////////////////
///////////////    B        U         Z         Z     //////////////////
////////////////////////////////////////////////////////////////////////

buzzerModule::buzzerModule(void){
	pinMode(15, OUTPUT);
	digitalWrite(15, LOW);
}

void buzzerModule::on(void){
	digitalWrite(15, HIGH);
}

void buzzerModule::off(void){
	digitalWrite(15, LOW);
}




////////////////////////////////////////////////////////////////////////
///////////////     I                           R     //////////////////
////////////////////////////////////////////////////////////////////////

irModule::irModule(int pin){
	pin_number = pin;
	pinMode(pin_number, INPUT_ANALOG);
}

int irModule::read(void){
	int readvalue = analogRead(pin_number);
	if (readvalue > 1200){
		return 1;
	}
	else if (readvalue < 1200) {
		return 0;
	}
}

void irModule::check(void){
	SerialUSB.print("Infrared sensor at pin ");
	SerialUSB.print(pin_number);
	SerialUSB.print(" is reading : ");
	SerialUSB.println(analogRead(pin_number));
}


////////////////////////////////////////////////////////////////////////
///////////////     M             I             C     //////////////////
////////////////////////////////////////////////////////////////////////

int _mic_pin;
int _delayTime;
int _micCount;
int _echoMic;
volatile long _lastMic;

void echoMic(){
		if (_echoMic > 0){
			SerialUSB.print("Pin");
			SerialUSB.print(_mic_pin);
			SerialUSB.println(" Mic Spike");
	}
}

void eventMic(){
	if (micros() - _lastMic > _delayTime){
		_micCount++;
		_lastMic = micros();
		echoMic();
	}
}

microphoneModule::microphoneModule(int pin){
	pin_number = pin;
	pinMode(pin_number, INPUT);
	attachInterrupt(pin_number, eventMic, RISING);
	_delayTime = 50 * 1000;
	_micCount = 0;
	_echoMic = 1;
}


int microphoneModule::timeSincePressed(void){
	return (micros() - _lastMic) / 1000;
}

int microphoneModule::howManyTimes(void){
	return _micCount;
}

void microphoneModule::timesReset(void){
	_micCount = 0;
}

int microphoneModule::read(void){
	pinMode(pin_number, INPUT_ANALOG);
	int analogValue = analogRead(pin_number);
	pinMode(pin_number, INPUT);
	return analogValue;
}

int microphoneModule::check(void){
	SerialUSB.print("Mic at pin ");
	SerialUSB.print(pin_number);
	SerialUSB.print(" has been spiked ");
	SerialUSB.print(_micCount);
	SerialUSB.println(" times and");
	SerialUSB.print((micros() - _lastMic) / 1000000);
	SerialUSB.println(" seconds have passed since last spike");
}

void microphoneModule::setDelay(int time){
	_delayTime = time * 1000;
}

void microphoneModule::echoOn(void){
	_echoMic = 1;
}

void microphoneModule::echoOff(void){
	_echoMic = 0;
}

