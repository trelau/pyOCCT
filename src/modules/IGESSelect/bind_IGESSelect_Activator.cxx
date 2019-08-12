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
#include <IFSelect_ReturnStatus.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IFSelect_SessionPilot.hxx>
#include <IGESSelect_Activator.hxx>
#include <Standard_Type.hxx>

void bind_IGESSelect_Activator(py::module &mod){

py::class_<IGESSelect_Activator, opencascade::handle<IGESSelect_Activator>, IFSelect_Activator> cls_IGESSelect_Activator(mod, "IGESSelect_Activator", "Performs Actions specific to IGESSelect, i.e. creation of IGES Selections and Dispatches, plus dumping specific to IGES");

// Constructors
cls_IGESSelect_Activator.def(py::init<>());

// Fields

// Methods
cls_IGESSelect_Activator.def("Do", (IFSelect_ReturnStatus (IGESSelect_Activator::*)(const Standard_Integer, const opencascade::handle<IFSelect_SessionPilot> &)) &IGESSelect_Activator::Do, "Executes a Command Line for IGESSelect", py::arg("number"), py::arg("pilot"));
cls_IGESSelect_Activator.def("Help", (Standard_CString (IGESSelect_Activator::*)(const Standard_Integer) const) &IGESSelect_Activator::Help, "Sends a short help message for IGESSelect commands", py::arg("number"));
cls_IGESSelect_Activator.def_static("get_type_name_", (const char * (*)()) &IGESSelect_Activator::get_type_name, "None");
cls_IGESSelect_Activator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_Activator::get_type_descriptor, "None");
cls_IGESSelect_Activator.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_Activator::*)() const) &IGESSelect_Activator::DynamicType, "None");

// Enums

}