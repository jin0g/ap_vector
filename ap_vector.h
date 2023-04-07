//
// Created by akira on 2023/04/07.
// ap_vector.h v1.0.0
//
#pragma once
#include <ap_int.h>

template <unsigned LENGTH, int _AP_W, bool _AP_S = true>
class ap_vector {
public:
    // Internal representation of the ap_vector
    ap_int_base<_AP_W, _AP_S> data[LENGTH];

    // Default constructor
    ap_vector() {}

    // Constructor from ap_uint with total bit width
    ap_vector(const ap_uint<LENGTH * _AP_W> &value) {
        for (int i = 0; i < LENGTH; ++i) {
            data[i] = value.range((i + 1) * _AP_W - 1, i * _AP_W);
        }
    }

    // Constructor from another ap_vector with different bit width
    template <int SRC_AP_W, bool SRC_AP_S>
    ap_vector(const ap_vector<LENGTH, SRC_AP_W, SRC_AP_S> &src) {
        for (int i = 0; i < LENGTH; ++i) {
            data[i] = src[i];
        }
    }

    // Read/Write access to individual elements
    ap_int_base<_AP_W, _AP_S> &operator[](int index) {
        return data[index];
    }

    const ap_int_base<_AP_W, _AP_S> &operator[](int index) const {
        return data[index];
    }

    // Conversion to ap_uint with total bit width
    operator ap_uint<LENGTH * _AP_W>() const {
        ap_uint<LENGTH * _AP_W> result;
        for (int i = 0; i < LENGTH; ++i) {
            result.range((i + 1) * _AP_W - 1, i * _AP_W) = data[i];
        }
        return result;
    }
};

// Macro to define arithmetic and shift operations between ap_vector and constant values
#define AP_CONST_OP(OP) \
template <unsigned LENGTH, int _AP_W, bool _AP_S, typename T, typename std::enable_if<std::is_integral<T>::value>::type* = nullptr> \
inline ap_vector<LENGTH, decltype(ap_int_base<_AP_W, _AP_S>() OP T())::width, _AP_S> operator OP(const ap_vector<LENGTH, _AP_W, _AP_S>& lhs, T rhs) { \
    ap_vector<LENGTH, decltype(ap_int_base<_AP_W, _AP_S>() OP T())::width, _AP_S> result; \
    for (int i = 0; i < LENGTH; ++i) { \
        result[i] = lhs[i] OP rhs; \
    } \
    return result; \
}

AP_CONST_OP(+)
AP_CONST_OP(-)
AP_CONST_OP(*)
AP_CONST_OP(/)
AP_CONST_OP(%)
AP_CONST_OP(<<)
AP_CONST_OP(>>)

#undef AP_CONST_OP

// Arithmetic and shift operations between an ap_vector and an ap_int
#define AP_INT_OP(OP) \
template<unsigned LENGTH, int _AP_W, bool _AP_S, int RHS_AP_W, bool RHS_AP_S> \
ap_vector<LENGTH, decltype(ap_int_base<_AP_W, _AP_S>() OP ap_int_base<RHS_AP_W, RHS_AP_S>())::width, _AP_S> operator OP(const ap_vector<LENGTH, _AP_W, _AP_S> &lhs, const ap_int_base<RHS_AP_W, RHS_AP_S> &rhs) { \
    ap_vector<LENGTH, decltype(ap_int_base<_AP_W, _AP_S>() OP ap_int_base<RHS_AP_W, RHS_AP_S>())::width, _AP_S> result; \
    for (int i = 0; i < LENGTH; ++i) { \
        result[i] = lhs[i] OP rhs; \
    } \
    return result; \
}

AP_INT_OP(+)
AP_INT_OP(-)
AP_INT_OP(*)
AP_INT_OP(/)
AP_INT_OP(%)
AP_INT_OP(<<)
AP_INT_OP(>>)

#undef AP_INT_OP

// Arithmetic and shift operations between ap_vectors
#define AP_VECTOR_OP(OP) \
template<unsigned LENGTH, int _AP_W, bool _AP_S, int RHS_AP_W, bool RHS_AP_S> \
ap_vector<LENGTH, decltype(ap_int_base<_AP_W, _AP_S>() OP ap_int_base<RHS_AP_W, RHS_AP_S>())::width, _AP_S> operator OP(const ap_vector<LENGTH, _AP_W, _AP_S> &lhs, const ap_vector<LENGTH, RHS_AP_W, RHS_AP_S> &rhs) { \
    ap_vector<LENGTH, decltype(ap_int_base<_AP_W, _AP_S>() OP ap_int_base<RHS_AP_W, RHS_AP_S>())::width, _AP_S> result; \
    for (int i = 0; i < LENGTH; ++i) { \
        result[i] = lhs[i] OP rhs[i]; \
    } \
    return result; \
}

AP_VECTOR_OP(+)
AP_VECTOR_OP(-)
AP_VECTOR_OP(*)
AP_VECTOR_OP(/)
AP_VECTOR_OP(%)
AP_VECTOR_OP(<<)
AP_VECTOR_OP(>>)

#undef AP_VECTOR_OP
