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
#include <gp_XYZ.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Ax1.hxx>
#include <gp_Ax2.hxx>
#include <gp_Trsf.hxx>
#include <gp_Vec.hxx>

void bind_gp_Pnt(py::module &mod){

py::class_<gp_Pnt, std::unique_ptr<gp_Pnt, Deleter<gp_Pnt>>> cls_gp_Pnt(mod, "gp_Pnt", "Defines a 3D cartesian point.");

// Constructors
cls_gp_Pnt.def(py::init<>());
cls_gp_Pnt.def(py::init<const gp_XYZ &>(), py::arg("Coord"));
cls_gp_Pnt.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Xp"), py::arg("Yp"), py::arg("Zp"));

// Fields

// Methods
// cls_gp_Pnt.def_static("operator new_", (void * (*)(size_t)) &gp_Pnt::operator new, "None", py::arg("theSize"));
// cls_gp_Pnt.def_static("operator delete_", (void (*)(void *)) &gp_Pnt::operator delete, "None", py::arg("theAddress"));
// cls_gp_Pnt.def_static("operator new[]_", (void * (*)(size_t)) &gp_Pnt::operator new[], "None", py::arg("theSize"));
// cls_gp_Pnt.def_static("operator delete[]_", (void (*)(void *)) &gp_Pnt::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Pnt.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Pnt::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Pnt.def_static("operator delete_", (void (*)(void *, void *)) &gp_Pnt::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Pnt.def("SetCoord", (void (gp_Pnt::*)(const Standard_Integer, const Standard_Real)) &gp_Pnt::SetCoord, "Changes the coordinate of range Index : Index = 1 => X is modified Index = 2 => Y is modified Index = 3 => Z is modified Raised if Index != {1, 2, 3}.", py::arg("Index"), py::arg("Xi"));
cls_gp_Pnt.def("SetCoord", (void (gp_Pnt::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &gp_Pnt::SetCoord, "For this point, assigns the values Xp, Yp and Zp to its three coordinates.", py::arg("Xp"), py::arg("Yp"), py::arg("Zp"));
cls_gp_Pnt.def("SetX", (void (gp_Pnt::*)(const Standard_Real)) &gp_Pnt::SetX, "Assigns the given value to the X coordinate of this point.", py::arg("X"));
cls_gp_Pnt.def("SetY", (void (gp_Pnt::*)(const Standard_Real)) &gp_Pnt::SetY, "Assigns the given value to the Y coordinate of this point.", py::arg("Y"));
cls_gp_Pnt.def("SetZ", (void (gp_Pnt::*)(const Standard_Real)) &gp_Pnt::SetZ, "Assigns the given value to the Z coordinate of this point.", py::arg("Z"));
cls_gp_Pnt.def("SetXYZ", (void (gp_Pnt::*)(const gp_XYZ &)) &gp_Pnt::SetXYZ, "Assigns the three coordinates of Coord to this point.", py::arg("Coord"));
cls_gp_Pnt.def("Coord", (Standard_Real (gp_Pnt::*)(const Standard_Integer) const) &gp_Pnt::Coord, "Returns the coordinate of corresponding to the value of Index : Index = 1 => X is returned Index = 2 => Y is returned Index = 3 => Z is returned Raises OutOfRange if Index != {1, 2, 3}. Raised if Index != {1, 2, 3}.", py::arg("Index"));
cls_gp_Pnt.def("Coord", [](gp_Pnt &self, Standard_Real & Xp, Standard_Real & Yp, Standard_Real & Zp){ self.Coord(Xp, Yp, Zp); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(Xp, Yp, Zp); }, "For this point gives its three coordinates Xp, Yp and Zp.", py::arg("Xp"), py::arg("Yp"), py::arg("Zp"));
cls_gp_Pnt.def("X", (Standard_Real (gp_Pnt::*)() const) &gp_Pnt::X, "For this point, returns its X coordinate.");
cls_gp_Pnt.def("Y", (Standard_Real (gp_Pnt::*)() const) &gp_Pnt::Y, "For this point, returns its Y coordinate.");
cls_gp_Pnt.def("Z", (Standard_Real (gp_Pnt::*)() const) &gp_Pnt::Z, "For this point, returns its Z coordinate.");
cls_gp_Pnt.def("XYZ", (const gp_XYZ & (gp_Pnt::*)() const) &gp_Pnt::XYZ, "For this point, returns its three coordinates as a XYZ object.");
cls_gp_Pnt.def("Coord", (const gp_XYZ & (gp_Pnt::*)() const) &gp_Pnt::Coord, "For this point, returns its three coordinates as a XYZ object.");
cls_gp_Pnt.def("ChangeCoord", (gp_XYZ & (gp_Pnt::*)()) &gp_Pnt::ChangeCoord, "Returns the coordinates of this point. Note: This syntax allows direct modification of the returned value.");
cls_gp_Pnt.def("BaryCenter", (void (gp_Pnt::*)(const Standard_Real, const gp_Pnt &, const Standard_Real)) &gp_Pnt::BaryCenter, "Assigns the result of the following expression to this point (Alpha*this + Beta*P) / (Alpha + Beta)", py::arg("Alpha"), py::arg("P"), py::arg("Beta"));
cls_gp_Pnt.def("IsEqual", (Standard_Boolean (gp_Pnt::*)(const gp_Pnt &, const Standard_Real) const) &gp_Pnt::IsEqual, "Comparison Returns True if the distance between the two points is lower or equal to LinearTolerance.", py::arg("Other"), py::arg("LinearTolerance"));
cls_gp_Pnt.def("Distance", (Standard_Real (gp_Pnt::*)(const gp_Pnt &) const) &gp_Pnt::Distance, "Computes the distance between two points.", py::arg("Other"));
cls_gp_Pnt.def("SquareDistance", (Standard_Real (gp_Pnt::*)(const gp_Pnt &) const) &gp_Pnt::SquareDistance, "Computes the square distance between two points.", py::arg("Other"));
cls_gp_Pnt.def("Mirror", (void (gp_Pnt::*)(const gp_Pnt &)) &gp_Pnt::Mirror, "Performs the symmetrical transformation of a point with respect to the point P which is the center of the symmetry.", py::arg("P"));
cls_gp_Pnt.def("Mirrored", (gp_Pnt (gp_Pnt::*)(const gp_Pnt &) const) &gp_Pnt::Mirrored, "Performs the symmetrical transformation of a point with respect to an axis placement which is the axis of the symmetry.", py::arg("P"));
cls_gp_Pnt.def("Mirror", (void (gp_Pnt::*)(const gp_Ax1 &)) &gp_Pnt::Mirror, "None", py::arg("A1"));
cls_gp_Pnt.def("Mirrored", (gp_Pnt (gp_Pnt::*)(const gp_Ax1 &) const) &gp_Pnt::Mirrored, "Performs the symmetrical transformation of a point with respect to a plane. The axis placement A2 locates the plane of the symmetry : (Location, XDirection, YDirection).", py::arg("A1"));
cls_gp_Pnt.def("Mirror", (void (gp_Pnt::*)(const gp_Ax2 &)) &gp_Pnt::Mirror, "None", py::arg("A2"));
cls_gp_Pnt.def("Mirrored", (gp_Pnt (gp_Pnt::*)(const gp_Ax2 &) const) &gp_Pnt::Mirrored, "Rotates a point. A1 is the axis of the rotation. Ang is the angular value of the rotation in radians.", py::arg("A2"));
cls_gp_Pnt.def("Rotate", (void (gp_Pnt::*)(const gp_Ax1 &, const Standard_Real)) &gp_Pnt::Rotate, "None", py::arg("A1"), py::arg("Ang"));
cls_gp_Pnt.def("Rotated", (gp_Pnt (gp_Pnt::*)(const gp_Ax1 &, const Standard_Real) const) &gp_Pnt::Rotated, "Scales a point. S is the scaling value.", py::arg("A1"), py::arg("Ang"));
cls_gp_Pnt.def("Scale", (void (gp_Pnt::*)(const gp_Pnt &, const Standard_Real)) &gp_Pnt::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Pnt.def("Scaled", (gp_Pnt (gp_Pnt::*)(const gp_Pnt &, const Standard_Real) const) &gp_Pnt::Scaled, "Transforms a point with the transformation T.", py::arg("P"), py::arg("S"));
cls_gp_Pnt.def("Transform", (void (gp_Pnt::*)(const gp_Trsf &)) &gp_Pnt::Transform, "None", py::arg("T"));
cls_gp_Pnt.def("Transformed", (gp_Pnt (gp_Pnt::*)(const gp_Trsf &) const) &gp_Pnt::Transformed, "Translates a point in the direction of the vector V. The magnitude of the translation is the vector's magnitude.", py::arg("T"));
cls_gp_Pnt.def("Translate", (void (gp_Pnt::*)(const gp_Vec &)) &gp_Pnt::Translate, "None", py::arg("V"));
cls_gp_Pnt.def("Translated", (gp_Pnt (gp_Pnt::*)(const gp_Vec &) const) &gp_Pnt::Translated, "Translates a point from the point P1 to the point P2.", py::arg("V"));
cls_gp_Pnt.def("Translate", (void (gp_Pnt::*)(const gp_Pnt &, const gp_Pnt &)) &gp_Pnt::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Pnt.def("Translated", (gp_Pnt (gp_Pnt::*)(const gp_Pnt &, const gp_Pnt &) const) &gp_Pnt::Translated, "None", py::arg("P1"), py::arg("P2"));

// Enums

}