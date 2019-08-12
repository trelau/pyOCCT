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
#include <IFSelect_Dispatch.hxx>
#include <IFSelect_GeneralModifier.hxx>
#include <IFSelect_Modifier.hxx>
#include <TCollection_HAsciiString.hxx>
#include <TCollection_AsciiString.hxx>
#include <IFSelect_ShareOut.hxx>
#include <Standard_Type.hxx>
#include <IFSelect_TSeqOfDispatch.hxx>
#include <IFSelect_SequenceOfGeneralModifier.hxx>

void bind_IFSelect_ShareOut(py::module &mod){

py::class_<IFSelect_ShareOut, opencascade::handle<IFSelect_ShareOut>, Standard_Transient> cls_IFSelect_ShareOut(mod, "IFSelect_ShareOut", "This class gathers the informations required to produce one or several file(s) from the content of an InterfaceModel (passing through the creation of intermediate Models).");

// Constructors
cls_IFSelect_ShareOut.def(py::init<>());

// Fields

// Methods
cls_IFSelect_ShareOut.def("Clear", (void (IFSelect_ShareOut::*)(const Standard_Boolean)) &IFSelect_ShareOut::Clear, "Removes in one operation all the Dispatches with their Idents Also clears all informations about Names, and all Results but naming informations which are : - kept if <onlydisp> is True. - cleared if <onlydisp> is False (complete clearing) If <onlydisp> is True, that's all. Else, clears also Modifiers", py::arg("onlydisp"));
cls_IFSelect_ShareOut.def("ClearResult", (void (IFSelect_ShareOut::*)(const Standard_Boolean)) &IFSelect_ShareOut::ClearResult, "Clears all data produced (apart from Dispatches, etc...) if <alsoname> is True, all is cleared. Else, informations about produced Names are kept (to maintain unicity of naming across clearings)", py::arg("alsoname"));
cls_IFSelect_ShareOut.def("RemoveItem", (Standard_Boolean (IFSelect_ShareOut::*)(const opencascade::handle<Standard_Transient> &)) &IFSelect_ShareOut::RemoveItem, "Removes an item, which can be, either a Dispatch (removed from the list of Dispatches), or a GeneralModifier (removed from the list of Model Modifiers or from the list of File Modifiers according to its type). Returns True if done, False if has not been found or if it is neither a Dispatch, nor a Modifier.", py::arg("item"));
cls_IFSelect_ShareOut.def("LastRun", (Standard_Integer (IFSelect_ShareOut::*)() const) &IFSelect_ShareOut::LastRun, "Returns the rank of last run item (ClearResult resets it to 0)");
cls_IFSelect_ShareOut.def("SetLastRun", (void (IFSelect_ShareOut::*)(const Standard_Integer)) &IFSelect_ShareOut::SetLastRun, "Records a new alue for the rank of last run item", py::arg("last"));
cls_IFSelect_ShareOut.def("NbDispatches", (Standard_Integer (IFSelect_ShareOut::*)() const) &IFSelect_ShareOut::NbDispatches, "Returns the count of Dispatches");
cls_IFSelect_ShareOut.def("DispatchRank", (Standard_Integer (IFSelect_ShareOut::*)(const opencascade::handle<IFSelect_Dispatch> &) const) &IFSelect_ShareOut::DispatchRank, "Returns the Rank of a Dispatch, given its Value (Handle). Returns 0 if the Dispatch is unknown in the ShareOut", py::arg("disp"));
cls_IFSelect_ShareOut.def("Dispatch", (const opencascade::handle<IFSelect_Dispatch> & (IFSelect_ShareOut::*)(const Standard_Integer) const) &IFSelect_ShareOut::Dispatch, "Returns a Dispatch, given its rank in the list", py::arg("num"));
cls_IFSelect_ShareOut.def("AddDispatch", (void (IFSelect_ShareOut::*)(const opencascade::handle<IFSelect_Dispatch> &)) &IFSelect_ShareOut::AddDispatch, "Adds a Dispatch to the list", py::arg("disp"));
cls_IFSelect_ShareOut.def("RemoveDispatch", (Standard_Boolean (IFSelect_ShareOut::*)(const Standard_Integer)) &IFSelect_ShareOut::RemoveDispatch, "Removes a Dispatch, given its rank in the list Returns True if done, False if rank is not between (LastRun + 1) and (NbDispatches)", py::arg("rank"));
cls_IFSelect_ShareOut.def("AddModifier", (void (IFSelect_ShareOut::*)(const opencascade::handle<IFSelect_GeneralModifier> &, const Standard_Integer)) &IFSelect_ShareOut::AddModifier, "Sets a Modifier to be applied on all Dispatches to be run If <modifier> is a ModelModifier, adds it to the list of Model Modifiers; else to the list of File Modifiers By default (atnum = 0) at the end of the list, else at <atnum> Each Modifier is used, after each copy of a packet of Entities into a Model : its criteria are checked and if they are OK, the method Perform of this Modifier is run.", py::arg("modifier"), py::arg("atnum"));
cls_IFSelect_ShareOut.def("AddModifier", (void (IFSelect_ShareOut::*)(const opencascade::handle<IFSelect_GeneralModifier> &, const Standard_Integer, const Standard_Integer)) &IFSelect_ShareOut::AddModifier, "Sets a Modifier to be applied on the Dispatch <dispnum> If <modifier> is a ModelModifier, adds it to the list of Model Modifiers; else to the list of File Modifiers This is the same list as for all Dispatches, but the Modifier is qualified to be applied to one Dispatch only Then, <atnum> refers to the entire list By default (atnum = 0) at the end of the list, else at <atnum> Remark : if the Modifier was already in the list and if <atnum> = 0, the Modifier is not moved, but only qualified for a Dispatch", py::arg("modifier"), py::arg("dispnum"), py::arg("atnum"));
cls_IFSelect_ShareOut.def("AddModif", [](IFSelect_ShareOut &self, const opencascade::handle<IFSelect_GeneralModifier> & a0, const Standard_Boolean a1) -> void { return self.AddModif(a0, a1); });
cls_IFSelect_ShareOut.def("AddModif", (void (IFSelect_ShareOut::*)(const opencascade::handle<IFSelect_GeneralModifier> &, const Standard_Boolean, const Standard_Integer)) &IFSelect_ShareOut::AddModif, "Adds a Modifier to the list of Modifiers : Model Modifiers if <formodel> is True, File Modifiers else (internal).", py::arg("modifier"), py::arg("formodel"), py::arg("atnum"));
cls_IFSelect_ShareOut.def("NbModifiers", (Standard_Integer (IFSelect_ShareOut::*)(const Standard_Boolean) const) &IFSelect_ShareOut::NbModifiers, "Returns count of Modifiers (which apply to complete Models) : Model Modifiers if <formodel> is True, File Modifiers else", py::arg("formodel"));
cls_IFSelect_ShareOut.def("GeneralModifier", (opencascade::handle<IFSelect_GeneralModifier> (IFSelect_ShareOut::*)(const Standard_Boolean, const Standard_Integer) const) &IFSelect_ShareOut::GeneralModifier, "Returns a Modifier of the list, given its rank : Model Modifiers if <formodel> is True, File Modifiers else", py::arg("formodel"), py::arg("num"));
cls_IFSelect_ShareOut.def("ModelModifier", (opencascade::handle<IFSelect_Modifier> (IFSelect_ShareOut::*)(const Standard_Integer) const) &IFSelect_ShareOut::ModelModifier, "Returns a Modifier of the list of Model Modifiers, duely casted", py::arg("num"));
cls_IFSelect_ShareOut.def("ModifierRank", (Standard_Integer (IFSelect_ShareOut::*)(const opencascade::handle<IFSelect_GeneralModifier> &) const) &IFSelect_ShareOut::ModifierRank, "Gives the rank of a Modifier in the list, 0 if not in the list Model Modifiers if <modifier> is kind of ModelModifer, File Modifiers else", py::arg("modifier"));
cls_IFSelect_ShareOut.def("RemoveModifier", (Standard_Boolean (IFSelect_ShareOut::*)(const Standard_Boolean, const Standard_Integer)) &IFSelect_ShareOut::RemoveModifier, "Removes a Modifier, given it rank in the list : Model Modifiers if <formodel> is True, File Modifiers else Returns True if done, False if <num> is out of range", py::arg("formodel"), py::arg("num"));
cls_IFSelect_ShareOut.def("ChangeModifierRank", (Standard_Boolean (IFSelect_ShareOut::*)(const Standard_Boolean, const Standard_Integer, const Standard_Integer)) &IFSelect_ShareOut::ChangeModifierRank, "Changes the rank of a modifier in the list : Model Modifiers if <formodel> is True, File Modifiers else from <before> to <after> Returns True if done, False else (before or after out of range)", py::arg("formodel"), py::arg("befor"), py::arg("after"));
cls_IFSelect_ShareOut.def("SetRootName", (Standard_Boolean (IFSelect_ShareOut::*)(const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &)) &IFSelect_ShareOut::SetRootName, "Attaches a Root Name to a Dispatch given its rank, as an HAsciiString (standard form). A Null Handle resets this name. Returns True if OK, False if this Name is already attached, for a Dispatch or for Default, or <num> out of range", py::arg("num"), py::arg("name"));
cls_IFSelect_ShareOut.def("HasRootName", (Standard_Boolean (IFSelect_ShareOut::*)(const Standard_Integer) const) &IFSelect_ShareOut::HasRootName, "Returns True if the Dispatch of rank <num> has an attached Root Name. False else, or if num is out of range", py::arg("num"));
cls_IFSelect_ShareOut.def("RootName", (opencascade::handle<TCollection_HAsciiString> (IFSelect_ShareOut::*)(const Standard_Integer) const) &IFSelect_ShareOut::RootName, "Returns the Root bound to a Dispatch, given its rank Returns a Null Handle if not defined", py::arg("num"));
cls_IFSelect_ShareOut.def("RootNumber", (Standard_Integer (IFSelect_ShareOut::*)(const opencascade::handle<TCollection_HAsciiString> &) const) &IFSelect_ShareOut::RootNumber, "Returns an integer value about a given root name : - positive : it's the rank of the Dispatch which has this name - null : this root name is unknown - negative (-1) : this root name is the default root name", py::arg("name"));
cls_IFSelect_ShareOut.def("SetPrefix", (void (IFSelect_ShareOut::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IFSelect_ShareOut::SetPrefix, "Defines or Changes the general Prefix (which is prepended to complete file name generated). If this method is not call, Prefix remains empty", py::arg("pref"));
cls_IFSelect_ShareOut.def("SetDefaultRootName", (Standard_Boolean (IFSelect_ShareOut::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IFSelect_ShareOut::SetDefaultRootName, "Defines or Changes the Default Root Name to a new value (which is used for dispatches which have no attached root name). If this method is not called, DefaultRootName remains empty Returns True if OK, False if this Name is already attached, for a Dispatch or for Default", py::arg("defrt"));
cls_IFSelect_ShareOut.def("SetExtension", (void (IFSelect_ShareOut::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IFSelect_ShareOut::SetExtension, "Defines or Changes the general Extension (which is appended to complete file name generated). If this method is not call, Extension remains empty", py::arg("ext"));
cls_IFSelect_ShareOut.def("Prefix", (opencascade::handle<TCollection_HAsciiString> (IFSelect_ShareOut::*)() const) &IFSelect_ShareOut::Prefix, "Returns the general Prefix. Can be empty.");
cls_IFSelect_ShareOut.def("DefaultRootName", (opencascade::handle<TCollection_HAsciiString> (IFSelect_ShareOut::*)() const) &IFSelect_ShareOut::DefaultRootName, "Returns the Default Root Name. Can be empty.");
cls_IFSelect_ShareOut.def("Extension", (opencascade::handle<TCollection_HAsciiString> (IFSelect_ShareOut::*)() const) &IFSelect_ShareOut::Extension, "Returns the general Extension. Can be empty (not recommanded)");
cls_IFSelect_ShareOut.def("FileName", [](IFSelect_ShareOut &self, const Standard_Integer a0, const Standard_Integer a1) -> TCollection_AsciiString { return self.FileName(a0, a1); });
cls_IFSelect_ShareOut.def("FileName", (TCollection_AsciiString (IFSelect_ShareOut::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer)) &IFSelect_ShareOut::FileName, "Computes the complete file name for a Packet of a Dispatch, given Dispatch Number (Rank), Packet Number, and Count of Packets generated by this Dispatch (0 if unknown)", py::arg("dnum"), py::arg("pnum"), py::arg("nbpack"));
cls_IFSelect_ShareOut.def_static("get_type_name_", (const char * (*)()) &IFSelect_ShareOut::get_type_name, "None");
cls_IFSelect_ShareOut.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_ShareOut::get_type_descriptor, "None");
cls_IFSelect_ShareOut.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_ShareOut::*)() const) &IFSelect_ShareOut::DynamicType, "None");

// Enums

}