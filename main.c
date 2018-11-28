#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ACCOLADE '{'
#define ACCOLADE_FERMANTE '}'
#define CARRIAGERETURN '\n'
#define SPACE ' '
#define COMMA ','
void arrayBracketEol();
void operatorsSpacing();
int main()
{

    arrayBracketEol();
    printf("\n");
    operatorsSpacing();
    printf("\n");
    commaSpacing();

    return 0;
}


void arrayBracketEol(){
    FILE *fichier;
    fichier=NULL;
    fichier = fopen("test.c","rb");
    char caractereActuel;
    char caractereBuff;
    int numLine=1;
    if (fichier != NULL)
    {
        do
        {
            caractereActuel = fgetc(fichier); // On lit le caractère
            if(CARRIAGERETURN==caractereActuel)
            {
                numLine++;
            }
            if(ACCOLADE==caractereActuel)
            {
                if (CARRIAGERETURN==caractereBuff)
                {
                    printf("array-bracket-eol error  line %d\n",numLine);
                }
            }

            if(SPACE!=caractereActuel)
            {
                caractereBuff = caractereActuel;
            }
        }
        while (!feof(fichier));
    }
    else
    {
        printf("Impossible d'ouvrir le fichier test.txt");

    }
    fclose(fichier);

}

void operatorsSpacing(){

    /* PENSER à GERER LES EXCEPTIONS EX:"* POUR LES DECLARATIONS DE POINTEURS"*/

    FILE *fichier;
    fichier=NULL;
    fichier = fopen("test.c","rb");
    char caractereActuel;
    char prevChar;
    char nextChar;
    int numLine=1;


    if (fichier != NULL)
    {
        do
        {
            if(CARRIAGERETURN==caractereActuel)
            {
                numLine++;
            }
            caractereActuel = fgetc(fichier);

            if(43==caractereActuel || 42==caractereActuel || 47==caractereActuel || 45==caractereActuel || 61==caractereActuel || 63==caractereActuel || 58==caractereActuel){

                fseek(fichier, -2, SEEK_CUR );
                prevChar=fgetc(fichier);
                fseek(fichier, 1, SEEK_CUR);
                nextChar=fgetc(fichier);

                if(prevChar!=SPACE || nextChar!=SPACE){
                     printf("operators-spacing error  line %d\n",numLine);
                }
            }

        }
        while (!feof(fichier));
    }
    else
    {
        printf("Impossible d'ouvrir le fichier test.txt");

    }

    fclose(fichier);


}

void commaSpacing(){

    FILE *fichier;
    fichier=NULL;
    fichier = fopen("test.c","rb");
    char caractereActuel;
    char nextChar;
    int numLine=1;



    if (fichier != NULL)
    {
        do
        {
            if(CARRIAGERETURN==caractereActuel)
            {
                numLine++;
            }
            caractereActuel = fgetc(fichier);
            if(COMMA==caractereActuel){
                nextChar=fgetc(fichier);

                if(nextChar!=SPACE){
                     printf("coma-spacing error  line %d\n",numLine);
                }
            }

        }
        while (!feof(fichier));
    }
    else
    {
        printf("Impossible d'ouvrir le fichier test.txt");

    }
    fclose(fichier);

}

void indent(){

    FILE *fichier;
    fichier=NULL;
    fichier = fopen("test.c","rb");
    char caractereActuel;
    char nextChar;
    int numLine=1;



    if (fichier != NULL)
    {
        do
        {
            if(CARRIAGERETURN==caractereActuel)
            {
                numLine++;
            }
            caractereActuel = fgetc(fichier);
            if(COMMA==caractereActuel){
                nextChar=fgetc(fichier);

                if(nextChar!=SPACE){
                     printf("coma-spacing error  line %d\n",numLine);
                }
            }

        }
        while (!feof(fichier));
    }
    else
    {
        printf("Impossible d'ouvrir le fichier test.txt");

    }
    fclose(fichier);

}
