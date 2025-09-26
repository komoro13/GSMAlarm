#include "helpers.h"

unsigned fast_atou(const char *s) {
    unsigned v = 0;
    while (*s) {
        v = v * 10u + (unsigned)(*s - '0');  // assumes '0'..'9' only
        s++;
    }
    return v;
}

size_t u8_to_dec(uint8_t v, char *buf, size_t cap) {
    if (!buf || cap < 2) return 0;
    // count digits
    unsigned x = v; size_t n = 1; while (x >= 10) { x/=10; n++; }
    if (n + 1 > cap) return 0;
    buf[n] = '\0';
    for (size_t i = n; i-- > 0;) { buf[i] = '0' + (v % 10); v /= 10; }
    return n;
}

size_t u8_concat(const unsigned char *s1,
                 const unsigned char *s2,
                 unsigned char *out,
                 size_t cap) {
    if (!out || cap == 0) return 0;

    // copy s1
    size_t n1 = strnlen((const char*)s1, cap - 1);
    memcpy(out, s1, n1);

    // copy s2 within remaining space
    size_t rem = cap - 1 - n1;
    size_t n2 = strnlen((const char*)s2, rem);
    memcpy(out + n1, s2, n2);

    out[n1 + n2] = 0; // null-terminate
    return n1 + n2;   // bytes written (not counting terminator)
}