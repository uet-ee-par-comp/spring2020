#include <Timer.hpp>
#include <iostream>
#include <iomanip>

using LOFAR::NSTimer;
using std::cout;
using std::cerr;
using std::endl;
using std::fixed;
using std::setprecision;


void rgb2gray(unsigned char *inputImage, unsigned char *grayImage, const int width, const int height) 
{

	for ( int y = 0; y < height; y++ ) 
	{
		for ( int x = 0; x < width; x++ ) 
		{
			float grayPix = 0.0f;
			float r = static_cast< float >(inputImage[(y * width) + x]);
			float g = static_cast< float >(inputImage[(width * height) + (y * width) + x]);
			float b = static_cast< float >(inputImage[(2 * width * height) + (y * width) + x]);

			grayPix = (0.3f * r) + (0.59f * g) + (0.11f * b);

			grayImage[(y * width) + x] = static_cast< unsigned char >(grayPix);
		}
	}

	
	
}

void histogram1D(unsigned char *grayImage, unsigned char *histogramImage, const int width, const int height, 
				unsigned int *histogram, const unsigned int HISTOGRAM_SIZE, const unsigned int BAR_WIDTH) 
{
	unsigned int max = 0;
	
	memset(reinterpret_cast< void * >(histogram), 0, HISTOGRAM_SIZE * sizeof(unsigned int));

	for ( int y = 0; y < height; y++ ) {
		for ( int x = 0; x < width; x++ ) {
			histogram[static_cast< unsigned int >(grayImage[(y * width) + x])] += 1;
		}
	}

	for ( unsigned int i = 0; i < HISTOGRAM_SIZE; i++ ) {
		if ( histogram[i] > max ) {
			max = histogram[i];
		}
	}

	for ( int x = 0; x < HISTOGRAM_SIZE * BAR_WIDTH; x += BAR_WIDTH ) {
		unsigned int value = HISTOGRAM_SIZE - ((histogram[x / BAR_WIDTH] * HISTOGRAM_SIZE) / max);

		for ( unsigned int y = 0; y < value; y++ ) {
			for ( unsigned int i = 0; i < BAR_WIDTH; i++ ) {
				histogramImage[(y * HISTOGRAM_SIZE * BAR_WIDTH) + x + i] = 0;
			}
		}
		for ( unsigned int y = value; y < HISTOGRAM_SIZE; y++ ) {
			for ( unsigned int i = 0; i < BAR_WIDTH; i++ ) {
				histogramImage[(y * HISTOGRAM_SIZE * BAR_WIDTH) + x + i] = 255;
			}
		}
	}
	

}

void contrast1D(unsigned char *grayImage, const int width, const int height, unsigned int *histogram, 
				const unsigned int HISTOGRAM_SIZE, const unsigned int CONTRAST_THRESHOLD) 
{
	unsigned int i = 0;

	while ( (i < HISTOGRAM_SIZE) && (histogram[i] < CONTRAST_THRESHOLD) ) {
		i++;
	}
	unsigned int min = i;

	i = HISTOGRAM_SIZE - 1;
	while ( (i > min) && (histogram[i] < CONTRAST_THRESHOLD) ) {
		i--;
	}
	unsigned int max = i;
	float diff = max - min;

	for ( int y = 0; y < height; y++ ) {
		for (int x = 0; x < width; x++ ) {
			unsigned char pixel = grayImage[(y * width) + x];

			if ( pixel < min ) {
				pixel = 0;
			}
			else if ( pixel > max ) {
				pixel = 255;
			}
			else {
				pixel = static_cast< unsigned char >(255.0f * (pixel - min) / diff);
			}
			
			grayImage[(y * width) + x] = pixel;
		}
	}


}

void triangularSmooth(unsigned char *grayImage, unsigned char *smoothImage, 
					  const int width, const int height, const float *filter) 
{

	for ( int y = 0; y < height; y++ ) {
		for ( int x = 0; x < width; x++ ) {
			unsigned int filterItem = 0;
			float filterSum = 0.0f;
			float smoothPix = 0.0f;

			for ( int fy = y - 2; fy < y + 3; fy++ ) {
				for ( int fx = x - 2; fx < x + 3; fx++ ) {
					if ( ((fy < 0) || (fy >= height)) || ((fx < 0) || (fx >= width)) ) {
						filterItem++;
						continue;
					}

					smoothPix += grayImage[(fy * width) + fx] * filter[filterItem];
					filterSum += filter[filterItem];
					filterItem++;
				}
			}

			smoothPix /= filterSum;
			smoothImage[(y * width) + x] = static_cast< unsigned char >(smoothPix);
		}
	}

	

}

