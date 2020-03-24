#include<opencv2/opencv.hpp>   
#include<opencv2/highgui/highgui.hpp>   
#include<opencv2/imgproc/imgproc.hpp>   
#include<iostream>  #include <stdio.h> 
#include <io.h> #include <string.h>  
using namespace std; 
using namespace cv;  
int main() 
{  	
	VideoCapture cap; 	
	cap.open("D:\\video\\0309\\SyncVideo2020-03-13-18-00-55.avi");  	
	if (!cap.isOpened()) 	
	{ 		
		return 0; 	
	} 	//cap.set(CAP_PROP_POS_FRAMES, 62); 

	char file_out[512]; 	 	
	int img_count = 0;  	
	cout << "GO \n";  	
	
	// Process frames.
	Mat frame, frame_all, blob; 	
	while (waitKey(1) < 0) 	
	{ 		
		cap >> frame_all; 		
		if (frame_all.empty()) 
		{ 			
			waitKey(); 			
			break; 		
		} 		
		img_count++;  		
		if ((img_count % 5) == 0) 		
		{ 			
			int now_time = (int)getTickCount();   			
			sprintf_s(file_out, "D:\\img\\%d_%d.jpg", now_time, img_count);  			
			Rect rect_left(0, 0, frame_all.cols / 2, frame_all.rows / 2);  	// 根据坐标选取图像大小  （0,0）为坐标，左上角  后面两个参数，为取值长度		
			frame = frame_all(rect_left); 			
			imwrite(file_out, frame); 		
		} 		 	
	}  	
	cout << "ok \n"; 	
	return 1;  
} 