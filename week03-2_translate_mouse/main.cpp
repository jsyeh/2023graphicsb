///week03-2_translate_mouse �n�[�W mouse �����ʥ\��
///(1) File-New-Project, GLUT�M��
///(2) �K�W week03-1_translate ���{��
///(3) �n�ϥ� global �ܼ�,�����y�Ч���
#include <GL/glut.h>
float X=0, Y=0, Z=0; ///step03-1 �ϥ� global �ܼ�
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );///step03-1 �M�I��
    glPushMatrix(); ///�ƥ��x�}
        glTranslatef( X, Y, Z ); ///step03-1 �ӵ� X,Y,Z�Ӳ���
        glutSolidTeapot( 0.3 );
    glPopMatrix(); ///�٭�x�}

    glutSwapBuffers();
}
void mouse( int button, int state, int x, int y ) ///step03-1 mouse()
{       ///     �����k��    ���U/��} �px   �py   0...300
    X =  (x-150)/150.0; ///step03-1 ��@�b�B���@�b
    Y = -(y-150)/150.0; ///step03-1 ��@�b�B���@�b�By�ܭt��
}
int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week03");

    glutMouseFunc(mouse); ///step03-1 �]�w�n mouse�禡
    glutDisplayFunc(display);

    glutMainLoop();
}
