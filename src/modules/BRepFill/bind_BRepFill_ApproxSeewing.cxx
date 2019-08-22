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
#include <BRepFill_MultiLine.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <Geom2d_Curve.hxx>
#include <BRepFill_ApproxSeewing.hxx>

void bind_BRepFill_ApproxSeewing(py::module &mod){

py::class_<BRepFill_ApproxSeewing> cls_BRepFill_ApproxSeewing(mod, "BRepFill_ApproxSeewing", "Evaluate the 3dCurve and the PCurves described in a MultiLine from BRepFill. The parametrization of those curves is not imposed by the Bissectrice. The parametrization is given approximatively by the abscissa of the curve3d.");

// Constructors
cls_BRepFill_ApproxSeewing.def(py::init<>());
cls_BRepFill_ApproxSeewing.def(py::init<const BRepFill_MultiLine &>(), py::arg("ML"));

// Fields

// Methods
// cls_BRepFill_ApproxSeewing.def_static("operator new_", (void * (*)(size_t)) &BRepFill_ApproxSeewing::operator new, "None", py::arg("theSize"));
// cls_BRepFill_ApproxSeewing.def_static("operator delete_", (void (*)(void *)) &BRepFill_ApproxSeewing::operator delete, "None", py::arg("theAddress"));
// cls_BRepFill_ApproxSeewing.def_static("operator new[]_", (void * (*)(size_t)) &BRepFill_ApproxSeewing::operator new[], "None", py::arg("theSize"));
// cls_BRepFill_ApproxSeewing.def_static("operator delete[]_", (void (*)(void *)) &BRepFill_ApproxSeewing::operator delete[], "None", py::arg("theAddress"));
// cls_BRepFill_ApproxSeewing.def_static("operator new_", (void * (*)(size_t, void *)) &BRepFill_ApproxSeewing::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepFill_ApproxSeewing.def_static("operator delete_", (void (*)(void *, void *)) &BRepFill_ApproxSeewing::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepFill_ApproxSeewing.def("Perform", (void (BRepFill_ApproxSeewing::*)(const BRepFill_MultiLine &)) &BRepFill_ApproxSeewing::Perform, "None", py::arg("ML"));
cls_BRepFill_ApproxSeewing.def("IsDone", (Standard_Boolean (BRepFill_ApproxSeewing::*)() const) &BRepFill_ApproxSeewing::IsDone, "None");
cls_BRepFill_ApproxSeewing.def("Curve", (const opencascade::handle<Geom_Curve> & (BRepFill_ApproxSeewing::*)() const) &BRepFill_ApproxSeewing::Curve, "returns the approximation of the 3d Curve");
cls_BRepFill_ApproxSeewing.def("CurveOnF1", (const opencascade::handle<Geom2d_Curve> & (BRepFill_ApproxSeewing::*)() const) &BRepFill_ApproxSeewing::CurveOnF1, "returns the approximation of the PCurve on the first face of the MultiLine");
cls_BRepFill_ApproxSeewing.def("CurveOnF2", (const opencascade::handle<Geom2d_Curve> & (BRepFill_ApproxSeewing::*)() const) &BRepFill_ApproxSeewing::CurveOnF2, "returns the approximation of the PCurve on the first face of the MultiLine");

// Enums

}