///Week05-2_TRT_robot �K�W week05-1_TRT_translate_rotate ���{��
///Week05-1_TRT_translate_rotate ��W�g�� week04-1 ���ӥ�
///����b�令 0,0,1 z�b, �A�ƻs�� ����B���
#include <GL/glut.h>
float angle = 0;
void myCube()///step2 ��禡
{
    glPushMatrix();///step1
        glScalef(0.5, 0.2, 0.2);///step1 �դj�p
        glutSolidCube(1); ///step1 �����
    glPopMatrix();///step1
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1,1,1);///step4 �զ⪺
    glutSolidCube(1); ///step4 ����

    glPushMatrix();///step2
        glTranslatef(0.5, 0.5, 0);///step5 ����k�W���h
        glRotatef(angle, 0, 0, 1);///step2 �०
        glTranslatef(0.25, 0, 0);///step3 ���k���� 0.25 �����`�b������
        glColor3f(0,1,0);///step4 ��⪺
        myCube(); ///step2 ��禡
    glPopMatrix();///step2

    glPushMatrix();///step2
        glTranslatef(-0.5, 0.5, 0);///step5 ����k�W���h
        glRotatef(angle, 0, 0, 1);///step2 �०
        glTranslatef(0.25, 0, 0);///step3 ���k���� 0.25 �����`�b������
        glColor3f(0,1,0);///step4 ��⪺
        myCube(); ///step2 ��禡
    glPopMatrix();///step2

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
