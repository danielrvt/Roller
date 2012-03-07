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
};

