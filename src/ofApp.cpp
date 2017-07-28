#include "ofApp.h"
#include <opencv2/nonfree/features2d.hpp>
#include <opencv2/legacy/legacy.hpp>
#include "ofxCv.h"

////--------------------------------------------------------------

void ofApp::setup(){
  ofSetVerticalSync(true);
  ofBackground(0);
  cam.setDeviceID(0);
  cam.initGrabber(680, 480);
  isFirstTime = true;
  beginTime = ofGetElapsedTimeMillis();
  cout << beginTime << endl;
  cout << "---------------" << endl;
}

//--------------------------------------------------------------

void ofApp::update(){
  
  cam.update();
  
  if ( cam.isFrameNew() ) {
    
    // Always updating camMat
    prevFrame = ofxCv::toCv(cam);
    cvtColor(prevFrame, currFrameGray, CV_RGB2GRAY);
    
    // Get previous the image
    if(isFirstTime){
      cvtColor(prevFrame, prevFrameGray, CV_RGB2GRAY);
      isFirstTime = false;
      
      cout << "Initialize 1" << endl;
      
      goodFeaturesToTrack(prevFrameGray, prevCorners, 20, 0.05, 5.0);
    }
    
    if(ofGetElapsedTimeMillis() - beginTime > 100){
      
      // Calculate features
      goodFeaturesToTrack(prevFrameGray, prevCorners, 400, 0.01, 5);
      calcOpticalFlowPyrLK(prevFrameGray,
                           currFrameGray,
                           prevCorners,
                           currCorners,
                           featuresFound,
                           featuresErrors);
      
      // Swap images
      prevFrameGray = currFrameGray.clone();
      
      // Reset timer
      beginTime = ofGetElapsedTimeMillis();
    }
  }
}


//--------------------------------------------------------------
void ofApp::draw(){
  ofSetColor(ofColor::white);
  cam.draw(0, 0);
  ofxCv::drawMat(prevFrameGray, 680, 0, 320, 240);
  ofxCv::drawMat(currFrameGray, 680, 240, 320, 240);
  ofSetColor(ofColor::aquamarine);
  for(int i=0; i<featuresFound.size(); i++){
    ofDrawLine(ofxCv::toOf(prevCorners[i]), ofxCv::toOf(currCorners[i]));
//  cout << prevCorners[i] << "-->" << currCorners[i] << endl;
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
