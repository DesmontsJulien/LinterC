#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ACCOLADE '{'
#define CARRIAGERETURN '\n'
#define SPACE ' '
#define COMMA ','

void arrayBracketEol();
void operatorsSpacing();
void noMultiDeclaration();
int main()
{

    //arrayBracketEol();
    printf("\n");
    //operatorsSpacing();
    printf("\n");
    //commaSpacing();
    printf("\n");
    noMultiDeclaration();

    return 0;
}


void arrayBracketEol()
{
    FILE *fichier;
    fichier=NULL;
    fichier = fopen("test.c","rb");
    char caractereActuel='0';
    char caractereBuff='0';
    int numLine,nomlpo=1;
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
        printf("Impossible d'ouvrir le fichier test.c");

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
    char caractereActuel,tutu;
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



void  noMultiDeclaration()
{

    FILE *fichier;
    fichier=NULL;
    fichier = fopen("test.c","rb");
    char a;
    char caractereActuel;
    int numLine=1;
    int nbCarac=0;
    char buffer[1000];
    if (fichier != NULL)
    {
        do
        {
            a=fgetc(fichier);
            for(int i=0; i<500; i++) //On fait un buffer sous forme de chaques caractères pour enregistrer chaques lignes
            {
                if(CARRIAGERETURN==a)
                {
                    for(int y=0; y<500; y++)
                    {
                        buffer[y]='0';
                    }

                    numLine++;
                }

                buffer[i]=a;
                printf("%c",buffer[i]);
                //Debut du process pour trouver les types de variables
                if('t'==buffer[i] && 'r'==buffer[i-1] && 'o'==buffer[i-2] && 'h'==buffer[i-3] && 's'==buffer[i-4])
                {
                    printf("%d",numLine);
                    printf("sdfghjkjhgfdsq");
                }


                if('e'==buffer[i] && 'l'==buffer[i-1] && 'b'==buffer[i-2] && 'u'==buffer[i-3] && 'o'==buffer[i] && 'd'==buffer[i-5])
                {
                    printf("%d",numLine);
                    printf("sdfghjkjhgfdsq");
                }


                if(116==buffer[i] && 110==buffer[i-1] && 105==buffer[i-2])
                {
                    printf("%d",numLine);
                    printf("sdfghjkjhgfdsq");
                }


                if('t'==buffer[i] && 'a'==buffer[i-1] && 'o'==buffer[i-2] && 'l'==buffer[i-3] && 'f'==buffer[i-4])
                {
                    printf("%d",numLine);
                    printf("sdfghjkjhgfdsq");
                }


                if('r'==buffer[i] && 'a'==buffer[i-1] && 'h'==buffer[i-2] && 'c'==buffer[i-3])
                {
                    printf("%d",numLine);
                    printf("sdfghjkjhgfdsq");
                }


                if('n'==buffer[i] && 'a'==buffer[i-1] && 'e'==buffer[i-2] && 'l'==buffer[i-3] && 'o'==buffer[i-4] && 'o'==buffer[i-5] && 'b'==buffer[i-6])
                {
                    printf("%d",numLine);
                    printf("sdfghjkjhgfdsq");
                }



            }


            nbCarac++;

        }

        while (!feof(fichier));
    }
    else
    {
        printf("Impossible d'ouvrir le fichier test.c");

    }
    printf("%d",nbCarac);
    fclose(fichier);
}
