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
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HVertex.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <IntPatch_ThePathPointOfTheSOnBounds.hxx>

void bind_IntPatch_ThePathPointOfTheSOnBounds(py::module &mod){

py::class_<IntPatch_ThePathPointOfTheSOnBounds, std::unique_ptr<IntPatch_ThePathPointOfTheSOnBounds>> cls_IntPatch_ThePathPointOfTheSOnBounds(mod, "IntPatch_ThePathPointOfTheSOnBounds", "None");

// Constructors
cls_IntPatch_ThePathPointOfTheSOnBounds.def(py::init<>());
cls_IntPatch_ThePathPointOfTheSOnBounds.def(py::init<const gp_Pnt &, const Standard_Real, const opencascade::handle<Adaptor3d_HVertex> &, const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real>(), py::arg("P"), py::arg("Tol"), py::arg("V"), py::arg("A"), py::arg("Parameter"));
cls_IntPatch_ThePathPointOfTheSOnBounds.def(py::init<const gp_Pnt &, const Standard_Real, const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real>(), py::arg("P"), py::arg("Tol"), py::arg("A"), py::arg("Parameter"));

// Fields

// Methods
// cls_IntPatch_ThePathPointOfTheSOnBounds.def_static("operator new_", (void * (*)(size_t)) &IntPatch_ThePathPointOfTheSOnBounds::operator new, "None", py::arg("theSize"));
// cls_IntPatch_ThePathPointOfTheSOnBounds.def_static("operator delete_", (void (*)(void *)) &IntPatch_ThePathPointOfTheSOnBounds::operator delete, "None", py::arg("theAddress"));
// cls_IntPatch_ThePathPointOfTheSOnBounds.def_static("operator new[]_", (void * (*)(size_t)) &IntPatch_ThePathPointOfTheSOnBounds::operator new[], "None", py::arg("theSize"));
// cls_IntPatch_ThePathPointOfTheSOnBounds.def_static("operator delete[]_", (void (*)(void *)) &IntPatch_ThePathPointOfTheSOnBounds::operator delete[], "None", py::arg("theAddress"));
// cls_IntPatch_ThePathPointOfTheSOnBounds.def_static("operator new_", (void * (*)(size_t, void *)) &IntPatch_ThePathPointOfTheSOnBounds::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntPatch_ThePathPointOfTheSOnBounds.def_static("operator delete_", (void (*)(void *, void *)) &IntPatch_ThePathPointOfTheSOnBounds::operator delete, "None", py::arg(""), py::arg(""));
cls_IntPatch_ThePathPointOfTheSOnBounds.def("SetValue", (void (IntPatch_ThePathPointOfTheSOnBounds::*)(const gp_Pnt &, const Standard_Real, const opencascade::handle<Adaptor3d_HVertex> &, const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real)) &IntPatch_ThePathPointOfTheSOnBounds::SetValue, "None", py::arg("P"), py::arg("Tol"), py::arg("V"), py::arg("A"), py::arg("Parameter"));
cls_IntPatch_ThePathPointOfTheSOnBounds.def("SetValue", (void (IntPatch_ThePathPointOfTheSOnBounds::*)(const gp_Pnt &, const Standard_Real, const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real)) &IntPatch_ThePathPointOfTheSOnBounds::SetValue, "None", py::arg("P"), py::arg("Tol"), py::arg("A"), py::arg("Parameter"));
cls_IntPatch_ThePathPointOfTheSOnBounds.def("Value", (const gp_Pnt & (IntPatch_ThePathPointOfTheSOnBounds::*)() const) &IntPatch_ThePathPointOfTheSOnBounds::Value, "None");
cls_IntPatch_ThePathPointOfTheSOnBounds.def("Tolerance", (Standard_Real (IntPatch_ThePathPointOfTheSOnBounds::*)() const) &IntPatch_ThePathPointOfTheSOnBounds::Tolerance, "None");
cls_IntPatch_ThePathPointOfTheSOnBounds.def("IsNew", (Standard_Boolean (IntPatch_ThePathPointOfTheSOnBounds::*)() const) &IntPatch_ThePathPointOfTheSOnBounds::IsNew, "None");
cls_IntPatch_ThePathPointOfTheSOnBounds.def("Vertex", (const opencascade::handle<Adaptor3d_HVertex> & (IntPatch_ThePathPointOfTheSOnBounds::*)() const) &IntPatch_ThePathPointOfTheSOnBounds::Vertex, "None");
cls_IntPatch_ThePathPointOfTheSOnBounds.def("Arc", (const opencascade::handle<Adaptor2d_HCurve2d> & (IntPatch_ThePathPointOfTheSOnBounds::*)() const) &IntPatch_ThePathPointOfTheSOnBounds::Arc, "None");
cls_IntPatch_ThePathPointOfTheSOnBounds.def("Parameter", (Standard_Real (IntPatch_ThePathPointOfTheSOnBounds::*)() const) &IntPatch_ThePathPointOfTheSOnBounds::Parameter, "None");

// Enums

}