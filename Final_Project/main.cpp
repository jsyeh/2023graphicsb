///Final_Project 之後都用同一個程式,來進行 Final Project
#include <stdio.h> ///要檔案的Input/Output
#include <GL/glut.h>
#include "glm.h" ///week13_step02-2
///week13_step02-2 再把 glm.cpp 在左邊 Add files 加進去
GLMmodel * head = NULL;///week13_step02-2
GLMmodel * body = NULL;///week13_step02-2
GLMmodel * uparmR = NULL;
GLMmodel * lowarmR = NULL;
int show[4] = {1,0,0,0}; ///week13_step03-1
float teapotX = 0, teapotY = 0;
FILE * fout = NULL;///step02-1
FILE * fin = NULL;///step02-2
void keyboard(unsigned char key, int x, int y) {///week13_step03-1
    if(key=='0') show[0] = ! show[0];///week13_step03-1
    if(key=='1') show[1] = ! show[1];///week13_step03-1
    if(key=='2') show[2] = ! show[2];///week13_step03-1
    if(key=='3') show[3] = ! show[3];///week13_step03-1
    glutPostRedisplay();///week13_step03-1
}///week13_step03-1
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    if(head==NULL){///week13_step02-2
        head = glmReadOBJ("model/head.obj");///week13_step02-2
        body = glmReadOBJ("model/body.obj");
        uparmR = glmReadOBJ("model/uparmR.obj");
        lowarmR = glmReadOBJ("model/lowarmR.obj");
        ///glmUnitize(head); ///week13_step02-2 之後會改
    }///week13_step02-2
    glPushMatrix();
        glScalef(0.3, 0.3, 0.3);///week13_step02-3
        if(show[0]) glmDraw(head, GLM_MATERIAL);///week13_step02-3
        if(show[1]) glmDraw(body, GLM_MATERIAL);///week13_step02-2
        if(show[2]) glmDraw(uparmR, GLM_MATERIAL);///week13_step02-3
        if(show[3]) glmDraw(lowarmR, GLM_MATERIAL);///week13_step02-3
        ///week13_step03-1 加上 if(show[??]) ...
    glPopMatrix();
    glutSwapBuffers();
}
void mouse(int button, int state, int x, int y)
{
    teapotX = (x-150)/150.0;
    teapotY = (150-y)/150.0;
    if(state==GLUT_DOWN){ ///如果mouse按下去
        if(fout==NULL) fout = fopen("file4.txt", "w");

        fprintf(fout, "%f %f\n", teapotX, teapotY);
    }
    display();
}
///void keyboard(unsigned char key, int x, int y)///step02-2
///{
///    if(fin==NULL){
///        fclose(fout);///step02-2
///        fin = fopen("file4.txt", "r");///step02-2
///    }
///    fscanf(fin, "%f%f", &teapotX, &teapotY);///step02-2
///    display();///step02-2
///}///step02-2
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard); ///step02-2
    glutMouseFunc(mouse); ///step02-1

    glutMainLoop();
}
