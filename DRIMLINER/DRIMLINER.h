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

#ifndef _DRIMLINER_H_
#define _DRIMLINER_H_

#include "wirish.h"
#include "dynamixel.h"

#define ON 1
#define OFF 0

class cdsModule {
public:
	cdsModule(int pin, int range);
	cdsModule(int pin);
	int read(void);
	int read(int range);
	int check(void);
private:
	int pin_number;
	int range_number;
};

class temperatureModule {
public:
	temperatureModule(int pin);
	float read(void);
	float check(void);
private:
	int pin_number;
};

class hallModule {
public:
	hallModule(int pin);
	int read(void);
	int check(void);
private:
	int pin_number;
};

class buttonModule {
public:
	buttonModule(int pin);
	float readTime(void);
	int howManyTimes(void);
	void timesReset(void);
	int readDigital(void);
	int read(void);
	int check(void);
	void setDebounce(int time);
	void echoOn(void);
	void echoOff(void);
private:
	int pin_number;
	int order_number;
};

class ledModule {
public:
	ledModule(int pin);
	void on(void);
	void off(void);
	void blink(float interval, int amount);
private:
	int pin_number;
	int order_number;
};

class axMotor {
public:
	axMotor(int id);
	void begin(int baud);
	void resetSettings(void);
	int readModelNumber(void);
	int readFirmwareVersion(void);
	void setID(int newID);
	void setBaud(int newBaud);
	void setReturnDelay(int newDelay);
	void setCWLimit(int newLimit);
	void setCCWLimit(int newLimit);
	void setTempLimit(int newTemp);
	void setLowVoltage(int newVolt);
	void setHighVoltage(int newVolt);
	void setStatusReturn(int newStat);
	void setWheelMode(void);
	void setJointMode(void);
    void jointMove(int position);
    void jointMove(int position, int speed);
	void setPosition(int newPosition);
	void setSpeed(int newSpeed);
	void ledOn(void);
	void ledOff(void);
	void setTorqueLimit(int newLimit);
	int readPosition(void);
	int readSpeed(void);
	int readLoad(void);
	int readVoltage(void);
	int readTemperature(void);
	int isItWorking(void);
	int isItMoving(void);
	void lock(void);
	void unlock(void);
	void setPunch(int newPunch);
	int isError(void);

private:
	int myID;
};

class xlMotor {
public:
	xlMotor(int id);
	void begin(int baud);
	void resetSettings(void);
	int readModelNumber(void);
	int readFirmwareVersion(void);
	void setID(int newID);
	void setBaud(int newBaud);
	void setReturnDelay(int newDelay);
	void setCWLimit(int newLimit);
	void setCCWLimit(int newLimit);
	void setTempLimit(int newTemp);
	void setLowVoltage(int newVolt);
	void setHighVoltage(int newVolt);
	void setStatusReturn(int newStat);
    void jointMove(int position);
    void jointMove(int position, int speed);
    void wheelMove(char direction);
    void wheelMove(char direction, int speed);
	void setPosition(int newPosition);
	void setSpeed(int newSpeed);
	void ledOn(void);
	void ledOff(void);
	void setTorqueLimit(int newLimit);
	int readPosition(void);
	int readSpeed(void);
	int readLoad(void);
	int readVoltage(void);
	int readTemperature(void);
	int isItWorking(void);
	int isItMoving(void);
	void lock(void);
	void unlock(void);
	void setPunch(int newPunch);
	int isError(void);
    
private:
	int myID;
};

class buzzerModule{
public:
	buzzerModule(void);
	void on(void);
	void off(void);
private:

};


class irModule {
public:
	irModule(int pin);
	void setThreshold(int threshold);
	int read(void);
	float readTime(void);
	int howManyTimes(void);
	void timesReset(void);
	int readDigital(void);
	int readAnalog(void);
	void check(void);
	void setDebounce(int time);
	void echoOn(void);
	void echoOff(void);

private:
	int pin_number;
	int thr;
	int orderNumber;
};

class microphoneModule{
public:
	microphoneModule(int pin);
	int timeSincePressed(void);
	int howManyTimes(void);
	void timesReset(void);
	int readDigital(void);
	int readAnalog(void);
	int read(void);
	int check(void);
	void setDelay(int time);
	void echoOn(void);
	void echoOff(void);
private:
	int pin_number;

};

#endif