/* 
 * File:   firmware.h
 * Author: tbogi
 *
 * Created on 2 ????????? 2024, 10:45 ??
 */

#ifndef FIRMWARE_H
#define	FIRMWARE_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* FIRMWARE_H */
void main_menu();
void boot();
void BlinkLED(int mode, int sensor);
void sensor_leds_off();
void boot_led_blink();
void MakeCall();
void start();
void sleep();
int save_phone(char *phone);
char *read_saved_phone();
void settings();