#include <GL/glut.h>
#include <math.h>
#include <time.h>
#include <bits/stdc++.h>
#include <stdarg.h>
#include <vector>

using namespace std; 

double rotate_y=0;
double rotate_x=0;
int choice;


void legs(float x,float y,float z)
{
	//front-face
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.0,0.0); 
	glVertex3f(x,y,z);
	glVertex3f(x+0.1,y,z);
	glVertex3f(x+0.1,y-0.4,z);
	glVertex3f(x,y-0.4,z);
	glEnd();
	
	//back-face
	glBegin(GL_POLYGON);
	glColor3f(0.0,1.0,0.0);
	glVertex3f(x,y,z+0.1);
	glVertex3f(x+0.1,y,z+0.1);
	glVertex3f(x+0.1,y-0.4,z+0.1);
	glVertex3f(x,y-0.4,z+0.1);
	glEnd();
	
	//left-face
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,1.0);
	glVertex3f(x+0.1,y,z);
	glVertex3f(x+0.1,y,z+0.1);
	glVertex3f(x+0.1,y-0.4,z+0.1);
	glVertex3f(x+0.1,y-0.4,z);
	glEnd();
	
	//right-face
	glBegin(GL_POLYGON);
	glColor3f(1.0,1.0,0.0);
	glVertex3f(x,y,z);
	glVertex3f(x,y,z+0.1);
	glVertex3f(x,y-0.4,z+0.1);
	glVertex3f(x,y-0.4,z);
	glEnd();
	
	//bottom-face
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.0,1.0);
	glVertex3f(x,y-0.4,z);
	glVertex3f(x+0.1,y-0.4,z);
	glVertex3f(x+0.1,y-0.4,z+0.1);
	glVertex3f(x,y-0.4,z+0.1);
	glEnd();
}
void table(float x,float y,float z)
{
	//front-face
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.0,0.0); 
	glVertex3f(-x,-y,-z);
	glVertex3f(x,-y,-z);
	glVertex3f(x,y,-z);
	glVertex3f(-x,y,-z);
	glEnd();
	
	//back-face
	glBegin(GL_POLYGON);
	glColor3f(0.0,1.0,0.0);
	glVertex3f(-x,-y,z);
	glVertex3f(x,-y,z);
	glVertex3f(x,y,z);
	glVertex3f(-x,y,z);
	glEnd();
	
	//left-face
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,1.0);
	glVertex3f(x,-y,-z);
	glVertex3f(x,-y,z);
	glVertex3f(x,y,z);
	glVertex3f(x,y,-z);
	glEnd();
	
	//right-face
	glBegin(GL_POLYGON);
	glColor3f(1.0,1.0,0.0);
	glVertex3f(-x,-y,-z);
	glVertex3f(-x,-y,z);
	glVertex3f(-x,y,z);
	glVertex3f(-x,y,-z);
	glEnd();
	
	//top-face
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.0,1.0);
	glVertex3f(-x,y,-z);
	glVertex3f(x,y,-z);
	glVertex3f(x,y,z);
	glVertex3f(-x,y,z);
	glEnd();
	
	//bottom-face
	glBegin(GL_POLYGON);
	glColor3f(0.0,1.0,1.0);
	glVertex3f(-x,-y,-z);
	glVertex3f(x,-y,-z);
	glVertex3f(x,-y,z);
	glVertex3f(-x,-y,z);
	glEnd();
}
void draw()
{
	table(0.3,0.1,0.5);
	legs(-0.3,-0.1,-0.5);
	legs(0.2,-0.1,-0.5);
	legs(-0.3,-0.1,0.4);
	legs(0.2,-0.1,0.4);
}
void display(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	glRotatef(rotate_x,1.0,0.0,0.0);
	glRotatef(rotate_y,0.0,1.0,0.0);
	draw();
	
	if(choice==1)
	{
		glTranslatef(0.0,0.4,0.0);
		draw();
	}
	else if(choice==2)
	{
		glRotatef(30,0.0,0.0,1.0);
		draw();
	}
	else if(choice==3)
	{
		glScalef(0.5,0.3,0.7);
		draw();
	}
	glFlush();
	glutSwapBuffers();
}

void specialKeys( int key, int x, int y ) {
  if (key == GLUT_KEY_RIGHT)
    rotate_y += 5;
  else if (key == GLUT_KEY_LEFT)
    rotate_y -= 5;
  else if (key == GLUT_KEY_UP)
    rotate_x += 5;
  else if (key == GLUT_KEY_DOWN)
    rotate_x -= 5;
  glutPostRedisplay();
 
}
int main(int argc, char** argv) {

	cout<<"Enter 1.Translation 2.Rotation 3.Scaling"<<endl;
	cin>>choice;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(80, 80);
	glutInitWindowSize(800, 800);
	glEnable(GL_DEPTH_TEST);
	glutCreateWindow("Table");

	glutDisplayFunc(display);
	glutSpecialFunc(specialKeys);
	glutMainLoop();	
	return 0;
}
