#include "tinybmp_maker.h"

TinyBMPMaker::TinyBMPMaker()
:m_image(NULL)
{

}

TinyBMPMaker::~TinyBMPMaker()
{
    delete m_image;
}

bool TinyBMPMaker::import_image(const char *_path)
{
    m_image = new TinyBitmap(_path);

    return true;
}

bool TinyBMPMaker::import_image(TinyBitmap &_image)
{
    if(m_image != NULL)
        delete m_image;

    m_image = new TinyBitmap(_image);
    return true;
}

bool TinyBMPMaker::export_image(const char *_path, unsigned _image_id)
{
    m_image->export_image(_path);
    return true;
}

unsigned char TinyBMPMaker::convert_to_pixel(float val)
{
    if(val >= 255)
        return 255;
    else if(val <= 0)
        return 0;
    else
        return (unsigned char)(val);
}

bool TinyBMPMaker::blur(unsigned int _image_id)
{
    float filter[3][3] = {{1/9.0, 1/9.0, 1/9.0}, {1/9.0, 1/9.0, 1/9.0}, {1/9.0, 1/9.0, 1/9.0}};
    BITMAP_INFO_HEADER bih = m_image->get_bitmap_info_header();
    unsigned char*** image_buf = m_image->get_buf();

    float pixel_val_r, pixel_val_g, pixel_val_b;
    for(int i = 1; i < bih.height-1; i++)
    {
        for(int j = 1; j < bih.width-1; j++)
        {
            pixel_val_b = filter[0][0]* image_buf[i-1][j-1][0] +
                        filter[0][1]* image_buf[i-1][j  ][0] +
                        filter[0][2]* image_buf[i-1][j+1][0] +

                        filter[1][0]* image_buf[i  ][j-1][0] +
                        filter[1][1]* image_buf[i  ][j  ][0] +
                        filter[1][2]* image_buf[i  ][j+1][0] +

                        filter[2][0]* image_buf[i+1][j-1][0] +
                        filter[2][1]* image_buf[i+1][j  ][0] +
                        filter[2][2]* image_buf[i+1][j+1][0];

            pixel_val_g = filter[0][0]* image_buf[i-1][j-1][1] +
                        filter[0][1]* image_buf[i-1][j  ][1] +
                        filter[0][2]* image_buf[i-1][j+1][1] +
                        filter[1][0]* image_buf[i  ][j-1][1] +
                        filter[1][1]* image_buf[i  ][j  ][1] +
                        filter[1][2]* image_buf[i  ][j+1][1] +
                        filter[2][0]* image_buf[i+1][j-1][1] +
                        filter[2][1]* image_buf[i+1][j  ][1] +
                        filter[2][2]* image_buf[i+1][j+1][1];

            pixel_val_r = filter[0][0]* image_buf[i-1][j-1][2] +
                        filter[0][1]* image_buf[i-1][j  ][2] +
                        filter[0][2]* image_buf[i-1][j+1][2] +
                        filter[1][0]* image_buf[i  ][j-1][2] +
                        filter[1][1]* image_buf[i  ][j  ][2] +
                        filter[1][2]* image_buf[i  ][j+1][2] +
                        filter[2][0]* image_buf[i+1][j-1][2] +
                        filter[2][1]* image_buf[i+1][j  ][2] +
                        filter[2][2]* image_buf[i+1][j+1][2];

            image_buf[i][j][0] = convert_to_pixel(pixel_val_b);
            image_buf[i][j][1] = convert_to_pixel(pixel_val_g);
            image_buf[i][j][2] = convert_to_pixel(pixel_val_r);
        }
    }
    return true;
}

bool TinyBMPMaker::sharpen(unsigned int _image_id){
    //float filter[3][3] = {{1/9.0, 1/9.0, 1/9.0}, {1/9.0, 1/9.0, 1/9.0}, {1/9.0, 1/9.0, 1/9.0}};
    float filter[3][3] = {{-1, -1, -1}, {-1, 9, -1}, {-1, -1, -1}};
    BITMAP_INFO_HEADER bih = m_image->get_bitmap_info_header();
    unsigned char*** image_buf = m_image->get_buf();

    float pixel_val_r, pixel_val_g, pixel_val_b;
    for(int i = 1; i < bih.height-1; i++)
    {
        for(int j = 1; j < bih.width-1; j++)
        {
            pixel_val_b = filter[0][0]* image_buf[i-1][j-1][0] +
                          filter[0][1]* image_buf[i-1][j  ][0] +
                          filter[0][2]* image_buf[i-1][j+1][0] +

                          filter[1][0]* image_buf[i  ][j-1][0] +
                          filter[1][1]* image_buf[i  ][j  ][0] +
                          filter[1][2]* image_buf[i  ][j+1][0] +

                          filter[2][0]* image_buf[i+1][j-1][0] +
                          filter[2][1]* image_buf[i+1][j  ][0] +
                          filter[2][2]* image_buf[i+1][j+1][0];

            pixel_val_g = filter[0][0]* image_buf[i-1][j-1][1] +
                          filter[0][1]* image_buf[i-1][j  ][1] +
                          filter[0][2]* image_buf[i-1][j+1][1] +
                          filter[1][0]* image_buf[i  ][j-1][1] +
                          filter[1][1]* image_buf[i  ][j  ][1] +
                          filter[1][2]* image_buf[i  ][j+1][1] +
                          filter[2][0]* image_buf[i+1][j-1][1] +
                          filter[2][1]* image_buf[i+1][j  ][1] +
                          filter[2][2]* image_buf[i+1][j+1][1];

            pixel_val_r = filter[0][0]* image_buf[i-1][j-1][2] +
                          filter[0][1]* image_buf[i-1][j  ][2] +
                          filter[0][2]* image_buf[i-1][j+1][2] +
                          filter[1][0]* image_buf[i  ][j-1][2] +
                          filter[1][1]* image_buf[i  ][j  ][2] +
                          filter[1][2]* image_buf[i  ][j+1][2] +
                          filter[2][0]* image_buf[i+1][j-1][2] +
                          filter[2][1]* image_buf[i+1][j  ][2] +
                          filter[2][2]* image_buf[i+1][j+1][2];

            image_buf[i][j][0] = convert_to_pixel(pixel_val_b);
            image_buf[i][j][1] = convert_to_pixel(pixel_val_g);
            image_buf[i][j][2] = convert_to_pixel(pixel_val_r);
        }
    }
    return true;
}

bool TinyBMPMaker::grayscale(unsigned int _image_id)
{
    BITMAP_INFO_HEADER bih = m_image->get_bitmap_info_header();
    unsigned char*** image_buf = m_image->get_buf();
    float pixel_val;
    for(int i = 0; i < bih.height; i++) {
        for (int j = 0; j < bih.width; j++) {
            pixel_val = (image_buf[i][j][0]*0.114 + image_buf[i][j][1]*0.587 + image_buf[i][j][2]*0.299);
            image_buf[i][j][0] = image_buf[i][j][1] = image_buf[i][j][2] = convert_to_pixel(pixel_val);

        }
    }
    return true;
}