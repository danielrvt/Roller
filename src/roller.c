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
#include <AR/gsub.h>
#include <AR/video.h>
#include <AR/param.h>
#include <AR/ar.h>
#include <tgmath.h>
#include "util.h"
#include "ball.h"

#define _USE_MATH_CONSTATS

#ifdef _WIN32
char			*vconf = "Data\\WDM_camera_flipV.xml";
#else
char			*vconf = "";
#endif

// Constantes globales.
int xsize, ysize;
int thresh = 100;
int count = 0;

// Directivas de configuracion de la
// camara.
char    *cparam_name = "Data/camera_para.dat";
ARParam cparam;

// Directivas de configuracion de la marca
char    *patt_name     = "Data/patt.hiro";
int     patt_id;
double  patt_width     = 80.0;
double  patt_center[2] = {0.0, 0.0};
double  patt_trans[3][4];

// Pelota del laberinto.
Ball ball;

// Prototipos.
static void init(void);
static void cleanup(void);
static void keyEvent( unsigned char key, int x, int y);
static void mainLoop(void);
static void draw( void );

int main(int argc, char **argv)
{
  // Inicializa la pelota en el centro del
  // escenario con una velocidad de 0.5.
  ball.position[0] = 0.0;
  ball.position[1] = 0.0;
  ball.speed = 0.5;

  // Inicializaciones generales.
	glutInit(&argc, argv);
	init();
  arVideoCapStart();
  argMainLoop( NULL, keyEvent, mainLoop );

	return (0);
}

static void   keyEvent( unsigned char key, int x, int y)
{
  /* quit if the ESC key is pressed */
  if( key == 0x1b ) {
    printf("*** %f (frame/sec)\n", (double)count/arUtilTimer());
      cleanup();
      exit(0);
  }
}

/* 
 * Ciclo del juego y de captura de
 * video.
 */
static void mainLoop(void)
{
  ARUint8         *dataPtr;
  ARMarkerInfo    *marker_info;
  int             marker_num;
  int             j, k;
  double omega[2];

  // Obtiene un cuadro de video de la camara.
  if( (dataPtr = (ARUint8 *)arVideoGetImage()) == NULL ) {
    arUtilSleep(2);
    return;
  }
  if( count == 0 ) arUtilTimerReset();
  count++;

  argDrawMode2D();
  argDispImage( dataPtr, 0,0 );

  // Detecta marcas en el cuadro de video.
  if( arDetectMarker(dataPtr, thresh, &marker_info, &marker_num) < 0 ) {
    cleanup();
    exit(0);
  }

  arVideoCapNext();

  // Checkea la confianza de la visibilidad
  // de la marca.
  k = -1;
  for( j = 0; j < marker_num; j++ ) {
    if( patt_id == marker_info[j].id ) {
        if( k == -1 ) k = j;
        else if( marker_info[k].cf < marker_info[j].cf ) k = j;
    }
  }
  if( k == -1 ) {
    argSwapBuffers();
    return;
  }
        
  // Obtiene la matriz de transformacion entre la marca y la
  // camara.
  arGetTransMat(&marker_info[k], patt_center, patt_width, patt_trans);

  // Actualiza la posicion de la pelota.
  updateBallPosition(&ball, patt_trans);

  draw();
  argSwapBuffers();
}

static void init( void ) {
  ARParam  wparam;
	
  // Abre el stream de video.
  if( arVideoOpen( vconf ) < 0 ) exit(0);

  // Encuentra el tamano de la ventana.
  if( arVideoInqSize(&xsize, &ysize) < 0 ) exit(0);
  printf("Image size (x,y) = (%d,%d)\n", xsize, ysize);

  // Setea los parametros iniciales de la camara.
  if( arParamLoad(cparam_name, 1, &wparam) < 0 ) {
      printf("Camera parameter load error !!\n");
      exit(0);
  }
  arParamChangeSize( &wparam, xsize, ysize, &cparam );
  arInitCparam( &cparam );
  printf("*** Camera Parameter ***\n");
  arParamDisp( &cparam );

  if( (patt_id=arLoadPatt(patt_name)) < 0 ) {
      printf("pattern load error !!\n");
      exit(0);
  }

  // Despliega la ventana.
  argInit( &cparam, 1.0, 0, 0, 0, 0 );
}

/**
 * Funcion de limpieza llamada cuando se termina
 * el programa.
 */
static void cleanup(void) {
  arVideoCapStop();
  arVideoClose();
  argCleanup();
}

/**
 * Dibuja una pelota sobre el marcador.
 */
static void draw( void ) {

  double    gl_para[16];
  GLfloat   mat_ambient[]     = {0.0, 0.0, 1.0, 1.0};
  GLfloat   mat_flash[]       = {0.0, 0.0, 1.0, 1.0};
  GLfloat   mat_flash_shiny[] = {50.0};
  GLfloat   light_position[]  = {100.0,-200.0,200.0,0.0};
  GLfloat   ambi[]            = {0.1, 0.1, 0.1, 0.1};
  GLfloat   lightZeroColor[]  = {0.9, 0.9, 0.9, 0.9};
  
  argDrawMode3D();
  argDraw3dCamera( 0, 0 );
  glClearDepth( 1.0 );
  glClear(GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
 
  // Carga matriz de transformacion de la camara.
  argConvGlpara(patt_trans, gl_para);
  glMatrixMode(GL_MODELVIEW);
  glLoadMatrixd( gl_para );

  // Setea condiciones de iluminacion.
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glLightfv(GL_LIGHT0, GL_AMBIENT, ambi);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, lightZeroColor);
  
  // Dibuja la pelota.
  drawBall(&ball);

  glDisable( GL_LIGHTING );
  glDisable( GL_DEPTH_TEST );
}
