#include "Image.h"
#include <iostream>
#include <fstream>



Image::Image(unsigned int w, unsigned int h, unsigned char* pxArray): pixelWidth(w), pixelHeight(h), pixelArray(pxArray)
{}

Image* Image::Create(unsigned int width, unsigned int height)
{
    Image* img = new Image(width, height, new unsigned char[3*width*height]); //create new image on heap and initalize with values as describer in header
    if(!img) //check if sucessfull
    {
        return nullptr;
    }
    return img;
}

Image::~Image()
{
    delete []pixelArray; //delete pixel array and set to nullptr
    pixelArray = nullptr;
}

Image::Image(const Image& img) : pixelWidth(img.getWidth()), pixelHeight(img.getHeight())
{
    pixelArray = new unsigned char [3 * img.getWidth() * img.getHeight()]; //create new pixel array 
    for(int y = 0; y < img.getHeight(); y++) //nested for loops used to set x and y for reach pixel, 
    {       
        for(int x = 0; x < img.getWidth(); x++)
        {
            unsigned char R = img.getRedPixel(x,y);
            unsigned char G = img.getGreenPixel(x,y);
            unsigned char B = img.getBluePixel(x,y);

            setPixel(x, y, R, G, B);
        }
    }
}


Image& Image::operator = (const Image& img)
{
    return *(new Image(img)); //use copy constructor to = new image
}

unsigned char Image::getRedPixel(unsigned int x, unsigned int y) const
{
    return *(pixelArray + y * (3 * this->pixelWidth) + 3*x);
}  

unsigned char Image::getGreenPixel(unsigned int x, unsigned int y) const
{
    return *(pixelArray + y * (3 * this->pixelWidth) + 3*x + 1);
}

unsigned char Image::getBluePixel(unsigned int x, unsigned int y) const
{
    return *(pixelArray + y * (3 * this->pixelWidth) + 3*x + 2);
}

void Image::setPixel(unsigned int x, unsigned int y,
              unsigned char r, unsigned char g, unsigned char b)
{
    pixelArray[y * (3 * this->pixelWidth) + 3*x + 0] = r;
    pixelArray[y * (3 * this->pixelWidth) + 3*x + 1] = g;
    pixelArray[y * (3 * this->pixelWidth) + 3*x + 2] = b;
}


unsigned int Image::getWidth() const
{
    return pixelWidth;
}

unsigned int Image::getHeight() const
{
    return pixelHeight;
}

/*
* The saveImage method makes the assumption that the 3 colours for each pixel are stored
* horizontally next to each other.
*/
bool Image::saveImage(std::string filename)
{
    try
    {
        // Open a file for writing.
        std::ofstream myfile;
        myfile.open (filename);
        
        // Write header info
        myfile << "P6\n" << this->pixelWidth << " "
               << this->pixelHeight << "\n255\n";
        
        // Write stored pixel values as rows.
        for (int y = 0; y < this->pixelHeight; y++)
        {
            for (int x = 0; x < this->pixelWidth * 3; x += 3)
            {
                int idx = y * (3 * this->pixelWidth) + 3*x;
                myfile << this->pixelArray[idx] << " "
                       << this->pixelArray[idx+1] << " "
                       << this->pixelArray[idx+2] << " ";
            }
            myfile << "\n";
        }
  
        myfile.close();
    }
    catch (...)
    {
        // If a file-related exception occurs, just return false.
        return false;
    }
    return true;
}