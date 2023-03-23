///Week06-2_TRT_robot3_hierarchy 有階層的
///全刪, 改用上週的 week05-2_TRT_robot 的程式來改
#include <GL/glut.h>
float angle = 0;
void myCube()///step02-1 函式
{
    glPushMatrix();
        glScalef(1, 0.3, 0.3);
        glutSolidCube(0.5);
    glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glutSolidSphere(0.01, 30, 30); ///step01-1 小球做中心點參考

    glPushMatrix();
        glTranslatef(0.25, 0, 0); ///(3) 這行則是要決定掛在哪裡
        glRotatef(angle, 0, 0, 1);///(2)
        glTranslatef(0.25, 0, 0); ///(1)
        myCube();
        glPushMatrix();
            glTranslatef(0.25, 0, 0); ///(3) 這行則是要決定掛在哪裡
            glRotatef(angle, 0, 0, 1);///(2)
            glTranslatef(0.25, 0, 0); ///(1)
            myCube();
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
    angle++;
}
int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week06");

    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
}
