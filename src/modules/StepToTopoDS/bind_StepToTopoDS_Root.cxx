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
#include <StepToTopoDS_Root.hxx>

void bind_StepToTopoDS_Root(py::module &mod){

py::class_<StepToTopoDS_Root, std::unique_ptr<StepToTopoDS_Root>> cls_StepToTopoDS_Root(mod, "StepToTopoDS_Root", "This class implements the common services for all classes of StepToTopoDS which report error and sets and returns precision.");

// Constructors

// Fields

// Methods
// cls_StepToTopoDS_Root.def_static("operator new_", (void * (*)(size_t)) &StepToTopoDS_Root::operator new, "None", py::arg("theSize"));
// cls_StepToTopoDS_Root.def_static("operator delete_", (void (*)(void *)) &StepToTopoDS_Root::operator delete, "None", py::arg("theAddress"));
// cls_StepToTopoDS_Root.def_static("operator new[]_", (void * (*)(size_t)) &StepToTopoDS_Root::operator new[], "None", py::arg("theSize"));
// cls_StepToTopoDS_Root.def_static("operator delete[]_", (void (*)(void *)) &StepToTopoDS_Root::operator delete[], "None", py::arg("theAddress"));
// cls_StepToTopoDS_Root.def_static("operator new_", (void * (*)(size_t, void *)) &StepToTopoDS_Root::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepToTopoDS_Root.def_static("operator delete_", (void (*)(void *, void *)) &StepToTopoDS_Root::operator delete, "None", py::arg(""), py::arg(""));
cls_StepToTopoDS_Root.def("IsDone", (Standard_Boolean (StepToTopoDS_Root::*)() const) &StepToTopoDS_Root::IsDone, "None");
cls_StepToTopoDS_Root.def("Precision", (Standard_Real (StepToTopoDS_Root::*)() const) &StepToTopoDS_Root::Precision, "Returns the value of 'MyPrecision'");
cls_StepToTopoDS_Root.def("SetPrecision", (void (StepToTopoDS_Root::*)(const Standard_Real)) &StepToTopoDS_Root::SetPrecision, "Sets the value of 'MyPrecision'", py::arg("preci"));
cls_StepToTopoDS_Root.def("MaxTol", (Standard_Real (StepToTopoDS_Root::*)() const) &StepToTopoDS_Root::MaxTol, "Returns the value of 'MaxTol'");
cls_StepToTopoDS_Root.def("SetMaxTol", (void (StepToTopoDS_Root::*)(const Standard_Real)) &StepToTopoDS_Root::SetMaxTol, "Sets the value of MaxTol", py::arg("maxpreci"));

// Enums

}