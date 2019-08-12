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
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor3d_TopolTool.hxx>
#include <Standard_TypeDef.hxx>
#include <IntPatch_ImpImpIntersection.hxx>
#include <IntPatch_Point.hxx>
#include <IntPatch_Line.hxx>
#include <IntPatch_SequenceOfPoint.hxx>
#include <IntPatch_SequenceOfLine.hxx>
#include <IntPatch_TheSOnBounds.hxx>

void bind_IntPatch_ImpImpIntersection(py::module &mod){

py::class_<IntPatch_ImpImpIntersection, std::unique_ptr<IntPatch_ImpImpIntersection, Deleter<IntPatch_ImpImpIntersection>>> cls_IntPatch_ImpImpIntersection(mod, "IntPatch_ImpImpIntersection", "Implementation of the intersection between two quadric patches : Plane, Cone, Cylinder or Sphere.");

// Constructors
cls_IntPatch_ImpImpIntersection.def(py::init<>());
cls_IntPatch_ImpImpIntersection.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real>(), py::arg("S1"), py::arg("D1"), py::arg("S2"), py::arg("D2"), py::arg("TolArc"), py::arg("TolTang"));
cls_IntPatch_ImpImpIntersection.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("S1"), py::arg("D1"), py::arg("S2"), py::arg("D2"), py::arg("TolArc"), py::arg("TolTang"), py::arg("theIsReqToKeepRLine"));

// Fields

// Methods
// cls_IntPatch_ImpImpIntersection.def_static("operator new_", (void * (*)(size_t)) &IntPatch_ImpImpIntersection::operator new, "None", py::arg("theSize"));
// cls_IntPatch_ImpImpIntersection.def_static("operator delete_", (void (*)(void *)) &IntPatch_ImpImpIntersection::operator delete, "None", py::arg("theAddress"));
// cls_IntPatch_ImpImpIntersection.def_static("operator new[]_", (void * (*)(size_t)) &IntPatch_ImpImpIntersection::operator new[], "None", py::arg("theSize"));
// cls_IntPatch_ImpImpIntersection.def_static("operator delete[]_", (void (*)(void *)) &IntPatch_ImpImpIntersection::operator delete[], "None", py::arg("theAddress"));
// cls_IntPatch_ImpImpIntersection.def_static("operator new_", (void * (*)(size_t, void *)) &IntPatch_ImpImpIntersection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntPatch_ImpImpIntersection.def_static("operator delete_", (void (*)(void *, void *)) &IntPatch_ImpImpIntersection::operator delete, "None", py::arg(""), py::arg(""));
cls_IntPatch_ImpImpIntersection.def("Perform", [](IntPatch_ImpImpIntersection &self, const opencascade::handle<Adaptor3d_HSurface> & a0, const opencascade::handle<Adaptor3d_TopolTool> & a1, const opencascade::handle<Adaptor3d_HSurface> & a2, const opencascade::handle<Adaptor3d_TopolTool> & a3, const Standard_Real a4, const Standard_Real a5) -> void { return self.Perform(a0, a1, a2, a3, a4, a5); });
cls_IntPatch_ImpImpIntersection.def("Perform", (void (IntPatch_ImpImpIntersection::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &IntPatch_ImpImpIntersection::Perform, "Flag theIsReqToKeepRLine has been entered only for compatibility with TopOpeBRep package. It shall be deleted after deleting TopOpeBRep. When intersection result returns IntPatch_RLine and another IntPatch_Line (not restriction) we (in case of theIsReqToKeepRLine==TRUE) will always keep both lines even if they are coincided.", py::arg("S1"), py::arg("D1"), py::arg("S2"), py::arg("D2"), py::arg("TolArc"), py::arg("TolTang"), py::arg("theIsReqToKeepRLine"));
cls_IntPatch_ImpImpIntersection.def("IsDone", (Standard_Boolean (IntPatch_ImpImpIntersection::*)() const) &IntPatch_ImpImpIntersection::IsDone, "Returns True if the calculus was successful.");
cls_IntPatch_ImpImpIntersection.def("GetStatus", (IntPatch_ImpImpIntersection::IntStatus (IntPatch_ImpImpIntersection::*)() const) &IntPatch_ImpImpIntersection::GetStatus, "Returns status");
cls_IntPatch_ImpImpIntersection.def("IsEmpty", (Standard_Boolean (IntPatch_ImpImpIntersection::*)() const) &IntPatch_ImpImpIntersection::IsEmpty, "Returns true if the is no intersection.");
cls_IntPatch_ImpImpIntersection.def("TangentFaces", (Standard_Boolean (IntPatch_ImpImpIntersection::*)() const) &IntPatch_ImpImpIntersection::TangentFaces, "Returns True if the two patches are considered as entirely tangent, i.e every restriction arc of one patch is inside the geometric base of the other patch.");
cls_IntPatch_ImpImpIntersection.def("OppositeFaces", (Standard_Boolean (IntPatch_ImpImpIntersection::*)() const) &IntPatch_ImpImpIntersection::OppositeFaces, "Returns True when the TangentFaces returns True and the normal vectors evaluated at a point on the first and the second surface are opposite. The exception DomainError is raised if TangentFaces returns False.");
cls_IntPatch_ImpImpIntersection.def("NbPnts", (Standard_Integer (IntPatch_ImpImpIntersection::*)() const) &IntPatch_ImpImpIntersection::NbPnts, "Returns the number of 'single' points.");
cls_IntPatch_ImpImpIntersection.def("Point", (const IntPatch_Point & (IntPatch_ImpImpIntersection::*)(const Standard_Integer) const) &IntPatch_ImpImpIntersection::Point, "Returns the point of range Index. An exception is raised if Index<=0 or Index>NbPnt.", py::arg("Index"));
cls_IntPatch_ImpImpIntersection.def("NbLines", (Standard_Integer (IntPatch_ImpImpIntersection::*)() const) &IntPatch_ImpImpIntersection::NbLines, "Returns the number of intersection lines.");
cls_IntPatch_ImpImpIntersection.def("Line", (const opencascade::handle<IntPatch_Line> & (IntPatch_ImpImpIntersection::*)(const Standard_Integer) const) &IntPatch_ImpImpIntersection::Line, "Returns the line of range Index. An exception is raised if Index<=0 or Index>NbLine.", py::arg("Index"));

// Enums
py::enum_<IntPatch_ImpImpIntersection::IntStatus>(cls_IntPatch_ImpImpIntersection, "IntStatus", "None")
	.value("IntStatus_OK", IntPatch_ImpImpIntersection::IntStatus::IntStatus_OK)
	.value("IntStatus_InfiniteSectionCurve", IntPatch_ImpImpIntersection::IntStatus::IntStatus_InfiniteSectionCurve)
	.value("IntStatus_Fail", IntPatch_ImpImpIntersection::IntStatus::IntStatus_Fail)
	.export_values();

}