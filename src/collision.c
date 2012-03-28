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
 * Actualiza la posicion de la pelota de acuerdo al choque.
 * @param: Pelota.
 * @param: Obstaculo.
 */
void bounceBall(Ball *ball, Obstacle *o) {

  // Esta en la altura de choque.
  if (ball->position[1] >= o->bottom && ball->position[1] <= o->top) {

    if(ball->position[0]>=o->left && ball->position[0]<=o->right){
    
     if(ball->prev_position[0]>=o->right){
       ball->position[0] = ball->prev_position[0] + 10;
     }
    if(ball->prev_position[0]<=o->left){
       ball->position[0] = ball->prev_position[0] - 10;   
    } 
   }
  }

  // Esta en la amplitud de choque.
  if (ball->position[0] >= o->left && ball->position[0] <= o->right) {
    
    if(ball->position[1]>=o->bottom && ball->position[1]<=o->top){    
		  //Choca por arriba
		  if(ball->prev_position[1]>=o->top){
		    ball->position[1] = ball->prev_position[1] + 10;
		  }
		  //Choca por debajo
		  if(ball->prev_position[1]<=o->bottom){
		    ball->position[1] = ball->prev_position[1] - 10;   
		  }
   } 
  } 
}

/**
 * Dibuja un obstaculo 
 * @param: Un objeto obstaculo.
 * @param: La posicion del objeto a dibujar en la lista.
 * @param: La posicion del objeto goal en la lista.
 */
void drawObstacle(Obstacle *o, int i, int goal) {
  
  glColorMaterial(GL_FRONT_AND_BACK, GL_EMISSION); // Importante para 
  glEnable(GL_COLOR_MATERIAL);                     // colorizar con iluminacion.

  glPushMatrix();

  glMatrixMode(GL_MODELVIEW);
  glTranslatef(o->position[0], o->position[1], o->size/2);
  
  if(i == goal){
   glColor3f(0.0f,3.0f,0.0f);  
  }  
  else{
   glColor3f(0.0f,0.0f,5.0f);  
  }
  glutSolidCube(o->size);

  glPopMatrix();
  glFlush();
  
}

/**
 * Dibuja una lista de obstaculos 
 * @param: Una lista de objetos tipo obstaculo.
 * @param: La cantidad de objetos en la lista.
 * @param: La posicion del objeto goal en la lista.
 */
void drawObstacleList(Obstacle *olist, int size, int goal) {
  
  int i;
	  for (i=0; i < size; i++){
    drawObstacle(&olist[i],i,goal);
  }
}

