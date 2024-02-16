#include "s21_string.h"
int s21_strlen(char *str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

int s21_strcmp(char *str1, char *str2) {
    int cmp = 0;
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            cmp = *str1 - *str2;
            break;
        } else {
            str1++;
            str2++;
        }
    }
    return cmp;
}

char s21_strcpy(char *str1, char *str2) {
    while (*str2) {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
    return *str1;
}

char *s21_strcat(char *str1, char *str2) {
    char *p = str1;
    while (*p != '\0') {
        p++;
    }
    while (*str2 != '\0') {
        *p = *str2;
        p++;
        str2++;
    }
    *p = '\0';
    return str1;
}

char *s21_strchr(char *str, int find) {
    char *chr = 0;
    while (*str != '\0') {
        if (*str == find) {
            *chr = *str;

        } else {
            return 0;
        }

        str++;
    }

    return chr;
}
