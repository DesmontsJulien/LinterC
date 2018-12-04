#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ACCOLADE '{'
#define CARRIAGERETURN '\n'
#define SPACE ' '
#define COMMA ','

void arrayBracketEol();
void operatorsSpacing();
void commentsHeader();
void maxLineNumbers(int n);
void noMultiDeclaration();
int main()
{

    arrayBracketEol();
    printf("\n");
    //operatorsSpacing();
    printf("\n");
    //commaSpacing();
    printf("\n");
    commentsHeader();
    printf("\n");
    maxLineNumbers(60);
    printf("\n");
    noMultiDeclaration();
    return 0;
}


void arrayBracketEol()
{
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

void operatorsSpacing()
{

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
            if(43==caractereActuel || 42==caractereActuel || 47==caractereActuel || 45==caractereActuel || 61==caractereActuel || 63==caractereActuel || 58==caractereActuel)
            {
                fseek(fichier, -1, SEEK_CUR );

                prevChar=fgetc(fichier);
                fseek(fichier, 2, SEEK_CUR);
                fseek(fichier, -1, SEEK_CUR );
                nextChar=fgetc(fichier);
                if(prevChar!=SPACE ||nextChar!=SPACE)
                {
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

void commaSpacing()
{

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
            if(COMMA==caractereActuel)
            {
                fseek(fichier, 1, SEEK_CUR );
                nextChar=fgetc(fichier);
                if(nextChar!=SPACE)
                {
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

void commentsHeader()
{
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
            if(numLine<6)
            {

                if('*'==caractereActuel)
                {
                    if ('/'==caractereBuff)
                    {
                        printf("comments header on top  line %d\n",numLine);
                    }
                }

            }


            caractereBuff = caractereActuel;

        }
        while (!feof(fichier));
    }
    else
    {
        printf("Impossible d'ouvrir le fichier test.txt");

    }
    fclose(fichier);

}

void maxLineNumbers(int n)
{
    FILE *fichier;
    fichier=NULL;
    fichier = fopen("test.c","rb");
    char caractereActuel;
    char caractereBuff;
    int numLine=1;
    int nbCarac=0;
    int reset=0;
    if (fichier != NULL)
    {
        do
        {
            caractereActuel = fgetc(fichier); // On lit le caractère
            if(CARRIAGERETURN==caractereActuel)
            {
                numLine++;
                reset=0;
            }
            nbCarac++;
            if (CARRIAGERETURN==caractereActuel)
            {
                nbCarac=0;
            }

            if(nbCarac>n && reset!=1)
            {
                printf("max-line-numbers error  line %d\n",numLine);
                reset=1;
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

void  noMultiDeclaration()
{

    FILE *fichier;
    fichier=NULL;
    fichier = fopen("test.c","rb");
    char a;
    char buffVar;
    int i=0;
    int numLine=1;
    int checkCR=0;
    int fileSize=0;
    int nbCarac=0;
    char *buffer;

    if (fichier != NULL)
    {
        do
        {
            fgetc(fichier);
            fileSize++;
        }
        while (!feof(fichier));

        buffer = malloc(sizeof(char) * fileSize);
        fseek(fichier, 0, SEEK_SET);

        do
        {
            buffer[i] = fgetc(fichier);
            i++;
        }
        while (!feof(fichier));


        for(int i=0; i< fileSize; i++)  //On fait un buffer sous forme de chaques caractères pour enregistrer chaques lignes
        {

            //Debut du process pour trouver les types de variables
            if('t'==buffer[i] && 'r'==buffer[i-1] && 'o'==buffer[i-2] && 'h'==buffer[i-3] && 's'==buffer[i-4] && (' '==buffer[i-5] || CARRIAGERETURN==buffer[i-5]))
            {
                while (CARRIAGERETURN != buffer[i])
                {
                    if(';'==buffer[i] || '('==buffer[i])
                    {
                        checkCR=1;

                    }
                    if (','==buffer[i] && checkCR==0)
                    {
                        printf("no-multi-declaration error line %d\n",numLine);
                    }
                    i++;
                }
                checkCR=0;
            }


            if('e'==buffer[i] && 'l'==buffer[i-1] && 'b'==buffer[i-2] && 'u'==buffer[i-3] && 'o'==buffer[i] && 'd'==buffer[i-5] && (' '==buffer[i-6] || CARRIAGERETURN==buffer[i-6]))
            {

                while (CARRIAGERETURN != buffer[i])
                {
                    if(';'==buffer[i] || '('==buffer[i])
                    {
                        checkCR=1;

                    }
                    if (','==buffer[i] && checkCR==0)
                    {
                        printf("no-multi-declaration error line %d\n",numLine);
                    }
                    i++;
                }
                checkCR=0;
            }


            if('t'==buffer[i] && 'n'==buffer[i-1] && 'i'==buffer[i-2] && (' '==buffer[i-3] || CARRIAGERETURN==buffer[i-3]))
            {
                while (CARRIAGERETURN != buffer[i])
                {
                    if(';'==buffer[i] || '('==buffer[i])
                    {
                        checkCR=1;

                    }
                    if (','==buffer[i] && checkCR==0)
                    {
                        printf("no-multi-declaration error line %d\n",numLine);
                    }
                    i++;
                }
                checkCR=0;

            }


            if('t'==buffer[i] && 'a'==buffer[i-1] && 'o'==buffer[i-2] && 'l'==buffer[i-3] && 'f'==buffer[i-4] && (' '==buffer[i-5] || CARRIAGERETURN==buffer[i-5]))
            {
                while (CARRIAGERETURN != buffer[i])
                {
                    if(';'==buffer[i] || '('==buffer[i])
                    {
                        checkCR=1;

                    }
                    if (','==buffer[i] && checkCR==0)
                    {
                        printf("no-multi-declaration error line %d\n",numLine);
                    }
                    i++;
                }
                checkCR=0;
            }


            if('r'==buffer[i] && 'a'==buffer[i-1] && 'h'==buffer[i-2] && 'c'==buffer[i-3] && (' '==buffer[i-4] || CARRIAGERETURN==buffer[i-4]))
            {

                while (CARRIAGERETURN != buffer[i])
                {
                    if(';'==buffer[i] || '('==buffer[i])
                    {
                        checkCR=1;

                    }
                    if (','==buffer[i] && checkCR==0)
                    {
                        printf("no-multi-declaration error line %d\n",numLine);
                    }
                    i++;
                }
                checkCR=0;
            }


            if('n'==buffer[i] && 'a'==buffer[i-1] && 'e'==buffer[i-2] && 'l'==buffer[i-3] && 'o'==buffer[i-4] && 'o'==buffer[i-5] && 'b'==buffer[i-6] && (' '==buffer[i-7] || CARRIAGERETURN==buffer[i-7]))
            {
                while (CARRIAGERETURN != buffer[i])
                {
                    if(';'==buffer[i] || '('==buffer[i])
                    {
                        checkCR=1;

                    }
                    if (','==buffer[i] && checkCR==0)
                    {
                        printf("no-multi-declaration error line %d\n",numLine);
                    }
                    i++;
                }
                numLine++;
                checkCR=0;
            }

            if(CARRIAGERETURN==buffer[i])
            {
                numLine++;
            }

        }
    }
    else
    {
        printf("Impossible d'ouvrir le fichier test.c");

    }
    printf("%d",numLine);
    fclose(fichier);
}


