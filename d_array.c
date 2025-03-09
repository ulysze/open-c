#include "d_array.h"

d_array* create(size_t element_size, size_t initial_size) {
        d_array* sptr = malloc(sizeof(d_array));
        if (sptr == NULL) return NULL;
        void* data = malloc(initial_size * element_size);
        if (data == NULL) {
                free(sptr);
                return NULL;
        }
        sptr->data = data; sptr->element_size = element_size; sptr->size = initial_size; sptr->capacity = initial_size;

        return sptr;
}

void destroy(d_array* dptr) {
        free(dptr->data);
        free(dptr);
}

int append(d_array* dptr, void* element) {
        if (dptr->size == dptr->capacity) {
                byte* new_data_ptr = malloc(2 * dptr->element_size * dptr->capacity);
                if (new_data_ptr == NULL) return -1;
                byte* temp_data_ptr = dptr->data;
                for (size_t i = 0; i < dptr->size * dptr->element_size; ++i) {
                        *(new_data_ptr + i) = *(temp_data_ptr + i);
                }
                free(dptr->data);
                dptr->data = (void*) new_data_ptr;
                dptr->capacity *= 2;
        }

        // arithmetic on bytes.. -> As every element in adresses occupies bytes. (minimal memory unit) in copmputer systems
        byte* initial_pos = dptr->data;
        byte* end_pos_sup = initial_pos + (dptr->element_size * dptr->size);
        byte* element_bytes = element;
        
        for(size_t i = 0; i < dptr->element_size; ++i){
                end_pos_sup[i] = element_bytes[i];
        }
        ++dptr->size;
        return 0;
}

int update(d_array* dptr, size_t index, void* new_value_ptr) {
        if (index >= dptr->size) return -1; 
        memcpy(ptr_to_byte_at_index(dptr,index), new_value_ptr, dptr->element_size); return 0;
}

void* apply(d_array* dptr, size_t index) {
        if (index >= dptr->size) return NULL; return (void*) ptr_to_byte_at_index(dptr, index);
}

byte* ptr_to_byte_at_index(d_array* dptr, size_t index) {
        if (dptr == NULL) return NULL; 
        byte* initial_b_ptr = dptr->data; return initial_b_ptr + (index * dptr->element_size);
}

int main(void) {
        d_array* darray = create(sizeof(double), 10);
        


}


