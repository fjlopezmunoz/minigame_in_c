#include "Rafaga.h"
#include <stdlib.h>

struct Nodo
{
    Bala dato;
    struct Nodo * sig;

};
typedef struct Nodo * Nodoptr;

struct Rafagarep
{
    Nodoptr cabecera;
    int n;
};

Rafaga crea_rafaga()
{
    Rafaga nuevo = malloc(sizeof(struct Rafagarep));
    nuevo->cabecera = malloc(sizeof(struct Nodo));
    nuevo->cabecera->sig= NULL;
    nuevo->n = 0;
    return nuevo;
}

void inserta_rafaga( Rafaga r, Bala b)
{
    Nodoptr nuevo= malloc(sizeof(struct Nodo));
    nuevo->dato = b;
    nuevo->sig=r->cabecera->sig;
    r->cabecera->sig = nuevo;
    r->n = (r->n) +1;
}

void libera_rafaga( Rafaga r)
{
    while(r->cabecera->sig!=NULL)
    {
        Nodoptr borrar=r->cabecera->sig;
        r->cabecera->sig = borrar->sig;
        libera_bala(borrar->dato);
        free(borrar);
    }
    free(r->cabecera);
    free(r);
}

void mueve_rafaga(Rafaga r)
{
    double rx = Pantalla_Anchura();
    Nodoptr aux = r->cabecera;
    while(aux->sig!=NULL)
    {
        mueve_bala(aux->sig->dato);
        if(get_x_bala(aux->sig->dato) + get_w_bala(aux->sig->dato) <0 || get_x_bala(aux->sig->dato) > rx || get_y_bala(aux->sig->dato) + get_h_bala(aux->sig->dato) <0 || get_y_bala(aux->sig->dato) > rx)
        {
            Nodoptr borrar = aux->sig;
            aux->sig=borrar->sig;
            libera_bala(borrar->dato);
            free(borrar);

        }
        if(aux->sig!=NULL)
        {
            aux = aux->sig;
        }

    }
}

void dibuja_rafaga(Rafaga r)
{
    Nodoptr aux = r->cabecera;
    while(aux->sig!=NULL)
    {
        dibuja_bala(aux->sig->dato);
        aux = aux->sig;
    }
}

int colision_rafaga(Rafaga r, double x, double y, double w, double h)
{
    Nodoptr aux = r->cabecera;
    while(aux->sig!=NULL && !colision_bala(aux->sig->dato,x,y,w,h))
    {
        aux = aux->sig;
    }
    if(aux->sig!=NULL && colision_bala(aux->sig->dato,x,y,w,h))
    {
        Nodoptr borrar = aux->sig;
        aux->sig = borrar->sig;
        libera_bala(borrar->dato);
        free(borrar);
        r->n = r->n -1;
        return 1;
    }
    return 0;
}

int longitud(Rafaga r)
{
    return r->n;
}
