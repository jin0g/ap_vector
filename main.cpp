#include <iostream>
#include "ap_int.h"
#include "ap_vector.h"

int main() {
    // Create ap_vector from an ap_uint value
    // Initialize ap_uint<32> value1 with 0x12345678
    ap_uint<32> value1 = 0x12345678;
    ap_vector<4, 8> list1 = value1;

    // Initialize ap_uint<32> value2 with 0x11111111
    ap_uint<32> value2 = 0x11111111;
    ap_vector<4, 8> list2 = value2;

    // Print the original list1 elements
    std::cout << "Original list1 elements: ";
    for (int i = 0; i < 4; ++i) {
        std::cout << std::hex << list1[i] << " ";
    }
    std::cout << std::endl;

    // Modify elements in ap_vector
    list1[1] = 0xAB;
    list1[3] = 0xCD;

    // Print the modified list1 elements
    std::cout << "Modified list1 elements: ";
    for (int i = 0; i < 4; ++i) {
        std::cout << std::hex << list1[i] << " ";
    }
    std::cout << std::endl;

    // Perform addition operation between list1 and list2
    auto list3 = list1 + list2;

    // Print the result of the addition operation (list3 elements)
    std::cout << "list3 elements (list1 + list2): ";
    for (int i = 0; i < 4; ++i) {
        std::cout << std::hex << list3[i] << " ";
    }
    std::cout << std::endl;

    // Convert ap_vector list1 back to an ap_uint value (result1)
    ap_uint<32> result1 = list1;

    // Print the result1 value in hexadecimal
    std::cout << "result1 (list1 as ap_uint<32>): " << std::hex << result1 << std::endl;

    // Demonstrate various arithmetic and shift operations with ap_vector and ap_int
    auto list_add = list1 + list2;
    auto list_sub = list1 - list2;
    auto list_mul = list1 * list2;
    auto list_shl = list1 << 1;
    auto list_shr = list1 >> 1;

    auto list_const_add = list1 + 2;
    auto list_const_sub = list1 - 2;
    auto list_const_mul = list1 * 2;
    auto list_const_shl = list1 << 2;
    auto list_const_shr = list1 >> 2;

    // Example of not using 'auto' for the resulting ap_vector type
    ap_vector<4, 8> list4 = list1 + list2;

    // Demonstrate complex numerical calculations using ap_vector and ap_int
    auto complex_calculation = (list1 + list2 * 3) << 1;
    std::cout << "Complex calculation result: ";
    for (int i = 0; i < 4; ++i) {
        std::cout << std::hex << complex_calculation[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}