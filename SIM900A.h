/* 
 * File:   SIM900A.h
 * Author: tbogi
 *
 * Created on 2 ????????? 2024, 10:09 ??
 */

#ifndef SIM900A_H
#define	SIM900A_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* SIM900A_H */

void initialize_SIM900A(void);
void _SIM900A_putch(char bt);
char _SIM900A_getch();
void SIM900A_send_string(char* st_pt);
void _SIM900A_print(unsigned const char *ptr);