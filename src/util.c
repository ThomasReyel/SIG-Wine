#include <string.h>
void tratarString(char string[]){
    int tam = strlen(string);
    string[tam - 1] = "\0";
}