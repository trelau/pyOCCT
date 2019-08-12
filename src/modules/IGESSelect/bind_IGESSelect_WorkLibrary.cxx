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
#include <IFSelect_WorkLibrary.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Interface_Protocol.hxx>
#include <IFSelect_ContextWrite.hxx>
#include <IGESData_Protocol.hxx>
#include <Standard_Transient.hxx>
#include <Message_Messenger.hxx>
#include <IGESSelect_WorkLibrary.hxx>
#include <Standard_Type.hxx>

void bind_IGESSelect_WorkLibrary(py::module &mod){

py::class_<IGESSelect_WorkLibrary, opencascade::handle<IGESSelect_WorkLibrary>, IFSelect_WorkLibrary> cls_IGESSelect_WorkLibrary(mod, "IGESSelect_WorkLibrary", "Performs Read and Write an IGES File with an IGES Model");

// Constructors
cls_IGESSelect_WorkLibrary.def(py::init<>());
cls_IGESSelect_WorkLibrary.def(py::init<const Standard_Boolean>(), py::arg("modefnes"));

// Fields

// Methods
cls_IGESSelect_WorkLibrary.def("ReadFile", (Standard_Integer (IGESSelect_WorkLibrary::*)(const Standard_CString, opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &) const) &IGESSelect_WorkLibrary::ReadFile, "Reads a IGES File and returns a IGES Model (into <mod>), or lets <mod> 'Null' in case of Error Returns 0 if OK, 1 if Read Error, -1 if File not opened", py::arg("name"), py::arg("model"), py::arg("protocol"));
cls_IGESSelect_WorkLibrary.def("WriteFile", (Standard_Boolean (IGESSelect_WorkLibrary::*)(IFSelect_ContextWrite &) const) &IGESSelect_WorkLibrary::WriteFile, "Writes a File from a IGES Model (brought by <ctx>) Returns False (and writes no file) if <ctx> is not for IGES", py::arg("ctx"));
cls_IGESSelect_WorkLibrary.def_static("DefineProtocol_", (opencascade::handle<IGESData_Protocol> (*)()) &IGESSelect_WorkLibrary::DefineProtocol, "Defines a protocol to be adequate for IGES (encompasses ALL the IGES norm including IGESSolid, IGESAppli)");
cls_IGESSelect_WorkLibrary.def("DumpEntity", (void (IGESSelect_WorkLibrary::*)(const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESSelect_WorkLibrary::DumpEntity, "Dumps an IGES Entity with an IGES Dumper. <level> is the one used by IGESDumper.", py::arg("model"), py::arg("protocol"), py::arg("entity"), py::arg("S"), py::arg("level"));
cls_IGESSelect_WorkLibrary.def_static("get_type_name_", (const char * (*)()) &IGESSelect_WorkLibrary::get_type_name, "None");
cls_IGESSelect_WorkLibrary.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_WorkLibrary::get_type_descriptor, "None");
cls_IGESSelect_WorkLibrary.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_WorkLibrary::*)() const) &IGESSelect_WorkLibrary::DynamicType, "None");

// Enums

}