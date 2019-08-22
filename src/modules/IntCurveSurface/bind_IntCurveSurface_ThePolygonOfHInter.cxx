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
#include <Adaptor3d_HCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Bnd_Box.hxx>
#include <gp_Pnt.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <IntCurveSurface_ThePolygonOfHInter.hxx>

void bind_IntCurveSurface_ThePolygonOfHInter(py::module &mod){

py::class_<IntCurveSurface_ThePolygonOfHInter> cls_IntCurveSurface_ThePolygonOfHInter(mod, "IntCurveSurface_ThePolygonOfHInter", "None");

// Constructors
cls_IntCurveSurface_ThePolygonOfHInter.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Integer>(), py::arg("Curve"), py::arg("NbPnt"));
cls_IntCurveSurface_ThePolygonOfHInter.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Curve"), py::arg("U1"), py::arg("U2"), py::arg("NbPnt"));
cls_IntCurveSurface_ThePolygonOfHInter.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const TColStd_Array1OfReal &>(), py::arg("Curve"), py::arg("Upars"));

// Fields

// Methods
// cls_IntCurveSurface_ThePolygonOfHInter.def_static("operator new_", (void * (*)(size_t)) &IntCurveSurface_ThePolygonOfHInter::operator new, "None", py::arg("theSize"));
// cls_IntCurveSurface_ThePolygonOfHInter.def_static("operator delete_", (void (*)(void *)) &IntCurveSurface_ThePolygonOfHInter::operator delete, "None", py::arg("theAddress"));
// cls_IntCurveSurface_ThePolygonOfHInter.def_static("operator new[]_", (void * (*)(size_t)) &IntCurveSurface_ThePolygonOfHInter::operator new[], "None", py::arg("theSize"));
// cls_IntCurveSurface_ThePolygonOfHInter.def_static("operator delete[]_", (void (*)(void *)) &IntCurveSurface_ThePolygonOfHInter::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurveSurface_ThePolygonOfHInter.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurveSurface_ThePolygonOfHInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurveSurface_ThePolygonOfHInter.def_static("operator delete_", (void (*)(void *, void *)) &IntCurveSurface_ThePolygonOfHInter::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurveSurface_ThePolygonOfHInter.def("Bounding", (const Bnd_Box & (IntCurveSurface_ThePolygonOfHInter::*)() const) &IntCurveSurface_ThePolygonOfHInter::Bounding, "Give the bounding box of the polygon.");
cls_IntCurveSurface_ThePolygonOfHInter.def("DeflectionOverEstimation", (Standard_Real (IntCurveSurface_ThePolygonOfHInter::*)() const) &IntCurveSurface_ThePolygonOfHInter::DeflectionOverEstimation, "None");
cls_IntCurveSurface_ThePolygonOfHInter.def("SetDeflectionOverEstimation", (void (IntCurveSurface_ThePolygonOfHInter::*)(const Standard_Real)) &IntCurveSurface_ThePolygonOfHInter::SetDeflectionOverEstimation, "None", py::arg("x"));
cls_IntCurveSurface_ThePolygonOfHInter.def("Closed", (void (IntCurveSurface_ThePolygonOfHInter::*)(const Standard_Boolean)) &IntCurveSurface_ThePolygonOfHInter::Closed, "None", py::arg("clos"));
cls_IntCurveSurface_ThePolygonOfHInter.def("Closed", (Standard_Boolean (IntCurveSurface_ThePolygonOfHInter::*)() const) &IntCurveSurface_ThePolygonOfHInter::Closed, "None");
cls_IntCurveSurface_ThePolygonOfHInter.def("NbSegments", (Standard_Integer (IntCurveSurface_ThePolygonOfHInter::*)() const) &IntCurveSurface_ThePolygonOfHInter::NbSegments, "Give the number of Segments in the polyline.");
cls_IntCurveSurface_ThePolygonOfHInter.def("BeginOfSeg", (const gp_Pnt & (IntCurveSurface_ThePolygonOfHInter::*)(const Standard_Integer) const) &IntCurveSurface_ThePolygonOfHInter::BeginOfSeg, "Give the point of range Index in the Polygon.", py::arg("Index"));
cls_IntCurveSurface_ThePolygonOfHInter.def("EndOfSeg", (const gp_Pnt & (IntCurveSurface_ThePolygonOfHInter::*)(const Standard_Integer) const) &IntCurveSurface_ThePolygonOfHInter::EndOfSeg, "Give the point of range Index in the Polygon.", py::arg("Index"));
cls_IntCurveSurface_ThePolygonOfHInter.def("InfParameter", (Standard_Real (IntCurveSurface_ThePolygonOfHInter::*)() const) &IntCurveSurface_ThePolygonOfHInter::InfParameter, "Returns the parameter (On the curve) of the first point of the Polygon");
cls_IntCurveSurface_ThePolygonOfHInter.def("SupParameter", (Standard_Real (IntCurveSurface_ThePolygonOfHInter::*)() const) &IntCurveSurface_ThePolygonOfHInter::SupParameter, "Returns the parameter (On the curve) of the last point of the Polygon");
cls_IntCurveSurface_ThePolygonOfHInter.def("ApproxParamOnCurve", (Standard_Real (IntCurveSurface_ThePolygonOfHInter::*)(const Standard_Integer, const Standard_Real) const) &IntCurveSurface_ThePolygonOfHInter::ApproxParamOnCurve, "Give an approximation of the parameter on the curve according to the discretization of the Curve.", py::arg("Index"), py::arg("ParamOnLine"));
cls_IntCurveSurface_ThePolygonOfHInter.def("Dump", (void (IntCurveSurface_ThePolygonOfHInter::*)() const) &IntCurveSurface_ThePolygonOfHInter::Dump, "None");

// Enums

}