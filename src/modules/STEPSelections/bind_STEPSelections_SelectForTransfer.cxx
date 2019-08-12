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
#include <XSControl_SelectForTransfer.hxx>
#include <Standard_Handle.hxx>
#include <XSControl_TransferReader.hxx>
#include <Interface_EntityIterator.hxx>
#include <Interface_Graph.hxx>
#include <STEPSelections_SelectForTransfer.hxx>
#include <Standard_Type.hxx>

void bind_STEPSelections_SelectForTransfer(py::module &mod){

py::class_<STEPSelections_SelectForTransfer, opencascade::handle<STEPSelections_SelectForTransfer>, XSControl_SelectForTransfer> cls_STEPSelections_SelectForTransfer(mod, "STEPSelections_SelectForTransfer", "None");

// Constructors
cls_STEPSelections_SelectForTransfer.def(py::init<>());
cls_STEPSelections_SelectForTransfer.def(py::init<const opencascade::handle<XSControl_TransferReader> &>(), py::arg("TR"));

// Fields

// Methods
cls_STEPSelections_SelectForTransfer.def("RootResult", (Interface_EntityIterator (STEPSelections_SelectForTransfer::*)(const Interface_Graph &) const) &STEPSelections_SelectForTransfer::RootResult, "None", py::arg("G"));
cls_STEPSelections_SelectForTransfer.def_static("get_type_name_", (const char * (*)()) &STEPSelections_SelectForTransfer::get_type_name, "None");
cls_STEPSelections_SelectForTransfer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &STEPSelections_SelectForTransfer::get_type_descriptor, "None");
cls_STEPSelections_SelectForTransfer.def("DynamicType", (const opencascade::handle<Standard_Type> & (STEPSelections_SelectForTransfer::*)() const) &STEPSelections_SelectForTransfer::DynamicType, "None");

// Enums

}