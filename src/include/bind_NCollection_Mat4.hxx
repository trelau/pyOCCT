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
#ifndef __NCollection_Mat4__
#define __NCollection_Mat4__

#include <pyOCCT_Common.hxx>
#include <NCollection_Mat4.hxx>
#include <NCollection_Vec4.hxx>
#include <NCollection_Vec3.hxx>

template <typename Element_t>
void bind_NCollection_Mat4(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<NCollection_Mat4<Element_t>, std::unique_ptr<NCollection_Mat4<Element_t>, Deleter<NCollection_Mat4<Element_t>>>> cls_NCollection_Mat4(mod, name.c_str(), "Generic matrix of 4 x 4 elements. To be used in conjunction with NCollection_Vec4 entities. Originally introduced for 3D space projection and orientation operations.", local);

// Constructors
cls_NCollection_Mat4.def(py::init<>());

// Fields

// Methods
cls_NCollection_Mat4.def_static("Rows_", (size_t (*)()) &NCollection_Mat4<Element_t>::Rows, "Get number of rows.");
cls_NCollection_Mat4.def_static("Cols_", (size_t (*)()) &NCollection_Mat4<Element_t>::Cols, "Get number of columns.");
cls_NCollection_Mat4.def("GetValue", (Element_t (NCollection_Mat4<Element_t>::*)(const size_t, const size_t) const) &NCollection_Mat4<Element_t>::GetValue, "Get element at the specified row and column.", py::arg("theRow"), py::arg("theCol"));
cls_NCollection_Mat4.def("ChangeValue", (Element_t & (NCollection_Mat4<Element_t>::*)(const size_t, const size_t)) &NCollection_Mat4<Element_t>::ChangeValue, "Access element at the specified row and column.", py::arg("theRow"), py::arg("theCol"));
cls_NCollection_Mat4.def("SetValue", (void (NCollection_Mat4<Element_t>::*)(const size_t, const size_t, const Element_t)) &NCollection_Mat4<Element_t>::SetValue, "Set value for the element specified by row and columns.", py::arg("theRow"), py::arg("theCol"), py::arg("theValue"));
cls_NCollection_Mat4.def("GetRow", (NCollection_Vec4<Element_t> (NCollection_Mat4<Element_t>::*)(const size_t) const) &NCollection_Mat4<Element_t>::GetRow, "Get vector of elements for the specified row.", py::arg("theRow"));
cls_NCollection_Mat4.def("SetRow", (void (NCollection_Mat4<Element_t>::*)(const size_t, const NCollection_Vec3<Element_t> &)) &NCollection_Mat4<Element_t>::SetRow, "Change first 3 row values by the passed vector.", py::arg("theRow"), py::arg("theVec"));
cls_NCollection_Mat4.def("SetRow", (void (NCollection_Mat4<Element_t>::*)(const size_t, const NCollection_Vec4<Element_t> &)) &NCollection_Mat4<Element_t>::SetRow, "Set row values by the passed 4 element vector.", py::arg("theRow"), py::arg("theVec"));
cls_NCollection_Mat4.def("GetColumn", (NCollection_Vec4<Element_t> (NCollection_Mat4<Element_t>::*)(const size_t) const) &NCollection_Mat4<Element_t>::GetColumn, "Get vector of elements for the specified column.", py::arg("theCol"));
cls_NCollection_Mat4.def("SetColumn", (void (NCollection_Mat4<Element_t>::*)(const size_t, const NCollection_Vec3<Element_t> &)) &NCollection_Mat4<Element_t>::SetColumn, "Change first 3 column values by the passed vector.", py::arg("theCol"), py::arg("theVec"));
cls_NCollection_Mat4.def("SetColumn", (void (NCollection_Mat4<Element_t>::*)(const size_t, const NCollection_Vec4<Element_t> &)) &NCollection_Mat4<Element_t>::SetColumn, "Set column values by the passed 4 element vector.", py::arg("theCol"), py::arg("theVec"));
cls_NCollection_Mat4.def("GetDiagonal", (NCollection_Vec4<Element_t> (NCollection_Mat4<Element_t>::*)() const) &NCollection_Mat4<Element_t>::GetDiagonal, "Get vector of diagonal elements.");
cls_NCollection_Mat4.def("SetDiagonal", (void (NCollection_Mat4<Element_t>::*)(const NCollection_Vec3<Element_t> &)) &NCollection_Mat4<Element_t>::SetDiagonal, "Change first 3 elements of the diagonal matrix.", py::arg("theVec"));
cls_NCollection_Mat4.def("SetDiagonal", (void (NCollection_Mat4<Element_t>::*)(const NCollection_Vec4<Element_t> &)) &NCollection_Mat4<Element_t>::SetDiagonal, "Set diagonal elements of the matrix by the passed vector.", py::arg("theVec"));
cls_NCollection_Mat4.def("InitIdentity", (void (NCollection_Mat4<Element_t>::*)()) &NCollection_Mat4<Element_t>::InitIdentity, "Initialize the identity matrix.");
cls_NCollection_Mat4.def("IsIdentity", (bool (NCollection_Mat4<Element_t>::*)() const) &NCollection_Mat4<Element_t>::IsIdentity, "Checks the matrix for identity.");
cls_NCollection_Mat4.def("IsEqual", (bool (NCollection_Mat4<Element_t>::*)(const NCollection_Mat4<Element_t> &) const) &NCollection_Mat4<Element_t>::IsEqual, "Check this matrix for equality with another matrix (without tolerance!).", py::arg("theOther"));
cls_NCollection_Mat4.def("__eq__", (bool (NCollection_Mat4<Element_t>::*)(const NCollection_Mat4<Element_t> &)) &NCollection_Mat4<Element_t>::operator==, py::is_operator(), "Check this matrix for equality with another matrix (without tolerance!).", py::arg("theOther"));
cls_NCollection_Mat4.def("__eq__", (bool (NCollection_Mat4<Element_t>::*)(const NCollection_Mat4<Element_t> &) const) &NCollection_Mat4<Element_t>::operator==, py::is_operator(), "None", py::arg("theOther"));
cls_NCollection_Mat4.def("__ne__", (bool (NCollection_Mat4<Element_t>::*)(const NCollection_Mat4<Element_t> &)) &NCollection_Mat4<Element_t>::operator!=, py::is_operator(), "Check this matrix for non-equality with another matrix (without tolerance!).", py::arg("theOther"));
cls_NCollection_Mat4.def("__ne__", (bool (NCollection_Mat4<Element_t>::*)(const NCollection_Mat4<Element_t> &) const) &NCollection_Mat4<Element_t>::operator!=, py::is_operator(), "None", py::arg("theOther"));
cls_NCollection_Mat4.def("GetData", (const Element_t * (NCollection_Mat4<Element_t>::*)() const) &NCollection_Mat4<Element_t>::GetData, "Raw access to the data (for OpenGL exchange).");
cls_NCollection_Mat4.def("ChangeData", (Element_t * (NCollection_Mat4<Element_t>::*)()) &NCollection_Mat4<Element_t>::ChangeData, "None");
cls_NCollection_Mat4.def("__mul__", (NCollection_Vec4<Element_t> (NCollection_Mat4<Element_t>::*)(const NCollection_Vec4<Element_t> &) const) &NCollection_Mat4<Element_t>::operator*, py::is_operator(), "Multiply by the vector (M * V).", py::arg("theVec"));
cls_NCollection_Mat4.def("Multiply", (NCollection_Mat4<Element_t> (NCollection_Mat4<Element_t>::*)(const NCollection_Mat4<Element_t> &, const NCollection_Mat4<Element_t> &)) &NCollection_Mat4<Element_t>::Multiply, "Compute matrix multiplication product: A * B.", py::arg("theMatA"), py::arg("theMatB"));
cls_NCollection_Mat4.def("Multiply", (void (NCollection_Mat4<Element_t>::*)(const NCollection_Mat4<Element_t> &)) &NCollection_Mat4<Element_t>::Multiply, "Compute matrix multiplication.", py::arg("theMat"));
cls_NCollection_Mat4.def("__imul__", (NCollection_Mat4<Element_t> & (NCollection_Mat4<Element_t>::*)(const NCollection_Mat4<Element_t> &)) &NCollection_Mat4<Element_t>::operator*=, py::is_operator(), "Multiply by the another matrix.", py::arg("theMat"));
cls_NCollection_Mat4.def("__mul__", (NCollection_Mat4<Element_t> (NCollection_Mat4<Element_t>::*)(const NCollection_Mat4<Element_t> &) const) &NCollection_Mat4<Element_t>::operator*, py::is_operator(), "Compute matrix multiplication product.", py::arg("theMat"));
cls_NCollection_Mat4.def("Multiplied", (NCollection_Mat4<Element_t> (NCollection_Mat4<Element_t>::*)(const NCollection_Mat4<Element_t> &) const) &NCollection_Mat4<Element_t>::Multiplied, "Compute matrix multiplication product.", py::arg("theMat"));
cls_NCollection_Mat4.def("Multiply", (void (NCollection_Mat4<Element_t>::*)(const Element_t)) &NCollection_Mat4<Element_t>::Multiply, "Compute per-component multiplication.", py::arg("theFactor"));
cls_NCollection_Mat4.def("__imul__", (NCollection_Mat4<Element_t> & (NCollection_Mat4<Element_t>::*)(const Element_t)) &NCollection_Mat4<Element_t>::operator*=, py::is_operator(), "Compute per-element multiplication.", py::arg("theFactor"));
cls_NCollection_Mat4.def("__mul__", (NCollection_Mat4<Element_t> (NCollection_Mat4<Element_t>::*)(const Element_t) const) &NCollection_Mat4<Element_t>::operator*, py::is_operator(), "Compute per-element multiplication.", py::arg("theFactor"));
cls_NCollection_Mat4.def("Multiplied", (NCollection_Mat4<Element_t> (NCollection_Mat4<Element_t>::*)(const Element_t) const) &NCollection_Mat4<Element_t>::Multiplied, "Compute per-element multiplication.", py::arg("theFactor"));
cls_NCollection_Mat4.def("Translate", (void (NCollection_Mat4<Element_t>::*)(const NCollection_Vec3<Element_t> &)) &NCollection_Mat4<Element_t>::Translate, "Translate the matrix on the passed vector.", py::arg("theVec"));
cls_NCollection_Mat4.def("Transposed", (NCollection_Mat4<Element_t> (NCollection_Mat4<Element_t>::*)() const) &NCollection_Mat4<Element_t>::Transposed, "Transpose the matrix.");
cls_NCollection_Mat4.def("Transpose", (void (NCollection_Mat4<Element_t>::*)()) &NCollection_Mat4<Element_t>::Transpose, "Transpose the matrix.");
cls_NCollection_Mat4.def("Inverted", (bool (NCollection_Mat4<Element_t>::*)(NCollection_Mat4<Element_t> &) const) &NCollection_Mat4<Element_t>::Inverted, "Compute inverted matrix.", py::arg("theOutMx"));
cls_NCollection_Mat4.def_static("Map_", (NCollection_Mat4<Element_t> & (*)(Element_t *)) &NCollection_Mat4<Element_t>::Map, "Maps plain C array to matrix type.", py::arg("theData"));
cls_NCollection_Mat4.def_static("Map_", (const NCollection_Mat4<Element_t> & (*)(const Element_t *)) &NCollection_Mat4<Element_t>::Map, "Maps plain C array to matrix type.", py::arg("theData"));

// Enums

}

#endif