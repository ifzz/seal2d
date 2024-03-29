#ifndef __seal__sprite__
#define __seal__sprite__

#include "seal.h"
#include "texture.h"

typedef struct sprite {
    float x, y;
    float width, height;
    
    GLuint vbo;
    GLuint color_vbo;
    GLuint vao;
    GLuint tex_id;
    
    vertex vert[6];
    struct texture* texture;
    
    float speed_x, speed_y;
}sprite;

sprite* sprite_alloc(float x, float y, float width, float height);
void sprite_free(sprite* spr);

void sprite_set_texture(sprite* spr, const char* file_name);

void sprite_set_pos(sprite* spr, float x, float y);
void sprite_set_size(sprite* spr, float width, float height);

void sprite_update(sprite* spr, float dt);
void sprite_draw(sprite* spr);

#endif
