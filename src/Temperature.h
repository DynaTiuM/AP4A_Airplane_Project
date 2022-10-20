/*
 * @author raphael_perrin
 * @file Temperature.h
 * @date 05/10/2022
 * @brief Temperature class, herited class from the Sensor superclass. Sensor that gets the temperature in the plane.
 */

#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "Sensor.h"

template <class T>
class Temperature : public Sensor<T>
{
public :
	Temperature(){
		this->setData(this->aleaGenVal());
		this->setSpecifications("Temperature","degrees Celsius");
	}
	
protected :
	/*
    * @brief Method that generates a random number between 23 and 25 (ON or OFF)
    * @return T
    * @param none
    */
	T aleaGenVal(){
		return static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/2)) + 23.;
	}
};

#endif // TEMPERATURE_H