#ifndef __Colisiones_H__
#define __Colisiones_H__

#include "Pantalla.h"

/**
\mainpage Colisiones

La biblioteca colisiones contiene funciones de colisiones entre objetos 2D.
Permite la escritura de programas que tengan colisiones entre una gama de figuras geom�tricas aqu�
detalladas, abstray�ndose de los c�lculos a realizar para conocer si colisionan.
Adem�s a�ade el objeto bala al que se le pueden aplicar las funciones de colisiones aqu� presentes
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
  \brief Crea una bala y la dota de una posici�n y velocidad escogidas por el usuario.

  Debe ser ejecutada antes que ninguna otra funci�n que haga uso de balas

  \param x Posici�n en el eje x en puntos.
  \param y Posici�n en el eje y en puntos.
  \param w Anchura de la bala en puntos.
  \param h Altura de la bala en puntos.
  \return La bala creada.
 */
Bala crea_bala( double x, double y, double vx, double vy );

/**
  \brief Libera la memoria reservada para la bala y sus recursos asociados.

  Debe ser ejecutada en �ltimo lugar. Si se ejecuta alguna funci�n que haga uso de balas despu�s de esta se producir� un error en tiempo de ejecuci�n.
 */
void libera_bala( Bala b );

/**
  \brief Recupera la posici�n en el eje x de la bala.
  \param La bala cuya posici�n desea conocer.
  \return La posici�n en el eje x de la bala.
*/
double get_x_bala( Bala b );

/**
  \brief Recupera la posici�n en el eje y de la bala.
  \param La bala cuya posici�n desea conocer.
  \return La posici�n en el eje y de la bala.
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
  \return La imagen de la bala cuyo tipo de dato proporciona el m�dulo Pantalla.h .
*/
Imagen get_imagen_bala( Bala b );

/**
  \brief Mueve la bala cambiando su posici�n en funci�n de su propia velocidad.
  \param La bala a mover.
*/
void mueve_bala( Bala b );

/**
  \pre w no puede ser menor que x y h no puede ser menor que y
  \brief Comprueba si un punto se encuentra en el interior de un rect�ngulo, ambos son concretados por el usuario.
  \param x Posici�n en el eje x de la esquina superior izq. del rect�ngulo.
  \param y Posici�n en el eje y de la esquina superior izq. del rect�ngulo.
  \param w Anchura del rect�ngulo.
  \param h Altura del rect�ngulo.
  \param px Posici�n en el eje x del punto.
  \param py Posici�n en el eje y del punto.
  \return 1 si el punto se encuentra dentro, 0 en caso contrario.
*/
int dentro_rectangulo( int x, int y, int w, int h, int px, int py );

/**
  \brief Calcula la distancia entre dos puntos dados por el usuario.
  \param x1 Posici�n en el eje x del primer punto.
  \param y1 Posici�n en el eje y del primer punto.
  \param x2 Posici�n en el eje x del segundo punto.
  \param y2 Posici�n en el eje y del segundo punto.
  \return La distancia entre ambos puntos.
*/
double distancia_punto_punto( double x1, double y1, double x2, double y2 );

/**
  \pre r1 y r2 no pueden ser menores que 0
  \brief Comprueba si dos circunferencias contienen alguno de sus puntos en el interior de la otra.
  \param x1 Posici�n en el eje x del centro de la primera circunferencia.
  \param y1 Posici�n en el eje y del centro de la primera circunferencia.
  \param r1 Longitud del radio de la primera circunferencia.
  \param x2 Posici�n en el eje x del centro de la segunda circunferencia.
  \param y2 Posici�n en el eje y del centro de la segunda circunferencia.
  \param r2 Longitud del radio de la segunda circunferencia.
  \return 1 si las circunferencias se solapan, 0 en caso contrario.
*/
int solape_circunferencias( int x1, int y1, int r1, int x2, int y2, int r2 );

/**
  \pre w no puede ser menor que xr, h no puede ser menor que yr y r no puede ser menor que 0
  \brief Comprueba si un rect�ngulo tiene alguno de sus puntos en el interior de una circunferencia o viceversa.
  \param xr Posici�n en el eje x del rect�ngulo.
  \param yr Posici�n en el eje y del rect�ngulo
  \param w Anchura del rect�ngulo.
  \param h Altura del rect�ngulo.
  \param xc Posici�n en el eje x del centro de la circunferencia.
  \param yc Posici�n en el eje y del centro de la circunferencia.
  \param r Longitud del radio de la circunferencia.
  \return 1 si ambos se solapan, 0 en caso contrario.
*/
int solaperectcir( int xr , int yr , int w , int h , int xc , int yc , int r );

/**
  \pre w1 y w2 no pueden ser menores que x1 y x2 respectivamente, de la misma forma h1 y h2 no pueden ser menores que y1 e y2.
  \brief Comprueba si un rect�ngulo tiene alguno de sus puntos en el interior de otro.
  \param x1 Posici�n en el eje x del primer rect�ngulo.
  \param y1 Posici�n en el eje y del primer rect�ngulo
  \param w1 Anchura del primer rect�ngulo.
  \param h1 Altura del primer rect�ngulo.
  \param x2 Posici�n en el eje x del segundo rect�ngulo.
  \param y2 Posici�n en el eje y del segundo rect�ngulo
  \param w2 Anchura del segundo rect�ngulo.
  \param h2 Altura del segundo rect�ngulo.
  \return 1 si los dos rect�ngulos se solapan, 0 en caso contrario.
*/
int solaperect( int x1 , int y1 , int w1 , int h1 , int x2 , int y2 , int w2 , int h2 );

/**
  \pre Se debe haber ejecutado Pantalla_crea del m�dulo pantalla.
  \brief Dibuja en pantalla la bala provista por el usuario.
  \param b Bala a dibujar.
*/
void dibuja_bala(Bala b);

/**
  \pre w1 y w2 no pueden ser menores que x1 y x2 respectivamente, de la misma forma h1 y h2 no pueden ser menores que y1 e y2.
  \brief Comprueba si un la bala se solapa con un objeto rectangular.
  \param x Posici�n en el eje x del rect�ngulo.
  \param y Posici�n en el eje y del rect�ngulo
  \param w Anchura del rect�ngulo.
  \param h Altura del rect�ngulo.
  \return 1 si la bala colisiona, 0 en caso contrario.
*/
int colision_bala( Bala b, double x, double y, double w, double h );

/**
  \pre w no puede ser menores que xr, de la misma forma hr no puede ser menor que yr.
  \brief Comprueba si un rect�ngulo tiene alguno de sus puntos en el interior de un tri�ngulo rect�ngulo o viceversa.
  \param xt Posici�n en el eje x del pico de 90� del tri�ngulo rect�ngulo.
  \param yt Posici�n en el eje y del pico de 90� del tri�ngulo rect�ngulo.
  \param b Base del tri�ngulo rect�ngulo.
  \param ht Altura del tri�ngulo rect�ngulo.
  \param xr Posici�n en el eje x del rect�ngulo.
  \param yr Posici�n en el eje y del rect�ngulo.
  \param w Anchura del rect�ngulo.
  \param hr Altura del rect�ngulo.
  \return 1 si se solapan, 0 en caso contrario.
*/
int solape_tri_rect(double xt, double yt, double b, double ht, double xr, double yr, double w, double hr);

#endif
