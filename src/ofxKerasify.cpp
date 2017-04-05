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
    isModelLoaded = true;
    return true;
}

bool ofxKerasify::predict(const std::vector<int> input_dim, const std::vector<float> input,
                          const std::vector<int> output_dim, std::vector<float> &output){
    if (!isModelLoaded){
        ofLogError() << "You need to load keras model before running";
        return false;
    }
    
    Tensor in;
    in.dims_ = input_dim;
    in.data_ = input;
    
    Tensor out;
    out.dims_ = output_dim;
    out.data_ = output;
    
    bool result = model.Apply(&in, &out);
    if (result != true){
        ofLogError() << "error: failed to apply model to the input";
        return false;
    }
    
    // Copy result
    output = out.data_;
    
    return true;
}

int ofxKerasify::getNumberOfLayers(){
    if (!isModelLoaded){
        ofLogError() << "You need to load keras model before running";
        return false;
    }
    
    return model.getNumberOfLayers();
}


bool ofxKerasify::setLayerEnabled(int layerId, bool enabled){
    if (!isModelLoaded){
        ofLogError() << "You need to load keras model before running";
        return false;
    }
    
    return model.setLayerEnabled(layerId, enabled);
}

void ofxKerasify::reset(){
    if (!isModelLoaded){
        ofLogError() << "You need to load keras model before running";
        return;
    }
    
    model.enableAllLayers();
}


