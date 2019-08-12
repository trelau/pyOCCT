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
#include <IFSelect_ContextModif.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_IGESModel.hxx>
#include <Interface_CopyTool.hxx>
#include <TCollection_AsciiString.hxx>
#include <IGESSelect_ComputeStatus.hxx>
#include <Standard_Type.hxx>

void bind_IGESSelect_ComputeStatus(py::module &mod){

py::class_<IGESSelect_ComputeStatus, opencascade::handle<IGESSelect_ComputeStatus>, IGESSelect_ModelModifier> cls_IGESSelect_ComputeStatus(mod, "IGESSelect_ComputeStatus", "Computes Status of IGES Entities for a whole IGESModel. This concerns SubordinateStatus and UseFlag, which must have some definite values according the way they are referenced. (see definitions of Logical use, Physical use, etc...)");

// Constructors
cls_IGESSelect_ComputeStatus.def(py::init<>());

// Fields

// Methods
cls_IGESSelect_ComputeStatus.def("Performing", (void (IGESSelect_ComputeStatus::*)(IFSelect_ContextModif &, const opencascade::handle<IGESData_IGESModel> &, Interface_CopyTool &) const) &IGESSelect_ComputeStatus::Performing, "Specific action : it first evaluates the required values for Subordinate Status and Use Flag (in Directory Part of each IGES Entity). Then it corrects them, for the whole target. Works with a Protocol. Implementation uses BasicEditor", py::arg("ctx"), py::arg("target"), py::arg("TC"));
cls_IGESSelect_ComputeStatus.def("Label", (TCollection_AsciiString (IGESSelect_ComputeStatus::*)() const) &IGESSelect_ComputeStatus::Label, "Returns a text which is 'Compute Subordinate Status and Use Flag'");
cls_IGESSelect_ComputeStatus.def_static("get_type_name_", (const char * (*)()) &IGESSelect_ComputeStatus::get_type_name, "None");
cls_IGESSelect_ComputeStatus.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_ComputeStatus::get_type_descriptor, "None");
cls_IGESSelect_ComputeStatus.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_ComputeStatus::*)() const) &IGESSelect_ComputeStatus::DynamicType, "None");

// Enums

}