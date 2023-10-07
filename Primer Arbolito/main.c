#include <stdio.h>
#include <stdlib.h>
#define color system("COLOR B")
#include <string.h>
#include <conio.h>


///ESTRUCTURAS
typedef struct Persona
{
    char Nombre[30];
    int edad;
} Persona;

typedef struct Arbol
{
    Persona pers;
    struct Arbol *izq;
    struct Arbol *der;
} Arbol;

///PROTOTIPADO
Arbol *crearArbol(Persona p);
Arbol *inicArbol();
Arbol *insertar(Arbol *ar,Persona p);
void mostrar_Persona(Arbol *ar);
void preorder(Arbol *ar);
void inorder(Arbol *ar);
void posorder(Arbol *ar);
Arbol *agregar_nodo(Arbol *ar);
int main()
{
    color;

    Arbol *ar=inicArbol();

    ar=agregar_nodo(ar);
    printf("SALI DE AGREGAR NODO");
    inorder(ar);

    return 0;
}


Arbol *inicArbol()
{
    return NULL;
}


Arbol *crearArbol(Persona p)
{
    Arbol *nuevo=(Arbol*)malloc(sizeof(Arbol));

    nuevo->der=NULL;
    nuevo->izq=NULL;
    strcpy(nuevo->pers.Nombre,p.Nombre);
    nuevo->pers.edad=p.edad;
    return nuevo;
}



Arbol *insertar(Arbol *ar, Persona p) {
    if (ar == NULL) {
        return crearArbol(p);
    }

    if (p.edad < ar->pers.edad) {
        ar->izq = insertar(ar->izq, p);
    } else {
        ar->der = insertar(ar->der, p);
    }

    return ar;
}


void mostrar_Persona(Arbol *ar)
{
    printf("Nombre: %s \n",ar->pers.Nombre);
    printf("EDAD: %d \n",ar->pers.edad);
}
void preorder(Arbol *ar)
{
    if(ar)
    {
        mostrar_Persona(ar);
        preorder(ar->izq);
        preorder(ar->der);
    }
}

void inorder(Arbol *ar)
{
    if(ar)
    {
        inorder(ar->izq);
        mostrar_Persona(ar);
        inorder(ar->der);
    }
}

void posorder(Arbol *ar)
{
    if(ar)
    {
        posorder(ar->izq);
        posorder(ar->der);
        mostrar_Persona(ar);
    }
}


Arbol *agregar_nodo(Arbol *ar)  ///CONTENEDORA PARA AGREGAR NODO DE TIPO ARBOL
{

    char o=0;
    Persona p;
    while(o!=27)
    {

        printf("Ingrese nombre\n");
        gets(p.Nombre);
        printf("Ingrese edad \n");
        scanf("%d",&p.edad);
        ar =insertar(ar,p);
        printf("PRess ESC \n");
        fflush(stdin);
        o=getch();

    }
    return ar;
}
