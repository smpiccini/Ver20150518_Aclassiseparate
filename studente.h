#define MAX_STRLEN 25
#define MAX_CLASSLEN 5

struct s_studente{
    char nome[MAX_STRLEN+1];
    char cognome[MAX_STRLEN+1];
    char classe[MAX_CLASSLEN+1];
    int sesso;
    unsigned int eta;
};
typedef struct s_studente studente;
