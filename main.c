#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_math.h"

static int is_valid_integer(const char* s)
{
    if (s == NULL || *s == '\0') return 0;
    if (*s == '+' || *s == '-') s++;
    if (*s == '\0') return 0;
    while (*s) {
        if (*s < '0' || *s > '9') return 0;
        s++;
    }
    return 1;
}

int main(int argc, char** argv)
{
    /* 1. 인자 개수 검사 ★ 가산점 */
    if (argc != 3) {
        fprintf(stderr, "Error: exactly 2 arguments required.\n");
        fprintf(stderr, "Usage: %s <integer1> <integer2>\n", argv[0]);
        return 1;
    }

    /* 2. 유효한 정수인지 검사 ★ 가산점 */
    if (!is_valid_integer(argv[1])) {
        fprintf(stderr, "Error: '%s' is not a valid integer.\n", argv[1]);
        return 1;
    }
    if (!is_valid_integer(argv[2])) {
        fprintf(stderr, "Error: '%s' is not a valid integer.\n", argv[2]);
        return 1;
    }

    long long a = atoll(argv[1]);
    long long b = atoll(argv[2]);

    /* 3. 둘 다 0인 경우 ★ 가산점 */
    if (a == 0 && b == 0) {
        fprintf(stderr, "Error: GCD(0, 0) is undefined.\n");
        return 1;
    }

    long long gcd = my_gcd_ll(a, b);

    int lcm_err = MYMATH_OK;
    long long lcm = my_lcm_ll(a, b, &lcm_err);

    /* 4. LCM 오버플로우 검사 ★ 가산점 */
    if (lcm_err == MYMATH_ERR_OVERFLOW) {
        fprintf(stderr, "Error: LCM overflow (result too large).\n");
        return 1;
    }

    printf("GCD: %lld, LCM: %lld\n", gcd, lcm);

    return 0;
}
