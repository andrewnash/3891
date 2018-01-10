/*!
 * @file Image.h
 * @brief Dclaration of the Image class for Assignment 6.
 *
 * @author Andrew House <andrew.w.h.house@mun.ca>
 * @copyright (c) 2017 Andrew House. All rights reserved.
 * @license Apache License, Version 2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy
 * of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */

// The following lines are "header guards": they prevent us from redefining the
// Course class if we include this header file more than once. They effectively
// tell the pre-processor, "only pay attention to the contents of this file if
// you haven't seen them before".
#if !defined(IMAGE_H)
#define IMAGE_H

#include <string>

class Image
{
public:
    /**
    * Static method to create new Image objects.  Images are a 2D
    * array of pixels, where each pixel is comprised of an 8-bit
    * red, green, blue triple (i.e. 3 unsigned char values stored
    * per pixel).
    *
    * @params width, height - width and height of image in pixels
    *
    * @returns pointer to valid Image object if successful, else nullptr
    **/
    static Image* Create(unsigned int width, unsigned int height);
    
    //! Destructor
    ~Image();
    //! Copy Constructor
    Image(const Image&);
    //! Assignment operator overload
    Image& operator = (const Image&);
    
    //! Extracts the red value of the pixel at (x,y)
    unsigned char getRedPixel(unsigned int x, unsigned int y) const;    
    //! Extracts the green value of the pixel at (x,y)
    unsigned char getGreenPixel(unsigned int x, unsigned int y) const;
    //! Extracts the blue value of the pixel at (x,y)
    unsigned char getBluePixel(unsigned int x, unsigned int y) const;
    
    /**
    * Sets the RGB values for the pixel at (x,y).
    *
    * @params x, y - the x and y coordinates of the pixel
    *                @pre 0 <= x < pixelWidth, 0 <= y < pixelHeight
    * @params r, g, b - the red, green, and blue values respectively
    *                   for the pixel (x,y)
    * 
    * @modifies pixel data for pixel (x,y) to have new RGB values
    **/
    void setPixel(unsigned int x, unsigned int y,
                  unsigned char r, unsigned char g, unsigned char b);
    
    //! Returns width of image (in pixels)
    unsigned int getWidth() const;
    //! Returns height of image (in pixels)
    unsigned int getHeight() const;
    
    /**
    * Saves the image as a PPM file (see https://en.wikipedia.org/wiki/Netpbm_format#PPM_example)
    * based on the assumption that the 3 pixel values are stored horizontally.
    * Hence, the actual array storing values is 3x wider than its stated width, to account
    * for the 3 values (red, green, blue) stored per pixel.
    *
    * @params filename - name to save image as (should have .ppm extension)
    *
    * @returns true if no exceptions/errors encountered during save, else false
    **/
    bool saveImage(std::string filename); // This is provided for you
private:
     // Private constructor used by Create method
    Image(unsigned int w, unsigned int h, unsigned char* pxArray);
    
    // width and height of image in pixels
    unsigned int pixelWidth;
    unsigned int pixelHeight;
    
    // Pointer to array of unsigned char with
    // size 3 * pixelWidth * pixelHeight.
    // This is because each pixel is represented
    // by 3 colour values: red, green, and blue,
    // which are stored separately.
    // We are assuming we store the pixel colours
    // horizontally, so this pointer is to be
    // interpreted as a (3*pixelWidth) wide by
    // pixelHeight tall 2D array.
    unsigned char* pixelArray;
};

#endif // end of IMAGE_H header guard