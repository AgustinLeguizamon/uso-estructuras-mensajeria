
#ifndef MENSAJERO_H_
#define MENSAJERO_H_

#include "Mensaje.h"

class Mensajero {

    public:

        /* post: procesa 'mensajesPendientes' para contabilizar aquellos
         *       Mensajes que tienen como uno de sus destinatarios
         *       a una Cuenta en cuya lista de remitentesBloqueados está
         *       el remitente del Mensaje.
         */
        unsigned int contarMensajesBloqueados(Lista<Mensaje*>* mensajesPendientes);
};

#endif /* MENSAJERO_H_ */
