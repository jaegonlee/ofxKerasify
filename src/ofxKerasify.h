//
//  ofxKerasify.h
//  example-mnist_mlp
//
//  Created by Nao Tokui on 3/30/17.
//
//

#pragma once

// openFrameworks
#include "ofMain.h"
#include "keras_model.h"

class ofxKerasify {
    
public:
    ofxKerasify();
    ~ofxKerasify();
    
    bool loadModel(const string& filename);
    bool predict(const std::vector<float> input, std::vector<float> &output);

private:
    
    KerasModel model;
    
};
