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
#include <IFSelect_DispGlobal.hxx>
#include <Standard_Type.hxx>

void bind_IFSelect_DispGlobal(py::module &mod){

py::class_<IFSelect_DispGlobal, opencascade::handle<IFSelect_DispGlobal>, IFSelect_Dispatch> cls_IFSelect_DispGlobal(mod, "IFSelect_DispGlobal", "A DispGlobal gathers all the input Entities into only one global Packet");

// Constructors
cls_IFSelect_DispGlobal.def(py::init<>());

// Fields

// Methods
cls_IFSelect_DispGlobal.def("Label", (TCollection_AsciiString (IFSelect_DispGlobal::*)() const) &IFSelect_DispGlobal::Label, "Returns as Label, 'One File for all Input'");
cls_IFSelect_DispGlobal.def("LimitedMax", [](IFSelect_DispGlobal &self, const Standard_Integer nbent, Standard_Integer & max){ Standard_Boolean rv = self.LimitedMax(nbent, max); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, max); }, "Returns True : maximum equates 1", py::arg("nbent"), py::arg("max"));
cls_IFSelect_DispGlobal.def("Packets", (void (IFSelect_DispGlobal::*)(const Interface_Graph &, IFGraph_SubPartsIterator &) const) &IFSelect_DispGlobal::Packets, "Computes the list of produced Packets. It is made of only ONE Packet, which gets the RootResult from the Final Selection. Remark : the inherited exception raising is never activated.", py::arg("G"), py::arg("packs"));
cls_IFSelect_DispGlobal.def_static("get_type_name_", (const char * (*)()) &IFSelect_DispGlobal::get_type_name, "None");
cls_IFSelect_DispGlobal.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_DispGlobal::get_type_descriptor, "None");
cls_IFSelect_DispGlobal.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_DispGlobal::*)() const) &IFSelect_DispGlobal::DynamicType, "None");

// Enums

}