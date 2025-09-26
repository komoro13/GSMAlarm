/* 
 * File:   helpers.h
 * Author: komoro
 *
 * Created on September 26, 2025, 4:53 PM
 */
#include <stddef.h>
#include <stdint.h>

#ifndef NEWFILE_H
#define	NEWFILE_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* NEWFILE_H */

unsigned fast_atou(const char *s);
size_t u8_concat(const unsigned char *s1,
                 const unsigned char *s2,
                 unsigned char *out,
                 size_t cap);
size_t u8_to_dec(uint8_t v, char *buf, size_t cap);