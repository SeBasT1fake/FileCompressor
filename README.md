# Huffman Compressor

## 📌 Descripción
Este proyecto implementa el **algoritmo de compresión de Huffman**, permitiendo comprimir y descomprimir archivos de texto. También ofrece opciones para encriptar y desencriptar archivos.

## 📖 Algoritmo de Compresión de Huffman
El **algoritmo de Huffman** es un método de compresión sin pérdida que reduce el tamaño de los archivos basándose en la frecuencia de los caracteres en el texto. Los pasos son:

1. **Contar la frecuencia de cada carácter** en el archivo de entrada.
2. **Construir un árbol binario de Huffman**, donde los caracteres con menor frecuencia tienen códigos más largos.
3. **Codificar el texto** reemplazando cada carácter con su código de Huffman.
4. **Almacenar el archivo comprimido**, que contiene la tabla de frecuencias y los bits comprimidos.

Para descomprimir, se usa la tabla de frecuencias para reconstruir el árbol de Huffman y decodificar los bits comprimidos.

## 🚀 Instalación y Uso
### 📥 **Compilación del Proyecto**
Si el código fuente incluye un `Makefile`, puedes compilarlo con:

```bash
make
```
Esto generará el ejecutable `compressor`.

### 📌 **Ejemplo de Uso**
#### 📌 Comprimir un Archivo
```bash
./compressor -c archivo.txt archivo_comprimido.huff
```
Esto generará `archivo_comprimido.huff`, el archivo comprimido.

#### 📌 Descomprimir un Archivo
```bash
./compressor -x archivo_comprimido.huff archivo_descomprimido.txt
```
Esto generará `archivo_descomprimido.txt` con el contenido original.

#### 📌 Ver Ayuda
```bash
./compressor -h
```

## ⚙️ Funcionalidades
- Compresión y descompresión de archivos con el **algoritmo de Huffman**.
- Manejo de archivos binarios y de texto.
- Opciones adicionales de encriptación y desencriptación (si están implementadas).



