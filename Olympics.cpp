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

void circle(float x,float y)
{
	glBegin(GL_LINE_LOOP);
	glColor3f(0.5,0.35,0.05);
    for (int i = 0; i < 360; i++)
	{
        float angle_theta = i * 3.142 / 180;	            
    	glVertex2f(x+20*cos(angle_theta),y+20*sin(angle_theta));
    }
    glEnd();
    glFlush();
}

void drawline(int x1,int y1,int x2,int y2)
{
	glBegin(GL_LINES);
    glColor3f(0.5,0.35,0.05);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd();
    glFlush();
}

void olympics()
{
	circle(30,60);
	circle(75,60);
	circle(120,60);
	circle(52.5,40);
	circle(97.5,40);
	
	drawline(0,100,0,0);
	
	circle(-30,60);
	circle(-75,60);
	circle(-120,60);
	circle(-52.5,40);
	circle(-97.5,40);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	
	glutInitWindowPosition(80, 80);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Olympics Flag Reflection");
	
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(-250, 250, -250, 250);
	
	glutDisplayFunc(olympics);
	glutMainLoop();	
}
