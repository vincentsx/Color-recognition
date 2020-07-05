
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int minh, maxh, mins, maxs, minv, maxv;
void helptext()
{
	cout << "B——黑色\n";
	cout << "H——灰色\n";
	cout << "W——白色\n";
	cout << "R——红色\n";
	cout << "O——橙色\n";
	cout << "Y——黄色\n";
	cout << "G——绿色\n";
	cout << "L——蓝色\n";
	cout << "P——紫色\n";
	cout << "输入要求识别的颜色对应的字母:";
}

//各种颜色HSV数值设定
void deal(char color)
{
	switch (color) {
	case 'B':
		minh = 0;
		maxh = 180;
		mins = 0;
		maxs = 255;
		minv = 0;
		maxv = 46;
		break;
	case 'H':
		minh = 0;
		maxh = 180;
		mins = 0;
		maxs = 43;
		minv = 46;
		maxv = 220;
		break;
	case 'W':
		minh = 0;
		maxh = 180;
		mins = 0;
		maxs = 30;
		minv = 221;
		maxv = 255;
		break;
	case 'R':
		minh = 0;
		maxh = 10;
		mins = 43;
		maxs = 255;
		minv = 46;
		maxv = 255;
		break;
	case 'O':
		minh = 11;
		maxh = 25;
		mins = 43;
		maxs = 255;
		minv = 46;
		maxv = 255;
		break;
	case 'Y':
		minh = 26;
		maxh = 34;
		mins = 43;
		maxs = 255;
		minv = 46;
		maxv = 255;
		break;
	case 'G':
		minh = 35;
		maxh = 77;
		mins = 43;
		maxs = 255;
		minv = 46;
		maxv = 255;
		break;
	case 'L':
		minh = 100;
		maxh = 124;
		mins = 43;
		maxs = 255;
		minv = 46;
		maxv = 255;
		break;
	case 'P':
		minh = 125;
		maxh = 155;
		mins = 43;
		maxs = 255;
		minv = 46;
		maxv = 255;
		break;
	default:
		cout << "输入错误" << endl;
		exit(0);
	}
}

int main()
{
	VideoCapture cap(1); //调用摄像头，0为计算机摄像头，1为外接USB摄像头

	Mat special;

	helptext();

	char color;
	cin >> color;
	deal(color);


	while (true) {

		Mat frame;              //存储每一帧的图像

		cap >> frame;        //读取当前帧

		Mat fhsv;

		cvtColor(frame, fhsv, COLOR_BGR2HSV);   //将图像转换为HSV模型

		inRange(fhsv, Scalar(minh, mins, minv), Scalar(maxh, maxs, maxv), special);          //找寻在要求区间内的颜色

		imshow("[pic]", special);

		imshow("Original", frame); //show the original image    

		if (waitKey(30) >= 0)
			break;
	}

	return 0;
}
