#include "s21_string.h"

#include <stdio.h>

void s21_strlen_test(char *str, int expected);
void s21_strcmp_test(char *str1, char *str2, int expected);
void s21_strcpy_test(char *str1, char *str2);
void s21_strcat_test(char *str1, char *str2);
void s21_strchr_test(char *str, int find, char *exp);

int main() {
#ifdef Quest_1
    s21_strlen_test("wew", 3);
    s21_strlen_test("", 0);
    s21_strlen_test("123123\0 3", 6);
#endif

#ifdef Quest_2
    s21_strcmp_test("wec", "wez", -23);
    s21_strcmp_test("wez", "wec", 23);
    s21_strcmp_test("wew", "wew", 0);
#endif

#ifdef Quest_3
    char test1[25], test2[1];
    s21_strcpy_test(test1, "winner");
    s21_strcpy_test(test1, "w");
    s21_strcpy_test(test2, "mew");
#endif

#ifdef Quest_4
    char test1[] = "inner", test2[] = "I am ";
    s21_strcat_test(test2, "winner");
    s21_strcat_test(test1, "w");
    s21_strcat_test(test1, "");
#endif

#ifdef Quest_5
    char test2[] = "I am ";
    s21_strchr_test(test2, 'a', "a");
    s21_strchr_test(test2, 'T', "NULL");
    s21_strchr_test(test2, 't', "NULL");
#endif

    return 0;
}

void s21_strlen_test(char *str, int expected) {
    printf("%s\n", str);
    if (s21_strlen(str) == expected) {
        printf("%d\nSUCCESS\n", s21_strlen(str));
    } else {
        printf("%d\nFAIL\n", s21_strlen(str));
    }
}

void s21_strcmp_test(char *str1, char *str2, int expected) {
    printf("%s %s\n", str1, str2);
    if (s21_strcmp(str1, str2) == expected) {
        printf("%d\nSUCCESS\n", s21_strcmp(str1, str2));
    } else {
        printf("%d\nFAIL\n", s21_strcmp(str1, str2));
    }
}

void s21_strcpy_test(char *str1, char *str2) {
    printf("%s %s\n", str1, str2);
    s21_strcpy(str1, str2);
    if (s21_strcpy(str1, str2) == 0) {
        printf("%d\nSUCCESS\n", s21_strcpy(str1, str2));
    } else {
        printf("%d\nFAIL\n", s21_strcpy(str1, str2));
    }
}

void s21_strcat_test(char *str1, char *str2) {
    printf("%s %s\n", str1, str2);
    int len1 = s21_strlen(str1), len2 = s21_strlen(str2);
    if (s21_strlen(s21_strcat(str1, str2)) == len1 + len2) {
        printf("%s\nSUCCESS\n", str1);
    } else {
        printf("%s\nFAIL\n", str1);
    }
}

void s21_strchr_test(char *str, int find, char *exp) {
    printf("%s %c\n", str, find);
    char *p = s21_strchr(str, find);
    if (*p == *exp && p >= str && p <= str + s21_strlen(str) - 1) {
        printf("%c\nSUCCESS\n", *p);
    } else if (*exp == 'N') {
        printf("NULL\nSUCCESS\n");
    } else {
        printf("NULL\nFAIL\n");
    }
}