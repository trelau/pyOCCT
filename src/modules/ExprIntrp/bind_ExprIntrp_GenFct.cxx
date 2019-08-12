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
#include <ExprIntrp_Generator.hxx>
#include <Standard_Handle.hxx>
#include <ExprIntrp_GenFct.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Type.hxx>

void bind_ExprIntrp_GenFct(py::module &mod){

py::class_<ExprIntrp_GenFct, opencascade::handle<ExprIntrp_GenFct>, ExprIntrp_Generator> cls_ExprIntrp_GenFct(mod, "ExprIntrp_GenFct", "Implements an interpreter for defining functions. All its functionnalities can be found in class GenExp.");

// Constructors

// Fields

// Methods
cls_ExprIntrp_GenFct.def_static("Create_", (opencascade::handle<ExprIntrp_GenFct> (*)()) &ExprIntrp_GenFct::Create, "None");
cls_ExprIntrp_GenFct.def("Process", (void (ExprIntrp_GenFct::*)(const TCollection_AsciiString &)) &ExprIntrp_GenFct::Process, "None", py::arg("str"));
cls_ExprIntrp_GenFct.def("IsDone", (Standard_Boolean (ExprIntrp_GenFct::*)() const) &ExprIntrp_GenFct::IsDone, "None");
cls_ExprIntrp_GenFct.def_static("get_type_name_", (const char * (*)()) &ExprIntrp_GenFct::get_type_name, "None");
cls_ExprIntrp_GenFct.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ExprIntrp_GenFct::get_type_descriptor, "None");
cls_ExprIntrp_GenFct.def("DynamicType", (const opencascade::handle<Standard_Type> & (ExprIntrp_GenFct::*)() const) &ExprIntrp_GenFct::DynamicType, "None");

// Enums

}