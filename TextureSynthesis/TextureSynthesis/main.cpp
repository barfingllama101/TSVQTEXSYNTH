

#include "ImageThings.h";
#include "LBG.h";
#include <cstdarg>
#include "iostream"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <GLFW\glfw3.h>
#include<GL/freeglut.h>
#include "structs.h"
using namespace std;
using namespace cv;
const char* window_name = "TexSynth";
vector<Mat> Pyramid = vector<Mat>();
vector<imgWH> imgWHs = vector<imgWH>();

//neighborhood creation

//send point data to opengl, not the image itself 
//shared data structure - iamge with opencv and do thte converseion, output - some datapoint into teh structure
//opengl - read teh data from thje structure.s tehdy ont communicate, but eh data structsure acts as the bridge
//

// l shape 
//wrap around 
//take in account torroidal wrapping
// mimic the l+1 on Ga 


//recursive img pyramid sizes 
//fill a vector with a struct? mayeb? and filll that by recursefly vgoign downt eh pyramid and 

//distance squared to get proper res distance 
float getAvg(_node neighborhood, Mat sample, Mat output, vector<int> coords, int points[][2], _node* root);
float getAvg(_node neighborhood, Mat sample, Mat output, vector<int> coords, int points[][2], _node* root) {
	int n = sizeof(points) / sizeof(points[0]);
	vector<Color> colors;

	//for (int y = 0; y < sample.cols; y++) {
	//	for (int x = 0; x < sample.rows; x++) {

		/*	Vec3b pixel = sample.at<Vec3b>(x,y);
			int blue = pixel.val[0];
			int green = pixel.val[1];
			int red = pixel.val[2];
			cout << "[" << blue << " " << green << " " << red << "]," << endl;*/
	//	}
	//	cout << endl;
	//}
//	for (int i = 0; i < n; i++) {
		//(search(root, point1)) ? cout << "Found\n" : cout << "Not Found\n";
		//get the point from the kd tree and then see where it is within the image 

		// get the color value at those points 

	//}

	//WAIT WE DONT NEED THE KD TREE FOR THIS AHAHA
	//Vec3b pixel = sample.at<Vec3b>(5,6);

	//std::cout << pixel.val[0] << " , " << pixel.val[1] << " , " << pixel.val[2] << " , " << endl;
	//just get the point val at the pixel 
	/*for (int i = 0; i < 2; i++) {
		//std::cout << points[i][0] << " jhldddkj" << endl;
		
		for (int j = 0; j < 12; j++) {
			Vec3b pixel = sample.at<Vec3b>(points[j][2]);
			int blue = pixel.val[0];
			int green = pixel.val[1];
			int red = pixel.val[2];
			std::cout << pixel.val[0] << " , " << pixel.val[1] << " , " << pixel.val[2] << " , " << endl;
		}
	}*/
	

	//compute average

	return 0.0f;
}

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
	if (event == EVENT_LBUTTONDOWN)
	{
		cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;

	}
	else if (event == EVENT_RBUTTONDOWN)
	{
		cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
	}
	else if (event == EVENT_MBUTTONDOWN)
	{
		cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
	}
	else if (event == EVENT_MOUSEMOVE)
	{
		cout << "Mouse move over the window - position (" << x << ", " << y << ")" << endl;
		cout << "Mouse move over the window - L + 1 POSITION (" << x / 2 << ", " <<  y / 2 << ")" << endl;

	//	Pyramid[1].at<uchar>(x / 2, y / 2)= 0;
	
	//	imshow("test",Pyramid[1]);
	}
	else {
		cout << "Mouse move sdfasdf the window - position (" << x << ", " << y << ")" << endl;

	}
}
int* pts = nullptr;
_node* neighborhoods(Mat sample, Mat outSample, int level, vector<int> coords) {
	struct _node* root = NULL;

	// get teh average pixel color at input location neighborhood n slap in on that portion of the output 
	//depending on how many usable spaces there are, we should count them to see how many pts we can use 
	int pointCount = 13; // basic structure no issues
	if (coords[0] == 0) {
		int points[][2] = { 
			{coords[0], coords[1]}
			/*
				0 0 0 0 0
				0 0 0 0 0
				0 0 x
			*/
		};
		int n = sizeof(points) / sizeof(points[0]);
		for (int i = 0; i < n; i++) {
			root = insert(root, points[i]);
		}
		pts = *points;
	//	getAvg(*root, sample, outSample, coords, points, root);
	}
	if (coords[0] >= sample.cols - 2) {
		int points[][2] = {
	  {coords[0] - 1, coords[1]},
	 /*
			 0 0 0 0 0
			 0 0 0 0 0
			 0 * x
	 */
			 {coords[0] - 2, coords[1]},
			 /*
			 0 0 0 0 0
			 0 0 0 0 0
			 * 0 x
	 */
			 {coords[0] - 2, coords[1] - 1},
			 /*
			 0 0 0 0 0
			 * 0 0 0 0
			 0 0 x
	 */
			 {coords[0] - 1, coords[1] - 1},
			 /*
			 0 0 0 0 0
			 0 * 0 0 0
			 0 0 x
	 */
			 {coords[0], coords[1] - 1 },
			 /*
			 0 0 0 0 0
			 0 0 * 0 0
			 0 0 x
	 */
			 {coords[0] + 1, coords[1] - 1},
			 /*
		 0 0 0 0 0
		 0 0 0 * 0
		 0 0 x
	 */
			 {coords[0] + 2, coords[1] - 1},
			 /*
				 0 0 0 0 0
				 0 0 0 0 *
				 0 0 x
			 */
		
			 {coords[0], coords[1]}
		};
		int n = sizeof(points) / sizeof(points[0]);
		for (int i = 0; i < n; i++) {
			root = insert(root, points[i]);
		}
		pts = *points;
	//	getAvg(*root, sample, outSample, coords, points, root);
	}
	if (coords[1] == 0) {
		int points[][2] = {
			{coords[0], coords[1]}
			/*
				0 0 0 0 0
				0 0 0 0 0
				0 0 x
			*/
		};
		int n = sizeof(points) / sizeof(points[0]);
		for (int i = 0; i < n; i++) {
			root = insert(root, points[i]);
		}
		pts = *points;
	//	getAvg(*root, sample, outSample, coords, points, root);
	}
	if(coords[1] >=sample.rows - 2){
		
	}
	/*if(sample.at<uchar>(coords[0]) >= sample.cols || sample.at<uchar>(coords[0]) >= sample.cols -2 || sample.at <uchar>(coords[0]) >= sample.cols + 2){
	}*/
	//if (sample.at <uchar>(coords[1]) == 0) {}
	//if (sample.at <uchar>(coords[1]) >= sample.rows || sample.at <uchar>(coords[1]) >= sample.rows + 2  || sample.at <uchar>(coords[1]) >= sample.rows - 2){}
	else {
	
		int points[][2] = { {coords[0] - 1, coords[1]},
			/*
					0 0 0 0 0
					0 0 0 0 0
					0 * x
			*/
					{coords[0] - 2, coords[1]},
			/*
			0 0 0 0 0
			0 0 0 0 0
			* 0 x
	*/
			{coords[0] - 2, coords[1] - 1},
			/*
			0 0 0 0 0
			* 0 0 0 0
			0 0 x
	*/
			{coords[0] - 1, coords[1] - 1},
			/*
			0 0 0 0 0
			0 * 0 0 0
			0 0 x
	*/
			{coords[0], coords[1] - 1 },
			/*
			0 0 0 0 0
			0 0 * 0 0
			0 0 x
	*/
			{coords[0] + 1, coords[1] - 1},
			/*
		0 0 0 0 0
		0 0 0 * 0
		0 0 x
	*/
			{coords[0] + 2, coords[1] - 1},
			/*
				0 0 0 0 0
				0 0 0 0 *
				0 0 x
			*/
			{coords[0] + 2, coords[1] - 2},
			/*
				0 0 0 0 *
				0 0 0 0 0
				0 0 x
			*/
			{coords[0] + 1, coords[1] - 2},
			/*
				0 0 0 * 0
				0 0 0 0 0
				0 0 x
			*/
			{coords[0], coords[1] - 2},
			/*
				0 0 * 0 0
				0 0 0 0 0
				0 0 x
			*/
			{coords[0] - 1, coords[1] - 2},
			/*
				0 * 0 0 0
				0 0 0 0 0
				0 0 x
			*/
			{coords[0] - 2, coords[1] - 2},
			/*
				* 0 0 0 0
				0 0 0 0 0
				0 0 x
			*/
			{coords[0], coords[1]}
		};
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 1; j++) {
				Vec3b pixel = Pyramid[0].at<Vec3b>(points[i][j], points[i][1]);
				int blue = pixel.val[0];
				int green = pixel.val[1];
				int red = pixel.val[2];
				std::cout << red << " , " << green << " , " << blue << " , " << endl; 
			}
		}
		int n = sizeof(points) / sizeof(points[0]);
		for (int i = 0; i < n; i++) {
			root = insert(root, points[i]);
		}
		pts = *points;
		getAvg(*root, sample, outSample, coords, points, root);

	}

	//a typical neighborhood would be two left, two up, on the up levels, two right 

	/*
	0 0 0 0 0
	0 0 0 0 0
	0 0 x
	*/
	//check:
	//if the incoming sample is to high up and down according to the current coord, set neighborhood up appropriately 

	//if not, go all out

	// we should be returning a current neighborhood average according to teh current cordinates 

	//in teh future, make it analyze the noise values and go up and down teh sample n find a similar thing
	return root;

}

void init() {
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);	//Line C
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(1000, 200);
	glutCreateWindow(window_name);
	//namedWindow(window_name, WINDOW_OPENGL | WINDOW_AUTOSIZE);
	//setOpenGlContext(window_name);

	//setOpenGlContext(window_name);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GLUT_SINGLE | GLUT_RGB);
	glLoadIdentity();
	glOrtho(-90, 100, -15, 100, 0.0, 1.0);
}

/*void display()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-20,20,-20,20,-1,1);
	//glClear(GL_COLOR_BUFFER_BIT);
	// gluOrtho2D(0.0,100.0,0,100.0);

	glEnable(GL_ALPHA_TEST);
	//glFlush();

	glAlphaFunc(GL_EQUAL, 1.0);
	// Size the viewport to be big enough for two images
	glViewport((GLsizei)0, (GLsizei)0, (GLsizei)640, (GLsizei)480);
	glClear(GL_COLOR_BUFFER_BIT);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	// Position first image starting at 0, 0

	if (Pyramid.size() != 0 ) {
		setMouseCallback(window_name, CallBackFunc, NULL);

		cv::cvtColor(Pyramid[0], Pyramid[0], COLOR_RGB2BGR);

		glRasterPos2i(-.5,0);

		// Get the width and height of image as first two params                              
		glDrawPixels(Pyramid[0].rows, Pyramid[0].cols, GL_RGB, GL_UNSIGNED_BYTE, Pyramid[0].data);

		// Position second image starting after the width of the first image
		//glRasterPos2i(-20, -300);
		//cv::cvtColor(Pyramid[1], Pyramid[1], COLOR_RGB2BGR);

		// get width and height of second image as first two params                                 
		glDrawPixels(Pyramid[1].rows, Pyramid[1].cols, GL_RGB, GL_UNSIGNED_BYTE, Pyramid[1].data);
		imshow(window_name, Pyramid[0]);
	/*	imshow(window_name, Pyramid[1]);
		imshow(window_name, Pyramid[2]);
		imshow(window_name, Pyramid[3]);*/

		
	/*}
	glutSwapBuffers();
	glFlush();
	

}*/
//int main() {

	/*BinaryTree* tree = new BinaryTree();
	//training set

	Node* rTrain = new Node();
	rTrain->position.x = 3;
	rTrain->position.y = 2;
	rTrain->c.R = 0;
	rTrain->c.B = 1;
	rTrain->c.G = 1;
	//tree->insert(10, rTrain->position, rTrain->c);

	Node* c = new Node();
	c->position.x = 4;
	c->position.y = 5;
	c->c.R = 1;
	c->c.B = 1;
	c->c.G = 1;
	//tree->insert(6, c->position, c->c);

	Node* d = new Node();
	d->position.x = 7;
	d->position.y = 8;
	d->c.R = 1;
	d->c.B = 1;
	d->c.G = 1;
	//tree->insert(14, d->position, d->c);

	Node* e = new Node();
	e->position.x = 8;
	e->position.y = 9;
	e->c.R = 1;
	e->c.B = 1;
	e->c.G = 1;
//	tree->insert(5, e->position, e->c);


	//create codebook
	BinaryTree* codeBook = new BinaryTree();
	//initial codebook vectors
	Node* iy1 = new Node();
	iy1->position.x = 1;
	iy1->position.y = 2;

	Node* iy2 = new Node();
	iy2->position = { 5,6 };
	Node* those[] = { iy1, iy2 };
	Node* nodes[] = { rTrain, c, d, e };


	Centroid(nodes, those, tree, 4);
	delete rTrain, c, d, e;*/
//}


    int main(int argc, char** argv)
    {
		namedWindow("test", WINDOW_AUTOSIZE);

		namedWindow(window_name, WINDOW_AUTOSIZE);
		const char* filename = argc >= 2 ? argv[1] : "checkbd.jpg";
		// Loads an image
		Mat src = imread(samples::findFile(filename));
		// Check if image is loaded fine
		if (src.empty()) {
			printf(" Error opening image\n");
			printf(" Program Arguments:  \n");
			return EXIT_FAILURE;
		}

		for (int i = 0; i < 4; i++) {
			pyrDown(src, src, Size(src.cols / 2, src.rows / 2)); 
		//	imgWH il = {src.cols, src.rows};
			//imgWHs.push_back(il);
			std::string imgNum = to_string(i);
			std::string newName = imgNum + "test.jpg";
			Pyramid.push_back(src);
			imwrite(newName, Pyramid[i]);
			imread(newName);
		}
		imshow(window_name, Pyramid[0]);
		Mat img(Size(Pyramid[0].cols, Pyramid[0].rows), CV_8UC3);
		//Mat lena1 = Mat::zeros(Size(Pyramid[0].cols, Pyramid[1].rows), CV_8UC1);
		randu(img, Scalar(0, 0, 0), Scalar(255, 255, 255));

		imshow("random colors image", img);
		setMouseCallback(window_name, CallBackFunc, NULL);
		
	/*	for (int y = 0; y < img.cols; y++) {
			for (int x = 0; x < img.rows; x++) {
				Vec3b pixel = img.at<Vec3b>(x, y);
				int blue = pixel.val[0];
				int green = pixel.val[1];
				int red = pixel.val[2];
				cout << "[" << blue << " " << green << " " << red << "]," << endl;
			}
			cout << endl;
		}*/

		int currentX = 0; 
		int currentY = 0;
		for (int i = 4; i < Pyramid[0].cols; i++) {
			for (int j = 5; j < Pyramid[0].rows; j++) {
				currentX = j;
				currentY = i;
				/*getAvg(**/neighborhoods(Pyramid[0], img, 0, vector<int>(currentX, currentY));//, Pyramid[0], img, vector<int>(currentX, currentY), pts, );

			}
		}

		//while synthesissing

		//while not

		waitKey();
	//	glutInit(&argc, argv);			//Line A
	//	init();					//Line B
	//	glutDisplayFunc(display);
	//	glutMainLoop();

        
		
        return EXIT_SUCCESS;
    }
  