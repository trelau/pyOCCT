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
#include <Standard_Handle.hxx>
#include <IFSelect_IntParam.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_AsciiString.hxx>
#include <Interface_Graph.hxx>
#include <IFGraph_SubPartsIterator.hxx>
#include <IFSelect_DispPerCount.hxx>
#include <Standard_Type.hxx>

void bind_IFSelect_DispPerCount(py::module &mod){

py::class_<IFSelect_DispPerCount, opencascade::handle<IFSelect_DispPerCount>, IFSelect_Dispatch> cls_IFSelect_DispPerCount(mod, "IFSelect_DispPerCount", "A DispPerCount gathers all the input Entities into one or several Packets, each containing a defined count of Entity This count is a Parameter of the DispPerCount, given as an IntParam, thus allowing external control of its Value");

// Constructors
cls_IFSelect_DispPerCount.def(py::init<>());

// Fields

// Methods
cls_IFSelect_DispPerCount.def("Count", (opencascade::handle<IFSelect_IntParam> (IFSelect_DispPerCount::*)() const) &IFSelect_DispPerCount::Count, "Returns the Count Parameter used for splitting");
cls_IFSelect_DispPerCount.def("SetCount", (void (IFSelect_DispPerCount::*)(const opencascade::handle<IFSelect_IntParam> &)) &IFSelect_DispPerCount::SetCount, "Sets a new Parameter for Count", py::arg("count"));
cls_IFSelect_DispPerCount.def("CountValue", (Standard_Integer (IFSelect_DispPerCount::*)() const) &IFSelect_DispPerCount::CountValue, "Returns the effective value of the count parameter (if Count Parameter not Set or value not positive, returns 1)");
cls_IFSelect_DispPerCount.def("Label", (TCollection_AsciiString (IFSelect_DispPerCount::*)() const) &IFSelect_DispPerCount::Label, "Returns as Label, 'One File per <count> Input Entities'");
cls_IFSelect_DispPerCount.def("LimitedMax", [](IFSelect_DispPerCount &self, const Standard_Integer nbent, Standard_Integer & max){ Standard_Boolean rv = self.LimitedMax(nbent, max); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, max); }, "Returns True, maximum count is given as <nbent>", py::arg("nbent"), py::arg("max"));
cls_IFSelect_DispPerCount.def("Packets", (void (IFSelect_DispPerCount::*)(const Interface_Graph &, IFGraph_SubPartsIterator &) const) &IFSelect_DispPerCount::Packets, "Computes the list of produced Packets. It defines Packets in order to have at most <Count> Entities per Packet, Entities are given by RootResult from the Final Selection.", py::arg("G"), py::arg("packs"));
cls_IFSelect_DispPerCount.def_static("get_type_name_", (const char * (*)()) &IFSelect_DispPerCount::get_type_name, "None");
cls_IFSelect_DispPerCount.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_DispPerCount::get_type_descriptor, "None");
cls_IFSelect_DispPerCount.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_DispPerCount::*)() const) &IFSelect_DispPerCount::DynamicType, "None");

// Enums

}