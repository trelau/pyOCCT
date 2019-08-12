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
#include <IFSelect_Activator.hxx>
#include <Standard_TypeDef.hxx>
#include <IFSelect_ActFunc.hxx>
#include <IFSelect_ReturnStatus.hxx>
#include <Standard_Handle.hxx>
#include <IFSelect_SessionPilot.hxx>
#include <IFSelect_Act.hxx>
#include <Standard_Type.hxx>
#include <TCollection_AsciiString.hxx>

void bind_IFSelect_Act(py::module &mod){

py::class_<IFSelect_Act, opencascade::handle<IFSelect_Act>, IFSelect_Activator> cls_IFSelect_Act(mod, "IFSelect_Act", "Act gives a simple way to define and add functions to be ran from a SessionPilot, as follows :");

// Constructors
cls_IFSelect_Act.def(py::init<const Standard_CString, const Standard_CString, const IFSelect_ActFunc>(), py::arg("name"), py::arg("help"), py::arg("func"));

// Fields

// Methods
cls_IFSelect_Act.def("Do", (IFSelect_ReturnStatus (IFSelect_Act::*)(const Standard_Integer, const opencascade::handle<IFSelect_SessionPilot> &)) &IFSelect_Act::Do, "Execution of Command Line. remark that <number> is senseless because each Act brings one and only one function", py::arg("number"), py::arg("pilot"));
cls_IFSelect_Act.def("Help", (Standard_CString (IFSelect_Act::*)(const Standard_Integer) const) &IFSelect_Act::Help, "Short Help for commands : returns the help given to create", py::arg("number"));
cls_IFSelect_Act.def_static("SetGroup_", [](const Standard_CString a0) -> void { return IFSelect_Act::SetGroup(a0); });
cls_IFSelect_Act.def_static("SetGroup_", (void (*)(const Standard_CString, const Standard_CString)) &IFSelect_Act::SetGroup, "Changes the default group name for the following Acts group empty means to come back to default from Activator Also a file name can be precised (to query by getsource)", py::arg("group"), py::arg("file"));
cls_IFSelect_Act.def_static("AddFunc_", (void (*)(const Standard_CString, const Standard_CString, const IFSelect_ActFunc)) &IFSelect_Act::AddFunc, "Adds a function with its name and help : creates an Act then records it as normal function", py::arg("name"), py::arg("help"), py::arg("func"));
cls_IFSelect_Act.def_static("AddFSet_", (void (*)(const Standard_CString, const Standard_CString, const IFSelect_ActFunc)) &IFSelect_Act::AddFSet, "Adds a function with its name and help : creates an Act then records it as function for XSET (i.e. to create control item)", py::arg("name"), py::arg("help"), py::arg("func"));
cls_IFSelect_Act.def_static("get_type_name_", (const char * (*)()) &IFSelect_Act::get_type_name, "None");
cls_IFSelect_Act.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_Act::get_type_descriptor, "None");
cls_IFSelect_Act.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_Act::*)() const) &IFSelect_Act::DynamicType, "None");

// Enums

}