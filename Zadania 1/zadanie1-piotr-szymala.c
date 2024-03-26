#include <stdio.h>
int main()
{
    char name[100];
    printf("Podaj imie: ");
    scanf("%s", name);
    printf("Twoje imie - %s", name);

    getchar();
    getchar();
    return 0;
}