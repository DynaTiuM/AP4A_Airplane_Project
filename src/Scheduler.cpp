#include "Scheduler.h"

#include <iostream>
#include <chrono>

using namespace std;

// Basic constructor
Scheduler::Scheduler()
{
	m_server = new Server();
	m_frequency = 2.;

    m_sensor1 = new Humidity<float>();
    m_sensor2 = new Light<bool>();
    m_sensor3 = new Pression<int>();
    m_sensor4 = new Temperature<float>();
}

// Copy constructor
Scheduler::Scheduler(Scheduler& scheduler_p)
{
    this->m_sensor1 = scheduler_p.m_sensor1;
    this->m_sensor2 = scheduler_p.m_sensor2;
    this->m_sensor3 = scheduler_p.m_sensor3;
    this->m_sensor4 = scheduler_p.m_sensor4;
    
    m_server = scheduler_p.m_server;
	m_frequency = scheduler_p.m_frequency;
}

// Assignment constructor
Scheduler& Scheduler::operator=(Scheduler& scheduler_p)
{
    this->m_sensor1 = scheduler_p.m_sensor1;
    this->m_sensor2 = scheduler_p.m_sensor2;
    this->m_sensor3 = scheduler_p.m_sensor3;
    this->m_sensor4 = scheduler_p.m_sensor4;

    m_server = scheduler_p.m_server;
	m_frequency = scheduler_p.m_frequency;

    return *this;
}

void Scheduler::wait(float frequency_p)
{
    // Initialising delta and lastTime
    time_t lastTime = time(NULL); 
    time_t delta = 0;

    // While delta value is inferior to the frequency passed in parameter, we continue the same processing
    while (delta < frequency_p)
    {
        time_t now = time(NULL);
        // the new value of delta is the difference between the current time and the last time when the method was called
        delta = (now - lastTime);
        // Thus, the value of delta is modified in relation to time
    }
    // when the loop is ended, we leave the method and the programm can continue to run
}

void Scheduler::ask()
{
	char answer;
	do{
		std::cin >> answer;
	}
    while(answer != 'c' && answer != 'l' && answer != 'y' && answer != 'q');
	
    // We check the answer of the user thanks to this method
    checkAnswer(answer);
}

void Scheduler::launchThreads(){
    // Every thread has different frequency of getting datas
    // Thus, every thread call the loop method parallely and can execute it independently of each other
    
    // Setting threads with lamda expressions
    std::thread thread1([this](){
        // Frequency of datas every second
		loop(*m_sensor1,1.F);
	});
	std::thread thread2([this](){
        // Frequency of datas every 2 seconds
		loop(*m_sensor2,2.F);
	});
	std::thread thread3([this](){
        // Frequency of datas every 5 seconds
		loop(*m_sensor3,5.F);
	});	
    std::thread thread4([this](){
        // Frequency of datas every 10 seconds
	    loop(*m_sensor4,10.F);
	});
    std::thread thread5([this](){
        while(isRunning()) ask();
	});

	thread1.join();
	thread2.join();
	thread3.join();
	thread4.join();
	thread5.join();
}

bool Scheduler::isRunning()
{
    // Returns true if the console is activated or logs are activated
    // Otherwise, it means that the program should'nt run anymore
    return (m_server->m_consoleActivation || m_server->m_logActivation);
}

void Scheduler::checkAnswer(char answer_p)
{
    // We check the user's answer
    switch(answer_p){
        // The user pressed q, it means that he wants to quit the program, we desactivate the console and logs
        case 'q' :
            m_server->m_consoleActivation = false;
            m_server->m_logActivation = false;
            cout << "Quitting program" << endl;
        break;
        // The user pressed c, he wants either to activate or desactivate console
        case 'c' :
            // The console is activated, we desactivate it
            if(m_server->m_consoleActivation){
                m_server->m_consoleActivation = false;
                cout << "Console desactivated!" << endl;
            }
            // The console is desactivated, we activate it
            else
            {
                m_server->m_consoleActivation = true;
                cout << "Console activated!" << endl;
            }
        break;
        // The user pressed l, he want either to activate or desactivate logs
        case 'l' :
            if (m_server->m_logActivation)
            {
                m_server->m_logActivation = false;
                cout << "Logs desactivated!" << endl;
            }
            else
            {
                m_server->m_logActivation = true;
                cout << "Logs activated!" << endl;
            }
        break;
        // The user pressed y, he wants to activate or desactivate both logs and console
        case 'y' :
            if(m_server->m_consoleActivation && m_server->m_logActivation)
            {
                m_server->m_consoleActivation = false;
                m_server->m_logActivation = false;
                cout << "Console & Logs desactivated!" << endl;
            }
            else
            {
                m_server->m_consoleActivation = true;
                m_server->m_logActivation = true;
                cout << "Console & Logs activated!" << endl;
            }
        break;
    }
}