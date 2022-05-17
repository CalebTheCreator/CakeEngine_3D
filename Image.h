#pragma once
#include "stb_image.h"

class Image
{
public:
	Image(const char* file);
	~Image();
	void LoadImage();
	void SetFile(const char* file) { this->file = file; }

private:
	int width;
	int height;
	int nrChannels;
	const char* file;
	unsigned char* data;
	unsigned int texture;

};

