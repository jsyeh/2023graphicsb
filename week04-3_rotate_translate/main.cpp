///week04-3_rotate_translate
///換成 week04-1_rotate的程式,拿來改寫
#include <GL/glut.h>
float angle = 0; ///step02-1 全域變數 angle角度
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///清畫面

    glPushMatrix(); ///step02-1 備份矩陣
        glTranslatef(0.5, 0, 0);///step03-3 移到右邊的
        glRotatef(angle, 0, 1, 0); ///step03-3 旋轉中的
        glColor3f(0,0,1);///step03-3 藍色的
        glutSolidTeapot( 0.3 ); ///茶壼
    glPopMatrix(); ///step02-1 還原矩陣

    glPushMatrix(); ///step02-1 備份矩陣
        glRotatef(angle, 0, 1, 0); ///step03-4 旋轉中的
        glTranslatef(0.5, 0, 0);///step03-4 移到右邊的
        glColor3f(1,1,0);///step03-4 黃色的
        glTranslatef(0, 0.5, 0); ///step03-4 往上移動的
        glutSolidTeapot( 0.3 ); ///茶壼
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
