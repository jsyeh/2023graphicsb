///week15-3_gluPerspective_gluLookAt
#include <GL/glut.h>
void display() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}
void motion(int x, int y) {///step03-1
    glLoadIdentity();
    float eyeX = (x-150)/150.0,  eyeY = (150-y)/150.0; ///step03-1
    gluLookAt(eyeX,eyeY,1,  0,0,0,  0,1,0);///step03-1
    glutPostRedisplay();///step03-1
}
void reshape(int w, int h) { ///step03-2
    float ar = w / (float) h;
    glViewport(0, 0, w, h); ///step03-2

    glMatrixMode(GL_PROJECTION); ///step03-2
    glLoadIdentity(); ///step03-2
    gluPerspective(60, ar, 0.01, 1000); ///step03-2

    glMatrixMode(GL_MODELVIEW); ///step03-2
    glLoadIdentity(); ///step03-2
    gluLookAt(0,0,1,  0,0,0,  0,1,0); ///step03-2
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week115");

    glutReshapeFunc(reshape);///step03-2
    glutMotionFunc(motion);///step03-1
    glutDisplayFunc(display);

    glutMainLoop();
}
