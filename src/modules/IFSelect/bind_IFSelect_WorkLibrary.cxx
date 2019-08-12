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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Interface_Protocol.hxx>
#include <IFSelect_ContextWrite.hxx>
#include <Interface_EntityIterator.hxx>
#include <Interface_CopyTool.hxx>
#include <Message_Messenger.hxx>
#include <IFSelect_WorkLibrary.hxx>
#include <Standard_Type.hxx>
#include <Interface_HArray1OfHAsciiString.hxx>

void bind_IFSelect_WorkLibrary(py::module &mod){

py::class_<IFSelect_WorkLibrary, opencascade::handle<IFSelect_WorkLibrary>, Standard_Transient> cls_IFSelect_WorkLibrary(mod, "IFSelect_WorkLibrary", "This class defines the (empty) frame which can be used to enrich a XSTEP set with new capabilities In particular, a specific WorkLibrary must give the way for Reading a File into a Model, and Writing a Model to a File Thus, it is possible to define several Work Libraries for each norm, but recommanded to define one general class for each one : this general class will define the Read and Write methods.");

// Fields

// Methods
cls_IFSelect_WorkLibrary.def("ReadFile", (Standard_Integer (IFSelect_WorkLibrary::*)(const Standard_CString, opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &) const) &IFSelect_WorkLibrary::ReadFile, "Gives the way to Read a File and transfer it to a Model <mod> is the resulting Model, which has to be created by this method. In case of error, <mod> must be returned Null Return value is a status with free values. Simply, 0 is for 'Execution OK' The Protocol can be used to work (e.g. create the Model, read and recognize the Entities)", py::arg("name"), py::arg("model"), py::arg("protocol"));
cls_IFSelect_WorkLibrary.def("WriteFile", (Standard_Boolean (IFSelect_WorkLibrary::*)(IFSelect_ContextWrite &) const) &IFSelect_WorkLibrary::WriteFile, "Gives the way to Write a File from a Model. <ctx> contains all necessary informations : the model, the protocol, the file name, and the list of File Modifiers to be applied, also with restricted list of selected entities for each one, if required. In return, it brings the produced check-list", py::arg("ctx"));
cls_IFSelect_WorkLibrary.def("CopyModel", (Standard_Boolean (IFSelect_WorkLibrary::*)(const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_InterfaceModel> &, const Interface_EntityIterator &, Interface_CopyTool &) const) &IFSelect_WorkLibrary::CopyModel, "Performs the copy of entities from an original model to a new one. It must also copy headers if any. Returns True when done. The provided default works by copying the individual entities designated in the list, by using the general service class CopyTool. It can be redefined for a norm which, either implements Copy by another way (do not forget to Bind each copied result with its original entity in TC) and returns True, or does not know how to copy and returns False", py::arg("original"), py::arg("newmodel"), py::arg("list"), py::arg("TC"));
cls_IFSelect_WorkLibrary.def("DumpEntity", (void (IFSelect_WorkLibrary::*)(const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IFSelect_WorkLibrary::DumpEntity, "Gives the way of dumping an entity under a form comprehensive for each norm. <model> helps to identify, number ... entities. <level> is to be interpreted for each norm (because of the formats which can be very different)", py::arg("model"), py::arg("protocol"), py::arg("entity"), py::arg("S"), py::arg("level"));
cls_IFSelect_WorkLibrary.def("DumpEntity", (void (IFSelect_WorkLibrary::*)(const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Message_Messenger> &) const) &IFSelect_WorkLibrary::DumpEntity, "Calls deferred DumpEntity with the recorded default level", py::arg("model"), py::arg("protocol"), py::arg("entity"), py::arg("S"));
cls_IFSelect_WorkLibrary.def("SetDumpLevels", (void (IFSelect_WorkLibrary::*)(const Standard_Integer, const Standard_Integer)) &IFSelect_WorkLibrary::SetDumpLevels, "Records a default level and a maximum value for level level for DumpEntity can go between 0 and <max> default value will be <def>", py::arg("def"), py::arg("max"));
cls_IFSelect_WorkLibrary.def("DumpLevels", [](IFSelect_WorkLibrary &self, Standard_Integer & def, Standard_Integer & max){ self.DumpLevels(def, max); return std::tuple<Standard_Integer &, Standard_Integer &>(def, max); }, "Returns the recorded default and maximum dump levels If none was recorded, max is returned negative, def as zero", py::arg("def"), py::arg("max"));
cls_IFSelect_WorkLibrary.def("SetDumpHelp", (void (IFSelect_WorkLibrary::*)(const Standard_Integer, const Standard_CString)) &IFSelect_WorkLibrary::SetDumpHelp, "Records a short line of help for a level (0 - max)", py::arg("level"), py::arg("help"));
cls_IFSelect_WorkLibrary.def("DumpHelp", (Standard_CString (IFSelect_WorkLibrary::*)(const Standard_Integer) const) &IFSelect_WorkLibrary::DumpHelp, "Returns the help line recorded for <level>, or an empty string", py::arg("level"));
cls_IFSelect_WorkLibrary.def_static("get_type_name_", (const char * (*)()) &IFSelect_WorkLibrary::get_type_name, "None");
cls_IFSelect_WorkLibrary.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_WorkLibrary::get_type_descriptor, "None");
cls_IFSelect_WorkLibrary.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_WorkLibrary::*)() const) &IFSelect_WorkLibrary::DynamicType, "None");

// Enums

}