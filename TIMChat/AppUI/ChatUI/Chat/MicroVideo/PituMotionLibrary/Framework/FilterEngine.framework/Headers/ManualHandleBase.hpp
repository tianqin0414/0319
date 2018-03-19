/*
 * ManualHandleBase.h
 *
 *  Created on: 2014-1-9
 *      Author: jason
 */

#ifndef MANUALHANDLEBASE_H_
#define MANUALHANDLEBASE_H_
#include "type_common.h"

class ManualHandleBase {
public:
	ManualHandleBase()
	{

	}
    virtual ~ManualHandleBase()
    {

    }
    virtual void touchBegin(int centerX ,int centerY){}
    virtual void touchEnd(int centerX ,int centerY,int radius){}
    virtual void touchMove(int centerX ,int centerY, int offsetX ,int offsetY, int radius){}
    virtual void maskUpdate(Image *mask_image, MRect rect, int radius){}
    
    
    virtual int  canUndo() = 0;
    virtual void undoActionImage() = 0;
    virtual int  canRedo() = 0;
	virtual void redoActionImage() = 0;
    virtual int  isRawImage() = 0;
    virtual void reset() = 0;
    
    // extend
    virtual void setParamRect(MRect rect){}
    virtual void setParamMag(float mag){}
    virtual void setParamPoint(MPoint mag){}
    virtual void getParamPoint(MPoint *mag){}
};

#endif /* MANUALHANDLEBASE_H_ */
