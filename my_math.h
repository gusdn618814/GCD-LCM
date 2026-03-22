#ifndef MY_MATH_H
#define MY_MATH_H

/* 
 * my_math.h
 * - GCD / LCM utilities
 */

#include <limits.h>

/* 에러 코드(필요 없으면 사용 안 해도 됨) */
#define MYMATH_OK 0
#define MYMATH_ERR_OVERFLOW 1

/* 최대공약수 */
long long my_gcd_ll(long long a, long long b);

/*
 * 최소공배수
 * - overflow 가능성이 있으므로 err 포인터로 상태를 알려줌 (NULL 허용)
 * - 성공: err = MYMATH_OK
 * - overflow: err = MYMATH_ERR_OVERFLOW, 반환값은 0
 */
long long my_lcm_ll(long long a, long long b, int *err);

#endif
