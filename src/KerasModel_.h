//
//  KerasModel_.h
//  example-ios-imageregression
//
//  Created by Nao Tokui on 4/5/17.
//
//

#ifndef KerasModel__hpp
#define KerasModel__hpp

#include <stdio.h>
#include "keras_model.h"

class KerasModel_ : public KerasModel {
public:
    bool LoadModel(std::string filepath);
    int getNumberOfLayers();
    bool setLayerEnabled(int layerId, bool enabled);
    bool Apply(Tensor* in, Tensor* out);
    void enableAllLayers();
private:
    std::vector<bool> layers_active;
};

#endif /* KerasModel__hpp */
