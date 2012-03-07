#include "floor.h"

typedef struct Ball {
  double position[2];
  double speed;
  double radius;
} Ball;

/**
 * Dibuja la pelota.
 * @param: La pelota.
 * @param: La matriz de transformacion de la marca
 * sobre la que esta la pelota.
 */
void drawBall(Ball *ball);

/**
 * Actualiza la posicion de la pelota.
 * @param: La pelota.
 * @param: La matriz de transformacion de la marca
 * sobre la que esta la pelota.
 */
void updateBallPosition(Ball *ball, double trans[3][4], Floor floor);


