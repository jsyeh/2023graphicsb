# 2023graphicsb
2023電腦圖學 資傳二乙 上課的程式

# Week01

## step01-1_介紹上課的規定、帶大家加入Blog發布文章


## step02-1_第一個OpenGL程式

## step02-2_第一個GLUT程式,並示範blog怎麼寫

1. 點開 freeglut 壓縮檔, 再把freeglut目錄拉到桌面上, 就好了!! 但要偽裝一下
2. 把 桌面\freeglut\lib  目錄裡的 libfreeglut.a 複製成 libglut32.a
3. CodeBlocks: File-New-Project, 選 GLUT專案, 專案名: week01-2_GLUT 再把 GLUT 的目錄, 設成 桌面的 freeglut 就可以執行了!!!

## step02-3_介紹CodeBlocks的View-Manager及View-Perspective怎麼設定工具列

## step03-1_介紹WebGL及如何切換CodeBlocks的專案,介紹回家作業

## step03-2_介紹Git指令上傳GitHub

### 建立 GitHub 倉庫

0. 登入 GitHub 開新的倉庫
0.1. sign in 進去 (帳號、密碼)
0.2. Add 新增一個倉庫
0.3. 取名字 2023graphicsb
0.4. 介紹它
0.5. public
0.6. 勾 README.md
0.7. .gitignore 選 C++

### 接下來, 要在 Git 指令, 把今天程式上傳

1. 先安裝 Git 軟體
1.1. 在桌面 葉正聖老師 或 Teams 或 Moodle 
1.2. 安裝時, 要按 20 下
1.3. 開啟 Git Bash (不用 view 網頁啦) 小黑出來了
1.4. cd desktop    進入桌面
1.5. git clone https://github.com/帳號/2023graphicsb
1.5. cd 2023graphicsb    進入你硬碟裡的倉庫
1.6. start .   會開啟檔案總管,把現在的目錄開起來

2. 把今天程式放進去 桌面的 2023graphicsb 的目錄裡
2.1. week01-1_OpenGL  複製整個目錄
2.2. week01-2_GLUT  複製整個目錄

3. git 加進帳冊
3.1. git status  (紅色的)
3.2. git add .   (要小心空格, 有個點)
3.3. git status  (綠色的)

4. git 確認認可你的修改, 配合訊息
4.0. git config --global user.email jsyeh@mail.mcu.edu.tw
4.0. git config --global user.name jsyeh
4.0. 少了上面的設定,會失敗, 因為 who you are?
4.1. git commit -m "第一週的程式"

5. git 推送上雲端
5.1. 登入 Chrome 的 GitHub
5.2. git push 

# Week02

## step01-1_親手打造GLUT程式10行, File-New-Project,GLUT專案,在桌面 week02-1_GLUT_first 專案, 再把 freeglut 的資料夾 解到桌面上, 再把 freeglut的lib的libfreeglut.a 複製成 libglut32.a 便偽裝好。便能設定GLUT並完成。挑出10行程式碼

我們要從 GLUT 範例中, 剪貼10行程式碼
```cpp
#include <GL/glut.h>  //step01-1 使用 GL/glut.h
void display()
{
	glutSolidTeapot( 0.3 ); /// 畫出實心的茶壼
	glutSwapBuffers(); ///交換顯示出來
}
int main(int argc, char *argv[])
{ ///這個 main() 是比較厲害的 main()
    glutInit(&argc, argv);  /// 要開始 GLUT 的功能
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    /// 要設定 GLUT 的顯示模式 ...
    glutCreateWindow("GLUT Shapes"); ///要建一個窗字,叫 "..."
    glutDisplayFunc(display); /// 要顯示的函式 display()
	glutMainLoop(); ///最後要有 glutMainLoop(); 主要迴圈卡最後面
}
```

## step01-2_有了基礎10行GLUT程式(畫茶壼),開始今天的第1行程式(色彩) glColor3f(r,g,b)。比如說 glColor3f(0,1,0) 會設定綠色, glColor3f(1,1,0) 會設定黃色。之後畫的茶壼,會用你設定的色彩來畫。

```cpp
#include <GL/glut.h>  //step01-1 使用 GL/glut.h
void display()
{
    glColor3f(1,1,0); ///step01-2 色彩 黃色
    glutSolidTeapot( 0.5 ); /// 畫出實心的大茶壼

    glColor3f(0,1,0); ///step01-2 色彩 綠色
	glutSolidTeapot( 0.3 ); /// 畫出實心的小茶壼

	glutSwapBuffers(); ///交換顯示出來
}
int main(int argc, char *argv[])
{ ///這個 main() 是比較厲害的 main()
    glutInit(&argc, argv);  /// 要開始 GLUT 的功能
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    /// 要設定 GLUT 的顯示模式 ...
    glutCreateWindow("week02"); ///要建一個窗字,叫 "..."
    glutDisplayFunc(display); /// 要顯示的函式 display()
	glutMainLoop(); ///最後要有 glutMainLoop(); 主要迴圈卡最後面
}
```

## step02-1_有了簡單的10行程式碼,還有glColor3f()之後, 我們要再學會Vertex頂點。glBegin(GL_POLYGON) 開始畫多邊形, glEnd()結束畫多邊形, 中間放很多個 glVertex2f(x,y) 來描出頂點座標。小心, 頂點座標不能共線。

大部分程式碼都和前面一樣, 剪貼就好!

```cpp
#include <GL/glut.h>
void display()
{
    glColor3f(0,1,0); ///綠色的
    glBegin(GL_POLYGON);
        glVertex2f(0,1); ///上面
        glVertex2f(-1,-1);///左下角
        glVertex2f(+1,-1);///右下角
    glEnd();

    glColor3f(1,1,0);
    glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}

int main(int argc, char * argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week02");

    glutDisplayFunc(display);

    glutMainLoop();
}
```

## step02-2_三角形可設一個色彩,也能每個頂點都設定不同的色彩, 所以有人程式的寫法,會把三角色的色彩與頂點放在同一行, 方便閱讀。現在做出彩色的三角形了。

```cpp
#include <GL/glut.h>
void display()
{
    ///glColor3f(0,1,0); ///step02-1 綠色的
    glBegin(GL_POLYGON);
        glColor3f(1,0,0); glVertex2f(0,1); ///上面 紅色
        glColor3f(0,1,0); glVertex2f(-1,-1);///左下角 綠色
        glColor3f(0,0,1); glVertex2f(+1,-1);///右下角 籃色
    glEnd();

    glColor3f(1,1,0);
    glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}

int main(int argc, char * argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week02");

    glutDisplayFunc(display);

    glutMainLoop();
}
```

## step02-3_回家作業需要用很多頂點來畫圖,但頂點座標怎麼來呢,可以用小畫家幫我們算座標。假設小畫家裡是200x200的圖,那把它減掉一半100,0..200的座標,會變成-100...+100的座標。再除一半100.0, 就會變成 -1.0到+1.0 這樣就可以有座標了。另外要小心,y的方向,在數學是y向上、在小畫家是y向下,所以要再加個負號。

```cpp
#include <GL/glut.h>
void display()
{ ///用小畫家幫我們寫程式
    glBegin(GL_POLYGON);
        glVertex2f( (65-100)/100.0, -(54-100)/100.0 );
        glVertex2f( (34-100)/100.0, -(138-100)/100.0 );
        glVertex2f( (59-100)/100.0, -(138-100)/100.0 );
        glVertex2f( (87-100)/100.0, -(53-100)/100.0 );
        ///先減一半,再除一半,y變負號
        ///0...200 => -100...+100 => -1.0  +1.0
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char * argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week02");

    glutDisplayFunc(display);

    glutMainLoop();
}
```

## step03-1_小畫家mspaint也可以幫我們挑選色彩。挑色彩的方法,是用滴管吸色彩,再編輯色彩,便可以看到0...255的色碼。但glColor3f(r,g,b)吃的參數是介於0..1.0的浮點數,所以我們要再把它除 255.0 就好了。

```cpp
#include <GL/glut.h>
void display()
{ ///用小畫家幫我們寫程式   除 255.0 就好了
    glColor3f( 233/255.0, 141/255.0, 128/255.0); 
    ///不可以超過 0...1
    glBegin(GL_POLYGON);
        glVertex2f( (65-100)/100.0, -(54-100)/100.0 );
        glVertex2f( (34-100)/100.0, -(138-100)/100.0 );
        glVertex2f( (59-100)/100.0, -(138-100)/100.0 );
        glVertex2f( (87-100)/100.0, -(53-100)/100.0 );
        ///先減一半,再除一半,y變負號
        ///0...200 => -100...+100 => -1.0  +1.0
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char * argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week02");

    glutDisplayFunc(display);

    glutMainLoop();
}
```


## step03-2_想要畫出圓形,其實只要2行哦! 利用for迴圈,配合glVertex2f()就畫出來。其中的座標, 可以用國中教過的cos()及sin()畫出來,請用直角三角形來理解, x剛好對應cos(), y則對應sin()。如果想要改變半徑,那就再乘上r來調大小。要改位置,就加上 x 和 y 的改變量, 就完成了。

```cpp
#include <GL/glut.h>
#include <math.h>
void myCircle(float r, float x, float y)
{
    glBegin(GL_POLYGON);
    for(float a=0; a<=2*3.141592; a+=0.01){
        glVertex2f( r*cos(a)+x, r*sin(a)+y );
    }
    glEnd();
}
void display()
{
    glColor3f( 233/255.0, 141/255.0, 128/255.0);
    myCircle(0.5, 0, 0);

    glColor3f(1,1,0);
    myCircle(0.3, 0.5, 0.5);

    glColor3f(1,0,0);
    myCircle(0.3, -0.5, 0.5);

    glColor3f(0,1,0);
    myCircle(0.3, -0.5, -0.5);

    glColor3f(0,0,1);
    myCircle(0.3, 0.5, -0.5);

    glutSwapBuffers();
}

int main(int argc, char * argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week02");

    glutDisplayFunc(display);

    glutMainLoop();
}
```


## step03-3_將今天的程式上傳到GitHub

0. 安裝 Git, 啟動 Git Bash

1. 進入desktop桌面, 將雲端 clone下來, 進入 2022graphicsb

2. start . 開啟檔案總管, 把今天的 4個程式 copy 到裡面

3. 把今天的檔案 add 加進帳冊

4. 確認/認可 commit 今天的修改
4.0. git config --global user.email jsyeh@mail.mcu.edu.tw
4.0. git config --global user.name jsyeh@mail
4.1. git commit -m "加入week02"

5. 推送 push 上雲端
