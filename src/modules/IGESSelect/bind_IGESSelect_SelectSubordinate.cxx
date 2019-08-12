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
#include <IGESSelect_SelectSubordinate.hxx>
#include <Standard_Type.hxx>

void bind_IGESSelect_SelectSubordinate(py::module &mod){

py::class_<IGESSelect_SelectSubordinate, opencascade::handle<IGESSelect_SelectSubordinate>, IFSelect_SelectExtract> cls_IGESSelect_SelectSubordinate(mod, "IGESSelect_SelectSubordinate", "This selections uses Subordinate Status as sort criterium It is an integer number which can be : 0 Independant 1 Physically Dependant 2 Logically Dependant 3 Both (recorded) + to sort : 4 : 1 or 3 -> at least Physically 5 : 2 or 3 -> at least Logically 6 : 1 or 2 or 3 -> any kind of dependance (corresponds to 0 reversed)");

// Constructors
cls_IGESSelect_SelectSubordinate.def(py::init<const Standard_Integer>(), py::arg("status"));

// Fields

// Methods
cls_IGESSelect_SelectSubordinate.def("Status", (Standard_Integer (IGESSelect_SelectSubordinate::*)() const) &IGESSelect_SelectSubordinate::Status, "Returns the status used for sorting");
cls_IGESSelect_SelectSubordinate.def("Sort", (Standard_Boolean (IGESSelect_SelectSubordinate::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IGESSelect_SelectSubordinate::Sort, "Returns True if <ent> is an IGES Entity with Subordinate Status matching the criterium", py::arg("rank"), py::arg("ent"), py::arg("model"));
cls_IGESSelect_SelectSubordinate.def("ExtractLabel", (TCollection_AsciiString (IGESSelect_SelectSubordinate::*)() const) &IGESSelect_SelectSubordinate::ExtractLabel, "Returns the Selection criterium : 'IGES Entity, Independant' etc...");
cls_IGESSelect_SelectSubordinate.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SelectSubordinate::get_type_name, "None");
cls_IGESSelect_SelectSubordinate.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SelectSubordinate::get_type_descriptor, "None");
cls_IGESSelect_SelectSubordinate.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SelectSubordinate::*)() const) &IGESSelect_SelectSubordinate::DynamicType, "None");

// Enums

}