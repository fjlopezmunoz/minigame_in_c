#ifndef __Rafaga_H__
#define __Rafaga_H__

#include "Colisiones.h"
#include "Pantalla.h"
/**
 \mainpage Rafaga

La biblioteca rafaga contiene funciones que manejan rafagas de objetos 2D.
Permite hacer largas cadenas de balas (inclu�das en el m�dulo Colisiones.h), olvid�ndose de su creaci�n y manejo una a una.



*/
/**
   \file Rafaga.h
   \brief  Fichero de cabecera para poder usar las funciones de manejo de rafagas.
*/

/**
    \brief TDA Rafaga
 */
typedef struct Rafagarep * Rafaga;

/**
  \brief Crea una rafaga a la que a�adirle balas.

  Debe ser ejecutada antes que ninguna otra funci�n que haga uso de rafagas.
 */
Rafaga crea_rafaga();

/**
  \brief Libera la memoria reservada para la rafaga y sus balas.

  Debe ser ejecutada en �ltimo lugar. Si se ejecuta alguna funci�n que haga uso de rafagas despu�s de esta se producir� un error en tiempo de ejecuci�n.
  \param r La rafaga a liberar.
 */
void libera_rafaga( Rafaga r);

/**
  \brief Mueve todas las balas presentes en la rafaga cambiando su posici�n en funci�n de su propia velocidad.
  \param La rafaga a mover.
*/
void mueve_rafaga(Rafaga r);

/**
  \pre La bala debe de haber sido creada con su correspondiente funci�n y de igual manera la rafaga con crea_rafaga.
  \brief A�ade la bala a la rafaga de balas provista.
  \param r La rafaga sobre la que se trabaja.
  \param b La bala a insertar.
*/
void inserta_rafaga( Rafaga r, Bala b);

/**
  \pre No se debe ejecutar antes de Pantalla_Crea del m�dulo pantalla.Si se desea ver movimiento de la rafaga se debe ejecutar antes mueve_rafaga y debe tambi�n haber sido creada con crea_rafaga
  \brief Dibuja las balas en pantalla pertenecientes a la rafaga.
  \param r La rafaga a dibujar.
*/
void dibuja_rafaga(Rafaga r);

/**
  \pre  La rafaga debe de existir, cre�ndola con crea_rafaga.
  \brief Comprueba si hay colisi�n entre un objeto rectangular y todas las balas de la rafaga; si se ha producido, las balas que lo hayan hecho ser�n eliminadas de la rafaga.
  \param r La rafaga sobre la que se trabaja.
  \param x Posici�n en el eje x de la esquina superior izq. del rect�ngulo.
  \param y Posici�n en el eje y de la esquina superior izq. del rect�ngulo.
  \param w Anchura del rect�ngulo.
  \param h Altura del rect�ngulo.
  \return 1 si se ha producido alguna colisi�n, 0 en caso contrario.
*/
int colision_rafaga(Rafaga r, double x, double y, double w, double h);

/**
  \pre La rafaga debe de existir, cre�ndola con crea_rafaga.
  \brief Devuelve el n�mero de balas presente en la rafaga.
  \param r La rafaga sobre la que se trabaja.
  \return no. de balas en la rafaga.
*/
int longitud(Rafaga r);

#endif
