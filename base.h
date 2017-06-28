#ifndef BASE_H
#define BASE_H

//****Mensajes****//

//load
#define LOAD_REQ	1
#define LOAD_ACK	2
#define LOAD_DATA	3
#define LOAD_REL	4

#define QUIT		5

//Ranks
#define CONSOLA		0


//otros
#define BUFFER_SIZE 1024


//logs
#include <ctime>
#include <fstream>
#include <iostream>
extern std::ofstream logFile;
void log(const std::string&);

#endif