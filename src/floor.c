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

#include "floor.h"
#include "util.h"

/*
 * Dibuja el tablero.
 * @param: El tablero.
*/
void drawFloor(Floor *floor){

	glColor3f(1.0f,1.0f,0.0f);  
	//Comienza a dibujar el cuadrado
	glBegin(GL_QUADS);

	//Coordenadas del cuadrado
	glVertex2f(floor->coord[0],floor->coord[1]); //Esquina Superior izquierda
	glVertex2f(floor->coord[0],floor->coord[2]); //Esquina Inferior izquierda
 	glVertex2f(floor->coord[3],floor->coord[2]); //Esquina Inferior derecha
	glVertex2f(floor->coord[3],floor->coord[1]); //Esquina Superior derecha
	
	//Deja de dibujar el cuadrado
	glEnd();
	glFlush();	
	
};

