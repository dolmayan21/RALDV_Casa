//Semestre 2018 - 2
//************************************************************//
//*************************************************************//
//************** Alumno (s): León del Villar Rubén Alejandro***//
//************	Visual Studio 2015		************************//
//************************************************************//
#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;



int nucleo = 0;
int proton1 = 0;
int proton2 = 0;
int proton3 = 0;
int proton4 = 0;



float camaraZ = 0.0;
float camaraX = 0.0;

GLfloat SunDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position


void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);
	
	glLightfv(GL_LIGHT1,GL_DIFFUSE,SunDiffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, SunSpecular);


}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX, 0.0, -5.0 + camaraZ);			//camara



	
	//	           ATOMO

	// NUCLEO

	glPushMatrix();
	glRotatef(nucleo, 0.0, 1.0, 0.0);	//El nucleo gira sobre su eje
	//glColor3f(1.0, 0.0, 0.0);


	glutSolidSphere(2, 12, 12);
	glPushMatrix();
	glTranslatef(-5.0, 0.0, 0.0);
	glRotatef(proton1 + 40, 0.0, 1.0, 0.0);	//El nucleo gira sobre su eje
	//glColor3f(0.0, 1.0, 0.0);
	glutSolidSphere(1, 12, 12);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotatef(225.0, 0.0, 0.0, 1.0);
	glRotatef(proton2, 1.0, 0.0, 0.0);	//El nucleo gira sobre su eje
	glTranslatef(0.0, 5.0, 0.0);
	//glColor3f(0.0, 1.0, 0.0);
	glutSolidSphere(1, 12, 12);
	glPopMatrix();

	glPushMatrix();
	glRotatef(135.0, 0.0, 0.0, 1.0);
	glRotatef(proton3 + 40, 1.0, 0.0, 0.0);	//El nucleo gira sobre su eje
	glTranslatef(0.0, 5.0, 0.0);
	//glColor3f(1.0, 0.0, 0.0);
	glutSolidSphere(1, 12, 12);
	glPopMatrix();

	glPushMatrix();
	glRotatef(180.0, 0.0, 0.0, 1.0);
	glRotatef(proton4, 1.0, 0.0, 0.0);	//El nucleo gira sobre su eje
	glTranslatef(0.0, 5.0, 0.0);
	//glColor3f(1.0, 1.0, 0.0);
	glutSolidSphere(1, 12, 12);
	glPopMatrix();
	

	glutSwapBuffers();

}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 30)
	{


		nucleo = (nucleo + 1) % 360;
		proton1 = (proton1 + 10) % 360;
		proton2 = (proton2 + 10) % 360;
		proton3 = (proton3 + 10) % 360;
		proton4 = (proton4 + 5) % 360;

		dwLastUpdateTime = dwCurrentTime;

	}

	glutPostRedisplay();   ///que vuelva a dibujar
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
														//glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		camaraZ += 0.5f;
		break;
	case 's':
	case 'S':
		camaraZ -= 0.5f;
		break;
	case 'a':
	case 'A':
		camaraX -= 0.5f;
		break;
	case 'd':
	case 'D':
		camaraX += 0.5f;
		break;

	case 'i':		//Movimientos de Luz
	case 'I':

		break;
	case 'k':
	case 'K':

		break;

	case 'l':   //Activamos/desactivamos luz
	case 'L':
		break;
	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...

		break;
	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...

		break;
	case GLUT_KEY_LEFT:

		break;
	case GLUT_KEY_RIGHT:

		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tama?o de la Ventana
	glutInitWindowPosition(20, 60);	//Posicion de la Ventana
	glutCreateWindow("Practica 6"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut funci?n de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut funci?n en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut funci?n de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);  //encender la animacion desde un principio--------------------
	glutMainLoop();          // 

	return 0;
}