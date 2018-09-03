/* The MIT License (MIT)
 *
 * Copyright (c) 2018 David Medina
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 */

#ifndef OCCA_PY_TOPY_HEADER
#define OCCA_PY_TOPY_HEADER

#include "defines.hpp"


namespace occa {
  namespace py {
    // Special
    static PyObject* none() {
      Py_RETURN_NONE;
    }

    template <class TM>
    static PyObject* toPy(const TM &value) {
      value.NOT_IMPLEMENTEED;
    }

    // Bool
    template <>
    PyObject* toPy<bool>(const bool &b) {
      if (b) {
        Py_RETURN_TRUE;
      }
      Py_RETURN_FALSE;
    }

    // Integer Types
    template <>
    PyObject* toPy<int>(const int &value) {
      return PyLong_FromLong((long) value);
    }

    template <>
    PyObject* toPy<long>(const long &value) {
      return PyLong_FromLong(value);
    }

    template <>
    PyObject* toPy<long long>(const long long &value) {
      return PyLong_FromLong(value);
    }

    template <>
    PyObject* toPy<size_t>(const size_t &value) {
      return PyLong_FromSize_t(value);
    }

    // Float / Double
    template <>
    PyObject* toPy<float>(const float &value) {
      return PyFloat_FromDouble((double) value);
    }

    template <>
    PyObject* toPy<double>(const double &value) {
      return PyFloat_FromDouble(value);
    }

    // String
    PyObject* toPy(const char *c) {
      return PyUnicode_FromString(c);
    }

    template <>
    PyObject* toPy<std::string>(const std::string &s) {
      return PyUnicode_FromString(s.c_str());
    }

    // Props / JSON
    template <>
    PyObject* toPy<occa::properties>(const occa::properties &props) {
      return toPy(props.dump(0));
    }

    template <>
    PyObject* toPy<occa::json>(const occa::json &j) {
      return toPy(j.dump(0));
    }
  }
}


#endif
