#include "Ejercito.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define PI 3.14159
struct enemigo
{
    double x;
    double y;
    double w;
    double h;
    double V;
    double vx;
    double vy;
    double alpha;
    int vivo;
};
typedef struct enemigo malo;
struct ejercitorep
{
    malo * maloptr;
    int tope;
    int max;
    int total;
    int vueltarray;
    Imagen carafea;
};

ejercito crea_ejercito(int N)
{
    ejercito nuevo = malloc(sizeof(struct ejercitorep));
    nuevo->maloptr = malloc(sizeof(struct enemigo)*N);
    nuevo->tope = 0;
    nuevo->total = 0;
    nuevo->max = N;
    nuevo->vueltarray = 0;
    nuevo->carafea = Pantalla_ImagenLee("enemy.bmp", 0);
    nuevo->maloptr[0].vivo = 0;
    return nuevo;
}
void libera_ejercito(ejercito e)
{
    free(e->maloptr);
    Pantalla_ImagenLibera(e->carafea);
    free(e);
}
void inserta_enemigo(ejercito e, double x, double y, double w, double h)
{
    int i = e->tope;
    if(e->vueltarray == 1)
    {
        i = 0;
    }
    else
    {
        e->maloptr[i].vivo = 0;
    }
    time_t t;
    srand((unsigned) time(&t));
    while (e->maloptr[i].vivo == 1 && i < (e->max-1))
    {
        i=i+1;
    }
    if (i<e->max && e->maloptr[i].vivo == 0)
    {
        e->maloptr[i].x = x;
        e->maloptr[i].y  = y;
        e->maloptr[i].w  = w;
        e->maloptr[i].h  = h;
        e->maloptr[i].V  = 2;
        e->maloptr[i].alpha  = rand() % 89 + 1;
        e->maloptr[i].vx  = e->maloptr[i].V * cos(e->maloptr[i].alpha *180/PI);
        e->maloptr[i].vy  = e->maloptr[i].V * fabs(sin(e->maloptr[i].alpha *180/PI));
        e->maloptr[i].vivo = 1;
        e->tope = (e->tope +1)%(e->max);
        e->total = e->total + 1;
        if (e->tope == 0)
        {
            e->vueltarray = 1;
        }
    }
    if (e->total==e->max) //Si excede el máximo entonces dobla el tamaño.
    {
        e->maloptr = realloc(e->maloptr, 2*e->max*(sizeof(struct enemigo)));
        e->tope = e->max;
        e->max = e->max*2;
        e->vueltarray = 0;
    }
}

void mueve_ejercito(ejercito e)
{
    int rx = Pantalla_Anchura();
    int ry = Pantalla_Altura();
    int finfor= e->max;
    if (e->vueltarray == 0)
    {
        finfor = e->tope;
    }
    for(int i=0; i<finfor; i=i+1)
    {
        if (e->maloptr[i].vivo == 1)
        {
            if (e->maloptr[i].x<0 && (e->maloptr[i].vx<0))
            {
                e->maloptr[i].x = 0;
                e->maloptr[i].vx = -1* e->maloptr[i].vx;

            }
            if (e->maloptr[i].x > rx - e->maloptr[i].w  && (e->maloptr[i].vx>0))
            {
                e->maloptr[i].x = rx - e->maloptr[i].w;
                e->maloptr[i].vx = -1* e->maloptr[i].vx;
            }
            if (e->maloptr[i].y > ry)
            {
                e->maloptr[i].vivo = 0;
                e->total = e->total - 1;
            }
            e->maloptr[i].x = e->maloptr[i].x + e->maloptr[i].vx;
            e->maloptr[i].y = e->maloptr[i].y + e->maloptr[i].vy;
        }
    }
}

void dibuja_ejercito( ejercito e )
{
    int finfor= e->max;
    if (e->vueltarray == 0)
    {
        finfor = e->tope;
    }
    for (int i=0; i<finfor; i=i+1)
    {
        if (e->maloptr[i].vivo == 1)
        {
            Pantalla_DibujaImagen(e->carafea, e->maloptr[i].x, e->maloptr[i].y, e->maloptr[i].w, e->maloptr[i].h);
        }
    }
}

int colision_ejercito_objeto( ejercito e, double x, double y, double w, double h )
{
    int finfor= e->max;
    if (e->vueltarray == 0)
    {
        finfor = e->tope;
    }
    for (int i=0; i<finfor; i=i+1)
    {
        if ((e->maloptr[i].vivo == 1) && solaperect(e->maloptr[i].x, e->maloptr[i].y, e->maloptr[i].w, e->maloptr[i].h, x, y, w, h))
        {
            return 1;
        }
    }
    return 0;
}

int colision_ejercito_rafaga( ejercito e, Rafaga r )
{
    int kill = 0;
    int finfor= e->max;
    if (e->vueltarray == 0)
    {
        finfor = e->tope;
    }
    for (int i=0; i<(finfor); i=i+1)
    {
        if((e->maloptr[i].vivo == 1) && (colision_rafaga(r, e->maloptr[i].x, e->maloptr[i].y, e->maloptr[i].w, e->maloptr[i].h)))
        {
            e->maloptr[i].vivo = 0;
            kill = kill +1;
        }
    }
    e->total = e->total - kill;
    return kill;
}

void rebotax_ejercito (ejercito e)
{
    int finfor= e->max;
    if (e->vueltarray == 0)
    {
        finfor = e->tope;
    }
    for (int i=0; i<(finfor); i++)
    {
        if (e->maloptr[i].x<0 && (e->maloptr[i].vx<0))
        {
            e->maloptr[i].x = 0;
            e->maloptr[i].vx = -1* e->maloptr[i].vx;

        }
        if (e->maloptr[i].x > Pantalla_Anchura() - e->maloptr[i].w  && (e->maloptr[i].vx>0))
        {
            e->maloptr[i].x = Pantalla_Anchura() - e->maloptr[i].w;
            e->maloptr[i].vx = -1* e->maloptr[i].vx;

        }
    }
}

struct heroerep
{
    double xr_up;
    double yr_up;
    double wr_up;
    double hr_up;
    double xr_left;
    double yr_left;
    double wr_left;
    double hr_left;
    double xr_rg;
    double yr_rg;
    double wr_rg;
    double hr_rg;
    double xt_up_left;
    double yt_up_left;
    double ht_up_left;
    double wt_up_left;
    double xt_up_rg;
    double yt_up_rg;
    double wt_up_rg;
    double ht_up_rg;
    double xt_down_left;
    double yt_down_left;
    double wt_down_left;
    double ht_down_left;
    double xt_down_rg;
    double yt_down_rg;
    double wt_down_rg;
    double ht_down_rg;
    Imagen tanque;
    double ximg;
    double yimg;
    double wimg;
    double himg;
    double vx;
    double anchotanque;
};

heroe crea_heroe(double x, double y, double vx)
{
    heroe nuevo = malloc(sizeof(struct heroerep));
    nuevo->xr_up = x+14;
    nuevo->yr_up = y;
    nuevo->wr_up = 25;
    nuevo->hr_up = 10;
    nuevo->xr_left = x;
    nuevo->yr_left = y+10;
    nuevo->wr_left = 14;
    nuevo->hr_left = 20;
    nuevo->xr_rg = x+39;
    nuevo->yr_rg = y+10;
    nuevo->wr_rg = 16;
    nuevo->hr_rg = 20;
    nuevo->xt_up_left = x + 14;
    nuevo->yt_up_left = y + 10;
    nuevo->ht_up_left = -10;
    nuevo->wt_up_left = -14;
    nuevo->xt_up_rg = x+39;
    nuevo->yt_up_rg = y+10;
    nuevo->wt_up_rg = 15;
    nuevo->ht_up_rg = -10;
    nuevo->xt_down_left = x+14;
    nuevo->yt_down_left = y+30;
    nuevo->wt_down_left = -14;
    nuevo->ht_down_left = 11;
    nuevo->xt_down_rg = x+39;
    nuevo->yt_down_rg = y+30;
    nuevo->wt_down_rg = 15;
    nuevo->ht_down_rg = 11;
    nuevo->tanque = Pantalla_ImagenLee("hero.bmp",0);
    nuevo->ximg = Pantalla_Anchura()/2;
    nuevo->yimg = Pantalla_Altura()-60;
    nuevo->wimg = 60;
    nuevo->himg = 60;
    nuevo->anchotanque = fabs(nuevo->wt_up_left)+nuevo->wt_up_rg+nuevo->wr_up;
    return nuevo;
}

void mueve_heroe(heroe h)
{
    h->xr_up = h->xr_up + h->vx;
    h->xr_left = h->xr_left + h->vx;
    h->xr_rg = h->xr_rg + h->vx;
    h->xt_up_left = h->xt_up_left + h->vx;
    h->xt_up_rg = h->xt_up_rg + h->vx;
    h->xt_down_left = h->xt_down_left + h->vx;
    h->xt_down_rg = h->xt_down_rg+ h->vx;
    h->ximg = h->ximg + h->vx;
}

int colision_ejercito_heroe(ejercito e, heroe h)
{
    double heroe_division_up = h->yt_up_left;
    double heroe_division_down = h->yt_down_left;
    double malo_esquina;
    int finfor= e->max;
    if (e->vueltarray == 0)
    {
        finfor = e->tope;
    }
    for (int i=0; i<finfor; i=i+1)
    {
        if (e->maloptr[i].vivo == 1)
        {
            malo_esquina = e->maloptr[i].y + e->maloptr[i].h;
            if(malo_esquina>(h->yr_up))
            {
                if( malo_esquina < heroe_division_up &&
                        (solaperect(e->maloptr[i].x, e->maloptr[i].y, e->maloptr[i].w, e->maloptr[i].h, h->xr_up, h->yr_up, h->wr_up, h->hr_up) ||
                         solape_tri_rect(h->xt_up_left, h->yt_up_left, h->wt_up_left, h->ht_up_left, e->maloptr[i].x, e->maloptr[i].y, e->maloptr[i].w, e->maloptr[i].h) ||
                         solape_tri_rect(h->xt_up_rg, h->yt_up_rg, h->wt_up_rg, h->ht_up_rg, e->maloptr[i].x, e->maloptr[i].y, e->maloptr[i].w, e->maloptr[i].h)))
                {
                    e->total = e->total -1;
                    e->maloptr[i].vivo = 0;
                    return 1;
                }
                else if (malo_esquina < heroe_division_down &&
                         ( solaperect(e->maloptr[i].x, e->maloptr[i].y, e->maloptr[i].w, e->maloptr[i].h, h->xr_left, h->yr_left, h->wr_left, h->hr_left) ||
                           solaperect(e->maloptr[i].x, e->maloptr[i].y, e->maloptr[i].w, e->maloptr[i].h, h->xr_rg, h->yr_rg, h->wr_rg, h->hr_rg) ))
                {
                    e->total = e->total -1;
                    e->maloptr[i].vivo = 0;
                    return 1;
                }
                else if ( solape_tri_rect(h->xt_down_left, h->yt_down_left, h->wt_down_left, h->ht_down_left, e->maloptr[i].x, e->maloptr[i].y, e->maloptr[i].w, e->maloptr[i].h) ||
                          solape_tri_rect(h->xt_down_rg, h->yt_down_rg, h->wt_down_rg, h->ht_down_rg, e->maloptr[i].x, e->maloptr[i].y, e->maloptr[i].w, e->maloptr[i].h) )
                {
                    e->total = e->total -1;
                    e->maloptr[i].vivo = 0;
                    return 1;
                }
            }
        }
    }
    return 0;
}

void libera_heroe(heroe h)
{
    Pantalla_ImagenLibera(h->tanque);
    free(h);
}

void dibuja_heroe(heroe h)
{
    Pantalla_DibujaImagen(h->tanque,h->ximg,h->yimg,h->wimg,h->himg);
}

void set_heroe_vx(heroe h, double vx)
{
    h->vx = vx;
}

double heroe_get_xr_left(heroe h)
{
    return h->xr_left;
}

double heroe_get_yr_up(heroe h)
{
    return h->yr_up;
}

double heroe_get_anchotanque(heroe h)
{
    return h->anchotanque;
}
