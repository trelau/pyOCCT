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
#include <StepData_StepModel.hxx>
#include <StepData_Protocol.hxx>
#include <Standard_TypeDef.hxx>
#include <StepData_StepWriter.hxx>
#include <Message_Messenger.hxx>
#include <Standard_Transient.hxx>
#include <Interface_GeneralLib.hxx>
#include <StepData_WriterLib.hxx>
#include <StepData_StepDumper.hxx>

void bind_StepData_StepDumper(py::module &mod){

py::class_<StepData_StepDumper, std::unique_ptr<StepData_StepDumper>> cls_StepData_StepDumper(mod, "StepData_StepDumper", "Provides a way to dump entities processed through STEP, with these features : - same form as for writing a STEP File (because it is clear and compact enough, even if the names of the fields do not appear) : thus, no additionnal resource is required - possibility to look for an entity itself (only its Type or with its content), an entity and it shared items (one level) or all the entities its refers to, directly or recursively.");

// Constructors
cls_StepData_StepDumper.def(py::init<const opencascade::handle<StepData_StepModel> &, const opencascade::handle<StepData_Protocol> &>(), py::arg("amodel"), py::arg("protocol"));
cls_StepData_StepDumper.def(py::init<const opencascade::handle<StepData_StepModel> &, const opencascade::handle<StepData_Protocol> &, const Standard_Integer>(), py::arg("amodel"), py::arg("protocol"), py::arg("mode"));

// Fields

// Methods
// cls_StepData_StepDumper.def_static("operator new_", (void * (*)(size_t)) &StepData_StepDumper::operator new, "None", py::arg("theSize"));
// cls_StepData_StepDumper.def_static("operator delete_", (void (*)(void *)) &StepData_StepDumper::operator delete, "None", py::arg("theAddress"));
// cls_StepData_StepDumper.def_static("operator new[]_", (void * (*)(size_t)) &StepData_StepDumper::operator new[], "None", py::arg("theSize"));
// cls_StepData_StepDumper.def_static("operator delete[]_", (void (*)(void *)) &StepData_StepDumper::operator delete[], "None", py::arg("theAddress"));
// cls_StepData_StepDumper.def_static("operator new_", (void * (*)(size_t, void *)) &StepData_StepDumper::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepData_StepDumper.def_static("operator delete_", (void (*)(void *, void *)) &StepData_StepDumper::operator delete, "None", py::arg(""), py::arg(""));
cls_StepData_StepDumper.def("StepWriter", (StepData_StepWriter & (StepData_StepDumper::*)()) &StepData_StepDumper::StepWriter, "Gives an access to the tool which is used to work : this allow to acts on some parameters : Floating Format, Scopes ...");
cls_StepData_StepDumper.def("Dump", (Standard_Boolean (StepData_StepDumper::*)(const opencascade::handle<Message_Messenger> &, const opencascade::handle<Standard_Transient> &, const Standard_Integer)) &StepData_StepDumper::Dump, "Dumps a Entity on an Messenger. Returns True if sucess, False, if the entity to dump has not been recognized by the Protocol. <level> can have one of these values : - 0 : prints the TYPE only, as known in STEP Files (StepType) If <ent> has not been regognized by the Protocol, or if its type is Complex, the StepType is replaced by the display of the cdl type. Complex Type are well processed by level 1. - 1 : dumps the entity, completely (whatever it has simple or complex type) but alone. - 2 : dumps the entity completely, plus the item its refers to at first level (a header message designates the starting entity of the dump) <Lists Shared and Implied> - 3 : dumps the entity and its refered items at any levels", py::arg("S"), py::arg("ent"), py::arg("level"));
cls_StepData_StepDumper.def("Dump", (Standard_Boolean (StepData_StepDumper::*)(const opencascade::handle<Message_Messenger> &, const Standard_Integer, const Standard_Integer)) &StepData_StepDumper::Dump, "Works as Dump with a Transient, but directly takes the entity designated by its number in the Model Returns False, also if <num> is out of range", py::arg("S"), py::arg("num"), py::arg("level"));

// Enums

}