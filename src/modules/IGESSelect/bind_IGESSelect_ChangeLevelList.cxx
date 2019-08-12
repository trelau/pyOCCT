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
#include <IGESSelect_ChangeLevelList.hxx>
#include <Standard_Type.hxx>

void bind_IGESSelect_ChangeLevelList(py::module &mod){

py::class_<IGESSelect_ChangeLevelList, opencascade::handle<IGESSelect_ChangeLevelList>, IGESSelect_ModelModifier> cls_IGESSelect_ChangeLevelList(mod, "IGESSelect_ChangeLevelList", "Changes Level List (in directory part) to a new single value Only entities attached to a LevelListEntity are considered If OldNumber is defined, only entities whose LevelList contains its Value are processed. Else all LevelLists are.");

// Constructors
cls_IGESSelect_ChangeLevelList.def(py::init<>());

// Fields

// Methods
cls_IGESSelect_ChangeLevelList.def("HasOldNumber", (Standard_Boolean (IGESSelect_ChangeLevelList::*)() const) &IGESSelect_ChangeLevelList::HasOldNumber, "Returns True if OldNumber is defined : then, only entities which have a LevelList which contains the value are processed. Else, all entities attached to a LevelList are.");
cls_IGESSelect_ChangeLevelList.def("OldNumber", (opencascade::handle<IFSelect_IntParam> (IGESSelect_ChangeLevelList::*)() const) &IGESSelect_ChangeLevelList::OldNumber, "Returns the parameter for OldNumber. If not defined (Null Handle), it will be interpreted as 'all level lists'");
cls_IGESSelect_ChangeLevelList.def("SetOldNumber", (void (IGESSelect_ChangeLevelList::*)(const opencascade::handle<IFSelect_IntParam> &)) &IGESSelect_ChangeLevelList::SetOldNumber, "Sets a parameter for OldNumber", py::arg("param"));
cls_IGESSelect_ChangeLevelList.def("HasNewNumber", (Standard_Boolean (IGESSelect_ChangeLevelList::*)() const) &IGESSelect_ChangeLevelList::HasNewNumber, "Returns True if NewNumber is defined : then, it gives the new value for Level Number. Else, the first value of the LevelList is used as new Level Number.");
cls_IGESSelect_ChangeLevelList.def("NewNumber", (opencascade::handle<IFSelect_IntParam> (IGESSelect_ChangeLevelList::*)() const) &IGESSelect_ChangeLevelList::NewNumber, "Returns the parameter for NewNumber. If not defined (Null Handle), it will be interpreted as 'new value 0'");
cls_IGESSelect_ChangeLevelList.def("SetNewNumber", (void (IGESSelect_ChangeLevelList::*)(const opencascade::handle<IFSelect_IntParam> &)) &IGESSelect_ChangeLevelList::SetNewNumber, "Sets a parameter for NewNumber", py::arg("param"));
cls_IGESSelect_ChangeLevelList.def("Performing", (void (IGESSelect_ChangeLevelList::*)(IFSelect_ContextModif &, const opencascade::handle<IGESData_IGESModel> &, Interface_CopyTool &) const) &IGESSelect_ChangeLevelList::Performing, "Specific action : considers selected target entities : If OldNumber is not defined, all entities attached to a Level List If OldNumber is defined (value not negative), entities with a Level List which contains this value Attaches all these entities to value given by NewNumber, or the first value of the Level List", py::arg("ctx"), py::arg("target"), py::arg("TC"));
cls_IGESSelect_ChangeLevelList.def("Label", (TCollection_AsciiString (IGESSelect_ChangeLevelList::*)() const) &IGESSelect_ChangeLevelList::Label, "Returns a text which begins by 'Changes Level Lists containing <old>', or 'Changes all Level Lists in D.E.', and ends by ' to Number <new>' or ' to Number = first value in List'");
cls_IGESSelect_ChangeLevelList.def_static("get_type_name_", (const char * (*)()) &IGESSelect_ChangeLevelList::get_type_name, "None");
cls_IGESSelect_ChangeLevelList.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_ChangeLevelList::get_type_descriptor, "None");
cls_IGESSelect_ChangeLevelList.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_ChangeLevelList::*)() const) &IGESSelect_ChangeLevelList::DynamicType, "None");

// Enums

}