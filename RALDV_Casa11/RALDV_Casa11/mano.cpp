//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************	León Del Villar Rubén Alejandro		**********//
//*************		Visual Studio 2017					******//
//***************		Mano con movimiento		**************//
//************************************************************//

#include "Main.h"

float transZ = -5.0f;
float transX = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;
int screenW = 0.0;
int screenH = 0.0;

float angHombro = 0.0f;
float angCodo = 0.0f;
float angWrist = 0.0f;
float angFalange = 0.0f;

float pulgar = 90.0f;
float indice = 90.0f;
float medio = 90.0f;
float anular = 90.0f;
float menique = 90.0f;


GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

///				COMIENZA ANIMACION



static GLuint movMano;

#define MAX_FRAMES 8

int maxSteps = 3000;
int currSteps = 0;
int FrameIndex = 7; // Frame final fijado por nosotros
bool play = false;
int playIndex = 0;

int frame = 0, time, timebase = 0;

typedef struct _Kframemov {


	float pulgar;
	float pulgarInc;
	float indice;
	float indiceInc;
	float medio;
	float medioInc;
	float anular;
	float anularInc;
	float menique;
	float meniqueInc;
} FRAME;

FRAME KeyFrame[MAX_FRAMES]; // Arreglo global, aqui se guardan todos los frames

void resetElements( void ) {
	pulgar = KeyFrame[0].pulgar;
	indice = KeyFrame[0].indice;
	medio = KeyFrame[0].medio;
	anular = KeyFrame[0].anular;
	menique = KeyFrame[0].menique;
}

void interpolation( void ) {
	KeyFrame[playIndex].pulgarInc = (KeyFrame[playIndex + 1].pulgar - KeyFrame[playIndex].pulgar) / maxSteps;
	KeyFrame[playIndex].indiceInc = (KeyFrame[playIndex + 1].indice - KeyFrame[playIndex].indice) / maxSteps;
	KeyFrame[playIndex].medioInc = (KeyFrame[playIndex + 1].medio - KeyFrame[playIndex].medio) / maxSteps;
	KeyFrame[playIndex].anularInc = (KeyFrame[playIndex + 1].anular - KeyFrame[playIndex].anular) / maxSteps;
	KeyFrame[playIndex].meniqueInc = (KeyFrame[playIndex + 1].menique - KeyFrame[playIndex].menique) / maxSteps;
}

///			TERMINA ANIMACIÓN

void InitGL ( void )     // Inicializamos parametros
{

	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.255, 0.412, 0.882, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing

	//Configuracion luz
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);



	for (int i = 0; i < MAX_FRAMES; i++) {
		KeyFrame[i].pulgar = 0.0f;
		KeyFrame[i].pulgarInc = 0.0f;
		KeyFrame[i].indice = 0.0f;
		KeyFrame[i].indiceInc = 0.0f;
		KeyFrame[i].medio = 0.0f;
		KeyFrame[i].medioInc = 0.0f;
		KeyFrame[i].anular = 0.0f;
		KeyFrame[i].anularInc = 0.0f;
		KeyFrame[i].menique = 0.0f;
		KeyFrame[i].meniqueInc = 0.0f;
	}


	KeyFrame[0].pulgar = 90;
	KeyFrame[0].indice = 90;
	KeyFrame[0].medio = 90;
	KeyFrame[0].anular = 90;
	KeyFrame[0].menique = 90;

	KeyFrame[1].pulgar = 85;
	KeyFrame[1].indice = 85;
	KeyFrame[1].medio = 85;
	KeyFrame[1].anular = 85;
	KeyFrame[1].menique = 85;

	KeyFrame[2].pulgar = 90;
	KeyFrame[2].indice = 90;
	KeyFrame[2].medio = 90;
	KeyFrame[2].anular = 90;
	KeyFrame[2].menique = 90;
	
	KeyFrame[3].pulgar = 0;
	KeyFrame[3].indice = 0;
	KeyFrame[3].medio = 0;
	KeyFrame[3].anular = 0;
	KeyFrame[3].menique = 0;

	KeyFrame[4].pulgar = 90;
	KeyFrame[4].indice = 90;
	KeyFrame[4].medio = 90;
	KeyFrame[4].anular = 90;
	KeyFrame[4].menique = 90;

	KeyFrame[5].pulgar = 90;
	KeyFrame[5].indice = 0;
	KeyFrame[5].medio = 0;
	KeyFrame[5].anular = 90;
	KeyFrame[5].menique = 90;

	KeyFrame[6].pulgar = 90;
	KeyFrame[6].indice = 90;
	KeyFrame[6].medio = 90;
	KeyFrame[6].anular = 90;
	KeyFrame[6].menique = 90;

	KeyFrame[7].pulgar = 0;
	KeyFrame[7].indice = 90;
	KeyFrame[7].medio = 90;
	KeyFrame[7].anular = 90;
	KeyFrame[7].menique = 90;


	
}

void animation( void ) {
	if(play) {
		if (currSteps >= maxSteps) {
			playIndex++;
			if (playIndex >= FrameIndex) { 
				printf("TERMINA ANIMACION\n");
				playIndex = 0;
				play = false;
			} else { 
				currSteps = 0;
				interpolation();
			}
		} else {
			
			// Dibujo Animación

			pulgar += KeyFrame[playIndex].pulgarInc;
			indice += KeyFrame[playIndex].indiceInc;
			medio += KeyFrame[playIndex].medioInc;
			anular += KeyFrame[playIndex].anularInc;
			menique += KeyFrame[playIndex].meniqueInc;

			currSteps++;
		}

	}

	glutPostRedisplay();
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f, -1.0f);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f( -1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX -5.5, 0.0f, transZ -3.0);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	
	//Poner Código Aquí.



	glRotatef(angHombro, 0.0, 0.0, 1.0);


			///		HOMBRO
		glPushMatrix(); 
				glColor3f(1.0, 1.0, 0.0);
				glScalef(1.0f, 2.0f, 0.5f);
				prisma();
		glPopMatrix();

				/// BICEP
		glPushMatrix();
				glColor3f(0.0, 1.0, 0.0);
				glTranslatef(2.0f, 0.0f, 0.0f);
				glScalef(3.0f, 2.0f, 0.5f);
				prisma();
		glPopMatrix();

		glTranslatef(3.75, 0.0, 0.0); 
		glRotatef(angCodo, 0.0, 0.0, 1.0);	///		ROTAR CODO
		glTranslatef(-3.75, 0.0, 0.0); 
				/// CODO
		glPushMatrix(); 
				glColor3f(1.0, 0.0, 1.0);
				glTranslatef(3.75f, 0.0f, 0.0f);
				glScalef(0.5f, 2.0f, 0.5f);
				prisma();
		glPopMatrix();
			/// ANTEBRAZO
		glPushMatrix(); 
				glColor3f(0.0, 1.0, 1.0f);
				glTranslatef(6.0f, 0.0f, 0.0f);
				glScalef(4.0f, 2.0f, 0.5f);
				prisma();
		glPopMatrix();

			glTranslatef(8.25f, 0.0f, 0.0f);
			glRotatef(angWrist, 0.0f, 1.0f, 0.0f); // WRIST ROTATEF
			glTranslatef(-8.25f, 0.0f, 0.0f);
				/// WRIST
		glPushMatrix();
				glColor3f(0.647, 0.165, 0.165);
				glTranslatef(8.25f, 0.0f, 0.0f);
				glScalef(0.5f, 2.0f, 0.5f);
				prisma();
		glPopMatrix();

		glTranslatef(9.5f, 0.0f, 0.0f); 
					/// PALMA
		glPushMatrix(); 
				glColor3f(1.000, 0.271, 0.000);
				glScalef(2.0f, 2.0f, 0.5f);
				prisma();
		glPopMatrix();

	
		glPushMatrix();	

		glTranslatef(-0.5f, 1.0f, 0.0f);
		glRotatef(pulgar, 1.0, 0.0, 0.0); 
		glTranslatef(0.5f, -1.0f, 0.0f);

		glPushMatrix(); // PULGAR FALANGE 1
			glColor3f(1.0f, 0.0f, 0.0f);
				glTranslatef(-0.5f, 1.25f, 0.0f);
				glScalef(0.4f, 0.5f, 0.5f);
				prisma();
		glPopMatrix();

		glTranslatef(-0.5f, 1.5f, 0.0f);
		glRotatef(pulgar - pulgar*0.5, 1.0, 0.0, 0.0); // PULGAR FALANGE 2
		glTranslatef(0.5f, -1.5f, 0.0f);

		glPushMatrix();  // PULGAR FALANGE 2
			glColor3f(1.0f, 0.0f, 0.0f);
				glTranslatef(-0.5f, 1.75f, 0.0f);
				glScalef(0.4f, 0.5f, 0.5f);
				prisma();
		glPopMatrix();

	glPopMatrix(); 

	glPushMatrix(); // ROTATEF INDICE

		glTranslatef(1.0f, 1.25f, 0.0f);
		glRotatef(indice, 0.0, -1.0, 0.0); // FALANGE 1
		glTranslatef(-1.0f, -1.25f, 0.0f);

		glPushMatrix(); // INDICE FALANGE 1
			glColor3f(0.0f, 1.0f, 0.0f);
				glTranslatef(1.25f, 0.75f, 0.0f);
				glScalef(0.5f, 0.4f, 0.5f);
				prisma();
		glPopMatrix();

		glTranslatef(1.5f, 1.25f, 0.0f);
		glRotatef(indice - indice*0.5, 0.0, -1.0, 0.0); // ROTAR FALANGE 2
		glTranslatef(-1.5f, -1.25f, 0.0f);

		glPushMatrix(); // 
			glColor3f(0.0f, 1.0f, 0.0f);
				glTranslatef(1.75f, 0.75f, 0.0f);
				glScalef(0.5f, 0.4f, 0.5f);
				prisma();
		glPopMatrix();

		glTranslatef(2.0f, 1.25f, 0.0f);
		glRotatef(indice - indice*0.75, 0.0, -1.0, 0.0); // ROTAR FALANGE 03
		glTranslatef(-2.0f, -1.25f, 0.0f);

		glPushMatrix(); // Indice 03
			glColor3f(0.0f, 1.0f, 0.0f);
				glTranslatef(2.25f, 0.75f, 0.0f);
				glScalef(0.5f, 0.4f, 0.5f);
				prisma();
		glPopMatrix();

	glPopMatrix(); 

	glPushMatrix(); 

		glTranslatef(1.0f, 0.25f, 0.0f);
		glRotatef(medio, 0.0, -1.0, 0.0); // MEDIO FALANGE 1
		glTranslatef(-1.0f, -0.25f, 0.0f);

		glPushMatrix(); // FALANGE 1
			glColor3f(1.0f, 0.0f, 1.0f);
				glTranslatef(1.25f, 0.25f, 0.0f);
				glScalef(0.5f, 0.4f, 0.5f);
				prisma();
		glPopMatrix();

		glTranslatef(1.5f, 0.25f, 0.0f);
		glRotatef(medio - medio * 0.5, 0.0, -1.0, 0.0);
		glTranslatef(-1.5f, -0.25f, 0.0f);

		glPushMatrix(); // FALANGE 2
			glColor3f(1.0f, 0.0f, 1.0f);
				glTranslatef(1.75f, 0.25f, 0.0f);
				glScalef(0.5f, 0.4f, 0.5f);
				prisma();
		glPopMatrix();

		glTranslatef(2.0f, 0.25f, 0.0f);
		glRotatef(medio - medio * 0.75, 0.0, -1.0, 0.0); 
		glTranslatef(-2.0f, -0.25f, 0.0f);

		glPushMatrix(); // FALANGE 3
				glColor3f(1.0f, 0.0f, 1.0f);
				glTranslatef(2.25f, 0.25f, 0.0f);
				glScalef(0.5f, 0.4f, 0.5f);
				prisma();
		glPopMatrix();
	
	glPopMatrix(); 

	glPushMatrix(); 

		glTranslatef(1.0f, -0.25f, 0.0f);
		glRotatef(anular, 0.0, -1.0, 0.0); // ROTATEF ANULAR 1
		glTranslatef(-1.0f, 0.25f, 0.0f);

		glPushMatrix(); // FALANGE 1
			glColor3f(0.000, 0.000, 0.804);
				glTranslatef(1.25f, -0.25f, 0.0f);
				glScalef(0.5f, 0.4f, 0.5f);
				prisma();
		glPopMatrix();

		glTranslatef(1.5f, -0.25f, 0.0f);
		glRotatef(anular - anular * 0.5, 0.0, -1.0, 0.0); 
		glTranslatef(-1.5f, 0.25f, 0.0f);

		glPushMatrix(); // FALANGE 2
			glColor3f(0.000, 0.000, 0.804);
				glTranslatef(1.75f, -0.25f, 0.0f);
				glScalef(0.5f, 0.4f, 0.5f);
				prisma();
		glPopMatrix();

		glTranslatef(2.0f, -0.25f, 0.0f);
		glRotatef(anular - anular * 0.75, 0.0, -1.0, 0.0); 
		glTranslatef(-2.0f, 0.25f, 0.0f);

		glPushMatrix(); // FALANGE 3
			glColor3f(0.000, 0.000, 0.804);
				glTranslatef(2.25f, -0.25f, 0.0f);
				glScalef(0.5f, 0.4f, 0.5f);
				prisma();
		glPopMatrix();

	glPopMatrix(); // TERMINA ANULAR
	
	glPushMatrix(); // MENIQUE

		glTranslatef(1.0f, -0.75f, 0.0f);
		glRotatef(menique, 0.0, -1.0, 0.0); 
		glTranslatef(-1.0f, 0.75f, 0.0f);

		glPushMatrix();	// FALANGE 1
			glColor3f(0.502, 0.000, 0.000);
				glTranslatef(1.25f, -0.75f, 0.0f);
				glScalef(0.5f, 0.4f, 0.5f);
				prisma();
		glPopMatrix();

		glTranslatef(1.5f, -0.75f, 0.0f);
		glRotatef(menique - menique * 0.5, 0.0, -1.0, 0.0); // Rotacion Meñique 02
		glTranslatef(-1.5f, 0.75f, 0.0f);

		glPushMatrix();	// FALANGE 2
			glColor3f(0.502, 0.000, 0.000);
				glTranslatef(1.65f, -0.75f, 0.0f);
				glScalef(0.3f, 0.4f, 0.5f);
				prisma();
		glPopMatrix();

		glTranslatef(1.8f, -0.75f, 0.0f);
		glRotatef(menique - menique * 0.75, 0.0, -1.0, 0.0); // Rotacion Meñique 03
		glTranslatef(-1.8f, 0.75f, 0.0f);

		glPushMatrix();	// FALANGE 3 
			glColor3f(0.502, 0.000, 0.000);
				glTranslatef(1.9f, -0.75f, 0.0f);
				glScalef(0.2f, 0.4f, 0.5f);
				prisma();
		glPopMatrix(); 

	glPopMatrix(); 
							
	glutSwapBuffers ();
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


	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();									
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
		case 'W':
			transZ +=0.2f;
			break;
		case 's':
		case 'S':
			transZ -=0.2f;
			break;
		case 'l':
		case 'L':
			transX +=0.2f;
			break;
		case 'r':
		case 'R':
			transX -=0.2f;
			break;

			///			CONTROLAR MOVIMIENTO
		case 'J':
			if(angHombro <= 80.0)
				angHombro += 1.0;
			break;
		case 'j':
			if (angHombro >= -80.0)
				angHombro -= 1.0;
			break;
		case 'M':
			if (angWrist >= -45.0)
				angWrist -= 1.0;
			break;
		case 'm':
			if (angWrist <= 45.0)
				angWrist += 1.0;
			break;
		case 'C':
			if (angCodo <= 80.0)
				angCodo += 1.0;
			break;
		case 'c':
			if (angCodo >= 0.0)
				angCodo -= 1.0;
			break;
		case 'i':
		case 'I':
			if (angFalange <= 90.0)
				angFalange += 1.0;
			break;
		case 'x':
		case 'X':
			if (angFalange >= 0.0)
				angFalange -= 1.0;
			break;
		case 'o':
		case 'O':
			if (play == false && (FrameIndex >= 1)) {

				resetElements();			
				interpolation();

				play = true;
				playIndex = 0;
				currSteps = 0;
			} else	{
				play = false;
			}
			break;
			
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;        
		default:        // Default
		break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX +=2.0f;
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX -=2.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY +=2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -=2.0f;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Mano en Movimiento"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutIdleFunc		  ( animation );
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}