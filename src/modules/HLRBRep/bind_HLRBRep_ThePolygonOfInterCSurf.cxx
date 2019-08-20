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
#include <gp_Lin.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Bnd_Box.hxx>
#include <gp_Pnt.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <HLRBRep_ThePolygonOfInterCSurf.hxx>

void bind_HLRBRep_ThePolygonOfInterCSurf(py::module &mod){

py::class_<HLRBRep_ThePolygonOfInterCSurf, std::unique_ptr<HLRBRep_ThePolygonOfInterCSurf>> cls_HLRBRep_ThePolygonOfInterCSurf(mod, "HLRBRep_ThePolygonOfInterCSurf", "None");

// Constructors
cls_HLRBRep_ThePolygonOfInterCSurf.def(py::init<const gp_Lin &, const Standard_Integer>(), py::arg("Curve"), py::arg("NbPnt"));
cls_HLRBRep_ThePolygonOfInterCSurf.def(py::init<const gp_Lin &, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Curve"), py::arg("U1"), py::arg("U2"), py::arg("NbPnt"));
cls_HLRBRep_ThePolygonOfInterCSurf.def(py::init<const gp_Lin &, const TColStd_Array1OfReal &>(), py::arg("Curve"), py::arg("Upars"));

// Fields

// Methods
// cls_HLRBRep_ThePolygonOfInterCSurf.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_ThePolygonOfInterCSurf::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_ThePolygonOfInterCSurf.def_static("operator delete_", (void (*)(void *)) &HLRBRep_ThePolygonOfInterCSurf::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_ThePolygonOfInterCSurf.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_ThePolygonOfInterCSurf::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_ThePolygonOfInterCSurf.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_ThePolygonOfInterCSurf::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_ThePolygonOfInterCSurf.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_ThePolygonOfInterCSurf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_ThePolygonOfInterCSurf.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_ThePolygonOfInterCSurf::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_ThePolygonOfInterCSurf.def("Bounding", (const Bnd_Box & (HLRBRep_ThePolygonOfInterCSurf::*)() const) &HLRBRep_ThePolygonOfInterCSurf::Bounding, "Give the bounding box of the polygon.");
cls_HLRBRep_ThePolygonOfInterCSurf.def("DeflectionOverEstimation", (Standard_Real (HLRBRep_ThePolygonOfInterCSurf::*)() const) &HLRBRep_ThePolygonOfInterCSurf::DeflectionOverEstimation, "None");
cls_HLRBRep_ThePolygonOfInterCSurf.def("SetDeflectionOverEstimation", (void (HLRBRep_ThePolygonOfInterCSurf::*)(const Standard_Real)) &HLRBRep_ThePolygonOfInterCSurf::SetDeflectionOverEstimation, "None", py::arg("x"));
cls_HLRBRep_ThePolygonOfInterCSurf.def("Closed", (void (HLRBRep_ThePolygonOfInterCSurf::*)(const Standard_Boolean)) &HLRBRep_ThePolygonOfInterCSurf::Closed, "None", py::arg("clos"));
cls_HLRBRep_ThePolygonOfInterCSurf.def("Closed", (Standard_Boolean (HLRBRep_ThePolygonOfInterCSurf::*)() const) &HLRBRep_ThePolygonOfInterCSurf::Closed, "None");
cls_HLRBRep_ThePolygonOfInterCSurf.def("NbSegments", (Standard_Integer (HLRBRep_ThePolygonOfInterCSurf::*)() const) &HLRBRep_ThePolygonOfInterCSurf::NbSegments, "Give the number of Segments in the polyline.");
cls_HLRBRep_ThePolygonOfInterCSurf.def("BeginOfSeg", (const gp_Pnt & (HLRBRep_ThePolygonOfInterCSurf::*)(const Standard_Integer) const) &HLRBRep_ThePolygonOfInterCSurf::BeginOfSeg, "Give the point of range Index in the Polygon.", py::arg("Index"));
cls_HLRBRep_ThePolygonOfInterCSurf.def("EndOfSeg", (const gp_Pnt & (HLRBRep_ThePolygonOfInterCSurf::*)(const Standard_Integer) const) &HLRBRep_ThePolygonOfInterCSurf::EndOfSeg, "Give the point of range Index in the Polygon.", py::arg("Index"));
cls_HLRBRep_ThePolygonOfInterCSurf.def("InfParameter", (Standard_Real (HLRBRep_ThePolygonOfInterCSurf::*)() const) &HLRBRep_ThePolygonOfInterCSurf::InfParameter, "Returns the parameter (On the curve) of the first point of the Polygon");
cls_HLRBRep_ThePolygonOfInterCSurf.def("SupParameter", (Standard_Real (HLRBRep_ThePolygonOfInterCSurf::*)() const) &HLRBRep_ThePolygonOfInterCSurf::SupParameter, "Returns the parameter (On the curve) of the last point of the Polygon");
cls_HLRBRep_ThePolygonOfInterCSurf.def("ApproxParamOnCurve", (Standard_Real (HLRBRep_ThePolygonOfInterCSurf::*)(const Standard_Integer, const Standard_Real) const) &HLRBRep_ThePolygonOfInterCSurf::ApproxParamOnCurve, "Give an approximation of the parameter on the curve according to the discretization of the Curve.", py::arg("Index"), py::arg("ParamOnLine"));
cls_HLRBRep_ThePolygonOfInterCSurf.def("Dump", (void (HLRBRep_ThePolygonOfInterCSurf::*)() const) &HLRBRep_ThePolygonOfInterCSurf::Dump, "None");

// Enums

}