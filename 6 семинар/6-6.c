#include <stdio.h>
void set_characters(char* begin, const char* end, char c) { //Если begin типа const char*, то begin[i] выдаёт ошибку. Не знаю, как это обойти.
    for (int i = 0; i < end - begin; i++) {
        begin[i] = c;
    }
}

int main()
{
    char s[] = "Sapere Aude";
    set_characters(&s[2], &s[8], 'b');
    printf("%s\n", s);
    set_characters(s, &s[4], 'a');
    printf("%s\n", s);
}
