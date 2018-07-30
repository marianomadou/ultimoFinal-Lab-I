#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "letras.h"
/// CONSTRUCTOR
eLetra* letra_newStruct()
{
    eLetra* aux=(eLetra*)malloc(sizeof(eLetra));
    return aux;
}
/// NUEVO NUM
void letra_new(eLetra* n, int* id, char letra, char* name, int vocal, int consonante)
{
    letra_setId(n,id);
    letra_setLetra(n,letra);
    letra_setName(n,name);
    letra_setVocal(n,vocal);
    letra_setConsonante(n,consonante);
}


/// SETTERS
void letra_setName(eLetra* n, char* aux)
{
    if(n!=NULL&&aux!=NULL)
    {
        strcpy(n->name,aux);
    }
}
void letra_setLetra(eLetra* n, char aux)
{
    if(n!=NULL)
    {
        n->letra=aux;
    }
}
void letra_setVocal(eLetra* n,int aux)
{
    if(n!=NULL)
    {
        n->vocal=aux;
    }
}
void letra_setConsonante(eLetra* n,int aux)
{
    if(n!=NULL)
    {
        n->consonante=aux;
    }
}
void letra_setId(eLetra* n,int* aux)
{
    if(n!=NULL)
    {
        n->id=*aux;
    }
}
/// GETTERS
char* letra_getName (eLetra* n)
{
    char* str=NULL;
    if(n!=NULL)
    {
        str=n->name;
    }
    return str;
}
char letra_getLetra (eLetra* n)
{
    char aux;
    if(n!=NULL)
    {
        aux=n->letra;
    }
    return aux;
}
int letra_getVocal(eLetra* n)
{
    int aux;
    if(n!=NULL)
    {
        aux=n->vocal;
    }
    return aux;
}
int letra_getConsonante(eLetra* n)
{
    int aux;
    if(n!=NULL)
    {
        aux=n->consonante;
    }
    return aux;
}
int letra_getId(eLetra* n)
{
    int aux;
    if(n!=NULL)
    {
        aux=n->id;
    }
    return aux;
}
/// CALCULOS
int letra_isVocal(eLetra* n)
{
    int ret=0;
    char letra=letra_getLetra(n);
    if(letra=='a'||letra=='e'||letra=='i'||letra=='o'||letra=='u')
    {
        ret=1;
    }
    return ret;
}
int letra_isConsonante(eLetra* n)
{
    int ret=0;
    if(!letra_isVocal(n))
    {
        ret=1;
    }
    return ret;
}
int letra_isNumero(eLetra* n)
{
    int ret=0;
    char letra=letra_getLetra(n);
    if(isdigit(letra))
    {
        ret=1;
    }
    return ret;
}
int letra_isMayus(eLetra* n)
{
    int ret=0;
    char letra=letra_getLetra(n);
    if(letra<'Z'&&letra>'A')
    {
        ret=1;
    }
    return ret;
}
int letra_isSpace(eLetra* n)
{
    int ret=0;
    char letra=letra_getLetra(n);
    if(isspace(letra))
    {
        ret=1;
    }
    return ret;
}
/// SET CALCULOS
void letra_setCalculos(eLetra* n)
{
    letra_setVocal(n,letra_isVocal(n));
    letra_setConsonante(n,letra_isConsonante(n));
}
/// HACER CALCULOS
void letra_completar(ArrayList* lista)
{
    eLetra* n=NULL;
    int i;
    for(i=0; i<al_len(lista); i++)
    {
        n=al_get(lista,i);
        letra_setCalculos(n);
    }
}


void mostrarUnaLetra(eLetra* c)
{
    printf("\n%-3d|%-3c |%-12s|%-5d|%-4d",letra_getId(c),letra_getLetra(c),letra_getName(c),letra_getVocal(c),letra_getConsonante(c));
}

void muestroLetra(eLetra* c)
{
    printf("\n%-3d|%-3c |%5d|%4d",letra_getId(c),letra_getLetra(c),letra_getVocal(c),letra_getConsonante(c));
}
void letra_mostrarLista(ArrayList* lista)
{
    int i;
    eLetra* c;
    if(lista!=NULL)
    {
        if(al_len(lista)!=0)
        {
            printf("ID |Let |    Name    | Voc | Cons");
            for(i=0; i<al_len(lista); i++)
            {
                c=al_get(lista,i);
                mostrarUnaLetra(c);
            }
        }
    }

    vista_finFuncion();
}
void mostrarLista(ArrayList* lista)
{
    int i;
    eLetra* c;
    if(lista!=NULL)
    {
        if(al_len(lista)!=0)
        {
            printf("ID |Let | Voc | Cons");
            for(i=0; i<al_len(lista); i++)
            {
                c=al_get(lista,i);
                muestroLetra(c);
            }
        }
    }

    vista_finFuncion();
}
void nuevaCadena(ArrayList* lista, ArrayList* A,ArrayList* B)
{
    int i,j;
    char cadena[200]={};
    char letrita;
    eLetra* n;
    eLetra* aux;

    ArrayList* C=al_newArrayList();
    ArrayList* D=al_newArrayList();
    ArrayList* noRepetidos=al_newArrayList();


    if(lista!=NULL)
    {
        for(j=0; j<al_len(lista); j++)//carga el arraylist A(ORIGINAL)
        {
            n=al_get(lista,j);
            letrita=letra_getLetra(n);
            al_add(A,n);
        }

        string_get("Ingrese cadena: ",cadena);

        for(j=0; j<al_len(lista); j++)//CARGA EL ARRAY LIST con las letras repetidas de la cadena ingresada y todos sus ocurrencias
        {
            n=al_get(lista,j);
            letrita=letra_getLetra(n);
            i=0;
            while(cadena[i]!='\0')
            {
                if(letrita==cadena[i])
                {
                    al_add(C,n);
                }
                i++;
            }
        }

         for(i=0; i<al_len(lista); i++)//carga en noRepetidos todas las letras sin repetidos
        {
            aux=(eLetra*)al_get(lista,i);

                if(contiene(aux,noRepetidos)==0)
                {
                    al_add(noRepetidos,aux);
                }
        }


         for(i=0; i<al_len(noRepetidos); i++)//carga en noRepetidos todas las letras sin repetidos y sin los caracteres de la cadenacadena
            {
                aux=(eLetra*)al_get(noRepetidos,i);

                    if(!al_contains(C,aux))
                    {
                        al_add(D,aux);
                    }
            }

    }
    printf("\nLista CADENA \n");//muestra la cadena cargada en el arraylist
    al_sort(C,letra_compararPop,0);
    mostrarLista(C);
    letras_parseOut(C,"cadena.csv");

    printf("\nLista A - ARRAYLIST ENTERO \n ");
    al_sort(A,letra_compararPop,0);
    mostrarLista(A);
    letras_parseOut(A,"conrepe.csv");

    printf("\nLista A sin repetidos:\n");
    al_sort(noRepetidos,letra_compararPop,1);
    mostrarLista(noRepetidos);
    letras_parseOut(noRepetidos,"norepe.csv");

    printf("\nLista D - ARRAYLIST con punto B Completo!\n ");
    al_sort(D,letra_compararPop,0);
    mostrarLista(D);
    letras_parseOut(D,"conrepe2.csv");
}


int letra_compararPop(void* itemA, void* itemB)
{
    eLetra* item1;
    eLetra* item2;
    int a, b, r;

    item1=(eLetra*)itemA;
    item2=(eLetra*)itemB;

    a=letra_getLetra(item1);
    b=letra_getLetra(item2);
    if(a>b)
    {
        r=1;
    }
    else if(a<b)
    {
        r=-1;
    }
    else if(a==b)
    {
        r=0;
    }

    return r;
}

int contiene(eLetra* dato, ArrayList* noRepetidos)
{
    int i;
    eLetra* aux;
    for(i=0; i<al_len(noRepetidos); i++)
    {
        aux=(eLetra*)al_get(noRepetidos,i);
        if(dato->letra==aux->letra)
        {
            return 1;
        }
    }
    return 0;
}


