///week07-1_opencv_cvLoadImage_cvShowImage.cpp
///檔名一定要 .cpp 不能 .c 不然會出錯

#include <opencv/highgui.h>

int main()
{                          ///圖檔要放在桌面程式的目錄裡
    IplImage * img = cvLoadImage("image.jpg");
    cvShowImage("week07", img);
    cvWaitKey(0); ///畫面不要閃退,等一下按任意鍵繼續
}
