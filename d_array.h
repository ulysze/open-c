#include <stdlib.h>
#include <string.h>

// Generic lightweight dynamic array

typedef unsigned char byte;

typedef struct
{
        void *data;
        size_t element_size;
        size_t capacity;
        size_t size;
} d_array;

d_array *create(size_t element_size, size_t initial_size);
void destroy(d_array *dptr);
int append(d_array *dptr, void *element);
int update(d_array *dptr, size_t index, void *new_value_ptr);
void *apply(d_array *dptr, size_t index);
byte *ptr_to_byte_at_index(d_array *dptr, size_t index);