#ifndef GAWD_VECTOR_H
#define GAWD_VECTOR_H

#include "internal/vector_base.h"

#define GAWD_VECTOR_DEFINE(type, name)                     \
                                                           \
  typedef struct                                           \
  {                                                        \
    gawd_vec_base_t base;                                  \
  } name;                                                  \
                                                           \
  static inline int name##_init(name* v)                   \
  {                                                        \
    gawd_container_cfg_t cfg = {.elem_size = sizeof(type), \
                                .copy = NULL,              \
                                .destroy = NULL,           \
                                .move = NULL,              \
                                .allocator = NULL};        \
    return gawd_vec_base_init(&v->base, cfg);              \
  }                                                        \
                                                           \
  static inline int name##_push_back(name* v, type value)  \
  {                                                        \
    return gawd_vec_base_push_back(&v->base, &value);      \
  }                                                        \
                                                           \
  static inline type* name##_get(name* v, size_t i)        \
  {                                                        \
    return (type*) gawd_vec_base_get(&v->base, i);         \
  }                                                        \
                                                           \
  static inline type* name##_front(name* v)                \
  {                                                        \
    return (type*) gawd_vec_base_front(&v->base);          \
  }                                                        \
                                                           \
  static inline type* name##_back(name* v)                 \
  {                                                        \
    return (type*) gawd_vec_base_back(&v->base);           \
  }

#endif  // GAWD_VECTOR_H
