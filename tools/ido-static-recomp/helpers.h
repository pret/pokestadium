#ifndef HELPERS_H
#define HELPERS_H

#include <stdint.h>

#define MEM_F64(a) (double_from_memory(mem, a))
#define MEM_F32(a) (*(float *)(mem + a))
#define MEM_U32(a) (*(uint32_t *)(mem + a))
#define MEM_S32(a) (*(int32_t *)(mem + a))
#define MEM_U16(a) (*(uint16_t *)(mem + ((a) ^ 2)))
#define MEM_S16(a) (*(int16_t *)(mem + ((a) ^ 2)))
#define MEM_U8(a) (*(uint8_t *)(mem + ((a) ^ 3)))
#define MEM_S8(a) (*(int8_t *)(mem + ((a) ^ 3)))

#if !defined(__GNUC__) && !defined(__clang__)
#define __attribute__(x)
#endif

#if __STDC_VERSION__ >= 202000L
#define FALLTHROUGH [[fallthrough]]
#define NODISCARD [[nodiscard]]
#define NORETURN [[noreturn]]
#define UNUSED [[maybe_unused]]
#else
#define FALLTHROUGH __attribute__((fallthrough))
#define NODISCARD __attribute__((warn_unused_result))
#define NORETURN _Noreturn
#define UNUSED __attribute__((unused))
#endif

#if defined(_MSC_VER)
#  define UNREACHABLE __assume(0)
#elif defined(__GNUC__) || defined(__clang__)
#  define UNREACHABLE __builtin_unreachable()
#else
#  define UNREACHABLE
#endif

#endif
