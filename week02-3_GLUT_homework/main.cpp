#include <GL/glut.h>
void display()
{ ///用小畫家幫我們寫程式   除 255.0 就好了
    glColor3f( 233/255.0, 141/255.0, 128/255.0);
    ///不可以超過 0...1
    glBegin(GL_POLYGON);
        glVertex2f( (65-100)/100.0, -(54-100)/100.0 );
        glVertex2f( (34-100)/100.0, -(138-100)/100.0 );
        glVertex2f( (59-100)/100.0, -(138-100)/100.0 );
        glVertex2f( (87-100)/100.0, -(53-100)/100.0 );
        ///先減一半,再除一半,y變負號
        ///0...200 => -100...+100 => -1.0  +1.0
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char * argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week02");

    glutDisplayFunc(display);

    glutMainLoop();
}
