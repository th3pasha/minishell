#include <stddef.h>

void move(char *dest, const char *src, size_t n) {
    if (dest > src && dest < src + n) {
        dest += n - 1;
        src += n - 1;

        while (n--) {
            *dest-- = *src--;
        }
    } else { 
        while (n--)
        { 
            *dest++ = *src++;
        }
    }
}

int trim(char *str)
{
    size_t begin = 0;
    size_t last = strlen(str) - 1;

    clean(str);
    
    while (str[begin] == ' '){
        begin++;
    }
    while (str[last] == ' '){
        last--;
    }

    move(str, str + begin, last - begin + 1);
    str[last - begin + 1] = '\0';
    
    return 0;
}

int clean(char* str) {
 size_t length = strlen(str); 
    int isSpace = 0; 
    size_t i, j; 

    for (i = 0, j = i; i < length; i++){
        if (str[i] == ' ')
        {
            if (!isSpace)
            {
                str[j++] = ' ';
                isSpace = 1;
            }
        } else {
            str[j++] = str[i];
            isSpace = 0;
        }
    }

    str[j] = '\0'; 

    return 0;
}

int separate_s(char* str, char* s, size_t max) {

}

int substenv(char* str, size_t max) {

}

int strcut(char* str, char sep, char** tokens, size_t max) {

}

int strcut_s(char* str, char sep, char** tokens, size_t max) {

}
