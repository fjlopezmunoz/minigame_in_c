#ifndef __Ejercito_H__
#define __Ejercito_H__

#include "Rafaga.h"
#include "Pantalla.h"
#include "Colisiones.h"
/**
 \mainpage Ejercito

La biblioteca ejercito contiene funciones que manejan conuntos de enemigos 2D.
Permite automatizar su creaci�n,movimientos..., simplificando mucho, la tarea de gestionar m�ltiples enemigos.
Adem�s tambi�n incluye el TDA h�roe basado en un tanque con forma hexagonal y funciones de manejo de este mismo para ponerse a prueba con el ejercito.



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
  \pre Debe ser ejecutado antes Pantalla_crea del m�dulo Pantalla.h
  \brief Crea un ejercito con un tama�o m�ximo temporal en memoria provisto por el usuario.

  Debe ser ejecutada antes que ninguna otra funci�n que haga uso de ejercitos.

  \param N tama�o m�ximo temporal en memoria provisto por el usuario.
  \return Ejercito creado.
 */
ejercito crea_ejercito(int N);

/**
  \brief Libera la memoria reservada para el ejercito y sus enemigos.

  Debe ser ejecutada en �ltimo lugar. Si se ejecuta alguna funci�n que haga uso ejercitos despu�s de esta se producir� un error en tiempo de ejecuci�n.
  \param e Ejercito a liberar.
 */
void libera_ejercito(ejercito e);

/**
  \pre El ejercito debe de haber sido creado con crea_ejercito.
  \brief Inserta un enemigo rectangular al ej�rcito y en caso de igualar el m�ximo, dobla el tama�o de su memoria para la cabida de m�s enemigos.
  \param e El ejercito sobre el que se trabaja.
  \param x Posici�n en el eje x de la esquina superior izq. del enemigo.
  \param y Posici�n en el eje y de la esquina superior izq. del enemigo.
  \param w Anchura del rect�ngulo.
  \param h Altura del rect�ngulo.
*/
void inserta_enemigo(ejercito e, double x, double y, double w, double h);

/**
  \brief Mueve todos los enemigos presentes en el ejercito cambiando su posici�n en funci�n de su propia velocidad
        (velocidad solo positiva en sentido descendente), haciendo que reboten con las paredes horizontales y que
        cuando llegue al fondo se elimine.
  \param El ejercito a mover.
*/
void mueve_ejercito(ejercito e);

/**
  \pre No se debe ejecutar antes de Pantalla_Crea del m�dulo pantalla.Si se desea ver movimiento del ejercito se debe ejecutar antes mueve_ejercito y debe tambi�n haber sido creado con crea_ejercito.
  \brief Dibuja en pantalla todos los enemigos vivos.
  \param e El ejercito a dibujar.
*/
void dibuja_ejercito( ejercito e );

/**
  \brief Comprueba si hay colisi�n entre un objeto rectangular y todos los enemigos del ejercito; si se ha producido, los enemigos que lo hayan hecho ser�n eliminadas del ejercito.
  \param e El ejercito sobre el que se trabaja.
  \param x Posici�n en el eje x de la esquina superior izq. del rect�ngulo.
  \param y Posici�n en el eje y de la esquina superior izq. del rect�ngulo.
  \param w Anchura del rect�ngulo.
  \param h Altura del rect�ngulo.
  \return 1 si se ha producido alguna colisi�n, 0 en caso contrario.
*/
int colision_ejercito_objeto( ejercito e, double x, double y, double w, double h );

/**
  \brief Comprueba si hay colisi�n entre todas las balas de una rafaga y todos los enemigos del ejercito; si se ha producido, los enemigos y las balas que lo hayan hecho ser�n eliminados.
  \param e El ejercito sobre el que se trabaja.
  \param r La rafaga sobre la que se trabaja.
  \return 1 si se ha producido alguna colisi�n, 0 en caso contrario.
*/
int colision_ejercito_rafaga( ejercito e, Rafaga r );

/**
  \brief Comprueba si hay colisi�n entre el h�roe hexagonal y todos los enemigos del ejercito; si se ha producido, los enemigos que lo hayan hecho ser�n eliminados del ejercito.
  \param e El ejercito sobre el que se trabaja.
  \param h El heroe.
  \return 1 si se ha producido alguna colisi�n, 0 en caso contrario.
*/
int colision_ejercito_heroe(ejercito e, heroe h);

/**
  \pre Debe ser ejecutado antes Pantalla_crea del m�dulo Pantalla.h
  \brief Crea un heroe con una posici�n y velocidad dadas por el usuario.

  Debe ser ejecutada antes que ninguna otra funci�n que haga uso de rafagas.
 */
heroe crea_heroe(double x, double y, double vx);

/**
  \brief Libera la memoria reservada para el h�roe rafaga y sus recursos asociados.

  Debe ser ejecutada en �ltimo lugar. Si se ejecuta alguna funci�n que haga uso del heroe despu�s de esta se producir� un error en tiempo de ejecuci�n.
  \param h heroe a liberar.
 */
void libera_heroe(heroe h);

/**
  \brief Mueve el heroe cambiando su posici�n horizontal en funci�n de su propia velocidad,

  \param El heroe a mover.
*/
void mueve_heroe(heroe h);

/**
  \pre No se debe ejecutar antes de Pantalla_Crea del m�dulo pantalla.Si se desea ver movimiento del heroe se debe ejecutar antes mueve_heroe y debe tambi�n haber sido creado con crea_heroe.
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
  \brief Recupera la posici�n en el eje x de la esquina m�s alta izquierda del heroe.
  \param El heroe cuya posici�n desea conocer.
  \return La posici�n en el eje x de la esquina m�s alta izquierda del heroe.
*/
double heroe_get_xr_left(heroe h);

/**
  \brief Recupera la posici�n en el eje y de la esquina m�s alta izquierda del heroe.
  \param El heroe cuya posici�n desea conocer.
  \return La posici�n en el eje y de la esquina m�s alta izquierda del heroe.
*/
double heroe_get_yr_up(heroe h);
/**
  \brief Recupera la longitud horizontal del heroe.
  \param El heroe cuyo dato desea conocer.
  \return La anchura en el eje x del heroe.
*/
double heroe_get_anchotanque(heroe h);

#endif

