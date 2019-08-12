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
#include <IFSelect_WorkLibrary.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Interface_Protocol.hxx>
#include <IFSelect_ContextWrite.hxx>
#include <Interface_EntityIterator.hxx>
#include <Interface_CopyTool.hxx>
#include <Standard_Transient.hxx>
#include <Message_Messenger.hxx>
#include <StepSelect_WorkLibrary.hxx>
#include <Standard_Type.hxx>

void bind_StepSelect_WorkLibrary(py::module &mod){

py::class_<StepSelect_WorkLibrary, opencascade::handle<StepSelect_WorkLibrary>, IFSelect_WorkLibrary> cls_StepSelect_WorkLibrary(mod, "StepSelect_WorkLibrary", "Performs Read and Write a STEP File with a STEP Model Following the protocols, Copy may be implemented or not");

// Constructors
cls_StepSelect_WorkLibrary.def(py::init<>());
cls_StepSelect_WorkLibrary.def(py::init<const Standard_Boolean>(), py::arg("copymode"));

// Fields

// Methods
cls_StepSelect_WorkLibrary.def("SetDumpLabel", (void (StepSelect_WorkLibrary::*)(const Standard_Integer)) &StepSelect_WorkLibrary::SetDumpLabel, "Selects a mode to dump entities 0 (D) : prints numbers, then displays table number/label 1 : prints labels, then displays table label/number 2 : prints labels onky", py::arg("mode"));
cls_StepSelect_WorkLibrary.def("ReadFile", (Standard_Integer (StepSelect_WorkLibrary::*)(const Standard_CString, opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &) const) &StepSelect_WorkLibrary::ReadFile, "Reads a STEP File and returns a STEP Model (into <mod>), or lets <mod> 'Null' in case of Error Returns 0 if OK, 1 if Read Error, -1 if File not opened", py::arg("name"), py::arg("model"), py::arg("protocol"));
cls_StepSelect_WorkLibrary.def("WriteFile", (Standard_Boolean (StepSelect_WorkLibrary::*)(IFSelect_ContextWrite &) const) &StepSelect_WorkLibrary::WriteFile, "Writes a File from a STEP Model Returns False (and writes no file) if <ctx> does not bring a STEP Model", py::arg("ctx"));
cls_StepSelect_WorkLibrary.def("CopyModel", (Standard_Boolean (StepSelect_WorkLibrary::*)(const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_InterfaceModel> &, const Interface_EntityIterator &, Interface_CopyTool &) const) &StepSelect_WorkLibrary::CopyModel, "Performs the copy of entities from an original model to a new one. Works according <copymode> : if True, standard copy is run else nothing is done and returned value is False", py::arg("original"), py::arg("newmodel"), py::arg("list"), py::arg("TC"));
cls_StepSelect_WorkLibrary.def("DumpEntity", (void (StepSelect_WorkLibrary::*)(const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &StepSelect_WorkLibrary::DumpEntity, "Dumps an entity under STEP form, i.e. as a part of a Step file Works with a StepDumper. Level 0 just displays type; level 1 displays the entity itself and level 2 displays the entity plus its shared ones (one sub-level : immediately shared entities)", py::arg("model"), py::arg("protocol"), py::arg("entity"), py::arg("S"), py::arg("level"));
cls_StepSelect_WorkLibrary.def_static("get_type_name_", (const char * (*)()) &StepSelect_WorkLibrary::get_type_name, "None");
cls_StepSelect_WorkLibrary.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepSelect_WorkLibrary::get_type_descriptor, "None");
cls_StepSelect_WorkLibrary.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepSelect_WorkLibrary::*)() const) &StepSelect_WorkLibrary::DynamicType, "None");

// Enums

}