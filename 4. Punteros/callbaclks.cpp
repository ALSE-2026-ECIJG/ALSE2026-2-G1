#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
    Callback que convierte un caracter a mayúscula
*/
char toUpperCase(char c)
{
    return toupper(c);
}

/*
    Callback que convierte un caracter a minúscula
*/
char toLowerCase(char c)
{
    return tolower(c);
}

/*
    Callback que reemplaza vocales por '*'
*/
char hideVowels(char c)
{
    char lower = tolower(c);
    if (lower == 'a' || lower == 'e' || lower == 'i' ||
        lower == 'o' || lower == 'u')
        return '*';
    return c;
}

/*
    Función que recibe un callback y lo aplica a cada
    caracter de una cadena.
*/
void processText(char *text, char (*callback)(char))
{
    for (int i = 0; i < strlen(text); i++)
    {
        text[i] = callback(text[i]);//toUpperCase(text[i]);toLowerCase(text[i]);hideVowels(text[i]);
    }
}

int main()
{
    char text1[] = "Callbac";
    char text2[] = "Callbacks in C   jhkj";
    char text3[] = "Callbacks in C";
    char* pchar;

    printf("Texto original: %s\n\n", text1);

    processText(text1, toUpperCase);
    printf("Mayúsculas: %s\n", text1);
    pchar=&text1[0];
    *pchar='f';
    pchar++;//text1[1]
    *pchar='a';


    processText(text2, toLowerCase);
    printf("Minúsculas: %s\n", text2);

    processText(text3, hideVowels);
    printf("Vocales ocultas: %s\n", text3);

    return 0;
}