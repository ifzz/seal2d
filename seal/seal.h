#ifndef __seal__seal__
#define __seal__seal__
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "lopen.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#ifndef luaL_newlib /* using LuaJIT */
/*
 ** set functions from list 'l' into table at top - 'nup'; each
 ** function gets the 'nup' elements at the top as upvalues.
 ** Returns with only the table at the stack.
 */
LUALIB_API void luaL_setfuncs (lua_State *L, const luaL_Reg *l, int nup);

#define luaL_newlibtable(L,l) \
lua_createtable(L, 0, sizeof(l)/sizeof((l)[0]) - 1)

#define luaL_newlib(L,l)  (luaL_newlibtable(L,l), luaL_setfuncs(L,l,0))
#endif

struct game {
    lua_State* lstate;
    SDL_Window* window;
    SDL_Renderer* gl_render;
    
    Uint32 window_width;
    Uint32 window_height;
};

#define GAME_TRACE  "GAME_TRACE"
#define GAME_UPDATE "GAME_UPDATE"
#define GAME_DRAW   "GAME_DRAW"
#define GAME_PAUSE  "GAME_PAUSE"
#define GAME_RESUME "GAME_RESUME"
#define GAME_EVENT  "GAME_EVENT"

// seal system
void seal_init();
void seal_load_string(const char* script_data);
void seal_load_file(const char* script_path);
void seal_start_game();
void seal_set_window(SDL_Window* window);
void seal_event(const SDL_Event* event);
void seal_update(float dt);
void seal_draw();
void seal_destroy();

SDL_Window* seal_get_window();
SDL_Renderer* seal_get_render();

#endif