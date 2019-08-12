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
#include <IFSelect_SelectDeduct.hxx>
#include <Interface_EntityIterator.hxx>
#include <Interface_Graph.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Handle.hxx>
#include <IGESSelect_SelectSingleViewFrom.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>

void bind_IGESSelect_SelectSingleViewFrom(py::module &mod){

py::class_<IGESSelect_SelectSingleViewFrom, opencascade::handle<IGESSelect_SelectSingleViewFrom>, IFSelect_SelectDeduct> cls_IGESSelect_SelectSingleViewFrom(mod, "IGESSelect_SelectSingleViewFrom", "This selection gets the Single Views attached to its input IGES entities. Single Views themselves or Drawings as passed as such (Drawings, for their Annotations)");

// Constructors
cls_IGESSelect_SelectSingleViewFrom.def(py::init<>());

// Fields

// Methods
cls_IGESSelect_SelectSingleViewFrom.def("RootResult", (Interface_EntityIterator (IGESSelect_SelectSingleViewFrom::*)(const Interface_Graph &) const) &IGESSelect_SelectSingleViewFrom::RootResult, "Selects the Single Views attached (in Directory Part) to input entities", py::arg("G"));
cls_IGESSelect_SelectSingleViewFrom.def("Label", (TCollection_AsciiString (IGESSelect_SelectSingleViewFrom::*)() const) &IGESSelect_SelectSingleViewFrom::Label, "Returns the label, with is 'Single Views attached'");
cls_IGESSelect_SelectSingleViewFrom.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SelectSingleViewFrom::get_type_name, "None");
cls_IGESSelect_SelectSingleViewFrom.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SelectSingleViewFrom::get_type_descriptor, "None");
cls_IGESSelect_SelectSingleViewFrom.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SelectSingleViewFrom::*)() const) &IGESSelect_SelectSingleViewFrom::DynamicType, "None");

// Enums

}