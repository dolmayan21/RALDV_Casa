//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s):Leon Del Villar Rubén Alejandro***//
//*************		Visual Studio 2015					******//
//*************											******//
//************************************************************//

//#include <gl/gl.h>     // The GL Header File
//#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
//#include <stdlib.h>
#include "Main.h"

float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float transX = 0.0f;
float transY = 0.0f;
float transZ = -5.0f;


void InitGL ( GLvoid )     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(float cS, float cI, float cD, float cIzq, float cF, float cB, float base, float altura, float profundidad)

{
	float b1, b2, a1, a2, mitad_base, mitad_altura, p1, p2, mitad_prof;
	float cS1, cS2, cS3;
	float cI1, cI2, cI3;
	float cD1, cD2, cD3;
	float cIzq1, cIzq2, cIzq3;
	float cF1, cF2, cF3;
	float cB1, cB2, cB3;

	cS1 = cS / 3; cS2 = cS1/3; cS3 = cS1/2;
	cI1 = cI / 4; cI2 = cI1/5; cI3 = cI1/4;
	cD1 = cD / 2; cD2 = cD1+0.3; cD3 = cD1+0.2;
	cIzq1 = cIzq / 3; cIzq2 = cIzq1/3; cIzq3 = cIzq1+0.1;
	cF1 = cF / 2; cF2 = cF1+0.3; cF3 = cF1+0.1;
	cB1 = cB / 3; cB2 = cB1 + 0.5; cB3 = cB1+0.2;

	mitad_base = base / 2;
	b1 = mitad_base;
	b2 = b1 - base;
	mitad_altura = altura / 2;
	a1 = mitad_base;
	a2 = a1 - altura;
	mitad_prof = profundidad / 2;
	p1 = mitad_prof;
	p2 = p1 - profundidad;

	GLfloat vertice [8][3] = {
				{b1 ,a2, p1},    //Coordenadas Vértice 0 V0
				{b2 ,a2, p1},    //Coordenadas Vértice 1 V1
				{b2 ,a2, p2},    //Coordenadas Vértice 2 V2
				{b1 ,a2, p2},    //Coordenadas Vértice 3 V3
				{b1 ,a1, p1},    //Coordenadas Vértice 4 V4
				{b1 ,a1, p2},    //Coordenadas Vértice 5 V5
				{b2 ,a1, p2},    //Coordenadas Vértice 6 V6
				{b2 ,a1, p1},    //Coordenadas Vértice 7 V7
				};

	//Cada una de las caras
		glBegin(GL_POLYGON);	//Front
			glColor3f(cF1,cF2,cF3);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glColor3f(cD1,cD2,cD3);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glColor3f(cB1,cB2,cB3);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glColor3f(cIzq1,cIzq2,cIzq3);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
	
		glColor3f(cI1,cI2,cI3);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glColor3f(cS1,cS2,cS3);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}


void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Poner Código Aquí.

	//glTranslatef(0.0, 0.0, -5.0);
	//prisma();

	glTranslatef(-6.0+transX,-6.0+transY,-5.0+transZ);	//	SIRVE PARA TRASLADAR EL OBJETO
	glRotatef(angleX, 1.0, 0.0, 0.0);			// SIRVE PARA ROTAR EL OBJETO

	glRotatef(angleY, 0.0, 1.0, 0.0);			// SIRVE PARA ROTAR EL OBJETO


	
	// CABEZA 
	glPushMatrix();
	// (0,0,0);
	glColor3f(0.545, 0.271, 0.075);
	prisma(0.3, 0.6, 0.8, 1.0, 0.1, 0.5, 6.0, 6.0, 6.0);
	glPopMatrix();


	// OJO IZQUIERDO
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(-1.0, 1.5, 3.0);
	prisma(0.3, 0.6, 0.8, 1.0, 0.1, 0.5, 1.0, 0.5, 0.5);
	glPopMatrix();

	// OJO DERECHO
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(1.0, 1.5, 3.0);
	prisma(0.3, 0.6, 0.8, 1.0, 0.1, 0.5, 1.0, 0.5, 0.5);
	glPopMatrix();

	// BOCA 
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.0, -1.5, 3.0);
	prisma(0.3, 0.6, 0.8, 1.0, 0.1, 0.5, 3.0, 1.5, 2.0);
	glPopMatrix();
	
	// NARIZ
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.0, 0.5, 3.0);
	prisma(0.3, 0.6, 0.8, 1.0, 0.1, 0.5, 1.0, 1.0, 2.0);
	glPopMatrix();


	// OREJA DERECHA 
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(-1.5, 3.5, 0.5);
	prisma(0.3, 0.6, 0.8, 1.0, 0.1, 0.5, 1.0, 1.5, 2.0);
	glPopMatrix();


	// OREJA IZQUIERDA 
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(1.5, 3.5, 0.5);
	prisma(0.3, 0.6, 0.8, 1.0, 0.1, 0.5, 1.0, 1.5, 2.0);
	glPopMatrix();

	// CUELLO
	glPushMatrix();
	glColor3f(0.412, 0.412, 0.412);
	glTranslatef(0.0, -2.5, -4.5);
	prisma(0.3, 0.6, 0.8, 1.0, 0.1, 0.5, 6.0, 3.5, 3.0);
	glPopMatrix();

	// CUERPO
	glPushMatrix();
	glColor3f(0.545, 0.271, 0.075);
	glTranslatef(0.0, -2.5, -12.5);
	prisma(0.3, 0.6, 0.8, 1.0, 0.1, 0.5, 8.0, 8.0, 13.0);
	glPopMatrix();

	// COLA
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.0, 2.5, -20.5);
	prisma(0.3, 0.6, 0.8, 1.0, 0.1, 0.5, 2.0, 7.0, 3.0);
	glPopMatrix();

	// PATA DELANTERA IZQUIERDA

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(-2.5, -8.0, -8.0);
	prisma(0.3, 0.6, 0.8, 1.0, 0.1, 0.5, 3.0, 6.0, 3.0);
	glPopMatrix();


	// PATA DELANTERA DERECHA

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(2.5, -8.0, -8.0);
	prisma(0.3, 0.6, 0.8, 1.0, 0.1, 0.5, 3.0, 6.0, 3.0);
	glPopMatrix();

	// PATA TRASERA IZQUIERDA

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(-2.5, -8.0, -17.0);
	
	prisma(0.3, 0.6, 0.8, 1.0, 0.1, 0.5, 3.0, 6.0, 3.0);
	glPopMatrix();

	// PATA TRASERA DERECHA

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(2.5, -8.0, -17.0);
	
	prisma(0.3, 0.6, 0.8, 1.0, 0.1, 0.5, 3.0, 6.0, 3.0);
	glPopMatrix();


	glPopMatrix();



	///				0.3, 0.6, 0.8, 1.0, 0.1, 0.5, 1.0, 0.5, 0.5

    glutSwapBuffers ( );
    //glFlush();
    // Swap The Buffers
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.1,20);	
	glFrustum (-0.5, 0.5,-0.5, 0.5, 0.5, 50.0); //Con esta función cambiamos la perspectiva
										//(10.0) máximo rango para la vista
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
		case 'W':
			transZ +=0.2f;
			printf("Posicion en Z: %f\n", transZ);
			break;
		case 's':
		case 'S':
			transZ -=0.2f;
			printf("Posicion en Z: %f\n", transZ);
			break;
		case 'l':
		case 'L':
			transX -=0.2f;
			break;
		case 'r':
		case 'R':
			transX +=0.2f;
			break;
		case 'd':
		case 'D':
			transY -= 0.2f;
			break;
		case 'u':
		case 'U':
			transY += 0.2f;
			break;

		case 't':
		case 'T':
			angleX += 10.0f;
			break;

		case 'q':
		case 'Q':
			angleY += 10.0f;
			break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;        
		default:        // Cualquier otra
		break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		angleX += 1.0f;
		break;
      //glutFullScreen ( ); // Full Screen Mode
      //break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		angleX -= 1.0f;
		break;
      //glutReshapeWindow ( 500, 500 ); // Cambiamos tamano de Ventana
      //break;
	case GLUT_KEY_LEFT:
		angleY += 1.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 1.0f;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 4"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}
