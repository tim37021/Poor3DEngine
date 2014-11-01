#ifndef UTILS_BITMAP_H_
#define UTILS_BITMAP_H_

namespace Poor3D
{
	namespace Utils
	{
		#pragma pack(2)
		struct BITMAP_FILEHEADER{
			//Magic identifier, BM(0x42,0x4d)
			unsigned short int type;
			unsigned int size; 		//File size in bytes
			unsigned short int reserved1, reserved2;
			unsigned int offset;	//Offset to image data, bytes

		};

		struct BITMAP_INFOHEADER{
			unsigned int size;	//Info Header size in bytes
			int width, height;	//Width and height of image
			unsigned short int planes;	//Number of colour planes
			unsigned short int bits; 	//Bits per pixel
			unsigned int compression; 	//Compression type
			unsigned int imagesize;		//Image size in bytes
			int xresolution, yresolution; //Pixels per meter
			unsigned int ncolours; 		//Number of colours
			unsigned int importantcolours; //Important colours

		};

		inline void *getBMPRaw(unsigned char *image, BITMAP_FILEHEADER *header)
		{
			return (unsigned char *)image+header->offset;
		}

		#pragma pack(4)

		unsigned char *loadBMP(const char *filename, BITMAP_FILEHEADER **header, BITMAP_INFOHEADER **info);
	}

}

#endif