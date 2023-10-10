#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define color system("COLOR B")
#define ESC 27
#include "../../Firma/Firma.h"

///Hacer una función que busque un nodo por legajo y lo retorne.

///ESTRUCTURAS
typedef struct
{
    int legajo;
    char nombre[20];
    int edad;
} persona;
typedef struct nodoArbol
{
    persona dato;
    struct nodoArbol * izq;
    struct nodoArbol * der;
} nodoArbol;

///PROTOTIPADO
nodoArbol *inicArbol();
nodoArbol *insertar(nodoArbol *ar,persona p);
persona carga_1_persona();
nodoArbol*agregarNodoArbol(nodoArbol *ar);
void mostrar_1_persona(persona p);
void preorder(nodoArbol *ar);
void inorder(nodoArbol*ar);
void posorder(nodoArbol *ar);
nodoArbol *buscarUnNodo(nodoArbol *ar,int lega );


int main()
{
    color;
    nodoArbol *ar=inicArbol();
    ar=agregarNodoArbol(ar);
    inorder(ar);
    system("pause");
    system("cls");
    printf("Ingrese un Nro de legajo \n");
    int legajo=0;
    scanf("%d",&legajo);

    nodoArbol *buscado=buscarUnNodo(ar,legajo);
    if(buscado)
        inorder(buscado);
    else
        printf("No se encontro el Legajo \n");
    firma();
    return 0;
}


nodoArbol *inicArbol()
{

    return NULL;
}

nodoArbol*crearNodoArbol(persona p)
{
    nodoArbol*nuevo=(nodoArbol*)malloc(sizeof(nodoArbol));
    strcpy(nuevo->dato.nombre,p.nombre);
    nuevo->dato.edad=p.edad;
    nuevo->dato.legajo=p.legajo;
    nuevo->der=NULL;
    nuevo->izq=NULL;
    return nuevo;

}
nodoArbol *insertar(nodoArbol *ar,persona p)
{


    if(!ar)
        return crearNodoArbol(p);
    else
    {
        if(p.legajo> ar->dato.legajo)
            ar->der=insertar(ar->der,p);
        else
            ar->izq= insertar(ar->izq,p);
    }
    return ar;
}


persona carga_1_persona()
{
    persona p;

    printf("Ingrese Nombre\n");
    fflush(stdin);
    gets(p.nombre);
    printf("Ingrese edad \n");
    scanf("%d",&p.edad);
    printf("Ingrese Nro Legajo \n");
    scanf("%d",&p.legajo);

    return p;
}


nodoArbol *agregarNodoArbol(nodoArbol *ar)
{

    char o=0;

    while(o!=27)
    {

        ar=insertar(ar,carga_1_persona());
        printf("Presione cualquier tecla para continuar o ESC para salir \n");
        fflush(stdin);
        o=getch();
    }
    return ar;
}
void mostrar_1_persona(persona p)
{
    printf("Nombre: %s \n",p.nombre);
    printf("Edad: %d \n",p.edad);
    printf("Legajo Nro: %d \n",p.legajo);
}
void preorder(nodoArbol *ar)
{
    if(ar)
    {
        mostrar_1_persona(ar->dato);
        preorder(ar->izq);
        preorder(ar->der);
    }
}

void inorder(nodoArbol *ar)
{
    if(ar)
    {
        inorder(ar->izq);
        mostrar_1_persona(ar->dato);
        inorder(ar->der);
    }
}
void posorder(nodoArbol *ar)
{
    if(ar)
    {
        posorder(ar->izq);
        posorder(ar->der);
        mostrar_1_persona(ar->dato);
    }
}

nodoArbol *buscarUnNodo(nodoArbol *ar, int lega)
{
    if (ar == NULL)
        return NULL;

    if (ar->dato.legajo == lega)
    {
        ar->der=NULL;
        ar->izq=NULL;
        return ar;
    }
    else if (ar->dato.legajo > lega)
    {
        return buscarUnNodo(ar->izq, lega);
    }
    else
    {
        return buscarUnNodo(ar->der, lega);
    }
}

