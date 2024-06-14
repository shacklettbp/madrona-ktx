#include "madrona_ktx.h"

void loadKTXMem(void *pixelData, size_t bufferSize, ConvertedOutput* out) {
    ktxTexture *ktexture;
    KTX_error_code result;
    ktx_size_t offset;
    ktx_uint8_t *image;
    ktx_uint32_t level, layer, faceSlice;
    result = ktxTexture_CreateFromMemory((ktx_uint8_t *) pixelData,
                                         bufferSize,
                                         KTX_TEXTURE_CREATE_LOAD_IMAGE_DATA_BIT,
                                         &ktexture);
    convertKTXTexture(ktexture,BC7, out);

    ktxTexture_Destroy(ktexture);
}
void convertKTXTexture(ktxTexture *tex, OutputFormat format, ConvertedOutput* out){
    if (tex->classId == ktxTexture2_c) {
        ktxTexture2 *texture2 = (ktxTexture2 *) tex;
        KTX_error_code ret = ktxTexture2_TranscodeBasis(texture2, KTX_TTF_BC7_RGBA, 0);
    }
    void *pixels = tex->pData;

    ktx_size_t tex_offset;
    ktxTexture_GetImageOffset(tex, 0, 0, 0, &tex_offset);
    ktx_size_t tex_size = ktxTexture_GetImageSize(tex, 0);

    uint32_t width = tex->baseWidth;
    uint32_t height = tex->baseHeight;

    size_t pixel_data_size = tex_size;
    void* pixel_data = malloc(pixel_data_size);

    memcpy(pixel_data, (void *)((char *)pixels + tex_offset), tex_size);

    out->texture_data = pixel_data;
    out->width = width;
    out->height = height;
    out->bufferSize = tex_size;
}
