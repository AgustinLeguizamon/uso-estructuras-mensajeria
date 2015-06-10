Algoritmos y Programaci�n 2 - FI UBA

# Uso de Estructuras Din�micas: Mensajer�a

## Enunciado

Considerando las clases:

    * Mensaje: [`Mensaje.h`](../master/src/Mensaje.h) - [`Mensaje.cpp`](../master/src/Mensaje.cpp)
        
    * Cuenta: [`Cuenta.h`](../master/src/Cuenta.h) - [`Cuenta.cpp`](../master/src/Cuenta.cpp)    

1. Implementar el m�todo `contarMensajesBloqueados` de la clase `Mensajero`:

```java

class Mensajero {

  public:

    /* post: procesa 'mensajesPendientes' para contabilizar aquellos Mensajes que tienen como uno de sus destinatarios
     *       a una Cuenta en cuya lista de remitentesBloqueados est� el remitente del Mensaje. 
     */ 
    unsigned int contarMensajesBloqueados(Lista<Mensaje*>* mensajesPendientes);

};

``` 


## Soluci�n

