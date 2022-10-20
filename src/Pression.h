/*
 * @author raphael_perrin
 * @file Pression.h
 * @date 05/10/2022
 * @brief Pression class, herited class from the Sensor superclass. Sensor that gets the pressure in the plane.
 */

#ifndef PRESSION_H
#define PRESSION_H
#include "Sensor.h"

template <class T>
class Pression : public Sensor<T>
{
public :
	Pression(){
        this->setData(this->aleaGenVal());
	    this->setSpecifications("Pression","hPa");
    }

protected :
	/*
    * @brief Method that generates a random number between 55 and 850 hPa
    * @return T
    * @param none
    */
	T aleaGenVal(){
        return rand() % 795 + 55;
    }
};

#endif // PRESSION_H