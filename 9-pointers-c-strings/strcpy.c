//
// Created by goat2 on 2023/12/1.
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void StrCpy(char *dest, const char *src);
void StrCpy1(char *dest, const char *src);
void StrCpy2(char *dest, const char *src);
void StrCpy3(char *dest, const char *src);
void StrCpy4(char *dest, const char *src);
void StrCpy5(char *dest, const char *src);
char *StrCpyStd(char *dest, const char *src);


int main() {
    const char *src = "Hello World";
    char *dest = malloc(strlen(src) + 1);

    printf("dest = %s\n", dest);

    return 0;
}

//需要在dest最后加上\0, 这样才会使dest成为一个c语言中的字符串;
void StrCpy(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void StrCpy1(char *dest, const char *src) {
    int i = 0;
    while ((dest[i] = src[i]) != '\0') {
        i++;
    }
}

void StrCpy2(char *dest, const char *src) {
    int i = 0;
    //src[i] : *(src +i)
    while ((*(dest +i) = *(src +i)) != '\0') {
        i++;
    }
}

//通过指针来copy
void StrCpy3(char *dest, const char *src) {
    while ((*dest = *src) != '\0') {
       src++;
       dest++;
    }
    //printf("src = %s\n", src); 不会有任何输出，因为指针src指向了'\0';
}

//后缀++的优先级>*，所以(*dest++ = *src++) = (*(dest++) = *(src++))
void StrCpy4(char *dest, const char *src) {
    //dest++ : dest + 1; evaluated to dest; 所以解引用的是+1之前的dest指针;
    //*++dest(前缀++的优先级与*是一样的，所以要看结合性;
    //而他们的结合性都是从右往左，所以先运算前缀++);
    while ((*dest++ = *src++) != '\0');
    //printf("src = %s\n", src); 会输出src = %s; src指向了'\0'的后一位;
}

//不推荐这样写(Not Recommended)
void StrCpy5(char *dest, const char *src) {
    //NULL: null pointer; (void *) 0, 这个0是强制转成指针的0，不是整数0;
    //'\0': Null; 0; 0表示假，而0以外的都表示真;
    //所以该代码为0时就为假（即：为'\0'的时候就为假）;
    while ((*dest++ = *src++));
}

char *StrCpyStd(char *dest, const char *src) {
    for (char *s = dest; (*s++ = *src) != '\0';);
    return dest;
}

