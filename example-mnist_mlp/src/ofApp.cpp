#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    ofSetWindowShape(600, 400);
    needsClear = true; // for initializing view
    
    // Load kerasified keras model
    // dont't forget to convert keras model into kerasify model
    kerasify.loadModel("mnist_mlp.model");
}

void ofApp::infer(){
    
    // Grab image
    ofImage img;
    img.grabScreen(50, 100, 280, 280);
    img.resize(28, 28);
    img.setImageType(OF_IMAGE_GRAYSCALE);
    
    // Image -> vector
    ofPixels pix = img.getPixels();
    std::vector<float> input;
    for (int i = 0; i < pix.size(); i++){
        input.push_back(pix.getData()[i]/255.0);
    }
    
    // INFERENCE
    output.resize(10);// output vector should be [10]. because we have 10 digits! ;-)
    kerasify.predict(input, output);
    
    // Get result
    std::vector<float>::iterator maxIt = std::max_element(output.begin(), output.end());
    size_t maxIndex = std::distance(output.begin(), maxIt);
    predicted_number = maxIndex; // result
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (needsClear) clear();
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (needsClear) clear();
    
    // Canvas
    ofSetColor(255);
    ofSetLineWidth(10);
    ofDrawBitmapString("MNIST Inference", 20, 20);
    ofDrawBitmapString("press RETURN to infer", 20, 40);
    ofDrawBitmapString("press SPACE to clear", 20, 60);
    if (ofGetMousePressed() == true){
        float mouseX = ofGetMouseX();
        float mouseY = ofGetMouseY();
        ofDrawLine(mouseX, mouseY, pmouseX, pmouseY);
        pmouseX = mouseX;
        pmouseY = mouseY;
    }
    
    // Show Result
    if (output.size() > 0){
        ofDrawBitmapString("INFERED NUMBER: " + ofToString(predicted_number), 400, 100);
        float min = *std::min_element(output.begin(), output.end());
        float max = *std::max_element(output.begin(), output.end());
        
        for (int i = 0; i < output.size(); i++){
            if (i == predicted_number) ofSetColor(255, 100, 100);
            else ofSetColor(200);
            float w = 100. * (output[i] - min)/(max - min) + 20.;
            ofDrawBitmapString(ofToString(i), 400, 160 + 20 * i);
            ofDrawRectangle(420, 150 + 20 * i, w, 10);
        }
    }
}

void ofApp::clear(){
    ofBackground(100);
    ofSetColor(0);
    ofDrawRectangle(50, 100, 280, 280);
    needsClear = false;
    
    output.resize(0);
    predicted_number = -1;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == OF_KEY_RETURN){
        infer();
    } else if (key == ' '){
        needsClear = true;
    }
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
    
    pmouseX = ofGetMouseX();
    pmouseY = ofGetMouseY();
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
