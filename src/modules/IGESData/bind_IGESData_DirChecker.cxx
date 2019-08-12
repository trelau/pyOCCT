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
#include <IGESData_DefType.hxx>
#include <Standard_Handle.hxx>
#include <Interface_Check.hxx>
#include <IGESData_IGESEntity.hxx>
#include <IGESData_DirChecker.hxx>

void bind_IGESData_DirChecker(py::module &mod){

py::class_<IGESData_DirChecker, std::unique_ptr<IGESData_DirChecker, Deleter<IGESData_DirChecker>>> cls_IGESData_DirChecker(mod, "IGESData_DirChecker", "This class centralizes general Checks upon an IGES Entity's Directory Part. That is : such field Ignored or Required, or Required with a given Value (for an Integer field) More precise checks can be performed as necessary, by each Entity (method OwnCheck).");

// Constructors
cls_IGESData_DirChecker.def(py::init<>());
cls_IGESData_DirChecker.def(py::init<const Standard_Integer>(), py::arg("atype"));
cls_IGESData_DirChecker.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("atype"), py::arg("aform"));
cls_IGESData_DirChecker.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("atype"), py::arg("aform1"), py::arg("aform2"));

// Fields

// Methods
// cls_IGESData_DirChecker.def_static("operator new_", (void * (*)(size_t)) &IGESData_DirChecker::operator new, "None", py::arg("theSize"));
// cls_IGESData_DirChecker.def_static("operator delete_", (void (*)(void *)) &IGESData_DirChecker::operator delete, "None", py::arg("theAddress"));
// cls_IGESData_DirChecker.def_static("operator new[]_", (void * (*)(size_t)) &IGESData_DirChecker::operator new[], "None", py::arg("theSize"));
// cls_IGESData_DirChecker.def_static("operator delete[]_", (void (*)(void *)) &IGESData_DirChecker::operator delete[], "None", py::arg("theAddress"));
// cls_IGESData_DirChecker.def_static("operator new_", (void * (*)(size_t, void *)) &IGESData_DirChecker::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESData_DirChecker.def_static("operator delete_", (void (*)(void *, void *)) &IGESData_DirChecker::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESData_DirChecker.def("IsSet", (Standard_Boolean (IGESData_DirChecker::*)() const) &IGESData_DirChecker::IsSet, "Returns True if at least one criterium has already been set Allows user to store a DirChecker (static variable) then ask if it has been set before setting it");
cls_IGESData_DirChecker.def("SetDefault", (void (IGESData_DirChecker::*)()) &IGESData_DirChecker::SetDefault, "Sets a DirChecker with most current criteria, that is : Structure Ignored ( worths call Structure(crit = DefVoid) )");
cls_IGESData_DirChecker.def("Structure", (void (IGESData_DirChecker::*)(const IGESData_DefType)) &IGESData_DirChecker::Structure, "Sets Structure criterium. If crit is DefVoid, Ignored : should not be defined If crit is DefReference, Required : must be defined Other values are not taken in account", py::arg("crit"));
cls_IGESData_DirChecker.def("LineFont", (void (IGESData_DirChecker::*)(const IGESData_DefType)) &IGESData_DirChecker::LineFont, "Sets LineFont criterium If crit is DefVoid, Ignored : should not be defined If crit is DefAny, Required : must be defined (value or ref) If crit is DefValue, Required as a Value (error if Reference) Other values are not taken in account", py::arg("crit"));
cls_IGESData_DirChecker.def("LineWeight", (void (IGESData_DirChecker::*)(const IGESData_DefType)) &IGESData_DirChecker::LineWeight, "Sets LineWeight criterium If crit is DefVoid, Ignored : should not be defined If crit is DefValue, Required Other values are not taken in account", py::arg("crit"));
cls_IGESData_DirChecker.def("Color", (void (IGESData_DirChecker::*)(const IGESData_DefType)) &IGESData_DirChecker::Color, "Sets Color criterium If crit is DefVoid, Ignored : should not be defined If crit is DefAny, Required : must be defined (value or ref) Other values are not taken in account", py::arg("crit"));
cls_IGESData_DirChecker.def("GraphicsIgnored", [](IGESData_DirChecker &self) -> void { return self.GraphicsIgnored(); });
cls_IGESData_DirChecker.def("GraphicsIgnored", (void (IGESData_DirChecker::*)(const Standard_Integer)) &IGESData_DirChecker::GraphicsIgnored, "Sets Graphics data (LineFont, LineWeight, Color, Level, View) to be ignored according value of Hierarchy status : If hierarchy is not given, they are Ignored any way (that is, they should not be defined) If hierarchy is given, Graphics are Ignored if the Hierarchy status has the value given in argument 'hierarchy'", py::arg("hierarchy"));
cls_IGESData_DirChecker.def("BlankStatusIgnored", (void (IGESData_DirChecker::*)()) &IGESData_DirChecker::BlankStatusIgnored, "Sets Blank Status to be ignored (should not be defined, or its value should be 0)");
cls_IGESData_DirChecker.def("BlankStatusRequired", (void (IGESData_DirChecker::*)(const Standard_Integer)) &IGESData_DirChecker::BlankStatusRequired, "Sets Blank Status to be required at a given value", py::arg("val"));
cls_IGESData_DirChecker.def("SubordinateStatusIgnored", (void (IGESData_DirChecker::*)()) &IGESData_DirChecker::SubordinateStatusIgnored, "Sets Subordinate Status to be ignored (should not be defined, or its value should be 0)");
cls_IGESData_DirChecker.def("SubordinateStatusRequired", (void (IGESData_DirChecker::*)(const Standard_Integer)) &IGESData_DirChecker::SubordinateStatusRequired, "Sets Subordinate Status to be required at a given value", py::arg("val"));
cls_IGESData_DirChecker.def("UseFlagIgnored", (void (IGESData_DirChecker::*)()) &IGESData_DirChecker::UseFlagIgnored, "Sets Blank Status to be ignored (should not be defined, or its value should be 0)");
cls_IGESData_DirChecker.def("UseFlagRequired", (void (IGESData_DirChecker::*)(const Standard_Integer)) &IGESData_DirChecker::UseFlagRequired, "Sets Blank Status to be required at a given value Give -1 to demand UseFlag not zero (but no precise value req.)", py::arg("val"));
cls_IGESData_DirChecker.def("HierarchyStatusIgnored", (void (IGESData_DirChecker::*)()) &IGESData_DirChecker::HierarchyStatusIgnored, "Sets Hierarchy Status to be ignored (should not be defined, or its value should be 0)");
cls_IGESData_DirChecker.def("HierarchyStatusRequired", (void (IGESData_DirChecker::*)(const Standard_Integer)) &IGESData_DirChecker::HierarchyStatusRequired, "Sets Hierarchy Status to be required at a given value", py::arg("val"));
cls_IGESData_DirChecker.def("Check", (void (IGESData_DirChecker::*)(opencascade::handle<Interface_Check> &, const opencascade::handle<IGESData_IGESEntity> &) const) &IGESData_DirChecker::Check, "Performs the Checks on an IGESEntity, according to the recorded criteria In addition, does minimal Checks, such as admitted range for Status, or presence of Error status in some data (Color, ...)", py::arg("ach"), py::arg("ent"));
cls_IGESData_DirChecker.def("CheckTypeAndForm", (void (IGESData_DirChecker::*)(opencascade::handle<Interface_Check> &, const opencascade::handle<IGESData_IGESEntity> &) const) &IGESData_DirChecker::CheckTypeAndForm, "Performs a Check only on Values of Type Number and Form Number This allows to do a check on an Entity not yet completely filled but of which Type and Form Number have been already set", py::arg("ach"), py::arg("ent"));
cls_IGESData_DirChecker.def("Correct", (Standard_Boolean (IGESData_DirChecker::*)(const opencascade::handle<IGESData_IGESEntity> &) const) &IGESData_DirChecker::Correct, "Corrects the Directory Entry of an IGES Entity as far as it is possible according recorded criteria without any ambiguity : - if a numeric Status is required a given value, this value is enforced - if an item is required to be Void, or if it recorded as Erroneous, it is cleared (set to Void) - Type Number is enforced - finally Form Number is enforced only if one and only Value is admitted (no range, see Constructors of DirChecker)", py::arg("ent"));

// Enums

}