#pragma once

#include "tinybmp.h"

class TinyBMPMaker
{
public:
    TinyBMPMaker();
    virtual ~TinyBMPMaker();

public:
    bool import_image(const char* _path);
    bool import_image(TinyBitmap& _image);
    bool export_image(const char* _path, unsigned _image_id = 0);

public:
    bool blur(unsigned _image_id = 0);
    bool grayscale(unsigned _image_id = 0);
    bool sharpen(unsigned _image_id = 0);
    unsigned char convert_to_pixel(float val);
private:
    TinyBitmap* m_image;
};