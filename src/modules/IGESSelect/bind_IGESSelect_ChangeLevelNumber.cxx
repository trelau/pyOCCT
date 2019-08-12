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
#include <IGESSelect_ModelModifier.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IFSelect_IntParam.hxx>
#include <IFSelect_ContextModif.hxx>
#include <IGESData_IGESModel.hxx>
#include <Interface_CopyTool.hxx>
#include <TCollection_AsciiString.hxx>
#include <IGESSelect_ChangeLevelNumber.hxx>
#include <Standard_Type.hxx>

void bind_IGESSelect_ChangeLevelNumber(py::module &mod){

py::class_<IGESSelect_ChangeLevelNumber, opencascade::handle<IGESSelect_ChangeLevelNumber>, IGESSelect_ModelModifier> cls_IGESSelect_ChangeLevelNumber(mod, "IGESSelect_ChangeLevelNumber", "Changes Level Number (as null or single) to a new single value Entities attached to a LevelListEntity are ignored Entities considered can be, either all Entities but those attached to a LevelListEntity, or Entities attached to a specific Level Number (0 for not defined).");

// Constructors
cls_IGESSelect_ChangeLevelNumber.def(py::init<>());

// Fields

// Methods
cls_IGESSelect_ChangeLevelNumber.def("HasOldNumber", (Standard_Boolean (IGESSelect_ChangeLevelNumber::*)() const) &IGESSelect_ChangeLevelNumber::HasOldNumber, "Returns True if OldNumber is defined : then, only entities attached to the value of OldNumber will be considered. Else, all entities but those attached to a Level List will be.");
cls_IGESSelect_ChangeLevelNumber.def("OldNumber", (opencascade::handle<IFSelect_IntParam> (IGESSelect_ChangeLevelNumber::*)() const) &IGESSelect_ChangeLevelNumber::OldNumber, "Returns the parameter for OldNumber. If not defined (Null Handle), it will be interpreted as 'all level numbers'");
cls_IGESSelect_ChangeLevelNumber.def("SetOldNumber", (void (IGESSelect_ChangeLevelNumber::*)(const opencascade::handle<IFSelect_IntParam> &)) &IGESSelect_ChangeLevelNumber::SetOldNumber, "Sets a parameter for OldNumber", py::arg("param"));
cls_IGESSelect_ChangeLevelNumber.def("NewNumber", (opencascade::handle<IFSelect_IntParam> (IGESSelect_ChangeLevelNumber::*)() const) &IGESSelect_ChangeLevelNumber::NewNumber, "Returns the parameter for NewNumber. If not defined (Null Handle), it will be interpreted as 'new value 0'");
cls_IGESSelect_ChangeLevelNumber.def("SetNewNumber", (void (IGESSelect_ChangeLevelNumber::*)(const opencascade::handle<IFSelect_IntParam> &)) &IGESSelect_ChangeLevelNumber::SetNewNumber, "Sets a parameter for NewNumber", py::arg("param"));
cls_IGESSelect_ChangeLevelNumber.def("Performing", (void (IGESSelect_ChangeLevelNumber::*)(IFSelect_ContextModif &, const opencascade::handle<IGESData_IGESModel> &, Interface_CopyTool &) const) &IGESSelect_ChangeLevelNumber::Performing, "Specific action : considers selected target entities : If OldNumber is not defined, all entities but those attached to a Level List If OldNumber is defined (value not negative), entities with a defined Level Number (can be zero) Attaches all these entities to value given by NewNumber, or zero if not defined", py::arg("ctx"), py::arg("target"), py::arg("TC"));
cls_IGESSelect_ChangeLevelNumber.def("Label", (TCollection_AsciiString (IGESSelect_ChangeLevelNumber::*)() const) &IGESSelect_ChangeLevelNumber::Label, "Returns a text which is 'Changes Level Number <old> to <new>' , or 'Changes all Levels Numbers positive and zero to <new>'");
cls_IGESSelect_ChangeLevelNumber.def_static("get_type_name_", (const char * (*)()) &IGESSelect_ChangeLevelNumber::get_type_name, "None");
cls_IGESSelect_ChangeLevelNumber.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_ChangeLevelNumber::get_type_descriptor, "None");
cls_IGESSelect_ChangeLevelNumber.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_ChangeLevelNumber::*)() const) &IGESSelect_ChangeLevelNumber::DynamicType, "None");

// Enums

}