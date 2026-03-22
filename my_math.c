#include "my_math.h"
#include <stdlib.h>   /* llabs */

/*
 *  최대공약수 – 유클리드 호제법
 *  gcd(a, b) = gcd(b, a % b)
 */
long long my_gcd_ll(long long a, long long b)
{
    if (a < 0) a = llabs(a);
    if (b < 0) b = llabs(b);

    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;          /* b == 0 이면 a 가 GCD */
}

/*
 *  최소공배수 – |a * b| / gcd(a, b)
 *  오버플로 방지: (a / gcd) * b 순서로 계산
 */
long long my_lcm_ll(long long a, long long b, int* err)
{
    if (err) *err = MYMATH_OK;

    if (a == 0 || b == 0) return 0;

    long long g = my_gcd_ll(a, b);
    long long ax = llabs(a) / g;        /* 먼저 나눠서 크기를 줄임 */
    long long bx = llabs(b);

    /* 오버플로 검사: ax * bx > LLONG_MAX ? */
    if (ax != 0 && bx > LLONG_MAX / ax) {
        if (err) *err = MYMATH_ERR_OVERFLOW;
        return 0;
    }

    return ax * bx;
}
