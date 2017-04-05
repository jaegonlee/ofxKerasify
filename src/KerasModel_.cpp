//
//  KerasModel_.cpp
//  example-ios-imageregression
//
//  Created by Nao Tokui on 4/5/17.
//
//

#include "KerasModel_.h"
#include "ofMain.h"

bool KerasModel_::LoadModel(std::string filepath)
{
    bool result = KerasModel::LoadModel(filepath);
    if (result) enableAllLayers();
    return result;
}

int KerasModel_::getNumberOfLayers(){
    return layers_.size();
}

bool KerasModel_::setLayerEnabled(int layerId, bool enabled){
    int num_layers = getNumberOfLayers();
    if (layerId < 0 || layerId >= num_layers){
        ofLogError() << "Invalid layerId" << layerId;
        return false;
    }
    layers_active[layerId] = enabled;
    return true;
}

bool KerasModel_::Apply(Tensor* in, Tensor* out) {
    Tensor temp_in, temp_out;
    
    for (unsigned int i = 0; i < layers_.size(); i++) {
        if (i == 0) {
            temp_in = *in;
        }
        
        if  (layers_active[i])
            layers_[i]->Apply(&temp_in, &temp_out);
        
        temp_in = temp_out;
    }
    
    *out = temp_out;
    
    return true;
}

void KerasModel_::enableAllLayers(){
    int num_layers = getNumberOfLayers();
    layers_active.assign(num_layers, true);
}
