#import "GPUImageOutput.h"
#import "HFGLFrameBufferWrapper.h"

#define STRINGIZE(x) #x
#define STRINGIZE2(x) STRINGIZE(x)
#define SHADER_STRING(text) @ STRINGIZE2(text)

typedef enum {
    UIImageFlipNone = 0,
    UIImageFlipHorizontal,
    UIImageFlipVertical,
    UIImageFlipHorizontalVertical
} UIImageFlipMode;

struct GPUVector4 {
    GLfloat one;
    GLfloat two;
    GLfloat three;
    GLfloat four;
};
typedef struct GPUVector4 GPUVector4;

struct GPUMatrix4x4 {
    GPUVector4 one;
    GPUVector4 two;
    GPUVector4 three;
    GPUVector4 four;
};
typedef struct GPUMatrix4x4 GPUMatrix4x4;

@class GPUCanvas;
@class SubImageInfo;
struct Matrix3;

@interface GPUImageFilter : GPUImageOutput <GPUImageInput>
{
    HFGLTextureWrapper *filterSourceTexture, *filterSourceTexture2, *filterSourceTexture3, *filterSourceTexture4;

    HFGLFrameBufferWrapper *filterFramebuffer;

    GLProgram *filterProgram;
    GLint filterPositionAttribute, filterTextureCoordinateAttribute;
    GLint filterInputTextureUniform, filterInputTextureUniform2,filterInputTextureUniform3,filterInputTextureUniform4;
    GLfloat backgroundColorRed, backgroundColorGreen, backgroundColorBlue, backgroundColorAlpha;
        
    GLfloat *curTextureCoordinates;
    GLfloat *curVertex;
    
    GPUCanvas *originRenderer;
    float scaleFact;
    float scaleForOilPaint;
    
    struct Matrix3 *innerMatrix;
    struct Matrix3 *outerMatrix;
}

@property (nonatomic, assign) CGFloat outputScale;
@property (nonatomic, assign) UIImageOrientation textureOrientation;

// Initialization and teardown
- (id)initWithVertexShaderFromString:(NSString *)vertexShaderString fragmentShaderFromString:(NSString *)fragmentShaderString;
- (id)initWithFragmentShaderFromString:(NSString *)fragmentShaderString;
- (id)initWithFragmentShaderFromFile:(NSString *)fragmentShaderFilename;
- (void)loadVertextShader:(NSString *)vertextString fragmentShader:(NSString *)fragmentString;
- (void)initializeAttributes;
- (void)setupFilterForSize:(CGSize)filterFrameSize;

- (void)recreateFilterFBO;
- (void)setOriginRenderer:(GPUCanvas*)originFilter;

// Managing the display FBOs
- (CGSize)sizeOfFBO;
- (void)createFilterFBOofSize:(CGSize)currentFBOSize;
- (void)destroyFilterFBO;
- (void)setFilterFBO;
- (void)setOutputFBO;

// Rendering
- (void)renderToTextureWithVertices:(const GLfloat *)vertices textureCoordinates:(const GLfloat *)textureCoordinates sourceTexture:(HFGLTextureWrapper *)sourceTexture;
- (void)processFrameAtTime:(CMTime)frameTime;
- (void)informTargetsAboutNewFrameAtTime:(CMTime)frameTime;
- (void)newImageReady;

// Input parameters
- (void)setBackgroundColorRed:(GLfloat)redComponent green:(GLfloat)greenComponent blue:(GLfloat)blueComponent alpha:(GLfloat)alphaComponent;
- (void)setInteger:(GLint)newInteger forUniform:(NSString *)uniformName;
- (void)setFloat:(GLfloat)newFloat forUniform:(NSString *)uniformName;
- (void)setSize:(CGSize)newSize forUniform:(NSString *)uniformName;
- (void)setPoint:(CGPoint)newPoint forUniform:(NSString *)uniformName;
- (void)setFloatVec2:(GLfloat *)newVec2 forUniform:(NSString *)uniformName;
- (void)setFloatVec3:(GLfloat *)newVec3 forUniform:(NSString *)uniformName;
- (void)setFloatVec4:(GLfloat *)newVec4 forUniform:(NSString *)uniformName;
- (void)setFloatArray:(GLfloat *)array length:(GLsizei)count forUniform:(NSString*)uniformName;
- (void)setInputTextureImage:(NSString *)filename;
- (void)setInputTextureImage:(NSString *)filename bundlePath:(NSString *)bundlePath;  // bundlePath不空，从素材包里取资源图
- (void)setInputTextureImage:(NSString *)filename index:(int)idx;
- (void)setInputTextureImage:(NSString *)filename index:(int)idx bundlePath:(NSString *)bundlePath;  // bundlePath不空，从素材包里取资源图
- (void)onDrawFrameGLSL;
- (void)setTextureCoordinate:(const GLfloat *)textureCoordinates;
- (void)setVertex:(const GLfloat *)vertex;
- (void)setRotation:(float)radian;
- (void)setOrientationMode:(UIImageOrientation)orientationMode;
- (void)setFlipMode:(UIImageFlipMode)flipMode;
- (void)setWidth:(int)width andHeight:(int)height;
- (void)setInputImage:(UIImage *)inputImage atIndex:(NSInteger)textureIndex;
- (HFGLTextureWrapper *)getInputTexture:(int)index;
- (void)setParameter:(float)p andType:(int) t;
- (void)setParameter:(float)p;
- (void)setProperty:(NSString *)name value:(NSObject *)value;
- (NSObject *)getProperty:(NSString *)name;
- (void) setScaleFactor:(float)sf;
- (void) setSFForOilPaint:(float) sf;

//Big image
- (void)setGPUFilterSubImageInfo: (SubImageInfo *)subImgInfo;
- (void)destroyFilterArrayFBO;
- (void)resetTextureSize:(CGSize) textureSize;

@end

@interface GPUImageFilterNearest : GPUImageFilter

@end