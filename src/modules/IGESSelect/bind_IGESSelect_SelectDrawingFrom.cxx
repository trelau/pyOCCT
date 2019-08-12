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
#include <IGESSelect_SelectDrawingFrom.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>

void bind_IGESSelect_SelectDrawingFrom(py::module &mod){

py::class_<IGESSelect_SelectDrawingFrom, opencascade::handle<IGESSelect_SelectDrawingFrom>, IFSelect_SelectDeduct> cls_IGESSelect_SelectDrawingFrom(mod, "IGESSelect_SelectDrawingFrom", "This selection gets the Drawings attached to its input IGES entities. They are read through thr Single Views, referenced in Directory Parts of the entities");

// Constructors
cls_IGESSelect_SelectDrawingFrom.def(py::init<>());

// Fields

// Methods
cls_IGESSelect_SelectDrawingFrom.def("RootResult", (Interface_EntityIterator (IGESSelect_SelectDrawingFrom::*)(const Interface_Graph &) const) &IGESSelect_SelectDrawingFrom::RootResult, "Selects the Drawings attached (through Single Views in Directory Part) to input entities", py::arg("G"));
cls_IGESSelect_SelectDrawingFrom.def("Label", (TCollection_AsciiString (IGESSelect_SelectDrawingFrom::*)() const) &IGESSelect_SelectDrawingFrom::Label, "Returns the label, with is 'Drawings attached'");
cls_IGESSelect_SelectDrawingFrom.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SelectDrawingFrom::get_type_name, "None");
cls_IGESSelect_SelectDrawingFrom.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SelectDrawingFrom::get_type_descriptor, "None");
cls_IGESSelect_SelectDrawingFrom.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SelectDrawingFrom::*)() const) &IGESSelect_SelectDrawingFrom::DynamicType, "None");

// Enums

}