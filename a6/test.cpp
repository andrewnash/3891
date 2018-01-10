//
// Created by Kovasky Buezo on 2017-11-14.
//

#include "Image.h"
#include <iostream>

int main()
{
    Image* sexypic;
	//big image, can try with less just in case
    sexypic = Image::Create(1000, 1000);

    std::cout << "Height of the image is: " << sexypic->getHeight() << "\n" << "Width of the image is: " << sexypic->getWidth() << std::endl;

    //These outputs will contain random numbers (or nothing at all, based on your implementation)
    std::cout << (int) sexypic->getRedPixel(2,2) << std::endl;
    std::cout << (int) sexypic->getGreenPixel(2,2) << std::endl;
    std::cout << (int) sexypic->getBluePixel(2,2) << std::endl;

    //this should work, it was implemented by Professor House
    if(sexypic->saveImage("nudes.ppm"))
    {
        std::cout<< "save complete" << std::endl;
    }

    std::cout << std::endl;

    //setting a specific rgb value for the pixel in location
    sexypic->setPixel(2,2,1,0,5);

    //output should be 1 0 5
    std::cout << (int) sexypic->getRedPixel(2,2) << std::endl;
    std::cout << (int) sexypic->getGreenPixel(2,2) << std::endl;
    std::cout << (int) sexypic->getBluePixel(2,2) << std::endl;

    std::cout << std::endl;

    //this should copy sexypic into this new object called sexypic2
    Image* sexypic2 = new Image(*sexypic);
    std::cout << (int) sexypic2->getRedPixel(2,2) << std::endl;
    std::cout << (int) sexypic2->getGreenPixel(2,2) << std::endl;
    std::cout << (int) sexypic2->getBluePixel(2,2) << std::endl;

    std::cout << std::endl;

    //should do the same as with sexypic 2
    Image* sexypic3 = sexypic;
    std::cout << (int) sexypic2->getRedPixel(2,2) << std::endl;
    std::cout << (int) sexypic2->getGreenPixel(2,2) << std::endl;
    std::cout << (int) sexypic2->getBluePixel(2,2) << std::endl;


    delete sexypic;
    delete sexypic2;
    delete sexypic3;

    return 0;
}