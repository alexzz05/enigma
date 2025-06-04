# Simulador de la maquina ENIGMA

Este proyecto es una version simplificada de la famosa maquina ENIGMA hecho con C++ que usaban los alemanes para cifrar mensajes durante la Segunda Guerra Mundial.

La idea es entender como funciona el cifrado con rotores (ese sistema de sustitucion que cambia segun la posicion de unas ruedas internas) y practicar lectura/escritura de ficheros.

## Que hace el programa

Cuando lo ejecutas, veras un menu con 4 opciones:


### Cifrar mensaje

- Puedes escribir el mensaje a mano o leerlo desde `desxifrat.txt`.
- El texto se limpia (se ponen mayusculas, se quitan espacios, signos, etc.).
- Se pasa por 3 rotores que transforman las letras segun su posicion.
- El resultado se guarda en `xifrat.txt`, agrupado en bloques de 5 letras (rollo militar).

### Descifrar mensaje

- Tienes que usar los mismos rotores y la misma posicion inicial que al cifrar.
- El texto cifrado se lee (a mano o desde `xifrat.txt`).
- El programa invierte el proceso del cifrado, usando el cableado al reves.
- La salida se guarda en `desxifrat.txt`.

### Editar rotores

- Puedes cambiar la configuracion de cualquier rotor (de los 3).
- Tienes que meter una permutacion valida (26 letras A-Z sin repetir).
- Tambien puedes cambiar la letra notch, que indica cuando gira el siguiente rotor (por defecto es Z si no se dice nada).

## Estructura del proyecto

├── main.cpp // Control del menu
├── main.hh
├── cifrar_descifrar.cpp // Codigo que hace el cifrado y descifrado
├── cifrar_descifrar.hh
├── in_out.cpp // Lectura y modificacion de los rotores
├── in_out.hh
├── utilidades.cpp // Funciones auxiliares
├── utilidades.hh
├── Rotor1.txt // Configuracion de cada rotor
├── Rotor2.txt
├── Rotor3.txt
├── xifrat.txt // Texto cifrado
├── desxifrat.txt // Texto claro

