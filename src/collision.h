#include "ball.h"

typedef struct obstacle {
  int position[2];
  int size;
  
  int top;
  int bottom;
  int left;
  int right;
} Obstacle;

/**
 * Crea un nuevo obstaculo.
 * @param: Coordenada x del centro.
 * @param: Coordenada y del centro.
 * @param: Tamano del obstaculo.
 */
Obstacle *newObstacle(int x, int y, int size);

/**
 * Determina si hay o no colision entre
 * la pelota y el obstaculo.
 * @param: Un objeto pelota.
 * @param: Un objeto obstaculo.
 * @return: 0 si no hay colision, 1 si la hay.
 */
int checkCollision(Ball *ball, Obstacle *obstacle);

/**
 * Dibuja un obstaculo 
 * @param: Un objeto obstaculo.
 */
void drawObstacle(Obstacle *o);

