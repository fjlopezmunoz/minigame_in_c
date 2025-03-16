#ifndef __Rafaga_H__
#define __Rafaga_H__

#include "Colisiones.h"
#include "Pantalla.h"
/**
 \mainpage Rafaga

La biblioteca rafaga contiene funciones que manejan rafagas de objetos 2D.
Permite hacer largas cadenas de balas (incluídas en el módulo Colisiones.h), olvidándose de su creación y manejo una a una.



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
  \brief Crea una rafaga a la que añadirle balas.

  Debe ser ejecutada antes que ninguna otra función que haga uso de rafagas.
 */
Rafaga crea_rafaga();

/**
  \brief Libera la memoria reservada para la rafaga y sus balas.

  Debe ser ejecutada en último lugar. Si se ejecuta alguna función que haga uso de rafagas después de esta se producirá un error en tiempo de ejecución.
  \param r La rafaga a liberar.
 */
void libera_rafaga( Rafaga r);

/**
  \brief Mueve todas las balas presentes en la rafaga cambiando su posición en función de su propia velocidad.
  \param La rafaga a mover.
*/
void mueve_rafaga(Rafaga r);

/**
  \pre La bala debe de haber sido creada con su correspondiente función y de igual manera la rafaga con crea_rafaga.
  \brief Añade la bala a la rafaga de balas provista.
  \param r La rafaga sobre la que se trabaja.
  \param b La bala a insertar.
*/
void inserta_rafaga( Rafaga r, Bala b);

/**
  \pre No se debe ejecutar antes de Pantalla_Crea del módulo pantalla.Si se desea ver movimiento de la rafaga se debe ejecutar antes mueve_rafaga y debe también haber sido creada con crea_rafaga
  \brief Dibuja las balas en pantalla pertenecientes a la rafaga.
  \param r La rafaga a dibujar.
*/
void dibuja_rafaga(Rafaga r);

/**
  \pre  La rafaga debe de existir, creándola con crea_rafaga.
  \brief Comprueba si hay colisión entre un objeto rectangular y todas las balas de la rafaga; si se ha producido, las balas que lo hayan hecho serán eliminadas de la rafaga.
  \param r La rafaga sobre la que se trabaja.
  \param x Posición en el eje x de la esquina superior izq. del rectángulo.
  \param y Posición en el eje y de la esquina superior izq. del rectángulo.
  \param w Anchura del rectángulo.
  \param h Altura del rectángulo.
  \return 1 si se ha producido alguna colisión, 0 en caso contrario.
*/
int colision_rafaga(Rafaga r, double x, double y, double w, double h);

/**
  \pre La rafaga debe de existir, creándola con crea_rafaga.
  \brief Devuelve el número de balas presente en la rafaga.
  \param r La rafaga sobre la que se trabaja.
  \return no. de balas en la rafaga.
*/
int longitud(Rafaga r);

#endif
