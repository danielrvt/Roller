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

#include "util.h"
#include "ball.h"

/**
 * Dibuja la pelota.
 * @param: La pelota.
 * @param: La matriz de transformacion de la marca
 * sobre la que esta la pelota.
 */
void drawBall(Ball *ball){

  glColorMaterial(GL_FRONT_AND_BACK, GL_EMISSION); // Importante para 
  glEnable(GL_COLOR_MATERIAL);                     // colorizar con iluminacion.

  glMatrixMode(GL_MODELVIEW);
  glTranslatef(ball->position[0], ball->position[1], 15);
  glColor3f(0.0f,3.0f,3.0f);  
  glutSolidSphere(ball->radius, 10, 10);
};

/**
 * Actualiza la posicion de la pelota.
 * @param: La pelota.
 * @param: La matriz de transformacion de la marca
 * sobre la que esta la pelota.
 */
void updateBallPosition(Ball *ball, double trans[3][4], Floor floor) {

  double omega[2];
  double wa, wb, wc;
  double nextX;
  double nextY;

  // Obtiene el angulo euleriano.
  get_angle(trans, &wa, &wb, &wc);
  
  omega[0] = wc;
  omega[1] = wb - GAME_FLAT_ANGLE;

  // Proxima posicion de la pelota en x y en y.
  nextX = ball->position[0] + omega[0]*ball->speed;
  nextY = ball->position[1] - omega[1]*ball->speed;

  // Checkea que no se salga por la izquierda ni la derecha.
  if (nextX - ball->radius > floor.left && nextX + ball->radius < floor.right){
    ball->position[0] = nextX; 
  }
  
  // Checkea que no se salga por arriba ni por abajo.
  if (nextY - ball->radius < floor.top && nextY + ball->radius > floor.bottom){
    ball->position[1] = nextY;
  }
};

