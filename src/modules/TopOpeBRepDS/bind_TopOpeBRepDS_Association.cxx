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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepDS_Interference.hxx>
#include <TopOpeBRepDS_ListOfInterference.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRepDS_Association.hxx>
#include <Standard_Type.hxx>
#include <TopOpeBRepDS_DataMapOfInterferenceListOfInterference.hxx>

void bind_TopOpeBRepDS_Association(py::module &mod){

py::class_<TopOpeBRepDS_Association, opencascade::handle<TopOpeBRepDS_Association>, Standard_Transient> cls_TopOpeBRepDS_Association(mod, "TopOpeBRepDS_Association", "None");

// Constructors
cls_TopOpeBRepDS_Association.def(py::init<>());

// Fields

// Methods
cls_TopOpeBRepDS_Association.def("Associate", (void (TopOpeBRepDS_Association::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_Association::Associate, "None", py::arg("I"), py::arg("K"));
cls_TopOpeBRepDS_Association.def("Associate", (void (TopOpeBRepDS_Association::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_Association::Associate, "None", py::arg("I"), py::arg("LI"));
cls_TopOpeBRepDS_Association.def("HasAssociation", (Standard_Boolean (TopOpeBRepDS_Association::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const) &TopOpeBRepDS_Association::HasAssociation, "None", py::arg("I"));
cls_TopOpeBRepDS_Association.def("Associated", (TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_Association::*)(const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_Association::Associated, "None", py::arg("I"));
cls_TopOpeBRepDS_Association.def("AreAssociated", (Standard_Boolean (TopOpeBRepDS_Association::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const opencascade::handle<TopOpeBRepDS_Interference> &) const) &TopOpeBRepDS_Association::AreAssociated, "None", py::arg("I"), py::arg("K"));
cls_TopOpeBRepDS_Association.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepDS_Association::get_type_name, "None");
cls_TopOpeBRepDS_Association.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepDS_Association::get_type_descriptor, "None");
cls_TopOpeBRepDS_Association.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepDS_Association::*)() const) &TopOpeBRepDS_Association::DynamicType, "None");

// Enums

}