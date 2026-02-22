Este proyecto ha sido creado como parte del currículo de 42 por vjamet-s

# Descripcion
Este proyecto imprime las diferentes lineas de u archivo

# Instrucciones

Si queremos utilizar esta libreria en un proyecto ajeno podemos utilizar ->
#include "get_next_line.h"

# Recursos
Referencias técnicas

Manuales de Unix:

man read, open, malloc

Uso de Inteligencia Artificial:

Se ha utilizado IA como herramienta de apoyo para:

Revisar explicaciones teóricas sobre el comportamiento de funciones estándar.

Contrastar casos límite y comportamientos esperados.

# Funciones Principales

**get_next_line**  
Lee y devuelve una línea del fd.

**read_until**  
Lee del fd hasta encontrar `\n` o EOF.

**extract_line**  
Saca la línea completa del buffer.

**save_remainder**  
Guarda lo que sobra para la siguiente llamada.


# Utils

**ft_strlen**  
Longitud de string.

**ft_strjoin**  
Une dos strings.

**has_newline**  
Detecta `\n` en string.

**ft_memcpy**  
Copia memoria.

**ft_strdup**  
Duplica string.
