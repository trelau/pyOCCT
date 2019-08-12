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
#include <IFSelect_Dispatch.hxx>
#include <TCollection_AsciiString.hxx>
#include <Interface_Graph.hxx>
#include <IFGraph_SubPartsIterator.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_EntityIterator.hxx>
#include <Standard_Handle.hxx>
#include <IGESSelect_DispPerSingleView.hxx>
#include <Standard_Type.hxx>
#include <IGESSelect_ViewSorter.hxx>

void bind_IGESSelect_DispPerSingleView(py::module &mod){

py::class_<IGESSelect_DispPerSingleView, opencascade::handle<IGESSelect_DispPerSingleView>, IFSelect_Dispatch> cls_IGESSelect_DispPerSingleView(mod, "IGESSelect_DispPerSingleView", "This type of dispatch defines sets of entities attached to distinct single views. This information appears in the Directory Part. Drawings are taken into account too, because of their frames (proper lists of annotations)");

// Constructors
cls_IGESSelect_DispPerSingleView.def(py::init<>());

// Fields

// Methods
cls_IGESSelect_DispPerSingleView.def("Label", (TCollection_AsciiString (IGESSelect_DispPerSingleView::*)() const) &IGESSelect_DispPerSingleView::Label, "Returns as Label, 'One File per single View or Drawing Frame'");
cls_IGESSelect_DispPerSingleView.def("Packets", (void (IGESSelect_DispPerSingleView::*)(const Interface_Graph &, IFGraph_SubPartsIterator &) const) &IGESSelect_DispPerSingleView::Packets, "Computes the list of produced Packets. Packets are computed by a ViewSorter (SortSingleViews with also frames).", py::arg("G"), py::arg("packs"));
cls_IGESSelect_DispPerSingleView.def("CanHaveRemainder", (Standard_Boolean (IGESSelect_DispPerSingleView::*)() const) &IGESSelect_DispPerSingleView::CanHaveRemainder, "Returns True, because of entities attached to no view.");
cls_IGESSelect_DispPerSingleView.def("Remainder", (Interface_EntityIterator (IGESSelect_DispPerSingleView::*)(const Interface_Graph &) const) &IGESSelect_DispPerSingleView::Remainder, "Returns Remainder which is a set of Entities. It is supposed to be called once Packets has been called.", py::arg("G"));
cls_IGESSelect_DispPerSingleView.def_static("get_type_name_", (const char * (*)()) &IGESSelect_DispPerSingleView::get_type_name, "None");
cls_IGESSelect_DispPerSingleView.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_DispPerSingleView::get_type_descriptor, "None");
cls_IGESSelect_DispPerSingleView.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_DispPerSingleView::*)() const) &IGESSelect_DispPerSingleView::DynamicType, "None");

// Enums

}