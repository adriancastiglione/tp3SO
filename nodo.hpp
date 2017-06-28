#ifndef _NODO_H
#define _NODO_H

#define BUFFER_SIZE 1024


#include "mpi.h"
#include "base.h"

/* Función que maneja un nodo.
 * Recibe el rank del nodo.
 */
void nodo(unsigned int rank);

/* Simula un tiempo de procesamiento no determinístico.
 */
void trabajarArduamente();

/* Protocolos */
void load(MPI_Status);


#endif  /* _NODO_H */
