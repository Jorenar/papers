#include <stdio.h>

#include <stdint.h>

#if __STDC_VERSION__ < 202300
# define typeof __typeof
#endif

#define INT(N,T) typeof(_Generic(char[N],  \
        char[8]:  (int ## T ## 8_t){},     \
        char[16]: (int ## T ## 16_t){},    \
        char[32]: (int ## T ## 32_t){},    \
        char[64]: (int ## T ## 64_t){},    \
        default:  (int ## T ## N ## _t){}))

#define intN(N) INT(N,)
#define intF(N) INT(N,fast)
#define intL(N) INT(N,least)
#define intB(N) _BitInt(N)

int main()
{
    intN(32) x = 12;
    printf("%d\n", x);
    return 0;
}
