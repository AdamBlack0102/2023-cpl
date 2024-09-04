#include <stdio.h>

int StrCmp(const char *s1, const char *s2);
int StrCmpStd(const char *s1, const char *s2);

int main() {
    const char *str1 = "hi, C";
    const char *str2 = "hi, c";

    // printf("StrCmp(\"%s\", \"%s\") = %d\n",
    //        str1, str2, StrCmp(str1, str2));
    // printf("StrCmpStd(\"%s\", \"%s\") = %d\n",
    //        str1, str2, StrCmpStd(str1, str2));
    //
    // int n = 2;
    // printf("StrNCmp(\"%s\", \"%s\", %d) = %d\n",
    //        str1, str2, n, StrNCmp(str1, str2, n));

    return 0;
}

//如果两个字符串一样，返回0；如果第一个大，返回一个正数；如果第一个小，返回一个负数;
int StrCmp(const char *s1, const char *s2) {
    while(*s1 == *s2 && (*s1 != '\0' && *s2 != '\0')) {
        s1++;
        s2++;
    }

    if(*s1 == '\0' && *s2 == '\0') {
        return 0;
    }

    return (*(const unsigned char *) s1)
    < *(const unsigned char *)s2 ? -1 : 1;
    //不能return *s1 - *s2, 因为char是无符号的;
    //当然，我们不能假设*s1和*s2是有符号的还是无符号的;
    //所以就算是有符号的，还是不能这样写；
}

int StrCmpStd(const char *s1, const char *s2) {
    for( ; *s1 == *s2; s1++, s2++) {
        if(*s1 == '\0') {
            return 0;
        }
    }

    return (*(const unsigned char *) s1)
           < *(const unsigned char *)s2 ? -1 : 1;
}