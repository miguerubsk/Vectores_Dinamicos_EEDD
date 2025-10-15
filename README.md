# Vectores Dinámicos EEDD

[![C++](https://img.shields.io/badge/language-C++-blue.svg)](https://cppreference.com/)
[![Licencia MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/miguerubsk/Vectores_Dinamicos_EEDD/blob/master/LICENSE.md)
[![Estado](https://img.shields.io/badge/status-active-brightgreen.svg)]()
<br>
[![Build and Run](https://github.com/miguerubsk/Vectores_Dinamicos_EEDD/actions/workflows/c-cpp.yml/badge.svg)](https://github.com/miguerubsk/Vectores_Dinamicos_EEDD/actions/workflows/c-cpp.yml)
[![CodeQL Advanced](https://github.com/miguerubsk/Vectores_Dinamicos_EEDD/actions/workflows/codeql.yml/badge.svg)](https://github.com/miguerubsk/Vectores_Dinamicos_EEDD/actions/workflows/codeql.yml)

## Descripción

Vectores Dinámicos EEDD es una implementación en C++ de una estructura de datos tipo vector dinámico, con operaciones de inserción, eliminación, ordenación y búsqueda binaria. Incluye una clase `Cliente` para pruebas y ejemplos de uso, orientado a prácticas de estructuras de datos.

## Tabla de Contenidos

- [Instalación](#instalación)
- [Uso](#uso)
- [Estructura del Proyecto](#estructura-del-proyecto)
- [Contribuir](#contribuir)
- [Licencia](#licencia)
- [Contacto](#contacto)
- [Reconocimientos](#reconocimientos)

## Instalación

1. Clona el repositorio:
	```sh
	git clone https://github.com/miguerubsk/Vectores_Dinamicos_EEDD.git
	```
2. Compila el proyecto con tu compilador C++ favorito:
	```sh
	g++ main.cpp -o vectores -std=c++11
	```
	O usa tu IDE (Code::Blocks, Visual Studio, CLion, etc).

3. Ejecuta el binario generado:
	```sh
	./vectores
	```

## Uso

- El programa lee clientes desde un archivo CSV (`clientes_v2.csv`), los almacena en un vector dinámico y realiza operaciones como ordenación, búsqueda binaria y eliminación.
- Calcula la distancia máxima entre clientes usando coordenadas UTM.
- Puedes modificar el código para probar otras estructuras o tipos de datos.

## Estructura del Proyecto

```
Vectores_Dinamicos_EEDD/
│
├── Cliente.h              # Definición de la clase Cliente y UTM
├── vectordinamico.h       # Implementación del vector dinámico genérico
├── main.cpp               # Ejemplo de uso y pruebas
├── clientes_v2.csv        # Archivo de datos de ejemplo (no incluido)
├── LICENSE                # Licencia MIT
└── README.md              # Este archivo
```

## Contribuir

Las contribuciones son bienvenidas. Puedes abrir issues para sugerencias o errores, y enviar pull requests con mejoras o nuevas funcionalidades.

## Licencia

Distribuido bajo la Licencia MIT. Consulta el archivo [`LICENSE`](https://github.com/miguerubsk/Vectores_Dinamicos_EEDD/blob/master/LICENSE.md) para más información.

## Contacto

[Fernando Jiménez Quesada](https://github.com/ferazules1998) y [Miguel González García](https://github.com/miguerubsk)

## Reconocimientos

- [othneildrew/Best-README-Template](https://github.com/othneildrew/Best-README-Template) por la plantilla.
- [shields.io](https://shields.io/) por los badges.
- C++ Standard Library.
