#include "opencv2/opencv.hpp"
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

void drawhist(Mat &hist,int type,string name){
	int hist_w=512;
	int hist_h=400;
	int width=2;
	Mat histimage=Mat::zeros(hist_h,hist_w,CV_8UC3);
	normalize(hist,hist,1,0,type,-1,Mat());
	for(int i=1;i<=hist.rows;i++){
		rectangle(histimage,Point(width*(i-1),hist_h-1),
		Point(width*i-1,hist_h-cvRound(20*hist_h*hist.at<float>(i-1))-1),Scalar(255,255,255),-1);
	}
	imshow(name,histimage);
}

void drwaline(Mat &img,vector<Vec2f> lines,double rows,double cols,Scalar scalar,int n)
{
	Point pt1, pt2;
	
	for (size_t i = 0; i < lines.size(); i++)
	{
		float rho = lines[i][0];  
		float theta = lines[i][1]; 
		double a = cos(theta);  
		double b = sin(theta); 
		double x0 = a*rho, y0 = b*rho;  
		double length = max(rows, cols);  
										
		pt1.x = cvRound(x0 + length  * (-b));
		pt1.y = cvRound(y0 + length  * (a));
		pt2.x = cvRound(x0 - length  * (-b));
		pt2.y = cvRound(y0 - length  * (a));
		line(img, pt1, pt2, scalar, n);
	}
}

int main()
{
	// cout<<"aca"<<endl;
	Mat img=imread("/home/charles/Documents/opencv/lena.png");
	Mat imggray,imgmask,maskwatershed;
	Mat gray;
	imshow("img",img);
	cvtColor(img,gray,COLOR_BGR2GRAY);

	Mat harris;
	int blocksize=2;
	int aperturesize=3;
	cornerHarris(gray,harris,blocksize,aperturesize,0.04);

	Mat harissin;
	normalize(harris,harissin,0,255,NORM_MINMAX);

	convertScaleAbs(harissin,harissin);

	vector<KeyPoint> keyPoints;
	for (int row = 0; row < harissin.rows; row++)
	{
		for (int col = 0; col < harissin.cols; col++)
		{
			int R = harissin.at<uchar>(row, col);
			if (R > 125)
			{
				//��ǵ����KeyPoint��
				KeyPoint keyPoint;
				keyPoint.pt.y = row;
				keyPoint.pt.x = col;
				keyPoints.push_back(keyPoint);
			}
		}
	}

	drawKeypoints(img,keyPoints,img);
	// imshow("harssin",harissin);
	// imshow("harssim",img);
	waitKey(0);

    return 0;	
}