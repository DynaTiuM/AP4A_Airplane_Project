/*
 * @author raphael_perrin
 * @file Scheduler.h
 * @date 05/10/2022
 * @brief Classe permettant l'envoit à une fréquence régulière des informations des Sensors de l'avion
 */

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Sensor.h"
#include "Server.h"
#include <thread>

#include "Temperature.h"
#include "Light.h"
#include "Humidity.h"
#include "Pression.h"

class Scheduler
{
private :
	Sensor<float>* m_sensor1;
	Sensor<bool>* m_sensor2;
	Sensor<int>* m_sensor3;
	Sensor<float>* m_sensor4;

	float m_frequency;

	Server* m_server;

public:
	// Definition of the canonical form
    Scheduler();
	Scheduler(Scheduler& scheduler_p);
	~Scheduler()
	{
		delete m_sensor1;
		delete m_sensor2;
		delete m_sensor3;
		delete m_sensor4;
	}
	Scheduler& operator=(Scheduler& scheduler_p);

private :
	/*
    * @brief Method that allows to stop the datas retrieval during a certain time depending on the frequency passed on paramater
    * @return void
    * @param float frequency_p
    * 
    */
    void wait(float frequency_p);

	/*
    * @brief Method allowing the program to get the datas on a specified sensor during all the program long
    * @return void
    * @param Sensor<T>& sensor_p
    * @param float frequency_p
    */
	
	template <class T> void loop(Sensor<T>& sensor_p, float frequency_p)
	{
    	while(isRunning())
		{
            this->wait(frequency_p);
			sensor_p.refreshData();
			if(m_server->m_consoleActivation)	m_server->consoleWrite(sensor_p);
			if(m_server->m_logActivation)		m_server->fileWrite(sensor_p);
		}
	}

	/*
    * @brief Method that allows to know if the program is currently working, i.e. that logs or console is activated
    * @return bool
    * @param none
    */
	bool isRunning();

	/*
    * @brief Method that checks the answer of the user and activate console or/and logs according to what the user entered
    * @return void
    * @param char answer_p
    */
	void checkAnswer(char answer_p);

public :
	/*
    * @brief Method that gets the answer that the user has entered
    * @return void
    * @param char answer_p
    */
	void ask();

	/*
    * @brief Method that launches independent threads to get datas at different frequencies
    * @return void
    * @param char answer_p
    */
	void launchThreads();
};

#endif // SCHEDULER_H