#ifndef UTIL_H
#define UTIL_H

/**
 * Obtiene la matriz de rotacion.
 * @param: Angulo euleriano a.
 * @param: Angulo euleriano b.
 * @param: Angulo euleriano c.
 * @param: Una matriz vacia[3][4] (out).
 */
void   get_rot( double a, double b , double c, double trans[3][4] );

/**
 * Obtiene el angulo euleriano.
 * @param: Una matriz de transformacion.
 * @param: Angulo euleriano a* (out).
 * @param: Angulo euleriano b* (out).
 * @param: Angulo euleriano c* (out).
 */
int    get_angle( double trans[3][4], double *wa, double *wb, double *wc );
double get_height( double x, double y, double trans[3][4], double boundary[3][2] );

/* RJS */
int
wrappedDropOntoMap(char *where, float *inPt, float *outPt);

#endif
