#ifdef _WIN32
#include <windows.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#ifndef __APPLE__
#include <GL/gl.h>
#include <GL/glut.h>
#else
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#endif

#include <stdlib.h>
#include "collision.h"

/**
 * Crea un nuevo obstaculo.
 * @param: Coordenada x del centro.
 * @param: Coordenada y del centro.
 * @param: Tamano del obstaculo.
 */
Obstacle *newObstacle(int x, int y, int size) {
  
  Obstacle *o = (Obstacle*) malloc(sizeof(Obstacle));

  o->position[0] = x;
  o->position[1] = y;
  o->size = size;

  o->top = y; 
  o->bottom = y - size;
  o->left = x - size;
  o->right = x + size;

  return o;
}

/**
 * Determina si hay o no colision entre
 * la pelota y el obstaculo.
 * @param: Un objeto pelota.
 * @param: Un objeto obstaculo.
 * @return: 0 si no hay colision, 1 si la hay.
 */
int checkCollision(Ball *ball, Obstacle *obstacle) {

  double *ball_pos = ball->position;
  double *ball_prev = ball->prev_position;

  // Checkea si hay colision.
  if (ball_pos[0] >= obstacle->left && ball_pos[0] <= obstacle->right) {
    if (ball_pos[1] >= obstacle->bottom && ball_pos[1] <= obstacle->top) {
      return 1;
    }
  }
  return 0;
}

/**
 * Dibuja un obstaculo 
 * @param: Un objeto obstaculo.
 */
void drawObstacle(Obstacle *o) {
  
  glColorMaterial(GL_FRONT_AND_BACK, GL_EMISSION); // Importante para 
  glEnable(GL_COLOR_MATERIAL);                     // colorizar con iluminacion.

  glMatrixMode(GL_MODELVIEW);
  glTranslatef(o->position[0], o->position[1], o->size/2);
  glColor3f(0.0f,0.0f,5.0f);  
  glutSolidCube(o->size);
}

