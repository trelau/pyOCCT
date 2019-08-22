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
#include <Adaptor2d_HCurve2d.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <Approx_Curve2d.hxx>

void bind_Approx_Curve2d(py::module &mod){

py::class_<Approx_Curve2d> cls_Approx_Curve2d(mod, "Approx_Curve2d", "Makes an approximation for HCurve2d from Adaptor3d");

// Constructors
cls_Approx_Curve2d.def(py::init<const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer>(), py::arg("C2D"), py::arg("First"), py::arg("Last"), py::arg("TolU"), py::arg("TolV"), py::arg("Continuity"), py::arg("MaxDegree"), py::arg("MaxSegments"));

// Fields

// Methods
// cls_Approx_Curve2d.def_static("operator new_", (void * (*)(size_t)) &Approx_Curve2d::operator new, "None", py::arg("theSize"));
// cls_Approx_Curve2d.def_static("operator delete_", (void (*)(void *)) &Approx_Curve2d::operator delete, "None", py::arg("theAddress"));
// cls_Approx_Curve2d.def_static("operator new[]_", (void * (*)(size_t)) &Approx_Curve2d::operator new[], "None", py::arg("theSize"));
// cls_Approx_Curve2d.def_static("operator delete[]_", (void (*)(void *)) &Approx_Curve2d::operator delete[], "None", py::arg("theAddress"));
// cls_Approx_Curve2d.def_static("operator new_", (void * (*)(size_t, void *)) &Approx_Curve2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Approx_Curve2d.def_static("operator delete_", (void (*)(void *, void *)) &Approx_Curve2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Approx_Curve2d.def("IsDone", (Standard_Boolean (Approx_Curve2d::*)() const) &Approx_Curve2d::IsDone, "None");
cls_Approx_Curve2d.def("HasResult", (Standard_Boolean (Approx_Curve2d::*)() const) &Approx_Curve2d::HasResult, "None");
cls_Approx_Curve2d.def("Curve", (opencascade::handle<Geom2d_BSplineCurve> (Approx_Curve2d::*)() const) &Approx_Curve2d::Curve, "None");
cls_Approx_Curve2d.def("MaxError2dU", (Standard_Real (Approx_Curve2d::*)() const) &Approx_Curve2d::MaxError2dU, "None");
cls_Approx_Curve2d.def("MaxError2dV", (Standard_Real (Approx_Curve2d::*)() const) &Approx_Curve2d::MaxError2dV, "None");

// Enums

}