#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "vista.h"

void vista_menuPrincipal()
{
    printf("-FINAL MMADOU-\n");
    printf("1. ALTAS (Lee y carga el Arraylist)\n");
    printf("2. COMPLETAR\n");
    printf("3. COMPROBAR (Ingresa cadena)\n");
    printf("4. GENERAR Y LISTAR A) y B)\n");
    printf("5. GUARDAR ARRAYLIST´S\n");

    printf("\n0. Salir\n");
}

void vista_finFuncion ()
{
    printf("\n");
    system("pause");
    system("cls");
}void vista_opcionInvalida()
{
    printf("\nOpcion invalida. Intente otra vez.");
    system("pause");
    system("cls");
}
