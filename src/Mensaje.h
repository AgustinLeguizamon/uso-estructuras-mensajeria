
#ifndef MENSAJE_H_
#define MENSAJE_H_

#include <string>
#include "Cuenta.h"
#include "Lista.h"

class Mensaje {

    private:

        Cuenta* remitente;

        std::string contenido;

        Lista<Cuenta*>* destinatarios;

    public:

        /* post: Mensaje con el contenido indicado y sin Destinatarios.
         */
        Mensaje(Cuenta* remitente, std::string contenido);

        /* post: devuelve el contenido del Mensaje.
         */
        std::string obtenerContenido();

        /* post: devuelve la Cuenta que envía el Mensaje.
         */
        Cuenta* obtenerRemitente();

        /* post: devuelve todas las Cuentas a las que debe enviar el Mensaje.
         */
        Lista<Cuenta*>* obtenerDestinatarios();

        /**
         * post: devuelve si uno de los destinatarios
         *       tiene bloqueado al remitente.
         */
        bool estaBloqueado();

        /* post: libera los recursos tomados.
         */
        ~Mensaje();
};

#endif /* MENSAJE_H_ */
