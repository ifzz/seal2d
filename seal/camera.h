#ifndef __yuusha__camera__
#define __yuusha__camera__

#include "seal.h"

enum CAMERA_DIRTY_FLAG {
    TRANSLATE_DIRTY = 1,
    SCALE_DIRTY = 2,
};
struct camera {
    float x, y;
    float scale_x, scale_y;
    float width, height;
    float scale;
    struct mat4* camer_mat;
    int dirty;
};

struct camera* camera_new(float width, float height);
void camera_free(struct camera* c);

void camera_pos(struct camera* self, float x, float y);
void camera_scale(struct camera* self, float sx, float sy);
void camera_update(struct camera* self);
#endif /* defined(__yuusha__camera__) */
