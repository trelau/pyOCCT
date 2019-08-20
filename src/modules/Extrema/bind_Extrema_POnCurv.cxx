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
#include <gp_Pnt.hxx>
#include <Extrema_POnCurv.hxx>

void bind_Extrema_POnCurv(py::module &mod){

py::class_<Extrema_POnCurv, std::unique_ptr<Extrema_POnCurv>> cls_Extrema_POnCurv(mod, "Extrema_POnCurv", "None");

// Constructors
cls_Extrema_POnCurv.def(py::init<>());
cls_Extrema_POnCurv.def(py::init<const Standard_Real, const gp_Pnt &>(), py::arg("U"), py::arg("P"));

// Fields

// Methods
// cls_Extrema_POnCurv.def_static("operator new_", (void * (*)(size_t)) &Extrema_POnCurv::operator new, "None", py::arg("theSize"));
// cls_Extrema_POnCurv.def_static("operator delete_", (void (*)(void *)) &Extrema_POnCurv::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_POnCurv.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_POnCurv::operator new[], "None", py::arg("theSize"));
// cls_Extrema_POnCurv.def_static("operator delete[]_", (void (*)(void *)) &Extrema_POnCurv::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_POnCurv.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_POnCurv::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_POnCurv.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_POnCurv::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_POnCurv.def("SetValues", (void (Extrema_POnCurv::*)(const Standard_Real, const gp_Pnt &)) &Extrema_POnCurv::SetValues, "sets the point and parameter values.", py::arg("U"), py::arg("P"));
cls_Extrema_POnCurv.def("Value", (const gp_Pnt & (Extrema_POnCurv::*)() const) &Extrema_POnCurv::Value, "Returns the point.");
cls_Extrema_POnCurv.def("Parameter", (Standard_Real (Extrema_POnCurv::*)() const) &Extrema_POnCurv::Parameter, "Returns the parameter on the curve.");

// Enums

}