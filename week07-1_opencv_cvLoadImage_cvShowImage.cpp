///week07-1_opencv_cvLoadImage_cvShowImage.cpp
///�ɦW�@�w�n .cpp ���� .c ���M�|�X��

#include <opencv/highgui.h>

int main()
{                          ///���ɭn��b�ୱ�{�����ؿ���
    IplImage * img = cvLoadImage("image.jpg");
    cvShowImage("week07", img);
    cvWaitKey(0); ///�e�����n�{�h,���@�U�����N���~��
}
