#include <stddef.h>
#define MAX_CMD_SIZE 256

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
    char *str_copy = malloc(MAX_CMD_SIZE); 
    char *ptr = str;                       
    size_t length = 0;

    while (*ptr != '\0' && length < max)
    {
        if (ptr == '\0') {
            str_copy[length++] = *(ptr++); 
        }
        else if (strchr(s, *ptr) != NULL){
            if (length > 0 && str_copy[length - 1] != '\0' && length + 1 < max){
                str_copy[length++] = ' '; 
            }

            str_copy[length++] = *(ptr++); 

            if (ptr != '\0' && length + 1 < max){
                str_copy[length++] = ' ';
            }
        } else {
            str_copy[length++] = *(ptr++);
        }
    }

    strncpy(str, str_copy, max + 2);
    free(str_copy);  

    return length;
}

void replace_env(char* str, size_t* j, size_t* i) {
    ++(*i);
    char temp[MAX_CMD_SIZE]; 
    size_t k = 0;

    if (str[*i] == '{') {
        ++(*i); 
        *i += copy_until(str + *i, temp, '}', MAX_CMD_SIZE - 1);
        if (str[*i] == '}') {
            ++(*i); 
        }
    } else {
        *i += copy_until(str + *i, temp, '\0', MAX_CMD_SIZE - 1);
    }

    char* env_value = getenv(temp);
    if (env_value != NULL) {
        *j += sprintf(str + *j, "%s", env_value) - 1;
        str[*j] = '\0';
    }

}

int substenv(char* str, size_t max) {
    size_t len = strlen(str); 
    char *str_copy = malloc(MAX_CMD_SIZE); 
    str_copy = strdup(str);

    for (size_t i = 0, j = 0; i < len; ++i, ++j) {
        if (str_copy[i] == '$') { 
            replace_env(str_copy, &j, &i); 
        } else {
            return 0; 
        }
    }
    int length = strlen(str_copy);
    str_copy[len] = '\0';
    str = NULL;
    strncpy(str, str_copy, max + 2);
    return length;
}

size_t copy_until(char* src, char* dest, char delimiter, size_t max) {
    size_t i, j; 
    for (i = 0, j = 0; src[i] != delimiter && src[i] != '\0' && j < max - 1; ++i, ++j) {
        dest[j] = src[i];
    dest[j] = '\0'; 
    return i;
}

void replace_env(char* str, size_t* j, size_t* i) {
    ++(*i);
    char temp[MAX_CMD_SIZE]; 
    size_t k = 0;

    if (str[*i] == '{') {
        ++(*i); 
        *i += copy_until(str + *i, temp, '}', MAX_CMD_SIZE - 1);
        if (str[*i] == '}') {
            ++(*i); 
        }
    } else {
        *i += copy_until(str + *i, temp, '\0', MAX_CMD_SIZE - 1);
    }

    char* env_value = getenv(temp);
    if (env_value != NULL) {
        *j += sprintf(str + *j, "%s", env_value) - 1;
        str[*j] = '\0';
    }

}

int strcut(char* str, char sep, char** tokens, size_t max) {
    size_t token_cmp = 0; 
    size_t begin = 0;     
    tokens[0] = '\0'; 

    for (size_t i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == sep)
        {
            if (begin != i) {
                tokens[token_cmp++] = str + begin; 
            }
            str[i] = '\0'; 
            begin = i + 1;
        }
    }

    tokens[token_cmp++] = str + begin; 
    tokens[token_cmp] = NULL;          

    return token_cmp;
}

int strcut_s(char* str, char sep, char** tokens, size_t max) {
    size_t token_cmp = 0;
    size_t begin = 0;
    int inQuotes = 0;
    tokens[0] = '\0';

    for (size_t i = 0; token_cmp < max; i++)
    {
        if (str[i] == '\"' || str[i] == '\'')
        {
            inQuotes = !inQuotes;
        }
        else if (!inQuotes && str[i] == sep)
        {
            tokens[token_cmp++] = str + begin; 
            str[i] = '\0';                    
            begin = i + 1;                    
        }
    }

    tokens[token_cmp++] = str + begin; // Ajouter le token au tableau
    tokens[token_cmp] = NULL; // Terminer le tableau de tokens

    return token_cmp;
}