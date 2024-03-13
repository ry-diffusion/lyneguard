#pragma once

#define unique(type) type *const restrict
#define list(type) unique(type)

typedef unsigned char byte;
// typedef unsigned char bool;
typedef char Int8;
typedef short int Int16;
typedef int Int32;
typedef long int Int64;

typedef unsigned char Uint8;
typedef unsigned short int Uint16;
typedef unsigned int Uint32;

typedef unsigned long int Uint64;

typedef float f32;
typedef double f64;

typedef unique(char) str;
