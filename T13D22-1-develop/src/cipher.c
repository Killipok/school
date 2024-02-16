#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

void caesar_cipher(char str[], int shift);

int main() {
    FILE *text;
    char name[100];
    char str[100];
    int num, shift;
    char filename[100];
    char filepath[200];
    char directory[] = "ai_modules";

    if (scanf("%d", &num) != 1) {
        printf("n/a\n");
        exit(1);
    }

    while (num != -1) {
        switch (num) {
                // case_1
            case 1:

                scanf("%s", name);

                text = fopen(name, "r");

                if (text == NULL) {
                    printf("n/a\n");
                } else {
                    fseek(text, 0, SEEK_END);
                    if (ftell(text) == 0) {
                        printf("n/a");
                    } else {
                        rewind(text);
                        while (fgets(str, 100, text) != NULL) {
                            printf("%s", str);
                        }
                    }
                    printf("\n");
                    rewind(text);
                    fclose(text);
                }

                break;
                // case_2
            case 2:
                text = fopen(name, "r");
                if (text == NULL) {
                    char tmp;
                    scanf("%s", &tmp);
                    printf("n/a\n");
                } else {
                    text = fopen(name, "a");
                    while (fgets(str, 100, stdin) != NULL) {
                        if (strncmp(str, "-1", 2) == 0) {
                            rewind(text);
                            text = fopen(name, "r");
                            while (fgets(str, 100, text) != NULL) {
                                printf("%s", str);
                            }
                            exit(0);
                        } else {
                            fputs(str, text);
                        }
                    }
                    fclose(text);
                }
                break;
                // case_3
            case 3:
                scanf("%d", &shift);

                DIR *dir = opendir(directory);
                if (dir == NULL) {
                    printf("n/a\n");
                    continue;
                }

                struct dirent *entry;
                struct stat file_info;
                while ((entry = readdir(dir)) != NULL) {
                    strcpy(filename, entry->d_name);
                    strcpy(filepath, directory);
                    strcat(filepath, "/");
                    strcat(filepath, filename);

                    if (stat(filepath, &file_info) == -1) {
                        printf("n/a\n");
                        continue;
                    }

                    if (S_ISREG(file_info.st_mode)) {
                        char *extension = strrchr(filename, '.');

                        if (extension != NULL && strcmp(extension, ".c") == 0) {
                            FILE *file = fopen(filepath, "r+");
                            if (file == NULL) {
                                printf("n/a");
                                continue;
                            }

                            char str[100];
                            while (fgets(str, sizeof(str), file) != NULL) {
                                caesar_cipher(str, shift);
                                fseek(file, -strlen(str), SEEK_CUR);
                                fputs(str, file);
                            }
                            fclose(file);
                        } else if (extension != NULL && strcmp(extension, ".h") == 0) {
                            FILE *file = fopen(filepath, "w");
                            if (file == NULL) {
                                printf("n/a\n");
                            } else {
                                fclose(file);
                            }
                        }
                    }
                }
                closedir(dir);
                break;
        }

        if (scanf("%d", &num) != 1) {
        }
    }

    return 0;
}

void caesar_cipher(char str[], int shift) {
    int i = 0;
    char c;
    while (str[i]) {
        c = str[i];
        if (c >= 'A' && c <= 'Z') {
            c = 'A' + (c - 'A' + shift) % 26;
        } else if (c >= 'a' && c <= 'z') {
            c = 'a' + (c - 'a' + shift) % 26;
        }
        str[i] = c;
        i++;
    }
}