#include "array.h"

typedef void* DATA_TYPE;
struct array {
    DATA_TYPE* data;
    size_t n;
    size_t cap;
};

struct array* array_new(int cap) {
    if(cap <= 0) {
        return NULL;
    }
    struct array* a = (struct array*)s_malloc(sizeof(struct array));
    a->n = 0;
    a->cap = cap;
    
    a->data = (DATA_TYPE*)s_malloc(sizeof(DATA_TYPE) * (a->cap));
    memset(a->data, 0, a->cap);
    return a;
}

void array_free(struct array* a) {
    s_free(a->data);
    s_free(a);
}

void array_push_back(struct array* self, void* data) {
    size_t cap = self->cap;
    if(self->n+1 > cap*3/4) {
        cap *= 2;
        
        self->data = (DATA_TYPE*)s_realloc(self->data, sizeof(DATA_TYPE) * cap);
        
        self->cap = cap;
    }
    self->data[self->n++] = data;
}

void array_set(struct array* self, size_t index, void* data) {
    s_assert(index < self->n);
    self->data[index] = data;
}

void* array_at(struct array* self, size_t index) {
    s_assert(index < self->n);
    return self->data[index];
}

void array_clear(struct array* self) {
    if (self->n == 0) {
        return;
    }
    self->n = 0;
    memset(self->data, 0, self->cap);
}

int array_empty(struct array* self) {
    return self->n == 0;
}

void array_debug_print(struct array* self) {
    printf("array: data address = %p, n = %ld, cap = %ld\n", self->data, self->n, self->cap);
    printf("array: data is:\n");
    for (int i = 0; i < self->n; ++i) {
        printf("%p ", self->data[i]);
    }
    printf("\n");
}