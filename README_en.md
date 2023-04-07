# ap_vector

Introducing the `ap_vector` library, a powerful integer vector computation library designed for Vitis HLS. Featuring seamless bidirectional type conversion between wide ap_uint types and ap_vector types, ap_vector provides numpy-like arithmetic operations. With ap_vector, complicated loop descriptions for HLS become more convenient, and code readability is significantly improved. Start leveraging the power of ap_vector in your HLS projects today!

## Overview

The `ap_vector` class provides the following features:

- Easily convert between long bit-width types of `ap_int` and arrays of the `ap_vector` type.
- Perform arithmetic and left-right shift operations between `ap_vector` objects and between `ap_vector` and `ap_int` objects.
- Convert between `ap_vector` objects with different bit widths.

## Usage

### Defining and Initializing ap_vector

```c++
#include "ap_int.h"
#include "ap_vector.h"

// Example: Create a 4-element ap_vector with 8-bit width
ap_uint<32> value = 0x12345678;
ap_vector<4, 8> list = value;
```

### Accessing and Modifying Elements

```c++
// Access an element
ap_int<8> elem = list[0];

// Modify an element
list[1] = 0xAB;
```

### Arithmetic and Shift Operations

```c++
// ap_vector and const value
auto list_add1 = list1 + 1234;

// ap_vector and ap_int
ap_int<32> item = 4321;
auto list_add2 = list1 + item;

// Operations between ap_vectors (example: addition)
auto list_add3 = list1 + list2;
```


You can perform addition between ap_vectors using the + operator as shown above.
In addition, the following operations are available:
```c++
- Subtraction: list1 - list2
- Multiplication: list1 * list2
- Division: list1 / list2
- Remainder: list1 % list2
- Left shift: list1 << list2
- Right shift: list1 >> list2
```

### Type Conversions

```c++
// Conversion from ap_uint to ap_vector
ap_uint<32> value = 0x12345678;
ap_vector<4, 8> list = value;

// Conversion from ap_vector to ap_uint
ap_uint<32> result = list;

// Conversion between ap_vector objects with different bit widths
ap_vector<4, 16> list2 = ap_vector<4, 16>(list1);
```


## NOTE
- ap_int cannot be cast bidirectionally with ap_vector, so it is recommended to use ap_uint instead.
- Proper performance may not be achieved without using the appropriate #pragma directives.
- In most cases, it is recommended to use ap_vector inside a #pragma HLS pipeline.

## Sample Code

Sample code can be found in `main.cc`. It contains test code that covers the full functionality, so please refer to it for understanding the implementation details and usage.


## Acknowledgements

This project was created entirely with the help of ChatGPT.
