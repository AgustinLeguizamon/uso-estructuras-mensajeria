
#include "gtest/gtest.h"

/* hack/truco para poder correr las pruebas sin copiar los fuentes */
#include "Mensajero.cpp"
#include "Mensaje.cpp"
#include "Cuenta.cpp"

class MensajeroTest : public ::testing::Test {

    protected:

        Mensajero mensajero;

        Lista<Mensaje*>* mensajes;
        Lista<Cuenta*>* cuentas;

        virtual void setUp() {

            mensajes = new Lista<Mensaje*>;
            cuentas = new Lista<Cuenta*>;
        }

        virtual void tearDown() {

            cuentas->iniciarCursor();
            while (cuentas->avanzarCursor()) {

                delete cuentas->obtenerCursor();
            }
            delete cuentas;

            mensajes->iniciarCursor();
            while (mensajes->avanzarCursor()) {

                delete mensajes->obtenerCursor();
            }
            delete mensajes;
        }
};

TEST_F(MensajeroTest, crear) {

    Mensajero mensajero;
}
