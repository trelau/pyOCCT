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
#include <Interface_EntityIterator.hxx>
#include <Interface_Graph.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Interface_InterfaceModel.hxx>
#include <TCollection_AsciiString.hxx>
#include <IFSelect_SelectFlag.hxx>
#include <Standard_Type.hxx>

void bind_IFSelect_SelectFlag(py::module &mod){

py::class_<IFSelect_SelectFlag, opencascade::handle<IFSelect_SelectFlag>, IFSelect_SelectExtract> cls_IFSelect_SelectFlag(mod, "IFSelect_SelectFlag", "A SelectFlag queries a flag noted in the bitmap of the Graph. The Flag is designated by its Name. Flag Names are defined by Work Session and, as necessary, other functional objects");

// Constructors
cls_IFSelect_SelectFlag.def(py::init<const Standard_CString>(), py::arg("flagname"));

// Fields

// Methods
cls_IFSelect_SelectFlag.def("FlagName", (Standard_CString (IFSelect_SelectFlag::*)() const) &IFSelect_SelectFlag::FlagName, "Returns the name of the flag");
cls_IFSelect_SelectFlag.def("RootResult", (Interface_EntityIterator (IFSelect_SelectFlag::*)(const Interface_Graph &) const) &IFSelect_SelectFlag::RootResult, "Returns the list of selected entities. It is redefined to work on the graph itself (not queried by sort)", py::arg("G"));
cls_IFSelect_SelectFlag.def("Sort", (Standard_Boolean (IFSelect_SelectFlag::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_SelectFlag::Sort, "Returns always False because RootResult has done the work", py::arg("rank"), py::arg("ent"), py::arg("model"));
cls_IFSelect_SelectFlag.def("ExtractLabel", (TCollection_AsciiString (IFSelect_SelectFlag::*)() const) &IFSelect_SelectFlag::ExtractLabel, "Returns a text defining the criterium, includes the flag name");
cls_IFSelect_SelectFlag.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectFlag::get_type_name, "None");
cls_IFSelect_SelectFlag.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectFlag::get_type_descriptor, "None");
cls_IFSelect_SelectFlag.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectFlag::*)() const) &IFSelect_SelectFlag::DynamicType, "None");

// Enums

}