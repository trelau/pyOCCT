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
#include <TopAbs_Orientation.hxx>
#include <GeomInt_ParameterAndOrientation.hxx>

void bind_GeomInt_ParameterAndOrientation(py::module &mod){

py::class_<GeomInt_ParameterAndOrientation, std::unique_ptr<GeomInt_ParameterAndOrientation>> cls_GeomInt_ParameterAndOrientation(mod, "GeomInt_ParameterAndOrientation", "None");

// Constructors
cls_GeomInt_ParameterAndOrientation.def(py::init<>());
cls_GeomInt_ParameterAndOrientation.def(py::init<const Standard_Real, const TopAbs_Orientation, const TopAbs_Orientation>(), py::arg("P"), py::arg("Or1"), py::arg("Or2"));

// Fields

// Methods
// cls_GeomInt_ParameterAndOrientation.def_static("operator new_", (void * (*)(size_t)) &GeomInt_ParameterAndOrientation::operator new, "None", py::arg("theSize"));
// cls_GeomInt_ParameterAndOrientation.def_static("operator delete_", (void (*)(void *)) &GeomInt_ParameterAndOrientation::operator delete, "None", py::arg("theAddress"));
// cls_GeomInt_ParameterAndOrientation.def_static("operator new[]_", (void * (*)(size_t)) &GeomInt_ParameterAndOrientation::operator new[], "None", py::arg("theSize"));
// cls_GeomInt_ParameterAndOrientation.def_static("operator delete[]_", (void (*)(void *)) &GeomInt_ParameterAndOrientation::operator delete[], "None", py::arg("theAddress"));
// cls_GeomInt_ParameterAndOrientation.def_static("operator new_", (void * (*)(size_t, void *)) &GeomInt_ParameterAndOrientation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomInt_ParameterAndOrientation.def_static("operator delete_", (void (*)(void *, void *)) &GeomInt_ParameterAndOrientation::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomInt_ParameterAndOrientation.def("SetOrientation1", (void (GeomInt_ParameterAndOrientation::*)(const TopAbs_Orientation)) &GeomInt_ParameterAndOrientation::SetOrientation1, "None", py::arg("Or"));
cls_GeomInt_ParameterAndOrientation.def("SetOrientation2", (void (GeomInt_ParameterAndOrientation::*)(const TopAbs_Orientation)) &GeomInt_ParameterAndOrientation::SetOrientation2, "None", py::arg("Or"));
cls_GeomInt_ParameterAndOrientation.def("Parameter", (Standard_Real (GeomInt_ParameterAndOrientation::*)() const) &GeomInt_ParameterAndOrientation::Parameter, "None");
cls_GeomInt_ParameterAndOrientation.def("Orientation1", (TopAbs_Orientation (GeomInt_ParameterAndOrientation::*)() const) &GeomInt_ParameterAndOrientation::Orientation1, "None");
cls_GeomInt_ParameterAndOrientation.def("Orientation2", (TopAbs_Orientation (GeomInt_ParameterAndOrientation::*)() const) &GeomInt_ParameterAndOrientation::Orientation2, "None");

// Enums

}