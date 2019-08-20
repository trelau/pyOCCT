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
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Interface_Protocol.hxx>
#include <IFSelect_AppliedModifiers.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_HGraph.hxx>
#include <Interface_Graph.hxx>
#include <IFSelect_GeneralModifier.hxx>
#include <Standard_Transient.hxx>
#include <Interface_Check.hxx>
#include <Interface_CheckIterator.hxx>
#include <TCollection_AsciiString.hxx>
#include <IFSelect_ContextWrite.hxx>

void bind_IFSelect_ContextWrite(py::module &mod){

py::class_<IFSelect_ContextWrite, std::unique_ptr<IFSelect_ContextWrite>> cls_IFSelect_ContextWrite(mod, "IFSelect_ContextWrite", "This class gathers various informations used by File Modifiers apart from the writer object, which is specific of the norm and of the physical format");

// Constructors
cls_IFSelect_ContextWrite.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &, const opencascade::handle<IFSelect_AppliedModifiers> &, const Standard_CString>(), py::arg("model"), py::arg("proto"), py::arg("applieds"), py::arg("filename"));
cls_IFSelect_ContextWrite.def(py::init<const opencascade::handle<Interface_HGraph> &, const opencascade::handle<Interface_Protocol> &, const opencascade::handle<IFSelect_AppliedModifiers> &, const Standard_CString>(), py::arg("hgraph"), py::arg("proto"), py::arg("applieds"), py::arg("filename"));

// Fields

// Methods
// cls_IFSelect_ContextWrite.def_static("operator new_", (void * (*)(size_t)) &IFSelect_ContextWrite::operator new, "None", py::arg("theSize"));
// cls_IFSelect_ContextWrite.def_static("operator delete_", (void (*)(void *)) &IFSelect_ContextWrite::operator delete, "None", py::arg("theAddress"));
// cls_IFSelect_ContextWrite.def_static("operator new[]_", (void * (*)(size_t)) &IFSelect_ContextWrite::operator new[], "None", py::arg("theSize"));
// cls_IFSelect_ContextWrite.def_static("operator delete[]_", (void (*)(void *)) &IFSelect_ContextWrite::operator delete[], "None", py::arg("theAddress"));
// cls_IFSelect_ContextWrite.def_static("operator new_", (void * (*)(size_t, void *)) &IFSelect_ContextWrite::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IFSelect_ContextWrite.def_static("operator delete_", (void (*)(void *, void *)) &IFSelect_ContextWrite::operator delete, "None", py::arg(""), py::arg(""));
cls_IFSelect_ContextWrite.def("Model", (opencascade::handle<Interface_InterfaceModel> (IFSelect_ContextWrite::*)() const) &IFSelect_ContextWrite::Model, "Returns the Model");
cls_IFSelect_ContextWrite.def("Protocol", (opencascade::handle<Interface_Protocol> (IFSelect_ContextWrite::*)() const) &IFSelect_ContextWrite::Protocol, "Returns the Protocol;");
cls_IFSelect_ContextWrite.def("FileName", (Standard_CString (IFSelect_ContextWrite::*)() const) &IFSelect_ContextWrite::FileName, "Returns the File Name");
cls_IFSelect_ContextWrite.def("AppliedModifiers", (opencascade::handle<IFSelect_AppliedModifiers> (IFSelect_ContextWrite::*)() const) &IFSelect_ContextWrite::AppliedModifiers, "Returns the object AppliedModifiers");
cls_IFSelect_ContextWrite.def("Graph", (const Interface_Graph & (IFSelect_ContextWrite::*)()) &IFSelect_ContextWrite::Graph, "Returns the Graph, either given when created, else created the first time it is queried");
cls_IFSelect_ContextWrite.def("NbModifiers", (Standard_Integer (IFSelect_ContextWrite::*)() const) &IFSelect_ContextWrite::NbModifiers, "Returns the count of recorded File Modifiers");
cls_IFSelect_ContextWrite.def("SetModifier", (Standard_Boolean (IFSelect_ContextWrite::*)(const Standard_Integer)) &IFSelect_ContextWrite::SetModifier, "Sets active the File Modifier n0 <numod> Then, it prepares the list of entities to consider, if any Returns False if <numod> out of range", py::arg("numod"));
cls_IFSelect_ContextWrite.def("FileModifier", (opencascade::handle<IFSelect_GeneralModifier> (IFSelect_ContextWrite::*)() const) &IFSelect_ContextWrite::FileModifier, "Returns the currently active File Modifier. Cast to be done Null if not properly set : must be test IsNull after casting");
cls_IFSelect_ContextWrite.def("IsForNone", (Standard_Boolean (IFSelect_ContextWrite::*)() const) &IFSelect_ContextWrite::IsForNone, "Returns True if no modifier is currently set");
cls_IFSelect_ContextWrite.def("IsForAll", (Standard_Boolean (IFSelect_ContextWrite::*)() const) &IFSelect_ContextWrite::IsForAll, "Returns True if the current modifier is to be applied to the whole model. Else, a restricted list of selected entities is defined, it can be exploited by the File Modifier");
cls_IFSelect_ContextWrite.def("NbEntities", (Standard_Integer (IFSelect_ContextWrite::*)() const) &IFSelect_ContextWrite::NbEntities, "Returns the total count of selected entities");
cls_IFSelect_ContextWrite.def("Start", (void (IFSelect_ContextWrite::*)()) &IFSelect_ContextWrite::Start, "Starts an iteration on selected items. It takes into account IsForAll/IsForNone, by really iterating on all selected items.");
cls_IFSelect_ContextWrite.def("More", (Standard_Boolean (IFSelect_ContextWrite::*)() const) &IFSelect_ContextWrite::More, "Returns True until the iteration has finished");
cls_IFSelect_ContextWrite.def("Next", (void (IFSelect_ContextWrite::*)()) &IFSelect_ContextWrite::Next, "Advances the iteration");
cls_IFSelect_ContextWrite.def("Value", (opencascade::handle<Standard_Transient> (IFSelect_ContextWrite::*)() const) &IFSelect_ContextWrite::Value, "Returns the current selected entity in the model");
cls_IFSelect_ContextWrite.def("AddCheck", (void (IFSelect_ContextWrite::*)(const opencascade::handle<Interface_Check> &)) &IFSelect_ContextWrite::AddCheck, "Adds a Check to the CheckList. If it is empty, nothing is done If it concerns an Entity from the Model (by SetEntity) to which another Check is attached, it is merged to it. Else, it is added or merged as to GlobalCheck.", py::arg("check"));
cls_IFSelect_ContextWrite.def("AddWarning", [](IFSelect_ContextWrite &self, const opencascade::handle<Standard_Transient> & a0, const Standard_CString a1) -> void { return self.AddWarning(a0, a1); });
cls_IFSelect_ContextWrite.def("AddWarning", (void (IFSelect_ContextWrite::*)(const opencascade::handle<Standard_Transient> &, const Standard_CString, const Standard_CString)) &IFSelect_ContextWrite::AddWarning, "Adds a Warning Message for an Entity from the Model If <start> is not an Entity from the model (e.g. the model itself) this message is added to Global Check.", py::arg("start"), py::arg("mess"), py::arg("orig"));
cls_IFSelect_ContextWrite.def("AddFail", [](IFSelect_ContextWrite &self, const opencascade::handle<Standard_Transient> & a0, const Standard_CString a1) -> void { return self.AddFail(a0, a1); });
cls_IFSelect_ContextWrite.def("AddFail", (void (IFSelect_ContextWrite::*)(const opencascade::handle<Standard_Transient> &, const Standard_CString, const Standard_CString)) &IFSelect_ContextWrite::AddFail, "Adds a Fail Message for an Entity from the Model If <start> is not an Entity from the model (e.g. the model itself) this message is added to Global Check.", py::arg("start"), py::arg("mess"), py::arg("orig"));
cls_IFSelect_ContextWrite.def("CCheck", [](IFSelect_ContextWrite &self) -> opencascade::handle<Interface_Check> { return self.CCheck(); });
cls_IFSelect_ContextWrite.def("CCheck", (opencascade::handle<Interface_Check> (IFSelect_ContextWrite::*)(const Standard_Integer)) &IFSelect_ContextWrite::CCheck, "Returns a Check given an Entity number (in the Model) by default a Global Check. Creates it the first time. It can then be acknowledged on the spot, in condition that the caller works by reference ('Interface_Check& check = ...')", py::arg("num"));
cls_IFSelect_ContextWrite.def("CCheck", (opencascade::handle<Interface_Check> (IFSelect_ContextWrite::*)(const opencascade::handle<Standard_Transient> &)) &IFSelect_ContextWrite::CCheck, "Returns a Check attached to an Entity from the Model It can then be acknowledged on the spot, in condition that the caller works by reference ('Interface_Check& check = ...')", py::arg("start"));
cls_IFSelect_ContextWrite.def("CheckList", (Interface_CheckIterator (IFSelect_ContextWrite::*)() const) &IFSelect_ContextWrite::CheckList, "Returns the complete CheckList");

// Enums

}