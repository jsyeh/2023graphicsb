///week06-4_TRT_robot5_mouse_motion_angle
///��mouse motion�ӱ����
///���R, week06-3_TRT_robot4_arm_hand_right_left ���{���ӧ�
#include <GL/glut.h>
float angle = 0;
void myCube()///step02-1 �禡
{
    glPushMatrix();
        glScalef(1, 0.3, 0.3);
        glutSolidCube(0.5);
    glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glutSolidSphere(0.01, 30, 30); ///step01-1 �p�y�������I�Ѧ�

    glPushMatrix(); ///�k�䪺
        glTranslatef(0.25, 0, 0); ///(3) �o��h�O�n�M�w���b����
        glRotatef(angle, 0, 0, 1);///(2)
        glTranslatef(0.25, 0, 0); ///(1)
        myCube(); ///�W���u
        glPushMatrix();
            glTranslatef(0.25, 0, 0); ///(3) �o��h�O�n�M�w���b����
            glRotatef(angle, 0, 0, 1);///(2)
            glTranslatef(0.25, 0, 0); ///(1)
            myCube(); ///�U��y
        glPopMatrix();
    glPopMatrix();

    glPushMatrix(); ///���䪺
        glTranslatef(-0.25, 0, 0); ///(3) �o��h�O�n�M�w���b����
        glRotatef(-angle, 0, 0, 1);///(2)
        glTranslatef(-0.25, 0, 0); ///(1)
        myCube(); ///�W���u
        glPushMatrix();
            glTranslatef(-0.25, 0, 0); ///(3) �o��h�O�n�M�w���b����
            glRotatef(-angle, 0, 0, 1);///(2)
            glTranslatef(-0.25, 0, 0); ///(1)
            myCube(); ///�U��y
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
    ///angle++; //step03-1 �� angle++���ѱ�
}
///�j�H���B�c��, ���}�B�c��,��j�H��i�h,������_��
///Q: �p���mouse����� ���� A: mouse���U�h,mouse����,mouse��}��
int oldX=0;
void mouse(int button, int state, int x, int y)
{
    oldX = x;
}
void motion(int x, int y)
{///step03-1 �s�[�� mouse motion
    angle += (x-oldX);
    oldX = x;
}
int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week06");

    glutMotionFunc(motion); ///step03-1 �s�[�� mouse motion
    glutMouseFunc(mouse);   ///step03-2 �s�[ mouse�禡
    glutDisplayFunc(display);
    glutIdleFunc(display);

    glutMainLoop();
}
