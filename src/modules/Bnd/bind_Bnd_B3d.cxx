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
#include <Bnd_B3d.hxx>
#include <gp_Trsf.hxx>
#include <gp_Ax1.hxx>
#include <gp_Ax3.hxx>

void bind_Bnd_B3d(py::module &mod){

py::class_<Bnd_B3d> cls_Bnd_B3d(mod, "Bnd_B3d", "None");

// Constructors
cls_Bnd_B3d.def(py::init<>());
cls_Bnd_B3d.def(py::init<const gp_XYZ &, const gp_XYZ &>(), py::arg("theCenter"), py::arg("theHSize"));

// Fields

// Methods
// cls_Bnd_B3d.def_static("operator new_", (void * (*)(size_t)) &Bnd_B3d::operator new, "None", py::arg("theSize"));
// cls_Bnd_B3d.def_static("operator delete_", (void (*)(void *)) &Bnd_B3d::operator delete, "None", py::arg("theAddress"));
// cls_Bnd_B3d.def_static("operator new[]_", (void * (*)(size_t)) &Bnd_B3d::operator new[], "None", py::arg("theSize"));
// cls_Bnd_B3d.def_static("operator delete[]_", (void (*)(void *)) &Bnd_B3d::operator delete[], "None", py::arg("theAddress"));
// cls_Bnd_B3d.def_static("operator new_", (void * (*)(size_t, void *)) &Bnd_B3d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Bnd_B3d.def_static("operator delete_", (void (*)(void *, void *)) &Bnd_B3d::operator delete, "None", py::arg(""), py::arg(""));
cls_Bnd_B3d.def("IsVoid", (Standard_Boolean (Bnd_B3d::*)() const) &Bnd_B3d::IsVoid, "Returns True if the box is void (non-initialized).");
cls_Bnd_B3d.def("Clear", (void (Bnd_B3d::*)()) &Bnd_B3d::Clear, "Reset the box data.");
cls_Bnd_B3d.def("Add", (void (Bnd_B3d::*)(const gp_XYZ &)) &Bnd_B3d::Add, "Update the box by a point.", py::arg("thePnt"));
cls_Bnd_B3d.def("Add", (void (Bnd_B3d::*)(const gp_Pnt &)) &Bnd_B3d::Add, "Update the box by a point.", py::arg("thePnt"));
cls_Bnd_B3d.def("Add", (void (Bnd_B3d::*)(const Bnd_B3d &)) &Bnd_B3d::Add, "Update the box by another box.", py::arg("theBox"));
cls_Bnd_B3d.def("CornerMin", (gp_XYZ (Bnd_B3d::*)() const) &Bnd_B3d::CornerMin, "Query the lower corner: (Center - HSize). You must make sure that the box is NOT VOID (see IsVoid()), otherwise the method returns irrelevant result.");
cls_Bnd_B3d.def("CornerMax", (gp_XYZ (Bnd_B3d::*)() const) &Bnd_B3d::CornerMax, "Query the upper corner: (Center + HSize). You must make sure that the box is NOT VOID (see IsVoid()), otherwise the method returns irrelevant result.");
cls_Bnd_B3d.def("SquareExtent", (Standard_Real (Bnd_B3d::*)() const) &Bnd_B3d::SquareExtent, "Query the square diagonal. If the box is VOID (see method IsVoid()) then a very big real value is returned.");
cls_Bnd_B3d.def("Enlarge", (void (Bnd_B3d::*)(const Standard_Real)) &Bnd_B3d::Enlarge, "Extend the Box by the absolute value of theDiff.", py::arg("theDiff"));
cls_Bnd_B3d.def("Limit", (Standard_Boolean (Bnd_B3d::*)(const Bnd_B3d &)) &Bnd_B3d::Limit, "Limit the Box by the internals of theOtherBox. Returns True if the limitation takes place, otherwise False indicating that the boxes do not intersect.", py::arg("theOtherBox"));
cls_Bnd_B3d.def("Transformed", (Bnd_B3d (Bnd_B3d::*)(const gp_Trsf &) const) &Bnd_B3d::Transformed, "Transform the bounding box with the given transformation. The resulting box will be larger if theTrsf contains rotation.", py::arg("theTrsf"));
cls_Bnd_B3d.def("IsOut", (Standard_Boolean (Bnd_B3d::*)(const gp_XYZ &) const) &Bnd_B3d::IsOut, "Check the given point for the inclusion in the Box. Returns True if the point is outside.", py::arg("thePnt"));
cls_Bnd_B3d.def("IsOut", [](Bnd_B3d &self, const gp_XYZ & a0, const Standard_Real a1) -> Standard_Boolean { return self.IsOut(a0, a1); });
cls_Bnd_B3d.def("IsOut", (Standard_Boolean (Bnd_B3d::*)(const gp_XYZ &, const Standard_Real, const Standard_Boolean) const) &Bnd_B3d::IsOut, "Check a sphere for the intersection with the current box. Returns True if there is no intersection between boxes. If the parameter 'IsSphereHollow' is True, then the intersection is not reported for a box that is completely inside the sphere (otherwise this method would report an intersection).", py::arg("theCenter"), py::arg("theRadius"), py::arg("isSphereHollow"));
cls_Bnd_B3d.def("IsOut", (Standard_Boolean (Bnd_B3d::*)(const Bnd_B3d &) const) &Bnd_B3d::IsOut, "Check the given box for the intersection with the current box. Returns True if there is no intersection between boxes.", py::arg("theOtherBox"));
cls_Bnd_B3d.def("IsOut", (Standard_Boolean (Bnd_B3d::*)(const Bnd_B3d &, const gp_Trsf &) const) &Bnd_B3d::IsOut, "Check the given box oriented by the given transformation for the intersection with the current box. Returns True if there is no intersection between boxes.", py::arg("theOtherBox"), py::arg("theTrsf"));
cls_Bnd_B3d.def("IsOut", [](Bnd_B3d &self, const gp_Ax1 & a0) -> Standard_Boolean { return self.IsOut(a0); });
cls_Bnd_B3d.def("IsOut", [](Bnd_B3d &self, const gp_Ax1 & a0, const Standard_Boolean a1) -> Standard_Boolean { return self.IsOut(a0, a1); });
cls_Bnd_B3d.def("IsOut", (Standard_Boolean (Bnd_B3d::*)(const gp_Ax1 &, const Standard_Boolean, const Standard_Real) const) &Bnd_B3d::IsOut, "Check the given Line for the intersection with the current box. Returns True if there is no intersection. isRay==True means intersection check with the positive half-line theOverthickness is the addition to the size of the current box (may be negative). If positive, it can be treated as the thickness of the line 'theLine' or the radius of the cylinder along 'theLine'", py::arg("theLine"), py::arg("isRay"), py::arg("theOverthickness"));
cls_Bnd_B3d.def("IsOut", (Standard_Boolean (Bnd_B3d::*)(const gp_Ax3 &) const) &Bnd_B3d::IsOut, "Check the given Plane for the intersection with the current box. Returns True if there is no intersection.", py::arg("thePlane"));
cls_Bnd_B3d.def("IsIn", (Standard_Boolean (Bnd_B3d::*)(const Bnd_B3d &) const) &Bnd_B3d::IsIn, "Check that the box 'this' is inside the given box 'theBox'. Returns True if 'this' box is fully inside 'theBox'.", py::arg("theBox"));
cls_Bnd_B3d.def("IsIn", (Standard_Boolean (Bnd_B3d::*)(const Bnd_B3d &, const gp_Trsf &) const) &Bnd_B3d::IsIn, "Check that the box 'this' is inside the given box 'theBox' transformed by 'theTrsf'. Returns True if 'this' box is fully inside the transformed 'theBox'.", py::arg("theBox"), py::arg("theTrsf"));
cls_Bnd_B3d.def("SetCenter", (void (Bnd_B3d::*)(const gp_XYZ &)) &Bnd_B3d::SetCenter, "Set the Center coordinates", py::arg("theCenter"));
cls_Bnd_B3d.def("SetHSize", (void (Bnd_B3d::*)(const gp_XYZ &)) &Bnd_B3d::SetHSize, "Set the HSize (half-diagonal) coordinates. All components of theHSize must be non-negative.", py::arg("theHSize"));

// Enums

}