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

void head(int x,int y)
{
	glBegin(GL_LINE_LOOP);
	glColor3f(0.5,0.35,0.05);
    for (int i = 0; i < 360; i+=10)
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
void dance(){
while(true){
	for(int i=0;i<3;i++)
	{
		for(int a=-60,b=-130;a<-30&&b<-100;a++,b++)
		{
			glClear(GL_COLOR_BUFFER_BIT);
	        head(0,0);
	        drawline(0,-20,0,-100);//body
	        drawline(0,-30,-30,a);//lefthand
	        drawline(0,-30,30,-60);//righthand
	        drawline(0,-100,-30,-130);//leftleg
	        drawline(0,-100,30,b);//rightleg
	        delay(10);
	    }
	    for(int a=-30,b=-100;a>-60&&b>-130;a--,b--)
		{
			glClear(GL_COLOR_BUFFER_BIT);
	        head(0,0);
	        drawline(0,-19.93,0,-100);//body
	        drawline(0,-30,-30,a);//lefthand
	        drawline(0,-30,30,-60);//righthand
	        drawline(0,-100,-30,-130);//leftleg
	        drawline(0,-100,30,b);//rightleg
	        delay(10);
	    }
	}
	for(int i=0;i<3;i++)
	{
		for(int a=-60,b=-130;a<-30&&b<-100;a++,b++)
		{
			glClear(GL_COLOR_BUFFER_BIT);
	        head(0,0);
	        drawline(0,-19.93,0,-100);//body
	        drawline(0,-30,-30,-60);//lefthand
	        drawline(0,-30,30,a);//righthand
	        drawline(0,-100,-30,b);//leftleg
	        drawline(0,-100,30,-130);//rightleg
	        delay(10);
	    }
	    for(int a=-30,b=-100;a>-60&&b>-130;a--,b--)
		{
			glClear(GL_COLOR_BUFFER_BIT);
	        head(0,0);
	        drawline(0,-19.93,0,-100);//body
	        drawline(0,-30,-30,-60);//lefthand
	        drawline(0,-30,30,a);//righthand
	        drawline(0,-100,-30,b);//leftleg
	        drawline(0,-100,30,-130);//rightleg
	        delay(10);
	    }
	}
	for(int i=0;i<3;i++)
	{
		for(int a=-60,b=-130;a<-30&&b<-100;a++,b++)
		{
			glClear(GL_COLOR_BUFFER_BIT);
	        head(0,0);
	        drawline(0,-19.93,0,-100);//body
	        drawline(0,-30,-30,a);//lefthand
	        drawline(0,-30,30,a);//righthand
	        drawline(0,-100,-30,b);//leftleg
	        drawline(0,-100,30,b);//rightleg
	        delay(10);
	    }
	    for(int a=-30,b=-100;a>-60&&b>-130;a--,b--)
		{
			glClear(GL_COLOR_BUFFER_BIT);
	        head(0,0);
	        drawline(0,-19.93,0,-100);//body
	        drawline(0,-30,-30,a);//lefthand
	        drawline(0,-30,30,a);//righthand
	        drawline(0,-100,-30,b);//leftleg
	        drawline(0,-100,30,b);//rightleg
	        delay(10);
	    }
	}
	for(int i=0;i<3;i++)
	{
		for(int a=-60,b=-130;a<0||b<-100;a++,b++)
		{
			glClear(GL_COLOR_BUFFER_BIT);
	        head(0,0);
	        drawline(0,-19.93,0,-100);//body
	        drawline(0,-30,-30,a);//lefthand
	        drawline(0,-30,30,a);//righthand
	        drawline(0,-100,-30,-130);//leftleg
	        drawline(0,-100,30,-130);//rightleg
	        delay(10);
	    }
	    for(int a=0,b=-100;a>-60||b>-130;a--,b--)
		{
			glClear(GL_COLOR_BUFFER_BIT);
	        head(0,0);
	        drawline(0,-19.93,0,-100);//body
	        drawline(0,-30,-30,a);//lefthand
	        drawline(0,-30,30,a);//righthand
	        drawline(0,-100,-30,-130);//leftleg
	        drawline(0,-100,30,-130);//rightleg
	        delay(10);
	    }
	}
}
        
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	
	glutInitWindowPosition(80, 80);
	glutInitWindowSize(600, 600);
	glutCreateWindow("DancingStickHuman");
	
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(-250, 250, -250, 250);
	glutDisplayFunc(dance);
	glutMainLoop();	
}





