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
#include <Contap_ThePathPointOfTheSearch.hxx>

void bind_Contap_ThePathPointOfTheSearch(py::module &mod){

py::class_<Contap_ThePathPointOfTheSearch> cls_Contap_ThePathPointOfTheSearch(mod, "Contap_ThePathPointOfTheSearch", "None");

// Constructors
cls_Contap_ThePathPointOfTheSearch.def(py::init<>());
cls_Contap_ThePathPointOfTheSearch.def(py::init<const gp_Pnt &, const Standard_Real, const opencascade::handle<Adaptor3d_HVertex> &, const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real>(), py::arg("P"), py::arg("Tol"), py::arg("V"), py::arg("A"), py::arg("Parameter"));
cls_Contap_ThePathPointOfTheSearch.def(py::init<const gp_Pnt &, const Standard_Real, const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real>(), py::arg("P"), py::arg("Tol"), py::arg("A"), py::arg("Parameter"));

// Fields

// Methods
// cls_Contap_ThePathPointOfTheSearch.def_static("operator new_", (void * (*)(size_t)) &Contap_ThePathPointOfTheSearch::operator new, "None", py::arg("theSize"));
// cls_Contap_ThePathPointOfTheSearch.def_static("operator delete_", (void (*)(void *)) &Contap_ThePathPointOfTheSearch::operator delete, "None", py::arg("theAddress"));
// cls_Contap_ThePathPointOfTheSearch.def_static("operator new[]_", (void * (*)(size_t)) &Contap_ThePathPointOfTheSearch::operator new[], "None", py::arg("theSize"));
// cls_Contap_ThePathPointOfTheSearch.def_static("operator delete[]_", (void (*)(void *)) &Contap_ThePathPointOfTheSearch::operator delete[], "None", py::arg("theAddress"));
// cls_Contap_ThePathPointOfTheSearch.def_static("operator new_", (void * (*)(size_t, void *)) &Contap_ThePathPointOfTheSearch::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Contap_ThePathPointOfTheSearch.def_static("operator delete_", (void (*)(void *, void *)) &Contap_ThePathPointOfTheSearch::operator delete, "None", py::arg(""), py::arg(""));
cls_Contap_ThePathPointOfTheSearch.def("SetValue", (void (Contap_ThePathPointOfTheSearch::*)(const gp_Pnt &, const Standard_Real, const opencascade::handle<Adaptor3d_HVertex> &, const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real)) &Contap_ThePathPointOfTheSearch::SetValue, "None", py::arg("P"), py::arg("Tol"), py::arg("V"), py::arg("A"), py::arg("Parameter"));
cls_Contap_ThePathPointOfTheSearch.def("SetValue", (void (Contap_ThePathPointOfTheSearch::*)(const gp_Pnt &, const Standard_Real, const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real)) &Contap_ThePathPointOfTheSearch::SetValue, "None", py::arg("P"), py::arg("Tol"), py::arg("A"), py::arg("Parameter"));
cls_Contap_ThePathPointOfTheSearch.def("Value", (const gp_Pnt & (Contap_ThePathPointOfTheSearch::*)() const) &Contap_ThePathPointOfTheSearch::Value, "None");
cls_Contap_ThePathPointOfTheSearch.def("Tolerance", (Standard_Real (Contap_ThePathPointOfTheSearch::*)() const) &Contap_ThePathPointOfTheSearch::Tolerance, "None");
cls_Contap_ThePathPointOfTheSearch.def("IsNew", (Standard_Boolean (Contap_ThePathPointOfTheSearch::*)() const) &Contap_ThePathPointOfTheSearch::IsNew, "None");
cls_Contap_ThePathPointOfTheSearch.def("Vertex", (const opencascade::handle<Adaptor3d_HVertex> & (Contap_ThePathPointOfTheSearch::*)() const) &Contap_ThePathPointOfTheSearch::Vertex, "None");
cls_Contap_ThePathPointOfTheSearch.def("Arc", (const opencascade::handle<Adaptor2d_HCurve2d> & (Contap_ThePathPointOfTheSearch::*)() const) &Contap_ThePathPointOfTheSearch::Arc, "None");
cls_Contap_ThePathPointOfTheSearch.def("Parameter", (Standard_Real (Contap_ThePathPointOfTheSearch::*)() const) &Contap_ThePathPointOfTheSearch::Parameter, "None");

// Enums

}