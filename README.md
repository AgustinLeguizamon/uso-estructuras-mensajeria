Algoritmos y Programación 2 - FI UBA

# Uso de Estructuras Dinámicas: Mensajería

## Enunciado

Considerando las clases:

* Mensaje: [`Mensaje.h`](../enunciado/src/Mensaje.h) - [`Mensaje.cpp`](../enunciado/src/Mensaje.cpp)
        
* Cuenta: [`Cuenta.h`](../enunciado/src/Cuenta.h) - [`Cuenta.cpp`](../enunciado/src/Cuenta.cpp)    

1. Implementar el método `contarMensajesBloqueados` de la clase `Mensajero`:

```c++

class Mensajero {

  public:

    /* post: procesa 'mensajesPendientes' para contabilizar aquellos 
     *       Mensajes que tienen como uno de sus destinatarios
     *       a una Cuenta en cuya lista de remitentesBloqueados 
     *       está el remitente del Mensaje. 
     */ 
    unsigned int contarMensajesBloqueados(Lista<Mensaje*>* mensajesPendientes);

};

``` 


## Solución

1. Implementación del método `contarMensajesBloqueados`:

* [`Mensajero.h`](../punto-01/src/Mensajero.h)

* [`Mensajero.cpp`](../punto-01/src/Mensajero.cpp)

**Mejora**: agrega el método `bool Mensaje::estaBloqueado()` para reemplazar `bool Mensajero::estaBloqueado(Mensaje* unMensaje)` y el método `bool Cuenta::tieneBloqueadoA(Cuenta* otraCuenta)` para reemplazar `bool Mensajero::destinatarioBloqueaRemitente(Cuenta* destinatario, Cuenta* remitente)`

* Mensajero: [`Mensajero.h`](../punto-01-mejora/src/Mensajero.h) - [`Mensajero.cpp`](../punto-01-mejora/src/Mensajero.cpp)

* Mensaje: [`Mensaje.h`](../punto-01-mejora/src/Mensaje.h) - [`Mensaje.cpp`](../punto-01-mejora/src/Mensaje.cpp)
        
* Cuenta: [`Cuenta.h`](../punto-01-mejora/src/Cuenta.h) - [`Cuenta.cpp`](../punto-01-mejora/src/Cuenta.cpp)    
