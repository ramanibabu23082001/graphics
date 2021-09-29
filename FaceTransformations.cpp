#include <GL/glut.h>
#include <math.h>
#include <time.h>
#include <bits/stdc++.h>

using namespace std; 

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void circle(float x,float y,float r,float startangle,float endangle,float a,float b,float c,bool isMouth)
{
	glBegin(GL_POLYGON);
	glColor3f(a,b,c);
    for (int i = startangle; i <= endangle; i++)
	{
        float angle_theta = i * 3.142 / 180;	            
    	glVertex2f(x+r*cos(angle_theta),y+r*sin(angle_theta));
    }
    glEnd();
    glFlush();
	if(!isMouth)
	{
		glBegin(GL_POINTS);
		glColor3f(0,0,0);
	    for (int i = startangle; i <= endangle; i++)
		{
	        float angle_theta = i * 3.142 / 180;	            
	    	glVertex2f(x+(r+0.2)*cos(angle_theta),y+(r+0.2)*sin(angle_theta));
	    }
	    glEnd();
	    glFlush();
	}
}

void face()
{
	circle(0,0,50,0,360,1.0,1.2,0.0,false);
	circle(-20,10,10,0,360,0.0,0.0,0.0,false);
	circle(20,10,10,0,360,0.0,0.0,0.0,false);
	circle(0,-15,20,180,360,1.0,1.0,1.0,true);
}
void translate()
{
	glTranslatef(15,12,0);
	face();
}

void scale()
{
	glScalef(2,2,0);
	face();
}

void rotate()
{
	glRotatef(45,0,0,10);
	face();
}

int main(int argc, char** argv) {
	int x;
	cout<<"Enter 1. Scaling 2. Rotation 3. Translation"<<endl;
	cin>>x;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	
	glutInitWindowPosition(80, 80);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Face Transformations");
	
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(-250, 250, -250, 250);
	if(x==1)
		glutDisplayFunc(scale);
	else if(x==2)
		glutDisplayFunc(rotate);
	else
		glutDisplayFunc(translate);
	glutMainLoop();	
}

