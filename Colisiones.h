#ifndef __Colisiones_H__
#define __Colisiones_H__

#include "Pantalla.h"

/**
\mainpage Colisiones

La biblioteca colisiones contiene funciones de colisiones entre objetos 2D.
Permite la escritura de programas que tengan colisiones entre una gama de figuras geométricas aquí
detalladas, abstrayéndose de los cálculos a realizar para conocer si colisionan.
Además añade el objeto bala al que se le pueden aplicar las funciones de colisiones aquí presentes
para interactuar con otros objetos.



*/
/**
   \file Colisiones.h
   \brief  Fichero de cabecera para poder usar las funciones de colisiones entre objetos 2D.
*/

/**
    \brief TDA Bala
 */
typedef struct BalaRep * Bala;

/**
  \brief Crea una bala y la dota de una posición y velocidad escogidas por el usuario.

  Debe ser ejecutada antes que ninguna otra función que haga uso de balas

  \param x Posición en el eje x en puntos.
  \param y Posición en el eje y en puntos.
  \param w Anchura de la bala en puntos.
  \param h Altura de la bala en puntos.
  \return La bala creada.
 */
Bala crea_bala( double x, double y, double vx, double vy );

/**
  \brief Libera la memoria reservada para la bala y sus recursos asociados.

  Debe ser ejecutada en último lugar. Si se ejecuta alguna función que haga uso de balas después de esta se producirá un error en tiempo de ejecución.
 */
void libera_bala( Bala b );

/**
  \brief Recupera la posición en el eje x de la bala.
  \param La bala cuya posición desea conocer.
  \return La posición en el eje x de la bala.
*/
double get_x_bala( Bala b );

/**
  \brief Recupera la posición en el eje y de la bala.
  \param La bala cuya posición desea conocer.
  \return La posición en el eje y de la bala.
*/
double get_y_bala( Bala b );

/**
  \brief Recupera la anchura de la bala.
  \param La bala cuya anchura desea conocer.
  \return La anchura de la bala.
*/
double get_w_bala( Bala b );

/**
  \brief Recupera la altura de la bala.
  \param La bala cuya altura desea conocer.
  \return La altura de la bala.
*/
double get_h_bala( Bala b );

/**
  \brief Recupera la imagen de la bala.
  \param La bala cuya imagen desea extraer.
  \return La imagen de la bala cuyo tipo de dato proporciona el módulo Pantalla.h .
*/
Imagen get_imagen_bala( Bala b );

/**
  \brief Mueve la bala cambiando su posición en función de su propia velocidad.
  \param La bala a mover.
*/
void mueve_bala( Bala b );

/**
  \pre w no puede ser menor que x y h no puede ser menor que y
  \brief Comprueba si un punto se encuentra en el interior de un rectángulo, ambos son concretados por el usuario.
  \param x Posición en el eje x de la esquina superior izq. del rectángulo.
  \param y Posición en el eje y de la esquina superior izq. del rectángulo.
  \param w Anchura del rectángulo.
  \param h Altura del rectángulo.
  \param px Posición en el eje x del punto.
  \param py Posición en el eje y del punto.
  \return 1 si el punto se encuentra dentro, 0 en caso contrario.
*/
int dentro_rectangulo( int x, int y, int w, int h, int px, int py );

/**
  \brief Calcula la distancia entre dos puntos dados por el usuario.
  \param x1 Posición en el eje x del primer punto.
  \param y1 Posición en el eje y del primer punto.
  \param x2 Posición en el eje x del segundo punto.
  \param y2 Posición en el eje y del segundo punto.
  \return La distancia entre ambos puntos.
*/
double distancia_punto_punto( double x1, double y1, double x2, double y2 );

/**
  \pre r1 y r2 no pueden ser menores que 0
  \brief Comprueba si dos circunferencias contienen alguno de sus puntos en el interior de la otra.
  \param x1 Posición en el eje x del centro de la primera circunferencia.
  \param y1 Posición en el eje y del centro de la primera circunferencia.
  \param r1 Longitud del radio de la primera circunferencia.
  \param x2 Posición en el eje x del centro de la segunda circunferencia.
  \param y2 Posición en el eje y del centro de la segunda circunferencia.
  \param r2 Longitud del radio de la segunda circunferencia.
  \return 1 si las circunferencias se solapan, 0 en caso contrario.
*/
int solape_circunferencias( int x1, int y1, int r1, int x2, int y2, int r2 );

/**
  \pre w no puede ser menor que xr, h no puede ser menor que yr y r no puede ser menor que 0
  \brief Comprueba si un rectángulo tiene alguno de sus puntos en el interior de una circunferencia o viceversa.
  \param xr Posición en el eje x del rectángulo.
  \param yr Posición en el eje y del rectángulo
  \param w Anchura del rectángulo.
  \param h Altura del rectángulo.
  \param xc Posición en el eje x del centro de la circunferencia.
  \param yc Posición en el eje y del centro de la circunferencia.
  \param r Longitud del radio de la circunferencia.
  \return 1 si ambos se solapan, 0 en caso contrario.
*/
int solaperectcir( int xr , int yr , int w , int h , int xc , int yc , int r );

/**
  \pre w1 y w2 no pueden ser menores que x1 y x2 respectivamente, de la misma forma h1 y h2 no pueden ser menores que y1 e y2.
  \brief Comprueba si un rectángulo tiene alguno de sus puntos en el interior de otro.
  \param x1 Posición en el eje x del primer rectángulo.
  \param y1 Posición en el eje y del primer rectángulo
  \param w1 Anchura del primer rectángulo.
  \param h1 Altura del primer rectángulo.
  \param x2 Posición en el eje x del segundo rectángulo.
  \param y2 Posición en el eje y del segundo rectángulo
  \param w2 Anchura del segundo rectángulo.
  \param h2 Altura del segundo rectángulo.
  \return 1 si los dos rectángulos se solapan, 0 en caso contrario.
*/
int solaperect( int x1 , int y1 , int w1 , int h1 , int x2 , int y2 , int w2 , int h2 );

/**
  \pre Se debe haber ejecutado Pantalla_crea del módulo pantalla.
  \brief Dibuja en pantalla la bala provista por el usuario.
  \param b Bala a dibujar.
*/
void dibuja_bala(Bala b);

/**
  \pre w1 y w2 no pueden ser menores que x1 y x2 respectivamente, de la misma forma h1 y h2 no pueden ser menores que y1 e y2.
  \brief Comprueba si un la bala se solapa con un objeto rectangular.
  \param x Posición en el eje x del rectángulo.
  \param y Posición en el eje y del rectángulo
  \param w Anchura del rectángulo.
  \param h Altura del rectángulo.
  \return 1 si la bala colisiona, 0 en caso contrario.
*/
int colision_bala( Bala b, double x, double y, double w, double h );

/**
  \pre w no puede ser menores que xr, de la misma forma hr no puede ser menor que yr.
  \brief Comprueba si un rectángulo tiene alguno de sus puntos en el interior de un triángulo rectángulo o viceversa.
  \param xt Posición en el eje x del pico de 90º del triángulo rectángulo.
  \param yt Posición en el eje y del pico de 90º del triángulo rectángulo.
  \param b Base del triángulo rectángulo.
  \param ht Altura del triángulo rectángulo.
  \param xr Posición en el eje x del rectángulo.
  \param yr Posición en el eje y del rectángulo.
  \param w Anchura del rectángulo.
  \param hr Altura del rectángulo.
  \return 1 si se solapan, 0 en caso contrario.
*/
int solape_tri_rect(double xt, double yt, double b, double ht, double xr, double yr, double w, double hr);

#endif
