///week04-1_rotate 先看範例的177行程式, 把它移到Notepad++
///換上我們上週的程式
#include <GL/glut.h>
float angle = 0; ///step02-1 全域變數 angle角度
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///清畫面
    glPushMatrix(); ///step02-1 備份矩陣
        glRotatef(angle, 0, 1, 0); ///step02-1 轉angle度
        glutSolidTeapot( 0.3 );
    glPopMatrix(); ///step02-1 還原矩陣
    glutSwapBuffers();
    angle++; ///step02-1 角度 ++
}
int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week04");

    glutDisplayFunc(display);
    glutIdleFunc(display); ///step02-1 閒閒有空,就重畫畫面
    glutMainLoop();
}
