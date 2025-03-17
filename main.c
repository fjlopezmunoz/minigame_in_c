#include "Pantalla.h"
#include "Colisiones.h"
#include "Rafaga.h"
#include "Ejercito.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.141592653589793

Imagen Fondo;

int ayuda()
{
    Imagen ayuda = Pantalla_ImagenLee("ayuda.bmp",255);
    int rx = Pantalla_Anchura();
    int ry = Pantalla_Altura();
    char strsalir[23] = "Pulse ESC para volver\0";
    Pantalla_DibujaImagen(Fondo,0,0,rx,ry);
    Pantalla_DibujaImagen(ayuda,0,0,rx,ry);
    while(Pantalla_Activa()&& Pantalla_TeclaPulsada(SDL_SCANCODE_ESCAPE)!=1)
    {
        Pantalla_DibujaTexto(strsalir,3*rx/5 +20,ry/10);
        Pantalla_Actualiza();
        Pantalla_Espera(16);
    }
    return 0;
}

int menu()
{
    int rx = Pantalla_Anchura();
    int ry = Pantalla_Altura();
    double x;
    double y;
    int color1 = 255, color2 = 255, color3 = 255;
    int a1 = 255, a2 = 255, a3 = 255;
    int opcion = 0;
    char strjugar[6]= "Jugar\0";
    char strayuda[7]= "Ayuda\0";
    char strsalir[6]= "Salir\0";
    Pantalla_DibujaImagen(Fondo,0,0,rx,ry);
    while(Pantalla_Activa() && opcion==0)
    {
        Pantalla_ColorRelleno(255,color1,color1, a1);
        Pantalla_DibujaRectangulo(rx/2-20, ry/6-15, 65, 40);
        Pantalla_DibujaTexto(strjugar,rx/2-10,ry/6);
        Pantalla_ColorRelleno(255,color2,color2,a2);
        Pantalla_DibujaRectangulo(rx/2-20, ry/6+60-15, 65, 40);
        Pantalla_DibujaTexto(strayuda,rx/2-10,ry/6+60);
        Pantalla_ColorRelleno(255,color3,color3,a3);
        Pantalla_DibujaRectangulo(rx/2-20, ry/6+120-15, 65, 40);
        Pantalla_DibujaTexto(strsalir,rx/2-10,ry/6+120);
        Pantalla_RatonCoordenadas(&x,&y);
        if(dentro_rectangulo(rx/2-20,ry/6-15,65,40,x,y))
        {
            color1 = 0;
            a1 = 20;
            if(Pantalla_RatonBotonPulsado(SDL_BUTTON_LEFT)==1)
            {
                opcion=1;
            }
        }
        else
        {
            color1 = 255;
            a1 = 255;
        }
        if(dentro_rectangulo(rx/2-20,ry/6+45,65,40,x,y))
        {
            color2 = 0;
            a2 = 20;
            if(Pantalla_RatonBotonPulsado(SDL_BUTTON_LEFT)==1)
            {
                opcion = 2;
            }
        }
        else
        {
            color2 = 255;
            a2 = 255;
        }
        if(dentro_rectangulo(rx/2-20,ry/6+105,65,40,x,y))
        {
            color3 = 0;
            a3 = 20;
            if(Pantalla_RatonBotonPulsado(SDL_BUTTON_LEFT)==1)
            {
                opcion=3;
            }
        }
        else
        {
            color3 = 255;
            a3 = 255;
        }
        Pantalla_Actualiza();
        Pantalla_Espera(16);
    }
    return opcion;
}

int jugarpartida()
{
    char str[50];
    char str2[50];
    int puntos = 0;
    int contador=0;
    int vidas = 3;
    int derecha = 0;
    int izquierda = 0;
    int keytime = -1;
    int rx=Pantalla_Anchura();
    int ry=Pantalla_Altura();
    time_t t;
    srand((unsigned) time(&t));
    double x  = (rx/2) + 60/22 +1;
    double y  = (ry-60) + 48/3;
    double id = rand() %(rx+1);
    double h2 = 20;
    double w2 = 20;
    heroe h = crea_heroe(x, y, 0);
    Rafaga r = crea_rafaga();
    ejercito e = crea_ejercito(50);
    inserta_enemigo(e, id, -20 , w2, h2);
    id = rand() %(rx+1);
    inserta_enemigo(e, id, -20 , w2, h2);
    sprintf(str2, "vidas : %d", vidas);
    sprintf(str, "puntos : %d", puntos);
    while (Pantalla_Activa() && vidas>0)
    {
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_RIGHT)&& heroe_get_xr_left(h)+heroe_get_anchotanque(h)<rx)
        {
            set_heroe_vx(h,3);
            mueve_heroe(h);
            derecha = derecha + 1;
            if (derecha >= 4)
            {
                set_heroe_vx(h,5);
            }
        }
        else
        {
            derecha = 0;
        }
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_LEFT)&& heroe_get_xr_left(h)>0)
        {
            set_heroe_vx(h,-3);
            mueve_heroe(h);
            izquierda = izquierda + 1;
            if (izquierda >= 4)
            {
                set_heroe_vx(h,-5);
            }
        }
        else
        {
            izquierda = 0;
        }

        Pantalla_DibujaImagen(Fondo,0,0,rx,ry);
        dibuja_heroe(h);
        /*Pantalla_ColorTrazo(255,0,0, 255);
        Pantalla_DibujaTriangulo(x,y+10, x+14, y, x+14, y+10); //tr up left
        Pantalla_DibujaRectangulo(x+14,y,25,10);               //rc up
        Pantalla_DibujaTriangulo(x+54,y+10, x+39, y, x+39, y+10); //tr up rg
        Pantalla_DibujaRectangulo(x+39,y+10,16,20); //rect rg
        Pantalla_DibujaRectangulo(x,y+10,14,20); //rect left
        Pantalla_DibujaTriangulo(x+54,y+30,x+39,y+40,x+39,y+30); //tr down right
        Pantalla_DibujaTriangulo(x,y+30,x+14,y+30,x+14,y+41); //tr down left*/

        if (contador==25)
        {
            id = rand()%(rx-(int)w2+1);
            inserta_enemigo(e, id, -20, w2, h2);
            contador = 0;
        }

        mueve_ejercito(e);
        if(colision_ejercito_heroe(e,h))
        {
            vidas = vidas -1;
            sprintf(str2, "vidas : %d", vidas);
            Pantalla_DibujaTexto(str2,529,10);
            Pantalla_DibujaTexto(str,520,25);
        }
        dibuja_ejercito(e);

        if (Pantalla_TeclaPulsada(SDL_SCANCODE_SPACE) && keytime == -1)
        {
            inserta_rafaga(r,crea_bala(heroe_get_xr_left(h)+21,heroe_get_yr_up(h)-15,0,-3));
            keytime = 0;
        }

        mueve_rafaga(r);
        dibuja_rafaga(r);
        if(colision_ejercito_rafaga(e,r))
        {
            puntos = puntos + 1;
            sprintf(str, "puntos : %d", puntos);
        }
        Pantalla_DibujaTexto(str2,529,10);
        Pantalla_DibujaTexto(str,520,25);
        contador = contador + 1;
        if (keytime!=-1)
        {
            keytime = keytime + 1;
            if (keytime>=15)
            {
                keytime = -1;
            }
        }
        Pantalla_Actualiza();
        Pantalla_Espera(16);

    }
    if(Pantalla_Activa()==1)
    {
        int marca = puntos;
        FILE * record = NULL;
        record = fopen("record.txt", "r+");
        if (record!=NULL)
        {
            fscanf(record,"%d",&marca);
            if(puntos>marca)
            {
                marca = puntos;
                rewind(record);
            }
        }
        else
        {
            record = fopen("record.txt", "w");
        }
        fprintf(record, "%d",marca);
        printf("record: %d\n",marca);
        fclose(record);
    }
    libera_heroe(h);
    libera_ejercito(e);
    libera_rafaga(r);
    return 0;
}


int main(int argc, char *argv[])
{
    int rx=640;
    int ry=480;
    Pantalla_Crea("Rocas picudas al ataque", rx,ry);
    Fondo = Pantalla_ImagenLee("fondo2.bmp", 0);
    Pantalla_DibujaImagen(Fondo,0,0,Pantalla_Anchura(),Pantalla_Altura());
    int selec = 0;
    while(selec!=3)
    {
        selec = menu();
        if (Pantalla_Activa()==0)
        {
            selec=3;
        }
        if(selec==1)
        {
            jugarpartida();
            if (Pantalla_Activa()==0)
            {
                selec=3;
            }
        }
        else if(selec==2)
        {
            ayuda();
            if (Pantalla_Activa()==0)
            {
                selec=3;
            }
        }
    }
    Pantalla_ImagenLibera(Fondo);
    Pantalla_Libera();
    return 0;
}






















