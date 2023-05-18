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

- 0. 安裝 Git, 啟動 Git Bash
- 1. 進入desktop桌面, 將雲端 clone下來, 進入 2022graphicsb
- 2. start . 開啟檔案總管, 把今天的 4個程式 copy 到裡面
- 3. 把今天的檔案 add 加進帳冊
- 4. 確認/認可 commit 今天的修改
- 4.0. git config --global user.email jsyeh@mail.mcu.edu.tw
- 4.0. git config --global user.name jsyeh@mail
- 4.1. git commit -m "加入week02"
- 5. 推送 push 上雲端


# Week03
電腦圖學 2023-03-02 Week03
1. 技巧: 用 mouse 幫忙寫作業
2. 主題: 移動 Translate
3. 實作: glTranslatef(x,y,z) 配合 glPushMatrix() glPopMatrix()
4. 問題與回覆Q&A: Blog, 作業

## step01-0_上課前,先介紹HW1、HW2的評分方式,老師使用HTML配合Browser來一起評分。介紹Blogger裡可以改日期, 要加上適當的標題,以推廣你的品牌, 要加上正確標籤,才能評分。顯示名稱只是字串,你可在設定裡自己改。不可以偷老師的圖、老師的字。

## step01-1_要下載課本的範例, 跑 Transformation.exe 並看它的glTranslatef()移動部分的參數

- https://jsyeh.org/3dcg10 下載 windows.zip 及 data.zip
	- windows.zip 解壓縮 下載\windows\Transformation.exe (今天的主角)
	- data.zip    解壓縮 下載\windows\data\很多3D模型檔  (小心目錄)
- 執行(今天的主角) 
	- glTranslatef( x, y, z ); 綠色的數字,上下拉動它
	- (其他也可以看看, 下週會教)
	- (右上角可右鍵換模型)
- 如果閃退, 就是你的 data.zip 解錯目錄
	- 不是 下載\windows\data\data\很多模型檔
	- 是 下載\windows\data\很多模型檔

## step02-1_CodeBlocks-File-New-Project, GLUT專案, 檔名 week03-1_translate (事先要把 freeglut 裝好,改出 libglut32.a ), 貼上上週的10行GLUT程式。

```cpp
///把177行程式全刪, 貼上上週的10行GLUT程式
#include <GL/glut.h>
void display()
{
    glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}
int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week03");

    glutDisplayFunc(display);

    glutMainLoop();
}
```

## step02-2_想要貼出漂亮的程式碼,可用 GitHub Gist功能, 新增一段程式, 檔名寫好,會照副檔名(.c .cpp .java .cs .py .html .javascript .css) 的文法來變色。使用 Embedded JavaScript 的方式, 便能把那一行程式, 用 HTML模式, 插到你Blog的 HTML 裡面, 前提是你要看得懂 HTML 才能正確插入。

```html
<script src="https://gist.github.com/jsyeh/45baebf225cf360aeb9d746ec35b6743.js"></script>
```

## step02-3_實作: glTranslatef(x,y,z) 配合 glPushMatrix() glPopMatrix() 便能正確將物體移到想要的位置。程式的排版有點奇怪,會在 push時往右推, pop時往左還原。。


```cpp
///把177行程式全刪, 貼上上週的10行GLUT程式
#include <GL/glut.h>
void display()
{
    glPushMatrix(); ///備份矩陣
        glTranslatef( 0.5, 0.5, 0); ///它會改變你的矩陣
        glutSolidTeapot( 0.3 );
    glPopMatrix(); ///還原矩陣

    glutSwapBuffers();
}
int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week03");

    glutDisplayFunc(display);

    glutMainLoop();
}
```

## step03-1_想要加上 mouse 的移動功能, 所以新增GLUT專案 week03-2_translate_mouse 裡面模仿前面的程式, 但再配合 global 變數 float X=0, Y=0, Z=0; 來讓 glTranslate(X, Y, Z); 照著移動。 void mouse() 裡面, 用小寫的x,y參數,換算出 -1..+1的座標。glutMouseFunc(mouse)會註冊好mouse()函式的。

```cpp
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
```

## step03-3_如果了解 void mouse()函式, 有機會用它來幫忙寫程式, 讓作業可以做得更漂亮。開新的 GLUT專案 week03-3_mouse_homework 來做事。


```cpp
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
```

## step03-3_將程式用 Git指令上傳

- 0. 安裝Git, 開啟 Git Bash
- 1. 進入 cd desktop, 雲端 git clone https://網址下載, 進入cd 2023graphicsb
- 2. start . 開啟檔案總管, 把今天的程式複製進來
- 3. 用 git add . 加入帳冊 (前後用 git status 綠色紅色)
- 4. 用 git commit -m "訊息" 確認、認可
- 4.0. git config --global user.email jsyeh@mail.mcu.edu.tw
- 4.0. git config --global user.name jsyeh
- 4.0. 要做上面2行, 才會知道 who you are
- 4.1. git commit -m "add week03"
- 5. 用 git push 推送上雲端


# Week04

1. 主題: 旋轉 Rotate
2. 實作: glRotatef(角度, x, y, z);
3. 主題: 矩陣 Matrix
4. 利用 mouse motion 來控制

## step01-1_上課的範例 jsyeh.org/3dcg10 下載 data win32, 解壓縮到對的目錄, 執行Transformation.exe 並且觀察它的轉法,使用右手來理解, 姆指是轉動軸, 其餘四指是轉動的方向。

windows.zip => 下載\windows\Transformation.exe
data.zip    => 下載\windows\data\模型檔

## step01-2_先了解「旋轉軸為Y軸」時怎麼轉, 再了解「旋轉軸為X軸」是怎麼轉。最後要了解「Z軸」是怎麼轉。在右手座標系統裡,z軸是「用右手4指,本來向著x軸,掃向y軸後, 決定z軸的方向」

## step01-3_如果是奇怪的旋轉軸, ex. (1,1,0)的話, 請想像在吃塩酥雞時,用竹籤去插塩酥雞時, 無聊的人在轉竹籤時, 就是那個感覺。所以可以看到人物的右肩往前撞的畫面。

## step02-0_要開起 CodeBlocks File-New-Project 存成 week04-1_rotate 專案 (先把桌面的 freeglut 裝好, 記得 lib的 libfreeglut.a 複製成 libglut32.a)。

## step02-1_先研究一下177行範例程式, 裡面的 display()有6塊程式, 會用 glPushMatrix() 與 glPopMatrix() 把程式包起來, 裡面有移動or旋轉的程式碼, 然後畫茶壼。把程式改成上週的10行GLUT程式, 然後利用全域變數 angle角度 float angle = 0; 接著在 display()裡, glRotatef(angle, 0, 1, 0) 轉動angle度, 最後 angle++ 增加一些角度。main()裡則是在 glutDisplay() 旁邊加上 glutIdleFunc(display) 告訴GLUT閒閒有空時,就重畫畫面。接著便看到茶壼在轉動了。

```cpp
///先看範例的177行程式, 把它移到Notepad++
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
    glutCreateWindow("week03");

    glutDisplayFunc(display);
    glutIdleFunc(display); ///step02-1 閒閒有空,就重畫畫面
    glutMainLoop();
}
```

## step02-2_讓大家看到打光的結果。請開新的 GLUT專案, week04-2_rotate_light 專案。在 177行程式裡, 用 Ctrl-F找light這個字, 可以找到2大段程式碼。再把 week04-1_rotate的程式拿來改造, 加上剛找到的2大段程式, 便能完成打光。

最前面先放陣列的宣告

```cpp
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
```
我們要發明一個函式 void myLight() 裡面有以下程式
```cpp
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
```

最後在 main() 裡面呼叫 myLight()函式, 便能簡單完成打光的設定。
(目前的打光還有點怪怪的, 前後的面有倒過來, 導致光的位置不對。先不管怪怪的問題。)


```cpp
///Week04-2_rotate_light 先貼上剛剛的程式 week04-1_rotate
#include <GL/glut.h>
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

void myLight()
{
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

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

    myLight(); ///step02-2
    glutDisplayFunc(display);
    glutIdleFunc(display); ///step02-1 閒閒有空,就重畫畫面
    glutMainLoop();
}
```


## step03-1_在Transform的範例中,可以交換swap translate和rotate的程式, 竟然會造成自轉、公轉的差別。但到底怎麼理解呢, 有個口訣是「左耳靠在左肩上, 讀程式就從下往上讀」。

```
藍色的車子
```

```
長胖的
藍色的車子
```

```
移到右邊的
長胖的
藍色的車子
```

```
轉動整個世界,
裡面有移到右邊的
長胖的
藍色的車子
```

```cpp
glRotatef(angle, 0, 1, 0);
glTranslatef(0.59, 0, 0);
glScalef(1.53, 1, 1);
glBegin(...) 畫出藍色的車子
```

## step03-2_老師拿2個範例來解釋
下面則是另外一個程式

```cpp
glTranslatef(0.59, 0, 0); //這兩行交換
glRotatef(angle, 0, 1, 0); //這兩行交換
glScalef(1.53, 1, 1);
glBegin(...) 畫出藍色的車子
```

```
藍色的車子
```

```
長胖的
藍色的車子
```

```
轉動
長胖的
藍色的車子
```

```
把下面那個移到右邊去
轉動
長胖的
藍色的車子
```


## step03-3_新開 GLUT專案 week04-3_rotate_translate, 先把 week04-1_rotate複製過來, 把它變成藍色的 glColor3f(0,0,1)


```cpp
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
```

## step03-4_再畫出另外一個寫法, 同時標示框線

```cpp
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
```

## step03-5_最後用 Git 把今天的程式上傳到GitHub
- 0. 安裝Git, 開Git Bash
- 1. 進入桌面 cd desktop 複製你的程式 git clone https://網址  再進入你的目錄 2023graphicsb
- 2. 開啟檔案總管 start . 整理今天的程式
- 3. 加入 git add .
- 4. 確認 git commit -m "week04"
- 4.0. git config --global user.email jsyeh@mail.mcu.edu.tw
- 4.0. git config --global user.name jsyeh
- 4.1. git commit -m week04
- 5. 推送上雲端 git push


# Week05

## step01-1_把上課的教材 jsyeh.org 的 3dcg10 裡的 data 及 windows.zip 下載、執行Transformation.exe 要先複習上週的「移動-旋轉」與「旋轉-移動」

「移動-旋轉」
```cpp
glTranslatef(0.8, 0, 0); //移動到右邊
glRotatef(角度, 0, 1, 0);//旋轉
glScalef(1, 2, 1);//長高的
glBegin(...);// 藍色車子
...
```

與「旋轉-移動」
```cpp
glRotatef(角度, 0, 1, 0);//旋轉
glTranslatef(0.8, 0, 0); //移動到右邊
glScalef(1, 2, 1);//長高的
glBegin(...);// 藍色車子
...
```

## step01-2_新開GLUT專案,week05-1_TRT_translate_rotate 看兩種不同的轉動的差別。先把week04-1的程式複製過來, 再把 display()裡, 改成 紅色茶壼、綠色茶壼, 裡面的轉動、移動的順序不同。

```cpp
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
```

## step02-1_要用老師的 opengl_TRT_demo 的互動程式 跑起來。按 ToDraw 可以畫身體、畫頭、畫手。可按住程式碼,移動它的位置。先只放一個旋轉(在手的前面,只影響手)會對正中心轉, 有點怪怪的。改成移動, 讓手臂的關節移到正中心。再來,把轉動加上去, 手臂會在肚臍上轉動, 有點變態。最後, 把移動加上去, 讓旋轉中的手臂「掛」到肩膀上。

```cpp
myDrawObject(0); //畫身體
glPushMatrix();
  glTranslatef(0.17, 0.38, 0);  //(3) 最後,把手臂掛到肩上
  glRotatef(angle, 0, 0, 1);    //(2) 轉動
  glTranslatef(-0.17, -0.38, 0);//(1)把關節放正中心
  myDrawObject(1); //畫手臂
glPopMatrix();
```

## step02-2_接下來講解下週的考試題目, 以奇異博士手上拿著寶石為例, drawHand()可以畫手,但它的旋轉中心沒有放在正中心, 怎麼辦 (1) 先把關節移到正中心。(2)上面再加上轉動,小心轉動軸不要寫錯、角度的正負號也不能寫錯。(3)最後, 最上面,就簡單的把會轉動的手「掛到」手肘上面去。

```cpp
glPushMatrix();
  glTranslatef(-0.5, -0.9, 0); //20分, (3) 最後,把它掛在肩上
  glRotatef(-45, 0,0,1);       //20分, (2) 轉動,小心正負號
  glTranslatef(-0.8, 0.9, 0);  //20分, (1) 把關節移到正中心
  drawHand(); 
glPopMatrix();
```

## step03-1_開新GLUT專案, week05-2_TRT_robot 要做出TRT關節轉動。先把 week05-1的程式拿來改。用 glutSolidCube(1)可畫出寬度1的方塊, 發明myCube()函式,可以用glScalef(0.5, 0.2, 0.2) 把方塊調成細長狀, 再把矩陣保護起來。再來用小考的T-R-T觀念, 慢慢把方塊變成正確轉動的手臂 (1) 調中心, (2)轉動, (3)掛到對的位置。

```cpp
///Week05-2_TRT_robot 貼上 week05-1_TRT_translate_rotate 的程式
///Week05-1_TRT_translate_rotate 把上週的 week04-1 拿來用
///旋轉軸改成 0,0,1 z軸, 再複製成 紅色、綠色
#include <GL/glut.h>
float angle = 0;
void myCube()///step2 改函式
{
    glPushMatrix();///step1
        glScalef(0.5, 0.2, 0.2);///step1 調大小
        glutSolidCube(1); ///step1 正方塊
    glPopMatrix();///step1
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1,1,1);///step4 白色的
    glutSolidCube(1); ///step4 身體

    glPushMatrix();///step2
        glTranslatef(x
        glColor3f(0,1,0);///step4 綠色的
        myCube(); ///step2 改函式
    glPopMatrix();///step2

    glPushMatrix();///step2
        glTranslatef(-0.5, 0.5, 0);///step5 掛到右上角去
        glRotatef(angle, 0, 0, 1);///step2 轉它
        glTranslatef(0.25, 0, 0);///step3 往右移動 0.25 讓關節在正中心
        glColor3f(0,1,0);///step4 綠色的
        myCube(); ///step2 改函式
    glPopMatrix();///step2

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
```

## step03-2_了解 Matrix在做什麼事。其實就是改變座標, 程式碼倒著看, 是因為最下面畫點的時候, 結合的順序是慢慢往上理解。因此理解時,就從下往上看。電腦運算時, 從上往下改變矩陣。

## step03-3_用Git指令, 上傳今天的2個程式到GitHub

- 0. 安裝 Git 開啟 Git Bash
- 1. 進入桌面 cd desktop 雲端複製下來 git clone 網址, 再進入 cd 2023graphicsb
- 2. 開啟檔案總管 start . 整理今天的程式
- 3. 加入帳冊 git add .
- 4. 確認修改 git commit -m week05 
- 4.0 要先 git config --global user.email jsyeh@mail.mcu.edu.tw
- 4.0 要先 git config --global user.name jsyeh
- 4.1 git commit -m week05
- 5. git push 推上雲端

如果想要偽造時間, 可用 git commit -m week05 --date="2023-03-16 15:00:00" 
這樣在 GitHub 裡看你的打卡時間, 就會用右邊的時間。


# Week06

## step01-0_介紹今天的T-R-T考試 

```cpp
glPushMatrix();
  glTranslatef(-0.3, -0.1, 0);
  glRotatef(-45, 0, 0, 1);
  glTranslatef(-0.1, +0.4, 0):
  drawHand();
glPopMatrix();
```


## step01-1_開新的 GLUT 專案  Week06-1_TRT_robot2_teapot, 使用上週的 week05-2_TRT_robot 的程式 拿來改, 把 display()改畫茶壼,用glPushMatrix()和glPopMatrix()包起來, 再照考試時的T-R-T 慢慢調好, 不過還沒有把東西掛上去

```cpp
///Week06-1_TRT_robot2_teapot
///全刪, 改用上週的 week05-2_TRT_robot 的程式來改
#include <GL/glut.h>
float angle = 0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glutSolidSphere(0.01, 30, 30); ///step01-1 小球做中心點參考

    glPushMatrix();
		//(3) 這行則是要決定掛在哪裡
        glRotatef(angle, 0, 0, 1);///(2)
        glTranslatef(0.45, 0, 0); ///(1)
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
```

## step02-1_新開 week06-2_TRT_robot3_hierarchy 有階層的TRT, 程式和 week06-1 與 week05-2 有點像。會有很多層的 T-R-T。為簡化程式碼, 我們使用 void myCube()函式, 裡面有push pop matrix 保護裡面的 glScalef() 畫的 glutSolidCube()

```cpp
///Week06-2_TRT_robot3_hierarchy 有階層的
///全刪, 改用上週的 week05-2_TRT_robot 的程式來改
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

    glPushMatrix();
        ///glTranslatef(0.5, 0.5, 0);///(3) 這行則是要決定掛在哪裡
        glRotatef(angle, 0, 0, 1);///(2)
        glTranslatef(0.25, 0, 0); ///(1)
        myCube();
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
```

然後再把 display() 再加上兩行
```cpp
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glutSolidSphere(0.01, 30, 30); ///step01-1 小球做中心點參考

    glPushMatrix();
        ///glTranslatef(0.5, 0.5, 0);///(3) 這行則是要決定掛在哪裡
        glRotatef(angle, 0, 0, 1);///(2)
        glTranslatef(0.25, 0, 0); ///(1)
        myCube();
    glPopMatrix();

    glutSwapBuffers();
    angle++;
}
```

最後把 glTranslatef(0.25, 0, 0); 掛到右邊。

## step02-2_接下來, 便是Hierarchy階層性轉動的效果, 把剛剛的程式碼, 像階層一樣, 上一層包下一層


```cpp
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glutSolidSphere(0.01, 30, 30); ///step01-1 小球做中心點參考

    glPushMatrix();
        glTranslatef(0.25, 0, 0); ///(3) 這行則是要決定掛在哪裡
        glRotatef(angle, 0, 0, 1);///(2)
        glTranslatef(0.25, 0, 0); ///(1)
        myCube();
        glPushMatrix();
            glTranslatef(0.25, 0, 0); ///(3) 這行則是要決定掛在哪裡
            glRotatef(angle, 0, 0, 1);///(2)
            glTranslatef(0.25, 0, 0); ///(1)
            myCube();
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
    angle++;
}
```

## step02-3_新的程式 week06-3_TRT_robot4_arm_hand_right_left 要模依右邊的上手臂、下手肘, 做出左邊的上手臂、下手肘。左邊的部分,要小心移動的正負號。

要很小心排版, 才不會把 glPushMatrix() glPopMatrix() 弄錯。

```cpp
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
        glRotatef(angle, 0, 0, 1);///(2)
        glTranslatef(-0.25, 0, 0); ///(1)
        myCube(); ///上手臂
        glPushMatrix();
            glTranslatef(-0.25, 0, 0); ///(3) 這行則是要決定掛在哪裡
            glRotatef(angle, 0, 0, 1);///(2)
            glTranslatef(-0.25, 0, 0); ///(1)
            myCube(); ///下手肘
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
    angle++;
}
```

## step03-1_新的 week06-4_TRT_robot5_mouse_motion_angle 想要利用 mouse motion 來控制 angle角度。先把左邊的 glRotatef(angle, 0, 0, 1) 改成 -angle, 讓左邊剛好鏡射右邊。增加 void motion()函式, 再利用 glutMotionFunc(motion) 來註冊新加的 mouse motion 函式。接下來便可以利用 mouse motion 拖曳,來控制角度了。

```cpp
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
void motion(int x, int y)
{///step03-1 新加的 mouse motion
    angle = x;
}
int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week06");

    glutMotionFunc(motion); ///step03-1 新加的 mouse motion
    glutDisplayFunc(display);
    glutIdleFunc(display);

    glutMainLoop();
}
```

## step03-1b_期中考題講解


## step03-2_最後還有時間,老師教mouse motion來準確控制angle角度。使用的方法是 int oldX=0; 外部變數, 等一下要拿來做計算。glutMouseFunc(mouse) 要註冊 void mouse(int button, int state, int x, int y) 裡面會把 oldX = x 設定好。 glutMotionFunc(motion)要註冊 void motion(int x, int y)函式, 裡面會修改 angle += (x-oldX); 並更新 oldX = x;

```cpp
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
```

## step03-3_用 Git 指令上傳今天的程式碼

- 0. 安裝 Git, 開 Git Bash
- 1. cd desktop 再 git clone https://網址 再 cd 2023graphicsb
- 2. start . 開檔案總管,整理今天的程式
- 3. git add . 把今天的修改加到帳冊中
- 4.0. git config --global user.email jsyeh@mail.mcu.edu.tw
- 4.0. git config --global user.name jsyeh
- 4.1. git commit -m week06
- 5. git push 推送上雲端

# Week07

## step01-1_請先到 jsyeh.org的3dcg10下載上課的程式 data 與 windows, 解壓縮後, 在 windows 裡有 data資料夾(內含圖檔、模型檔) 還有今天的主角 Texture.exe, 請執行它, 看一下不同的色彩, 會與貼圖互相影響。接下來理解4個頂點的逆時針繞的關係, 通常用右手座標系統(有些軟體會反過來)。試著調 glVertex3f()的座標, 了解點在哪裡。對應的貼圖的的座標也看一下。

## step01-2_要試著講解貼圖的座標的意思。在改貼圖座標時, 貼圖座標介於0到1之間。但是如果超過這個範圍, 有幾種不同的作法, 如果是GL_REPEAT的話, 就會又切回 0到1之間重覆。有時候會改設成左右上下鏡射,有時候直接拿 0 或 1的值。現在這個程式範例是0到1之間重覆。 

## step01-3_讀圖檔很麻煩, 在課本的範例, 用了 texture.c 配上 sgi.h sgi.c 才只能讀一個 .sgi 過時的檔名。所以今天老師要用 2行, 把所有的圖檔都讀進來。先回頭看一下期中考題, 使用老師的網站 jsyeh.org 的 gl 裡面有 OpenGL圖學期中考-模擬練習。老師示範, 讓同學練習。

```cpp
1.  glPushMatrix(); //備份矩陣
2.    glTranslatef(x, y, z); //移動
3.    glRotatef(angle, x, y, z); //轉動
4.    glScalef(x, y, z); //縮放
5.    glBegin(GL_POLYGON); //開始畫
6.      glColor3f(r, g, b);//色彩
7.      glNormal3f(nx, ny, nz); //打光的法向量
8.      glTexCoord2f( tx, ty );//貼圖座標
9.      glVertex3f(x, y, z);//頂點
10.   glEnd(); //結束畫
11. glPopMatrix(); //還原矩陣
```

## step02-1_第二節課才來實作圖檔的部分。使用OpenCV最簡單,但是不要用最新版,因為太大了, 而且只能在最新的Visual Studio跑。老師建議用 OpenCV 2.1 又小,又快、又跨平台, 各種compiler都能用。在你的桌面-葉正聖老師 OpenCV-2.1.0-win32-vs2008.exe 安裝時, 要勾 Add PATH (不然就完蛋了),預設裝在 C:的OpenCV2.1 不要亂動。「重開CodeBlocks」。還要設定 3個咒語。

- CodeBlocks 的 Setting-Compiler 裡面的 Search directoies 及 Linker setting 要改3個地方
- Compiler 的目錄, 要加 C:\OpenCV2.1\include
- Linker 的目錄, 要加 C:\OpenCV2.1\lib
- Linker setting 裡, 要加 cv210 cxcore210 highgui210 不能拼字拼錯。

## step02-2_接下來要寫3行程式, 分號是 include 你 opencv的highgui.h檔案, 再宣告 IplImage 指標的 img = cvLoadImage("image.jpg"); 同時把圖檔放好, 小心副檔名。 cvShowImage("week07", img); 會在 week07 的視窗秀圖。cvWaitKey(0); 會等任意鍵繼續, 就不會閃退。

```cpp
#include <opencv/highgui.h>

int main()
{
	IplImage * img = cvLoadImage("檔名");
	cvShowImage("week07", img);
	cvWaitKey(0);
}
```

## step03-1_有了 OpenCV 的設定, 我們不只能讀圖、秀圖,還可以把圖拿來做 OpenGL 的貼圖。老師寫了一個範例在 gist.github.com/jsyeh 裡面的 myTexture, 把裡面的 sample 拿來用。新增GLUT專案 week07-2_myTexture (並先把 freeglut裝好,你會的), 再把程式換成 myTexture的版本。最後還要把圖檔放在對的工作執行目錄, 這次的 GLUT專案,會在 freeglut 的 bin 目錄裡面。把 earth.jpg 的圖檔, 放在裡面, 就可以看到囉

```cpp
///Week07-2_myTexture
///程式碼全刪,換我們的 gist.github.com/jsyeh 裡的 myTexture

#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week09 texture");

    glutDisplayFunc(display);
    myTexture("earth.jpg");

    glutMainLoop();
}
```

## step03-2_今天第一節課的 Texture.exe 裡面有一段程式, glBegin(GL_POLYGON) glEnd() 裡面有許多 glTexCoord2f() 與 glVertex3f(), 所以我們把剛剛的 week07-2_myTexture 改寫成自己再釘上4個貼圖的釘子, 看到茶壼的後面有一個地球地圖的背景。

```cpp
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glTexCoord2f(0, 0); glVertex2f(-1, +1);
        glTexCoord2f(1, 0); glVertex2f(+1, +1);
        glTexCoord2f(1, 1); glVertex2f(+1, -1);
        glTexCoord2f(0, 1); glVertex2f(-1, -1);
    glEnd();
    glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}
```

## step03-3_最後一個GLUT專案 week07-3_myEarth 程式來自 gist.github.com/jsyeh 的 myEarth, 裡面稍做修改後, 便可以看到會旋轉的地球。

不過如果地圖的圖檔有錯, 畫出來的地球可能會貼錯圖, 請別太在意。

```cpp
///Week07-3_myEarth 從 gist.github.com/jsyeh 的 myEarth
///全刪,拿剛剛的程式來用!!!
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
GLUquadric * sphere = NULL;///一個指到二次曲面的指標
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle, 0,-1,0);
        glRotatef(90, 1,0,0);
        gluQuadricTexture(sphere, 1);
        gluSphere(sphere, 1, 30, 30);///glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
    angle++;
}
///Week07-3_myEarth 從 gist.github.com/jsyeh 的 myEarth
///全刪,拿剛剛的程式來用!!!
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week07 texture earth");

    glutIdleFunc(display);
    glutDisplayFunc(display);
    myTexture("earth.jpg");
    sphere = gluNewQuadric();
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();
}
```
## step03-4_利用Git指令,把今天的程式(1個檔案、兩個程式專案的目錄)上傳到GitHub
- 0. 安裝 Git 再開啟 Git Bash
- 1. cd desktop 進入桌面, git clone https://網址 再 cd 2023graphicsb
- 2. start . 開啟檔案總管, 整理今天的程式
- 3. git add . 加入帳冊
- 4.0. git config --global user.email jsyeh@mail.mcu.edu.tw
- 4.0. git config --global user.name jsyeh
- 4.1. git commit -m week07
- 5. git push 推送上雲端

# Week08
電腦圖學 2023-04-06 Week08
1. 主題: 3D模型
2. 主題: OBJ檔
3. 主題: glm.h glm.cpp
4. 實作: Gundam 剛彈模型

## step01-1_今天的目標,是3D模型,從jsyeh.org 3dcg10下載 3個檔 source(第二節要看程式碼), data(有模型檔obj,mtl), windows(執行檔), 老師帶同學看 OBJ 檔的內容,並解釋3D模型的檔案格式是怎麼來的。

我們要了解3D模型,是如何產生的

v 對應 vertex頂點
vt 對應 貼圖座標 glTexCoord2f(tx,ty)
vn 對應 vertex normal法向量
f 對應 面facet

## step01-2_自己的3D模型,匯出 OBJ檔(配上一個.mtl), 把程式偷改檔名ex. F-16.obj 把它放到課本範例 windows的data目錄裡(尤其是.obj檔的前面有對應.mtl的檔名,要正確),便可以在課本範例裡, 看到自己的模型。研究一下obj模型檔裡的內容。

## step02-1_新的GLUT專案 week08-1_glm_model, 先從上上週的「白色茶壼」開始做起, 接下來 include glm.h 並把 .h 檔準備好。把 glm.c 變成 glm.cpp 加入專案中。程式部分,把指標 GLMmodel 準備好。3D模型檔案放在「工作執行目錄」(Build log 會顯示 in ...)

- include 後面用 "glm.h" 表示會去同一個目錄裡面找 glm.h
- 所以, 要把 source.zip 裡面的 glm.h 放好, 才能順利編譯compile
- 把 glm.c 改成 glm.cpp 再把它放到剛剛的目錄中
- 在專案裡,右鍵-Add Files,加入 glm.cpp 成功後, 左邊會有 main.cpp glm.cpp
- 3D模型 .obj .mtl 檔案放在「工作執行目錄」 C:\Users\Administrator\Desktop\freeglut\bin
- GLMmodel *pmodel = NULL;
- glmReadOBJ(...)
- glmDraw(...)

```cpp
///Week08-1_glm_model
///把範例全刪,先把上上週的程式拿來用
#include <GL/glut.h>
#include "glm.h" ///step02-1 把 source.zip裡的 glm.h 放在同目錄中
GLMmodel * pmodel = NULL; ///step02-1 模型的指標,一開始NULL空的
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    if(pmodel==NULL){ ///第一次會進來 step02-1
        pmodel = glmReadOBJ("Gundam.obj");///檔名照你的檔名 step02-1
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
```

## step02-2_因為3D模型的大小(很可能)太大or太小, 所以需要縮放一下。可以使用 glmUnitize() 調成單位大小

```cpp
GLMmodel * pmodel = NULL; ///step02-1 模型的指標,一開始NULL空的
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    if(pmodel==NULL){ ///第一次會進來 step02-1
        pmodel = glmReadOBJ("Gundam.obj");///檔名照你的檔名 step02-1
        glmUnitize(pmodel);///step02-2 縮放成Unit單位大小(-1..+1)
    }
    glmDraw(pmodel, GLM_SMOOTH | GLM_MATERIAL); ///step02-1

    ///glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}
```


## step03-1_要把貼圖,加到 week08-2_glm_model_texture。先把剛剛的 week08-1_glm_model 的程式, 貼過來, 要修改。同時補上 glmFacetNormals() 及 glmVertexNormals()函式, 方便計算法向量。也要把剛剛的 glm.h 及 glm.cpp 準備好, 並把 glm.cpp 也加到專案中。先確認 Gundam 模型可以順利畫出來。
- 老師會傳給你 5個檔案: Gundam.obj Gundom.mtl Diffuse.jpg AO.jpg Specular map.jpg 其中你只要用到 .obj .mtl 和 Diffuse.jpg
- File-New-Project, GLUT專案 week08-2_glm_model_texture
- 把剛剛的程式拿來用, 再改更好!!!!
- 增加 glmFacetNormals() 和 glmVertexNormals()計算正確的法向量
- 其實剛剛的Gundam.obj 裡已有 vn 法向量, 所以不執行這兩行也可以

```cpp
///Week08-2_glm_model_texture
///把範例全刪,貼上 Week08-1_glm_model
///再結合上週的 myTexture的(部分)程式
///記得再裝 opencv2.1, 再配上週的3個咒語 目錄、目錄、cv210 cxcore210 highgui210
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
#include "glm.h" ///step02-1 把 source.zip裡的 glm.h 放在同目錄中
///step03-1也要把step02-1的 glm.h也準備好
///glm.cpp 也要加到你的程式目錄裡
GLMmodel * pmodel = NULL; ///step02-1 模型的指標,一開始NULL空的
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    ///step03-1執行前,確認Gundam.obj Gundam.mtl 都在freeglut的bin
    if(pmodel==NULL){ ///第一次會進來 step02-1
        pmodel = glmReadOBJ("Gundam.obj");///檔名照你的檔名 step02-1
        glmUnitize(pmodel);///step02-2 縮放成Unit單位大小(-1..+1)
        glmFacetNormals(pmodel);///step03-1
        glmVertexNormals(pmodel, 90);///step03-1
    }
    glPushMatrix();
        glRotatef(angle, 0,1,0);
        glmDraw(pmodel, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE); ///step02-1
    glPopMatrix();

    ///glutSolidTeapot( 0.3 );
    angle++;
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week08");

    myTexture("Diffuse.jpg");///step03-2圖檔也是放freeglut的bin
    glEnable(GL_DEPTH_TEST);///下週再教3D的glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
}
```

## step03-2_要繼續把貼圖完成。也就是上週的貼圖做的事,全部做一次
- 安裝 OpenCV, 要記得 Add PATH
- 重開CodeBlocks
- 貼上 myTexture的函式(18行)
- 在 main() 加入 myTexture("Diffuse.jpg"); 圖檔也要放在 freeglut的bin
- 加上 Settings-Compiler咒語: C:\OpenCV2.1\include
- 加上 Settings-Compiler咒語: C:\OpenCV2.1\lib
- 加上 Settings-Compiler咒語: cv210 cxcore210 highgui210
- 最後 glmDraw(pmodel, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE); 增加貼圖功能

因為 OpenCV讀圖檔時,是倒過來的, 所以可以在小畫家,把圖檔倒過來,就會正確

## step03-3_上傳 GitHub
- 0. 安裝Git 開啟 Git Bash
- 1. cd desktop 進入桌面 git clone https://網址 再 cd 2023graphicsb
- 2. start . 開檔案總管,把今天的2個程式加進去
- 3. git add . 加入帳冊
- 4.0. git config --global user.email jsyeh@mail.mcu.edu.tw
- 4.0. git config --global user.name jsyeh
- 4.1. git commit -m week08
- 5. git push

# Week09
期中考週

# Week10


## step01-0_期中考試

## step01-1_上次week08上課時,有讓大家實作 week08-2_glm_model可以開3D模型。利用Git指令,把GitHub的備份取下來。

Git Bash
- cd desktop
- git clone https://github.com/jsyeh/2023graphicsb

可以利用CodeBlocks 開啟桌面的2023graphicsb的 week08-2_glm_model 目錄裡的 week08-2_glm_model.cbp 專案檔


接下來, 要安裝 GLUT 及 OpenCV 才會有對應的 lib 檔

1. freeglut 解壓縮到桌面, 把 lib的 libfreeglut.a 複製成 libglut32.a
2. 安裝 OpenCV 2.1 預設目錄, 且 Add PATH 要勾!
3. 重開 CodeBlocks, 把咒語設好: Setting-Compiler裡
- Search Directories - Compiler 加 C:\OpenCV2.1\include
- Search Directories - Linker 加 C:\OpenCV2.1\lib
- Linker Setting 加: cv210 cxcore210 highgui210

先把上面的裝好, 我們再開新GLUT專案 week10-1_glm_gundam 吧!

程式碼分成 3大段
- 10行 GLUT 最簡單的程式 (include, display(), main())
- 18行 myTexture 貼圖的程式 
- 上週的重點 glm
	1. glm.h glm.cpp (從課本範例 jsyeh.org/3dcg10 source.zip) 複製好
	2. 把 glm.cpp 加到專案裡
	3. 程式要修改 #include "glm.h" 還有指標 `GLMmodel * pmodel = NULL;`
	4. 還有 display()裡面的 if(pmodel==NULL) 要去讀檔
	5. glmDraw(pmodel, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
- 把 Gundam.obj Gundam.mtl Diffuse.jpg 都放到 工作執行目錄


## step03-1_如何切割3D模型,可以使用 Maya把模型讀入後,刪除不要的, 再匯出。便能得到我們要的身體的各個部位。之後期末作品,便可以照著TRT來做出來。

# Week11

## step01-1_新開GLUT專案 week11-1_keyboard 一開始的範例裡面, 就已經有 keyboard 對應的鍵盤, 像是 + - 和 Esc 鍵的操作。所以我們就仿效它, 直接寫 if(key==27) exit(0); 離開。 27 是 ESC 這個特殊鍵

Ctrl-F 在程式碼裡找 keyboard

找到
glutKeyboardFunc(keyboard)

```cpp
#include <GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}
void keyboard(unsigned char key, int x, int y)
{///step01-1
    if( key == 27 ) exit(1234); ///step01-1
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week11");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard); ///step01-1

    glutMainLoop();
}
```

## step01-2_再結合keyboard和播放音樂, 新增GLUT專案  week11-2_keyboard_PlaySound, 首先前面要 include windows.h 才能有這個功能。對應的函式是 PlaySound() 裡面的檔名先用「絕對路徑」, 也就是從C磁碟開始的很長的檔名, 同時因為反斜線是特殊符號, 所以要兩個反斜線,來把目錄標示好。 NULL 是空指標, 表示這個參數不用。SND_ASYNC 是聲音 「不等待、不同步」,也就是直接播的意思。 

wav: 檔案大，沒壓縮,容易播放
mp3: 檔案小、有壓縮,麻煩一點

最前面要 #include <windows.h>

PlaySound("檔名.wav", ...);

SND_ASYNC 是「不等待、不同步」
SND_SYNC 是「要等待、同步」

```cpp
///Week11-2_keyboard_PlaySound 拿 Week11-1_keyboard 程式來用
#include <windows.h> ///step01-2 要放在第1行
#include <GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}
void keyboard(unsigned char key, int x, int y)
{///step01-1
    if(key=='1') PlaySound("C:\\Users\\Administrator\\Desktop\\do-re-mi\\do.wav", NULL, SND_ASYNC);
    if(key=='2') PlaySound("C:\\Users\\Administrator\\Desktop\\do-re-mi\\re.wav", NULL, SND_ASYNC);
    if(key=='3') PlaySound("C:\\Users\\Administrator\\Desktop\\do-re-mi\\mi.wav", NULL, SND_ASYNC);
}///step01-2
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week11");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard); ///step01-1

    glutMainLoop();
}
```


## step02-1_現在想要練習 PlaySound 在大一教的 Hello World 範例裡。File-New-Empty空白檔案,存 week11-3_PlaySound.cpp 使用方法, 一樣簡單的使用 PlaySound()函式, 同時在第1行要有 windows.h 最後的咒語 winmm 要加好

```cpp
#include <windows.h> ///step02-1
#include <stdio.h>
int main()
{ ///Setting-Compiler, Linker咒語: 需要 winmm 
    PlaySound("C:\\Users\\Administrator\\Desktop\\do-re-mi\\do.wav", NULL, SND_SYNC);
    PlaySound("C:\\Users\\Administrator\\Desktop\\do-re-mi\\re.wav", NULL, SND_SYNC);
    PlaySound("C:\\Users\\Administrator\\Desktop\\do-re-mi\\mi.wav", NULL, SND_SYNC);
    printf("Hello World\n");
}

```

## step02-1b_解釋「絕對路徑、相對路徑」的差別。絕對路徑比較長,但可能每台電腦都不一樣。相對路徑 要看從哪裡開始。

```cpp
///Week11-3_PlaySound.cpp
#include <windows.h> ///step02-1
#include <stdio.h>
int main()
{ ///Setting-Compiler, Linker咒語: 需要 winmm
    ///絕對路徑 Absolute Path
    ///PlaySound("C:\\Users\\Administrator\\Desktop\\do-re-mi\\do.wav", NULL, SND_SYNC);
    ///PlaySound("C:\\Users\\Administrator\\Desktop\\do-re-mi\\re.wav", NULL, SND_SYNC);
    ///PlaySound("C:\\Users\\Administrator\\Desktop\\do-re-mi\\mi.wav", NULL, SND_SYNC);

    ///目錄的斜線可以用 兩個反斜線 \\ 或著是一個斜線 /
    PlaySound("do-re-mi/do.wav", NULL, SND_SYNC);
    ///相對路徑 Relative Path

    printf("Hello World\n");
}
```


## step02-2_想要播放MP3檔,MP3從網路下載(ex. youtube mp3 download), 新的GLUT專案 week11-4_CMP3_MCI_Load_Play 。裡面先 include "CMP3_MCI.h" 這個外掛, 便能簡單播放MP3檔。步驟是先宣告物件變數 CMP3_MCI myMP3; 接下來 myMP3.Load("檔名.mp3")把檔案讀進來, 再 myMP3.Play()播放, 就可以了。小心路徑問題。看是要絕對路徑or相對路徑。

```cpp
/* Program entry point */

#include "CMP3_MCI.h" ///step02-2 使用外掛 用雙引號,表示是同一目錄裡的.h檔

///CMP3_MCI.h 放在 week11-4_CMP3_MCI_Load_Play 程式同一目錄

CMP3_MCI myMP3; ///step02-2 宣告物件變數



int main(int argc, char *argv[])

{

    char filename[] = "C:/Users/Administrator/Desktop/do-re-mi/suzume.mp3";

    myMP3.Load(filename); ///step02-2

    myMP3.Play();///step02-2

```


## step03-1_想要解決歷史餘毒,也就是 working_dir 工作執行目錄, 不要在(很長很長的) freeglut的bin裡面。所以, 把 freeglut的bin裡面的 freeglut.dll 複製到 專案 的同一目錄裡, 再把聲音檔 suzume.mp3 也放在同一目錄裡。最後, 把 Project-Properties 裡面的 Build targets 的 工作執行目錄 working dir 改成小數點 . 代表同一目錄。

```cpp
#include "CMP3_MCI.h" ///step02-2 使用外掛 用雙引號,表示是同一目錄裡的.h檔

///CMP3_MCI.h 放在 week11-4_CMP3_MCI_Load_Play 程式同一目錄

CMP3_MCI myMP3; ///step02-2 宣告物件變數



int main(int argc, char *argv[])

{

    ///char filename[] = "C:/Users/Administrator/Desktop/do-re-mi/suzume.mp3";

    ///myMP3.Load(filename); ///step02-2

    myMP3.Load("suzume.mp3"); ///step03-1

    myMP3.Play();///step02-2

```


## step03-2_現在的專案目錄裡, 有 mp3 及 .dll檔, 可是 Git 無法上傳, 因為 .gitignore 會把 .dll 檔忽略。但是如果沒有備份它, 則下載的程式就不能執行, 會出現.dll找不到的錯誤。所以, 現在要把 .gitignore改一下。之後在Git備份時,就會連那個 freeglut.dll 一起備份

git clone https://github.com/jsyeh/2023graphicsb

會把你的倉庫下載複製下來。

你要把裡面的 .gitignore 用 Notepad++ 開起來
把 

```
# *.dll 這行的前面加上註解
```

- git status 會看到紅色的地方,多一個 modify 的 .gitignore
- git add .
- git status 看到全部的修改變綠色

最後
- git config --global user.email jsyeh@mail.mcu.edu.tw
- git config --global user.name jsyeh
- git commit -m week11
- git push

# Week12

## step01-1_新的空白檔案 week12-1_printf_fprintf.cpp 要練習寫檔案。和 printf()很像, fprintf()的前面, 要有一個 f 也就是檔案指標。檔案指標 fout = fopen("檔名", "w") 就會寫檔出去。

```cpp
///Week12-1_printf_fprintf.cpp
///要開檔案指標  fopen()
#include <stdio.h>
int main()
{///檔案指標 fout = fopen("檔名", "模式"); 要開檔
    FILE * fout = fopen("file.txt", "w");///w:write
    printf("Hello World\n");
    fprintf(fout, "Hello World在檔案裡\n");
}

```

## step01-2_新的空白檔案 week12-2_fscanf.cpp 要把檔案讀進來, 檔案指標 fin = fopen("檔名", "r") 之後 fscanf()便能把 fin 當前面的參數來讀檔。前一個程式 fprintf()印出字串, 這裡就宣告字串 char line[20]; 再用 %s 讀進來。因為空格斷開, 所以分2次讀入。

```cpp
///Week12-2_scanf.cpp
#include <stdio.h>
int main()
{
    char line[20];
    ///scanf("%s", line);
    FILE * fin = fopen("file.txt", "r");///r:read讀
    fscanf(fin, "%s", line);
    printf("讀到了:%s\n", line);///馬上印
    fscanf(fin, "%s", line);
    printf("讀到了:%s\n", line);///馬上印
}
```

## step01-3_接下來就辛苦了, 我們想要在同一個程式中, 又有寫檔案、又有讀檔案。新的空白檔案 week12-3_fopen_fclose_fprintf_fscanf.cpp 在這個範例裡, 我們想寫的是一堆數字、想讀的也是一堆數字(因為期末作品,要做出動畫的動作時, 有很多關節的角度要存起來, 之後再播放)。因為是同一個檔案, 明顯會出問題, 一定要記得 fopen() 結束時要fclose()。

```cpp
///week12-3_fopen_fclose_fprintf_fscanf.cpp
#include <stdio.h>
int main()
{
    int a[10] = {10,20,30,40,50,60,70,80,90,100};
    FILE * fout = fopen("file3.txt", "w");
    for(int i=0; i<10; i++){
        fprintf(fout, "%d ", a[i] ); ///寫到檔案去,同時
        printf("%d ", a[i] ); ///順便印出來,讓你看看
    }
    fclose(fout);

    int b[10];
    FILE * fin = fopen("file3.txt", "r");
    for(int i=0; i<10; i++){
        fscanf(fin, "%d", &b[i] ); ///讀到陣列 b[i]裡
        printf("%d ", b[i] );
    }
    fclose(fin);
}
```

## step02-0_介紹buffer_overflow相關的議題,小心指標容易出錯


## step02-1_新的GLUT專案 week12-4_keyboard_mouse 想要用 mouse 來控制 teapot 的位置, 使用 teapotX 和 teapotY 變數, 再 glTranslatef(teapotX, teapotY, 0) 來移動茶壼。

```cpp
///Week12-4_keyboard_mouse 要能用 mouse來移動, 同時要解決存讀檔的問題
#include <stdio.h> ///要檔案的Input/Output
#include <GL/glut.h>
float teapotX = 0, teapotY = 0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(teapotX, teapotY, 0);
        glutSolidTeapot( 0.3 );
    glPopMatrix();
    glutSwapBuffers();
}
void mouse(int button, int state, int x, int y)
{
    teapotX = (x-150)/150.0;
    teapotY = (150-y)/150.0;
    display();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12");

    glutDisplayFunc(display);
    glutMouseFunc(mouse); ///step02-1

    glutMainLoop();
}
```

## step02-2_剛剛的 week12_keyboard_mouse專案裡, 還沒有加 檔案的部分, 我們將在 mouse()裡的 GLUT_DOWN 按下mouse時寫檔, 再用 keyboard() 來觸發讀檔的動作。

```cpp
///Week12-4_keyboard_mouse 要能用 mouse來移動, 同時要解決存讀檔的問題
#include <stdio.h> ///要檔案的Input/Output
#include <GL/glut.h>
float teapotX = 0, teapotY = 0;
FILE * fout = NULL;///step02-1
FILE * fin = NULL;///step02-2
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(teapotX, teapotY, 0);
        glutSolidTeapot( 0.3 );
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
void keyboard(unsigned char key, int x, int y)///step02-2
{
    if(fin==NULL){
        fclose(fout);///step02-2
        fin = fopen("file4.txt", "r");///step02-2
    }
    fscanf(fin, "%f%f", &teapotX, &teapotY);///step02-2
    display();///step02-2
}///step02-2
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
```

## step03-1_再來調整工作執行目錄 CodeBlocks 的 Project-Properties 裡可改

```cpp
///Week12-4_keyboard_mouse 要能用 mouse來移動, 同時要解決存讀檔的問題
#include <stdio.h> ///要檔案的Input/Output
#include <GL/glut.h>
///step03-1
///CodeBlocks的專案設定 Project-Properties裡第二個Build Target
/// Executing working dir 工作執行目錄
///原本是 C:\Users\Administrator\Desktop\freeglut\bin
///改成 . (小數點) 再 File-Save Everything 便能將專案檔設好、存檔。
///之後你的工作執行目錄, 就在你的程式專案的那一目錄裡
///但執行時, 就會少了 freeglut.dll 檔, 你再手動copy到你的專案檔裡。
///  註: 你可以看到 .cbp CodeBlocks Project 專案裡 working_dir 有變動哦
float teapotX = 0, teapotY = 0;
FILE * fout = NULL;///step02-1
FILE * fin = NULL;///step02-2
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(teapotX, teapotY, 0);
        glutSolidTeapot( 0.3 );
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
void keyboard(unsigned char key, int x, int y)///step02-2
{
    if(fin==NULL){
        fclose(fout);///step02-2
        fin = fopen("file4.txt", "r");///step02-2
    }
    fscanf(fin, "%f%f", &teapotX, &teapotY);///step02-2
    display();///step02-2
}///step02-2
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
```


## step03-2_想在同一個目錄裡, 寫期末作品Final_Project 
- 所以,把CodeBlocks關掉(確認檔案都有存好),
- 整個 week12-4_keyboard_mouse目錄,都copy 目錄改成 Final_Project,
- 把專案檔 week12-4_keyboard_mouse.cbp 改成 Final_Project.cbp。
- 再把 Project-Properties裡的title改成 Final_Project, 
- Save Everything。
- 之後雲端這份, 到處都能用。只用這個來寫期末作品。

## step03-3_用Git上傳GitHub

- git add .
- git config --global user.email jsyeh@mail.mcu.edu.tw
- git config --global user.name jsyeh
- git commit -m week12
- git push


# Week13

## step01-1_要承接上週的程式, 所以要先安裝Git, 再 git clone 把整個倉庫拿下來, 其中 Final_Project 裡面的 Final_Project.cbp 專案檔,用CodeBlocks 開起來。以後不要再裝 freeglut了, 因為我們要用相對路徑, 這樣家裡、學校,都可以順利compile程式。Project-Properties的右下角的設定,把 compiler 及 linker 的目錄設成相對路徑, 把 freeglut放在我們的目錄裡,並把libglut32.a準備好,便能順利編譯了。File-Save Everything

## step01-2_想要馬上用Git備份上傳。先把 .gitignore 放行 .a .lib .dll 都註解掉,就可以放行了。存檔。CodeBlocks也要 Save Everything

- cd desktop
- git clone https://github.com/jsyeh/2023graphicsb
- cd 2023graphicsb
- start .

以上是前一步做的。後來做的,加到要上傳的帳冊
- git status (紅色)
- git add .  (加到帳冊)
- git status (綠色)

帳冊要確認 (確認前, 要設定好你的email及名字)
- git config --global user.email jsyeh@mail.mcu.edu.tw
- git config --global user.name jsyeh
- git commit -m week13
- git push 
以上就可以推送上雲端

## step02-1_利用 Maya 把上課範例的 Al.obj 裁切成 head.obj body.obj uparmR.obj lowarmR.obj ... 等一下要放到你的 Final_Project 裡面


## step02-2_把week08的 glm.h glm.cpp 複製到 Final_Project裡, 加到專案, #include "glm.h" 並 Add Files 把 glm.cpp 加好, 再準備好 GLMmodel 指標 head = NULL; 要讀檔用。利用 glmReadOBJ() 把 model 目錄裡的 head.obj 讀好, glmUnitize()之後會刪掉。 glmDraw()便可以讀入模型

## step02-3_要再把更多的模型讀入時, 發現「大小」是個問題。不能每個都用 glmUnitize() 調到-1...+1間。而應該是整體用 glScalef()縮放到適當的大小, 可以用 Maya 查看模型整體的大小, 以便設定對的縮放比例,讓畫面容易處理。

## step03-1_想要用鍵盤來切換不同的模型要不要秀出來, 就宣告 int show[4] = {1, 0, 0, 0}; 一開始只秀 頭。自己寫 keyboard()函式, if(key=='1') show[1] = ! show[1]; 意思是把 0 變 1 或 1 變 0。 display()裡, 加入 if(show[0]) glmDraw(head, GLM_MATERIAL); 用陣列來決定誰要秀出來。

## step03-2_利用 motion 來移動物體

```cpp
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
        glPushMatrix();///week13_step03-2
            glTranslatef(teapotX, teapotY, 0); ///week13_step03-2
            if(show[0]) glmDraw(head, GLM_MATERIAL);///week13_step02-3
        glPopMatrix();///week13_step03-2
        if(show[1]) glmDraw(body, GLM_MATERIAL);///week13_step02-2
        if(show[2]) glmDraw(uparmR, GLM_MATERIAL);///week13_step02-3
        if(show[3]) glmDraw(lowarmR, GLM_MATERIAL);///week13_step02-3
        ///week13_step03-1 加上 if(show[??]) ...
    glPopMatrix();
    glutSwapBuffers();
}
int oldX=0, oldY=0; ///week13_step03-2
void mouse(int button, int state, int x, int y) {
    if(state==GLUT_DOWN){
        oldX = x;
        oldY = y;
    }
}
void motion(int x, int y) { ///week13_step03-2
    teapotX += (x - oldX)/150.0*3;
    teapotY -= (y - oldY)/150.0*3;
    oldX = x;
    oldY = y;
    glutPostRedisplay();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12");

    glutMotionFunc(motion); ///week13_step03-2
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);

    glutMainLoop();
}
```

# Week14

電腦圖學 2023-05-18 Week14
1. 主題: 切換關節
2. 主題: 切換移動、旋轉
3. 整合打光、貼圖
4. 主題: 計時器、內插動作

## step01-1_先把程式Git複製下來,在裡面開GLUT專案 week14-1_timer 先有10行GLUT程式, 再加3行 timer, 讓它轉。使用 float angle=0; 一開始是0度, 之後每次+90度, 然後重畫畫面。起床時, 先設定「下一次起床」的鬧鐘時間, 就能每次起床轉動90度, 完成動畫了。

1. 安裝Git,開Git Bash
	- cd desktop 到桌面
	- git clone https://github.com/你的網址/2023graphicsb
	- cd 2023graphicsb 
	- start .    開檔案總管
2. 在你的專案裡, 開新的GLUT專案 week14-1_timer 專案
	- (可不用了)我們先把桌面的 freeglut 設好
	- 新專案,開在桌面的 2023graphicsb 裡
	- freeglut 用 2023graphicsb 的 Final_Project 的 freeglut

```cpp
///Week14-1_timer
#include <GL/glut.h>
float angle = 0; ///step01-1
void timer(int t) ///step01-1
{
    glutTimerFunc(500, timer, t+1); ///step01-1
    angle += 90; ///角度+90度
    glutPostRedisplay(); ///step01-1 重畫畫面
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix(); ///step01-1
        glRotatef(angle, 0, 0, 1); ///step01-1
        glutSolidTeapot( 0.3 );
    glPopMatrix(); ///step01-1
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week14");

    glutTimerFunc(3000, timer, 0); ///step01-1
    glutDisplayFunc(display);

    glutMainLoop();
}
```

## step01-2_按鍵後,再開始Play播放動畫, week14-2_timer_play。把 glutTimerFunc()改在 keyboard()裡面啟動, 後面就源源不絕的一直被叫起床。glutTimerFunc(等多久, timer, t+1); 裡面等待的時間,單位是 ms (千分之一秒), 把等待時間變成 33 ms, 再把 angle += 3; 每次轉少一點, 就會變很順。


```cpp
///Week14-2_timer_play
#include <GL/glut.h>
float angle = 0; ///step01-1
void timer(int t) ///step01-1
{
    glutTimerFunc(33, timer, t+1); ///step01-1
    angle += 3; ///角度+90度
    glutPostRedisplay(); ///step01-1 重畫畫面
}
void keyboard(unsigned char key, int x, int y)  ///step01-2
{
     glutTimerFunc(0, timer, 0); ///step01-2
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix(); ///step01-1
        glRotatef(angle, 0, 0, 1); ///step01-1
        glutSolidTeapot( 0.3 );
    glPopMatrix(); ///step01-1
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week14");

    glutKeyboardFunc(keyboard); ///step01-2
    ///glutTimerFunc(3000, timer, 0); ///step01-1
    glutDisplayFunc(display);

    glutMainLoop();
}
```

## step02-1_關於動作內插,可以很順的把中間的值都變出來。使用的公式, 是有個 alpha值, 介於 0.0~1.0 之間。使用公式 (alpha)乘(新的) + (1-alpha)乘(舊的), 便能把中間的值都推算出來。使用Excel來講解示範。


把現在的程式先 Git 備份起來
- git config --global user.email jsyeh@mail.mcu.edu.tw
- git config --global user.name jsyeh

前2行設定, 後3行會備份到雲端
- git add .
- git commit -m week14
- git push

## step02-2_把 alpha內插,用程式寫出來。week14-3_timer_alpha_interpolation 專案, 裡面利用 mouse 來點擊你的開始、結束的位置, 然後再play

```cpp
///Week14-3_timer_alpha_interpolate
#include <GL/glut.h>
float angle = 0, newAngle = 0, oldAngle = 0; ///step02-2 宣告 新角度、舊角度
float oldX = 0;  ///step02-2 舊的x座標
void timer(int t) ///step01-1
{
    if(t<100) glutTimerFunc(33, timer, t+1); ///step01-1
    float alpha = t/100.0;  ///step02-2 所以 alpha介 0.0~1.0 之間
    angle = alpha*newAngle + (1-alpha)*oldAngle; ///step02-2
    glutPostRedisplay(); ///step01-1 重畫畫面
}
void keyboard(unsigned char key, int x, int y)  ///step01-2
{
     glutTimerFunc(0, timer, 0); ///step01-2
}
void mouse(int button, int state, int x, int y) {  ///step02-2
    if(state==GLUT_DOWN) oldAngle = angle;  ///step02-2
    if(state==GLUT_UP) newAngle = angle;  ///step02-2
    oldX = x;  ///step02-2
    glutPostRedisplay();  ///step02-2
}
void motion(int x, int y) {  ///step02-2
    angle += x-oldX;  ///step02-2
    oldX = x;  ///step02-2
    glutPostRedisplay();  ///step02-2 更新畫面
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix(); ///step01-1
        glRotatef(angle, 0, 0, 1); ///step01-1
        glutSolidTeapot( 0.3 );
    glPopMatrix(); ///step01-1
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week14");

    glutMouseFunc(mouse); ///step02-2
    glutMotionFunc(motion); ///step02-2
    glutKeyboardFunc(keyboard); ///step01-2
    ///glutTimerFunc(3000, timer, 0); ///step01-1
    glutDisplayFunc(display);

    glutMainLoop();
}
```

## step03-1_請檢查上週的 Final_Project 專案裡,有沒有2個檔案 (沒有的話,就是上週雲端備分失敗)。程式碼裡, 準備好關節的 int ID = 2; 表示決定要把哪一個關節變紅色。display()裡,就照著if(ID==2) glColor3f(1,0,0); else glColor3f(1,1,1); 來著色。 int show[4] = {1,1,1,1}; 表示4個關節都要畫出來。


```cpp
///Final_Project 之後都用同一個程式,來進行 Final Project
#include <stdio.h> ///要檔案的Input/Output
#include <GL/glut.h>
#include "glm.h" ///week13_step02-2
///week13_step02-2 再把 glm.cpp 在左邊 Add files 加進去
GLMmodel * head = NULL;///week13_step02-2
GLMmodel * body = NULL;///week13_step02-2
GLMmodel * uparmR = NULL;
GLMmodel * lowarmR = NULL;
int show[4] = {1,1,1,1}; ///week14_step03_1 都秀出來 ///week13_step03-1
int ID = 2; ///week14_step03_1 設定關節 ID
float teapotX = 0, teapotY = 0;
FILE * fout = NULL;///step02-1
FILE * fin = NULL;///step02-2
void keyboard(unsigned char key, int x, int y) {///week13_step03-1
    if(key=='0') ID = 0; ///week14_step03_1 ///show[0] = ! show[0];///week13_step03-1
    if(key=='1') ID = 1; ///week14_step03_1 ///show[1] = ! show[1];///week13_step03-1
    if(key=='2') ID = 2; ///week14_step03_1 ///show[2] = ! show[2];///week13_step03-1
    if(key=='3') ID = 3; ///week14_step03_1 ///show[3] = ! show[3];///week13_step03-1
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
        glPushMatrix();///week13_step03-2
            glTranslatef(teapotX, teapotY, 0); ///week13_step03-2

            if(ID==0) glColor3f(1,0,0);///week14_step03_1 秀紅色
            else glColor3f(1,1,1);///week14_step03_1 秀白色
            if(show[0]) glmDraw(head, GLM_MATERIAL);///week13_step02-3
        glPopMatrix();///week13_step03-2

        if(ID==1) glColor3f(1,0,0);///week14_step03_1 秀紅色
        else glColor3f(1,1,1);///week14_step03_1 秀白色
        if(show[1]) glmDraw(body, GLM_MATERIAL);///week13_step02-2

        if(ID==2) glColor3f(1,0,0);///week14_step03_1 秀紅色
        else glColor3f(1,1,1);///week14_step03_1 秀白色
        if(show[2]) glmDraw(uparmR, GLM_MATERIAL);///week13_step02-3

        if(ID==3) glColor3f(1,0,0);///week14_step03_1 秀紅色
        else glColor3f(1,1,1);///week14_step03_1 秀白色
        if(show[3]) glmDraw(lowarmR, GLM_MATERIAL);///week13_step02-3
        ///week13_step03-1 加上 if(show[??]) ...
    glPopMatrix();
    glutSwapBuffers();
}
int oldX=0, oldY=0; ///week13_step03-2
void mouse(int button, int state, int x, int y) {
    if(state==GLUT_DOWN){
        oldX = x;
        oldY = y;
    }
}
void motion(int x, int y) { ///week13_step03-2
    teapotX += (x - oldX)/150.0*3;
    teapotY -= (y - oldY)/150.0*3;
    oldX = x;
    oldY = y;
    glutPostRedisplay();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12");

    glutMotionFunc(motion); ///week13_step03-2
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);

    glutMainLoop();
}
```

## step03-2_今天最後的程式, 利用 motion()裡的 printf()來印出程式碼, 幫忙找出 T-R-T 最重要的下面的T,把關節的旋轉中心移到正中心。上面的T就把座標正負倒過來, 中間夾了 glRotatef()做旋轉, 前後要有 glPushMatrix()和 glPopMatrix()包起來。程式碼就這樣慢慢長出來。一層層做下去,便能做出階層性轉動, 也就是上手臂會帶動下手臂。期末作品快要完成囉


備份到雲端
- git add .
- git commit -m week14
- git push

```cpp
///Final_Project 之後都用同一個程式,來進行 Final Project
#include <stdio.h> ///要檔案的Input/Output
#include <GL/glut.h>
#include "glm.h" ///week13_step02-2
///week13_step02-2 再把 glm.cpp 在左邊 Add files 加進去
GLMmodel * head = NULL;///week13_step02-2
GLMmodel * body = NULL;///week13_step02-2
GLMmodel * uparmR = NULL;
GLMmodel * lowarmR = NULL;
int show[4] = {1,1,1,1}; ///week14_step03_1 都秀出來 ///week13_step03-1
int ID = 3; ///week14_step03_1 設定關節 ID
float teapotX = 0, teapotY = 0;
float angle = 0;
FILE * fout = NULL;///step02-1
FILE * fin = NULL;///step02-2
void keyboard(unsigned char key, int x, int y) {///week13_step03-1
    if(key=='0') ID = 0; ///week14_step03_1 ///show[0] = ! show[0];///week13_step03-1
    if(key=='1') ID = 1; ///week14_step03_1 ///show[1] = ! show[1];///week13_step03-1
    if(key=='2') ID = 2; ///week14_step03_1 ///show[2] = ! show[2];///week13_step03-1
    if(key=='3') ID = 3; ///week14_step03_1 ///show[3] = ! show[3];///week13_step03-1
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
        glPushMatrix();///week13_step03-2
            ///glTranslatef(teapotX, teapotY, 0); ///week13_step03-2

            if(ID==0) glColor3f(1,0,0);///week14_step03_1 秀紅色
            else glColor3f(1,1,1);///week14_step03_1 秀白色
            if(show[0]) glmDraw(head, GLM_MATERIAL);///week13_step02-3
        glPopMatrix();///week13_step03-2

        if(ID==1) glColor3f(1,0,0);///week14_step03_1 秀紅色
        else glColor3f(1,1,1);///week14_step03_1 秀白色
        if(show[1]) glmDraw(body, GLM_MATERIAL);///week13_step02-2

        glPushMatrix(); ///week14_step03_2
            ///glTranslatef(teapotX, teapotY, 0); ///week14_step03_2 要設定 TRT
            glTranslatef(-1.360000, +0.360000, 0); ///week14_step03_2
            glRotatef(angle, 0, 0, 1); ///week14_step03_2
            glTranslatef(1.360000, -0.360000, 0); ///week14_step03_2

            if(ID==2) glColor3f(1,0,0);///week14_step03_1 秀紅色
            else glColor3f(1,1,1);///week14_step03_1 秀白色
            if(show[2]) glmDraw(uparmR, GLM_MATERIAL);///week13_step02-3

            glPushMatrix();  ///week14_step03_2
                ///glTranslatef(teapotX, teapotY, 0); ///week14_step03_2 要設定 TRT
                glTranslatef(-1.959999, +0.080000, 0);
                glRotatef(angle, 0, 0, 1);
                glTranslatef(1.959999, -0.080000, 0);

                if(ID==3) glColor3f(1,0,0);///week14_step03_1 秀紅色
                else glColor3f(1,1,1);///week14_step03_1 秀白色
                if(show[3]) glmDraw(lowarmR, GLM_MATERIAL);///week13_step02-3
            glPopMatrix();  ///week14_step03_2
        glPopMatrix(); ///week14_step03_2


    glPopMatrix();
    glColor3f(0,1,0);  ///week14_step03_2 綠色的
    glutSolidTeapot( 0.02 ); ///week14_step03_2
    glutSwapBuffers();
}
int oldX=0, oldY=0; ///week13_step03-2
void mouse(int button, int state, int x, int y) {
    if(state==GLUT_DOWN){
        oldX = x;
        oldY = y;
    }
}
void motion(int x, int y) { ///week13_step03-2
    teapotX += (x - oldX)/150.0*3;
    teapotY -= (y - oldY)/150.0*3;
    printf("glTranslatef(%f, %f, 0);\n", teapotX, teapotY); ///week14_step03_2
    angle += x-oldX; ///week14_step03_2
    oldX = x;
    oldY = y;
    glutPostRedisplay();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12");

    glutMotionFunc(motion); ///week13_step03-2
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);

    glutMainLoop();
}
```