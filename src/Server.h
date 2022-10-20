/*
 * @author raphael_perrin
 * @file Server.h
 * @date 05/10/2022
 * @brief Server class that allows to display the datas of sensors on console or/and write them in logs
 */

#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Sensor.h"

class Server
{

private :
    bool m_consoleActivation;
    bool m_logActivation;

public:
    // Definition of canonical form
    Server();
    ~Server(){}
    Server(const Server& server_p);
    Server& operator=(const Server& server_p);

private :
    /*
    * @brief Method that displays the datas of the sensors on the console
    * @return void
    * @param Sensor<T>& sensor
    */
    template <typename T> void consoleWrite(Sensor<T>& sensor_p)
    {
        std::cout << sensor_p.getName() << " : " << sensor_p.getData() << " " << sensor_p.getUnity() << std::endl;
    }

    /*
    * @brief Method that writes the datas of the sensors in a log file
    * @return void
    * @param Sensor&<T> sensor
    */
    template <typename T> void fileWrite(Sensor<T>& sensor_p)
    {
        // The path should be modified if the user is using this program on another device
        std::string path = "C:/Users/rapha/AP4A/src/";

        // This allows to set the datas in independent files according to the name of the sensor
        path += sensor_p.getName();
        // Extension of the file
        path += ".txt";
        std::string filename(path);
        FILE *o_file = fopen(filename.c_str(), "a");
        // If the file can be opened
        if (o_file)
        {
            std::string chaine;
            chaine += sensor_p.getName();
            chaine += " ";    
            chaine += std::to_string(sensor_p.getData());
            chaine += " ";
            chaine += sensor_p.getUnity();
            chaine += "\n";
            // We write this new line on the file opened
            fwrite(chaine.c_str(), 1, chaine.size(), o_file);
        }
        // We close the file
        fclose(o_file);
    }

    friend class Scheduler;
};

#endif // SERVER_H