#include <stdio.h>
#include <stdlib.h>
#define color system("COLOR B")
#include <string.h>
#include <conio.h>
#define ESC 27
#include "../../Firma/Firma.h"
/// 3) Hacer una función que copie el contenido del árbol en una lista simplemente enlazada.


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

typedef struct Nodo
{
    persona perso;
    struct Nodo *sig;
} Nodo;

///PROTOTIPADO
nodoArbol *inicArbol();
nodoArbol *crearNodoArbol(persona p);
nodoArbol *insertar(nodoArbol *ar,persona p);
nodoArbol *agregarNodo(nodoArbol *ar);
void mostrar_1_persona(persona p);
void preorder(nodoArbol *ar);
void inorder(nodoArbol *ar);
void posorder(nodoArbol *ar);
Nodo *crearNodoSimple(persona p);
Nodo*inicLista();
Nodo *copia_1_nodo(nodoArbol *ar);
Nodo *agrega_a_lista(Nodo *lista,Nodo *nuevo);
Nodo *agregarNodoSimple(nodoArbol *ar,Nodo *lista);
void mostrar_lista(Nodo*lista);

int main()
{
    color;
    nodoArbol *ar=inicArbol();
    ar=agregarNodo(ar);
    inorder(ar);
    system("pause");
    system("cls");

    Nodo *lista=inicLista();
    lista=agregarNodoSimple(ar,lista);
    mostrar_lista(lista);
    return 0;
}
Nodo *inicLista()
{
    return NULL;
}

nodoArbol *inicArbol()
{
    return NULL;
}



nodoArbol *crearNodoArbol(persona p)
{
    nodoArbol *nuevo=(nodoArbol*)malloc(sizeof(nodoArbol));
    nuevo->dato.edad=p.edad;
    nuevo->dato.legajo=p.legajo;
    strcpy(nuevo->dato.nombre,p.nombre);
    nuevo->der=NULL;
    nuevo->izq=NULL;
    return nuevo;
}

nodoArbol *insertar(nodoArbol *ar, persona p)
{

    nodoArbol *nuevo=crearNodoArbol(p);

    if(!ar)
        ar=nuevo;
    else if(p.legajo > ar->dato.legajo)
        ar->der=insertar(ar->der,p);
    else
        ar->izq=insertar(ar->izq,p);

    return ar;
}

nodoArbol *agregarNodo(nodoArbol *ar)
{
    persona p;
    char o=0;
    while(o!=27)
    {
        printf("Ingrese nombre \n");
        fflush(stdin);
        gets(p.nombre);
        printf("Ingrese edad \n");
        scanf("%d",&p.edad);
        printf("Ingrese Nro Legajo \n");
        scanf("%d",&p.legajo);
        ar=insertar(ar,p);
        printf("PRESS ANY KEY TO CONTINUE OR ESC TO EXIT \n ");
        fflush(stdin);
        o=getch();
    }

    return ar;
}

void mostrar_1_persona(persona p)
{
    printf("Nombre: %s \n",p.nombre);
    printf("Edad: %d \n",p.edad);
    printf("Nro Legajo: %d \n",p.legajo);
}

void preorder(nodoArbol *ar)
{
    if(ar)
    {
        mostrar_1_persona(ar->dato);
        preorder(ar->der);
        preorder(ar->izq);
    }
}

void inorder(nodoArbol*ar)
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


Nodo *crearNodoSimple(persona p)
{
    Nodo *nuevo=(Nodo*)malloc(sizeof(Nodo));
    nuevo->perso.edad=p.edad;
    nuevo->perso.legajo=p.legajo;
    strcpy(nuevo->perso.nombre,p.nombre);
    nuevo->sig=NULL;
    return nuevo;
}


Nodo *copia_1_nodo(nodoArbol *ar)
{
    persona p;
    strcpy(p.nombre,ar->dato.nombre);
    p.edad=ar->dato.edad;
    p.legajo=ar->dato.legajo;
    Nodo *nuevo=crearNodoSimple(p);

    return nuevo;
}

Nodo *agrega_a_lista(Nodo *lista,Nodo *nuevo)
{
Nodo *seg=lista;
    if(!lista)
        lista=nuevo;
    else
    {
        while(seg->sig){


seg=seg->sig;
        }
    seg->sig=nuevo;

    }
    return lista;
}

Nodo *agregarNodoSimple(nodoArbol *ar,Nodo *lista)
{

    if(ar)
    {
         lista = agregarNodoSimple(ar->izq, lista);
        Nodo *nuevo = copia_1_nodo(ar);
        lista = agrega_a_lista(lista, nuevo);
        lista = agregarNodoSimple(ar->der, lista);
    }
    return lista;
}

void mostrar_lista(Nodo *lista)
{
    Nodo *seg=lista;
    while(seg)
    {
        printf("Nombre: %s\n",seg->perso.nombre);
        printf("Edad: %d \n",seg->perso.edad);
        printf("Legajo Nro: %d \n",seg->perso.legajo);
        seg=seg->sig;
    }
}

