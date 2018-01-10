
#include "Image.h"
#include <iostream>
using namespace std;

int main()
{
    

    Image* sq100 = Image::Create(100, 100);
    if (sq100)
    {
    	cout << "Success!" << endl;
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                sq100->setPixel(i, j, 100, 200, 50);            
            }
        }
    }
    else
    {
        cout << "Error! Image::Create() method returned nullptr! Quitting with no more tests..." << endl;
    }

    // Test 0 verifies that image exists and pixel values set
    // properly as indicated above.

    // Tests 1 and 2: copy constructor and assignment operator
    // Verifies succesful create of these new images
    Image sq2(*sq100);
    Image* sq3 = Image::Create(50,50);
    if (sq3)
    {
        *sq3 = sq2; // overwrite 50x50
    }

    // Tests 3 and 4: Make changes to each of the images to
    // verify that they all own their own memory.

    // ...


    // Delete the heap-allocated images.
    // sq2 will be deleted when scope of main ends.
    delete sq100;
    delete sq3;

    return 0;
}
