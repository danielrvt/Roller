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

void drawFrame(Floor *floor) {

  glColorMaterial(GL_FRONT_AND_BACK, GL_EMISSION); // Importante para 
  glEnable(GL_COLOR_MATERIAL);                     // colorizar con iluminacion.

  int thickness = 5;
  
  int i;
  for(i=0; i<abs(floor->left-floor->right); i+=thickness) {
    
    // Fila superior
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    glTranslatef(floor->left + i, floor->top, thickness);
    glColor3f(0.0f,0.0f,5.0f);  
    glutSolidCube(5);
    glPopMatrix();
    glFlush();

    // Fila inferior
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    glTranslatef(floor->left + i, floor->bottom, thickness);
    glColor3f(0.0f,0.0f,5.0f);  
    glutSolidCube(5);
    glPopMatrix();
    glFlush();
  }

  for(i=0; i<abs(floor->bottom-floor->top); i+=thickness) {
    
    // Columna izquierda
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    glTranslatef(floor->left, floor->bottom + i, thickness);
    glColor3f(0.0f,0.0f,5.0f);  
    glutSolidCube(5);
    glPopMatrix();
    glFlush();

    // Columna derecha
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    glTranslatef(floor->right, floor->bottom + i, thickness);
    glColor3f(0.0f,0.0f,5.0f);  
    glutSolidCube(5);
    glPopMatrix();
    glFlush();
  }
}

/*
 * Dibuja el tablero.
 * @param: El tablero.
*/
void drawFloor(Floor *floor){

	glColor3f(0.0f,0.0f,0.0f);  
  glPushMatrix();

  //Comienza a dibujar el cuadrado
	glBegin(GL_QUADS);

	//Coordenadas del cuadrado
	glVertex2f(floor->left,floor->top);     //Esquina Superior izquierda
	glVertex2f(floor->left,floor->bottom);  //Esquina Inferior izquierda
 	glVertex2f(floor->right,floor->bottom); //Esquina Inferior derecha
	glVertex2f(floor->right,floor->top);    //Esquina Superior derecha
	
	//Deja de dibujar el cuadrado
	glEnd();

  glPopMatrix();
	glFlush();	

  // Dibuja los bordes.
  //parallelepiped_draw();
  drawFrame(floor);
};

   
