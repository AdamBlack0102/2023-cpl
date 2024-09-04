//
// Created by goat2 on 2023/12/1.
//
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    //char msg[] = {'H', 'e', ... , '\0'};
    char msg[] = "Hello World!";
    //用字符串初始化数组的时候最好不要在[]里面写数字
    msg[0] = 'N';
    printf("%s\n", msg);

    //read-only memory!
    char *ptr_msg = "Hello World!";
    //该字符数组的首地址被赋值给ptr_msg（指针变量）
    //ub ↓
    ptr_msg[0] = 'N';
    printf("%s\n", msg);

    return 0;
}