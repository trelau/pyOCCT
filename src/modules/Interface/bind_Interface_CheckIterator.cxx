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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Interface_CheckIterator.hxx>
#include <Interface_Check.hxx>
#include <Standard_Transient.hxx>
#include <Interface_CheckStatus.hxx>
#include <TColStd_HSequenceOfTransient.hxx>
#include <Message_Messenger.hxx>
#include <Interface_HSequenceOfCheck.hxx>
#include <TColStd_HSequenceOfInteger.hxx>
#include <TCollection_AsciiString.hxx>
#include <Interface_IntVal.hxx>

void bind_Interface_CheckIterator(py::module &mod){

py::class_<Interface_CheckIterator> cls_Interface_CheckIterator(mod, "Interface_CheckIterator", "Result of a Check operation (especially from InterfaceModel)");

// Constructors
cls_Interface_CheckIterator.def(py::init<>());
cls_Interface_CheckIterator.def(py::init<const Standard_CString>(), py::arg("name"));

// Fields

// Methods
// cls_Interface_CheckIterator.def_static("operator new_", (void * (*)(size_t)) &Interface_CheckIterator::operator new, "None", py::arg("theSize"));
// cls_Interface_CheckIterator.def_static("operator delete_", (void (*)(void *)) &Interface_CheckIterator::operator delete, "None", py::arg("theAddress"));
// cls_Interface_CheckIterator.def_static("operator new[]_", (void * (*)(size_t)) &Interface_CheckIterator::operator new[], "None", py::arg("theSize"));
// cls_Interface_CheckIterator.def_static("operator delete[]_", (void (*)(void *)) &Interface_CheckIterator::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_CheckIterator.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_CheckIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_CheckIterator.def_static("operator delete_", (void (*)(void *, void *)) &Interface_CheckIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_CheckIterator.def("SetName", (void (Interface_CheckIterator::*)(const Standard_CString)) &Interface_CheckIterator::SetName, "Sets / Changes the name", py::arg("name"));
cls_Interface_CheckIterator.def("Name", (Standard_CString (Interface_CheckIterator::*)() const) &Interface_CheckIterator::Name, "Returns the recorded name (can be empty)");
cls_Interface_CheckIterator.def("SetModel", (void (Interface_CheckIterator::*)(const opencascade::handle<Interface_InterfaceModel> &)) &Interface_CheckIterator::SetModel, "Defines a Model, used to locate entities (not required, if it is absent, entities are simply less documented)", py::arg("model"));
cls_Interface_CheckIterator.def("Model", (opencascade::handle<Interface_InterfaceModel> (Interface_CheckIterator::*)() const) &Interface_CheckIterator::Model, "Returns the stored model (can be a null handle)");
cls_Interface_CheckIterator.def("Clear", (void (Interface_CheckIterator::*)()) &Interface_CheckIterator::Clear, "Clears the list of checks");
cls_Interface_CheckIterator.def("Merge", (void (Interface_CheckIterator::*)(Interface_CheckIterator &)) &Interface_CheckIterator::Merge, "Merges another CheckIterator into <me>, i.e. adds each of its Checks. Content of <other> remains unchanged. Takes also the Model but not the Name", py::arg("other"));
cls_Interface_CheckIterator.def("Add", [](Interface_CheckIterator &self, const opencascade::handle<Interface_Check> & a0) -> void { return self.Add(a0); });
cls_Interface_CheckIterator.def("Add", (void (Interface_CheckIterator::*)(const opencascade::handle<Interface_Check> &, const Standard_Integer)) &Interface_CheckIterator::Add, "Adds a Check to the list to be iterated This Check is Accompanied by Entity Number in the Model (0 for Global Check or Entity unknown in the Model), if 0 and Model is recorded in <me>, it is computed", py::arg("ach"), py::arg("num"));
cls_Interface_CheckIterator.def("Check", (const opencascade::handle<Interface_Check> & (Interface_CheckIterator::*)(const Standard_Integer) const) &Interface_CheckIterator::Check, "Returns the Check which was attached to an Entity given its Number in the Model. <num>=0 is for the Global Check. If no Check was recorded for this Number, returns an empty Check. Remark : Works apart from the iteration methods (no interference)", py::arg("num"));
cls_Interface_CheckIterator.def("Check", (const opencascade::handle<Interface_Check> & (Interface_CheckIterator::*)(const opencascade::handle<Standard_Transient> &) const) &Interface_CheckIterator::Check, "Returns the Check attached to an Entity If no Check was recorded for this Entity, returns an empty Check. Remark : Works apart from the iteration methods (no interference)", py::arg("ent"));
cls_Interface_CheckIterator.def("CCheck", (opencascade::handle<Interface_Check> & (Interface_CheckIterator::*)(const Standard_Integer)) &Interface_CheckIterator::CCheck, "Returns the Check bound to an Entity Number (0 : Global) in order to be consulted or completed on the spot I.e. returns the Check if is already exists, or adds it then returns the new empty Check", py::arg("num"));
cls_Interface_CheckIterator.def("CCheck", (opencascade::handle<Interface_Check> & (Interface_CheckIterator::*)(const opencascade::handle<Standard_Transient> &)) &Interface_CheckIterator::CCheck, "Returns the Check bound to an Entity, in order to be consulted or completed on the spot I.e. returns the Check if is already exists, or adds it then returns the new empty Check", py::arg("ent"));
cls_Interface_CheckIterator.def("IsEmpty", (Standard_Boolean (Interface_CheckIterator::*)(const Standard_Boolean) const) &Interface_CheckIterator::IsEmpty, "Returns True if : no Fail has been recorded if <failsonly> is True, no Check at all if <failsonly> is False", py::arg("failsonly"));
cls_Interface_CheckIterator.def("Status", (Interface_CheckStatus (Interface_CheckIterator::*)() const) &Interface_CheckIterator::Status, "Returns worst status among : OK, Warning, Fail");
cls_Interface_CheckIterator.def("Complies", (Standard_Boolean (Interface_CheckIterator::*)(const Interface_CheckStatus) const) &Interface_CheckIterator::Complies, "Tells if this check list complies with a given status : OK (i.e. empty), Warning (at least one Warning, but no Fail), Fail (at least one), Message (not OK), NoFail, Any", py::arg("status"));
cls_Interface_CheckIterator.def("Extract", (Interface_CheckIterator (Interface_CheckIterator::*)(const Interface_CheckStatus) const) &Interface_CheckIterator::Extract, "Returns a CheckIterator which contains the checks which comply with a given status Each check is added completely (no split Warning/Fail)", py::arg("status"));
cls_Interface_CheckIterator.def("Extract", (Interface_CheckIterator (Interface_CheckIterator::*)(const Standard_CString, const Standard_Integer, const Interface_CheckStatus) const) &Interface_CheckIterator::Extract, "Returns a CheckIterator which contains the check which comply with a message, plus some conditions as follows : <incl> = 0 : <mess> exactly matches one of the messages <incl> < 0 : <mess> is contained by one of the messages <incl> > 0 : <mess> contains one of the messages For <status> : for CheckWarning and CheckFail, considers only resp. Warning or Check messages. for CheckAny, considers all other values are ignored (answer will be false) Each Check which complies is entirely taken", py::arg("mess"), py::arg("incl"), py::arg("status"));
cls_Interface_CheckIterator.def("Remove", (Standard_Boolean (Interface_CheckIterator::*)(const Standard_CString, const Standard_Integer, const Interface_CheckStatus)) &Interface_CheckIterator::Remove, "Removes the messages of all Checks, under these conditions : <incl> = 0 : <mess> exactly matches one of the messages <incl> < 0 : <mess> is contained by one of the messages <incl> > 0 : <mess> contains one of the messages For <status> : for CheckWarning and CheckFail, considers only resp. Warning or Check messages. for CheckAny, considers all other values are ignored (nothing is done) Returns True if at least one message has been removed, False else", py::arg("mess"), py::arg("incl"), py::arg("status"));
cls_Interface_CheckIterator.def("Checkeds", (opencascade::handle<TColStd_HSequenceOfTransient> (Interface_CheckIterator::*)(const Standard_Boolean, const Standard_Boolean) const) &Interface_CheckIterator::Checkeds, "Returns the list of entities concerned by a Check Only fails if <failsonly> is True, else all non-empty checks If <global> is true, adds the model for a global check Else, global check is ignored", py::arg("failsonly"), py::arg("global"));
cls_Interface_CheckIterator.def("Start", (void (Interface_CheckIterator::*)() const) &Interface_CheckIterator::Start, "Starts Iteration. Thus, it is possible to restart it Remark : an iteration may be done with a const Iterator While its content is modified (through a pointer), this allows to give it as a const argument to a function");
cls_Interface_CheckIterator.def("More", (Standard_Boolean (Interface_CheckIterator::*)() const) &Interface_CheckIterator::More, "Returns True if there are more Checks to get");
cls_Interface_CheckIterator.def("Next", (void (Interface_CheckIterator::*)() const) &Interface_CheckIterator::Next, "Sets Iteration to next Item");
cls_Interface_CheckIterator.def("Value", (const opencascade::handle<Interface_Check> & (Interface_CheckIterator::*)() const) &Interface_CheckIterator::Value, "Returns Check currently Iterated It brings all other informations (status, messages, ...) The Number of the Entity in the Model is given by Number below");
cls_Interface_CheckIterator.def("Number", (Standard_Integer (Interface_CheckIterator::*)() const) &Interface_CheckIterator::Number, "Returns Number of Entity for the Check currently iterated or 0 for GlobalCheck");
cls_Interface_CheckIterator.def("Print", [](Interface_CheckIterator &self, const opencascade::handle<Message_Messenger> & a0, const Standard_Boolean a1) -> void { return self.Print(a0, a1); });
cls_Interface_CheckIterator.def("Print", (void (Interface_CheckIterator::*)(const opencascade::handle<Message_Messenger> &, const Standard_Boolean, const Standard_Integer) const) &Interface_CheckIterator::Print, "Prints the list of Checks with their attached Numbers If <failsonly> is True, prints only Fail messages If <failsonly> is False, prints all messages If <final> = 0 (D), prints also original messages if different If <final> < 0, prints only original messages If <final> > 0, prints only final messages It uses the recorded Model if it is defined Remark : Works apart from the iteration methods (no interference)", py::arg("S"), py::arg("failsonly"), py::arg("final"));
cls_Interface_CheckIterator.def("Print", [](Interface_CheckIterator &self, const opencascade::handle<Message_Messenger> & a0, const opencascade::handle<Interface_InterfaceModel> & a1, const Standard_Boolean a2) -> void { return self.Print(a0, a1, a2); });
cls_Interface_CheckIterator.def("Print", (void (Interface_CheckIterator::*)(const opencascade::handle<Message_Messenger> &, const opencascade::handle<Interface_InterfaceModel> &, const Standard_Boolean, const Standard_Integer) const) &Interface_CheckIterator::Print, "Works as Print without a model, but for entities which have no attached number (Number not positive), tries to compute this Number from <model> and displays 'original' or 'computed'", py::arg("S"), py::arg("model"), py::arg("failsonly"), py::arg("final"));
cls_Interface_CheckIterator.def("Destroy", (void (Interface_CheckIterator::*)()) &Interface_CheckIterator::Destroy, "Clears data of iteration");

// Enums

}