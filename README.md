# Huffman Compressor

## 📌 Descripción

Este proyecto implementa el **algoritmo de compresión de Huffman**, permitiendo la compresión y descompresión de archivos de texto. Además, ofrece una funcionalidad adicional de **encriptación y desencriptación** mediante el **método XOR**, proporcionando una capa extra de seguridad a los archivos comprimidos.

## 📖 Algoritmo de Compresión de Huffman

El **algoritmo de Huffman** es un método de compresión sin pérdida basado en la frecuencia de los caracteres en un texto. Su funcionamiento se divide en los siguientes pasos:

1. **Análisis de frecuencia:** Se cuenta la frecuencia de aparición de cada carácter en el archivo de entrada.
2. **Construcción del árbol de Huffman:** Se crea un árbol binario donde los caracteres menos frecuentes se colocan en nodos más profundos.
3. **Generación de códigos Huffman:** Se asigna un código binario único a cada carácter en función de su posición en el árbol.
4. **Codificación del archivo:** Se reemplazan los caracteres originales por sus códigos Huffman generados.
5. **Almacenamiento:** Se guarda el archivo comprimido junto con la estructura necesaria para su posterior decodificación.

El proceso de descompresión implica leer el archivo comprimido, reconstruir el árbol de Huffman y decodificar los bits para recuperar el archivo original.

---

## 🔐 Encriptación y Desencriptación (Método XOR)

Adicionalmente, este programa permite aplicar encriptación XOR para proteger los archivos comprimidos. El método XOR funciona de la siguiente manera:

- Se elige una **clave secreta**.
- Cada byte del archivo se somete a una operación XOR con la clave.
- Para desencriptar, se aplica XOR nuevamente con la misma clave, recuperando el texto original.

Esto proporciona una capa adicional de seguridad, evitando que los archivos comprimidos sean leídos sin la clave correcta.

---

## 🚀 Instalación y Uso

### 📥 **Compilación del Proyecto**

Si el proyecto incluye un `Makefile`, puedes compilarlo con:

```bash
make
```

Esto generará el ejecutable `compressor`.

Si deseas compilar manualmente con `g++`, usa:

```bash
g++ -o compressor main.cpp HuffmanCompression.cpp -std=c++11
```

---

### 📌 **Ejemplo de Uso**

#### 🔄 Comprimir un Archivo

```bash
./compressor -c archivo.txt 
```

Esto generará `archivo_comprimido.huff`, el archivo comprimido.

#### 🔄 Descomprimir un Archivo

```bash
./compressor -x archivo_comprimido.huff 
```

Esto generará `archivo_descomprimido.txt` con el contenido original.

#### 🔒  Encriptar

```bash
./compressor -e archivo.txt 
```

Esto generará `archivo_encriptado.huff`, un archivo  encriptado.

#### 🔓  Desencriptar

```bash
./compressor -d archivo_encriptado.huff 
```

Esto recuperará el archivo original siempre que se use la misma clave utilizada en la encriptación.

#### 📌 Ver Ayuda

```bash
./compressor -h
```

Muestra un resumen de los comandos disponibles.

---

## ⚙️ Funcionalidades

✅ Compresión y descompresión de archivos mediante el **algoritmo de Huffman**.\
✅ Manejo de **archivos binarios y de texto**.\
✅ **Encriptación y desencriptación** con el **método XOR**.\
✅ Uso de estructuras eficientes para la manipulación de datos comprimidos.\
✅ Interfaz sencilla con opciones de línea de comandos para un uso fácil.

---

## 🛠️ Detalles Técnicos

### 🔹 Árbol de Huffman y Estructuras de Datos

El programa utiliza un **montón de mínimos (MinHeap)** para construir el árbol de Huffman de manera eficiente. Cada nodo del árbol es una instancia de `MinHeapNode`, con los siguientes atributos:

- `char data`: carácter almacenado en el nodo.
- `int freq`: frecuencia de aparición del carácter en el texto.
- `MinHeapNode* left, *right`: punteros a los nodos hijo izquierdo y derecho.

### 🔹 Estructura del Archivo Comprimido

El archivo comprimido almacena:

1. **Tabla de frecuencias** para reconstruir el árbol de Huffman.
2. **Bits comprimidos** codificados según el árbol de Huffman.
3. **(Opcional) Encriptación XOR**, si se activó la protección del archivo.

---

## 📄 Licencia

Este proyecto es de **uso académico**, desarrollado como parte de un curso de Sistemas Operativos.

📌 **Autor:** [Sebastian Aguilar-Tomas Zuleta-Jeronimo Cardona]\
📌 **Profesor:** [Edison Valencia]\
📌 **Curso:** [Sistemas Operativos]

---

