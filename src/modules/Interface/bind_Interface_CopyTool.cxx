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
#include <Interface_GeneralLib.hxx>
#include <Interface_Protocol.hxx>
#include <Interface_CopyControl.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Transient.hxx>
#include <Interface_EntityIterator.hxx>
#include <Interface_CopyMap.hxx>
#include <Interface_BitMap.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <Interface_GeneralModule.hxx>
#include <Interface_CopyTool.hxx>

void bind_Interface_CopyTool(py::module &mod){

py::class_<Interface_CopyTool, std::unique_ptr<Interface_CopyTool>> cls_Interface_CopyTool(mod, "Interface_CopyTool", "Performs Deep Copies of sets of Entities Allows to perform Copy of Interface Entities from a Model to another one. Works by calling general services GetFromAnother and GetImplied. Uses a CopyMap to bind a unique Result to each Copied Entity");

// Constructors
cls_Interface_CopyTool.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const Interface_GeneralLib &>(), py::arg("amodel"), py::arg("lib"));
cls_Interface_CopyTool.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &>(), py::arg("amodel"), py::arg("protocol"));
cls_Interface_CopyTool.def(py::init<const opencascade::handle<Interface_InterfaceModel> &>(), py::arg("amodel"));

// Fields

// Methods
// cls_Interface_CopyTool.def_static("operator new_", (void * (*)(size_t)) &Interface_CopyTool::operator new, "None", py::arg("theSize"));
// cls_Interface_CopyTool.def_static("operator delete_", (void (*)(void *)) &Interface_CopyTool::operator delete, "None", py::arg("theAddress"));
// cls_Interface_CopyTool.def_static("operator new[]_", (void * (*)(size_t)) &Interface_CopyTool::operator new[], "None", py::arg("theSize"));
// cls_Interface_CopyTool.def_static("operator delete[]_", (void (*)(void *)) &Interface_CopyTool::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_CopyTool.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_CopyTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_CopyTool.def_static("operator delete_", (void (*)(void *, void *)) &Interface_CopyTool::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_CopyTool.def("Model", (opencascade::handle<Interface_InterfaceModel> (Interface_CopyTool::*)() const) &Interface_CopyTool::Model, "Returns the Model on which the CopyTool works");
cls_Interface_CopyTool.def("SetControl", (void (Interface_CopyTool::*)(const opencascade::handle<Interface_CopyControl> &)) &Interface_CopyTool::SetControl, "Changes the Map of Result for another one. This allows to work with a more sophisticated Mapping Control than the Standard one which is CopyMap (e.g. TransferProcess from Transfer)", py::arg("othermap"));
cls_Interface_CopyTool.def("Control", (opencascade::handle<Interface_CopyControl> (Interface_CopyTool::*)() const) &Interface_CopyTool::Control, "Returns the object used for Control");
cls_Interface_CopyTool.def("Clear", (void (Interface_CopyTool::*)()) &Interface_CopyTool::Clear, "Clears Transfer List. Gets Ready to begin another Transfer");
cls_Interface_CopyTool.def("Copy", (Standard_Boolean (Interface_CopyTool::*)(const opencascade::handle<Standard_Transient> &, opencascade::handle<Standard_Transient> &, const Standard_Boolean, const Standard_Boolean)) &Interface_CopyTool::Copy, "Creates the CounterPart of an Entity (by ShallowCopy), Binds it, then Copies the content of the former Entity to the other one (same Type), by call to the General Service Library It may command the Copy of Referenced Entities Then, its returns True.", py::arg("entfrom"), py::arg("entto"), py::arg("mapped"), py::arg("errstat"));
cls_Interface_CopyTool.def("Transferred", (opencascade::handle<Standard_Transient> (Interface_CopyTool::*)(const opencascade::handle<Standard_Transient> &)) &Interface_CopyTool::Transferred, "Transfers one Entity, if not yet bound to a result Remark : For an Entity which is reported in the Starting Model, the ReportEntity will also be copied with its Content if it has one (at least ShallowCopy; Complete Copy if the Protocol recognizes the Content : see method Copy)", py::arg("ent"));
cls_Interface_CopyTool.def("Bind", (void (Interface_CopyTool::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &)) &Interface_CopyTool::Bind, "Defines a Result for the Transfer of a Starting object. Used by method Transferred (which performs a normal Copy), but can also be called to enforce a result : in the latter case, the enforced result must be compatible with the other Transfers which are performed", py::arg("ent"), py::arg("res"));
cls_Interface_CopyTool.def("Search", (Standard_Boolean (Interface_CopyTool::*)(const opencascade::handle<Standard_Transient> &, opencascade::handle<Standard_Transient> &) const) &Interface_CopyTool::Search, "Search for the result of a Starting Object (i.e. an Entity) Returns True if a Result is Bound (and fills 'result') Returns False if no result is Bound", py::arg("ent"), py::arg("res"));
cls_Interface_CopyTool.def("ClearLastFlags", (void (Interface_CopyTool::*)()) &Interface_CopyTool::ClearLastFlags, "Clears LastFlags only. This allows to know what Entities are copied after its call (see method LastCopiedAfter). It can be used when copies are done by increments, which must be distinghished. ClearLastFlags is also called by Clear.");
cls_Interface_CopyTool.def("LastCopiedAfter", (Standard_Integer (Interface_CopyTool::*)(const Standard_Integer, opencascade::handle<Standard_Transient> &, opencascade::handle<Standard_Transient> &) const) &Interface_CopyTool::LastCopiedAfter, "Returns an copied Entity and its Result which were operated after last call to ClearLastFlags. It returns the first 'Last Copied Entity' which Number follows <numfrom>, Zero if none. It is used in a loop as follow : Integer num = 0; while ( (num = CopyTool.LastCopiedAfter(num,ent,res)) ) { .. Process Starting <ent> and its Result <res> }", py::arg("numfrom"), py::arg("ent"), py::arg("res"));
cls_Interface_CopyTool.def("TransferEntity", (void (Interface_CopyTool::*)(const opencascade::handle<Standard_Transient> &)) &Interface_CopyTool::TransferEntity, "Transfers one Entity and records result into the Transfer List Calls method Transferred", py::arg("ent"));
cls_Interface_CopyTool.def("RenewImpliedRefs", (void (Interface_CopyTool::*)()) &Interface_CopyTool::RenewImpliedRefs, "Renews the Implied References. These References do not involve Copying of referenced Entities. For such a Reference, if the Entity which defines it AND the referenced Entity are both copied, then this Reference is renewed. Else it is deleted in the copied Entities. Remark : this concerns only some specific references, such as 'back pointers'.");
cls_Interface_CopyTool.def("FillModel", (void (Interface_CopyTool::*)(const opencascade::handle<Interface_InterfaceModel> &)) &Interface_CopyTool::FillModel, "Fills a Model with the result of the transfer (TransferList) Commands copy of Header too, and calls RenewImpliedRefs", py::arg("bmodel"));
cls_Interface_CopyTool.def("CompleteResult", [](Interface_CopyTool &self) -> Interface_EntityIterator { return self.CompleteResult(); });
cls_Interface_CopyTool.def("CompleteResult", (Interface_EntityIterator (Interface_CopyTool::*)(const Standard_Boolean) const) &Interface_CopyTool::CompleteResult, "Returns the complete list of copied Entities If <withreports> is given True, the entities which were reported in the Starting Model are replaced in the list by the copied ReportEntities", py::arg("withreports"));
cls_Interface_CopyTool.def("RootResult", [](Interface_CopyTool &self) -> Interface_EntityIterator { return self.RootResult(); });
cls_Interface_CopyTool.def("RootResult", (Interface_EntityIterator (Interface_CopyTool::*)(const Standard_Boolean) const) &Interface_CopyTool::RootResult, "Returns the list of Root copied Entities (those which were asked for copy by the user of CopyTool, not by copying another Entity)", py::arg("withreports"));

// Enums

}