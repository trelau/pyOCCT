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
#pragma once

#include <pyOCCT_Common.hxx>
#include <NCollection_Vec2.hxx>

template <typename Element_t>
void bind_NCollection_Vec2(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<NCollection_Vec2<Element_t>> cls_NCollection_Vec2(mod, name.c_str(), "Defines the 2D-vector template. The main target for this class - to handle raw low-level arrays (from/to graphic driver etc.).", local);

// Constructors
cls_NCollection_Vec2.def(py::init<>());
cls_NCollection_Vec2.def(py::init<const Element_t>(), py::arg("theXY"));
cls_NCollection_Vec2.def(py::init<const Element_t, const Element_t>(), py::arg("theX"), py::arg("theY"));

// Methods
cls_NCollection_Vec2.def_static("Length_", (int (*)()) &NCollection_Vec2<Element_t>::Length, "Returns the number of components.");
cls_NCollection_Vec2.def("SetValues", (void (NCollection_Vec2<Element_t>::*)(const Element_t, const Element_t)) &NCollection_Vec2<Element_t>::SetValues, "Assign new values to the vector.", py::arg("theX"), py::arg("theY"));
cls_NCollection_Vec2.def("x", (Element_t (NCollection_Vec2<Element_t>::*)() const) &NCollection_Vec2<Element_t>::x, "Alias to 1st component as X coordinate in XY.");
cls_NCollection_Vec2.def("y", (Element_t (NCollection_Vec2<Element_t>::*)() const) &NCollection_Vec2<Element_t>::y, "Alias to 2nd component as Y coordinate in XY.");
cls_NCollection_Vec2.def("xy", (const NCollection_Vec2<Element_t> (NCollection_Vec2<Element_t>::*)() const) &NCollection_Vec2<Element_t>::xy, "None");
cls_NCollection_Vec2.def("yx", (const NCollection_Vec2<Element_t> (NCollection_Vec2<Element_t>::*)() const) &NCollection_Vec2<Element_t>::yx, "None");
cls_NCollection_Vec2.def("x", (Element_t & (NCollection_Vec2<Element_t>::*)()) &NCollection_Vec2<Element_t>::x, "Alias to 1st component as X coordinate in XY.");
cls_NCollection_Vec2.def("y", (Element_t & (NCollection_Vec2<Element_t>::*)()) &NCollection_Vec2<Element_t>::y, "Alias to 2nd component as Y coordinate in XY.");
cls_NCollection_Vec2.def("IsEqual", (bool (NCollection_Vec2<Element_t>::*)(const NCollection_Vec2<Element_t> &) const) &NCollection_Vec2<Element_t>::IsEqual, "Check this vector with another vector for equality (without tolerance!).", py::arg("theOther"));
cls_NCollection_Vec2.def("__eq__", (bool (NCollection_Vec2<Element_t>::*)(const NCollection_Vec2<Element_t> &)) &NCollection_Vec2<Element_t>::operator==, py::is_operator(), "Check this vector with another vector for equality (without tolerance!).", py::arg("theOther"));
cls_NCollection_Vec2.def("__eq__", (bool (NCollection_Vec2<Element_t>::*)(const NCollection_Vec2<Element_t> &) const) &NCollection_Vec2<Element_t>::operator==, py::is_operator(), "None", py::arg("theOther"));
cls_NCollection_Vec2.def("__ne__", (bool (NCollection_Vec2<Element_t>::*)(const NCollection_Vec2<Element_t> &)) &NCollection_Vec2<Element_t>::operator!=, py::is_operator(), "Check this vector with another vector for non-equality (without tolerance!).", py::arg("theOther"));
cls_NCollection_Vec2.def("__ne__", (bool (NCollection_Vec2<Element_t>::*)(const NCollection_Vec2<Element_t> &) const) &NCollection_Vec2<Element_t>::operator!=, py::is_operator(), "None", py::arg("theOther"));
cls_NCollection_Vec2.def("GetData", (const Element_t * (NCollection_Vec2<Element_t>::*)() const) &NCollection_Vec2<Element_t>::GetData, "Raw access to the data (for OpenGL exchange).");
cls_NCollection_Vec2.def("ChangeData", (Element_t * (NCollection_Vec2<Element_t>::*)()) &NCollection_Vec2<Element_t>::ChangeData, "None");
cls_NCollection_Vec2.def("__iadd__", (NCollection_Vec2<Element_t> & (NCollection_Vec2<Element_t>::*)(const NCollection_Vec2<Element_t> &)) &NCollection_Vec2<Element_t>::operator+=, py::is_operator(), "Compute per-component summary.", py::arg("theAdd"));
cls_NCollection_Vec2.def("__isub__", (NCollection_Vec2<Element_t> & (NCollection_Vec2<Element_t>::*)(const NCollection_Vec2<Element_t> &)) &NCollection_Vec2<Element_t>::operator-=, py::is_operator(), "Compute per-component subtraction.", py::arg("theDec"));
cls_NCollection_Vec2.def("__sub__", (NCollection_Vec2<Element_t> (NCollection_Vec2<Element_t>::*)() const) &NCollection_Vec2<Element_t>::operator-, py::is_operator(), "Unary -.");
cls_NCollection_Vec2.def("__imul__", (NCollection_Vec2<Element_t> & (NCollection_Vec2<Element_t>::*)(const NCollection_Vec2<Element_t> &)) &NCollection_Vec2<Element_t>::operator*=, py::is_operator(), "Compute per-component multiplication.", py::arg("theRight"));
cls_NCollection_Vec2.def("Multiply", (void (NCollection_Vec2<Element_t>::*)(const Element_t)) &NCollection_Vec2<Element_t>::Multiply, "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
cls_NCollection_Vec2.def("Multiplied", (NCollection_Vec2<Element_t> (NCollection_Vec2<Element_t>::*)(const Element_t) const) &NCollection_Vec2<Element_t>::Multiplied, "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
cls_NCollection_Vec2.def("cwiseMin", (NCollection_Vec2<Element_t> (NCollection_Vec2<Element_t>::*)(const NCollection_Vec2<Element_t> &) const) &NCollection_Vec2<Element_t>::cwiseMin, "Compute component-wise minimum of two vectors.", py::arg("theVec"));
cls_NCollection_Vec2.def("cwiseMax", (NCollection_Vec2<Element_t> (NCollection_Vec2<Element_t>::*)(const NCollection_Vec2<Element_t> &) const) &NCollection_Vec2<Element_t>::cwiseMax, "Compute component-wise maximum of two vectors.", py::arg("theVec"));
// cls_NCollection_Vec2.def("cwiseAbs", (NCollection_Vec2<Element_t> (NCollection_Vec2<Element_t>::*)() const) &NCollection_Vec2<Element_t>::cwiseAbs, "Compute component-wise modulus of the vector.");
cls_NCollection_Vec2.def("maxComp", (Element_t (NCollection_Vec2<Element_t>::*)() const) &NCollection_Vec2<Element_t>::maxComp, "Compute maximum component of the vector.");
cls_NCollection_Vec2.def("minComp", (Element_t (NCollection_Vec2<Element_t>::*)() const) &NCollection_Vec2<Element_t>::minComp, "Compute minimum component of the vector.");
cls_NCollection_Vec2.def("__imul__", (NCollection_Vec2<Element_t> & (NCollection_Vec2<Element_t>::*)(const Element_t)) &NCollection_Vec2<Element_t>::operator*=, py::is_operator(), "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
cls_NCollection_Vec2.def("__itruediv__", (NCollection_Vec2<Element_t> & (NCollection_Vec2<Element_t>::*)(const Element_t)) &NCollection_Vec2<Element_t>::operator/=, py::is_operator(), "Compute per-component division by scale factor.", py::arg("theInvFactor"));
cls_NCollection_Vec2.def("__mul__", (NCollection_Vec2<Element_t> (NCollection_Vec2<Element_t>::*)(const Element_t) const) &NCollection_Vec2<Element_t>::operator*, py::is_operator(), "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
cls_NCollection_Vec2.def("__truediv__", (NCollection_Vec2<Element_t> (NCollection_Vec2<Element_t>::*)(const Element_t) const) &NCollection_Vec2<Element_t>::operator/, py::is_operator(), "Compute per-component division by scale factor.", py::arg("theInvFactor"));
cls_NCollection_Vec2.def("Dot", (Element_t (NCollection_Vec2<Element_t>::*)(const NCollection_Vec2<Element_t> &) const) &NCollection_Vec2<Element_t>::Dot, "Computes the dot product.", py::arg("theOther"));
cls_NCollection_Vec2.def("Modulus", (Element_t (NCollection_Vec2<Element_t>::*)() const) &NCollection_Vec2<Element_t>::Modulus, "Computes the vector modulus (magnitude, length).");
cls_NCollection_Vec2.def("SquareModulus", (Element_t (NCollection_Vec2<Element_t>::*)() const) &NCollection_Vec2<Element_t>::SquareModulus, "Computes the square of vector modulus (magnitude, length). This method may be used for performance tricks.");
cls_NCollection_Vec2.def_static("DX_", (NCollection_Vec2<Element_t> (*)()) &NCollection_Vec2<Element_t>::DX, "Constuct DX unit vector.");
cls_NCollection_Vec2.def_static("DY_", (NCollection_Vec2<Element_t> (*)()) &NCollection_Vec2<Element_t>::DY, "Constuct DY unit vector.");

}
