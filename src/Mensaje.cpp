
#include "Mensaje.h"

Mensaje::Mensaje(Cuenta* remitente, std::string contenido) {

    this->remitente = remitente;
    this->contenido = contenido;
    this->destinatarios = new Lista<Cuenta*>;
}

Mensaje::~Mensaje() {

    delete this->destinatarios;
}

std::string Mensaje::obtenerContenido() {

    return this->contenido;
}

Cuenta* Mensaje::obtenerRemitente() {

    return this->remitente;
}

Lista<Cuenta*>* Mensaje::obtenerDestinatarios() {

    return this->destinatarios;
}

bool Mensaje::estaBloqueado() {

    bool estaBloqueado = false;

    this->destinatarios->iniciarCursor();

    while (!estaBloqueado && this->destinatarios->avanzarCursor()) {

        Cuenta* unDestinatario = this->destinatarios->obtenerCursor();

        estaBloqueado = unDestinatario->tieneBloqueadoA(this->remitente);

    }

    return estaBloqueado;
}

