//
//  IHFTexture.hpp
//  FilterEngine
//
//  Created by Patrick Yang on 15/12/24.
//  Copyright © 2015年 Tencent. All rights reserved.
//

#ifndef IHFTexture_hpp
#define IHFTexture_hpp

#include "shared_ptr.hpp"
#include "unique_ptr.hpp"

struct _Image;

class IHFTexture;
typedef shared_ptr<IHFTexture> IHFTexturePtr;

class IHFTexture
{
public:
    IHFTexture() { };
    virtual ~IHFTexture() { };
    virtual void setImage(struct _Image *image) = 0;
    virtual struct _Image* getOutputImage() = 0;
    virtual unsigned int   getOutputTexture() = 0;
};

#endif /* IHFTexture_hpp */
