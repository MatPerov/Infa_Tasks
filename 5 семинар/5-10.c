#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_SIZE 1000000
void encrypt(char* str, int k) {
    int i = 0, len = 0;
    while (str[i] != 0) {
        len += 1;
        i += 1;
    }
    for (int i = 0; i < len; i++) {
        if (isupper(str[i]) == 1) {
            if (str[i] + k <= 90)
                str[i] = str[i] + k;
            else
                str[i] = 64 + (str[i] + k) - 90;
        }
        if (islower(str[i]) == 2) {
            if (str[i] + k <= 122)
                str[i] = str[i] + k;
            else
                str[i] = 96 + (str[i] + k) - 122;
        }
    }
}
void read_file_to_string(const char filename[], char str[])
{
    FILE* f = fopen(filename, "r");
    
    int i = 0;
    while (1)
    {
        int c = fgetc(f);
        if (c == EOF)
            break;

        str[i] = (char)c;
        i += 1;
    }
    str[i] = '\0';

    fclose(f);
}
void write_to_file(const char filename[], char str[]) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Error!\n");
        exit(1);
    }
    fprintf(fp, str);
    fclose(fp);
}
int main() {
    char readfilename[200];
    char writefilename[200];
    char str[10000];
    int k;
    scanf("%s", readfilename);
    scanf("%s", writefilename);
    scanf("%i", &k);
    read_file_to_string(readfilename, str);
    encrypt(str, k);
    write_to_file(writefilename, str);
}