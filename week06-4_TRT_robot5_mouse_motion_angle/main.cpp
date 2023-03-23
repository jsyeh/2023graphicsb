///week06-4_TRT_robot5_mouse_motion_angle
///用mouse motion來控制角度
///全刪, week06-3_TRT_robot4_arm_hand_right_left 的程式來改
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

    glPushMatrix(); ///右邊的
        glTranslatef(0.25, 0, 0); ///(3) 這行則是要決定掛在哪裡
        glRotatef(angle, 0, 0, 1);///(2)
        glTranslatef(0.25, 0, 0); ///(1)
        myCube(); ///上手臂
        glPushMatrix();
            glTranslatef(0.25, 0, 0); ///(3) 這行則是要決定掛在哪裡
            glRotatef(angle, 0, 0, 1);///(2)
            glTranslatef(0.25, 0, 0); ///(1)
            myCube(); ///下手肘
        glPopMatrix();
    glPopMatrix();

    glPushMatrix(); ///左邊的
        glTranslatef(-0.25, 0, 0); ///(3) 這行則是要決定掛在哪裡
        glRotatef(-angle, 0, 0, 1);///(2)
        glTranslatef(-0.25, 0, 0); ///(1)
        myCube(); ///上手臂
        glPushMatrix();
            glTranslatef(-0.25, 0, 0); ///(3) 這行則是要決定掛在哪裡
            glRotatef(-angle, 0, 0, 1);///(2)
            glTranslatef(-0.25, 0, 0); ///(1)
            myCube(); ///下手肘
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
    ///angle++; //step03-1 把 angle++註解掉
}
///大象放到冰箱裡, 打開冰箱門,把大象放進去,把門關起來
///Q: 如何用mouse來轉動 物體 A: mouse按下去,mouse移動,mouse放開來
int oldX=0;
void mouse(int button, int state, int x, int y)
{
    oldX = x;
}
void motion(int x, int y)
{///step03-1 新加的 mouse motion
    angle += (x-oldX);
    oldX = x;
}
int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week06");

    glutMotionFunc(motion); ///step03-1 新加的 mouse motion
    glutMouseFunc(mouse);   ///step03-2 新加 mouse函式
    glutDisplayFunc(display);
    glutIdleFunc(display);

    glutMainLoop();
}
