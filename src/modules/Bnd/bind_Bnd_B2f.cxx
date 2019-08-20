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
#include <gp_XY.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt2d.hxx>
#include <Bnd_B2f.hxx>
#include <gp_Trsf2d.hxx>
#include <gp_Ax2d.hxx>

void bind_Bnd_B2f(py::module &mod){

py::class_<Bnd_B2f, std::unique_ptr<Bnd_B2f>> cls_Bnd_B2f(mod, "Bnd_B2f", "None");

// Constructors
cls_Bnd_B2f.def(py::init<>());
cls_Bnd_B2f.def(py::init<const gp_XY &, const gp_XY &>(), py::arg("theCenter"), py::arg("theHSize"));

// Fields

// Methods
// cls_Bnd_B2f.def_static("operator new_", (void * (*)(size_t)) &Bnd_B2f::operator new, "None", py::arg("theSize"));
// cls_Bnd_B2f.def_static("operator delete_", (void (*)(void *)) &Bnd_B2f::operator delete, "None", py::arg("theAddress"));
// cls_Bnd_B2f.def_static("operator new[]_", (void * (*)(size_t)) &Bnd_B2f::operator new[], "None", py::arg("theSize"));
// cls_Bnd_B2f.def_static("operator delete[]_", (void (*)(void *)) &Bnd_B2f::operator delete[], "None", py::arg("theAddress"));
// cls_Bnd_B2f.def_static("operator new_", (void * (*)(size_t, void *)) &Bnd_B2f::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Bnd_B2f.def_static("operator delete_", (void (*)(void *, void *)) &Bnd_B2f::operator delete, "None", py::arg(""), py::arg(""));
cls_Bnd_B2f.def("IsVoid", (Standard_Boolean (Bnd_B2f::*)() const) &Bnd_B2f::IsVoid, "Returns True if the box is void (non-initialized).");
cls_Bnd_B2f.def("Clear", (void (Bnd_B2f::*)()) &Bnd_B2f::Clear, "Reset the box data.");
cls_Bnd_B2f.def("Add", (void (Bnd_B2f::*)(const gp_XY &)) &Bnd_B2f::Add, "Update the box by a point.", py::arg("thePnt"));
cls_Bnd_B2f.def("Add", (void (Bnd_B2f::*)(const gp_Pnt2d &)) &Bnd_B2f::Add, "Update the box by a point.", py::arg("thePnt"));
cls_Bnd_B2f.def("Add", (void (Bnd_B2f::*)(const Bnd_B2f &)) &Bnd_B2f::Add, "Update the box by another box.", py::arg("theBox"));
cls_Bnd_B2f.def("CornerMin", (gp_XY (Bnd_B2f::*)() const) &Bnd_B2f::CornerMin, "Query a box corner: (Center - HSize). You must make sure that the box is NOT VOID (see IsVoid()), otherwise the method returns irrelevant result.");
cls_Bnd_B2f.def("CornerMax", (gp_XY (Bnd_B2f::*)() const) &Bnd_B2f::CornerMax, "Query a box corner: (Center + HSize). You must make sure that the box is NOT VOID (see IsVoid()), otherwise the method returns irrelevant result.");
cls_Bnd_B2f.def("SquareExtent", (Standard_Real (Bnd_B2f::*)() const) &Bnd_B2f::SquareExtent, "Query the square diagonal. If the box is VOID (see method IsVoid()) then a very big real value is returned.");
cls_Bnd_B2f.def("Enlarge", (void (Bnd_B2f::*)(const Standard_Real)) &Bnd_B2f::Enlarge, "Extend the Box by the absolute value of theDiff.", py::arg("theDiff"));
cls_Bnd_B2f.def("Limit", (Standard_Boolean (Bnd_B2f::*)(const Bnd_B2f &)) &Bnd_B2f::Limit, "Limit the Box by the internals of theOtherBox. Returns True if the limitation takes place, otherwise False indicating that the boxes do not intersect.", py::arg("theOtherBox"));
cls_Bnd_B2f.def("Transformed", (Bnd_B2f (Bnd_B2f::*)(const gp_Trsf2d &) const) &Bnd_B2f::Transformed, "Transform the bounding box with the given transformation. The resulting box will be larger if theTrsf contains rotation.", py::arg("theTrsf"));
cls_Bnd_B2f.def("IsOut", (Standard_Boolean (Bnd_B2f::*)(const gp_XY &) const) &Bnd_B2f::IsOut, "Check the given point for the inclusion in the Box. Returns True if the point is outside.", py::arg("thePnt"));
cls_Bnd_B2f.def("IsOut", [](Bnd_B2f &self, const gp_XY & a0, const Standard_Real a1) -> Standard_Boolean { return self.IsOut(a0, a1); });
cls_Bnd_B2f.def("IsOut", (Standard_Boolean (Bnd_B2f::*)(const gp_XY &, const Standard_Real, const Standard_Boolean) const) &Bnd_B2f::IsOut, "Check a circle for the intersection with the current box. Returns True if there is no intersection between boxes.", py::arg("theCenter"), py::arg("theRadius"), py::arg("isCircleHollow"));
cls_Bnd_B2f.def("IsOut", (Standard_Boolean (Bnd_B2f::*)(const Bnd_B2f &) const) &Bnd_B2f::IsOut, "Check the given box for the intersection with the current box. Returns True if there is no intersection between boxes.", py::arg("theOtherBox"));
cls_Bnd_B2f.def("IsOut", (Standard_Boolean (Bnd_B2f::*)(const Bnd_B2f &, const gp_Trsf2d &) const) &Bnd_B2f::IsOut, "Check the given box oriented by the given transformation for the intersection with the current box. Returns True if there is no intersection between boxes.", py::arg("theOtherBox"), py::arg("theTrsf"));
cls_Bnd_B2f.def("IsOut", (Standard_Boolean (Bnd_B2f::*)(const gp_Ax2d &) const) &Bnd_B2f::IsOut, "Check the given Line for the intersection with the current box. Returns True if there is no intersection.", py::arg("theLine"));
cls_Bnd_B2f.def("IsOut", (Standard_Boolean (Bnd_B2f::*)(const gp_XY &, const gp_XY &) const) &Bnd_B2f::IsOut, "Check the Segment defined by the couple of input points for the intersection with the current box. Returns True if there is no intersection.", py::arg("theP0"), py::arg("theP1"));
cls_Bnd_B2f.def("IsIn", (Standard_Boolean (Bnd_B2f::*)(const Bnd_B2f &) const) &Bnd_B2f::IsIn, "Check that the box 'this' is inside the given box 'theBox'. Returns True if 'this' box is fully inside 'theBox'.", py::arg("theBox"));
cls_Bnd_B2f.def("IsIn", (Standard_Boolean (Bnd_B2f::*)(const Bnd_B2f &, const gp_Trsf2d &) const) &Bnd_B2f::IsIn, "Check that the box 'this' is inside the given box 'theBox' transformed by 'theTrsf'. Returns True if 'this' box is fully inside the transformed 'theBox'.", py::arg("theBox"), py::arg("theTrsf"));
cls_Bnd_B2f.def("SetCenter", (void (Bnd_B2f::*)(const gp_XY &)) &Bnd_B2f::SetCenter, "Set the Center coordinates", py::arg("theCenter"));
cls_Bnd_B2f.def("SetHSize", (void (Bnd_B2f::*)(const gp_XY &)) &Bnd_B2f::SetHSize, "Set the HSize (half-diagonal) coordinates. All components of theHSize must be non-negative.", py::arg("theHSize"));

// Enums

}