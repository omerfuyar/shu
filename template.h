/*
    This file is a template for creating shu... libraries.

    shu.h defines SHU_HEADER macro, so if the header is already included by the user
    it skips the including part.

    User can define SHU to specify where shu.h is. This can be useful when quick compiling from CLI.
    Though it may cause problems when compiling multiple shu... libraries.

    Otherwise library will search shu.h in the submodule next to this directory in.
*/

#pragma once

#ifndef SHU_HEADER
#ifdef SHU
#include SHU
#else
#include "../shu/shu.h"
#endif
#endif

#pragma region Macros

#pragma endregion Macros

#pragma region Declarations

#pragma endregion Declarations

#pragma region Definitions

#ifdef SHU_IMPLEMENTATION

#ifdef _WIN32
#else
#endif

#pragma region Internals

#pragma endregion Internals

#endif

#pragma endregion Definitions
