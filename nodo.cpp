#include "nodo.hpp"
#include "HashMap.hpp"
#include <unistd.h>
#include <stdlib.h>

#include "base.h"
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

//variables globales del nodo
HashMap hashMap;

void nodo(unsigned int rank) {

	char buffer[BUFFER_SIZE];
	MPI_Status status;
	hashMap = HashMap();

	//convertir rank a string
	string Result;
	stringstream convert;
	convert << "rank";
	convert << rank;
	convert << ".log";

	logFile.open(convert.str().c_str(), std::fstream::out);

	bool continuar = true;
    while (continuar) {
        MPI_Recv(buffer, BUFFER_SIZE, MPI_CHAR, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
        switch(status.MPI_TAG){
        	case LOAD_REQ:
        		log("recibido LOAD_REQ");
        		load(status);
        		break;


        	case QUIT:
        		log("recibido QUIT, saliendo");
        		continuar = false;
        		break;
        }
        log("esperando nuevo protocolo");
    }

    //terminar
    logFile.close();
}


void load(MPI_Status status){

	char buffer[BUFFER_SIZE];

	//si llegas hasta aca es porque recibiste LOAD_REQ
	while(true){
		trabajarArduamente();
		log("enviando LOAD_ACK");
	    MPI_Send(buffer, 1, MPI_CHAR, CONSOLA, LOAD_ACK, MPI_COMM_WORLD);
		MPI_Recv(buffer, BUFFER_SIZE, MPI_CHAR, CONSOLA, MPI_ANY_TAG, MPI_COMM_WORLD, &status);

		switch(status.MPI_TAG){
			case LOAD_DATA:{
				std::string nombreArchivo(buffer);
				log(std::string("recibido LOAD_DATA, cargando archivo ") + nombreArchivo);
				hashMap.load(nombreArchivo);
				break;
			}

			case LOAD_REL:{
				log("recibido LOAD_REL, terminando protocolo de load");
				return; //se terminaron de cargar los archivos
			}

			default:
				//no hacer nada
				log("recibido mensaje inválido (protocolo actual: load)");
		}
	}
}

void trabajarArduamente() {
    int r = rand() % 2500000 + 500000;
    usleep(r);
}
