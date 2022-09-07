/* 
 * File:   I_O.h
 * Author: Mayar
 *
 * Created on August 21, 2022, 5:07 PM
 */

#ifndef I_O_H
#define	I_O_H

#ifdef	__cplusplus
extern "C" {
#endif
void init_Relay();
void set_Relay(int state);
void init_Buzzer();
void set_Buzzer(int state);

void init_Leds();
void set_Led(int LedNumber, int state);

void init_Buttons();

int isPress_B(int pinNum);
int isPressed(int portNum, int pinNum);

// PORT Level
void setPortDir(int portNum, int state);
void setPortData(int portNum, int data);
void togglePortData(int portNum);
// Pin Level

void setPinDir(int portNum, int pinNum,int state);
void setPinData(int portNum, int pinNum, int data);
void togglePinData(int portNum, int pinNum);



#ifdef	__cplusplus
}
#endif

#endif	/* I_O_H */

