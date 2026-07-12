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

Configurations:
#define SHU_IMPLEMENTATION : to implement shu... libraries
#define SHU_LOG_STREAM <stream> : changes where to log for SHU_Log and its derivatives
#define SHU_NO_LOG : disables logging for SHU_Log and its derivatives
*/

#ifndef SHU_HEADER
#define SHU_HEADER

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 700
#endif

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#ifndef SHU_LOG_STREAM
#define SHU_LOG_STREAM stderr
#endif

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

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
    SHUResult_Err,
    SHUResult_ErrAssertion,
    SHUResult_ErrNotFound,
    SHUResult_ErrBadData,
    SHUResult_ErrFile,
    SHUResult_ErrInternal,
    SHUResult_ErrAllocation,
    SHUResult_ErrIndexOutOfBounds,
    SHUResult_ErrNullPointer,
    SHUResult_ErrNetwork,
    SHUResult_ErrPrivileges,
} SHUResult;

/// @brief An attribute to warn an unused return value used as 'SHUWUR SHUResult foo(...)'
#define SHUWUR __attribute__((warn_unused_result))

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

/// @brief Create a slice from its contents.
/// @param data Data which this slice owns.
/// @param size Size of the data of this slice.
#define cs(sliceData, sliceSize) \
    (SHUSlice) { .data = sliceData, .size = sliceSize }

/// @brief Create a slice view from a slice.
/// @param slice Slice to create a view of.
#define csv(slice) \
    (SHUSliceView) { .data = slice.data, .size = slice.size }

#define cs0 cs(NULL, 0)

#ifndef SHU_NO_LOG
/// @brief Log macro for all of the shu... libraries.
/// @param terminate Terminates the application if the code is other than 0.
/// @param header Header to enter to log as to stream.
/// @param format Formatted message to log.
/// @param ... Format parameters.
#define SHU_Log(terminate, header, format, ...)                                 \
    do                                                                          \
    {                                                                           \
        fprintf(SHU_LOG_STREAM, "%s:%d:%s : \x1b[1m[%s]\x1b[0m : " format "\n", \
                __FILE__, __LINE__, __func__, header, ##__VA_ARGS__);           \
                                                                                \
        if (terminate)                                                          \
        {                                                                       \
            exit(terminate);                                                    \
        }                                                                       \
    } while (0)
#endif

#define SHU_LogInfo(format, ...) SHU_Log(0, "\x1b[32mINFO\x1b[0m", format, ##__VA_ARGS__)

#define SHU_LogWarning(format, ...) SHU_Log(0, "\x1b[33mWARNING\x1b[0m", format, ##__VA_ARGS__)

#define SHU_LogError(code, format, ...) SHU_Log((code), "\x1b[31mERROR\x1b[0m", format, ##__VA_ARGS__)

#define SHU_Assert(condition, format, ...)                                                  \
    if (!(condition))                                                                       \
    {                                                                                       \
        SHU_Log(SHUResult_ErrAssertion, "\x1b[35mASSERTION\x1b[0m", format, ##__VA_ARGS__); \
    }

#define SHU_CheckPanic(result) SHU_Assert(!(result), "Result of " #result " (%d) is not SHUResult_Ok", (result))

#define SHU_CheckPanicNullPointer(ptr) SHU_Assert(ptr != NULL, "Pointer variable " #ptr " is NULL")

#define SHU_CheckReturn(result, ...)  \
    do                                \
    {                                 \
        SHUResult ___shures = result; \
        if (___shures)                \
        {                             \
            __VA_ARGS__               \
            return ___shures;         \
        }                             \
    } while (0)

#endif // SHU_HEADER