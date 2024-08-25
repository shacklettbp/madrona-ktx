#ifndef MADRONA_KTX_MADRONA_KTX_H
#define MADRONA_KTX_MADRONA_KTX_H

#include <ktx.h>
#include <string>
#include <span>

namespace ktx {

struct ConvertedOutput {
    void *textureData;
    int width;
    int height;
    size_t bufferSize;
};

void loadKTXMem(void * pixel_data,
                size_t buffer_size,
                ConvertedOutput* out);

}

#endif //MADRONA_KTX_MADRONA_KTX_H
