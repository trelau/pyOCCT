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
#include <IGESSelect_SelectFromDrawing.hxx>
#include <Standard_Type.hxx>

void bind_IGESSelect_SelectFromDrawing(py::module &mod){

py::class_<IGESSelect_SelectFromDrawing, opencascade::handle<IGESSelect_SelectFromDrawing>, IFSelect_SelectDeduct> cls_IGESSelect_SelectFromDrawing(mod, "IGESSelect_SelectFromDrawing", "This selection gets in all the model, the entities which are attached to the drawing(s) given as input. This includes : - Drawing Frame (Annotations directky referenced by Drawings) - Entities attached to the single Views referenced by Drawings");

// Constructors
cls_IGESSelect_SelectFromDrawing.def(py::init<>());

// Fields

// Methods
cls_IGESSelect_SelectFromDrawing.def("RootResult", (Interface_EntityIterator (IGESSelect_SelectFromDrawing::*)(const Interface_Graph &) const) &IGESSelect_SelectFromDrawing::RootResult, "Selects the Entities which are attached to the Drawing(s) present in the Input", py::arg("G"));
cls_IGESSelect_SelectFromDrawing.def("Label", (TCollection_AsciiString (IGESSelect_SelectFromDrawing::*)() const) &IGESSelect_SelectFromDrawing::Label, "Returns the label, with is 'Entities attached to Drawing'");
cls_IGESSelect_SelectFromDrawing.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SelectFromDrawing::get_type_name, "None");
cls_IGESSelect_SelectFromDrawing.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SelectFromDrawing::get_type_descriptor, "None");
cls_IGESSelect_SelectFromDrawing.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SelectFromDrawing::*)() const) &IGESSelect_SelectFromDrawing::DynamicType, "None");

// Enums

}