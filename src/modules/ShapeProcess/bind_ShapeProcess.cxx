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
#include <Standard_Handle.hxx>
#include <ShapeProcess_Operator.hxx>
#include <ShapeProcess_Context.hxx>
#include <ShapeProcess_ShapeContext.hxx>
#include <ShapeProcess_UOperator.hxx>
#include <ShapeProcess_OperLibrary.hxx>
#include <ShapeProcess.hxx>

void bind_ShapeProcess(py::module &mod){

py::class_<ShapeProcess, std::unique_ptr<ShapeProcess>> cls_ShapeProcess(mod, "ShapeProcess", "Shape Processing module allows to define and apply general Shape Processing as a customizable sequence of Shape Healing operators. The customization is implemented via user-editable resource file which defines sequence of operators to be executed and their parameters.");

// Constructors

// Fields

// Methods
// cls_ShapeProcess.def_static("operator new_", (void * (*)(size_t)) &ShapeProcess::operator new, "None", py::arg("theSize"));
// cls_ShapeProcess.def_static("operator delete_", (void (*)(void *)) &ShapeProcess::operator delete, "None", py::arg("theAddress"));
// cls_ShapeProcess.def_static("operator new[]_", (void * (*)(size_t)) &ShapeProcess::operator new[], "None", py::arg("theSize"));
// cls_ShapeProcess.def_static("operator delete[]_", (void (*)(void *)) &ShapeProcess::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeProcess.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeProcess::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeProcess.def_static("operator delete_", (void (*)(void *, void *)) &ShapeProcess::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeProcess.def_static("RegisterOperator_", (Standard_Boolean (*)(const Standard_CString, const opencascade::handle<ShapeProcess_Operator> &)) &ShapeProcess::RegisterOperator, "Registers operator to make it visible for Performer", py::arg("name"), py::arg("op"));
cls_ShapeProcess.def_static("FindOperator_", (Standard_Boolean (*)(const Standard_CString, opencascade::handle<ShapeProcess_Operator> &)) &ShapeProcess::FindOperator, "Finds operator by its name", py::arg("name"), py::arg("op"));
cls_ShapeProcess.def_static("Perform_", (Standard_Boolean (*)(const opencascade::handle<ShapeProcess_Context> &, const Standard_CString)) &ShapeProcess::Perform, "Performs a specified sequence of operators on Context Resource file and other data should be already loaded to Context (including description of sequence seq)", py::arg("context"), py::arg("seq"));

// Enums

}