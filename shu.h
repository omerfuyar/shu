/*
 .--..--..--..--..--..--..--..--..--..--..--..--..--.
/ .. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \
\ \/\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ \/ /
 \/ /`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'\/ /
 / /\    █████████  █████   █████ █████  █████   / /\
/ /\ \  ███░░░░░███░░███   ░░███ ░░███  ░░███   / /\ \
\ \/ / ░███    ░░░  ░███    ░███  ░███   ░███   \ \/ /
 \/ /  ░░█████████  ░███████████  ░███   ░███    \/ /
 / /\   ░░░░░░░░███ ░███░░░░░███  ░███   ░███    / /\
/ /\ \  ███    ░███ ░███    ░███  ░███   ░███   / /\ \
\ \/ / ░░█████████  █████   █████ ░░████████    \ \/ /
 \/ /   ░░░░░░░░░  ░░░░░   ░░░░░   ░░░░░░░░      \/ /
 / /\.--..--..--..--..--..--..--..--..--..--..--./ /\
/ /\ \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \/\ \
\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `' /
 `--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'

SHU is a series of (somewhat) single header C libraries.
It includes essential type definitions and macros which
all of the shu... library will use.

It does not requires any implementation like libraries do.
So you can just include it without any other operation.

So every library header will try to include this file as
"shu.h". You can define the macro 'SHU' as ".../shu.h" to
tell where to find it. Or include it directly.

In my opinion this file should be used by your own projects
too to have easy to use standards.

The recommendation is to create a shu.c file and define
'SHU_IMPLEMENTATION' at start, then include this file and
include all the libraries you need. So in one file all the
implementation is finished in one unit.

See [Code-Juliett](https://github.com/omerfuyar/Code-Juliett)
for more practical use of the system.
*/

#ifndef SHU_HEADER
#define SHU_HEADER

#define _CRT_SECURE_NO_WARNINGS

#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 700
#endif
#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <float.h>

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

#ifdef __SIZEOF_INT128__
typedef __int128_t i128;
#endif

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

#ifdef __SIZEOF_INT128__
typedef __uint128_t u128;
#endif

#ifdef __FLT16_MAX__
typedef _Float16 f16;
#endif

typedef float f32;
typedef double f64;

#ifdef __SIZEOF_FLOAT128__
typedef __float128 f128;
#endif

typedef size_t usz;

typedef enum SHUResult
{
    SHUResult_Ok = 0,
    SHUResult_Pending,
    SHUResult_ErrBadStructData,
    SHUResult_ErrNullPointer,
    SHUResult_ErrNetwork,
    SHUResult_ErrPrivileges,
} SHUResult;

typedef struct SHUSlice
{
    u8 *data;
    usz size;
} SHUSlice;

typedef const struct SHUSliceView
{
    const u8 *const data;
    const usz size;
} SHUSliceView;

#define cs(data, size) \
    (SHUSlice) { .data = data, .size = size }
#define csv(slice) \
    (SHUSliceView) { .data = slice.data, .size = slice.size }

#endif // SHU_HEADER