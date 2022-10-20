#include "Scheduler.h"
#include <iostream>
#include <thread>

int main()
{
    Scheduler scheduler;

    // Asking user the parameters he wants to activate
    std::cout << "Activate console only : c" << std::endl;
    std::cout << "Activate logs only : l" << std::endl;
    std::cout << "Activate logs and console : y" << std::endl; 
    std::cout << "\nTo desactivate/activate \n\t- logs\n\t- console\n\t- both\nduring the program, press the same keys as mentionned above during the program" << std::endl;
    std::cout << "\n-- Press 'q' to simply quit the programm --\n" << std::endl;
	
    // User's response is analyzed thanks to this method
    scheduler.ask();

    // Launching threads to get the datas of sensors with different frequencies
    scheduler.launchThreads();

    return 0;
}
