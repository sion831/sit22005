#pragma once

#include "tinybmp.h"

class TinyBMPMaker
{
public:
    TinyBMPMaker();
    virtual ~TinyBMPMaker();

public:
    bool import_image(const char* _path);
    bool export_image(const char* _path, unsigned _image_id);

public:

private:

};