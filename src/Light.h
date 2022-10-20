/*
 * @author raphael_perrin
 * @file Light.h
 * @date 05/10/2022
 * @brief Light class, herited class from the Sensor superclass. Sensor that gets the light in the plane.
 */

#ifndef LIGHT_H
#define LIGHT_H

#include "Sensor.h"

template <class T>
class Light : public Sensor<T>
{
public :
	Light(){
        this->setData(this->aleaGenVal());
	    this->setSpecifications("Light");
    }
protected :
	/*
    * @brief Method that generates a random number between 0 and 1 (ON or OFF)
    * @return T
    * @param none
    */
	T aleaGenVal(){
        return rand() % 2 == 1 ? true : false;
    }
};

#endif // LIGHT_H