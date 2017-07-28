#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxCv.h"

using namespace cv;
using namespace ofxCv;

class ofApp : public ofBaseApp{

  public:
		void setup();
		void update();
		void draw();
  
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

    cv::Mat frame, prevFrame, prevFrameGray, currFrameGray;
//    cv::Size frameSize;
//    cv::Point p1, p2;
//  
//  std::vector<::Point2f> prevCorners;
//  std::vector<::Point2f> currCorners;
//  
//  std::vector<uchar> featuresFound;
//  std::vector<float> featuresErrors;
//  
//  ofImage outputOfImg01, outputOfImg02;
//  
    ofVideoGrabber cam;

    bool isFirstTime;
    
    // Features
    vector<cv::Point2f> prevCorners;
    vector<cv::Point2f> currCorners;
    vector<uchar> featuresFound;
    vector<float> featuresErrors;
    
    int beginTime;
    int elapsedTime;
//  };
};
