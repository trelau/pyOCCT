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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <TCollection_AsciiString.hxx>
#include <TColStd_HSequenceOfHAsciiString.hxx>
#include <TColStd_HSequenceOfTransient.hxx>
#include <Message_Messenger.hxx>
#include <Interface_InterfaceModel.hxx>
#include <IFSelect_PrintCount.hxx>
#include <IFSelect_SignatureList.hxx>
#include <Standard_Type.hxx>
#include <TCollection_HAsciiString.hxx>

void bind_IFSelect_SignatureList(py::module &mod){

py::class_<IFSelect_SignatureList, opencascade::handle<IFSelect_SignatureList>, Standard_Transient> cls_IFSelect_SignatureList(mod, "IFSelect_SignatureList", "A SignatureList is given as result from a Counter (any kind) It gives access to a list of signatures, with counts, and optionally with list of corresponding entities");

// Constructors
cls_IFSelect_SignatureList.def(py::init<>());
cls_IFSelect_SignatureList.def(py::init<const Standard_Boolean>(), py::arg("withlist"));

// Fields

// Methods
cls_IFSelect_SignatureList.def("SetList", (void (IFSelect_SignatureList::*)(const Standard_Boolean)) &IFSelect_SignatureList::SetList, "Changes the record-list status. The list is not cleared but its use changes", py::arg("withlist"));
cls_IFSelect_SignatureList.def("ModeSignOnly", (Standard_Boolean & (IFSelect_SignatureList::*)()) &IFSelect_SignatureList::ModeSignOnly, "Returns modifiable the SignOnly Mode If False (D), the counter normally counts If True, the counting work is turned off, Add only fills the LastValue, which can be used as signature, when a counter works from data which are not available from a Signature");
cls_IFSelect_SignatureList.def("Clear", (void (IFSelect_SignatureList::*)()) &IFSelect_SignatureList::Clear, "None");
cls_IFSelect_SignatureList.def("Add", (void (IFSelect_SignatureList::*)(const opencascade::handle<Standard_Transient> &, const Standard_CString)) &IFSelect_SignatureList::Add, "Adds an entity with its signature, i.e. : - counts an item more for <sign> - if record-list status is set, records the entity Accepts a null entity (the signature is then for the global model). But if the string is empty, counts a Null item.", py::arg("ent"), py::arg("sign"));
cls_IFSelect_SignatureList.def("LastValue", (Standard_CString (IFSelect_SignatureList::*)() const) &IFSelect_SignatureList::LastValue, "Returns the last value recorded by Add (only if SignMode set) Cleared by Clear or Init");
cls_IFSelect_SignatureList.def("Init", (void (IFSelect_SignatureList::*)(const Standard_CString, const NCollection_IndexedDataMap<TCollection_AsciiString, Standard_Integer> &, const NCollection_IndexedDataMap<TCollection_AsciiString, opencascade::handle<Standard_Transient> > &, const Standard_Integer)) &IFSelect_SignatureList::Init, "Aknowledges the list in once. Name identifies the Signature", py::arg("name"), py::arg("count"), py::arg("list"), py::arg("nbnuls"));
cls_IFSelect_SignatureList.def("List", [](IFSelect_SignatureList &self) -> opencascade::handle<TColStd_HSequenceOfHAsciiString> { return self.List(); });
cls_IFSelect_SignatureList.def("List", (opencascade::handle<TColStd_HSequenceOfHAsciiString> (IFSelect_SignatureList::*)(const Standard_CString) const) &IFSelect_SignatureList::List, "Returns the list of signatures, as a sequence of strings (but without their respective counts). It is ordered. By default, for all the signatures. If <root> is given non empty, for the signatures which begin by <root>", py::arg("root"));
cls_IFSelect_SignatureList.def("HasEntities", (Standard_Boolean (IFSelect_SignatureList::*)() const) &IFSelect_SignatureList::HasEntities, "Returns True if the list of Entities is aknowledged, else the method Entities will always return a Null Handle");
cls_IFSelect_SignatureList.def("NbNulls", (Standard_Integer (IFSelect_SignatureList::*)() const) &IFSelect_SignatureList::NbNulls, "Returns the count of null entities");
cls_IFSelect_SignatureList.def("NbTimes", (Standard_Integer (IFSelect_SignatureList::*)(const Standard_CString) const) &IFSelect_SignatureList::NbTimes, "Returns the number of times a signature was counted, 0 if it has not been recorded at all", py::arg("sign"));
cls_IFSelect_SignatureList.def("Entities", (opencascade::handle<TColStd_HSequenceOfTransient> (IFSelect_SignatureList::*)(const Standard_CString) const) &IFSelect_SignatureList::Entities, "Returns the list of entities attached to a signature It is empty if <sign> has not been recorded It is a Null Handle if the list of entities is not known", py::arg("sign"));
cls_IFSelect_SignatureList.def("SetName", (void (IFSelect_SignatureList::*)(const Standard_CString)) &IFSelect_SignatureList::SetName, "Defines a name for a SignatureList (used to print it)", py::arg("name"));
cls_IFSelect_SignatureList.def("Name", (Standard_CString (IFSelect_SignatureList::*)() const) &IFSelect_SignatureList::Name, "Returns the recorded Name. Remark : default is '...' (no SetName called)");
cls_IFSelect_SignatureList.def("PrintCount", (void (IFSelect_SignatureList::*)(const opencascade::handle<Message_Messenger> &) const) &IFSelect_SignatureList::PrintCount, "Prints the counts of items (not the list)", py::arg("S"));
cls_IFSelect_SignatureList.def("PrintList", [](IFSelect_SignatureList &self, const opencascade::handle<Message_Messenger> & a0, const opencascade::handle<Interface_InterfaceModel> & a1) -> void { return self.PrintList(a0, a1); });
cls_IFSelect_SignatureList.def("PrintList", (void (IFSelect_SignatureList::*)(const opencascade::handle<Message_Messenger> &, const opencascade::handle<Interface_InterfaceModel> &, const IFSelect_PrintCount) const) &IFSelect_SignatureList::PrintList, "Prints the lists of items, if they are present (else, prints a message 'no list available') Uses <model> to determine for each entity to be listed, its number, and its specific identifier (by PrintLabel) <mod> gives a mode for printing : - CountByItem : just count (as PrintCount) - ShortByItem : minimum i.e. count plus 5 first entity numbers - ShortByItem(D) complete list of entity numbers (0: 'Global') - EntitiesByItem : list of (entity number/PrintLabel from the model) other modes are ignored", py::arg("S"), py::arg("model"), py::arg("mod"));
cls_IFSelect_SignatureList.def("PrintSum", (void (IFSelect_SignatureList::*)(const opencascade::handle<Message_Messenger> &) const) &IFSelect_SignatureList::PrintSum, "Prints a summary Item which has the greatest count of entities For items which are numeric values : their count, maximum, minimum values, cumul, average", py::arg("S"));
cls_IFSelect_SignatureList.def_static("get_type_name_", (const char * (*)()) &IFSelect_SignatureList::get_type_name, "None");
cls_IFSelect_SignatureList.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SignatureList::get_type_descriptor, "None");
cls_IFSelect_SignatureList.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SignatureList::*)() const) &IFSelect_SignatureList::DynamicType, "None");

// Enums

}