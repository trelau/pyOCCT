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
#include <IFSelect_SelectExtract.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Interface_InterfaceModel.hxx>
#include <TCollection_AsciiString.hxx>
#include <IGESSelect_SelectVisibleStatus.hxx>
#include <Standard_Type.hxx>

void bind_IGESSelect_SelectVisibleStatus(py::module &mod){

py::class_<IGESSelect_SelectVisibleStatus, opencascade::handle<IGESSelect_SelectVisibleStatus>, IFSelect_SelectExtract> cls_IGESSelect_SelectVisibleStatus(mod, "IGESSelect_SelectVisibleStatus", "This selection looks at Blank Status of IGES Entities Direct selection keeps Visible Entities (Blank = 0), Reverse selection keeps Blanked Entities (Blank = 1)");

// Constructors
cls_IGESSelect_SelectVisibleStatus.def(py::init<>());

// Fields

// Methods
cls_IGESSelect_SelectVisibleStatus.def("Sort", (Standard_Boolean (IGESSelect_SelectVisibleStatus::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IGESSelect_SelectVisibleStatus::Sort, "Returns True if <ent> is an IGES Entity with Blank Status = 0", py::arg("rank"), py::arg("ent"), py::arg("model"));
cls_IGESSelect_SelectVisibleStatus.def("ExtractLabel", (TCollection_AsciiString (IGESSelect_SelectVisibleStatus::*)() const) &IGESSelect_SelectVisibleStatus::ExtractLabel, "Returns the Selection criterium : 'IGES Entity, Status Visible'");
cls_IGESSelect_SelectVisibleStatus.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SelectVisibleStatus::get_type_name, "None");
cls_IGESSelect_SelectVisibleStatus.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SelectVisibleStatus::get_type_descriptor, "None");
cls_IGESSelect_SelectVisibleStatus.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SelectVisibleStatus::*)() const) &IGESSelect_SelectVisibleStatus::DynamicType, "None");

// Enums

}