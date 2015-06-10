Algoritmos y Programación 2 - FI UBA

# Uso de Estructuras Dinámicas: Mensajería

## Enunciado

Considerando las clases:

    * Mensaje: [`Mensaje.h`](../master/src/Mensaje.h) - [`Mensaje.cpp`](../master/src/Mensaje.cpp)
        
    * Cuenta: [`Cuenta.h`](../master/src/Cuenta.h) - [`Cuenta.cpp`](../master/src/Cuenta.cpp)    

1. Implementar el método `contarMensajesBloqueados` de la clase `Mensajero`:

```java

class Mensajero {

  public:

    /* post: procesa 'mensajesPendientes' para contabilizar aquellos Mensajes que tienen como uno de sus destinatarios
     *       a una Cuenta en cuya lista de remitentesBloqueados está el remitente del Mensaje. 
     */ 
    unsigned int contarMensajesBloqueados(Lista<Mensaje*>* mensajesPendientes);

};

``` 


## Solución

