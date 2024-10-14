#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** get_test_strings() {
	char** p = (char**)malloc(sizeof(char*) * 4);
	if (p == NULL)
		printf("Error. Can't allocate memory!\n");
	p[0] = (char*)malloc(sizeof(char) * 4);
	if (p[0] == NULL)
		printf("Error. Can't allocate memory!\n");
	strcpy(p[0], "Cat");
	p[1] = (char*)malloc(sizeof(char) * 6);
	if (p[1] == NULL)
		printf("Error. Can't allocate memory!\n");
	strcpy(p[1], "Mouse");
	p[2] = (char*)malloc(sizeof(char) * 9);
	if (p[2] == NULL)
		printf("Error. Can't allocate memory!\n");
	strcpy(p[2], "Elephant");
    	p[3] = NULL;
	return p;
}
void print_strings(FILE* stream, char** string_array) {
    int i = 0;
    while (string_array[i] != NULL) {
        fprintf(stream, "%s\n", string_array[i]);
        i += 1;
    }
    fclose(stream);
}

char** load_lines(const char* filename) {
    FILE* f = fopen(filename, "r");
    int num = 0;
    while (1)
    {
        int c = fgetc(f);
        if (c == EOF)
            break;
        if ((char)c == 10) {
            num += 1;
        }
    }
    num += 1;
    char** p = (char**)malloc(sizeof(char*) * (num+1));
    p[num] = NULL;
    if (p == NULL)
        printf("Error. Can't allocate memory!\n");
    fseek(f, 0, SEEK_SET);
    int* p_arr = (int*)malloc(sizeof(int) * (num));
    int len = 0;
    int i = 0;
    while (1)
    {
        int c = fgetc(f);
        if (c == EOF)
            break;
        if (((char)c == 10) || (c==EOF)) {
            p_arr[i] = len;
            len = 0;
            i += 1;
        }
        len += 1;
    }
    fseek(f,0, SEEK_SET);
    for (int i = 0; i < num; i++) {
        p[i] = (char*)malloc(sizeof(char) * p_arr[i]);
        if (p[i] == NULL)
            printf("Error. Can't allocate memory!\n");
    }
    for (int i = 0; i < num; i++) {
        fgets(p[i], 10000, f);
    }
    free(p_arr);
    fclose(f);
    return p;
}
void destroy_strings(char*** p_string_array) {
    int i = 0;
    while (*(p_string_array[i]) != NULL) {
        free(*(p_string_array[i]));
        i += 1;
    }
    free(*(p_string_array[i]));
    free(*p_string_array);
    p_string_array = NULL;
    }
void sort_strings(char** words) {
    int num = 0;
    while (words[num] != NULL) {
        num += 1;
    }
    for (int j = 0; j < num; ++j)
    {
        int min_index = j;
        for (int i = j + 1; i < num; ++i)
        {
            if (strcmp(words[i], words[min_index]) < 0)
                min_index = i;
        }
        char* temp = words[j];
        words[j] = words[min_index];
        words[min_index] = temp;
    }
}
int main() {
	char** p = get_test_strings();
    FILE* f = fopen("result.txt", "w");
    char** p1 = load_lines("three_little_pigs.txt");
    sort_strings(p1);
    print_strings(f, p1);

}
