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
#include <IFSelect_SessionDumper.hxx>
#include <Standard_TypeDef.hxx>
#include <IFSelect_SessionFile.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <TCollection_AsciiString.hxx>
#include <IFSelect_BasicDumper.hxx>
#include <Standard_Type.hxx>

void bind_IFSelect_BasicDumper(py::module &mod){

py::class_<IFSelect_BasicDumper, opencascade::handle<IFSelect_BasicDumper>, IFSelect_SessionDumper> cls_IFSelect_BasicDumper(mod, "IFSelect_BasicDumper", "BasicDumper takes into account, for SessionFile, all the classes defined in the package IFSelect : Selections, Dispatches (there is no Modifier)");

// Constructors
cls_IFSelect_BasicDumper.def(py::init<>());

// Fields

// Methods
cls_IFSelect_BasicDumper.def("WriteOwn", (Standard_Boolean (IFSelect_BasicDumper::*)(IFSelect_SessionFile &, const opencascade::handle<Standard_Transient> &) const) &IFSelect_BasicDumper::WriteOwn, "Write the Own Parameters of Types defined in package IFSelect Returns True if <item> has been processed, False else", py::arg("file"), py::arg("item"));
cls_IFSelect_BasicDumper.def("ReadOwn", (Standard_Boolean (IFSelect_BasicDumper::*)(IFSelect_SessionFile &, const TCollection_AsciiString &, opencascade::handle<Standard_Transient> &) const) &IFSelect_BasicDumper::ReadOwn, "Recognizes and Read Own Parameters for Types of package IFSelect. Returns True if done and <item> created, False else", py::arg("file"), py::arg("type"), py::arg("item"));
cls_IFSelect_BasicDumper.def_static("get_type_name_", (const char * (*)()) &IFSelect_BasicDumper::get_type_name, "None");
cls_IFSelect_BasicDumper.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_BasicDumper::get_type_descriptor, "None");
cls_IFSelect_BasicDumper.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_BasicDumper::*)() const) &IFSelect_BasicDumper::DynamicType, "None");

// Enums

}