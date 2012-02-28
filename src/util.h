#ifndef UTIL_H
#define UTIL_H

// Angulo de inclinacion neutro de la marca. En este
// angulo, la pelota no rueda. Este angulo equivale
// a unos 30° de inclinacion para alcanzar la 
// estabilidad vertical.
#define GAME_FLAT_ANGLE 2.0943951023931953   // 120°


/**
 * Obtiene la matriz de rotacion.
 * @param: Angulo euleriano a.
 * @param: Angulo euleriano b.
 * @param: Angulo euleriano c.
 * @param: Una matriz vacia[3][4] (out).
 */
void   get_rot( double a, double b , double c, double trans[3][4] );

/**
 * Retorna la velocidad angular.
 * @param: Matriz de transformacion entre la marca y la camara.
 * @param: Angulo de inclinacion horizontal. (out)
 * @param: Angulo de inclinacion vertical. (out)
 */
void get_ball_omega(double trans[3][4], double *wx, double *wy);

/**
 * Obtiene el angulo euleriano.
 * @param: Una matriz de transformacion.
 * @param: Angulo euleriano a* (out).
 * @param: Angulo euleriano b* (out).
 * @param: Angulo euleriano c* (out).
 */
int    get_angle( double trans[3][4], double *wa, double *wb, double *wc );

/**
 * Transforma un grado de radianes a decimales.
 * @param: Grado en radianes.
 */
double toDegree(double rad);

/**
 * Obtiene el angulo de inclinacion de la marca
 * en grados. 
 * La marca forma 0° al estar paralela al suelo, 
 * y 90° al estar paralela a la camara. Esto es
 * yangle.
 * La marca forma 0° al estar paralela a la camara
 * y 180° al estar mirando hacia los lados. Cuando
 * mira hacia la derecha los grados son - y cuando
 * mira hacia la izquierda los grados son +. Esto
 * es xangle.
 */
void get_user_angle(double trans[3][4], double *xangle, double *yangle);

double get_height( double x, double y, double trans[3][4], double boundary[3][2] );

/* RJS */
int
wrappedDropOntoMap(char *where, float *inPt, float *outPt);

#endif
