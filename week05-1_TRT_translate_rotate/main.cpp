///Week05-1_TRT_translate_rotate ��W�g�� week04-1 ���ӥ�
///����b�令 0,0,1 z�b, �A�ƻs�� ����B���
#include <GL/glut.h>
float angle = 0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1, 0, 0);///����
    glPushMatrix();
        glRotatef(angle, 0, 0, 1); ///step02-1 �令 0,0,1 z�b
        glTranslatef(0.8, 0, 0);///����k��
        glutSolidTeapot( 0.3 );
    glPopMatrix();

    glColor3f(0, 1, 0);///���
    glPushMatrix();
        glTranslatef(0.8, 0, 0);///����k��
        glRotatef(angle*1.5, 0, 0, 1); ///step02-1 �令 0,0,1 z�b
        glutSolidTeapot( 0.3 );
    glPopMatrix();

    glutSwapBuffers();
    angle++;
}
int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week05");

    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
}
