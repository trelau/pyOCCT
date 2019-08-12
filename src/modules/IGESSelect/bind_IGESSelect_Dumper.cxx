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
#include <IGESSelect_Dumper.hxx>
#include <Standard_Type.hxx>

void bind_IGESSelect_Dumper(py::module &mod){

py::class_<IGESSelect_Dumper, opencascade::handle<IGESSelect_Dumper>, IFSelect_SessionDumper> cls_IGESSelect_Dumper(mod, "IGESSelect_Dumper", "Dumper from IGESSelect takes into account, for SessionFile, the classes defined in the package IGESSelect : Selections, Dispatches, Modifiers");

// Constructors
cls_IGESSelect_Dumper.def(py::init<>());

// Fields

// Methods
cls_IGESSelect_Dumper.def("WriteOwn", (Standard_Boolean (IGESSelect_Dumper::*)(IFSelect_SessionFile &, const opencascade::handle<Standard_Transient> &) const) &IGESSelect_Dumper::WriteOwn, "Write the Own Parameters of Types defined in package IGESSelect Returns True if <item> has been processed, False else", py::arg("file"), py::arg("item"));
cls_IGESSelect_Dumper.def("ReadOwn", (Standard_Boolean (IGESSelect_Dumper::*)(IFSelect_SessionFile &, const TCollection_AsciiString &, opencascade::handle<Standard_Transient> &) const) &IGESSelect_Dumper::ReadOwn, "Recognizes and Read Own Parameters for Types of package IGESSelect. Returns True if done and <item> created, False else", py::arg("file"), py::arg("type"), py::arg("item"));
cls_IGESSelect_Dumper.def_static("get_type_name_", (const char * (*)()) &IGESSelect_Dumper::get_type_name, "None");
cls_IGESSelect_Dumper.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_Dumper::get_type_descriptor, "None");
cls_IGESSelect_Dumper.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_Dumper::*)() const) &IGESSelect_Dumper::DynamicType, "None");

// Enums

}