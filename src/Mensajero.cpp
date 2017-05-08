
#include "Mensajero.h"

unsigned int Mensajero::contarMensajesBloqueados(Lista<Mensaje*>* mensajesPendientes) {

    unsigned int bloqueados = 0;

    mensajesPendientes->iniciarCursor();

    while (mensajesPendientes->avanzarCursor()) {

        Mensaje* mensajeActual = mensajesPendientes->obtenerCursor();

        if (mensajeActual->estaBloqueado()) {

            bloqueados++;
        }
    }

    return bloqueados;
}
