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
#include "floor.h"

void parallelepiped(int x1,  int x2,int y1, int y2, int y3, int y4) {
  
  glColor3f(0.0, 0.0, 1.0);
  glPointSize(2.0);
  glBegin(GL_LINE_LOOP);
  glVertex2i(x1,y1);
  glVertex2i(x2,y3);
  glVertex2i(x2,y4);
  glVertex2i(x1,y2);
  glEnd();
}

void parallelepiped_draw() {
  int x1=-100,x2=100,y1=-100,y2=100,y3=-100,y4=100;
     GLint i,n=5;
   for(i=0;i<n;i++)
   {
   parallelepiped(x1+i,x2+i,y1+i,y2+i,y3+i,y4+i);
   }
     
}

/*
 * Dibuja el tablero.
 * @param: El tablero.
*/
void drawFloor(Floor *floor){

	glColor3f(0.0f,0.0f,0.0f);  

  //Comienza a dibujar el cuadrado
	glBegin(GL_QUADS);

	//Coordenadas del cuadrado
	glVertex2f(floor->left,floor->top);     //Esquina Superior izquierda
	glVertex2f(floor->left,floor->bottom);  //Esquina Inferior izquierda
 	glVertex2f(floor->right,floor->bottom); //Esquina Inferior derecha
	glVertex2f(floor->right,floor->top);    //Esquina Superior derecha
	
	//Deja de dibujar el cuadrado
	glEnd();
	glFlush();	

  // Dibuja los bordes.
  parallelepiped_draw();
};

   
