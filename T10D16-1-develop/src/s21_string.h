#ifndef S21_STRING_H
#define S21_STRING_H

#include <stdio.h>
#include <stdlib.h>

int s21_strlen(char *str);
int s21_strcmp(char *str1, char *str2);
char s21_strcpy(char *str1, char *str2);
char *s21_strcat(char *str1, char *str2);
char *s21_strchr(char *str, int find);

#endif