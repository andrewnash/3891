#include "MotorVehicle.h"
#include <iostream>
using namespace std;


MotorVehicle::MotorVehicle(Category vehicleType, unsigned int numDoors,
                 unsigned int maxPassengers, double engineHP,
                 std::string licensePlate) : vehicleType(vehicleType), doors(numDoors),
                maxPassengers(maxPassengers), horsepower(engineHP), plate(licensePlate), currentPassengers(0){

                }


bool MotorVehicle::addPassenger(bool overrideLimit)
{
	if (currentPassengers < maxPassengers || overrideLimit == true) //We can omly add passengers if override is true or we are not full as per contract
	{
		currentPassengers++;
		return true;
	}
	else
	{
		return false;
	}
}

unsigned int MotorVehicle::getMaxPassengers() const
{
	return maxPassengers;
}

unsigned int MotorVehicle::getNumPassengers() const
{
	return currentPassengers;
}

int MotorVehicle::getSpotsRemaining() const
{
	if (maxPassengers < currentPassengers) //This if statmnet is used incase we have more passengers than current, in which case spots remaining should be 0 and not a negative number
	{
		return 0;
	}
	else
	{
		return maxPassengers - currentPassengers;
	}
}

unsigned int MotorVehicle::getNumDoors() const
{
	return doors;
}

double MotorVehicle::getHorsepower() const
{
	return horsepower;
}

void MotorVehicle::setHorsepower(double newHP)
{
	horsepower = newHP;
}

std::string MotorVehicle::getLicense() const
{
	return plate;
}
