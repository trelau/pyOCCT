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
#include <math_IntegerVector.hxx>
#include <Standard_RangeError.hxx>
#include <Standard_OStream.hxx>
#include <math_SingleTab.hxx>

void bind_math_IntegerVector(py::module &mod){

py::class_<math_IntegerVector, std::unique_ptr<math_IntegerVector>> cls_math_IntegerVector(mod, "math_IntegerVector", "This class implements the real IntegerVector abstract data type. IntegerVectors can have an arbitrary range which must be define at the declaration and cannot be changed after this declaration. Example:");

// Constructors
cls_math_IntegerVector.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theFirst"), py::arg("theLast"));
cls_math_IntegerVector.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theFirst"), py::arg("theLast"), py::arg("theInitialValue"));
cls_math_IntegerVector.def(py::init<const Standard_Address, const Standard_Integer, const Standard_Integer>(), py::arg("theTab"), py::arg("theFirst"), py::arg("theLast"));
cls_math_IntegerVector.def(py::init<const math_IntegerVector &>(), py::arg("theOther"));

// Fields

// Methods
// cls_math_IntegerVector.def_static("operator new_", (void * (*)(size_t)) &math_IntegerVector::operator new, "None", py::arg("theSize"));
// cls_math_IntegerVector.def_static("operator delete_", (void (*)(void *)) &math_IntegerVector::operator delete, "None", py::arg("theAddress"));
// cls_math_IntegerVector.def_static("operator new[]_", (void * (*)(size_t)) &math_IntegerVector::operator new[], "None", py::arg("theSize"));
// cls_math_IntegerVector.def_static("operator delete[]_", (void (*)(void *)) &math_IntegerVector::operator delete[], "None", py::arg("theAddress"));
// cls_math_IntegerVector.def_static("operator new_", (void * (*)(size_t, void *)) &math_IntegerVector::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_IntegerVector.def_static("operator delete_", (void (*)(void *, void *)) &math_IntegerVector::operator delete, "None", py::arg(""), py::arg(""));
cls_math_IntegerVector.def("Init", (void (math_IntegerVector::*)(const Standard_Integer)) &math_IntegerVector::Init, "Initialize an IntegerVector with all the elements set to theInitialValue.", py::arg("theInitialValue"));
cls_math_IntegerVector.def("Length", (Standard_Integer (math_IntegerVector::*)() const) &math_IntegerVector::Length, "returns the length of an IntegerVector");
cls_math_IntegerVector.def("Lower", (Standard_Integer (math_IntegerVector::*)() const) &math_IntegerVector::Lower, "returns the value of the Lower index of an IntegerVector.");
cls_math_IntegerVector.def("Upper", (Standard_Integer (math_IntegerVector::*)() const) &math_IntegerVector::Upper, "returns the value of the Upper index of an IntegerVector.");
cls_math_IntegerVector.def("Norm", (Standard_Real (math_IntegerVector::*)() const) &math_IntegerVector::Norm, "returns the value of the norm of an IntegerVector.");
cls_math_IntegerVector.def("Norm2", (Standard_Real (math_IntegerVector::*)() const) &math_IntegerVector::Norm2, "returns the value of the square of the norm of an IntegerVector.");
cls_math_IntegerVector.def("Max", (Standard_Integer (math_IntegerVector::*)() const) &math_IntegerVector::Max, "returns the value of the Index of the maximum element of an IntegerVector.");
cls_math_IntegerVector.def("Min", (Standard_Integer (math_IntegerVector::*)() const) &math_IntegerVector::Min, "returns the value of the Index of the minimum element of an IntegerVector.");
cls_math_IntegerVector.def("Invert", (void (math_IntegerVector::*)()) &math_IntegerVector::Invert, "inverses an IntegerVector.");
cls_math_IntegerVector.def("Inverse", (math_IntegerVector (math_IntegerVector::*)() const) &math_IntegerVector::Inverse, "returns the inverse IntegerVector of an IntegerVector.");
cls_math_IntegerVector.def("Set", (void (math_IntegerVector::*)(const Standard_Integer, const Standard_Integer, const math_IntegerVector &)) &math_IntegerVector::Set, "sets an IntegerVector from 'theI1' to 'theI2' to the IntegerVector 'theV'; An exception is raised if 'theI1' is less than 'LowerIndex' or 'theI2' is greater than 'UpperIndex' or 'theI1' is greater than 'theI2'. An exception is raised if 'theI2-theI1+1' is different from the Length of 'theV'.", py::arg("theI1"), py::arg("theI2"), py::arg("theV"));
cls_math_IntegerVector.def("Slice", (math_IntegerVector (math_IntegerVector::*)(const Standard_Integer, const Standard_Integer) const) &math_IntegerVector::Slice, "slices the values of the IntegerVector between 'theI1' and 'theI2': Example: [2, 1, 2, 3, 4, 5] becomes [2, 4, 3, 2, 1, 5] between 2 and 5. An exception is raised if 'theI1' is less than 'LowerIndex' or 'theI2' is greater than 'UpperIndex'.", py::arg("theI1"), py::arg("theI2"));
cls_math_IntegerVector.def("Multiply", (void (math_IntegerVector::*)(const Standard_Integer)) &math_IntegerVector::Multiply, "returns the product of an IntegerVector by an integer value.", py::arg("theRight"));
cls_math_IntegerVector.def("__imul__", (void (math_IntegerVector::*)(const Standard_Integer)) &math_IntegerVector::operator*=, py::is_operator(), "None", py::arg("theRight"));
cls_math_IntegerVector.def("Multiplied", (math_IntegerVector (math_IntegerVector::*)(const Standard_Integer) const) &math_IntegerVector::Multiplied, "returns the product of an IntegerVector by an integer value.", py::arg("theRight"));
cls_math_IntegerVector.def("__mul__", (math_IntegerVector (math_IntegerVector::*)(const Standard_Integer) const) &math_IntegerVector::operator*, py::is_operator(), "None", py::arg("theRight"));
cls_math_IntegerVector.def("TMultiplied", (math_IntegerVector (math_IntegerVector::*)(const Standard_Integer) const) &math_IntegerVector::TMultiplied, "returns the product of a vector and a real value.", py::arg("theRight"));
cls_math_IntegerVector.def("Add", (void (math_IntegerVector::*)(const math_IntegerVector &)) &math_IntegerVector::Add, "adds the IntegerVector 'theRight' to an IntegerVector. An exception is raised if the IntegerVectors have not the same length. An exception is raised if the lengths are not equal.", py::arg("theRight"));
cls_math_IntegerVector.def("__iadd__", (void (math_IntegerVector::*)(const math_IntegerVector &)) &math_IntegerVector::operator+=, py::is_operator(), "None", py::arg("theRight"));
cls_math_IntegerVector.def("Added", (math_IntegerVector (math_IntegerVector::*)(const math_IntegerVector &) const) &math_IntegerVector::Added, "adds the IntegerVector 'theRight' to an IntegerVector. An exception is raised if the IntegerVectors have not the same length. An exception is raised if the lengths are not equal.", py::arg("theRight"));
cls_math_IntegerVector.def("__add__", (math_IntegerVector (math_IntegerVector::*)(const math_IntegerVector &) const) &math_IntegerVector::operator+, py::is_operator(), "None", py::arg("theRight"));
cls_math_IntegerVector.def("Add", (void (math_IntegerVector::*)(const math_IntegerVector &, const math_IntegerVector &)) &math_IntegerVector::Add, "sets an IntegerVector to the sum of the IntegerVector 'theLeft' and the IntegerVector 'theRight'. An exception is raised if the lengths are different.", py::arg("theLeft"), py::arg("theRight"));
cls_math_IntegerVector.def("Subtract", (void (math_IntegerVector::*)(const math_IntegerVector &, const math_IntegerVector &)) &math_IntegerVector::Subtract, "sets an IntegerVector to the substraction of 'theRight' from 'theLeft'. An exception is raised if the IntegerVectors have not the same length.", py::arg("theLeft"), py::arg("theRight"));
cls_math_IntegerVector.def("Value", (Standard_Integer & (math_IntegerVector::*)(const Standard_Integer) const) &math_IntegerVector::Value, "accesses (in read or write mode) the value of index theNum of an IntegerVector.", py::arg("theNum"));
cls_math_IntegerVector.def("__call__", (Standard_Integer & (math_IntegerVector::*)(const Standard_Integer) const) &math_IntegerVector::operator(), py::is_operator(), "None", py::arg("theNum"));
cls_math_IntegerVector.def("Initialized", (math_IntegerVector & (math_IntegerVector::*)(const math_IntegerVector &)) &math_IntegerVector::Initialized, "Initialises an IntegerVector by copying 'theOther'. An exception is raised if the Lengths are different.", py::arg("theOther"));
// cls_math_IntegerVector.def("operator=", (math_IntegerVector & (math_IntegerVector::*)(const math_IntegerVector &)) &math_IntegerVector::operator=, "None", py::arg("theOther"));
cls_math_IntegerVector.def("Multiplied", (Standard_Integer (math_IntegerVector::*)(const math_IntegerVector &) const) &math_IntegerVector::Multiplied, "returns the inner product of 2 IntegerVectors. An exception is raised if the lengths are not equal.", py::arg("theRight"));
cls_math_IntegerVector.def("__mul__", (Standard_Integer (math_IntegerVector::*)(const math_IntegerVector &) const) &math_IntegerVector::operator*, py::is_operator(), "None", py::arg("theRight"));
cls_math_IntegerVector.def("Opposite", (math_IntegerVector (math_IntegerVector::*)()) &math_IntegerVector::Opposite, "returns the opposite of an IntegerVector.");
cls_math_IntegerVector.def("__sub__", (math_IntegerVector (math_IntegerVector::*)()) &math_IntegerVector::operator-, py::is_operator(), "None");
cls_math_IntegerVector.def("Subtract", (void (math_IntegerVector::*)(const math_IntegerVector &)) &math_IntegerVector::Subtract, "returns the subtraction of 'theRight' from 'me'. An exception is raised if the IntegerVectors have not the same length.", py::arg("theRight"));
cls_math_IntegerVector.def("__isub__", (void (math_IntegerVector::*)(const math_IntegerVector &)) &math_IntegerVector::operator-=, py::is_operator(), "None", py::arg("theRight"));
cls_math_IntegerVector.def("Subtracted", (math_IntegerVector (math_IntegerVector::*)(const math_IntegerVector &) const) &math_IntegerVector::Subtracted, "returns the subtraction of 'theRight' from 'me'. An exception is raised if the IntegerVectors have not the same length.", py::arg("theRight"));
cls_math_IntegerVector.def("__sub__", (math_IntegerVector (math_IntegerVector::*)(const math_IntegerVector &) const) &math_IntegerVector::operator-, py::is_operator(), "None", py::arg("theRight"));
cls_math_IntegerVector.def("Multiply", (void (math_IntegerVector::*)(const Standard_Integer, const math_IntegerVector &)) &math_IntegerVector::Multiply, "returns the multiplication of an integer by an IntegerVector.", py::arg("theLeft"), py::arg("theRight"));
cls_math_IntegerVector.def("Dump", (void (math_IntegerVector::*)(Standard_OStream &) const) &math_IntegerVector::Dump, "Prints on the stream theO information on the current state of the object. Is used to redefine the operator <<.", py::arg("theO"));

// Enums

}