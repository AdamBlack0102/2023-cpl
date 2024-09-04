//
// Created by goat2 on 2023/12/11.
//
#include<stdio.h>

#define LEN 1000

void reserve();
void integer();
void flo();
void opera();
void variable();
void enter();

const char *reserved[16] = {"const", "int",
                            "float", "double",
                            "long", "static",
                            "void", "char",
                            "extern", "return",
                            "break", "enum",
                            "struct", "typedef",
                            "union", "goto"};

const char *operator[LEN] = {"+", "-", "*", "/",
                             "=", "==", "!=", ">=",
                             "<=", ">", ">"};

int main(void) {


    return 0;
}

void reserve() {
    printf("reserved ");
}

void integer() {
    printf("integer ");
}

void flo() {
    printf("float ");
}

void opera() {
    printf("operator ");
}

void variable() {
    printf("variable ");
}

void enter() {
    printf("\n");
}
