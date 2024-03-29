#include "lauxlib.h"

extern int luaopen_seal_core(lua_State* L);
extern int luaopen_affine_core(lua_State* L);

void stackDump (lua_State *L) {
    int i;
    int top = lua_gettop(L);
    for (i = 1; i <= top; i++) {  /* repeat for each level */
        int t = lua_type(L, i);
        switch (t) {
                
            case LUA_TSTRING:  /* strings */
                printf("`%s'", lua_tostring(L, i));
                break;
                
            case LUA_TBOOLEAN:  /* booleans */
                printf(lua_toboolean(L, i) ? "true" : "false");
                break;
                
            case LUA_TNUMBER:  /* numbers */
                printf("%g", lua_tonumber(L, i));
                break;
                
            default:  /* other values */
                printf("%s", lua_typename(L, t));
                break;
                
        }
        printf("    ");  /* put a separator */
    }
    printf("\n");  /* end the listing */
}

void setfiled_f(lua_State *L, const char* key, float f) {
    lua_pushstring(L, key);
    lua_pushnumber(L, f);
    lua_settable(L, -3);
}

void setfiled_i(lua_State* L, const char* key, lua_Integer n) {
    lua_pushstring(L, key);
    lua_pushinteger(L, n);
    lua_settable(L, -3);
}

void setfiled_s(lua_State *L, const char* key, const char* s) {
    lua_pushstring(L, key);
    lua_pushstring(L, s);
    lua_settable(L, -3);
}

void luaopen_lua_extensions(lua_State *L)
{
    // load extensions
    luaL_Reg lua_modules[] = {
        {"seal.core", luaopen_seal_core},
        {"seal.affine", luaopen_affine_core},
        {NULL, NULL}
    };
    
    luaL_Reg* lib = lua_modules;
    lua_getglobal(L, "package");
    lua_getfield(L, -1, "preload");
    for (; lib->func; lib++)
    {
        lua_pushcfunction(L, lib->func);
        lua_setfield(L, -2, lib->name);
    }
    lua_pop(L, 2);
}