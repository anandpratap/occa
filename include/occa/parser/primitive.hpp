/* The MIT License (MIT)
 *
 * Copyright (c) 2014-2018 David Medina and Tim Warburton
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

#ifndef OCCA_PARSER_PRIMITIVE_HEADER
#define OCCA_PARSER_PRIMITIVE_HEADER

#include <iostream>
#include <sstream>
#include <iomanip>

#include <stdint.h>
#include <stdlib.h>

#include "occa/defines.hpp"
#include "occa/tools/string.hpp"
#include "occa/tools/sys.hpp"

namespace occa {
  //---[ Primitive Type ]---------------
  namespace primitiveType {
    static const int none       = (1 << 0);

    static const int bool_      = (1 << 1);

    static const int int8_      = (1 << 2);
    static const int uint8_     = (1 << 3);
    static const int int16_     = (1 << 4);
    static const int uint16_    = (1 << 5);
    static const int int32_     = (1 << 6);
    static const int uint32_    = (1 << 7);
    static const int int64_     = (1 << 8);
    static const int uint64_    = (1 << 9);

    static const int isSigned   = (int8_  |
                                   int16_ |
                                   int32_ |
                                   int64_);
    static const int isUnsigned = (uint8_  |
                                   uint16_ |
                                   uint32_ |
                                   uint64_);

    static const int isInteger  = (isSigned |
                                   isUnsigned);

    static const int float_     = (1 << 10);
    static const int double_    = (1 << 11);
    static const int isFloat    = (float_ |
                                   double_);

    static const int ptr        = (1 << 12);
  }
  //====================================

  class primitive {
  public:
    int type;

    union {
      bool bool_;

      uint8_t  uint8_;
      uint16_t uint16_;
      uint32_t uint32_;
      uint64_t uint64_;

      int8_t  int8_;
      int16_t int16_;
      int32_t int32_;
      int64_t int64_;

      float  float_;
      double double_;

      char* ptr;
    } value;

    inline primitive() :
      type(primitiveType::none) {
      value.ptr = NULL;
    }

    inline primitive(const primitive &p) :
      type(p.type) {
      value.ptr = p.value.ptr;
    }

    primitive(const char *c);
    primitive(const std::string &s);

    inline primitive(const bool value_) {
      type = primitiveType::bool_;
      value.bool_ = (bool) value_;
    }

    inline primitive(const uint8_t value_) {
      type = primitiveType::uint8_;
      value.uint8_ = (uint8_t) value_;
    }

    inline primitive(const uint16_t value_) {
      type = primitiveType::uint16_;
      value.uint16_ = (uint16_t) value_;
    }

    inline primitive(const uint32_t value_) {
      type = primitiveType::uint32_;
      value.uint32_ = (uint32_t) value_;
    }

    inline primitive(const uint64_t value_) {
      type = primitiveType::uint64_;
      value.uint64_ = (uint64_t) value_;
    }

    inline primitive(const int8_t value_) {
      type = primitiveType::int8_;
      value.int8_ = (int8_t) value_;
    }

    inline primitive(const int16_t value_) {
      type = primitiveType::int16_;
      value.int16_ = (int16_t) value_;
    }

    inline primitive(const int32_t value_) {
      type = primitiveType::int32_;
      value.int32_ = (int32_t) value_;
    }

    inline primitive(const int64_t value_) {
      type = primitiveType::int64_;
      value.int64_ = (int64_t) value_;
    }

    inline primitive(const float value_) {
      type = primitiveType::float_;
      value.float_ = value_;
    }

    inline primitive(const double value_) {
      type = primitiveType::double_;
      value.double_ = value_;
    }

    inline primitive(void *value_) {
      type = primitiveType::ptr;
      value.ptr = (char*) value_;
    }

    static primitive load(const char *&c,
                          const bool includeSign = true);
    static primitive load(const std::string &s,
                          const bool includeSign = true);

    static primitive loadBinary(const char *&c, const bool isNegative = false);
    static primitive loadHex(const char *&c, const bool isNegative = false);

    inline primitive& operator = (const bool value_) {
      type = primitiveType::bool_;
      value.bool_ = (bool) value_;
      return *this;
    }

    inline primitive& operator = (const uint8_t value_) {
      type = primitiveType::uint8_;
      value.uint8_ = (uint8_t) value_;
      return *this;
    }

    inline primitive& operator = (const uint16_t value_) {
      type = primitiveType::uint16_;
      value.uint16_ = (uint16_t) value_;
      return *this;
    }

    inline primitive& operator = (const uint32_t value_) {
      type = primitiveType::uint32_;
      value.uint32_ = (uint32_t) value_;
      return *this;
    }

    inline primitive& operator = (const uint64_t value_) {
      type = primitiveType::uint64_;
      value.uint64_ = (uint64_t) value_;
      return *this;
    }

    inline primitive& operator = (const int8_t value_) {
      type = primitiveType::int8_;
      value.int8_ = (int8_t) value_;
      return *this;
    }

    inline primitive& operator = (const int16_t value_) {
      type = primitiveType::int16_;
      value.int16_ = (int16_t) value_;
      return *this;
    }

    inline primitive& operator = (const int32_t value_) {
      type = primitiveType::int32_;
      value.int32_ = (int32_t) value_;
      return *this;
    }

    inline primitive& operator = (const int64_t value_) {
      type = primitiveType::int64_;
      value.int64_ = (int64_t) value_;
      return *this;
    }

    inline primitive& operator = (const float value_) {
      type = primitiveType::float_;
      value.float_ = value_;
      return *this;
    }

    inline primitive& operator = (const double value_) {
      type = primitiveType::double_;
      value.double_ = value_;
      return *this;
    }

    inline primitive& operator = (void *value_) {
      type = primitiveType::ptr;
      value.ptr = (char*) value_;
      return *this;
    }

    inline operator bool () const {
      return to<bool>();
    }

    inline operator uint8_t () const {
      return to<uint8_t>();
    }

    inline operator uint16_t () const {
      return to<uint16_t>();
    }

    inline operator uint32_t () const {
      return to<uint32_t>();
    }

    inline operator uint64_t () const {
      return to<uint64_t>();
    }

    inline operator int8_t () const {
      return to<int8_t>();
    }

    inline operator int16_t () const {
      return to<int16_t>();
    }

    inline operator int32_t () const {
      return to<int32_t>();
    }

    inline operator int64_t () const {
      return to<int64_t>();
    }

    inline operator float () const {
      return to<float>();
    }

    inline operator double () const {
      return to<double>();
    }

    template <class TM>
    inline TM to() const {
      switch(type) {
      case primitiveType::bool_   : return (TM) value.bool_;
      case primitiveType::uint8_  : return (TM) value.uint8_;
      case primitiveType::uint16_ : return (TM) value.uint16_;
      case primitiveType::uint32_ : return (TM) value.uint32_;
      case primitiveType::uint64_ : return (TM) value.uint64_;
      case primitiveType::int8_   : return (TM) value.int8_;
      case primitiveType::int16_  : return (TM) value.int16_;
      case primitiveType::int32_  : return (TM) value.int32_;
      case primitiveType::int64_  : return (TM) value.int64_;
      case primitiveType::float_  : return (TM) value.float_;
      case primitiveType::double_ : return (TM) value.double_;
      default: OCCA_FORCE_ERROR("Type not set");
      }
      return TM();
    }

    inline bool isNaN() const {
      return type & primitiveType::none;
    }

    inline bool isBool() const {
      return type & primitiveType::bool_;
    }

    inline bool isSigned() const {
      return type & primitiveType::isSigned;
    }

    inline bool isUnsigned() const {
      return type & primitiveType::isUnsigned;
    }

    inline bool isInteger() const {
      return type & primitiveType::isInteger;
    }

    inline bool isFloat() const {
      return type & primitiveType::isFloat;
    }

    inline bool isPointer() const {
      return type & primitiveType::ptr;
    }

    std::string toString() const;

    friend std::ostream& operator << (std::ostream &out, const primitive &p);

    //---[ Misc Methods ]-----------------
    inline uint64_t sizeof_() {
      switch(type) {
      case primitiveType::bool_   : return sizeof(bool);
      case primitiveType::uint8_  : return sizeof(uint8_t);
      case primitiveType::uint16_ : return sizeof(uint16_t);
      case primitiveType::uint32_ : return sizeof(uint32_t);
      case primitiveType::uint64_ : return sizeof(uint64_t);
      case primitiveType::int8_   : return sizeof(int8_t);
      case primitiveType::int16_  : return sizeof(int16_t);
      case primitiveType::int32_  : return sizeof(int32_t);
      case primitiveType::int64_  : return sizeof(int64_t);
      case primitiveType::float_  : return sizeof(float);
      case primitiveType::double_ : return sizeof(double);
      default: OCCA_FORCE_ERROR("Type not set");
      }
      return 0;
    }
    //====================================
  };

  //---[ Unary Operators ]--------------
  inline primitive not_(const primitive &p) {
    switch(p.type) {
    case primitiveType::bool_   : return primitive(!p.value.bool_);
    case primitiveType::int8_   : return primitive(!p.value.int8_);
    case primitiveType::uint8_  : return primitive(!p.value.uint8_);
    case primitiveType::int16_  : return primitive(!p.value.int16_);
    case primitiveType::uint16_ : return primitive(!p.value.uint16_);
    case primitiveType::int32_  : return primitive(!p.value.int32_);
    case primitiveType::uint32_ : return primitive(!p.value.uint32_);
    case primitiveType::int64_  : return primitive(!p.value.int64_);
    case primitiveType::uint64_ : return primitive(!p.value.uint64_);
    case primitiveType::float_  : return primitive(!p.value.float_);
    case primitiveType::double_ : return primitive(!p.value.double_);
    default: ;
    }
    return primitive();
  }

  inline primitive positive(const primitive &p) {
    switch(p.type) {
    case primitiveType::bool_   : return primitive(+p.value.bool_);
    case primitiveType::int8_   : return primitive(+p.value.int8_);
    case primitiveType::uint8_  : return primitive(+p.value.uint8_);
    case primitiveType::int16_  : return primitive(+p.value.int16_);
    case primitiveType::uint16_ : return primitive(+p.value.uint16_);
    case primitiveType::int32_  : return primitive(+p.value.int32_);
    case primitiveType::uint32_ : return primitive(+p.value.uint32_);
    case primitiveType::int64_  : return primitive(+p.value.int64_);
    case primitiveType::uint64_ : return primitive(+p.value.uint64_);
    case primitiveType::float_  : return primitive(+p.value.float_);
    case primitiveType::double_ : return primitive(+p.value.double_);
    default: ;
    }
    return primitive();
  }

  inline primitive negative(const primitive &p) {
    switch(p.type) {
    case primitiveType::bool_   : return primitive(-p.value.bool_);
    case primitiveType::int8_   : return primitive(-p.value.int8_);
    case primitiveType::uint8_  : return primitive(-p.value.uint8_);
    case primitiveType::int16_  : return primitive(-p.value.int16_);
    case primitiveType::uint16_ : return primitive(-p.value.uint16_);
    case primitiveType::int32_  : return primitive(-p.value.int32_);
    case primitiveType::uint32_ : return primitive(-p.value.uint32_);
    case primitiveType::int64_  : return primitive(-p.value.int64_);
    case primitiveType::uint64_ : return primitive(-p.value.uint64_);
    case primitiveType::float_  : return primitive(-p.value.float_);
    case primitiveType::double_ : return primitive(-p.value.double_);
    default: ;
    }
    return primitive();
  }

  inline primitive tilde(const primitive &p) {
    switch(p.type) {
    case primitiveType::bool_   : return primitive(!p.value.bool_);
    case primitiveType::int8_   : return primitive(~p.value.int8_);
    case primitiveType::uint8_  : return primitive(~p.value.uint8_);
    case primitiveType::int16_  : return primitive(~p.value.int16_);
    case primitiveType::uint16_ : return primitive(~p.value.uint16_);
    case primitiveType::int32_  : return primitive(~p.value.int32_);
    case primitiveType::uint32_ : return primitive(~p.value.uint32_);
    case primitiveType::int64_  : return primitive(~p.value.int64_);
    case primitiveType::uint64_ : return primitive(~p.value.uint64_);
    case primitiveType::float_  : OCCA_FORCE_ERROR("Cannot apply operator ~ to float type");   break;
    case primitiveType::double_ : OCCA_FORCE_ERROR("Cannot apply operator ~ to double type");  break;
    default: ;
    }
    return primitive();
  }

  inline primitive& leftIncrement(primitive &p) {
    switch(p.type) {
    case primitiveType::bool_   : OCCA_FORCE_ERROR("Cannot apply operator ++ to bool type"); break;
    case primitiveType::int8_   : ++p.value.int8_;    return p;
    case primitiveType::uint8_  : ++p.value.uint8_;   return p;
    case primitiveType::int16_  : ++p.value.int16_;   return p;
    case primitiveType::uint16_ : ++p.value.uint16_;  return p;
    case primitiveType::int32_  : ++p.value.int32_;   return p;
    case primitiveType::uint32_ : ++p.value.uint32_;  return p;
    case primitiveType::int64_  : ++p.value.int64_;   return p;
    case primitiveType::uint64_ : ++p.value.uint64_;  return p;
    case primitiveType::float_  : ++p.value.float_;   return p;
    case primitiveType::double_ : ++p.value.double_;  return p;
    default: ;
    }
    return p;
  }

  inline primitive& leftDecrement(primitive &p) {
    switch(p.type) {
    case primitiveType::bool_   : OCCA_FORCE_ERROR("Cannot apply operator -- to bool type"); break;
    case primitiveType::int8_   : --p.value.int8_;    return p;
    case primitiveType::uint8_  : --p.value.uint8_;   return p;
    case primitiveType::int16_  : --p.value.int16_;   return p;
    case primitiveType::uint16_ : --p.value.uint16_;  return p;
    case primitiveType::int32_  : --p.value.int32_;   return p;
    case primitiveType::uint32_ : --p.value.uint32_;  return p;
    case primitiveType::int64_  : --p.value.int64_;   return p;
    case primitiveType::uint64_ : --p.value.uint64_;  return p;
    case primitiveType::float_  : --p.value.float_;   return p;
    case primitiveType::double_ : --p.value.double_;  return p;
    default: ;
    }
    return p;
  }

  inline primitive rightIncrement(primitive &p) {
    primitive oldP = p;
    switch(p.type) {
    case primitiveType::bool_   : OCCA_FORCE_ERROR("Cannot apply operator ++ to bool type"); break;
    case primitiveType::int8_   : p.value.int8_++;    return oldP;
    case primitiveType::uint8_  : p.value.uint8_++;   return oldP;
    case primitiveType::int16_  : p.value.int16_++;   return oldP;
    case primitiveType::uint16_ : p.value.uint16_++;  return oldP;
    case primitiveType::int32_  : p.value.int32_++;   return oldP;
    case primitiveType::uint32_ : p.value.uint32_++;  return oldP;
    case primitiveType::int64_  : p.value.int64_++;   return oldP;
    case primitiveType::uint64_ : p.value.uint64_++;  return oldP;
    case primitiveType::float_  : p.value.float_++;   return oldP;
    case primitiveType::double_ : p.value.double_++;  return oldP;
    default: ;
    }
    return oldP;
  }

  inline primitive rightDecrement(primitive &p) {
    primitive oldP = p;
    switch(p.type) {
    case primitiveType::bool_   : OCCA_FORCE_ERROR("Cannot apply operator -- to bool type"); break;
    case primitiveType::int8_   : p.value.int8_--;    return oldP;
    case primitiveType::uint8_  : p.value.uint8_--;   return oldP;
    case primitiveType::int16_  : p.value.int16_--;   return oldP;
    case primitiveType::uint16_ : p.value.uint16_--;  return oldP;
    case primitiveType::int32_  : p.value.int32_--;   return oldP;
    case primitiveType::uint32_ : p.value.uint32_--;  return oldP;
    case primitiveType::int64_  : p.value.int64_--;   return oldP;
    case primitiveType::uint64_ : p.value.uint64_--;  return oldP;
    case primitiveType::float_  : p.value.float_--;   return oldP;
    case primitiveType::double_ : p.value.double_--;  return oldP;
    default: ;
    }
    return oldP;
  }
  //====================================


  //---[ Boolean Operators ]------------
  inline primitive lessThan(const primitive &a, const primitive &b) {
    const int retType = (a.type > b.type) ? a.type : b.type;
    switch(retType) {
    case primitiveType::bool_   : return primitive(a.to<bool>()     < b.to<bool>());
    case primitiveType::int8_   : return primitive(a.to<int8_t>()   < b.to<int8_t>());
    case primitiveType::uint8_  : return primitive(a.to<uint8_t>()  < b.to<uint8_t>());
    case primitiveType::int16_  : return primitive(a.to<int16_t>()  < b.to<int16_t>());
    case primitiveType::uint16_ : return primitive(a.to<uint16_t>() < b.to<uint16_t>());
    case primitiveType::int32_  : return primitive(a.to<int32_t>()  < b.to<int32_t>());
    case primitiveType::uint32_ : return primitive(a.to<uint32_t>() < b.to<uint32_t>());
    case primitiveType::int64_  : return primitive(a.to<int64_t>()  < b.to<int64_t>());
    case primitiveType::uint64_ : return primitive(a.to<uint64_t>() < b.to<uint64_t>());
    case primitiveType::float_  : return primitive(a.to<float>()    < b.to<float>());
    case primitiveType::double_ : return primitive(a.to<double>()   < b.to<double>());
    default: ;
    }
    return primitive();
  }

  inline primitive lessThanEq(const primitive &a, const primitive &b) {
    const int retType = (a.type > b.type) ? a.type : b.type;
    switch(retType) {
    case primitiveType::bool_   : return primitive(a.to<bool>()     <= b.to<bool>());
    case primitiveType::int8_   : return primitive(a.to<int8_t>()   <= b.to<int8_t>());
    case primitiveType::uint8_  : return primitive(a.to<uint8_t>()  <= b.to<uint8_t>());
    case primitiveType::int16_  : return primitive(a.to<int16_t>()  <= b.to<int16_t>());
    case primitiveType::uint16_ : return primitive(a.to<uint16_t>() <= b.to<uint16_t>());
    case primitiveType::int32_  : return primitive(a.to<int32_t>()  <= b.to<int32_t>());
    case primitiveType::uint32_ : return primitive(a.to<uint32_t>() <= b.to<uint32_t>());
    case primitiveType::int64_  : return primitive(a.to<int64_t>()  <= b.to<int64_t>());
    case primitiveType::uint64_ : return primitive(a.to<uint64_t>() <= b.to<uint64_t>());
    case primitiveType::float_  : return primitive(a.to<float>()    <= b.to<float>());
    case primitiveType::double_ : return primitive(a.to<double>()   <= b.to<double>());
    default: ;
    }
    return primitive();
  }

  inline primitive equal(const primitive &a, const primitive &b) {
    const int retType = (a.type > b.type) ? a.type : b.type;
    switch(retType) {
    case primitiveType::bool_   : return primitive(a.to<bool>()     == b.to<bool>());
    case primitiveType::int8_   : return primitive(a.to<int8_t>()   == b.to<int8_t>());
    case primitiveType::uint8_  : return primitive(a.to<uint8_t>()  == b.to<uint8_t>());
    case primitiveType::int16_  : return primitive(a.to<int16_t>()  == b.to<int16_t>());
    case primitiveType::uint16_ : return primitive(a.to<uint16_t>() == b.to<uint16_t>());
    case primitiveType::int32_  : return primitive(a.to<int32_t>()  == b.to<int32_t>());
    case primitiveType::uint32_ : return primitive(a.to<uint32_t>() == b.to<uint32_t>());
    case primitiveType::int64_  : return primitive(a.to<int64_t>()  == b.to<int64_t>());
    case primitiveType::uint64_ : return primitive(a.to<uint64_t>() == b.to<uint64_t>());
    case primitiveType::float_  : return primitive(a.to<float>()    == b.to<float>());
    case primitiveType::double_ : return primitive(a.to<double>()   == b.to<double>());
    default: ;
    }
    return primitive();
  }

  inline primitive notEqual(const primitive &a, const primitive &b) {
    const int retType = (a.type > b.type) ? a.type : b.type;
    switch(retType) {
    case primitiveType::bool_   : return primitive(a.to<bool>()     != b.to<bool>());
    case primitiveType::int8_   : return primitive(a.to<int8_t>()   != b.to<int8_t>());
    case primitiveType::uint8_  : return primitive(a.to<uint8_t>()  != b.to<uint8_t>());
    case primitiveType::int16_  : return primitive(a.to<int16_t>()  != b.to<int16_t>());
    case primitiveType::uint16_ : return primitive(a.to<uint16_t>() != b.to<uint16_t>());
    case primitiveType::int32_  : return primitive(a.to<int32_t>()  != b.to<int32_t>());
    case primitiveType::uint32_ : return primitive(a.to<uint32_t>() != b.to<uint32_t>());
    case primitiveType::int64_  : return primitive(a.to<int64_t>()  != b.to<int64_t>());
    case primitiveType::uint64_ : return primitive(a.to<uint64_t>() != b.to<uint64_t>());
    case primitiveType::float_  : return primitive(a.to<float>()    != b.to<float>());
    case primitiveType::double_ : return primitive(a.to<double>()   != b.to<double>());
    default: ;
    }
    return primitive();
  }

  inline primitive greaterThanEq(const primitive &a, const primitive &b) {
    const int retType = (a.type > b.type) ? a.type : b.type;
    switch(retType) {
    case primitiveType::bool_   : return primitive(a.to<bool>()     >= b.to<bool>());
    case primitiveType::int8_   : return primitive(a.to<int8_t>()   >= b.to<int8_t>());
    case primitiveType::uint8_  : return primitive(a.to<uint8_t>()  >= b.to<uint8_t>());
    case primitiveType::int16_  : return primitive(a.to<int16_t>()  >= b.to<int16_t>());
    case primitiveType::uint16_ : return primitive(a.to<uint16_t>() >= b.to<uint16_t>());
    case primitiveType::int32_  : return primitive(a.to<int32_t>()  >= b.to<int32_t>());
    case primitiveType::uint32_ : return primitive(a.to<uint32_t>() >= b.to<uint32_t>());
    case primitiveType::int64_  : return primitive(a.to<int64_t>()  >= b.to<int64_t>());
    case primitiveType::uint64_ : return primitive(a.to<uint64_t>() >= b.to<uint64_t>());
    case primitiveType::float_  : return primitive(a.to<float>()    >= b.to<float>());
    case primitiveType::double_ : return primitive(a.to<double>()   >= b.to<double>());
    default: ;
    }
    return primitive();
  }

  inline primitive greaterThan(const primitive &a, const primitive &b) {
    const int retType = (a.type > b.type) ? a.type : b.type;
    switch(retType) {
    case primitiveType::bool_   : return primitive(a.to<bool>()     > b.to<bool>());
    case primitiveType::int8_   : return primitive(a.to<int8_t>()   > b.to<int8_t>());
    case primitiveType::uint8_  : return primitive(a.to<uint8_t>()  > b.to<uint8_t>());
    case primitiveType::int16_  : return primitive(a.to<int16_t>()  > b.to<int16_t>());
    case primitiveType::uint16_ : return primitive(a.to<uint16_t>() > b.to<uint16_t>());
    case primitiveType::int32_  : return primitive(a.to<int32_t>()  > b.to<int32_t>());
    case primitiveType::uint32_ : return primitive(a.to<uint32_t>() > b.to<uint32_t>());
    case primitiveType::int64_  : return primitive(a.to<int64_t>()  > b.to<int64_t>());
    case primitiveType::uint64_ : return primitive(a.to<uint64_t>() > b.to<uint64_t>());
    case primitiveType::float_  : return primitive(a.to<float>()    > b.to<float>());
    case primitiveType::double_ : return primitive(a.to<double>()   > b.to<double>());
    default: ;
    }
    return primitive();
  }

  inline primitive and_(const primitive &a, const primitive &b) {
    const int retType = (a.type > b.type) ? a.type : b.type;
    switch(retType) {
    case primitiveType::bool_   : return primitive(a.to<bool>()     && b.to<bool>());
    case primitiveType::int8_   : return primitive(a.to<int8_t>()   && b.to<int8_t>());
    case primitiveType::uint8_  : return primitive(a.to<uint8_t>()  && b.to<uint8_t>());
    case primitiveType::int16_  : return primitive(a.to<int16_t>()  && b.to<int16_t>());
    case primitiveType::uint16_ : return primitive(a.to<uint16_t>() && b.to<uint16_t>());
    case primitiveType::int32_  : return primitive(a.to<int32_t>()  && b.to<int32_t>());
    case primitiveType::uint32_ : return primitive(a.to<uint32_t>() && b.to<uint32_t>());
    case primitiveType::int64_  : return primitive(a.to<int64_t>()  && b.to<int64_t>());
    case primitiveType::uint64_ : return primitive(a.to<uint64_t>() && b.to<uint64_t>());
    case primitiveType::float_  : return primitive(a.to<float>()    && b.to<float>());
    case primitiveType::double_ : return primitive(a.to<double>()   && b.to<double>());
    default: ;
    }
    return primitive();
  }

  inline primitive or_(const primitive &a, const primitive &b) {
    const int retType = (a.type > b.type) ? a.type : b.type;
    switch(retType) {
    case primitiveType::bool_   : return primitive(a.to<bool>()     || b.to<bool>());
    case primitiveType::int8_   : return primitive(a.to<int8_t>()   || b.to<int8_t>());
    case primitiveType::uint8_  : return primitive(a.to<uint8_t>()  || b.to<uint8_t>());
    case primitiveType::int16_  : return primitive(a.to<int16_t>()  || b.to<int16_t>());
    case primitiveType::uint16_ : return primitive(a.to<uint16_t>() || b.to<uint16_t>());
    case primitiveType::int32_  : return primitive(a.to<int32_t>()  || b.to<int32_t>());
    case primitiveType::uint32_ : return primitive(a.to<uint32_t>() || b.to<uint32_t>());
    case primitiveType::int64_  : return primitive(a.to<int64_t>()  || b.to<int64_t>());
    case primitiveType::uint64_ : return primitive(a.to<uint64_t>() || b.to<uint64_t>());
    case primitiveType::float_  : return primitive(a.to<float>()    || b.to<float>());
    case primitiveType::double_ : return primitive(a.to<double>()   || b.to<double>());
    default: ;
    }
    return primitive();
  }
  //====================================


  //---[ Binary Operators ]-------------
  inline primitive mult(const primitive &a, const primitive &b) {
    const int retType = (a.type > b.type) ? a.type : b.type;
    switch(retType) {
    case primitiveType::bool_   : return primitive(a.to<bool>()     * b.to<bool>());
    case primitiveType::int8_   : return primitive(a.to<int8_t>()   * b.to<int8_t>());
    case primitiveType::uint8_  : return primitive(a.to<uint8_t>()  * b.to<uint8_t>());
    case primitiveType::int16_  : return primitive(a.to<int16_t>()  * b.to<int16_t>());
    case primitiveType::uint16_ : return primitive(a.to<uint16_t>() * b.to<uint16_t>());
    case primitiveType::int32_  : return primitive(a.to<int32_t>()  * b.to<int32_t>());
    case primitiveType::uint32_ : return primitive(a.to<uint32_t>() * b.to<uint32_t>());
    case primitiveType::int64_  : return primitive(a.to<int64_t>()  * b.to<int64_t>());
    case primitiveType::uint64_ : return primitive(a.to<uint64_t>() * b.to<uint64_t>());
    case primitiveType::float_  : return primitive(a.to<float>()    * b.to<float>());
    case primitiveType::double_ : return primitive(a.to<double>()   * b.to<double>());
    default: ;
    }
    return primitive();
  }

  inline primitive add(const primitive &a, const primitive &b) {
    const int retType = (a.type > b.type) ? a.type : b.type;
    switch(retType) {
    case primitiveType::bool_   : return primitive(a.to<bool>()     + b.to<bool>());
    case primitiveType::int8_   : return primitive(a.to<int8_t>()   + b.to<int8_t>());
    case primitiveType::uint8_  : return primitive(a.to<uint8_t>()  + b.to<uint8_t>());
    case primitiveType::int16_  : return primitive(a.to<int16_t>()  + b.to<int16_t>());
    case primitiveType::uint16_ : return primitive(a.to<uint16_t>() + b.to<uint16_t>());
    case primitiveType::int32_  : return primitive(a.to<int32_t>()  + b.to<int32_t>());
    case primitiveType::uint32_ : return primitive(a.to<uint32_t>() + b.to<uint32_t>());
    case primitiveType::int64_  : return primitive(a.to<int64_t>()  + b.to<int64_t>());
    case primitiveType::uint64_ : return primitive(a.to<uint64_t>() + b.to<uint64_t>());
    case primitiveType::float_  : return primitive(a.to<float>()    + b.to<float>());
    case primitiveType::double_ : return primitive(a.to<double>()   + b.to<double>());
    default: ;
    }
    return primitive();
  }

  inline primitive sub(const primitive &a, const primitive &b) {
    const int retType = (a.type > b.type) ? a.type : b.type;
    switch(retType) {
    case primitiveType::bool_   : return primitive(a.to<bool>()     - b.to<bool>());
    case primitiveType::int8_   : return primitive(a.to<int8_t>()   - b.to<int8_t>());
    case primitiveType::uint8_  : return primitive(a.to<uint8_t>()  - b.to<uint8_t>());
    case primitiveType::int16_  : return primitive(a.to<int16_t>()  - b.to<int16_t>());
    case primitiveType::uint16_ : return primitive(a.to<uint16_t>() - b.to<uint16_t>());
    case primitiveType::int32_  : return primitive(a.to<int32_t>()  - b.to<int32_t>());
    case primitiveType::uint32_ : return primitive(a.to<uint32_t>() - b.to<uint32_t>());
    case primitiveType::int64_  : return primitive(a.to<int64_t>()  - b.to<int64_t>());
    case primitiveType::uint64_ : return primitive(a.to<uint64_t>() - b.to<uint64_t>());
    case primitiveType::float_  : return primitive(a.to<float>()    - b.to<float>());
    case primitiveType::double_ : return primitive(a.to<double>()   - b.to<double>());
    default: ;
    }
    return primitive();
  }

  inline primitive div(const primitive &a, const primitive &b) {
    const int retType = (a.type > b.type) ? a.type : b.type;
    switch(retType) {
    case primitiveType::bool_   : return primitive(a.to<bool>()     / b.to<bool>());
    case primitiveType::int8_   : return primitive(a.to<int8_t>()   / b.to<int8_t>());
    case primitiveType::uint8_  : return primitive(a.to<uint8_t>()  / b.to<uint8_t>());
    case primitiveType::int16_  : return primitive(a.to<int16_t>()  / b.to<int16_t>());
    case primitiveType::uint16_ : return primitive(a.to<uint16_t>() / b.to<uint16_t>());
    case primitiveType::int32_  : return primitive(a.to<int32_t>()  / b.to<int32_t>());
    case primitiveType::uint32_ : return primitive(a.to<uint32_t>() / b.to<uint32_t>());
    case primitiveType::int64_  : return primitive(a.to<int64_t>()  / b.to<int64_t>());
    case primitiveType::uint64_ : return primitive(a.to<uint64_t>() / b.to<uint64_t>());
    case primitiveType::float_  : return primitive(a.to<float>()    / b.to<float>());
    case primitiveType::double_ : return primitive(a.to<double>()   / b.to<double>());
    default: ;
    }
    return primitive();
  }

  inline primitive mod(const primitive &a, const primitive &b) {
    const int retType = (a.type > b.type) ? a.type : b.type;
    switch(retType) {
    case primitiveType::bool_   : return primitive(a.to<bool>()     % b.to<bool>());
    case primitiveType::int8_   : return primitive(a.to<int8_t>()   % b.to<int8_t>());
    case primitiveType::uint8_  : return primitive(a.to<uint8_t>()  % b.to<uint8_t>());
    case primitiveType::int16_  : return primitive(a.to<int16_t>()  % b.to<int16_t>());
    case primitiveType::uint16_ : return primitive(a.to<uint16_t>() % b.to<uint16_t>());
    case primitiveType::int32_  : return primitive(a.to<int32_t>()  % b.to<int32_t>());
    case primitiveType::uint32_ : return primitive(a.to<uint32_t>() % b.to<uint32_t>());
    case primitiveType::int64_  : return primitive(a.to<int64_t>()  % b.to<int64_t>());
    case primitiveType::uint64_ : return primitive(a.to<uint64_t>() % b.to<uint64_t>());
    case primitiveType::float_  : OCCA_FORCE_ERROR("Cannot apply operator % to float type"); break;
    case primitiveType::double_ : OCCA_FORCE_ERROR("Cannot apply operator % to double type"); break;
    default: ;
    }
    return primitive();
  }

  inline primitive bitAnd(const primitive &a, const primitive &b) {
    const int retType = (a.type > b.type) ? a.type : b.type;
    switch(retType) {
    case primitiveType::bool_   : return primitive(a.to<bool>()     & b.to<bool>());
    case primitiveType::int8_   : return primitive(a.to<int8_t>()   & b.to<int8_t>());
    case primitiveType::uint8_  : return primitive(a.to<uint8_t>()  & b.to<uint8_t>());
    case primitiveType::int16_  : return primitive(a.to<int16_t>()  & b.to<int16_t>());
    case primitiveType::uint16_ : return primitive(a.to<uint16_t>() & b.to<uint16_t>());
    case primitiveType::int32_  : return primitive(a.to<int32_t>()  & b.to<int32_t>());
    case primitiveType::uint32_ : return primitive(a.to<uint32_t>() & b.to<uint32_t>());
    case primitiveType::int64_  : return primitive(a.to<int64_t>()  & b.to<int64_t>());
    case primitiveType::uint64_ : return primitive(a.to<uint64_t>() & b.to<uint64_t>());
    case primitiveType::float_  : OCCA_FORCE_ERROR("Cannot apply operator & to float type");   break;
    case primitiveType::double_ : OCCA_FORCE_ERROR("Cannot apply operator & to double type");  break;
    default: ;
    }
    return primitive();
  }

  inline primitive bitOr(const primitive &a, const primitive &b) {
    const int retType = (a.type > b.type) ? a.type : b.type;
    switch(retType) {
    case primitiveType::bool_   : return primitive(a.to<bool>()     | b.to<bool>());
    case primitiveType::int8_   : return primitive(a.to<int8_t>()   | b.to<int8_t>());
    case primitiveType::uint8_  : return primitive(a.to<uint8_t>()  | b.to<uint8_t>());
    case primitiveType::int16_  : return primitive(a.to<int16_t>()  | b.to<int16_t>());
    case primitiveType::uint16_ : return primitive(a.to<uint16_t>() | b.to<uint16_t>());
    case primitiveType::int32_  : return primitive(a.to<int32_t>()  | b.to<int32_t>());
    case primitiveType::uint32_ : return primitive(a.to<uint32_t>() | b.to<uint32_t>());
    case primitiveType::int64_  : return primitive(a.to<int64_t>()  | b.to<int64_t>());
    case primitiveType::uint64_ : return primitive(a.to<uint64_t>() | b.to<uint64_t>());
    case primitiveType::float_  : OCCA_FORCE_ERROR("Cannot apply operator | to float type");   break;
    case primitiveType::double_ : OCCA_FORCE_ERROR("Cannot apply operator | to double type");  break;
    default: ;
    }
    return primitive();
  }

  inline primitive xor_(const primitive &a, const primitive &b) {
    const int retType = (a.type > b.type) ? a.type : b.type;
    switch(retType) {
    case primitiveType::bool_   : return primitive(a.to<bool>()     ^ b.to<bool>());
    case primitiveType::int8_   : return primitive(a.to<int8_t>()   ^ b.to<int8_t>());
    case primitiveType::uint8_  : return primitive(a.to<uint8_t>()  ^ b.to<uint8_t>());
    case primitiveType::int16_  : return primitive(a.to<int16_t>()  ^ b.to<int16_t>());
    case primitiveType::uint16_ : return primitive(a.to<uint16_t>() ^ b.to<uint16_t>());
    case primitiveType::int32_  : return primitive(a.to<int32_t>()  ^ b.to<int32_t>());
    case primitiveType::uint32_ : return primitive(a.to<uint32_t>() ^ b.to<uint32_t>());
    case primitiveType::int64_  : return primitive(a.to<int64_t>()  ^ b.to<int64_t>());
    case primitiveType::uint64_ : return primitive(a.to<uint64_t>() ^ b.to<uint64_t>());
    case primitiveType::float_  : OCCA_FORCE_ERROR("Cannot apply operator ^ to float type");   break;
    case primitiveType::double_ : OCCA_FORCE_ERROR("Cannot apply operator ^ to double type");  break;
    default: ;
    }
    return primitive();
  }

  inline primitive rightShift(const primitive &a, const primitive &b) {
    const int retType = (a.type > b.type) ? a.type : b.type;
    switch(retType) {
    case primitiveType::bool_   : return primitive(a.to<bool>()     >> b.to<bool>());
    case primitiveType::int8_   : return primitive(a.to<int8_t>()   >> b.to<int8_t>());
    case primitiveType::uint8_  : return primitive(a.to<uint8_t>()  >> b.to<uint8_t>());
    case primitiveType::int16_  : return primitive(a.to<int16_t>()  >> b.to<int16_t>());
    case primitiveType::uint16_ : return primitive(a.to<uint16_t>() >> b.to<uint16_t>());
    case primitiveType::int32_  : return primitive(a.to<int32_t>()  >> b.to<int32_t>());
    case primitiveType::uint32_ : return primitive(a.to<uint32_t>() >> b.to<uint32_t>());
    case primitiveType::int64_  : return primitive(a.to<int64_t>()  >> b.to<int64_t>());
    case primitiveType::uint64_ : return primitive(a.to<uint64_t>() >> b.to<uint64_t>());
    case primitiveType::float_  : OCCA_FORCE_ERROR("Cannot apply operator >> to float type");   break;
    case primitiveType::double_ : OCCA_FORCE_ERROR("Cannot apply operator >> to double type");  break;
    default: ;
    }
    return primitive();
  }

  inline primitive leftShift(const primitive &a, const primitive &b) {
    const int retType = (a.type > b.type) ? a.type : b.type;
    switch(retType) {
    case primitiveType::bool_   : return primitive(a.to<bool>()     << b.to<bool>());
    case primitiveType::int8_   : return primitive(a.to<int8_t>()   << b.to<int8_t>());
    case primitiveType::uint8_  : return primitive(a.to<uint8_t>()  << b.to<uint8_t>());
    case primitiveType::int16_  : return primitive(a.to<int16_t>()  << b.to<int16_t>());
    case primitiveType::uint16_ : return primitive(a.to<uint16_t>() << b.to<uint16_t>());
    case primitiveType::int32_  : return primitive(a.to<int32_t>()  << b.to<int32_t>());
    case primitiveType::uint32_ : return primitive(a.to<uint32_t>() << b.to<uint32_t>());
    case primitiveType::int64_  : return primitive(a.to<int64_t>()  << b.to<int64_t>());
    case primitiveType::uint64_ : return primitive(a.to<uint64_t>() << b.to<uint64_t>());
    case primitiveType::float_  : OCCA_FORCE_ERROR("Cannot apply operator << to float type");   break;
    case primitiveType::double_ : OCCA_FORCE_ERROR("Cannot apply operator << to double type");  break;
    default: ;
    }
    return primitive();
  }
  //====================================


  //---[ Assignment Operators ]---------
  inline primitive& assign(primitive &a, const primitive &b) {
    a = b;
    return a;
  }

  inline primitive& multEq(primitive &a, const primitive &b) {
    const int retType = (a.type > b.type) ? a.type : b.type;
    switch(retType) {
    case primitiveType::bool_   : a = (a.to<bool>()     * b.to<bool>());     break;
    case primitiveType::int8_   : a = (a.to<int8_t>()   * b.to<int8_t>());   break;
    case primitiveType::uint8_  : a = (a.to<uint8_t>()  * b.to<uint8_t>());  break;
    case primitiveType::int16_  : a = (a.to<int16_t>()  * b.to<int16_t>());  break;
    case primitiveType::uint16_ : a = (a.to<uint16_t>() * b.to<uint16_t>()); break;
    case primitiveType::int32_  : a = (a.to<int32_t>()  * b.to<int32_t>());  break;
    case primitiveType::uint32_ : a = (a.to<uint32_t>() * b.to<uint32_t>()); break;
    case primitiveType::int64_  : a = (a.to<int64_t>()  * b.to<int64_t>());  break;
    case primitiveType::uint64_ : a = (a.to<uint64_t>() * b.to<uint64_t>()); break;
    case primitiveType::float_  : a = (a.to<float>()    * b.to<float>());    break;
    case primitiveType::double_ : a = (a.to<double>()   * b.to<double>());   break;
    default: ;
    }
    return a;
  }

  inline primitive& addEq(primitive &a, const primitive &b) {
    const int retType = (a.type > b.type) ? a.type : b.type;
    switch(retType) {
    case primitiveType::bool_   : a = (a.to<bool>()     + b.to<bool>());     break;
    case primitiveType::int8_   : a = (a.to<int8_t>()   + b.to<int8_t>());   break;
    case primitiveType::uint8_  : a = (a.to<uint8_t>()  + b.to<uint8_t>());  break;
    case primitiveType::int16_  : a = (a.to<int16_t>()  + b.to<int16_t>());  break;
    case primitiveType::uint16_ : a = (a.to<uint16_t>() + b.to<uint16_t>()); break;
    case primitiveType::int32_  : a = (a.to<int32_t>()  + b.to<int32_t>());  break;
    case primitiveType::uint32_ : a = (a.to<uint32_t>() + b.to<uint32_t>()); break;
    case primitiveType::int64_  : a = (a.to<int64_t>()  + b.to<int64_t>());  break;
    case primitiveType::uint64_ : a = (a.to<uint64_t>() + b.to<uint64_t>()); break;
    case primitiveType::float_  : a = (a.to<float>()    + b.to<float>());    break;
    case primitiveType::double_ : a = (a.to<double>()   + b.to<double>());   break;
    default: ;
    }
    return a;
  }

  inline primitive& subEq(primitive &a, const primitive &b) {
    const int retType = (a.type > b.type) ? a.type : b.type;
    switch(retType) {
    case primitiveType::bool_   : a = (a.to<bool>()     - b.to<bool>());     break;
    case primitiveType::int8_   : a = (a.to<int8_t>()   - b.to<int8_t>());   break;
    case primitiveType::uint8_  : a = (a.to<uint8_t>()  - b.to<uint8_t>());  break;
    case primitiveType::int16_  : a = (a.to<int16_t>()  - b.to<int16_t>());  break;
    case primitiveType::uint16_ : a = (a.to<uint16_t>() - b.to<uint16_t>()); break;
    case primitiveType::int32_  : a = (a.to<int32_t>()  - b.to<int32_t>());  break;
    case primitiveType::uint32_ : a = (a.to<uint32_t>() - b.to<uint32_t>()); break;
    case primitiveType::int64_  : a = (a.to<int64_t>()  - b.to<int64_t>());  break;
    case primitiveType::uint64_ : a = (a.to<uint64_t>() - b.to<uint64_t>()); break;
    case primitiveType::float_  : a = (a.to<float>()    - b.to<float>());    break;
    case primitiveType::double_ : a = (a.to<double>()   - b.to<double>());   break;
    default: ;
    }
    return a;
  }

  inline primitive& divEq(primitive &a, const primitive &b) {
    const int retType = (a.type > b.type) ? a.type : b.type;
    switch(retType) {
    case primitiveType::bool_   : a = (a.to<bool>()     / b.to<bool>());     break;
    case primitiveType::int8_   : a = (a.to<int8_t>()   / b.to<int8_t>());   break;
    case primitiveType::uint8_  : a = (a.to<uint8_t>()  / b.to<uint8_t>());  break;
    case primitiveType::int16_  : a = (a.to<int16_t>()  / b.to<int16_t>());  break;
    case primitiveType::uint16_ : a = (a.to<uint16_t>() / b.to<uint16_t>()); break;
    case primitiveType::int32_  : a = (a.to<int32_t>()  / b.to<int32_t>());  break;
    case primitiveType::uint32_ : a = (a.to<uint32_t>() / b.to<uint32_t>()); break;
    case primitiveType::int64_  : a = (a.to<int64_t>()  / b.to<int64_t>());  break;
    case primitiveType::uint64_ : a = (a.to<uint64_t>() / b.to<uint64_t>()); break;
    case primitiveType::float_  : a = (a.to<float>()    / b.to<float>());    break;
    case primitiveType::double_ : a = (a.to<double>()   / b.to<double>());   break;
    default: ;
    }
    return a;
  }

  inline primitive& modEq(primitive &a, const primitive &b) {
    const int retType = (a.type > b.type) ? a.type : b.type;
    switch(retType) {
    case primitiveType::bool_   : a = (a.to<bool>()     % b.to<bool>());     break;
    case primitiveType::int8_   : a = (a.to<int8_t>()   % b.to<int8_t>());   break;
    case primitiveType::uint8_  : a = (a.to<uint8_t>()  % b.to<uint8_t>());  break;
    case primitiveType::int16_  : a = (a.to<int16_t>()  % b.to<int16_t>());  break;
    case primitiveType::uint16_ : a = (a.to<uint16_t>() % b.to<uint16_t>()); break;
    case primitiveType::int32_  : a = (a.to<int32_t>()  % b.to<int32_t>());  break;
    case primitiveType::uint32_ : a = (a.to<uint32_t>() % b.to<uint32_t>()); break;
    case primitiveType::int64_  : a = (a.to<int64_t>()  % b.to<int64_t>());  break;
    case primitiveType::uint64_ : a = (a.to<uint64_t>() % b.to<uint64_t>()); break;
    case primitiveType::float_  : OCCA_FORCE_ERROR("Cannot apply operator % to float type"); break;
    case primitiveType::double_ : OCCA_FORCE_ERROR("Cannot apply operator % to double type"); break;
    default: ;
    }
    return a;
  }

  inline primitive& bitAndEq(primitive &a, const primitive &b) {
    const int retType = (a.type > b.type) ? a.type : b.type;
    switch(retType) {
    case primitiveType::bool_   : a = (a.to<bool>()     & b.to<bool>());     break;
    case primitiveType::int8_   : a = (a.to<int8_t>()   & b.to<int8_t>());   break;
    case primitiveType::uint8_  : a = (a.to<uint8_t>()  & b.to<uint8_t>());  break;
    case primitiveType::int16_  : a = (a.to<int16_t>()  & b.to<int16_t>());  break;
    case primitiveType::uint16_ : a = (a.to<uint16_t>() & b.to<uint16_t>()); break;
    case primitiveType::int32_  : a = (a.to<int32_t>()  & b.to<int32_t>());  break;
    case primitiveType::uint32_ : a = (a.to<uint32_t>() & b.to<uint32_t>()); break;
    case primitiveType::int64_  : a = (a.to<int64_t>()  & b.to<int64_t>());  break;
    case primitiveType::uint64_ : a = (a.to<uint64_t>() & b.to<uint64_t>()); break;
    case primitiveType::float_  : OCCA_FORCE_ERROR("Cannot apply operator & to float type");  break;
    case primitiveType::double_ : OCCA_FORCE_ERROR("Cannot apply operator & to double type"); break;
    default: ;
    }
    return a;
  }

  inline primitive& bitOrEq(primitive &a, const primitive &b) {
    const int retType = (a.type > b.type) ? a.type : b.type;
    switch(retType) {
    case primitiveType::bool_   : a = (a.to<bool>()     | b.to<bool>());     break;
    case primitiveType::int8_   : a = (a.to<int8_t>()   | b.to<int8_t>());   break;
    case primitiveType::uint8_  : a = (a.to<uint8_t>()  | b.to<uint8_t>());  break;
    case primitiveType::int16_  : a = (a.to<int16_t>()  | b.to<int16_t>());  break;
    case primitiveType::uint16_ : a = (a.to<uint16_t>() | b.to<uint16_t>()); break;
    case primitiveType::int32_  : a = (a.to<int32_t>()  | b.to<int32_t>());  break;
    case primitiveType::uint32_ : a = (a.to<uint32_t>() | b.to<uint32_t>()); break;
    case primitiveType::int64_  : a = (a.to<int64_t>()  | b.to<int64_t>());  break;
    case primitiveType::uint64_ : a = (a.to<uint64_t>() | b.to<uint64_t>()); break;
    case primitiveType::float_  : OCCA_FORCE_ERROR("Cannot apply operator | to float type");  break;
    case primitiveType::double_ : OCCA_FORCE_ERROR("Cannot apply operator | to double type"); break;
    default: ;
    }
    return a;
  }

  inline primitive& xorEq(primitive &a, const primitive &b) {
    const int retType = (a.type > b.type) ? a.type : b.type;
    switch(retType) {
    case primitiveType::bool_   : a = (a.to<bool>()     ^ b.to<bool>());     break;
    case primitiveType::int8_   : a = (a.to<int8_t>()   ^ b.to<int8_t>());   break;
    case primitiveType::uint8_  : a = (a.to<uint8_t>()  ^ b.to<uint8_t>());  break;
    case primitiveType::int16_  : a = (a.to<int16_t>()  ^ b.to<int16_t>());  break;
    case primitiveType::uint16_ : a = (a.to<uint16_t>() ^ b.to<uint16_t>()); break;
    case primitiveType::int32_  : a = (a.to<int32_t>()  ^ b.to<int32_t>());  break;
    case primitiveType::uint32_ : a = (a.to<uint32_t>() ^ b.to<uint32_t>()); break;
    case primitiveType::int64_  : a = (a.to<int64_t>()  ^ b.to<int64_t>());  break;
    case primitiveType::uint64_ : a = (a.to<uint64_t>() ^ b.to<uint64_t>()); break;
    case primitiveType::float_  : OCCA_FORCE_ERROR("Cannot apply operator ^ to float type");  break;
    case primitiveType::double_ : OCCA_FORCE_ERROR("Cannot apply operator ^ to double type"); break;
    default: ;
    }
    return a;
  }

  inline primitive& rightShiftEq(primitive &a, const primitive &b) {
    const int retType = (a.type > b.type) ? a.type : b.type;
    switch(retType) {
    case primitiveType::bool_   : a = (a.to<bool>()     >> b.to<bool>());     break;
    case primitiveType::int8_   : a = (a.to<int8_t>()   >> b.to<int8_t>());   break;
    case primitiveType::uint8_  : a = (a.to<uint8_t>()  >> b.to<uint8_t>());  break;
    case primitiveType::int16_  : a = (a.to<int16_t>()  >> b.to<int16_t>());  break;
    case primitiveType::uint16_ : a = (a.to<uint16_t>() >> b.to<uint16_t>()); break;
    case primitiveType::int32_  : a = (a.to<int32_t>()  >> b.to<int32_t>());  break;
    case primitiveType::uint32_ : a = (a.to<uint32_t>() >> b.to<uint32_t>()); break;
    case primitiveType::int64_  : a = (a.to<int64_t>()  >> b.to<int64_t>());  break;
    case primitiveType::uint64_ : a = (a.to<uint64_t>() >> b.to<uint64_t>()); break;
    case primitiveType::float_  : OCCA_FORCE_ERROR("Cannot apply operator >> to float type");  break;
    case primitiveType::double_ : OCCA_FORCE_ERROR("Cannot apply operator >> to double type"); break;
    default: ;
    }
    return a;
  }

  inline primitive& leftShiftEq(primitive &a, const primitive &b) {
    const int retType = (a.type > b.type) ? a.type : b.type;
    switch(retType) {
    case primitiveType::bool_   : a = (a.to<bool>()     << b.to<bool>());     break;
    case primitiveType::int8_   : a = (a.to<int8_t>()   << b.to<int8_t>());   break;
    case primitiveType::uint8_  : a = (a.to<uint8_t>()  << b.to<uint8_t>());  break;
    case primitiveType::int16_  : a = (a.to<int16_t>()  << b.to<int16_t>());  break;
    case primitiveType::uint16_ : a = (a.to<uint16_t>() << b.to<uint16_t>()); break;
    case primitiveType::int32_  : a = (a.to<int32_t>()  << b.to<int32_t>());  break;
    case primitiveType::uint32_ : a = (a.to<uint32_t>() << b.to<uint32_t>()); break;
    case primitiveType::int64_  : a = (a.to<int64_t>()  << b.to<int64_t>());  break;
    case primitiveType::uint64_ : a = (a.to<uint64_t>() << b.to<uint64_t>()); break;
    case primitiveType::float_  : OCCA_FORCE_ERROR("Cannot apply operator << to float type");  break;
    case primitiveType::double_ : OCCA_FORCE_ERROR("Cannot apply operator << to double type"); break;
    default: ;
    }
    return a;
  }
  //====================================
}
#endif
