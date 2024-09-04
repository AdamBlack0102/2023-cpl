#include <stdio.h>

int StrLen(const char *str);
int StrLen1(const char *str);
int StrLen2(const char *str);
size_t StrLenStd(const char *str);

int main() {
    char msg[] = "Hello World!";

    printf("StrLen(%s) = %d\n", msg, StrLen(msg));
    printf("StrLen1(%s) = %d\n", msg, StrLen1(msg));
    printf("StrLen2(%s) = %d\n", msg, StrLen2(msg));
    printf("StrLenStd(%s) = %zu\n", msg, StrLenStd(msg));

    return 0;
}

//const: 保护字符串不被修改（不能通过对str解引用来修改字符串）
//（如：不能写str[0] = '\0'; 会报错）
//const char *str == char const *str
//const只保护里面的字符，不保护str（指针变量本身）；
//如果要保护指针变量本身，用：const char * const str（不过不经常使用）
int StrLen(const char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int StrLen1(const char *str) {
    int len = 0;
    while(str[len++] != '\0');
    return len - 1;
}

int StrLen2(const char *str) {
    int len = -1;
    while(str[++len] != '\0');
    return len;
}

size_t StrLenStd(const char *str) {
    const char *sc;
    for (sc = str; *sc !='\0'; ++sc);
    return sc - str;
}