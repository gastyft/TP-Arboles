#include <stdio.h>
#include <stdlib.h>
#define color system("COLOR B")
#include <string.h>
#include <conio.h>
#define ESC 27
#include "../../Firma/Firma.h"
/**
 1) Hacer una función que permita ingresar nuevos nodos manteniendo el árbol ordenado (por legajo).

2) Hacer una función que permita ingresar nuevos nodos manteniendo el árbol ordenado (por legajo).
Hacer tres funciones, una función que recorra el árbol y
muestre su contenido en orden (verificar cual de los recorridos es conveniente: inorder, posorder o preorder).
Modularizar.

3) Hacer una función que copie el contenido del árbol en una lista simplemente enlazada.

4) Hacer una función que busque un nodo por legajo y lo retorne.

5) Hacer una función que busque un nodo por nombre. Cuidado, el árbol está ordenado por legajo.

6) Hacer una función que calcule la altura que tiene el árbol.

7) Hacer una función que calcule la cantidad de nodos del árbol.

8) Hacer una función que calcule la cantidad de hojas del árbol.

9) Hacer una función que borre un nodo de un árbol.

*/

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
nodoArbol *insertar(nodoArbol *ar,persona p);
nodoArbol *crearNodoArbol(persona p);
nodoArbol *inicArbol();
nodoArbol *AgregarNodo(nodoArbol *ar);
void mostrarPersona(persona p);
void preorder(nodoArbol *ar);
void inorder(nodoArbol *ar);
void posorder(nodoArbol *ar);

int main()
{
    color;
    nodoArbol *ar=inicArbol();
    ar=AgregarNodo(ar);
    inorder(ar);
firma();
    return 0;
}

nodoArbol *inicArbol()
{
    return NULL;
}

nodoArbol *crearNodoArbol(persona p)
{
    nodoArbol *nuevo=(nodoArbol*)malloc(sizeof(nodoArbol));
    nuevo->dato.edad= p.edad;
    nuevo->dato.legajo=p.legajo;
    strcpy(nuevo->dato.nombre,p.nombre);
    nuevo->der=NULL;
    nuevo->izq=NULL;
    return nuevo;
}

nodoArbol *insertar(nodoArbol *ar,persona p)
{
    nodoArbol *nuevo=crearNodoArbol(p);
    if(!ar)
        ar=nuevo;
    else
    {
        if(p.legajo > ar->dato.legajo )
            ar->der=insertar(ar->der,p);
        else
            ar->izq=insertar(ar->izq,p);
    }
    return ar;
}

nodoArbol *AgregarNodo(nodoArbol *ar)
{
    persona p;
    char o=0;
    while(o!=27)
    {
        printf("Ingrese nombre \n");
        fflush(stdin);
        gets(p.nombre);
        printf("Ingrese edad\n");
        scanf("%d",&p.edad);
        printf("Ingrese Nro Legajo \n");
        scanf("%d",&p.legajo);
        ar=insertar(ar,p);
        printf("PRESS ANY KEY TO CONTINUE OR ESC TO EXIT \n");
        fflush(stdin);
        o=getch();
    }

    return ar;
}

void mostrarPersona(persona p)
{
    printf("Nombre %s \n",p.nombre);
    printf("Edad: %d \n",p.edad);
    printf("Legajo Nro: %d \n",p.legajo);
}

void preorder(nodoArbol *ar)
{
    if(ar)
    {
        mostrarPersona(ar->dato);
        preorder(ar->izq);
        preorder(ar->der);
    }
}
void inorder(nodoArbol *ar)
{
    if(ar)
    {
        inorder(ar->izq);
        mostrarPersona(ar->dato);
        inorder(ar->der);
    }
}

void posorder(nodoArbol *ar)
{
    if(ar){
    posorder(ar->izq);
    posorder(ar->der);
    mostrarPersona(ar->dato);
}
}
