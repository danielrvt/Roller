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
 * Actualiza la posicion de la pelota de acuerdo al choque.
 * @param: Pelota.
 * @param: Obstaculo.
 */
void bounceBall(Ball *ball, Obstacle *o);

/**
 * Dibuja un obstaculo 
 * @param: Un objeto obstaculo.
 * @param: La posicion del objeto a dibujar en la lista.
 * @param: La posicion del objeto goal en la lista.
 */
void drawObstacle(Obstacle *o, int i, int goal);

/**
 * Dibuja una lista de obstaculos 
 * @param: Una lista de objetos tipo obstaculo.
 * @param: La cantidad de objetos en la lista.
 * @param: La posicion del objeto goal en la lista.
 */
void drawObstacleList(Obstacle *olist, int size, int goal);
