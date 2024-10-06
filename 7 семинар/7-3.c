#include <stdio.h>
#include <string.h>
struct game
{
    char title[50];
    float rating;
};
typedef struct game Game;
int main() {
    int n;
    scanf("%i", &n);
    Game arr[10];
    char temp;
    int k;
    float r;
    for (int i = 0; i < n; i++) {
        scanf("%[^:]", arr[i].title);
        scanf("%c", &temp);
        scanf("%i", &k);
        for (int j = 0; j < k; j++) {
            scanf(" %f", &r);
            arr[i].rating += r;
        }
        scanf("%c", &temp);
        arr[i].rating /= k;
    }
    for (int j = 0; j < n; ++j){
    int max_index = j;
    for (int i = j + 1; i < n; ++i)
    {
        if (arr[i].rating > arr[max_index].rating)
            max_index = i;
    }

    char temp1[50];
    float temp2;
    strcpy(temp1, arr[j].title);
    strcpy(arr[j].title, arr[max_index].title);
    strcpy(arr[max_index].title, temp1);
    temp2 = arr[j].rating;
    arr[j].rating = arr[max_index].rating;
    arr[max_index].rating = temp2;
    }
    for (int i = 0; i < n; i++) 
        printf("%s, %.3f\n", arr[i].title, arr[i].rating);
 }