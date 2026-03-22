#include <stdio.h>
#include <string.h>
#include "my_math.h"

int main(void)
{
    char line[256];
    long long a, b;

    /* 입력: "a b" 형태 권장 */
    if (!fgets(line, sizeof(line), stdin)) {
        return 0;
    }

    /* 공백/개행 포함 입력을 안정적으로 처리 */
    if (sscanf(line, "%lld %lld", &a, &b) != 2) {
        printf("Invalid input format. Please enter two integers.\n");
        return 0;
    }

    long long g = my_gcd_ll(a, b);

    int err = MYMATH_OK;
    long long l = my_lcm_ll(a, b, &err);

    printf("GCD = %lld\n", g);

    if (err == MYMATH_ERR_OVERFLOW) {
        printf("LCM = overflow\n");
    } else {
        printf("LCM = %lld\n", l);
    }

    return 0;
}
