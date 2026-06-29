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

SHU is a series of single header C libraries. It includes
essential type definitions and macros which all of the
shu... library will use.

It does not requires any implementation like libraries do.
So you can just include it without any other operation.

So every library header will try to include this file as
"shu.h". You can define the macro 'SHU' as ".../shu.h" to
tell where to find it.

In my opinion this file should be used by your own projects
too to have easy to use standards.

See [Code-Juliett](https://github.com/omerfuyar/Code-Juliett)
for more practical use of the system.
*/

#pragma once
#include <stdint.h>

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

typedef u64 usz;

typedef struct SHUSlice
{
    void *data;
    usz size;
} SHUSlice;

typedef const struct SHUSliceView
{
    const void *const data;
    const usz size;
} SHUSliceView;