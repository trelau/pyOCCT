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
#include <gp_Lin.hxx>
#include <IntRes2d_IntersectionPoint.hxx>
#include <IntCurveSurface_IntersectionPoint.hxx>
#include <IntRes2d_IntersectionSegment.hxx>
#include <IntCurveSurface_IntersectionSegment.hxx>
#include <HLRBRep_CInter.hxx>
#include <HLRBRep_InterCSurf.hxx>
#include <HLRBRep_ThePolyhedronOfInterCSurf.hxx>
#include <HLRBRep_Intersector.hxx>

void bind_HLRBRep_Intersector(py::module &mod){

py::class_<HLRBRep_Intersector, std::unique_ptr<HLRBRep_Intersector, Deleter<HLRBRep_Intersector>>> cls_HLRBRep_Intersector(mod, "HLRBRep_Intersector", "The Intersector computes 2D intersections of the projections of 3D curves.");

// Constructors
cls_HLRBRep_Intersector.def(py::init<>());

// Fields

// Methods
// cls_HLRBRep_Intersector.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_Intersector::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_Intersector.def_static("operator delete_", (void (*)(void *)) &HLRBRep_Intersector::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_Intersector.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_Intersector::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_Intersector.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_Intersector::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_Intersector.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_Intersector::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_Intersector.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_Intersector::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_Intersector.def("Perform", (void (HLRBRep_Intersector::*)(const Standard_Address, const Standard_Real, const Standard_Real)) &HLRBRep_Intersector::Perform, "Performs the auto intersection of an edge. The edge domain is cutted at start with da1*(b-a) and at end with db1*(b-a).", py::arg("A1"), py::arg("da1"), py::arg("db1"));
cls_HLRBRep_Intersector.def("Perform", (void (HLRBRep_Intersector::*)(const Standard_Integer, const Standard_Address, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Address, const Standard_Real, const Standard_Real, const Standard_Boolean)) &HLRBRep_Intersector::Perform, "Performs the intersection between the two edges. The edges domains are cutted at start with da*(b-a) and at end with db*(b-a).", py::arg("nA"), py::arg("A1"), py::arg("da1"), py::arg("db1"), py::arg("nB"), py::arg("A2"), py::arg("da2"), py::arg("db2"), py::arg("NoBound"));
cls_HLRBRep_Intersector.def("SimulateOnePoint", (void (HLRBRep_Intersector::*)(const Standard_Address, const Standard_Real, const Standard_Address, const Standard_Real)) &HLRBRep_Intersector::SimulateOnePoint, "Create a single IntersectionPoint (U on A1) (V on A2) The point is middle on both curves.", py::arg("A1"), py::arg("U"), py::arg("A2"), py::arg("V"));
cls_HLRBRep_Intersector.def("Load", (void (HLRBRep_Intersector::*)(Standard_Address &)) &HLRBRep_Intersector::Load, "None", py::arg("A"));
cls_HLRBRep_Intersector.def("Perform", (void (HLRBRep_Intersector::*)(const gp_Lin &, const Standard_Real)) &HLRBRep_Intersector::Perform, "None", py::arg("L"), py::arg("P"));
cls_HLRBRep_Intersector.def("IsDone", (Standard_Boolean (HLRBRep_Intersector::*)() const) &HLRBRep_Intersector::IsDone, "None");
cls_HLRBRep_Intersector.def("NbPoints", (Standard_Integer (HLRBRep_Intersector::*)() const) &HLRBRep_Intersector::NbPoints, "None");
cls_HLRBRep_Intersector.def("Point", (const IntRes2d_IntersectionPoint & (HLRBRep_Intersector::*)(const Standard_Integer) const) &HLRBRep_Intersector::Point, "None", py::arg("N"));
cls_HLRBRep_Intersector.def("CSPoint", (const IntCurveSurface_IntersectionPoint & (HLRBRep_Intersector::*)(const Standard_Integer) const) &HLRBRep_Intersector::CSPoint, "None", py::arg("N"));
cls_HLRBRep_Intersector.def("NbSegments", (Standard_Integer (HLRBRep_Intersector::*)() const) &HLRBRep_Intersector::NbSegments, "None");
cls_HLRBRep_Intersector.def("Segment", (const IntRes2d_IntersectionSegment & (HLRBRep_Intersector::*)(const Standard_Integer) const) &HLRBRep_Intersector::Segment, "None", py::arg("N"));
cls_HLRBRep_Intersector.def("CSSegment", (const IntCurveSurface_IntersectionSegment & (HLRBRep_Intersector::*)(const Standard_Integer) const) &HLRBRep_Intersector::CSSegment, "None", py::arg("N"));
cls_HLRBRep_Intersector.def("Destroy", (void (HLRBRep_Intersector::*)()) &HLRBRep_Intersector::Destroy, "None");

// Enums

}