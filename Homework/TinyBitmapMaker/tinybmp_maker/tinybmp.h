#pragma once

#include <iostream>
#include "tinybmp_def.h"

class TinyBitmap
{
public:
	TinyBitmap();
	TinyBitmap(const char* _path);
	virtual ~TinyBitmap();

public:
	void print_header(std::ostream& strm);
	void print_info_header(std::ostream& strm);

public:
	bool import_image(const char* _path);
	bool export_image(const char* _path);

private:
	BITMAP_HEADER m_header;
	BITMAP_INFO_HEADER m_info_header;

	char*** m_image_buf;
};