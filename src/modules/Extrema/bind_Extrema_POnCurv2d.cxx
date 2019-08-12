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
#include <gp_Pnt2d.hxx>
#include <Extrema_POnCurv2d.hxx>

void bind_Extrema_POnCurv2d(py::module &mod){

py::class_<Extrema_POnCurv2d, std::unique_ptr<Extrema_POnCurv2d, Deleter<Extrema_POnCurv2d>>> cls_Extrema_POnCurv2d(mod, "Extrema_POnCurv2d", "None");

// Constructors
cls_Extrema_POnCurv2d.def(py::init<>());
cls_Extrema_POnCurv2d.def(py::init<const Standard_Real, const gp_Pnt2d &>(), py::arg("U"), py::arg("P"));

// Fields

// Methods
// cls_Extrema_POnCurv2d.def_static("operator new_", (void * (*)(size_t)) &Extrema_POnCurv2d::operator new, "None", py::arg("theSize"));
// cls_Extrema_POnCurv2d.def_static("operator delete_", (void (*)(void *)) &Extrema_POnCurv2d::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_POnCurv2d.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_POnCurv2d::operator new[], "None", py::arg("theSize"));
// cls_Extrema_POnCurv2d.def_static("operator delete[]_", (void (*)(void *)) &Extrema_POnCurv2d::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_POnCurv2d.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_POnCurv2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_POnCurv2d.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_POnCurv2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_POnCurv2d.def("SetValues", (void (Extrema_POnCurv2d::*)(const Standard_Real, const gp_Pnt2d &)) &Extrema_POnCurv2d::SetValues, "sets the point and parameter values.", py::arg("U"), py::arg("P"));
cls_Extrema_POnCurv2d.def("Value", (const gp_Pnt2d & (Extrema_POnCurv2d::*)() const) &Extrema_POnCurv2d::Value, "Returns the point.");
cls_Extrema_POnCurv2d.def("Parameter", (Standard_Real (Extrema_POnCurv2d::*)() const) &Extrema_POnCurv2d::Parameter, "Returns the parameter on the curve.");

// Enums

}