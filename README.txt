Autores
-------

Proyecto desarrollado en la Universidad Simon Bolivar por:

    * Daniel Rodriguez del Villar Trimarchi 06-40234
    * Daniela Velasquez Conde               06-40433

Para el curso de Realidad Aumentada.

Sobre el proyecto
-----------------

Juego de laberinto hecho en realidad aumentada con el uso
de ARToolKit. Requiere de la maraca HIRO.

Instalacion y ejecucion
-----------------------

Para instalar el juego deben seguirse los siguiente pasos:

  1) Compilar ARToolKit: 
        
       a. Entrar al directorio: "roller/lib/ARTooKit/".
       b. Ejecutar "./Configure".
       c. Ejecutar "make".

     Al compilarse ARToolKit se debe generar algunos binarios en:
     "roller/lib/ARToolKit/bin/". Para mas informacion sobre la
     instalacion de ARToolKit referirse a:

      * http://simocap.wordpress.com/2010/06/18/tutorial-instalacion-y-ejecucion-de-artoolkit-en-ubuntu/
      * http://www.hitl.washington.edu/artoolkit/documentation/usersetup.htm

   2) Compilar el juego:
      
        a. Entrar al directorio: "roller/".
        b. Ejecutar "make".

      Al compilarse el juego se debe crear el ejecutable: "roller/bin/roller".

   3) Ejecutar el juego:
        
        a. Entrar al directorio: "roller/bin/".
        b Ejecutar "./roller".

      Esto debe desplegar una ventana con imagenes de la camara. Para 
      jugar se debe tener la marca HIRO y hacerla visible a la camara.


