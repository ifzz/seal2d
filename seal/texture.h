#ifndef __seal__texture__
#define __seal__texture__

#include "seal.h"

struct texture {
    GLuint id;
    unsigned int width, height;
} texture;


struct texture* load_from_png(const char* file_path);

#endif
