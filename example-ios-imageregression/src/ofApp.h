#pragma once

#include "ofxiOS.h"
#include "ofxKerasify.h"
#include "ofxGui.h"

class ofApp : public ofxiOSApp {
	
    public:
        void setup();
        void update();
        void draw();
        void exit();
	
        void touchDown(ofTouchEventArgs & touch);
        void touchMoved(ofTouchEventArgs & touch);
        void touchUp(ofTouchEventArgs & touch);
        void touchDoubleTap(ofTouchEventArgs & touch);
        void touchCancelled(ofTouchEventArgs & touch);

        void lostFocus();
        void gotFocus();
        void gotMemoryWarning();
        void deviceOrientationChanged(int newOrientation);


        ofxKerasify kerasify; // handling keras model
    
        void infer(); // core function to run the loaded model
    
private:
    ofImage img;
    
    string  labelStr;
    ofxPanel gui;
    ofxToggle randomToggle;
    bool isGenerating = false;
};


