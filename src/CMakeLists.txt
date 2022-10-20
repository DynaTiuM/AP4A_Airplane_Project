cmake_minimum_required(VERSION 3.10)

project(TP_Note)

find_package(Threads)

add_executable(TP_Note Main.cpp Scheduler.h Scheduler.cpp Humidity.h Light.h Pression.h Sensor.h Server.cpp Server.h Temperature.h)
target_link_libraries(TP_Note PUBLIC Threads::Threads)