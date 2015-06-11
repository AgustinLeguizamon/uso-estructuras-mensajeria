
#include <iostream>

#include "gtest/gtest.h"

using namespace std;

/* hack/truco para poder correr las pruebas sin copiar los fuentes */
#include "Mensajero.cpp"
#include "Mensaje.cpp"
#include "Cuenta.cpp"

class MensajeroTest : public ::testing::Test {

    protected:

        Mensajero mensajero;

        Lista<Mensaje*>* mensajes;
        Lista<Cuenta*>* cuentas;

        virtual void SetUp() {

            mensajes = new Lista<Mensaje*>;
            cuentas = new Lista<Cuenta*>;
        }

        virtual void TearDown() {

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

        Cuenta* crearCuenta(std::string nombre,
                            Cuenta* bloqueado1 = NULL,
                            Cuenta* bloqueado2 = NULL) {

            Cuenta* cuenta = new Cuenta(nombre);
            cuentas->agregar(cuenta);

            if (bloqueado1 != NULL) {
                cuenta->obtenerRemitentesBloqueados()->agregar(bloqueado1);
            }
            if (bloqueado2 != NULL) {
                cuenta->obtenerRemitentesBloqueados()->agregar(bloqueado2);
            }

            return cuenta;
        }

        Mensaje* crearMensaje(Cuenta* remitente, std::string contenido,
                              Cuenta* destinatario1 = NULL,
                              Cuenta* destinatario2 = NULL,
                              Cuenta* destinatario3 = NULL) {

            Mensaje* mensaje = new Mensaje(remitente, contenido);
            mensajes->agregar(mensaje);

            if (destinatario1 != NULL) {
                mensaje->obtenerDestinatarios()->agregar(destinatario1);
            }
            if (destinatario2 != NULL) {
                mensaje->obtenerDestinatarios()->agregar(destinatario2);
            }
            if (destinatario3 != NULL) {
                mensaje->obtenerDestinatarios()->agregar(destinatario3);
            }

            return mensaje;
        }
};

TEST_F(MensajeroTest, crear) {

    Mensajero mensajero;
}

TEST_F(MensajeroTest, contarMensajeBloqueadosSinMensajes) {

    ASSERT_EQ(0, mensajero.contarMensajesBloqueados(mensajes));
}

TEST_F(MensajeroTest, contarMensajeBloqueadosConUnUnicoMensajeConElRemitenteBloqueado) {

    Cuenta* marcos = crearCuenta("Marcos");
    Cuenta* julieta = crearCuenta("Julieta");
    julieta->obtenerRemitentesBloqueados()->agregar(marcos);

    Mensaje* hola = crearMensaje(marcos, "Hola");
    hola->obtenerDestinatarios()->agregar(julieta);

    ASSERT_EQ(1, mensajero.contarMensajesBloqueados(mensajes));
}

TEST_F(MensajeroTest, contarMensajeBloqueadosConUnUnicoMensajeConElRemitenteBloqueadoEnLosDosDestinatarios) {

    Cuenta* marcos = crearCuenta("Marcos");
    Cuenta* carlos = crearCuenta("Carlos");
    Cuenta* julieta = crearCuenta("Julieta");

    julieta->obtenerRemitentesBloqueados()->agregar(marcos);
    carlos->obtenerRemitentesBloqueados()->agregar(marcos);

    Mensaje* hola = crearMensaje(marcos, "Hola");
    hola->obtenerDestinatarios()->agregar(julieta);
    hola->obtenerDestinatarios()->agregar(marcos);

    ASSERT_EQ(1, mensajero.contarMensajesBloqueados(mensajes));
}

TEST_F(MensajeroTest, contarMensajeBloqueadosConMensajesSinRemitentesBloqueados) {

    Cuenta* marcos = crearCuenta("Marcos");
    Cuenta* carlos = crearCuenta("Carlos");
    Cuenta* julieta = crearCuenta("Julieta");

    Mensaje* hola = crearMensaje(marcos, "Hola");
    hola->obtenerDestinatarios()->agregar(carlos);
    hola->obtenerDestinatarios()->agregar(julieta);
    Mensaje* comoEstas = crearMensaje(marcos, "Como estas?");
    comoEstas->obtenerDestinatarios()->agregar(julieta);
    Mensaje* saludos = crearMensaje(carlos, "Saludos");
    saludos->obtenerDestinatarios()->agregar(julieta);
    Mensaje* bienYVos = crearMensaje(julieta, "Bien y vos?");
    bienYVos->obtenerDestinatarios()->agregar(marcos);

    ASSERT_EQ(0, mensajero.contarMensajesBloqueados(mensajes));
}

TEST_F(MensajeroTest, contarMensajeBloqueadosConMensajesSinDestinatarios) {

    Cuenta* marcos = crearCuenta("Marcos");
    Cuenta* carlos = crearCuenta("Carlos");
    Cuenta* julieta = crearCuenta("Julieta");

    crearMensaje(marcos, "Hola");
    crearMensaje(marcos, "Como estas?");
    crearMensaje(carlos, "Saludos");
    crearMensaje(julieta, "Bien y vos?");

    ASSERT_EQ(0, mensajero.contarMensajesBloqueados(mensajes));
}

TEST_F(MensajeroTest, contarMultiplesMensajeBloqueados) {

    Cuenta* marcos = crearCuenta("Marcos");
    Cuenta* carlos = crearCuenta("Carlos");
    Cuenta* julieta = crearCuenta("Julieta", marcos);
    Cuenta* valeria = crearCuenta("Valeria", marcos, carlos);
    Cuenta* lucas = crearCuenta("Lucas", valeria);

    crearMensaje(marcos, "Hola", julieta, lucas, valeria);
    crearMensaje(lucas, "Como estas?", marcos);
    crearMensaje(carlos, "Saludos", valeria, lucas);
    crearMensaje(julieta, "Como va?", valeria, lucas, carlos);
    crearMensaje(lucas, "Bien y vos?", julieta);
    crearMensaje(marcos, "Hasta luego", carlos, julieta, valeria);

    ASSERT_EQ(3, mensajero.contarMensajesBloqueados(mensajes));
}

