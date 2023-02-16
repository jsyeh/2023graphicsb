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