///Week05-2_TRT_robot 貼上 week05-1_TRT_translate_rotate 的程式
///Week05-1_TRT_translate_rotate 把上週的 week04-1 拿來用
///旋轉軸改成 0,0,1 z軸, 再複製成 紅色、綠色
#include <GL/glut.h>
float angle = 0;
void myCube()///step2 改函式
{
    glPushMatrix();///step1
        glScalef(0.5, 0.2, 0.2);///step1 調大小
        glutSolidCube(1); ///step1 正方塊
    glPopMatrix();///step1
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1,1,1);///step4 白色的
    glutSolidCube(1); ///step4 身體

    glPushMatrix();///step2
        glTranslatef(0.5, 0.5, 0);///step5 掛到右上角去
        glRotatef(angle, 0, 0, 1);///step2 轉它
        glTranslatef(0.25, 0, 0);///step3 往右移動 0.25 讓關節在正中心
        glColor3f(0,1,0);///step4 綠色的
        myCube(); ///step2 改函式
    glPopMatrix();///step2

    glPushMatrix();///step2
        glTranslatef(-0.5, 0.5, 0);///step5 掛到右上角去
        glRotatef(angle, 0, 0, 1);///step2 轉它
        glTranslatef(0.25, 0, 0);///step3 往右移動 0.25 讓關節在正中心
        glColor3f(0,1,0);///step4 綠色的
        myCube(); ///step2 改函式
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
