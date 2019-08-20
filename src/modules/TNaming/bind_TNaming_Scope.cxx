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
#include <TDF_LabelMap.hxx>
#include <TDF_Label.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Handle.hxx>
#include <TNaming_NamedShape.hxx>
#include <TNaming_Scope.hxx>

void bind_TNaming_Scope(py::module &mod){

py::class_<TNaming_Scope, std::unique_ptr<TNaming_Scope>> cls_TNaming_Scope(mod, "TNaming_Scope", "this class manage a scope of labels ===================================");

// Constructors
cls_TNaming_Scope.def(py::init<>());
cls_TNaming_Scope.def(py::init<const Standard_Boolean>(), py::arg("WithValid"));
cls_TNaming_Scope.def(py::init<TDF_LabelMap &>(), py::arg("valid"));

// Fields

// Methods
// cls_TNaming_Scope.def_static("operator new_", (void * (*)(size_t)) &TNaming_Scope::operator new, "None", py::arg("theSize"));
// cls_TNaming_Scope.def_static("operator delete_", (void (*)(void *)) &TNaming_Scope::operator delete, "None", py::arg("theAddress"));
// cls_TNaming_Scope.def_static("operator new[]_", (void * (*)(size_t)) &TNaming_Scope::operator new[], "None", py::arg("theSize"));
// cls_TNaming_Scope.def_static("operator delete[]_", (void (*)(void *)) &TNaming_Scope::operator delete[], "None", py::arg("theAddress"));
// cls_TNaming_Scope.def_static("operator new_", (void * (*)(size_t, void *)) &TNaming_Scope::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TNaming_Scope.def_static("operator delete_", (void (*)(void *, void *)) &TNaming_Scope::operator delete, "None", py::arg(""), py::arg(""));
cls_TNaming_Scope.def("WithValid", (Standard_Boolean (TNaming_Scope::*)() const) &TNaming_Scope::WithValid, "None");
cls_TNaming_Scope.def("WithValid", (void (TNaming_Scope::*)(const Standard_Boolean)) &TNaming_Scope::WithValid, "None", py::arg("mode"));
cls_TNaming_Scope.def("ClearValid", (void (TNaming_Scope::*)()) &TNaming_Scope::ClearValid, "None");
cls_TNaming_Scope.def("Valid", (void (TNaming_Scope::*)(const TDF_Label &)) &TNaming_Scope::Valid, "None", py::arg("L"));
cls_TNaming_Scope.def("ValidChildren", [](TNaming_Scope &self, const TDF_Label & a0) -> void { return self.ValidChildren(a0); });
cls_TNaming_Scope.def("ValidChildren", (void (TNaming_Scope::*)(const TDF_Label &, const Standard_Boolean)) &TNaming_Scope::ValidChildren, "None", py::arg("L"), py::arg("withroot"));
cls_TNaming_Scope.def("Unvalid", (void (TNaming_Scope::*)(const TDF_Label &)) &TNaming_Scope::Unvalid, "None", py::arg("L"));
cls_TNaming_Scope.def("UnvalidChildren", [](TNaming_Scope &self, const TDF_Label & a0) -> void { return self.UnvalidChildren(a0); });
cls_TNaming_Scope.def("UnvalidChildren", (void (TNaming_Scope::*)(const TDF_Label &, const Standard_Boolean)) &TNaming_Scope::UnvalidChildren, "None", py::arg("L"), py::arg("withroot"));
cls_TNaming_Scope.def("IsValid", (Standard_Boolean (TNaming_Scope::*)(const TDF_Label &) const) &TNaming_Scope::IsValid, "None", py::arg("L"));
cls_TNaming_Scope.def("GetValid", (const TDF_LabelMap & (TNaming_Scope::*)() const) &TNaming_Scope::GetValid, "None");
cls_TNaming_Scope.def("ChangeValid", (TDF_LabelMap & (TNaming_Scope::*)()) &TNaming_Scope::ChangeValid, "None");
cls_TNaming_Scope.def("CurrentShape", (TopoDS_Shape (TNaming_Scope::*)(const opencascade::handle<TNaming_NamedShape> &) const) &TNaming_Scope::CurrentShape, "Returns the current value of <NS> according to the Valid Scope.", py::arg("NS"));

// Enums

}