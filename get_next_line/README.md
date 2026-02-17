Este proyecto ha sido creado como parte del currículo de 42 por vjamet-s

# Descripcion
Este proyecto engloba una replica la funcionalidad minima especificada por ft_printf

# Instrucciones
make #Compilamos el proyecto

Si queremos utilizar esta libreria en un proyecto ajeno podemos utilizar ->
#include "ft_printf.h"

# Recursos
Referencias técnicas

Manuales de Unix:

man printf

Uso de Inteligencia Artificial:

Se ha utilizado IA como herramienta de apoyo para:

Revisar explicaciones teóricas sobre el comportamiento de funciones estándar.

Contrastar casos límite y comportamientos esperados.

# Funciones Principales

**ft_printf**
Funcion principal que recorre a string evaluando las especificaciones

**print_arg**
Actua como dispatcher para organizar que tipo de spec y variable vamos a printear

## Funciones de conversión

**ft_put_c**
Imprimimos el caracter

**ft_put_str**
Imprimimos la string directamente

**ft_put_p**
Evaluamos el pointer y pasamos a put_base_rec el formateo exacto
**ft_put_int**
Transformamos el valor interger y su simbolo

**ft_put_hex**
Evalua que tipo de hex vamos a procesar uppercase o lowercase

## Funciones Auxiliares

**ft_put_base_rec**
Formateamos la cadena con la base indicada y imprimimos por pantalla

