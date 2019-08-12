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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_HSequenceOfTransient.hxx>
#include <Interface_EntityIterator.hxx>
#include <IFSelect_PacketList.hxx>
#include <Standard_Type.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <Interface_IntList.hxx>
#include <TCollection_AsciiString.hxx>

void bind_IFSelect_PacketList(py::module &mod){

py::class_<IFSelect_PacketList, opencascade::handle<IFSelect_PacketList>, Standard_Transient> cls_IFSelect_PacketList(mod, "IFSelect_PacketList", "This class gives a simple way to return then consult a list of packets, determined from the content of a Model, by various criteria.");

// Constructors
cls_IFSelect_PacketList.def(py::init<const opencascade::handle<Interface_InterfaceModel> &>(), py::arg("model"));

// Fields

// Methods
cls_IFSelect_PacketList.def("SetName", (void (IFSelect_PacketList::*)(const Standard_CString)) &IFSelect_PacketList::SetName, "Sets a name to a packet list : this makes easier a general routine to print it. Default is 'Packets'", py::arg("name"));
cls_IFSelect_PacketList.def("Name", (Standard_CString (IFSelect_PacketList::*)() const) &IFSelect_PacketList::Name, "Returns the recorded name for a packet list");
cls_IFSelect_PacketList.def("Model", (opencascade::handle<Interface_InterfaceModel> (IFSelect_PacketList::*)() const) &IFSelect_PacketList::Model, "Returns the Model of reference");
cls_IFSelect_PacketList.def("AddPacket", (void (IFSelect_PacketList::*)()) &IFSelect_PacketList::AddPacket, "Declares a new Packet, ready to be filled The entities to be added will be added to this Packet");
cls_IFSelect_PacketList.def("Add", (void (IFSelect_PacketList::*)(const opencascade::handle<Standard_Transient> &)) &IFSelect_PacketList::Add, "Adds an entity from the Model into the current packet for Add", py::arg("ent"));
cls_IFSelect_PacketList.def("AddList", (void (IFSelect_PacketList::*)(const opencascade::handle<TColStd_HSequenceOfTransient> &)) &IFSelect_PacketList::AddList, "Adds an list of entities into the current packet for Add", py::arg("list"));
cls_IFSelect_PacketList.def("NbPackets", (Standard_Integer (IFSelect_PacketList::*)() const) &IFSelect_PacketList::NbPackets, "Returns the count of non-empty packets");
cls_IFSelect_PacketList.def("NbEntities", (Standard_Integer (IFSelect_PacketList::*)(const Standard_Integer) const) &IFSelect_PacketList::NbEntities, "Returns the count of entities in a Packet given its rank, or 0", py::arg("numpack"));
cls_IFSelect_PacketList.def("Entities", (Interface_EntityIterator (IFSelect_PacketList::*)(const Standard_Integer) const) &IFSelect_PacketList::Entities, "Returns the content of a Packet given its rank Null Handle if <numpack> is out of range", py::arg("numpack"));
cls_IFSelect_PacketList.def("HighestDuplicationCount", (Standard_Integer (IFSelect_PacketList::*)() const) &IFSelect_PacketList::HighestDuplicationCount, "Returns the highest number of packets which know a same entity For no duplication, should be one");
cls_IFSelect_PacketList.def("NbDuplicated", (Standard_Integer (IFSelect_PacketList::*)(const Standard_Integer, const Standard_Boolean) const) &IFSelect_PacketList::NbDuplicated, "Returns the count of entities duplicated : <count> times, if <andmore> is False, or <count> or more times, if <andmore> is True See Duplicated for more details", py::arg("count"), py::arg("andmore"));
cls_IFSelect_PacketList.def("Duplicated", (Interface_EntityIterator (IFSelect_PacketList::*)(const Standard_Integer, const Standard_Boolean) const) &IFSelect_PacketList::Duplicated, "Returns a list of entities duplicated : <count> times, if <andmore> is False, or <count> or more times, if <andmore> is True Hence, count=2 & andmore=True gives all duplicated entities count=1 gives non-duplicated entities (in only one packet) count=0 gives remaining entities (in no packet at all)", py::arg("count"), py::arg("andmore"));
cls_IFSelect_PacketList.def_static("get_type_name_", (const char * (*)()) &IFSelect_PacketList::get_type_name, "None");
cls_IFSelect_PacketList.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_PacketList::get_type_descriptor, "None");
cls_IFSelect_PacketList.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_PacketList::*)() const) &IFSelect_PacketList::DynamicType, "None");

// Enums

}