///week04-3_rotate_translate
///���� week04-1_rotate���{��,���ӧ�g
#include <GL/glut.h>
float angle = 0; ///step02-1 �����ܼ� angle����
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///�M�e��

    glPushMatrix(); ///step02-1 �ƥ��x�}
        glTranslatef(0.5, 0, 0);///step03-3 ����k�䪺
        glRotatef(angle, 0, 1, 0); ///step03-3 ���त��
        glColor3f(0,0,1);///step03-3 �Ŧ⪺
        glutSolidTeapot( 0.3 ); ///����
    glPopMatrix(); ///step02-1 �٭�x�}

    glPushMatrix(); ///step02-1 �ƥ��x�}
        glRotatef(angle, 0, 1, 0); ///step03-4 ���त��
        glTranslatef(0.5, 0, 0);///step03-4 ����k�䪺
        glColor3f(1,1,0);///step03-4 ���⪺
        glTranslatef(0, 0.5, 0); ///step03-4 ���W���ʪ�
        glutSolidTeapot( 0.3 ); ///����
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
