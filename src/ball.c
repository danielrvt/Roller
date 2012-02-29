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

#include "ball.h"
#include "util.h"

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
  glTranslatef(ball->position[0], ball->position[1], 1.5);
  glColor3f(0.0f,3.0f,3.0f);  
  glutSolidSphere(5.0, 10, 10);
};

/**
 * Actualiza la posicion de la pelota.
 * @param: La pelota.
 * @param: La matriz de transformacion de la marca
 * sobre la que esta la pelota.
 */
void updateBallPosition(Ball *ball, double trans[3][4]) {

  double omega[2];
  double wa, wb, wc;

  // Obtiene el angulo euleriano.
  get_angle(trans, &wa, &wb, &wc);
  
  omega[0] = wc;
  omega[1] = wb - GAME_FLAT_ANGLE;

  // Actualiza la posicion de la pelota.
  ball->position[0] = ball->position[0] + omega[0]*ball->speed; 
  ball->position[1] = ball->position[1] - omega[1]*ball->speed;
};

