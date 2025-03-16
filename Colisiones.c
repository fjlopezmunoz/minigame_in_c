#include "Colisiones.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>

int dentro_rectangulo( int x, int y, int w, int h, int px, int py )
{
    if((x<px && px<x+w)&&(y<py && py<y+h))
    {
        return 1;
    }
    return 0;
}

double distancia_punto_punto( double x1, double y1, double x2, double y2 )
{
    return sqrt(pow((x2-x1),2)+pow((y2-y1),2));
}

int solape_circunferencias( int x1, int y1, int r1, int x2, int y2, int r2 )
{
    if (distancia_punto_punto(x1,y1,x2,y2)<(r2+r1))
    {
        return 1;
    }
    return 0;
}

int solaperectcir(int xr,int yr,int w,int h,int xc,int yc,int r)
{
    int px = xc;
    int py = yc;
    if (px<xr) px = xr;
    if (px>xr+w) px= xr + w;
    if (py<yr) py = yr;
    if (py>yr+h) py = yr + h;
    if (sqrt(pow((xc-px),2)+pow((yc-py),2))<r) return 1;
    else return 0;
}

int solaperect(int x1,int y1,int w1,int h1,int x2,int y2,int w2,int h2)
{
    if (((x1>(x2+w2)) || ((x1+w1)<x2)) || (((y1+h1)<y2) || ((y2+h2)<y1)))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int comprobar_error(double real,double obtenido,double epsilon)
{
    if (fabs(real-obtenido)<=epsilon)
    {
        return 1;
    }
    return 0;
}

double Montecarlo(double N_ptos,int Lado)
{
    int x;
    int y;
    double ptos_circulo=0;
    time_t t;
    srand((unsigned) time(&t));
    for(int i=0; i<N_ptos; i=i+1)
    {
        x = rand() % Lado;
        y = rand() % Lado;
        if ((sqrt(pow((x-Lado/2),2)+pow((y-Lado/2),2)))<(Lado/2))
        {
            ptos_circulo = ptos_circulo +1;
        }
    }
    return(ptos_circulo*4/N_ptos);
}
struct BalaRep
{
    double x;
    double y;
    double w;
    double h;
    double vx;
    double vy;
    Imagen fotobala;
};

Bala crea_bala(double x, double y, double vx, double vy)
{

    Bala ptr = malloc( sizeof( struct BalaRep ));
    ptr -> x = x;
    ptr -> y = y;
    ptr -> vx = vx;
    ptr -> vy = vy;
    ptr -> fotobala = Pantalla_ImagenLee("bullet.bmp",0);
    ptr -> h = 10;
    ptr -> w = 10;
    return ptr;
}

void libera_bala( Bala b)
{
    Pantalla_ImagenLibera (b -> fotobala);
    free(b);
}

void mueve_bala( Bala b)
{
    b -> x = (b->x) +(b->vx);
    b -> y = (b->y) +(b->vy);
}

double get_x_bala( Bala b)
{
    return b->x;
}

double get_y_bala( Bala b)
{
    return b->y;
}

double get_w_bala( Bala b)
{
    return b->w;
}

double get_h_bala( Bala b)
{
    return b->h;
}

Imagen get_imagen_bala( Bala b )
{
    return b->fotobala;
}

void dibuja_bala(Bala b)
{
    Pantalla_DibujaImagen(b->fotobala,b->x,b->y,b->w,b->h);
}

int colision_bala( Bala b, double x, double y, double w, double h )
{
    return solaperect(b->x,b->y,b->w,b->h,x,y,w,h);
}

int solape_tri_rect(double xt, double yt, double b, double ht, double xr, double yr, double w, double hr)
{
    double pxt;
    double pxr;
    double sb;
    double sa;
    if (b<0)
    {
        if (ht<0)
        {
            pxt = xt + b ;          //punto eje x de la esquina inferior izq. del triangulo
            pxr = xr + w;           //punto eje x del rectangulo mas cercano al triangulo
            sb = (fabs(pxr-pxt));   /*distancia eje x desde extremo horizontal izquierdo del triangulo a esquina inferior derecha del rectangulo
                                la cual tomaremos como base de un triangulo semejante al anterior para calcular la altura del triangulo semejante mediante Tales*/
            sa = -sb*ht/b;       //altura del triangulo semejante
            if (xr+w<xt && yr+hr<yt)
            {
                return ( (xr+w> pxt) && (yr+hr>yt+sa) );
            }
            else
            {
                return solaperect(xr, yr, w, hr, xt + b, yt, b, ht);
            }
        }
        else
        {
            pxt = xt + b;
            pxr = xr + w;
            sb = (fabs(pxr-pxt));
            sa = -sb*ht/b;
            if (xr+w<xt && yr>yt)
            {
                return (xr+w>pxt && yr<(sa+yt));
            }
            else
            {
                return solaperect(xr, yr, w, hr, xt + b, yt, b, ht);
            }
        }
    }
    else
    {
        if (ht<0)
        {
            pxt = xt + b;
            pxr = xr;
            sb = (fabs(pxr-pxt));
            sa = sb*ht/b;
            if (xr>xt && yr+hr<yt)
            {
                return (xr<pxt && yr+hr>(sa+yt));
            }
            else
            {
                return solaperect(xr, yr, w, hr, xt, yt, b, ht);
            }
        }
        else
        {
            pxt = xt + b ;
            pxr = xr;
            sb = (fabs(pxr-pxt));
            sa = sb*ht/b;
            if (xr>xt && yr>yt)
            {
                return (xr<pxt && yr<(sa+yt));
            }
            else
            {
                return solaperect(xr, yr, w, hr, xt, yt, b, ht);
            }
        }
    }

}



