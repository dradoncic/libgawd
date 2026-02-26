#ifndef GAWD_VECTOR_BASE_H
#define GAWD_VECTOR_BASE_H

#include "../types.h"

typedef struct
{
  void* data;
  size_t size;
  size_t capacity;
  gawd_container_cfg_t cfg;
} gawd_vec_base_t;

int gawd_vec_base_init(gawd_vec_base_t* v, gawd_container_cfg_t cfg);
void gawd_vec_base_destroy(gawd_vec_base_t* v);
void* gawd_vec_base_clear(gawd_vec_base_t* v);

int* gawd_vec_base_reserve(gawd_vec_base_t* v, size_t new_capacity);
size_t* gawd_vec_base_capacity(const gawd_vec_base_t* v);
size_t* gawd_vec_base_size(const gawd_vec_base_t* v);
int* gawd_vec_base_empty(const gawd_vec_base_t* v);

void* gawd_vec_base_get(gawd_vec_base_t* v, size_t index);
void* gawd_vec_base_at(gawd_vec_base_t* v, size_t index);
void* gawd_vec_base_front(gawd_vec_base_t* v);
void* gawd_vec_base_back(gawd_vec_base_t* v);

int gawd_vec_base_push_back(gawd_vec_base_t* v, const void* elem);
int gawd_vec_base_emplace_back(gawd_vec_base_t* v, const void* elem);
void gawd_vec_base_pop_back(gawd_vec_base_t* v);
void gawd_vec_base_insert(gawd_vec_base_t* v, size_t index, const void* elem);
void gawd_vec_base_erase(gawd_vec_base_t* v, size_t index);

void gawd_vec_base_copy(gawd_vec_base_t* dest, const gawd_vec_base_t* src);
void gawd_vec_base_move(gawd_vec_base_t* dest, gawd_vec_base_t* src);

#endif  // GAWD_VECTOR_BASE_H
