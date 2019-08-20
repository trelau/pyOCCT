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
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <TColStd_IndexedDataMapOfTransientTransient.hxx>
#include <TNaming_Translator.hxx>

void bind_TNaming_Translator(py::module &mod){

py::class_<TNaming_Translator, std::unique_ptr<TNaming_Translator>> cls_TNaming_Translator(mod, "TNaming_Translator", "only for Shape Copy test - to move in DNaming");

// Constructors
cls_TNaming_Translator.def(py::init<>());

// Fields

// Methods
// cls_TNaming_Translator.def_static("operator new_", (void * (*)(size_t)) &TNaming_Translator::operator new, "None", py::arg("theSize"));
// cls_TNaming_Translator.def_static("operator delete_", (void (*)(void *)) &TNaming_Translator::operator delete, "None", py::arg("theAddress"));
// cls_TNaming_Translator.def_static("operator new[]_", (void * (*)(size_t)) &TNaming_Translator::operator new[], "None", py::arg("theSize"));
// cls_TNaming_Translator.def_static("operator delete[]_", (void (*)(void *)) &TNaming_Translator::operator delete[], "None", py::arg("theAddress"));
// cls_TNaming_Translator.def_static("operator new_", (void * (*)(size_t, void *)) &TNaming_Translator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TNaming_Translator.def_static("operator delete_", (void (*)(void *, void *)) &TNaming_Translator::operator delete, "None", py::arg(""), py::arg(""));
cls_TNaming_Translator.def("Add", (void (TNaming_Translator::*)(const TopoDS_Shape &)) &TNaming_Translator::Add, "None", py::arg("aShape"));
cls_TNaming_Translator.def("Perform", (void (TNaming_Translator::*)()) &TNaming_Translator::Perform, "None");
cls_TNaming_Translator.def("IsDone", (Standard_Boolean (TNaming_Translator::*)() const) &TNaming_Translator::IsDone, "None");
cls_TNaming_Translator.def("Copied", (const TopoDS_Shape (TNaming_Translator::*)(const TopoDS_Shape &) const) &TNaming_Translator::Copied, "returns copied shape", py::arg("aShape"));
cls_TNaming_Translator.def("Copied", (const TopTools_DataMapOfShapeShape & (TNaming_Translator::*)() const) &TNaming_Translator::Copied, "returns DataMap of results; (shape <-> copied shape)");
cls_TNaming_Translator.def("DumpMap", [](TNaming_Translator &self) -> void { return self.DumpMap(); });
cls_TNaming_Translator.def("DumpMap", (void (TNaming_Translator::*)(const Standard_Boolean) const) &TNaming_Translator::DumpMap, "None", py::arg("isWrite"));

// Enums

}