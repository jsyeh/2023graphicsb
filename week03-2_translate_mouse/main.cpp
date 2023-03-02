///week03-2_translate_mouse 要加上 mouse 的移動功能
///(1) File-New-Project, GLUT專案
///(2) 貼上 week03-1_translate 的程式
///(3) 要使用 global 變數,來讓座標改變
#include <GL/glut.h>
float X=0, Y=0, Z=0; ///step03-1 使用 global 變數
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );///step03-1 清背景
    glPushMatrix(); ///備份矩陣
        glTranslatef( X, Y, Z ); ///step03-1 照著 X,Y,Z來移動
        glutSolidTeapot( 0.3 );
    glPopMatrix(); ///還原矩陣

    glutSwapBuffers();
}
void mouse( int button, int state, int x, int y ) ///step03-1 mouse()
{       ///     左中右鍵    按下/放開 小x   小y   0...300
    X =  (x-150)/150.0; ///step03-1 減一半、除一半
    Y = -(y-150)/150.0; ///step03-1 減一半、除一半、y變負的
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
