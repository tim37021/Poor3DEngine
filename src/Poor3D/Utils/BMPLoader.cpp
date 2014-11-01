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