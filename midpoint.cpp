/* DAUDI FELIX KOKI
SCT212-0062/2018 */

#include<stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

float x1,y3,x2,y4,dInitial,changeD,newD;
float dx,dy;
void display(void)
{
/* clear all pixels */
glClear (GL_COLOR_BUFFER_BIT);

glEnd();

glColor3f (1, 0, 0);
glBegin(GL_LINES);

if(dInitial<0)
{
while (x1<=x2 && y3<=y4)
{
    x1=x1+1;
    y3=y3;
    newD = dInitial + 2*dy;
    glVertex3d(x1/100,y3/100,0.0);
   printf("%f %f",x1,y3);

}
}
else if(dInitial>=0)
{
while (x1<=x2 && y3<=y4)
{
    x1=x1+1;
    y3=y3+1;
    newD = dInitial + changeD;
   glVertex3d(x1/100,y3/100,0.0);
   printf("%f %f",x1,y3);
}
}

glEnd();


/* don't wait!
* start processing buffered OpenGL routines
*/
glFlush ();
}
void init (void)
{
/* select clearing (background) color */
glClearColor (0.0, 0.0, 0.0, 0.0);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{

   
    printf("Enter value of X1 :");
    scanf("%f",&x1);
    printf("Enter value of y3 :");
    scanf("%f",&y3);
    printf("Enter value of X2 :");
    scanf("%f",&x2);
    printf("Enter value of y4 :");
    scanf("%f",&y4);
    dx=x2-x1;
    dy=y4-y3;
    dInitial = (2*dy -dx);
    changeD = 2*(dy-dx);



glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE);/*initialize mode of display*/
glutInitWindowSize (400, 300); //screen size/window
glutInitWindowPosition (100, 100); //screen position
glutCreateWindow ("MIDPOINT");//screen title
init ();
glutDisplayFunc(display);
glutMainLoop();
return 0; /* ISO C requires main to return int. */
}

