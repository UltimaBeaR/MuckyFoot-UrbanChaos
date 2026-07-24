#ifndef ENGINE_CORE_RNG_H
#define ENGINE_CORE_RNG_H

#include "engine/core/types.h"

// Portable reimplementation of the Microsoft C runtime's rand()/srand().
//
// The C standard does not define rand()'s algorithm, so each platform/compiler
// ships a different one. Urban Chaos seeds the generator with a fixed constant
// (srand(1234567)) expecting a deterministic sequence — but that sequence only
// matches the original game and our Windows build, where the MS runtime is used.
// glibc / Apple libc use different algorithms, so the same seed yields a
// different sequence and thus divergent behavior across platforms (and, before
// index masking was added, out-of-range trig-table reads from unbounded values).
//
// uc_rand()/uc_srand() replicate the MS linear congruential generator exactly:
//   seed = seed * 214013 + 2531011;  result = (seed >> 16) & 0x7fff;
// so every platform reproduces the Windows reference sequence bit-for-bit. On
// Windows this is identical to the libc rand() it replaces, so behavior on the
// reference platform is unchanged.
//
// Not thread-safe (single global seed) — this matches libc rand()'s own contract.

// Inclusive upper bound of uc_rand()'s result. Matches MS RAND_MAX.
#define UC_RAND_MAX 0x7fff

// Seeds the generator. Drop-in replacement for srand().
void uc_srand(ULONG seed);

// Returns a pseudo-random value in [0, UC_RAND_MAX]. Drop-in replacement for rand().
SLONG uc_rand(void);

#endif // ENGINE_CORE_RNG_H
