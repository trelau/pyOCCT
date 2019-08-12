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
#include <IGESSelect_DispPerDrawing.hxx>
#include <Standard_Type.hxx>
#include <IGESSelect_ViewSorter.hxx>

void bind_IGESSelect_DispPerDrawing(py::module &mod){

py::class_<IGESSelect_DispPerDrawing, opencascade::handle<IGESSelect_DispPerDrawing>, IFSelect_Dispatch> cls_IGESSelect_DispPerDrawing(mod, "IGESSelect_DispPerDrawing", "This type of dispatch defines sets of entities attached to distinct drawings. This information is taken from attached views which appear in the Directory Part. Also Drawing Frames are considered when Drawings are part of input list.");

// Constructors
cls_IGESSelect_DispPerDrawing.def(py::init<>());

// Fields

// Methods
cls_IGESSelect_DispPerDrawing.def("Label", (TCollection_AsciiString (IGESSelect_DispPerDrawing::*)() const) &IGESSelect_DispPerDrawing::Label, "Returns as Label, 'One File per Drawing'");
cls_IGESSelect_DispPerDrawing.def("Packets", (void (IGESSelect_DispPerDrawing::*)(const Interface_Graph &, IFGraph_SubPartsIterator &) const) &IGESSelect_DispPerDrawing::Packets, "Computes the list of produced Packets. Packets are computed by a ViewSorter (SortDrawings with also frames).", py::arg("G"), py::arg("packs"));
cls_IGESSelect_DispPerDrawing.def("CanHaveRemainder", (Standard_Boolean (IGESSelect_DispPerDrawing::*)() const) &IGESSelect_DispPerDrawing::CanHaveRemainder, "Returns True, because of entities attached to no view.");
cls_IGESSelect_DispPerDrawing.def("Remainder", (Interface_EntityIterator (IGESSelect_DispPerDrawing::*)(const Interface_Graph &) const) &IGESSelect_DispPerDrawing::Remainder, "Returns Remainder which is a set of Entities. It is supposed to be called once Packets has been called.", py::arg("G"));
cls_IGESSelect_DispPerDrawing.def_static("get_type_name_", (const char * (*)()) &IGESSelect_DispPerDrawing::get_type_name, "None");
cls_IGESSelect_DispPerDrawing.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_DispPerDrawing::get_type_descriptor, "None");
cls_IGESSelect_DispPerDrawing.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_DispPerDrawing::*)() const) &IGESSelect_DispPerDrawing::DynamicType, "None");

// Enums

}