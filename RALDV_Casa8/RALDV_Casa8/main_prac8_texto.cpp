//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): León Del Villar Rubén Alejandro**//
//*************				Máquina 12					******//
//*************			Visual Studio 2015				******//
//************************************************************//
#include "texture.h"

float pos_camX = 0, pos_camY = 0, pos_camZ = -5;
int eye_camX = 0, eye_camY = 0.0, eye_camZ = 0;


GLfloat Diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[] = { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[] = { 0.0f, -5.0f, 0.0f, 1.0f };			// Light Position


CTexture t_Ajedrez1; //variable de tipo textura
CTexture t_Ajedrez2;
CTexture t_metal01;
CTexture t_ladrillo;
CTexture t_madera;
CTexture t_madera2;
CTexture t_vidrio;


int font = (int)GLUT_BITMAP_TIMES_ROMAN_24;



void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.5f, 0.5f, 0.8f, 0.0f);				// Azul de fondo	

	glEnable(GL_TEXTURE_2D);  //Habilitamos las texturas

							  //glShadeModel (GL_SMOOTH);
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);


	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	t_Ajedrez1.LoadTGA("01.tga");
	t_Ajedrez1.BuildGLTexture();
	t_Ajedrez1.ReleaseImage();

	t_metal01.LoadBMP("metal2.bmp");
	t_metal01.BuildGLTexture();
	t_metal01.ReleaseImage();

	t_Ajedrez2.LoadTGA("02.tga");
	t_Ajedrez2.BuildGLTexture();
	t_Ajedrez2.ReleaseImage();

	t_vidrio.LoadTGA("vidrio1.tga");
	t_vidrio.BuildGLTexture();
	t_vidrio.ReleaseImage();

	//t_ladrillo.LoadTGA("ladrillo.tga"); //cargamos la textura
	//t_ladrillo.BuildGLTexture();  //generamos la textura y para poder ocuparla
	//t_ladrillo.ReleaseImage();

	t_madera2.LoadTGA("madera2.tga"); //cargamos la textura
	t_madera2.BuildGLTexture();  //generamos la textura y para poder ocuparla
	t_madera2.ReleaseImage();

	t_madera.LoadTGA("madera.tga"); //cargamos la textura
	t_madera.BuildGLTexture();  //generamos la textura y para poder ocuparla
	t_madera.ReleaseImage();
}


void renderBitmapCharacter(float x, float y, float z, void *font, char *string)
{

	char *c;     //Almacena los caracteres a escribir
	glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
							//glWindowPos2i(150,100);
	for (c = string; *c != '\0'; c++) //Condicion de fin de cadena
	{
		glutBitmapCharacter(font, *c); //imprime
	}
}



void prisma(GLuint textura1, GLuint textura2)  //Funcion creacion prisma
{

	GLfloat vertice[12][3] = {
		{ 0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 0 V0
		{ -0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 1 V1
		{ -0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 2 V2
		{ 0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 3 V3
		{ 0.5 ,0.5, 0.5 },    //Coordenadas Vértice 4 V4
		{ 0.5 ,0.5, -0.5 },    //Coordenadas Vértice 5 V5
		{ -0.5 ,0.5, -0.5 },    //Coordenadas Vértice 6 V6
		{ -0.5 ,0.5, 0.5 },    //Coordenadas Vértice 7 V7
		{ -0.35 ,0.5, -0.35 },    //Coordenadas Vértice 8 V8
		{ 0.35 ,0.5, -0.35 },    //Coordenadas Vértice 9 V9
		{ 0.35 ,0.5, 0.35 },    //Coordenadas Vértice 10 V10
		{ -0.35 ,0.5, 0.35 },    //Coordenadas Vértice 11 V11
	};


	glBindTexture(GL_TEXTURE_2D, textura2);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]); //Se ponen los vértices donde está la textura. La primer coordenada de la
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]); //textura pertenece al primer vértice 0
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[5]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura2);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, textura1);
	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(4.0, 0.0f); glVertex3fv(vertice[10]);
	glTexCoord2f(4.0, 4.0f); glVertex3fv(vertice[9]);
	glTexCoord2f(0.0, 4.0f); glVertex3fv(vertice[8]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[11]);
	glEnd();

}

void prisma2(GLuint textura2, GLuint textura3)  //Funcion creacion prisma
{

	GLfloat vertice[8][3] = {
		{ 0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 0 V0
		{ -0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 1 V1
		{ -0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 2 V2
		{ 0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 3 V3
		{ 0.5 ,0.5, 0.5 },    //Coordenadas Vértice 4 V4
		{ 0.5 ,0.5, -0.5 },    //Coordenadas Vértice 5 V5
		{ -0.5 ,0.5, -0.5 },    //Coordenadas Vértice 6 V6
		{ -0.5 ,0.5, 0.5 },    //Coordenadas Vértice 7 V7
	};


	glBindTexture(GL_TEXTURE_2D, textura2);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]); //Se ponen los vértices donde está la textura. La primer coordenada de la
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]); //textura pertenece al primer vértice 0
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[5]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura3);
	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura2);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
	glEnd();

}

void prisma3(GLuint textura2)  //Funcion creacion prisma
{

	GLfloat vertice[8][3] = {
		{ 0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 0 V0
		{ -0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 1 V1
		{ -0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 2 V2
		{ 0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 3 V3
		{ 0.5 ,0.5, 0.5 },    //Coordenadas Vértice 4 V4
		{ 0.5 ,0.5, -0.5 },    //Coordenadas Vértice 5 V5
		{ -0.5 ,0.5, -0.5 },    //Coordenadas Vértice 6 V6
		{ -0.5 ,0.5, 0.5 },    //Coordenadas Vértice 7 V7
	};


	glBindTexture(GL_TEXTURE_2D, textura2);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]); //Se ponen los vértices donde está la textura. La primer coordenada de la
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]); //textura pertenece al primer vértice 0
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[5]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura2);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
	glEnd();

}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	glPushMatrix();
	glTranslatef(pos_camX, pos_camY, pos_camZ);
	glRotatef(eye_camX, 1.0, 0.0, 0.0);
	glRotatef(eye_camY, 0.0, 1.0, 0.0);
	glRotatef(eye_camZ, 0.0, 0.0, 1.0);

	//*****MESA
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glScalef(2.0, 0.2, 2.0);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);

	prisma(t_Ajedrez2.GLindex, t_vidrio.GLindex); //Estamos asignando la textura ladrillo

	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	//Pata delantera izquiera		
	glPushMatrix();
	glTranslatef(-0.60f, -1.2f, 0.85f);
	glColor3f(1.0, 1.0, 1.0);
	glScalef(0.2, 2.5, 0.2);

	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	
	prisma2(t_vidrio.GLindex, t_metal01.GLindex); //Estamos asignando la textura madera
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	//Pata delantera derecha
	glPushMatrix();
	glTranslatef(0.60f, -1.2f, 0.85f);
	glColor3f(1.0, 1.0, 1.0);
	glScalef(0.2, 2.5, 0.2);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);

	prisma2(t_vidrio.GLindex, t_metal01.GLindex); //Estamos asignando la textura madera
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	//Pata trasera izquierda
	glPushMatrix();
	glTranslatef(-0.60f, -1.2f, -0.85f);
	glColor3f(1.0, 1.0, 1.0);
	glScalef(0.2, 2.5, 0.2);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);

	prisma2(t_vidrio.GLindex, t_metal01.GLindex); //Estamos asignando la textura madera
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	//Pata trasera derecha
	glPushMatrix();
	glTranslatef(0.60f, -1.2f, -0.85f);
	glColor3f(1.0, 1.0, 1.0);
	glScalef(0.2, 2.5, 0.2);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);

	prisma2(t_vidrio.GLindex, t_metal01.GLindex); //Estamos asignando la textura madera
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	//******SILLA
	//asiento
	glPushMatrix();
	glTranslatef(1.8f, -1.0f, -0.0f);
	glColor3f(1.0, 1.0, 1.0);
	glScalef(1.0, 0.2, 1.0);
	prisma3(t_madera.GLindex);
	glPopMatrix();

	//respaldo
	glPushMatrix();
	glTranslatef(2.23f, -0.15f, -0.42f);
	glColor3f(1.0, 1.0, 1.0);
	glScalef(0.15, 1.5, 0.15);
	prisma2(t_madera.GLindex, t_metal01.GLindex);
	glPopMatrix();


	//respaldo 2
	glPushMatrix();
	glTranslatef(2.23f, -0.15f, 0.42f);
	glColor3f(1.0, 1.0, 1.0);
	glScalef(0.15, 1.5, 0.15);
	prisma2(t_madera.GLindex, t_metal01.GLindex);
	glPopMatrix();

	//respaldo 3
	glPushMatrix();
	glTranslatef(2.23f, 0.45f, 0.0f);
	glColor3f(1.0, 1.0, 1.0);
	glScalef(0.15, 0.3, 0.7);
	prisma3(t_madera.GLindex);
	glPopMatrix();



	//respaldo 4				// CRISTALIZAR
	glPushMatrix();
	glTranslatef(2.23f, -0.30f, 0.0f);
	glColor3f(1.0, 1.0, 1.0);
	glScalef(0.15, 1.2, 0.7);

	//glDisable(GL_DEPTH_TEST);

	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	prisma3(t_vidrio.GLindex);
	glDisable(GL_ALPHA_TEST);
	
	glPopMatrix();



	//pata silla delantera derecha
	glPushMatrix();
	glTranslatef(2.23f, -1.75f, 0.42f);
	glColor3f(1.0, 1.0, 1.0);
	glScalef(0.15, 1.3, 0.15);
	prisma2(t_madera.GLindex, t_metal01.GLindex);
	glPopMatrix();

	//pata silla trasera deracha
	glPushMatrix();
	glTranslatef(2.23f, -1.75f, -0.42f);
	glColor3f(1.0, 1.0, 1.0);
	glScalef(0.15, 1.3, 0.15);
	prisma2(t_madera.GLindex, t_metal01.GLindex);
	glPopMatrix();

	//pata silla delantera izquierda
	glPushMatrix();
	glTranslatef(1.37f, -1.75f, 0.42f);
	glColor3f(1.0, 1.0, 1.0);
	glScalef(0.15, 1.3, 0.15);
	prisma2(t_madera.GLindex, t_metal01.GLindex);
	glPopMatrix();

	//pata silla trasera izquierda
	glPushMatrix();
	glTranslatef(1.37f, -1.75f, -0.42f);
	glColor3f(1.0, 1.0, 1.0);
	glScalef(0.15, 1.3, 0.15);
	prisma2(t_madera.GLindex, t_metal01.GLindex);
	glPopMatrix();
	/*glPushMatrix();
	glTranslatef(2.23f, -0.15f, -0.0f);
	glColor3f(1.0, 1.0, 1.0);
	glScalef(0.15, 1.5, 1.0);
	prisma3(t_madera.GLindex);
	glPopMatrix();*/



	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	renderBitmapCharacter(-11, 12.0, -14.0, (void *)font, "Practica 8");
	renderBitmapCharacter(-11, 10.5, -14, (void *)font, "Ejercicio en Clase");
	glEnable(GL_TEXTURE_2D);

	glutSwapBuffers();

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
	glLoadIdentity();
}

void animacion()
{


	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		pos_camZ += 0.5f;
		//eye_camZ -= 0.5f;
		break;

	case 's':
	case 'S':
		pos_camZ -= 0.5f;
		//eye_camZ += 0.5f;
		break;

	case 'a':
	case 'A':
		pos_camX += 0.5f;
		//eye_camX -= 0.5f;
		break;
	case 'd':
	case 'D':
		pos_camX -= 0.5f;
		//eye_camX += 0.5f;
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
	case GLUT_KEY_PAGE_UP:
		pos_camY -= 0.5f;
		//eye_camY += 0.5f;
		break;

	case GLUT_KEY_PAGE_DOWN:
		pos_camY += 0.5f;
		//eye_camY -= 0.5f;
		break;

	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		eye_camX = (eye_camX - 15) % 360;
		break;

	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		eye_camX = (eye_camX + 15) % 360;
		break;

	case GLUT_KEY_LEFT:
		eye_camY = (eye_camY - 15) % 360;
		break;

	case GLUT_KEY_RIGHT:
		eye_camY = (eye_camY + 15) % 360;
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
	glutInitWindowSize(5000, 5000);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Practica 8"); // Nombre de la Ventana
									//glutFullScreen     ( );         // Full Screen
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 

	return 0;
}