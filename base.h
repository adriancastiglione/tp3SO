#ifndef BASE_H
#define BASE_H

//****Mensajes****//

//load
#define LOAD_REQ		1
#define LOAD_ACK		2
#define LOAD_DATA		3
#define LOAD_REL		4

//member
#define MEMBER_REQ		5
#define MEMBER_DATA 	6

//addAndInc
#define ADD_REQ			7
#define ADD_ACK			8
#define ADD_COMMIT		9
#define ADD_ROLLBACK	10

//maximum
#define MAXIMUM_REQ		11
#define MAXIMUM_DATA	12
#define MAXIMUM_END		13

//quit
#define QUIT			14

//****Fin Mensajes****//

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