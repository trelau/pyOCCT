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
#include <Geom2d_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <Standard_OStream.hxx>
#include <Geom2dConvert_ApproxCurve.hxx>

void bind_Geom2dConvert_ApproxCurve(py::module &mod){

py::class_<Geom2dConvert_ApproxCurve, std::unique_ptr<Geom2dConvert_ApproxCurve, Deleter<Geom2dConvert_ApproxCurve>>> cls_Geom2dConvert_ApproxCurve(mod, "Geom2dConvert_ApproxCurve", "A framework to convert a 2D curve to a BSpline. This is done by approximation within a given tolerance.");

// Constructors
cls_Geom2dConvert_ApproxCurve.def(py::init<const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer>(), py::arg("Curve"), py::arg("Tol2d"), py::arg("Order"), py::arg("MaxSegments"), py::arg("MaxDegree"));
cls_Geom2dConvert_ApproxCurve.def(py::init<const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer>(), py::arg("Curve"), py::arg("Tol2d"), py::arg("Order"), py::arg("MaxSegments"), py::arg("MaxDegree"));

// Fields

// Methods
// cls_Geom2dConvert_ApproxCurve.def_static("operator new_", (void * (*)(size_t)) &Geom2dConvert_ApproxCurve::operator new, "None", py::arg("theSize"));
// cls_Geom2dConvert_ApproxCurve.def_static("operator delete_", (void (*)(void *)) &Geom2dConvert_ApproxCurve::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dConvert_ApproxCurve.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dConvert_ApproxCurve::operator new[], "None", py::arg("theSize"));
// cls_Geom2dConvert_ApproxCurve.def_static("operator delete[]_", (void (*)(void *)) &Geom2dConvert_ApproxCurve::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dConvert_ApproxCurve.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dConvert_ApproxCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dConvert_ApproxCurve.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dConvert_ApproxCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dConvert_ApproxCurve.def("Curve", (opencascade::handle<Geom2d_BSplineCurve> (Geom2dConvert_ApproxCurve::*)() const) &Geom2dConvert_ApproxCurve::Curve, "Returns the 2D BSpline curve resulting from the approximation algorithm.");
cls_Geom2dConvert_ApproxCurve.def("IsDone", (Standard_Boolean (Geom2dConvert_ApproxCurve::*)() const) &Geom2dConvert_ApproxCurve::IsDone, "returns Standard_True if the approximation has been done with within requiered tolerance");
cls_Geom2dConvert_ApproxCurve.def("HasResult", (Standard_Boolean (Geom2dConvert_ApproxCurve::*)() const) &Geom2dConvert_ApproxCurve::HasResult, "returns Standard_True if the approximation did come out with a result that is not NECESSARELY within the required tolerance");
cls_Geom2dConvert_ApproxCurve.def("MaxError", (Standard_Real (Geom2dConvert_ApproxCurve::*)() const) &Geom2dConvert_ApproxCurve::MaxError, "Returns the greatest distance between a point on the source conic and the BSpline curve resulting from the approximation. (>0 when an approximation has been done, 0 if no approximation)");
cls_Geom2dConvert_ApproxCurve.def("Dump", (void (Geom2dConvert_ApproxCurve::*)(Standard_OStream &) const) &Geom2dConvert_ApproxCurve::Dump, "Print on the stream o information about the object", py::arg("o"));

// Enums

}