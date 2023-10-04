
#include "base.h"

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif // __EMSCRIPTEN__

#include <stdlib.h>

void b_force_exit(int code) {
#ifdef __EMSCRIPTEN__
    emscripten_force_exit(code);
#else
    exit(code);
#endif
}

