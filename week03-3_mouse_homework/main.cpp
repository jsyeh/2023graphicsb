///week03-3_mouse_homework
///如果了解 void mouse()函式, 有機會用它來幫忙寫程式,
///讓作業可以做得更漂亮。開新的 GLUT專案 week03-3_mouse_homework 來做事。
///(1) File-New-Project, GLUT專案
///(2) 貼上 week03-2_translate_mouse 的程式
///(3) 要使用 if()及printf()
#include <GL/glut.h>
#include <stdio.h> ///step03-2 printf()
float X=0, Y=0, Z=0; ///step03-1 使用 global 變數
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );///step03-1 清背景
    ///step03-2 把程式刪掉,留下 glClear()清背景 glutSwapBuffers()交換畫出

    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.02, 0.23);
    glVertex2f(-0.02, 0.29);
    glVertex2f(0.00, 0.40);
    glVertex2f(0.03, 0.50);
    glVertex2f(0.09, 0.59);
    glVertex2f(0.19, 0.65);
    glVertex2f(0.32, 0.66);
    glVertex2f(0.41, 0.59);
    glVertex2f(0.43, 0.44);
    glVertex2f(0.41, 0.38);
    glVertex2f(0.39, 0.34);
    glVertex2f(0.35, 0.30);
    glVertex2f(0.31, 0.27);
    glVertex2f(0.27, 0.22);
    glVertex2f(0.25, 0.19);
    glVertex2f(0.23, 0.17);
    glVertex2f(0.21, 0.15);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.39, 0.14);
    glVertex2f(-0.45, 0.18);
    glVertex2f(-0.51, 0.25);
    glVertex2f(-0.57, 0.37);
    glVertex2f(-0.57, 0.50);
    glVertex2f(-0.45, 0.65);
    glVertex2f(-0.37, 0.67);
    glVertex2f(-0.31, 0.65);
    glVertex2f(-0.29, 0.53);
    glVertex2f(-0.33, 0.43);
    glVertex2f(-0.33, 0.34);
    glVertex2f(-0.33, 0.25);
    glVertex2f(-0.33, 0.21);
    glVertex2f(-0.30, 0.18);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-0.46, 0.10);
    glVertex2f(-0.34, 0.18);
    glVertex2f(-0.15, 0.25);
    glVertex2f(0.05, 0.24);
    glVertex2f(0.27, 0.11);
    glVertex2f(0.25, -0.05);
    glVertex2f(0.09, -0.11);
    glVertex2f(-0.10, -0.15);
    glVertex2f(-0.28, -0.15);
    glVertex2f(-0.49, -0.06);
    glEnd();
    glutSwapBuffers();
}
void mouse( int button, int state, int x, int y ) ///step03-1 mouse()
{       ///     左中右鍵    按下/放開 小x   小y   0...300
    X =  (x-150)/150.0; ///step03-1 減一半、除一半
    Y = -(y-150)/150.0; ///step03-1 減一半、除一半、y變負的
    ///printf("%d %d %d %d\n", button, state, x, y); ///step03-2 先試印參數
    if(state==GLUT_DOWN) printf("    glVertex2f(%.2f, %.2f);\n", X, Y); ///step03-2
}
int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week03");

    glutMouseFunc(mouse); ///step03-1 設定好 mouse函式
    glutDisplayFunc(display);

    glutMainLoop();
}
