#ifndef __Ejercito_H__
#define __Ejercito_H__

#include "Rafaga.h"
#include "Pantalla.h"
#include "Colisiones.h"
/**
 \mainpage Ejercito

La biblioteca ejercito contiene funciones que manejan conuntos de enemigos 2D.
Permite automatizar su creación,movimientos..., simplificando mucho, la tarea de gestionar múltiples enemigos.
Además también incluye el TDA héroe basado en un tanque con forma hexagonal y funciones de manejo de este mismo para ponerse a prueba con el ejercito.



*/
/**
   \file Ejercito.h
   \brief  Fichero de cabecera para hacer uso de funciones que simplifiquen el manejo de varios enemigos.
*/

/**
    \brief TDA Rafaga
 */
typedef struct ejercitorep * ejercito;

/**
    \brief TDA heroe
 */
typedef struct heroerep * heroe;

/**
  \pre Debe ser ejecutado antes Pantalla_crea del módulo Pantalla.h
  \brief Crea un ejercito con un tamaño máximo temporal en memoria provisto por el usuario.

  Debe ser ejecutada antes que ninguna otra función que haga uso de ejercitos.

  \param N tamaño máximo temporal en memoria provisto por el usuario.
  \return Ejercito creado.
 */
ejercito crea_ejercito(int N);

/**
  \brief Libera la memoria reservada para el ejercito y sus enemigos.

  Debe ser ejecutada en último lugar. Si se ejecuta alguna función que haga uso ejercitos después de esta se producirá un error en tiempo de ejecución.
  \param e Ejercito a liberar.
 */
void libera_ejercito(ejercito e);

/**
  \pre El ejercito debe de haber sido creado con crea_ejercito.
  \brief Inserta un enemigo rectangular al ejército y en caso de igualar el máximo, dobla el tamaño de su memoria para la cabida de más enemigos.
  \param e El ejercito sobre el que se trabaja.
  \param x Posición en el eje x de la esquina superior izq. del enemigo.
  \param y Posición en el eje y de la esquina superior izq. del enemigo.
  \param w Anchura del rectángulo.
  \param h Altura del rectángulo.
*/
void inserta_enemigo(ejercito e, double x, double y, double w, double h);

/**
  \brief Mueve todos los enemigos presentes en el ejercito cambiando su posición en función de su propia velocidad
        (velocidad solo positiva en sentido descendente), haciendo que reboten con las paredes horizontales y que
        cuando llegue al fondo se elimine.
  \param El ejercito a mover.
*/
void mueve_ejercito(ejercito e);

/**
  \pre No se debe ejecutar antes de Pantalla_Crea del módulo pantalla.Si se desea ver movimiento del ejercito se debe ejecutar antes mueve_ejercito y debe también haber sido creado con crea_ejercito.
  \brief Dibuja en pantalla todos los enemigos vivos.
  \param e El ejercito a dibujar.
*/
void dibuja_ejercito( ejercito e );

/**
  \brief Comprueba si hay colisión entre un objeto rectangular y todos los enemigos del ejercito; si se ha producido, los enemigos que lo hayan hecho serán eliminadas del ejercito.
  \param e El ejercito sobre el que se trabaja.
  \param x Posición en el eje x de la esquina superior izq. del rectángulo.
  \param y Posición en el eje y de la esquina superior izq. del rectángulo.
  \param w Anchura del rectángulo.
  \param h Altura del rectángulo.
  \return 1 si se ha producido alguna colisión, 0 en caso contrario.
*/
int colision_ejercito_objeto( ejercito e, double x, double y, double w, double h );

/**
  \brief Comprueba si hay colisión entre todas las balas de una rafaga y todos los enemigos del ejercito; si se ha producido, los enemigos y las balas que lo hayan hecho serán eliminados.
  \param e El ejercito sobre el que se trabaja.
  \param r La rafaga sobre la que se trabaja.
  \return 1 si se ha producido alguna colisión, 0 en caso contrario.
*/
int colision_ejercito_rafaga( ejercito e, Rafaga r );

/**
  \brief Comprueba si hay colisión entre el héroe hexagonal y todos los enemigos del ejercito; si se ha producido, los enemigos que lo hayan hecho serán eliminados del ejercito.
  \param e El ejercito sobre el que se trabaja.
  \param h El heroe.
  \return 1 si se ha producido alguna colisión, 0 en caso contrario.
*/
int colision_ejercito_heroe(ejercito e, heroe h);

/**
  \pre Debe ser ejecutado antes Pantalla_crea del módulo Pantalla.h
  \brief Crea un heroe con una posición y velocidad dadas por el usuario.

  Debe ser ejecutada antes que ninguna otra función que haga uso de rafagas.
 */
heroe crea_heroe(double x, double y, double vx);

/**
  \brief Libera la memoria reservada para el héroe rafaga y sus recursos asociados.

  Debe ser ejecutada en último lugar. Si se ejecuta alguna función que haga uso del heroe después de esta se producirá un error en tiempo de ejecución.
  \param h heroe a liberar.
 */
void libera_heroe(heroe h);

/**
  \brief Mueve el heroe cambiando su posición horizontal en función de su propia velocidad,

  \param El heroe a mover.
*/
void mueve_heroe(heroe h);

/**
  \pre No se debe ejecutar antes de Pantalla_Crea del módulo pantalla.Si se desea ver movimiento del heroe se debe ejecutar antes mueve_heroe y debe también haber sido creado con crea_heroe.
  \brief Dibuja en pantalla al heroe.
  \param h El heroe a dibujar.
*/
void dibuja_heroe(heroe h);

/**
  \brief Actualiza la velocidad en el eje x del heroe.
  \param El heroe cuya velocidad desea cambiar.
  \param La velocidad que quiere darle al heroe.
*/
void set_heroe_vx(heroe h, double vx);

/**
  \brief Recupera la posición en el eje x de la esquina más alta izquierda del heroe.
  \param El heroe cuya posición desea conocer.
  \return La posición en el eje x de la esquina más alta izquierda del heroe.
*/
double heroe_get_xr_left(heroe h);

/**
  \brief Recupera la posición en el eje y de la esquina más alta izquierda del heroe.
  \param El heroe cuya posición desea conocer.
  \return La posición en el eje y de la esquina más alta izquierda del heroe.
*/
double heroe_get_yr_up(heroe h);
/**
  \brief Recupera la longitud horizontal del heroe.
  \param El heroe cuyo dato desea conocer.
  \return La anchura en el eje x del heroe.
*/
double heroe_get_anchotanque(heroe h);

#endif

