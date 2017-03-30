//
//  ofxKerasify.cpp
//  example-mnist_mlp
//
//  Created by Nao Tokui on 3/30/17.
//
//

#include "ofxKerasify.h"

ofxKerasify::ofxKerasify(){

}

ofxKerasify::~ofxKerasify(){

}

bool ofxKerasify::loadModel(const string &filename){
    
    bool result = model.LoadModel(ofToDataPath(filename));
    if (result != true){
        ofLogError() << "error: failed to load keras model";
        return false;
    }
    return true;
}

bool ofxKerasify::predict(const std::vector<float> input, std::vector<float> &output){
    
    Tensor in(1, input.size());
    in.data_ = input;
    
    Tensor out(1, output.size());
    
    bool result = model.Apply(&in, &out);
    if (result != true){
        ofLogError() << "error: failed to apply model to the input";
        return false;
    }
    
    // Copy result
    output = out.data_;
    
    return true;
}
