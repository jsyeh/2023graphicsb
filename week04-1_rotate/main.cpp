///week04-1_rotate ���ݽd�Ҫ�177��{��, �⥦����Notepad++
///���W�ڭ̤W�g���{��
#include <GL/glut.h>
float angle = 0; ///step02-1 �����ܼ� angle����
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///�M�e��
    glPushMatrix(); ///step02-1 �ƥ��x�}
        glRotatef(angle, 0, 1, 0); ///step02-1 ��angle��
        glutSolidTeapot( 0.3 );
    glPopMatrix(); ///step02-1 �٭�x�}
    glutSwapBuffers();
    angle++; ///step02-1 ���� ++
}
int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week04");

    glutDisplayFunc(display);
    glutIdleFunc(display); ///step02-1 ��������,�N���e�e��
    glutMainLoop();
}
