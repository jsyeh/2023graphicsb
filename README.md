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