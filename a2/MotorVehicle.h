/*!
 * @file      MotorVehicle.h
 * @brief     Declaration of the MotorVehicle class.
 *
 * @author    Andrew House <andrew.w.h.house@mun.ca>
 * @copyright (c) 2017 Andrew House. All rights reserved.
 * @license   Apache License, Version 2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License.  You may obtain a copy
 * of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
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
#if !defined(MOTORVEHICLE_H)
#define MOTORVEHICLE_H

#include <string>

/**
 * A basic representation of a motor vehicle that could be
 * used for a traffic simulation or video game.
 */
class MotorVehicle
{
public:
    enum class Category
    {
        Motorcycle,
        Car,
        SUV,
        Jeep,
        Pickup,
        Bus,
        Tractor,
        Semi
    };

    /**
     * Construct a new MotorVehicle.
     *
     * @param   vehicleType     the category of vehicle (motorcycle, car, etc.)
     * @param   numDoors        the number of doors the vehicle has
     * @param   maxPassengers   the maximum recommended number of passengers
     * @param   engineHP        horsepower rating of the engine
     * @param   licensePlate    the license plate of the vechile
     */
    MotorVehicle(Category vehicleType, unsigned int numDoors,
                 unsigned int maxPassengers, double engineHP,
                 std::string licensePlate);

    /**
     * Add a passenger to the vehicle.
     *
     * This method, in the normal case, will only add a passenger if the
     * number of passengers is less than the maximum number of passengers.
     * However, it is possible to explicitly override the capacity limit
     * if needs must.
     *
     * **Note:** for this assignment, we do not have or use any details
     *           about the passengers, we only track the total number of them
     *
     * @param   overrideLimits    force addition of a passenger, even
     *                            if capacity has already been reached
     *
     * @returns whether or not the passenger was added
     */
    bool addPassenger(bool overrideLimit = false);

    //! What is the maximum number of passengers for this vehicle?
    unsigned int getMaxPassengers() const;

    //! How many passengers currently in the vehicle?
    unsigned int getNumPassengers() const;

    //! How many spots remain for passengers in this vehicle?
    int getSpotsRemaining() const;

    //! How many doors does the vehicle have?
    unsigned int getNumDoors() const;

    //! What is the engine horsepower?
    double getHorsepower() const;

    //! Set a new horsepower (i.e. replace the engine).
    void setHorsepower(double newHP);

    //! What is the vehicle license plate?
    std::string getLicense() const;

private:
    const Category vehicleType;
    const unsigned int maxPassengers;
    const unsigned int doors;
    const std::string plate;
    double horsepower;
    unsigned int currentPassengers;
};

#endif // the end of the MOTORVEHICLE_H header guard

