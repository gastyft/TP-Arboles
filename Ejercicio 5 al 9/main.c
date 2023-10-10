#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define color system("COLOR B")
#define ESC 27
#include "../../Firmas/Firma.h"

/// 5) Hacer una función que busque un nodo por nombre. Cuidado, el árbol está ordenado por legajo.
/// 6) Hacer una función que calcule la altura que tiene el árbol.
/// 7) Hacer una función que calcule la cantidad de nodos del árbol.
/// 8) Hacer una función que calcule la cantidad de hojas del árbol.
/// 9) Hacer una función que borre un nodo de un árbol.

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
nodoArbol *buscar_nombre(nodoArbol *ar,char nom[30]);
int altura_arbol(nodoArbol*ar);
int cant_nodo(nodoArbol *ar);
int cant_hojas(nodoArbol*ar);
nodoArbol * buscaNodoMasDer(nodoArbol * arbol);
nodoArbol * buscaNodoMasIzq(nodoArbol* arbol);
nodoArbol * borrarNodoArbol (nodoArbol * arbol, int datoAeliminar);







int main()
{
    color;
  nodoArbol *ar=inicArbol();
    ar=agregarNodoArbol(ar);
    inorder(ar);
    system("pause");
    system("cls");

    char nom[30];
    printf("Ingrese nombre a buscar \n");
    gets(nom);
    nodoArbol *buscado=buscar_nombre(ar,nom);
    if(buscado)
      mostrar_1_persona(buscado->dato);
    else
        printf("No se encontro el Nombre Buscado \n");

        system("pause");
        system("cls");
        printf("Altura del arbol es: %d\n",altura_arbol(ar));
         system("pause");
        system("cls");
        printf("La cantidad de nodos es de: %d \n",cant_nodo(ar));
        system("pause");
        system("cls");

        printf("La cantidad de hojas es: %d\n",cant_hojas(ar));

        printf("INGRESE LEGAJO A ELIMINAR \n");
        int datoAeliminar;
        scanf("%d",&datoAeliminar);

        ar=borrarNodoArbol(ar,datoAeliminar);
        system("pause");
        system("cls");

        inorder(ar);
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

nodoArbol *buscar_nombre(nodoArbol*ar,char nom[30]) ///NO DEVUELVE EL ULTIMO NODO SI ES EL BUSCADO PREGUNTAR
{
    if (ar == NULL)
        return NULL;
    else{
    if (strcmpi(ar->dato.nombre,nom)==0)
    {
        return ar;
    }
    else if (strcmpi(ar->dato.nombre,nom)<0)
    {
        return buscar_nombre(ar->izq, nom);
    }
    else
    {
        return buscar_nombre(ar->der, nom);
    }
}
}

int altura_arbol(nodoArbol*ar){
    if (ar == NULL)
        return 0;

    int alt_izq = altura_arbol(ar->izq);
    int alt_der = altura_arbol(ar->der);

if (alt_izq > alt_der) {
    return alt_izq + 1;
} else {
    return alt_der + 1;
}
}

int cant_nodo(nodoArbol *ar){
    int cant_der=0;
    int cant_izq=0;
if(!ar)
    return 0;
else{
  cant_izq= cant_nodo(ar->izq);
  cant_der= cant_nodo(ar->der);
}

return cant_der+ cant_izq +1;
}

int cant_hojas(nodoArbol*ar){
int hoja=0;
if(!ar){
    return 0;
}
else{
int hoja_izq= cant_hojas(ar->izq);
 int hoja_der=cant_hojas(ar->der);
    if(ar->izq==NULL && ar->der==NULL){
    hoja++;
    }
return hoja_der +hoja_izq +hoja;
}
   }



nodoArbol * buscaNodoMasDer(nodoArbol * arbol)
{

    nodoArbol * aux = inicArbol();

    if(arbol)
    {
        aux= buscaNodoMasDer(arbol->der);
        if(!aux)
        {
            aux=arbol;
        }
    }
  return aux;
}
nodoArbol * buscaNodoMasIzq (nodoArbol * arbol)
{

    nodoArbol * aux = inicArbol();

    if(arbol)
    {
        aux= buscaNodoMasIzq(arbol->izq);
        if(!aux)
        {
            aux=arbol;
        }
    }
return aux;
}



nodoArbol * borrarNodoArbol (nodoArbol * arbol, int datoAeliminar)
{


    if(arbol)
    {
        if(arbol->dato.legajo==datoAeliminar)
        {
            if(arbol->izq)
            {
                nodoArbol * masDer= buscaNodoMasDer(arbol->izq);

                arbol->dato=masDer->dato;

                arbol->izq= borrarNodoArbol(arbol->izq,masDer->izq);
            }
            else
            {
                if(arbol->der)
                {
                 nodoArbol* masIzq = buscaNodoMasIzq(arbol->der);
                 arbol->dato=masIzq->dato;
                 arbol->der=borrarNodoArbol(arbol->der,masIzq->der);
                }
                else
                {
                    free(arbol);
                    arbol = inicArbol();
                }
            }
        }
        else
        {
            if(datoAeliminar>arbol->dato.legajo)
            {
                arbol->der = borrarNodoArbol(arbol->der,datoAeliminar);
            }
            else
            {
                arbol->izq = borrarNodoArbol(arbol->izq,datoAeliminar);
            }
        }
    }
    return arbol;
}
