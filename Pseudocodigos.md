# Fisica-Computacional


## Ejercicio 1: Préstamo de libro en la Biblioteca Central

```text
INICIO
    Buscar la signatura topográfica de "Cien años de soledad" en el catálogo virtual.
    
    SI el libro aparece como "Disponible" ENTONCES:
        Ir a la Biblioteca Central.
        Dejar el maletín en el locker.
        Ingresar a la sala principal de libros.
        Buscar el estante correspondiente a la signatura topográfica.
        Tomar el libro del estante.
        Dirigirse al módulo de atención.
        Entregar el libro y el carnet al trabajador de la biblioteca.
        Recibir el libro prestado y confirmar la fecha de entrega.
    SINO:
        Mostrar mensaje: "El libro está prestado, buscar otra edición o volver otro día".
    FIN SI
    
    Recoger el maletín del locker.
    Salir de la biblioteca.
FIN


## Ejercicio 2: Receta para una tortilla básica

INICIO
    Sacar 2 huevos, sal, aceite y una sartén.
    Romper los huevos en un plato.
    Añadir una pizca de sal.
    Batir los huevos con un tenedor.
    
    Poner la sartén en la estufa.
    Encender el fuego a nivel medio.
    Añadir un poco de aceite a la sartén.
    
    MIENTRAS el aceite no esté caliente HACER:
        Esperar 5 segundos.
    FIN MIENTRAS
    
    Verter los huevos batidos en la sartén.
    
    MIENTRAS la parte de abajo no esté firme HACER:
        Esperar.
    FIN MIENTRAS
    
    Darle la vuelta a la tortilla con una espátula.
    
    SI el otro lado ya está dorado ENTONCES:
        Sacar la tortilla y ponerla en un plato.
    SINO:
        Dejar cocinar un poco más y luego sacarla.
    FIN SI
    
    Apagar el fuego.
FIN

## Ejercicio 3: Comer en la Cafetería Central

INICIO
    Dirigirse a la Cafetería Central.
    
    SI NO tengo tickets recargados en el carnet ENTONCES:
        Ir al punto de venta o taquilla.
        Comprar y recargar los tickets en el carnet.
    FIN SI
    
    Hacer la fila para recibir la comida.
    Mostrar el carnet con los tickets recargados al personal.
    Tomar una bandeja y los cubiertos.
    Recibir la comida servida.
    Buscar un lugar libre, sentarse y comer.
    
    Llevar la bandeja, platos y cubiertos al punto de recolección (zona de lavado).
    Salir de la Cafetería Central.
FIN
