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
#include <GeomAbs_Shape.hxx>
#include <Geom_BSplineCurve.hxx>
#include <Standard_OStream.hxx>
#include <Approx_Curve3d.hxx>

void bind_Approx_Curve3d(py::module &mod){

py::class_<Approx_Curve3d> cls_Approx_Curve3d(mod, "Approx_Curve3d", "None");

// Constructors
cls_Approx_Curve3d.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer>(), py::arg("Curve"), py::arg("Tol3d"), py::arg("Order"), py::arg("MaxSegments"), py::arg("MaxDegree"));

// Fields

// Methods
// cls_Approx_Curve3d.def_static("operator new_", (void * (*)(size_t)) &Approx_Curve3d::operator new, "None", py::arg("theSize"));
// cls_Approx_Curve3d.def_static("operator delete_", (void (*)(void *)) &Approx_Curve3d::operator delete, "None", py::arg("theAddress"));
// cls_Approx_Curve3d.def_static("operator new[]_", (void * (*)(size_t)) &Approx_Curve3d::operator new[], "None", py::arg("theSize"));
// cls_Approx_Curve3d.def_static("operator delete[]_", (void (*)(void *)) &Approx_Curve3d::operator delete[], "None", py::arg("theAddress"));
// cls_Approx_Curve3d.def_static("operator new_", (void * (*)(size_t, void *)) &Approx_Curve3d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Approx_Curve3d.def_static("operator delete_", (void (*)(void *, void *)) &Approx_Curve3d::operator delete, "None", py::arg(""), py::arg(""));
cls_Approx_Curve3d.def("Curve", (opencascade::handle<Geom_BSplineCurve> (Approx_Curve3d::*)() const) &Approx_Curve3d::Curve, "None");
cls_Approx_Curve3d.def("IsDone", (Standard_Boolean (Approx_Curve3d::*)() const) &Approx_Curve3d::IsDone, "returns Standard_True if the approximation has been done within requiered tolerance");
cls_Approx_Curve3d.def("HasResult", (Standard_Boolean (Approx_Curve3d::*)() const) &Approx_Curve3d::HasResult, "returns Standard_True if the approximation did come out with a result that is not NECESSARELY within the required tolerance");
cls_Approx_Curve3d.def("MaxError", (Standard_Real (Approx_Curve3d::*)() const) &Approx_Curve3d::MaxError, "returns the Maximum Error (>0 when an approximation has been done, 0 if no approximation)");
cls_Approx_Curve3d.def("Dump", (void (Approx_Curve3d::*)(Standard_OStream &) const) &Approx_Curve3d::Dump, "Print on the stream o information about the object", py::arg("o"));

// Enums

}