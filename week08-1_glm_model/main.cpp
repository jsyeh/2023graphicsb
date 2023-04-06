///Week08-1_glm_model
///把範例全刪,先把上上週的程式拿來用
#include <GL/glut.h>
#include "glm.h" ///step02-1 把 source.zip裡的 glm.h 放在同目錄中
GLMmodel * pmodel = NULL; ///step02-1 模型的指標,一開始NULL空的
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    if(pmodel==NULL){ ///第一次會進來 step02-1
        pmodel = glmReadOBJ("Gundam.obj");///step03-1 改用Gundam的模型
        glmUnitize(pmodel);///step02-2 縮放成Unit單位大小(-1..+1)
    }
    glmDraw(pmodel, GLM_SMOOTH | GLM_MATERIAL); ///step02-1

    ///glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week08");

    glutDisplayFunc(display);
    glutMainLoop();
}

