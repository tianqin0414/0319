//
//  IHFFilter.hpp
//  FilterEngine
//
//  Created by Patrick Yang on 15/12/24.
//  Copyright © 2015年 Tencent. All rights reserved.
//

#ifndef IHFFilter_hpp
#define IHFFilter_hpp

#include "HFFilterConfig.h"
#include "HFType.h"
#include "IHFTexture.hpp"

class IHFFilter;
typedef shared_ptr<IHFFilter> IHFFilterPtr;
class HFFilterParam;
class IHFTexture;

class IHFFilter
{
public:
    IHFFilter() { }
    DLL_EXPORT virtual ~IHFFilter() { }
    
    DLL_EXPORT virtual void setInputTextureSize(HFSize size) = 0;
    DLL_EXPORT virtual void setInputTextureImage(struct _Image *image, int index) = 0;
    DLL_EXPORT virtual void setInputTexture(shared_ptr<IHFTexture> texture, int index) = 0;
    DLL_EXPORT virtual shared_ptr<IHFTexture> getInputTexture(int index) = 0;
    DLL_EXPORT virtual void setProperty(const char *name, float value) = 0;
    DLL_EXPORT virtual void setFilterFBO() = 0;
    DLL_EXPORT virtual void render(struct _Image *image = NULL) = 0;
    DLL_EXPORT virtual void setFrameBufferBlendMode(int sfactor, int dfactor) = 0;
    DLL_EXPORT virtual HFSize outputTextureSize() = 0;
    DLL_EXPORT virtual IHFTexturePtr outputTexture() = 0;
    DLL_EXPORT virtual void readOutput(struct _Image *image) = 0;
    DLL_EXPORT virtual void clearMemoryData() = 0;
    DLL_EXPORT virtual void cpuCodeSlot() = 0;
};

#endif /* IHFFilter_hpp */
