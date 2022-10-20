/*
 * @author raphael_perrin
 * @file Sensor.h
 * @date 05/10/2022
 * @brief Superclass of herited classes Humidity, Light, Pression & Temperature
 */

#ifndef SENSOR_H
#define SENSOR_H

#define LENGTH 2

template <class T>
class Sensor
{
	
private:
	T m_data;
	const char* m_name;
	const char* m_unity;

public:
	// Definition of the canonical form
	Sensor(){
		this->m_data = 0;
   		this->m_name = "";
		this->m_unity = "";

	}
	virtual ~Sensor() {}
	Sensor(const Sensor& sensor_p){
		this->m_data = sensor_p.m_data;
   		this->m_name = sensor_p.m_name;
		this->m_unity = sensor_p.m_unity;
	}
	Sensor& operator=(const Sensor& sensor_p){
		this->m_data = sensor_p.m_data;
   		this->m_name = sensor_p.m_name;
		this->m_unity = sensor_p.m_unity;

    	return *this;
	}

	/*
    * @brief Getter getting the value of the private attribute m_data
    * @return T
    * @param none
    */
	T getData(){
		return m_data;
	}

	/*
    * @brief Getter getting the name of the Sensor
    * @return const char*
    * @param none
    */
	const char* getName(){
		return m_name;
	}

	/*
    * @brief Getter getting the unity of the Sensor
    * @return const char*
    * @param none
    */
	const char* getUnity(){
		return m_unity;
	}

	/*
    * @brief Méthod that refreshes the data of the sensor
    * @return void
    * @param none
    */
	void refreshData()
	{
		m_data = aleaGenVal();
	}

protected :
	/*
    * @brief Setter that allows to set the name of the sensor and its unity
    * @return void
    * @param const char* name
	* @param const char* unity
    */
	void setSpecifications(const char* name_p, const char* unity_p = ""){
		this->m_name = name_p;
		this->m_unity = unity_p;
	}

	/*
    * @brief Setter that allows the modify the data of the sensor
    * @return void
    * @param int data
    */
	void setData(T data_p){
		 this->m_data = data_p;
	}

	/*
    * @brief Abstract method that is implemented by every child class since they all have specific characteristics
    * @return int
    * @param none
    */
	virtual T aleaGenVal() = 0;
};

#endif // SENSOR_H