#ifndef GAWD_TYPES_H
#define GAWD_TYPES_H

#include <stddef.h>

typedef struct
{
  void* (*alloc)(size_t size);
  void* (*reallloc)(void* ptr, size_t size);
  void (*free)(void* ptr);
} gawd_allocator_t;

typedef void (*gawd_elem_copy_fn)(void* dst, const void* src);
typedef void (*gawd_elem_destroy_fn)(void* elem);
typedef void (*gawd_elem_move_fn)(void* dst, void* src);

typedef struct
{
  size_t elem_size;
  gawd_elem_copy_fn copy;
  gawd_elem_destroy_fn destroy;
  gawd_elem_move_fn move;
  gawd_allocator_t* allocator;  // NULL -> default allocator, i.e. glibc malloc()
} gawd_container_cfg_t;

#endif  // GAWD_TYPES_H
