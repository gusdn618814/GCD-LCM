#include "my_math.h"
#include <stdlib.h>   /* llabs */

/* GCD: Euclidean Algorithm */
long long my_gcd_ll(long long a, long long b)
{
    a = llabs(a);
    b = llabs(b);

    if (a == 0 && b == 0) return 0;

    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

/* LCM with overflow check (MSVC 호환: __int128 미사용) */
long long my_lcm_ll(long long a, long long b, int *err)
{
    if (err) *err = MYMATH_OK;

    if (a == 0 || b == 0) return 0;

    long long g = my_gcd_ll(a, b);

    /* (a/g) * b 형태로 overflow 위험을 줄임 */
    long long x = a / g;

    /* overflow check: |x * b| <= LLONG_MAX */
    long long ax = llabs(x);
    long long ab = llabs(b);

    if (ax != 0 && ab > LLONG_MAX / ax) {
        if (err) *err = MYMATH_ERR_OVERFLOW;
        return 0;
    }

    long long l = x * b;
    return llabs(l);
}
