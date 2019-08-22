/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_XY.hxx>
#include <gp_XYZ.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <Standard_RangeError.hxx>
#include <Standard_OStream.hxx>
#include <math_SingleTab.hxx>

void bind_math_Vector(py::module &mod){

py::class_<math_Vector> cls_math_Vector(mod, "math_Vector", "This class implements the real vector abstract data type. Vectors can have an arbitrary range which must be defined at the declaration and cannot be changed after this declaration.");

// Constructors
cls_math_Vector.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_math_Vector.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theInitialValue"));
cls_math_Vector.def(py::init<const Standard_Address, const Standard_Integer, const Standard_Integer>(), py::arg("theTab"), py::arg("theLower"), py::arg("theUpper"));
cls_math_Vector.def(py::init<const gp_XY &>(), py::arg("Other"));
cls_math_Vector.def(py::init<const gp_XYZ &>(), py::arg("Other"));
cls_math_Vector.def(py::init<const math_Vector &>(), py::arg("theOther"));

// Fields

// Methods
// cls_math_Vector.def_static("operator new_", (void * (*)(size_t)) &math_Vector::operator new, "None", py::arg("theSize"));
// cls_math_Vector.def_static("operator delete_", (void (*)(void *)) &math_Vector::operator delete, "None", py::arg("theAddress"));
// cls_math_Vector.def_static("operator new[]_", (void * (*)(size_t)) &math_Vector::operator new[], "None", py::arg("theSize"));
// cls_math_Vector.def_static("operator delete[]_", (void (*)(void *)) &math_Vector::operator delete[], "None", py::arg("theAddress"));
// cls_math_Vector.def_static("operator new_", (void * (*)(size_t, void *)) &math_Vector::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_Vector.def_static("operator delete_", (void (*)(void *, void *)) &math_Vector::operator delete, "None", py::arg(""), py::arg(""));
cls_math_Vector.def("Init", (void (math_Vector::*)(const Standard_Real)) &math_Vector::Init, "Initialize all the elements of a vector with 'theInitialValue'.", py::arg("theInitialValue"));
cls_math_Vector.def("Length", (Standard_Integer (math_Vector::*)() const) &math_Vector::Length, "Returns the length of a vector");
cls_math_Vector.def("Lower", (Standard_Integer (math_Vector::*)() const) &math_Vector::Lower, "Returns the value of the theLower index of a vector.");
cls_math_Vector.def("Upper", (Standard_Integer (math_Vector::*)() const) &math_Vector::Upper, "Returns the value of the theUpper index of a vector.");
cls_math_Vector.def("Norm", (Standard_Real (math_Vector::*)() const) &math_Vector::Norm, "Returns the value or the square of the norm of this vector.");
cls_math_Vector.def("Norm2", (Standard_Real (math_Vector::*)() const) &math_Vector::Norm2, "Returns the value of the square of the norm of a vector.");
cls_math_Vector.def("Max", (Standard_Integer (math_Vector::*)() const) &math_Vector::Max, "Returns the value of the 'Index' of the maximum element of a vector.");
cls_math_Vector.def("Min", (Standard_Integer (math_Vector::*)() const) &math_Vector::Min, "Returns the value of the 'Index' of the minimum element of a vector.");
cls_math_Vector.def("Normalize", (void (math_Vector::*)()) &math_Vector::Normalize, "Normalizes this vector (the norm of the result is equal to 1.0) and assigns the result to this vector Exceptions Standard_NullValue if this vector is null (i.e. if its norm is less than or equal to Standard_Real::RealEpsilon().");
cls_math_Vector.def("Normalized", (math_Vector (math_Vector::*)() const) &math_Vector::Normalized, "Normalizes this vector (the norm of the result is equal to 1.0) and creates a new vector Exceptions Standard_NullValue if this vector is null (i.e. if its norm is less than or equal to Standard_Real::RealEpsilon().");
cls_math_Vector.def("Invert", (void (math_Vector::*)()) &math_Vector::Invert, "Inverts this vector and assigns the result to this vector.");
cls_math_Vector.def("Inverse", (math_Vector (math_Vector::*)() const) &math_Vector::Inverse, "Inverts this vector and creates a new vector.");
cls_math_Vector.def("Set", (void (math_Vector::*)(const Standard_Integer, const Standard_Integer, const math_Vector &)) &math_Vector::Set, "sets a vector from 'theI1' to 'theI2' to the vector 'theV'; An exception is raised if 'theI1' is less than 'LowerIndex' or 'theI2' is greater than 'UpperIndex' or 'theI1' is greater than 'theI2'. An exception is raised if 'theI2-theI1+1' is different from the 'Length' of 'theV'.", py::arg("theI1"), py::arg("theI2"), py::arg("theV"));
cls_math_Vector.def("Slice", (math_Vector (math_Vector::*)(const Standard_Integer, const Standard_Integer) const) &math_Vector::Slice, "Creates a new vector by inverting the values of this vector between indexes 'theI1' and 'theI2'. If the values of this vector were (1., 2., 3., 4.,5., 6.), by slicing it between indexes 2 and 5 the values of the resulting vector are (1., 5., 4., 3., 2., 6.)", py::arg("theI1"), py::arg("theI2"));
cls_math_Vector.def("Multiply", (void (math_Vector::*)(const Standard_Real)) &math_Vector::Multiply, "returns the product of a vector and a real value.", py::arg("theRight"));
cls_math_Vector.def("__imul__", (void (math_Vector::*)(const Standard_Real)) &math_Vector::operator*=, py::is_operator(), "None", py::arg("theRight"));
cls_math_Vector.def("Multiplied", (math_Vector (math_Vector::*)(const Standard_Real) const) &math_Vector::Multiplied, "returns the product of a vector and a real value.", py::arg("theRight"));
cls_math_Vector.def("__mul__", (math_Vector (math_Vector::*)(const Standard_Real) const) &math_Vector::operator*, py::is_operator(), "None", py::arg("theRight"));
cls_math_Vector.def("TMultiplied", (math_Vector (math_Vector::*)(const Standard_Real) const) &math_Vector::TMultiplied, "returns the product of a vector and a real value.", py::arg("theRight"));
cls_math_Vector.def("Divide", (void (math_Vector::*)(const Standard_Real)) &math_Vector::Divide, "divides a vector by the value 'theRight'. An exception is raised if 'theRight' = 0.", py::arg("theRight"));
cls_math_Vector.def("__itruediv__", (void (math_Vector::*)(const Standard_Real)) &math_Vector::operator/=, py::is_operator(), "None", py::arg("theRight"));
cls_math_Vector.def("Divided", (math_Vector (math_Vector::*)(const Standard_Real) const) &math_Vector::Divided, "divides a vector by the value 'theRight'. An exception is raised if 'theRight' = 0.", py::arg("theRight"));
cls_math_Vector.def("__truediv__", (math_Vector (math_Vector::*)(const Standard_Real) const) &math_Vector::operator/, py::is_operator(), "None", py::arg("theRight"));
cls_math_Vector.def("Add", (void (math_Vector::*)(const math_Vector &)) &math_Vector::Add, "adds the vector 'theRight' to a vector. An exception is raised if the vectors have not the same length. Warning In order to avoid time-consuming copying of vectors, it is preferable to use operator += or the function Add whenever possible.", py::arg("theRight"));
cls_math_Vector.def("__iadd__", (void (math_Vector::*)(const math_Vector &)) &math_Vector::operator+=, py::is_operator(), "None", py::arg("theRight"));
cls_math_Vector.def("Added", (math_Vector (math_Vector::*)(const math_Vector &) const) &math_Vector::Added, "adds the vector theRight to a vector. An exception is raised if the vectors have not the same length. An exception is raised if the lengths are not equal.", py::arg("theRight"));
cls_math_Vector.def("__add__", (math_Vector (math_Vector::*)(const math_Vector &) const) &math_Vector::operator+, py::is_operator(), "None", py::arg("theRight"));
cls_math_Vector.def("Multiply", (void (math_Vector::*)(const math_Vector &, const math_Matrix &)) &math_Vector::Multiply, "sets a vector to the product of the vector 'theLeft' with the matrix 'theRight'.", py::arg("theLeft"), py::arg("theRight"));
cls_math_Vector.def("Multiply", (void (math_Vector::*)(const math_Matrix &, const math_Vector &)) &math_Vector::Multiply, "sets a vector to the product of the matrix 'theLeft' with the vector 'theRight'.", py::arg("theLeft"), py::arg("theRight"));
cls_math_Vector.def("TMultiply", (void (math_Vector::*)(const math_Matrix &, const math_Vector &)) &math_Vector::TMultiply, "sets a vector to the product of the transpose of the matrix 'theTLeft' by the vector 'theRight'.", py::arg("theTLeft"), py::arg("theRight"));
cls_math_Vector.def("TMultiply", (void (math_Vector::*)(const math_Vector &, const math_Matrix &)) &math_Vector::TMultiply, "sets a vector to the product of the vector 'theLeft' by the transpose of the matrix 'theTRight'.", py::arg("theLeft"), py::arg("theTRight"));
cls_math_Vector.def("Add", (void (math_Vector::*)(const math_Vector &, const math_Vector &)) &math_Vector::Add, "sets a vector to the sum of the vector 'theLeft' and the vector 'theRight'. An exception is raised if the lengths are different.", py::arg("theLeft"), py::arg("theRight"));
cls_math_Vector.def("Subtract", (void (math_Vector::*)(const math_Vector &, const math_Vector &)) &math_Vector::Subtract, "sets a vector to the Subtraction of the vector theRight from the vector theLeft. An exception is raised if the vectors have not the same length. Warning In order to avoid time-consuming copying of vectors, it is preferable to use operator -= or the function Subtract whenever possible.", py::arg("theLeft"), py::arg("theRight"));
cls_math_Vector.def("Value", (Standard_Real & (math_Vector::*)(const Standard_Integer) const) &math_Vector::Value, "accesses (in read or write mode) the value of index 'theNum' of a vector.", py::arg("theNum"));
cls_math_Vector.def("__call__", (Standard_Real & (math_Vector::*)(const Standard_Integer) const) &math_Vector::operator(), py::is_operator(), "None", py::arg("theNum"));
cls_math_Vector.def("Initialized", (math_Vector & (math_Vector::*)(const math_Vector &)) &math_Vector::Initialized, "Initialises a vector by copying 'theOther'. An exception is raised if the Lengths are differents.", py::arg("theOther"));
// cls_math_Vector.def("operator=", (math_Vector & (math_Vector::*)(const math_Vector &)) &math_Vector::operator=, "None", py::arg("theOther"));
cls_math_Vector.def("Multiplied", (Standard_Real (math_Vector::*)(const math_Vector &) const) &math_Vector::Multiplied, "returns the inner product of 2 vectors. An exception is raised if the lengths are not equal.", py::arg("theRight"));
cls_math_Vector.def("__mul__", (Standard_Real (math_Vector::*)(const math_Vector &) const) &math_Vector::operator*, py::is_operator(), "None", py::arg("theRight"));
cls_math_Vector.def("Multiplied", (math_Vector (math_Vector::*)(const math_Matrix &) const) &math_Vector::Multiplied, "returns the product of a vector by a matrix.", py::arg("theRight"));
cls_math_Vector.def("__mul__", (math_Vector (math_Vector::*)(const math_Matrix &) const) &math_Vector::operator*, py::is_operator(), "None", py::arg("theRight"));
cls_math_Vector.def("Opposite", (math_Vector (math_Vector::*)()) &math_Vector::Opposite, "returns the opposite of a vector.");
cls_math_Vector.def("__sub__", (math_Vector (math_Vector::*)()) &math_Vector::operator-, py::is_operator(), "None");
cls_math_Vector.def("Subtract", (void (math_Vector::*)(const math_Vector &)) &math_Vector::Subtract, "returns the subtraction of 'theRight' from 'me'. An exception is raised if the vectors have not the same length.", py::arg("theRight"));
cls_math_Vector.def("__isub__", (void (math_Vector::*)(const math_Vector &)) &math_Vector::operator-=, py::is_operator(), "None", py::arg("theRight"));
cls_math_Vector.def("Subtracted", (math_Vector (math_Vector::*)(const math_Vector &) const) &math_Vector::Subtracted, "returns the subtraction of 'theRight' from 'me'. An exception is raised if the vectors have not the same length.", py::arg("theRight"));
cls_math_Vector.def("__sub__", (math_Vector (math_Vector::*)(const math_Vector &) const) &math_Vector::operator-, py::is_operator(), "None", py::arg("theRight"));
cls_math_Vector.def("Multiply", (void (math_Vector::*)(const Standard_Real, const math_Vector &)) &math_Vector::Multiply, "returns the multiplication of a real by a vector. 'me' = 'theLeft' * 'theRight'", py::arg("theLeft"), py::arg("theRight"));
cls_math_Vector.def("Dump", (void (math_Vector::*)(Standard_OStream &) const) &math_Vector::Dump, "Prints information on the current state of the object. Is used to redefine the operator <<.", py::arg("theO"));

// Enums

}