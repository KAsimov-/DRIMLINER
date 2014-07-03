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
		supported by Jeeho Ahn
		supported by Jason Lee of ROBOTIS
- inquiries please email
mingyu@mingyu.co.kr

Library Version 1.6
For OPENCM IDE 1.0.2
Last Updated on July. 2. 2014

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

#define ON 1
#define OFF 0

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
	return temp;
}

int cdsModule::read(int range)
{
    pinMode(pin_number, INPUT_ANALOG);
	int temp = map(analogRead(pin_number), 0, 4095, 0, range-1);
	return temp;
}

int cdsModule::check(void){
	pinMode(pin_number, INPUT_ANALOG);
	int temp = cdsModule::read();
	SerialUSB.print("light intesity ");
	SerialUSB.println(temp);
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
	return temp;
}

float temperatureModule::check(void){
	float temp = temperatureModule::read();
	SerialUSB.print("temperature ");
	SerialUSB.print(temp);
    SerialUSB.println(" Celcius");
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
			SerialUSB.print(order_number);
			_int_pin_number[order_number] = pin_number;
			break;
		}
	}

	switch (order_number){
	case 0:
		attachInterrupt(pin_number, event0, RISING);
		SerialUSB.println(pin_number);
		break;
	case 1:
		attachInterrupt(pin_number, event1, RISING);
		SerialUSB.println(pin_number);
		break;
	case 2:
		attachInterrupt(pin_number, event2, RISING);
		SerialUSB.println(pin_number);
		break;
	case 3:
		attachInterrupt(pin_number, event3, RISING);
		SerialUSB.println(pin_number);
		break;
	case 4:
		attachInterrupt(pin_number, event4, RISING);
		SerialUSB.println(pin_number);
		break;
	case 5:
		attachInterrupt(pin_number, event5, RISING);
		SerialUSB.println(pin_number);
		break;
	case 6:
		attachInterrupt(pin_number, event6, RISING);
		SerialUSB.println(pin_number);
		break;
	case 7:
		attachInterrupt(pin_number, event7, RISING);
		SerialUSB.println(pin_number);
		break;
	case 8:
		attachInterrupt(pin_number, event8, RISING);
		SerialUSB.println(pin_number);
		break;
	case 9:
		attachInterrupt(pin_number, event9, RISING);
		SerialUSB.println(pin_number);
		break;
	}
	_debounce[order_number] = 50 * 1000;
	_countup[order_number] = 0;
	_echo[order_number] = 1;
}


float buttonModule::readTime(void){
	return (micros() - _last_press[order_number]) / 1000000;
}

int buttonModule::howManyTimes(void){
	return _countup[order_number];
}

void buttonModule::timesReset(void){
	_countup[order_number] = 0;
}

int buttonModule::readDigital(void){
	return digitalRead(pin_number);
}

int buttonModule::read(void){
	int buttonCount = buttonModule::howManyTimes();
	buttonModule::timesReset();
	return buttonCount;
}

int buttonModule::check(void){
	SerialUSB.print("button at pin ");
	SerialUSB.print(pin_number);
	SerialUSB.print(" has been pressed ");
    SerialUSB.print(" ");
	SerialUSB.print(_countup[order_number]);
	SerialUSB.println(" times");
	SerialUSB.print((micros() - _last_press[order_number]) / 1000000);
	SerialUSB.println(" seconds have passed since last pressed");
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
						digitalWrite(_LED_NUMBER[counter][_pin_number], HIGH);
						_LED_LAST_STATUS[counter] = true;
						_LED_LAST_TIME[counter] = micros();
					}
					else{
						digitalWrite(_LED_NUMBER[counter][_pin_number], LOW);
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
	digitalWrite(pin_number, HIGH);
}

void ledModule::off(void){
	digitalWrite(pin_number, LOW);
}

void ledModule::blink(float interval, int duration){
	if (!_has_led_init)_led_blink_init();
	_LED_NUMBER[order_number][_pin_number] = pin_number;
	_LED_NUMBER[order_number][_interval] = int(interval * 1000000);
	_LED_NUMBER[order_number][_duration] = duration * 1000000;
	_LED_NUMBER[order_number][_start_time] = micros();
}


////////////////////////////////////////////////////////////////////////
///////////////     D          X           L     ax-12//////////////////
////////////////////////////////////////////////////////////////////////

Dynamixel Dxl(1);

axMotor::axMotor(int id){
	myID = id;
    axMotor::begin(3);
}

void axMotor::begin(int baud){
	Dxl.begin(baud);
}

void axMotor::resetSettings(void){
	axMotor::setBaud(3);
	axMotor::setReturnDelay(250);
	axMotor::setCWLimit(0);
	axMotor::setCCWLimit(1023);
	axMotor::setTempLimit(70);
	axMotor::setStatusReturn(2);
    
}

void axMotor::setWheelMode(void){
	axMotor::setCWLimit(0);
	axMotor::setCCWLimit(0);
}

void axMotor::setJointMode(void){
	axMotor::setCWLimit(0);
	axMotor::setCCWLimit(1023);
}

void axMotor::jointMove(int position)
{
    axMotor::setJointMode();
    axMotor::setPosition(position);
}

void axMotor::jointMove(int position, int speed)
{
    axMotor::setJointMode();
    axMotor::setSpeed(speed);
    axMotor::setPosition(position);
    
}

int axMotor::readModelNumber(void){
	return Dxl.readWord(myID, 0);
}

int axMotor::readFirmwareVersion(void){
	return Dxl.readByte(myID, 2);
}

void axMotor::setID(int newID){
	Dxl.writeByte(myID, 3, newID);
}

void axMotor::setBaud(int newBaud){
	Dxl.writeByte(myID, 4, newBaud);
}

void axMotor::setReturnDelay(int newDelay){
	Dxl.writeByte(myID, 5, newDelay);
}

void axMotor::setCWLimit(int newLimit){
	Dxl.writeWord(myID, 6, newLimit);
}

void axMotor::setCCWLimit(int newLimit){
	Dxl.writeWord(myID, 8, newLimit);
}

void axMotor::setTempLimit(int newTemp){
	Dxl.writeByte(myID, 11, newTemp);
}

void axMotor::setLowVoltage(int newVolt){
	Dxl.writeByte(myID, 12, newVolt);
}

void axMotor::setHighVoltage(int newVolt){
	Dxl.writeByte(myID, 13, newVolt);
}

void axMotor::setStatusReturn(int newStat){
	Dxl.writeByte(myID, 16, newStat);
}

void axMotor::setPosition(int newPosition){
	Dxl.writeWord(myID, 30, newPosition);
}

void axMotor::setSpeed(int newSpeed){
	Dxl.writeWord(myID, 32, newSpeed);
}

void axMotor::ledOn(void){
	Dxl.writeByte(myID, 25, 1);
}

void axMotor::ledOff(void){
	Dxl.writeByte(myID, 25, 0);
}

void axMotor::setTorqueLimit(int newLimit){
	Dxl.writeWord(myID, 34, newLimit);
}

int axMotor::readPosition(void){
	return Dxl.readWord(myID, 36);
}

int axMotor::readSpeed(void){
	return Dxl.readWord(myID, 38);
}

int axMotor::readLoad(void){
	return Dxl.readWord(myID, 40);
}

int axMotor::readVoltage(void){
	return Dxl.readByte(myID, 42);
}

int axMotor::readTemperature(void){
	return Dxl.readByte(myID, 43);
}

int axMotor::isItWorking(void){
	return Dxl.readByte(myID, 44);
}

int axMotor::isItMoving(void){
	return Dxl.readByte(myID, 46);
}

void axMotor::lock(void){
	Dxl.writeByte(myID, 47, 1);
}

void axMotor::unlock(void){
	Dxl.writeByte(myID, 47, 0);
}

void axMotor::setPunch(int newPunch){
	Dxl.writeWord(myID, 48, newPunch);
}

int axMotor::isError(void){
	return Dxl.readByte(myID, 18);
}



////////////////////////////////////////////////////////////////////////
///////////////     D          X          L     xl-320//////////////////
////////////////////////////////////////////////////////////////////////


xlMotor::xlMotor(int id){
	myID = id;
    xlMotor::begin(3);
}

void xlMotor::begin(int baud){
	Dxl.begin(baud);
}

void xlMotor::resetSettings(void){
	xlMotor::setBaud(3);
	xlMotor::setReturnDelay(250);
    Dxl.jointMode(myID);
	xlMotor::setTempLimit(70);
	xlMotor::setStatusReturn(2);
    
}


void xlMotor::jointMove(int position)
{
    Dxl.jointMode(myID);
    delayMicroseconds(1);
    Dxl.setPosition(myID,position,512);
    delayMicroseconds(1);
}

void xlMotor::jointMove(int position, int speed)
{
    Dxl.jointMode(myID);
    delayMicroseconds(100);
    Dxl.setPosition(myID,position,speed);
    delayMicroseconds(1);
}

void xlMotor::wheelMove(char direction)
{
    Dxl.wheelMode(myID);
    if (direction=='F')
	{
        Dxl.goalSpeed(myID, 512);
    }
    else if(direction=='R')
	{
        Dxl.goalSpeed(myID, 512| 0x400);
    }
    else if(direction=='S')
    {
        Dxl.goalSpeed(myID, 0);
    }
    
}

void xlMotor::wheelMove(char direction,int speed)
{
    if (direction=='F') {
        Dxl.goalSpeed(myID, speed);
    }
    else if(direction=='R')
    {
        Dxl.goalSpeed(myID, speed| 0x400);
    }
   
    
}

int xlMotor::readModelNumber(void){
	return Dxl.readWord(myID, 0);
}

int xlMotor::readFirmwareVersion(void){
	return Dxl.readByte(myID, 2);
}

void xlMotor::setID(int newID){
	Dxl.writeByte(BROADCAST_ID, 3, newID);
}

void xlMotor::setBaud(int newBaud){
	Dxl.writeByte(myID, 4, newBaud);
}

void xlMotor::setReturnDelay(int newDelay){
	Dxl.writeByte(myID, 5, newDelay);
}

void xlMotor::setCWLimit(int newLimit){
	Dxl.writeWord(myID, 6, newLimit);
}

void xlMotor::setCCWLimit(int newLimit){
	Dxl.writeWord(myID, 8, newLimit);
}

void xlMotor::setTempLimit(int newTemp){
	Dxl.writeByte(myID, 12, newTemp);
}

void xlMotor::setLowVoltage(int newVolt){
	Dxl.writeByte(myID, 13, newVolt);
}

void xlMotor::setHighVoltage(int newVolt){
	Dxl.writeByte(myID, 14, newVolt);
}

void xlMotor::setStatusReturn(int newStat){
	Dxl.writeByte(myID, 17, newStat);
}

void xlMotor::setPosition(int newPosition){
	Dxl.writeWord(myID, 30, newPosition);
}

void xlMotor::setSpeed(int newSpeed){
	Dxl.writeWord(myID, 32, newSpeed);
}

void xlMotor::ledOn(void){
	Dxl.writeByte(myID, 25, 1);
}

void xlMotor::ledOff(void){
	Dxl.writeByte(myID, 25, 0);
}

void xlMotor::setTorqueLimit(int newLimit){
	Dxl.writeWord(myID, 15, newLimit);
}

int xlMotor::readPosition(void){
	return Dxl.readWord(myID, 37);
}

int xlMotor::readSpeed(void){
	return Dxl.readWord(myID, 39);
}

int xlMotor::readLoad(void){
	return Dxl.readWord(myID, 41);
}

int xlMotor::readVoltage(void){
	return Dxl.readByte(myID, 45);
}

int xlMotor::readTemperature(void){
	return Dxl.readByte(myID, 46);
}

int xlMotor::isItWorking(void){
	return Dxl.readByte(myID, 47);
}

int xlMotor::isItMoving(void){
	return Dxl.readByte(myID, 49);
}

void xlMotor::lock(void){
	Dxl.writeByte(myID, 47, 1);
}

void xlMotor::unlock(void){
	Dxl.writeByte(myID, 47, 0);
}

void xlMotor::setPunch(int newPunch){
	Dxl.writeWord(myID, 48, newPunch);
}

int xlMotor::isError(void){
	return Dxl.readByte(myID, 18);
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




int _infra_pins[4] = { -1, -1, -1, -1};
int _infra_debounce[4];
int _infra_countup[4];
int _infra_echo[4];
volatile long _last_infra_press[4];

void echoInfra(){
	for (int counter = 0; counter < 4; counter++){
		if (_infra_echo[counter] > 0){
			SerialUSB.print("Infrared");
			SerialUSB.print(_infra_pins[counter]);
			SerialUSB.println(" Activated");
		}
	}
}

void infraevent0(){
	if (micros() - _last_infra_press[0] > _infra_debounce[0]){
		_infra_countup[0]++;
		_last_infra_press[0] = micros();
		echoInfra();
	}
}
void infraevent1(){
	if (micros() - _last_infra_press[1] > _infra_debounce[1]){
		_infra_countup[1]++;
		_last_infra_press[1] = micros();
		echoInfra();
	}
}
void infraevent2(){
	if (micros() - _last_infra_press[2] > _infra_debounce[2]){
		_infra_countup[2]++;
		_last_infra_press[2] = micros();
		echoInfra();
	}
}
void infraevent3(){
	if (micros() - _last_infra_press[3] > _infra_debounce[3]){
		_infra_countup[3]++;
		_last_infra_press[3] = micros();
		echoInfra();
	}
}

irModule::irModule(int pin){

	pin_number = pin;
	pinMode(pin_number, INPUT);
	thr = 1200;

	for (int counter = 0; counter < 10; counter++){
		if (_button_pins[counter] < 0){
			_button_pins[counter] = pin_number;
			orderNumber = counter;
			break;
		}
	}

	switch (orderNumber){
	case 0:
		attachInterrupt(pin_number, infraevent0, RISING);
		break;
	case 1:
		attachInterrupt(pin_number, infraevent1, RISING);
		break;
	case 2:
		attachInterrupt(pin_number, infraevent2, RISING);
		break;
	case 3:
		attachInterrupt(pin_number, infraevent3, RISING);
		break;
	}
	_infra_debounce[orderNumber] = 50 * 1000;
	_infra_countup[orderNumber] = 0;
	_infra_echo[orderNumber] = 1;
}

void irModule::setThreshold(int threshold){
	thr = threshold;
}


int irModule::readAnalog(void){
	pinMode(pin_number, INPUT_ANALOG);
	int analogValue = analogRead(pin_number);
	pinMode(pin_number, INPUT);
	return analogValue;
}

void irModule::check(void){
	SerialUSB.print("Infrared sensor at pin ");
	SerialUSB.print(pin_number);
	SerialUSB.print(" is reading : ");
	SerialUSB.println(irModule::readAnalog());
	SerialUSB.print("digital threshold is set to ");
	SerialUSB.println(thr);
	SerialUSB.print("Infrared sensor at pin ");
	SerialUSB.print(pin_number);
	SerialUSB.print(" has been activated ");
	SerialUSB.print(_infra_countup[orderNumber]);
	SerialUSB.println(" times");
	SerialUSB.print((micros() - _last_infra_press[orderNumber]) / 1000000);
	SerialUSB.println(" seconds have passed since last pressed");
}

float irModule::readTime(void){
	return (micros() - _last_infra_press[orderNumber]) / 1000000;
}

int irModule::howManyTimes(void){
	return _countup[orderNumber];
}

void irModule::timesReset(void){
	_countup[orderNumber] = 0;
}

int irModule::readDigital(void){
	return digitalRead(orderNumber);
}

int irModule::read(void){
	int irCount = irModule::howManyTimes();
	irModule::timesReset();
	return irCount;
}


void irModule::setDebounce(int time){
	_infra_debounce[orderNumber] = time * 1000;
}

void irModule::echoOn(void){
	_infra_echo[orderNumber] = 1;
}

void irModule::echoOff(void){
	_infra_echo[orderNumber] = 0;
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

int microphoneModule::readAnalog(void){
	pinMode(pin_number, INPUT_ANALOG);
	int analogValue = analogRead(pin_number);
	pinMode(pin_number, INPUT);
	return analogValue;
}

int microphoneModule::readDigital(void){
	return digitalRead(pin_number);
}

int microphoneModule::read(void){
	int micCount = microphoneModule::howManyTimes();
	microphoneModule::timesReset();
	return micCount;
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

