#include <Poor3D/Utils/bitmap.h>
#include <cstdio>

using namespace Poor3D::Utils;

unsigned char *Poor3D::Utils::loadBMP(const char *filename, BITMAP_FILEHEADER **header, BITMAP_INFOHEADER **info)
{
	FILE *fp = fopen(filename, "rb");
	fseek(fp, 0, SEEK_END);
	int size=ftell(fp);
	fseek(fp, 0, SEEK_SET);

	unsigned char *buffer = new unsigned char[size];

	*header = (BITMAP_FILEHEADER *) buffer;
	*info = (BITMAP_INFOHEADER *)(buffer+sizeof(BITMAP_FILEHEADER));

	fread(buffer, 1, size, fp);

	fclose(fp);
	return buffer;
}

void Poor3D::Utils::saveBMP(const char *filename, const void *data, int width, int height)
{
	BITMAP_FILEHEADER header={0x4d42, 
		sizeof(BITMAP_FILEHEADER)+sizeof(BITMAP_INFOHEADER)+width*height*3
		, 0, 0, sizeof(BITMAP_FILEHEADER)+sizeof(BITMAP_INFOHEADER)};
	BITMAP_INFOHEADER info={sizeof(BITMAP_INFOHEADER), width, height, 1, 24, 0, width*height*3, width, height, 0, 1};

	FILE *fp = fopen(filename, "wb");

	fwrite(&header, 1, sizeof(header), fp);
	fwrite(&info, 1, sizeof(info), fp);

	fwrite(data, 1, width*height*3, fp);

	fclose(fp);
}