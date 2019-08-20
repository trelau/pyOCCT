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
#ifndef __NCollection_Vec3__
#define __NCollection_Vec3__

#include <pyOCCT_Common.hxx>
#include <NCollection_Vec3.hxx>
#include <NCollection_Vec2.hxx>

template <typename Element_t>
void bind_NCollection_Vec3(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<NCollection_Vec3<Element_t>, std::unique_ptr<NCollection_Vec3<Element_t>>> cls_NCollection_Vec3(mod, name.c_str(), "Generic 3-components vector. To be used as RGB color pixel or XYZ 3D-point. The main target for this class - to handle raw low-level arrays (from/to graphic driver etc.).", local);

// Constructors
cls_NCollection_Vec3.def(py::init<>());
cls_NCollection_Vec3.def(py::init<Element_t>(), py::arg("theValue"));
cls_NCollection_Vec3.def(py::init<const Element_t, const Element_t, const Element_t>(), py::arg("theX"), py::arg("theY"), py::arg("theZ"));
cls_NCollection_Vec3.def(py::init<const NCollection_Vec2<Element_t> &>(), py::arg("theVec2"));

// Fields

// Methods
cls_NCollection_Vec3.def_static("Length_", (int (*)()) &NCollection_Vec3<Element_t>::Length, "Returns the number of components.");
cls_NCollection_Vec3.def("SetValues", (void (NCollection_Vec3<Element_t>::*)(const Element_t, const Element_t, const Element_t)) &NCollection_Vec3<Element_t>::SetValues, "Assign new values to the vector.", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
cls_NCollection_Vec3.def("x", (Element_t (NCollection_Vec3<Element_t>::*)() const) &NCollection_Vec3<Element_t>::x, "Alias to 1st component as X coordinate in XYZ.");
cls_NCollection_Vec3.def("r", (Element_t (NCollection_Vec3<Element_t>::*)() const) &NCollection_Vec3<Element_t>::r, "Alias to 1st component as RED channel in RGB.");
cls_NCollection_Vec3.def("y", (Element_t (NCollection_Vec3<Element_t>::*)() const) &NCollection_Vec3<Element_t>::y, "Alias to 2nd component as Y coordinate in XYZ.");
cls_NCollection_Vec3.def("g", (Element_t (NCollection_Vec3<Element_t>::*)() const) &NCollection_Vec3<Element_t>::g, "Alias to 2nd component as GREEN channel in RGB.");
cls_NCollection_Vec3.def("z", (Element_t (NCollection_Vec3<Element_t>::*)() const) &NCollection_Vec3<Element_t>::z, "Alias to 3rd component as Z coordinate in XYZ.");
cls_NCollection_Vec3.def("b", (Element_t (NCollection_Vec3<Element_t>::*)() const) &NCollection_Vec3<Element_t>::b, "Alias to 3rd component as BLUE channel in RGB.");
cls_NCollection_Vec3.def("xy", (const NCollection_Vec2<Element_t> (NCollection_Vec3<Element_t>::*)() const) &NCollection_Vec3<Element_t>::xy, "None");
cls_NCollection_Vec3.def("yx", (const NCollection_Vec2<Element_t> (NCollection_Vec3<Element_t>::*)() const) &NCollection_Vec3<Element_t>::yx, "None");
cls_NCollection_Vec3.def("xz", (const NCollection_Vec2<Element_t> (NCollection_Vec3<Element_t>::*)() const) &NCollection_Vec3<Element_t>::xz, "None");
cls_NCollection_Vec3.def("zx", (const NCollection_Vec2<Element_t> (NCollection_Vec3<Element_t>::*)() const) &NCollection_Vec3<Element_t>::zx, "None");
cls_NCollection_Vec3.def("yz", (const NCollection_Vec2<Element_t> (NCollection_Vec3<Element_t>::*)() const) &NCollection_Vec3<Element_t>::yz, "None");
cls_NCollection_Vec3.def("zy", (const NCollection_Vec2<Element_t> (NCollection_Vec3<Element_t>::*)() const) &NCollection_Vec3<Element_t>::zy, "None");
cls_NCollection_Vec3.def("xyz", (const NCollection_Vec3<Element_t> (NCollection_Vec3<Element_t>::*)() const) &NCollection_Vec3<Element_t>::xyz, "None");
cls_NCollection_Vec3.def("xzy", (const NCollection_Vec3<Element_t> (NCollection_Vec3<Element_t>::*)() const) &NCollection_Vec3<Element_t>::xzy, "None");
cls_NCollection_Vec3.def("yxz", (const NCollection_Vec3<Element_t> (NCollection_Vec3<Element_t>::*)() const) &NCollection_Vec3<Element_t>::yxz, "None");
cls_NCollection_Vec3.def("yzx", (const NCollection_Vec3<Element_t> (NCollection_Vec3<Element_t>::*)() const) &NCollection_Vec3<Element_t>::yzx, "None");
cls_NCollection_Vec3.def("zyx", (const NCollection_Vec3<Element_t> (NCollection_Vec3<Element_t>::*)() const) &NCollection_Vec3<Element_t>::zyx, "None");
cls_NCollection_Vec3.def("zxy", (const NCollection_Vec3<Element_t> (NCollection_Vec3<Element_t>::*)() const) &NCollection_Vec3<Element_t>::zxy, "None");
cls_NCollection_Vec3.def("x", (Element_t & (NCollection_Vec3<Element_t>::*)()) &NCollection_Vec3<Element_t>::x, "Alias to 1st component as X coordinate in XYZ.");
cls_NCollection_Vec3.def("r", (Element_t & (NCollection_Vec3<Element_t>::*)()) &NCollection_Vec3<Element_t>::r, "Alias to 1st component as RED channel in RGB.");
cls_NCollection_Vec3.def("y", (Element_t & (NCollection_Vec3<Element_t>::*)()) &NCollection_Vec3<Element_t>::y, "Alias to 2nd component as Y coordinate in XYZ.");
cls_NCollection_Vec3.def("g", (Element_t & (NCollection_Vec3<Element_t>::*)()) &NCollection_Vec3<Element_t>::g, "Alias to 2nd component as GREEN channel in RGB.");
cls_NCollection_Vec3.def("z", (Element_t & (NCollection_Vec3<Element_t>::*)()) &NCollection_Vec3<Element_t>::z, "Alias to 3rd component as Z coordinate in XYZ.");
cls_NCollection_Vec3.def("b", (Element_t & (NCollection_Vec3<Element_t>::*)()) &NCollection_Vec3<Element_t>::b, "Alias to 3rd component as BLUE channel in RGB.");
cls_NCollection_Vec3.def("xy", (NCollection_Vec2<Element_t> & (NCollection_Vec3<Element_t>::*)()) &NCollection_Vec3<Element_t>::xy, "Returns XY-components modifiable vector");
cls_NCollection_Vec3.def("yz", (NCollection_Vec2<Element_t> & (NCollection_Vec3<Element_t>::*)()) &NCollection_Vec3<Element_t>::yz, "Returns YZ-components modifiable vector");
cls_NCollection_Vec3.def("IsEqual", (bool (NCollection_Vec3<Element_t>::*)(const NCollection_Vec3<Element_t> &) const) &NCollection_Vec3<Element_t>::IsEqual, "Check this vector with another vector for equality (without tolerance!).", py::arg("theOther"));
cls_NCollection_Vec3.def("__eq__", (bool (NCollection_Vec3<Element_t>::*)(const NCollection_Vec3<Element_t> &)) &NCollection_Vec3<Element_t>::operator==, py::is_operator(), "Check this vector with another vector for equality (without tolerance!).", py::arg("theOther"));
cls_NCollection_Vec3.def("__eq__", (bool (NCollection_Vec3<Element_t>::*)(const NCollection_Vec3<Element_t> &) const) &NCollection_Vec3<Element_t>::operator==, py::is_operator(), "None", py::arg("theOther"));
cls_NCollection_Vec3.def("__ne__", (bool (NCollection_Vec3<Element_t>::*)(const NCollection_Vec3<Element_t> &)) &NCollection_Vec3<Element_t>::operator!=, py::is_operator(), "Check this vector with another vector for non-equality (without tolerance!).", py::arg("theOther"));
cls_NCollection_Vec3.def("__ne__", (bool (NCollection_Vec3<Element_t>::*)(const NCollection_Vec3<Element_t> &) const) &NCollection_Vec3<Element_t>::operator!=, py::is_operator(), "None", py::arg("theOther"));
cls_NCollection_Vec3.def("GetData", (const Element_t * (NCollection_Vec3<Element_t>::*)() const) &NCollection_Vec3<Element_t>::GetData, "Raw access to the data (for OpenGL exchange).");
cls_NCollection_Vec3.def("ChangeData", (Element_t * (NCollection_Vec3<Element_t>::*)()) &NCollection_Vec3<Element_t>::ChangeData, "None");
cls_NCollection_Vec3.def("__iadd__", (NCollection_Vec3<Element_t> & (NCollection_Vec3<Element_t>::*)(const NCollection_Vec3<Element_t> &)) &NCollection_Vec3<Element_t>::operator+=, py::is_operator(), "Compute per-component summary.", py::arg("theAdd"));
cls_NCollection_Vec3.def("__sub__", (NCollection_Vec3<Element_t> (NCollection_Vec3<Element_t>::*)() const) &NCollection_Vec3<Element_t>::operator-, py::is_operator(), "Unary -.");
cls_NCollection_Vec3.def("__isub__", (NCollection_Vec3<Element_t> & (NCollection_Vec3<Element_t>::*)(const NCollection_Vec3<Element_t> &)) &NCollection_Vec3<Element_t>::operator-=, py::is_operator(), "Compute per-component subtraction.", py::arg("theDec"));
cls_NCollection_Vec3.def("Multiply", (void (NCollection_Vec3<Element_t>::*)(const Element_t)) &NCollection_Vec3<Element_t>::Multiply, "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
cls_NCollection_Vec3.def("__imul__", (NCollection_Vec3<Element_t> & (NCollection_Vec3<Element_t>::*)(const NCollection_Vec3<Element_t> &)) &NCollection_Vec3<Element_t>::operator*=, py::is_operator(), "Compute per-component multiplication.", py::arg("theRight"));
cls_NCollection_Vec3.def("__imul__", (NCollection_Vec3<Element_t> & (NCollection_Vec3<Element_t>::*)(const Element_t)) &NCollection_Vec3<Element_t>::operator*=, py::is_operator(), "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
cls_NCollection_Vec3.def("__mul__", (NCollection_Vec3<Element_t> (NCollection_Vec3<Element_t>::*)(const Element_t) const) &NCollection_Vec3<Element_t>::operator*, py::is_operator(), "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
cls_NCollection_Vec3.def("Multiplied", (NCollection_Vec3<Element_t> (NCollection_Vec3<Element_t>::*)(const Element_t) const) &NCollection_Vec3<Element_t>::Multiplied, "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
cls_NCollection_Vec3.def("cwiseMin", (NCollection_Vec3<Element_t> (NCollection_Vec3<Element_t>::*)(const NCollection_Vec3<Element_t> &) const) &NCollection_Vec3<Element_t>::cwiseMin, "Compute component-wise minimum of two vectors.", py::arg("theVec"));
cls_NCollection_Vec3.def("cwiseMax", (NCollection_Vec3<Element_t> (NCollection_Vec3<Element_t>::*)(const NCollection_Vec3<Element_t> &) const) &NCollection_Vec3<Element_t>::cwiseMax, "Compute component-wise maximum of two vectors.", py::arg("theVec"));
// cls_NCollection_Vec3.def("cwiseAbs", (NCollection_Vec3<Element_t> (NCollection_Vec3<Element_t>::*)() const) &NCollection_Vec3<Element_t>::cwiseAbs, "Compute component-wise modulus of the vector.");
cls_NCollection_Vec3.def("maxComp", (Element_t (NCollection_Vec3<Element_t>::*)() const) &NCollection_Vec3<Element_t>::maxComp, "Compute maximum component of the vector.");
cls_NCollection_Vec3.def("minComp", (Element_t (NCollection_Vec3<Element_t>::*)() const) &NCollection_Vec3<Element_t>::minComp, "Compute minimum component of the vector.");
cls_NCollection_Vec3.def("__itruediv__", (NCollection_Vec3<Element_t> & (NCollection_Vec3<Element_t>::*)(const Element_t)) &NCollection_Vec3<Element_t>::operator/=, py::is_operator(), "Compute per-component division by scale factor.", py::arg("theInvFactor"));
cls_NCollection_Vec3.def("__truediv__", (NCollection_Vec3<Element_t> (NCollection_Vec3<Element_t>::*)(const Element_t)) &NCollection_Vec3<Element_t>::operator/, py::is_operator(), "Compute per-component division by scale factor.", py::arg("theInvFactor"));
cls_NCollection_Vec3.def("Dot", (Element_t (NCollection_Vec3<Element_t>::*)(const NCollection_Vec3<Element_t> &) const) &NCollection_Vec3<Element_t>::Dot, "Computes the dot product.", py::arg("theOther"));
cls_NCollection_Vec3.def("Modulus", (Element_t (NCollection_Vec3<Element_t>::*)() const) &NCollection_Vec3<Element_t>::Modulus, "Computes the vector modulus (magnitude, length).");
cls_NCollection_Vec3.def("SquareModulus", (Element_t (NCollection_Vec3<Element_t>::*)() const) &NCollection_Vec3<Element_t>::SquareModulus, "Computes the square of vector modulus (magnitude, length). This method may be used for performance tricks.");
cls_NCollection_Vec3.def("Normalize", (void (NCollection_Vec3<Element_t>::*)()) &NCollection_Vec3<Element_t>::Normalize, "Normalize the vector.");
cls_NCollection_Vec3.def("Normalized", (NCollection_Vec3<Element_t> (NCollection_Vec3<Element_t>::*)() const) &NCollection_Vec3<Element_t>::Normalized, "Normalize the vector.");
cls_NCollection_Vec3.def_static("Cross_", (NCollection_Vec3<Element_t> (*)(const NCollection_Vec3<Element_t> &, const NCollection_Vec3<Element_t> &)) &NCollection_Vec3<Element_t>::Cross, "Computes the cross product.", py::arg("theVec1"), py::arg("theVec2"));
cls_NCollection_Vec3.def_static("GetLERP_", (NCollection_Vec3<Element_t> (*)(const NCollection_Vec3<Element_t> &, const NCollection_Vec3<Element_t> &, const Element_t)) &NCollection_Vec3<Element_t>::GetLERP, "Compute linear interpolation between to vectors.", py::arg("theFrom"), py::arg("theTo"), py::arg("theT"));
cls_NCollection_Vec3.def_static("DX_", (NCollection_Vec3<Element_t> (*)()) &NCollection_Vec3<Element_t>::DX, "Constuct DX unit vector.");
cls_NCollection_Vec3.def_static("DY_", (NCollection_Vec3<Element_t> (*)()) &NCollection_Vec3<Element_t>::DY, "Constuct DY unit vector.");
cls_NCollection_Vec3.def_static("DZ_", (NCollection_Vec3<Element_t> (*)()) &NCollection_Vec3<Element_t>::DZ, "Constuct DZ unit vector.");

// Enums

}

#endif