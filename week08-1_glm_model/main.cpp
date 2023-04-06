///Week08-1_glm_model
///��d�ҥ��R,����W�W�g���{�����ӥ�
#include <GL/glut.h>
#include "glm.h" ///step02-1 �� source.zip�̪� glm.h ��b�P�ؿ���
GLMmodel * pmodel = NULL; ///step02-1 �ҫ�������,�@�}�lNULL�Ū�
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    if(pmodel==NULL){ ///�Ĥ@���|�i�� step02-1
        pmodel = glmReadOBJ("Gundam.obj");///step03-1 ���Gundam���ҫ�
        glmUnitize(pmodel);///step02-2 �Y��Unit���j�p(-1..+1)
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

