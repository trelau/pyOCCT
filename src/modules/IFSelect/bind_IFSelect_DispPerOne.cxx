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
#include <Standard_TypeDef.hxx>
#include <Interface_Graph.hxx>
#include <IFGraph_SubPartsIterator.hxx>
#include <Standard_Handle.hxx>
#include <IFSelect_DispPerOne.hxx>
#include <Standard_Type.hxx>

void bind_IFSelect_DispPerOne(py::module &mod){

py::class_<IFSelect_DispPerOne, opencascade::handle<IFSelect_DispPerOne>, IFSelect_Dispatch> cls_IFSelect_DispPerOne(mod, "IFSelect_DispPerOne", "A DispPerOne gathers all the input Entities into as many Packets as there Root Entities from the Final Selection, that is, one Packet per Entity");

// Constructors
cls_IFSelect_DispPerOne.def(py::init<>());

// Fields

// Methods
cls_IFSelect_DispPerOne.def("Label", (TCollection_AsciiString (IFSelect_DispPerOne::*)() const) &IFSelect_DispPerOne::Label, "Returns as Label, 'One File per Input Entity'");
cls_IFSelect_DispPerOne.def("LimitedMax", [](IFSelect_DispPerOne &self, const Standard_Integer nbent, Standard_Integer & max){ Standard_Boolean rv = self.LimitedMax(nbent, max); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, max); }, "Returns True, maximum limit is given as <nbent>", py::arg("nbent"), py::arg("max"));
cls_IFSelect_DispPerOne.def("Packets", (void (IFSelect_DispPerOne::*)(const Interface_Graph &, IFGraph_SubPartsIterator &) const) &IFSelect_DispPerOne::Packets, "Returns the list of produced Packets. It defines one Packet per Entity given by RootResult from the Final Selection.", py::arg("G"), py::arg("packs"));
cls_IFSelect_DispPerOne.def_static("get_type_name_", (const char * (*)()) &IFSelect_DispPerOne::get_type_name, "None");
cls_IFSelect_DispPerOne.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_DispPerOne::get_type_descriptor, "None");
cls_IFSelect_DispPerOne.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_DispPerOne::*)() const) &IFSelect_DispPerOne::DynamicType, "None");

// Enums

}