
#include "Cuenta.h"

Cuenta::Cuenta(std::string nombre) {

    this->nombre = nombre;
    this->remitentesBloqueados = new Lista<Cuenta*>;
}

std::string Cuenta::obtenerNombre() {

    return this->nombre;
}
Lista<Cuenta*>* Cuenta::obtenerRemitentesBloqueados() {

    return this->remitentesBloqueados;
}

bool Cuenta::tieneBloqueadoA(Cuenta* otraCuenta) {

    bool tieneBloqueado = false;

    this->remitentesBloqueados->iniciarCursor();

    while (!tieneBloqueado && this->remitentesBloqueados->avanzarCursor()) {

        Cuenta* cuentaBloqueada = this->remitentesBloqueados->obtenerCursor();

        tieneBloqueado = (otraCuenta == cuentaBloqueada);
    }

    return tieneBloqueado;
}


Cuenta::~Cuenta() {

    delete this->remitentesBloqueados;
}
