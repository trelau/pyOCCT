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
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Lin.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <gp_Pnt.hxx>
#include <IntCurveSurface_TransitionOnCurve.hxx>
#include <TopAbs_State.hxx>
#include <TopoDS_Face.hxx>
#include <BRepTopAdaptor_SeqOfPtr.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <IntCurvesFace_ShapeIntersector.hxx>

void bind_IntCurvesFace_ShapeIntersector(py::module &mod){

py::class_<IntCurvesFace_ShapeIntersector> cls_IntCurvesFace_ShapeIntersector(mod, "IntCurvesFace_ShapeIntersector", "None");

// Constructors
cls_IntCurvesFace_ShapeIntersector.def(py::init<>());

// Fields

// Methods
// cls_IntCurvesFace_ShapeIntersector.def_static("operator new_", (void * (*)(size_t)) &IntCurvesFace_ShapeIntersector::operator new, "None", py::arg("theSize"));
// cls_IntCurvesFace_ShapeIntersector.def_static("operator delete_", (void (*)(void *)) &IntCurvesFace_ShapeIntersector::operator delete, "None", py::arg("theAddress"));
// cls_IntCurvesFace_ShapeIntersector.def_static("operator new[]_", (void * (*)(size_t)) &IntCurvesFace_ShapeIntersector::operator new[], "None", py::arg("theSize"));
// cls_IntCurvesFace_ShapeIntersector.def_static("operator delete[]_", (void (*)(void *)) &IntCurvesFace_ShapeIntersector::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurvesFace_ShapeIntersector.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurvesFace_ShapeIntersector::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurvesFace_ShapeIntersector.def_static("operator delete_", (void (*)(void *, void *)) &IntCurvesFace_ShapeIntersector::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurvesFace_ShapeIntersector.def("Load", (void (IntCurvesFace_ShapeIntersector::*)(const TopoDS_Shape &, const Standard_Real)) &IntCurvesFace_ShapeIntersector::Load, "None", py::arg("Sh"), py::arg("Tol"));
cls_IntCurvesFace_ShapeIntersector.def("Perform", (void (IntCurvesFace_ShapeIntersector::*)(const gp_Lin &, const Standard_Real, const Standard_Real)) &IntCurvesFace_ShapeIntersector::Perform, "Perform the intersection between the segment L and the loaded shape.", py::arg("L"), py::arg("PInf"), py::arg("PSup"));
cls_IntCurvesFace_ShapeIntersector.def("PerformNearest", (void (IntCurvesFace_ShapeIntersector::*)(const gp_Lin &, const Standard_Real, const Standard_Real)) &IntCurvesFace_ShapeIntersector::PerformNearest, "Perform the intersection between the segment L and the loaded shape.", py::arg("L"), py::arg("PInf"), py::arg("PSup"));
cls_IntCurvesFace_ShapeIntersector.def("Perform", (void (IntCurvesFace_ShapeIntersector::*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, const Standard_Real)) &IntCurvesFace_ShapeIntersector::Perform, "same method for a HCurve from Adaptor3d. PInf an PSup can also be - and + INF.", py::arg("HCu"), py::arg("PInf"), py::arg("PSup"));
cls_IntCurvesFace_ShapeIntersector.def("IsDone", (Standard_Boolean (IntCurvesFace_ShapeIntersector::*)() const) &IntCurvesFace_ShapeIntersector::IsDone, "True is returned when the intersection have been computed.");
cls_IntCurvesFace_ShapeIntersector.def("NbPnt", (Standard_Integer (IntCurvesFace_ShapeIntersector::*)() const) &IntCurvesFace_ShapeIntersector::NbPnt, "None");
cls_IntCurvesFace_ShapeIntersector.def("UParameter", (Standard_Real (IntCurvesFace_ShapeIntersector::*)(const Standard_Integer) const) &IntCurvesFace_ShapeIntersector::UParameter, "Returns the U parameter of the ith intersection point on the surface.", py::arg("I"));
cls_IntCurvesFace_ShapeIntersector.def("VParameter", (Standard_Real (IntCurvesFace_ShapeIntersector::*)(const Standard_Integer) const) &IntCurvesFace_ShapeIntersector::VParameter, "Returns the V parameter of the ith intersection point on the surface.", py::arg("I"));
cls_IntCurvesFace_ShapeIntersector.def("WParameter", (Standard_Real (IntCurvesFace_ShapeIntersector::*)(const Standard_Integer) const) &IntCurvesFace_ShapeIntersector::WParameter, "Returns the parameter of the ith intersection point on the line.", py::arg("I"));
cls_IntCurvesFace_ShapeIntersector.def("Pnt", (const gp_Pnt & (IntCurvesFace_ShapeIntersector::*)(const Standard_Integer) const) &IntCurvesFace_ShapeIntersector::Pnt, "Returns the geometric point of the ith intersection between the line and the surface.", py::arg("I"));
cls_IntCurvesFace_ShapeIntersector.def("Transition", (IntCurveSurface_TransitionOnCurve (IntCurvesFace_ShapeIntersector::*)(const Standard_Integer) const) &IntCurvesFace_ShapeIntersector::Transition, "Returns the ith transition of the line on the surface.", py::arg("I"));
cls_IntCurvesFace_ShapeIntersector.def("State", (TopAbs_State (IntCurvesFace_ShapeIntersector::*)(const Standard_Integer) const) &IntCurvesFace_ShapeIntersector::State, "Returns the ith state of the point on the face. The values can be either TopAbs_IN ( the point is in the face) or TopAbs_ON ( the point is on a boudary of the face).", py::arg("I"));
cls_IntCurvesFace_ShapeIntersector.def("Face", (const TopoDS_Face & (IntCurvesFace_ShapeIntersector::*)(const Standard_Integer) const) &IntCurvesFace_ShapeIntersector::Face, "Returns the significant face used to determine the intersection.", py::arg("I"));
cls_IntCurvesFace_ShapeIntersector.def("SortResult", (void (IntCurvesFace_ShapeIntersector::*)()) &IntCurvesFace_ShapeIntersector::SortResult, "Internal method. Sort the result on the Curve parameter.");
cls_IntCurvesFace_ShapeIntersector.def("Destroy", (void (IntCurvesFace_ShapeIntersector::*)()) &IntCurvesFace_ShapeIntersector::Destroy, "None");

// Enums

}