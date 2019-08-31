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
#ifndef __NCollection_Vec4__
#define __NCollection_Vec4__

#include <NCollection_Vec4.hxx>
#include <NCollection_Vec2.hxx>
#include <NCollection_Vec3.hxx>

template <typename Element_t>
void bind_NCollection_Vec4(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<NCollection_Vec4<Element_t>> cls_NCollection_Vec4(mod, name.c_str(), "Generic 4-components vector. To be used as RGBA color vector or XYZW 3D-point with special W-component for operations with projection / model view matrices. Use this class for 3D-points carefully because declared W-component may results in incorrect results if used without matrices.", local);

// Constructors
cls_NCollection_Vec4.def(py::init<>());
cls_NCollection_Vec4.def(py::init<const Element_t>(), py::arg("theValue"));
cls_NCollection_Vec4.def(py::init<const Element_t, const Element_t, const Element_t, const Element_t>(), py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theW"));
cls_NCollection_Vec4.def(py::init<const NCollection_Vec2<Element_t> &>(), py::arg("theVec2"));
cls_NCollection_Vec4.def(py::init<const NCollection_Vec3<Element_t> &>(), py::arg("theVec3"));
cls_NCollection_Vec4.def(py::init<const NCollection_Vec3<Element_t> &, const Element_t>(), py::arg("theVec3"), py::arg("theAlpha"));

// Methods
cls_NCollection_Vec4.def_static("Length_", (int (*)()) &NCollection_Vec4<Element_t>::Length, "Returns the number of components.");
cls_NCollection_Vec4.def("SetValues", (void (NCollection_Vec4<Element_t>::*)(const Element_t, const Element_t, const Element_t, const Element_t)) &NCollection_Vec4<Element_t>::SetValues, "Assign new values to the vector.", py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theW"));
cls_NCollection_Vec4.def("x", (Element_t (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::x, "Alias to 1st component as X coordinate in XYZW.");
cls_NCollection_Vec4.def("r", (Element_t (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::r, "Alias to 1st component as RED channel in RGBA.");
cls_NCollection_Vec4.def("y", (Element_t (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::y, "Alias to 2nd component as Y coordinate in XYZW.");
cls_NCollection_Vec4.def("g", (Element_t (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::g, "Alias to 2nd component as GREEN channel in RGBA.");
cls_NCollection_Vec4.def("z", (Element_t (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::z, "Alias to 3rd component as Z coordinate in XYZW.");
cls_NCollection_Vec4.def("b", (Element_t (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::b, "Alias to 3rd component as BLUE channel in RGBA.");
cls_NCollection_Vec4.def("w", (Element_t (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::w, "Alias to 4th component as W coordinate in XYZW.");
cls_NCollection_Vec4.def("a", (Element_t (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::a, "Alias to 4th component as ALPHA channel in RGBA.");
cls_NCollection_Vec4.def("xy", (const NCollection_Vec2<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::xy, "None");
cls_NCollection_Vec4.def("yx", (const NCollection_Vec2<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::yx, "None");
cls_NCollection_Vec4.def("xz", (const NCollection_Vec2<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::xz, "None");
cls_NCollection_Vec4.def("zx", (const NCollection_Vec2<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::zx, "None");
cls_NCollection_Vec4.def("xw", (const NCollection_Vec2<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::xw, "None");
cls_NCollection_Vec4.def("wx", (const NCollection_Vec2<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::wx, "None");
cls_NCollection_Vec4.def("yz", (const NCollection_Vec2<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::yz, "None");
cls_NCollection_Vec4.def("zy", (const NCollection_Vec2<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::zy, "None");
cls_NCollection_Vec4.def("yw", (const NCollection_Vec2<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::yw, "None");
cls_NCollection_Vec4.def("wy", (const NCollection_Vec2<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::wy, "None");
cls_NCollection_Vec4.def("zw", (const NCollection_Vec2<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::zw, "None");
cls_NCollection_Vec4.def("wz", (const NCollection_Vec2<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::wz, "None");
cls_NCollection_Vec4.def("xyz", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::xyz, "None");
cls_NCollection_Vec4.def("xzy", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::xzy, "None");
cls_NCollection_Vec4.def("yxz", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::yxz, "None");
cls_NCollection_Vec4.def("yzx", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::yzx, "None");
cls_NCollection_Vec4.def("zyx", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::zyx, "None");
cls_NCollection_Vec4.def("zxy", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::zxy, "None");
cls_NCollection_Vec4.def("xyw", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::xyw, "None");
cls_NCollection_Vec4.def("xwy", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::xwy, "None");
cls_NCollection_Vec4.def("yxw", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::yxw, "None");
cls_NCollection_Vec4.def("ywx", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::ywx, "None");
cls_NCollection_Vec4.def("wyx", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::wyx, "None");
cls_NCollection_Vec4.def("wxy", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::wxy, "None");
cls_NCollection_Vec4.def("xzw", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::xzw, "None");
cls_NCollection_Vec4.def("xwz", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::xwz, "None");
cls_NCollection_Vec4.def("zxw", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::zxw, "None");
cls_NCollection_Vec4.def("zwx", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::zwx, "None");
cls_NCollection_Vec4.def("wzx", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::wzx, "None");
cls_NCollection_Vec4.def("wxz", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::wxz, "None");
cls_NCollection_Vec4.def("yzw", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::yzw, "None");
cls_NCollection_Vec4.def("ywz", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::ywz, "None");
cls_NCollection_Vec4.def("zyw", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::zyw, "None");
cls_NCollection_Vec4.def("zwy", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::zwy, "None");
cls_NCollection_Vec4.def("wzy", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::wzy, "None");
cls_NCollection_Vec4.def("wyz", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::wyz, "None");
cls_NCollection_Vec4.def("rgb", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::rgb, "None");
cls_NCollection_Vec4.def("rbg", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::rbg, "None");
cls_NCollection_Vec4.def("grb", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::grb, "None");
cls_NCollection_Vec4.def("gbr", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::gbr, "None");
cls_NCollection_Vec4.def("bgr", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::bgr, "None");
cls_NCollection_Vec4.def("brg", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::brg, "None");
cls_NCollection_Vec4.def("x", (Element_t & (NCollection_Vec4<Element_t>::*)()) &NCollection_Vec4<Element_t>::x, "Alias to 1st component as X coordinate in XYZW.");
cls_NCollection_Vec4.def("r", (Element_t & (NCollection_Vec4<Element_t>::*)()) &NCollection_Vec4<Element_t>::r, "Alias to 1st component as RED channel in RGBA.");
cls_NCollection_Vec4.def("y", (Element_t & (NCollection_Vec4<Element_t>::*)()) &NCollection_Vec4<Element_t>::y, "Alias to 2nd component as Y coordinate in XYZW.");
cls_NCollection_Vec4.def("g", (Element_t & (NCollection_Vec4<Element_t>::*)()) &NCollection_Vec4<Element_t>::g, "Alias to 2nd component as GREEN channel in RGBA.");
cls_NCollection_Vec4.def("z", (Element_t & (NCollection_Vec4<Element_t>::*)()) &NCollection_Vec4<Element_t>::z, "Alias to 3rd component as Z coordinate in XYZW.");
cls_NCollection_Vec4.def("b", (Element_t & (NCollection_Vec4<Element_t>::*)()) &NCollection_Vec4<Element_t>::b, "Alias to 3rd component as BLUE channel in RGBA.");
cls_NCollection_Vec4.def("w", (Element_t & (NCollection_Vec4<Element_t>::*)()) &NCollection_Vec4<Element_t>::w, "Alias to 4th component as W coordinate in XYZW.");
cls_NCollection_Vec4.def("a", (Element_t & (NCollection_Vec4<Element_t>::*)()) &NCollection_Vec4<Element_t>::a, "Alias to 4th component as ALPHA channel in RGBA.");
cls_NCollection_Vec4.def("xy", (NCollection_Vec2<Element_t> & (NCollection_Vec4<Element_t>::*)()) &NCollection_Vec4<Element_t>::xy, "Returns XY-components modifiable vector");
cls_NCollection_Vec4.def("yz", (NCollection_Vec2<Element_t> & (NCollection_Vec4<Element_t>::*)()) &NCollection_Vec4<Element_t>::yz, "Returns YZ-components modifiable vector");
cls_NCollection_Vec4.def("zw", (NCollection_Vec2<Element_t> & (NCollection_Vec4<Element_t>::*)()) &NCollection_Vec4<Element_t>::zw, "Returns YZ-components modifiable vector");
cls_NCollection_Vec4.def("xyz", (NCollection_Vec3<Element_t> & (NCollection_Vec4<Element_t>::*)()) &NCollection_Vec4<Element_t>::xyz, "Returns XYZ-components modifiable vector");
cls_NCollection_Vec4.def("yzw", (NCollection_Vec3<Element_t> & (NCollection_Vec4<Element_t>::*)()) &NCollection_Vec4<Element_t>::yzw, "Returns YZW-components modifiable vector");
cls_NCollection_Vec4.def("IsEqual", (bool (NCollection_Vec4<Element_t>::*)(const NCollection_Vec4<Element_t> &) const) &NCollection_Vec4<Element_t>::IsEqual, "Check this vector with another vector for equality (without tolerance!).", py::arg("theOther"));
cls_NCollection_Vec4.def("__eq__", (bool (NCollection_Vec4<Element_t>::*)(const NCollection_Vec4<Element_t> &)) &NCollection_Vec4<Element_t>::operator==, py::is_operator(), "Check this vector with another vector for equality (without tolerance!).", py::arg("theOther"));
cls_NCollection_Vec4.def("__eq__", (bool (NCollection_Vec4<Element_t>::*)(const NCollection_Vec4<Element_t> &) const) &NCollection_Vec4<Element_t>::operator==, py::is_operator(), "None", py::arg("theOther"));
cls_NCollection_Vec4.def("__ne__", (bool (NCollection_Vec4<Element_t>::*)(const NCollection_Vec4<Element_t> &)) &NCollection_Vec4<Element_t>::operator!=, py::is_operator(), "Check this vector with another vector for non-equality (without tolerance!).", py::arg("theOther"));
cls_NCollection_Vec4.def("__ne__", (bool (NCollection_Vec4<Element_t>::*)(const NCollection_Vec4<Element_t> &) const) &NCollection_Vec4<Element_t>::operator!=, py::is_operator(), "None", py::arg("theOther"));
cls_NCollection_Vec4.def("GetData", (const Element_t * (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::GetData, "Raw access to the data (for OpenGL exchange).");
cls_NCollection_Vec4.def("ChangeData", (Element_t * (NCollection_Vec4<Element_t>::*)()) &NCollection_Vec4<Element_t>::ChangeData, "None");
cls_NCollection_Vec4.def("__iadd__", (NCollection_Vec4<Element_t> & (NCollection_Vec4<Element_t>::*)(const NCollection_Vec4<Element_t> &)) &NCollection_Vec4<Element_t>::operator+=, py::is_operator(), "Compute per-component summary.", py::arg("theAdd"));
cls_NCollection_Vec4.def("__sub__", (NCollection_Vec4<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::operator-, py::is_operator(), "Unary -.");
cls_NCollection_Vec4.def("__isub__", (NCollection_Vec4<Element_t> & (NCollection_Vec4<Element_t>::*)(const NCollection_Vec4<Element_t> &)) &NCollection_Vec4<Element_t>::operator-=, py::is_operator(), "Compute per-component subtraction.", py::arg("theDec"));
cls_NCollection_Vec4.def("__imul__", (NCollection_Vec4<Element_t> & (NCollection_Vec4<Element_t>::*)(const NCollection_Vec4<Element_t> &)) &NCollection_Vec4<Element_t>::operator*=, py::is_operator(), "Compute per-component multiplication.", py::arg("theRight"));
cls_NCollection_Vec4.def("Multiply", (void (NCollection_Vec4<Element_t>::*)(const Element_t)) &NCollection_Vec4<Element_t>::Multiply, "Compute per-component multiplication.", py::arg("theFactor"));
cls_NCollection_Vec4.def("__imul__", (NCollection_Vec4<Element_t> & (NCollection_Vec4<Element_t>::*)(const Element_t)) &NCollection_Vec4<Element_t>::operator*=, py::is_operator(), "Compute per-component multiplication.", py::arg("theFactor"));
cls_NCollection_Vec4.def("__mul__", (NCollection_Vec4<Element_t> (NCollection_Vec4<Element_t>::*)(const Element_t) const) &NCollection_Vec4<Element_t>::operator*, py::is_operator(), "Compute per-component multiplication.", py::arg("theFactor"));
cls_NCollection_Vec4.def("Multiplied", (NCollection_Vec4<Element_t> (NCollection_Vec4<Element_t>::*)(const Element_t) const) &NCollection_Vec4<Element_t>::Multiplied, "Compute per-component multiplication.", py::arg("theFactor"));
cls_NCollection_Vec4.def("cwiseMin", (NCollection_Vec4<Element_t> (NCollection_Vec4<Element_t>::*)(const NCollection_Vec4<Element_t> &) const) &NCollection_Vec4<Element_t>::cwiseMin, "Compute component-wise minimum of two vectors.", py::arg("theVec"));
cls_NCollection_Vec4.def("cwiseMax", (NCollection_Vec4<Element_t> (NCollection_Vec4<Element_t>::*)(const NCollection_Vec4<Element_t> &) const) &NCollection_Vec4<Element_t>::cwiseMax, "Compute component-wise maximum of two vectors.", py::arg("theVec"));
// cls_NCollection_Vec4.def("cwiseAbs", (NCollection_Vec4<Element_t> (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::cwiseAbs, "Compute component-wise modulus of the vector.");
cls_NCollection_Vec4.def("maxComp", (Element_t (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::maxComp, "Compute maximum component of the vector.");
cls_NCollection_Vec4.def("minComp", (Element_t (NCollection_Vec4<Element_t>::*)() const) &NCollection_Vec4<Element_t>::minComp, "Compute minimum component of the vector.");
cls_NCollection_Vec4.def("Dot", (Element_t (NCollection_Vec4<Element_t>::*)(const NCollection_Vec4<Element_t> &) const) &NCollection_Vec4<Element_t>::Dot, "Computes the dot product.", py::arg("theOther"));
cls_NCollection_Vec4.def("__itruediv__", (NCollection_Vec4<Element_t> & (NCollection_Vec4<Element_t>::*)(const Element_t)) &NCollection_Vec4<Element_t>::operator/=, py::is_operator(), "Compute per-component division by scale factor.", py::arg("theInvFactor"));
cls_NCollection_Vec4.def("__truediv__", (NCollection_Vec4<Element_t> (NCollection_Vec4<Element_t>::*)(const Element_t)) &NCollection_Vec4<Element_t>::operator/, py::is_operator(), "Compute per-component division by scale factor.", py::arg("theInvFactor"));

}

#endif