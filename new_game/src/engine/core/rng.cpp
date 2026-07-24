#include "engine/core/rng.h"

// Microsoft C runtime LCG constants (documented msvcrt/ucrt rand()).
static const ULONG UC_RAND_MULTIPLIER = 214013;
static const ULONG UC_RAND_INCREMENT = 2531011;
// MS rand() returns the state's bits [30..16]; shift down then mask to UC_RAND_MAX.
static const SLONG UC_RAND_RESULT_SHIFT = 16;

// Generator state. Fixed 32-bit width (ULONG) so the multiply wraps identically
// on every platform. Default seed 1 mirrors the C standard's pre-srand() default.
static ULONG uc_rand_seed = 1;

void uc_srand(ULONG seed)
{
    uc_rand_seed = seed;
}

SLONG uc_rand(void)
{
    uc_rand_seed = (uc_rand_seed * UC_RAND_MULTIPLIER) + UC_RAND_INCREMENT;
    return (SLONG)((uc_rand_seed >> UC_RAND_RESULT_SHIFT) & UC_RAND_MAX);
}
