#ifndef MADRONA_KTX_MADRONA_KTX_H
#define MADRONA_KTX_MADRONA_KTX_H

//#define KHRONOS_STATIC
//#include "external/KTX-Software/include/ktx.h"
#include <ktx.h>
#include <string>
#include <span>

struct ConvertedOutput {
    void *texture_data;
    int width;
    int height;
    int pixelDataSize;
};

enum OutputFormat{
    BC7 = KTX_TTF_BC7_RGBA
};

void load_ktx_texture(std::string filename);
void loadKTXMem(void * pixelData, size_t bufferSize, ConvertedOutput* out);
void convertKTXTexture(ktxTexture* tex, OutputFormat format, ConvertedOutput* out);

#endif //MADRONA_KTX_MADRONA_KTX_H
