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
    bool predict(const vector<int> input_dim, const vector<float> input,
                              const vector<int> output_dim, vector<float> &output);

private:
    
    KerasModel model;
    
};
