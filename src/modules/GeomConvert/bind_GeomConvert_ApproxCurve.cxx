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
#include <Geom_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <Geom_BSplineCurve.hxx>
#include <Standard_OStream.hxx>
#include <GeomConvert_ApproxCurve.hxx>

void bind_GeomConvert_ApproxCurve(py::module &mod){

py::class_<GeomConvert_ApproxCurve> cls_GeomConvert_ApproxCurve(mod, "GeomConvert_ApproxCurve", "A framework to convert a 3D curve to a 3D BSpline. This is done by approximation to a BSpline curve within a given tolerance.");

// Constructors
cls_GeomConvert_ApproxCurve.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer>(), py::arg("Curve"), py::arg("Tol3d"), py::arg("Order"), py::arg("MaxSegments"), py::arg("MaxDegree"));
cls_GeomConvert_ApproxCurve.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer>(), py::arg("Curve"), py::arg("Tol3d"), py::arg("Order"), py::arg("MaxSegments"), py::arg("MaxDegree"));

// Fields

// Methods
// cls_GeomConvert_ApproxCurve.def_static("operator new_", (void * (*)(size_t)) &GeomConvert_ApproxCurve::operator new, "None", py::arg("theSize"));
// cls_GeomConvert_ApproxCurve.def_static("operator delete_", (void (*)(void *)) &GeomConvert_ApproxCurve::operator delete, "None", py::arg("theAddress"));
// cls_GeomConvert_ApproxCurve.def_static("operator new[]_", (void * (*)(size_t)) &GeomConvert_ApproxCurve::operator new[], "None", py::arg("theSize"));
// cls_GeomConvert_ApproxCurve.def_static("operator delete[]_", (void (*)(void *)) &GeomConvert_ApproxCurve::operator delete[], "None", py::arg("theAddress"));
// cls_GeomConvert_ApproxCurve.def_static("operator new_", (void * (*)(size_t, void *)) &GeomConvert_ApproxCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomConvert_ApproxCurve.def_static("operator delete_", (void (*)(void *, void *)) &GeomConvert_ApproxCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomConvert_ApproxCurve.def("Curve", (opencascade::handle<Geom_BSplineCurve> (GeomConvert_ApproxCurve::*)() const) &GeomConvert_ApproxCurve::Curve, "Returns the BSpline curve resulting from the approximation algorithm.");
cls_GeomConvert_ApproxCurve.def("IsDone", (Standard_Boolean (GeomConvert_ApproxCurve::*)() const) &GeomConvert_ApproxCurve::IsDone, "returns Standard_True if the approximation has been done within requiered tolerance");
cls_GeomConvert_ApproxCurve.def("HasResult", (Standard_Boolean (GeomConvert_ApproxCurve::*)() const) &GeomConvert_ApproxCurve::HasResult, "Returns Standard_True if the approximation did come out with a result that is not NECESSARELY within the required tolerance");
cls_GeomConvert_ApproxCurve.def("MaxError", (Standard_Real (GeomConvert_ApproxCurve::*)() const) &GeomConvert_ApproxCurve::MaxError, "Returns the greatest distance between a point on the source conic and the BSpline curve resulting from the approximation. (>0 when an approximation has been done, 0 if no approximation)");
cls_GeomConvert_ApproxCurve.def("Dump", (void (GeomConvert_ApproxCurve::*)(Standard_OStream &) const) &GeomConvert_ApproxCurve::Dump, "Print on the stream o information about the object", py::arg("o"));

// Enums

}