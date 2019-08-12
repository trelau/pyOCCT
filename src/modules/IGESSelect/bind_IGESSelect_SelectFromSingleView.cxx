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
#include <IGESSelect_SelectFromSingleView.hxx>
#include <Standard_Type.hxx>

void bind_IGESSelect_SelectFromSingleView(py::module &mod){

py::class_<IGESSelect_SelectFromSingleView, opencascade::handle<IGESSelect_SelectFromSingleView>, IFSelect_SelectDeduct> cls_IGESSelect_SelectFromSingleView(mod, "IGESSelect_SelectFromSingleView", "This selection gets in all the model, the entities which are attached to the views given as input. Only Single Views are considered. This information is kept from Directory Part (View Item).");

// Constructors
cls_IGESSelect_SelectFromSingleView.def(py::init<>());

// Fields

// Methods
cls_IGESSelect_SelectFromSingleView.def("RootResult", (Interface_EntityIterator (IGESSelect_SelectFromSingleView::*)(const Interface_Graph &) const) &IGESSelect_SelectFromSingleView::RootResult, "Selects the Entities which are attached to the Single View(s) present in the Input", py::arg("G"));
cls_IGESSelect_SelectFromSingleView.def("Label", (TCollection_AsciiString (IGESSelect_SelectFromSingleView::*)() const) &IGESSelect_SelectFromSingleView::Label, "Returns the label, with is 'Entities attached to single View'");
cls_IGESSelect_SelectFromSingleView.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SelectFromSingleView::get_type_name, "None");
cls_IGESSelect_SelectFromSingleView.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SelectFromSingleView::get_type_descriptor, "None");
cls_IGESSelect_SelectFromSingleView.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SelectFromSingleView::*)() const) &IGESSelect_SelectFromSingleView::DynamicType, "None");

// Enums

}