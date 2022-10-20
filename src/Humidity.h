/*
 * @author raphael_perrin
 * @file Humidity.h
 * @date 05/10/2022
 * @brief Humidity class, herited class from the Sensor superclass. Sensor that gets the humidity in the plane.
 */

#ifndef HUMIDITY_H
#define HUMIDITY_H

#include "Sensor.h"

template <class T>
class Humidity : public Sensor<T>
{
public:
    Humidity(){
        this->setData(this->aleaGenVal());
	    this->setSpecifications("Humidity","%");
    }
protected :
    /*
    * @brief Method that generates a random number between 0 and 100%
    * @return T
    * @param none
    */
	T aleaGenVal(){
        return static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/101));
    }
};

#endif // HUMIDITY_H