#ifndef HELPER_FUNCTIONS_H_
#define HELPER_FUNCTIONS_H_

static inline void minimal_delay() {
    __asm__(
            "nop\n\t"
           );
    return;
}

#endif
