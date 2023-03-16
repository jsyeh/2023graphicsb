///Week05-1_TRT_translate_rotate 把上週的 week04-1 拿來用
///旋轉軸改成 0,0,1 z軸, 再複製成 紅色、綠色
#include <GL/glut.h>
float angle = 0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1, 0, 0);///紅色
    glPushMatrix();
        glRotatef(angle, 0, 0, 1); ///step02-1 改成 0,0,1 z軸
        glTranslatef(0.8, 0, 0);///移到右邊
        glutSolidTeapot( 0.3 );
    glPopMatrix();

    glColor3f(0, 1, 0);///綠色
    glPushMatrix();
        glTranslatef(0.8, 0, 0);///移到右邊
        glRotatef(angle*1.5, 0, 0, 1); ///step02-1 改成 0,0,1 z軸
        glutSolidTeapot( 0.3 );
    glPopMatrix();

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
