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
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Interface_FileReaderData.hxx>
#include <Interface_Protocol.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Message_Messenger.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_Check.hxx>
#include <Standard_Transient.hxx>
#include <Interface_GeneralLib.hxx>
#include <Interface_ReaderLib.hxx>
#include <TColStd_HArray1OfTransient.hxx>
#include <Interface_FileReaderTool.hxx>

void bind_Interface_FileReaderTool(py::module &mod){

py::class_<Interface_FileReaderTool, std::unique_ptr<Interface_FileReaderTool>> cls_Interface_FileReaderTool(mod, "Interface_FileReaderTool", "Defines services which are required to load an InterfaceModel from a File. Typically, it may firstly transform a system file into a FileReaderData object, then work on it, not longer considering file contents, to load an Interface Model. It may also work on a FileReaderData already loaded.");

// Fields

// Methods
// cls_Interface_FileReaderTool.def_static("operator new_", (void * (*)(size_t)) &Interface_FileReaderTool::operator new, "None", py::arg("theSize"));
// cls_Interface_FileReaderTool.def_static("operator delete_", (void (*)(void *)) &Interface_FileReaderTool::operator delete, "None", py::arg("theAddress"));
// cls_Interface_FileReaderTool.def_static("operator new[]_", (void * (*)(size_t)) &Interface_FileReaderTool::operator new[], "None", py::arg("theSize"));
// cls_Interface_FileReaderTool.def_static("operator delete[]_", (void (*)(void *)) &Interface_FileReaderTool::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_FileReaderTool.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_FileReaderTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_FileReaderTool.def_static("operator delete_", (void (*)(void *, void *)) &Interface_FileReaderTool::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_FileReaderTool.def("SetData", (void (Interface_FileReaderTool::*)(const opencascade::handle<Interface_FileReaderData> &, const opencascade::handle<Interface_Protocol> &)) &Interface_FileReaderTool::SetData, "Sets Data to a FileReaderData. Works with a Protocol", py::arg("reader"), py::arg("protocol"));
cls_Interface_FileReaderTool.def("Protocol", (opencascade::handle<Interface_Protocol> (Interface_FileReaderTool::*)() const) &Interface_FileReaderTool::Protocol, "Returns the Protocol given at creation time");
cls_Interface_FileReaderTool.def("Data", (opencascade::handle<Interface_FileReaderData> (Interface_FileReaderTool::*)() const) &Interface_FileReaderTool::Data, "Returns the FileReaderData which is used to work");
cls_Interface_FileReaderTool.def("SetModel", (void (Interface_FileReaderTool::*)(const opencascade::handle<Interface_InterfaceModel> &)) &Interface_FileReaderTool::SetModel, "Stores a Model. Used when the Model has been loaded", py::arg("amodel"));
cls_Interface_FileReaderTool.def("Model", (opencascade::handle<Interface_InterfaceModel> (Interface_FileReaderTool::*)() const) &Interface_FileReaderTool::Model, "Returns the stored Model");
cls_Interface_FileReaderTool.def("SetMessenger", (void (Interface_FileReaderTool::*)(const opencascade::handle<Message_Messenger> &)) &Interface_FileReaderTool::SetMessenger, "Sets Messenger used for outputting messages", py::arg("messenger"));
cls_Interface_FileReaderTool.def("Messenger", (opencascade::handle<Message_Messenger> (Interface_FileReaderTool::*)() const) &Interface_FileReaderTool::Messenger, "Returns Messenger used for outputting messages. The returned object is guaranteed to be non-null; default is Message::Messenger().");
cls_Interface_FileReaderTool.def("SetTraceLevel", (void (Interface_FileReaderTool::*)(const Standard_Integer)) &Interface_FileReaderTool::SetTraceLevel, "Sets trace level used for outputting messages - 0: no trace at all - 1: errors - 2: errors and warnings - 3: all messages Default is 1 : Errors traced", py::arg("tracelev"));
cls_Interface_FileReaderTool.def("TraceLevel", (Standard_Integer (Interface_FileReaderTool::*)() const) &Interface_FileReaderTool::TraceLevel, "Returns trace level used for outputting messages.");
cls_Interface_FileReaderTool.def("SetErrorHandle", (void (Interface_FileReaderTool::*)(const Standard_Boolean)) &Interface_FileReaderTool::SetErrorHandle, "Allows controlling whether exception raisings are handled If err is False, they are not (hence, dbx can take control) If err is True, they are, and they are traced (by putting on messenger Entity's Number and file record num) Default given at Model's creation time is True", py::arg("err"));
cls_Interface_FileReaderTool.def("ErrorHandle", (Standard_Boolean (Interface_FileReaderTool::*)() const) &Interface_FileReaderTool::ErrorHandle, "Returns ErrorHandle flag");
cls_Interface_FileReaderTool.def("SetEntities", (void (Interface_FileReaderTool::*)()) &Interface_FileReaderTool::SetEntities, "Fills records with empty entities; once done, each entity can ask the FileReaderTool for any entity referenced through an identifier. Calls Recognize which is specific to each specific type of FileReaderTool");
cls_Interface_FileReaderTool.def("Recognize", (Standard_Boolean (Interface_FileReaderTool::*)(const Standard_Integer, opencascade::handle<Interface_Check> &, opencascade::handle<Standard_Transient> &)) &Interface_FileReaderTool::Recognize, "Recognizes a record, given its number. Specific to each Interface; called by SetEntities. It can call the basic method RecognizeByLib. Returns False if recognition has failed, True else. <ach> has not to be filled if simply Recognition has failed : it must record true error messages : RecognizeByLib can generate error messages if NewRead is called", py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_Interface_FileReaderTool.def("RecognizeByLib", (Standard_Boolean (Interface_FileReaderTool::*)(const Standard_Integer, Interface_GeneralLib &, Interface_ReaderLib &, opencascade::handle<Interface_Check> &, opencascade::handle<Standard_Transient> &) const) &Interface_FileReaderTool::RecognizeByLib, "Recognizes a record with the help of Libraries. Can be used to implement the method Recognize. <rlib> is used to find Protocol and CaseNumber to apply <glib> performs the creation (by service NewVoid, or NewRead if NewVoid gave no result) <ach> is a check, which is transmitted to NewRead if it is called, gives a result but which is false <ent> is the result Returns False if recognition has failed, True else", py::arg("num"), py::arg("glib"), py::arg("rlib"), py::arg("ach"), py::arg("ent"));
cls_Interface_FileReaderTool.def("UnknownEntity", (opencascade::handle<Standard_Transient> (Interface_FileReaderTool::*)() const) &Interface_FileReaderTool::UnknownEntity, "Provides an unknown entity, specific to the Interface called by SetEntities when Recognize has failed (Unknown alone) or by LoadModel when an Entity has caused a Fail on reading (to keep at least its literal description) Uses Protocol to do it");
cls_Interface_FileReaderTool.def("NewModel", (opencascade::handle<Interface_InterfaceModel> (Interface_FileReaderTool::*)() const) &Interface_FileReaderTool::NewModel, "Creates an empty Model of the norm. Uses Protocol to do it");
cls_Interface_FileReaderTool.def("LoadModel", (void (Interface_FileReaderTool::*)(const opencascade::handle<Interface_InterfaceModel> &)) &Interface_FileReaderTool::LoadModel, "Reads and fills Entities from the FileReaderData set by SetData to an InterfaceModel. It enchains required operations, the specific ones correspond to deferred methods (below) to be defined for each Norm. It manages also error recovery and trace. Remark : it calls SetModel. It Can raise any error which can occur during a load operation, unless Error Handling is set. This method can also be redefined if judged necessary.", py::arg("amodel"));
cls_Interface_FileReaderTool.def("LoadedEntity", (opencascade::handle<Standard_Transient> (Interface_FileReaderTool::*)(const Standard_Integer)) &Interface_FileReaderTool::LoadedEntity, "Reads, Fills and Returns one Entity read from a Record of the FileReaderData. This Method manages also case of Fail or Warning, by producing a ReportEntyty plus , for a Fail, a literal Content (as an UnknownEntity). Performs also Trace", py::arg("num"));
cls_Interface_FileReaderTool.def("BeginRead", (void (Interface_FileReaderTool::*)(const opencascade::handle<Interface_InterfaceModel> &)) &Interface_FileReaderTool::BeginRead, "Fills model's header; each Interface defines for its Model its own file header; this method fills it from FileReaderTool.+ It is called by AnalyseFile from InterfaceModel", py::arg("amodel"));
cls_Interface_FileReaderTool.def("AnalyseRecord", (Standard_Boolean (Interface_FileReaderTool::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, opencascade::handle<Interface_Check> &)) &Interface_FileReaderTool::AnalyseRecord, "Fills an Entity, given record no; specific to each Interface, called by AnalyseFile from InterfaceModel (which manages its calling arguments) To work, each Interface can define a method in its proper Transient class, like this (given as an example) : AnalyseRecord (me : mutable; FR : in out FileReaderTool; num : Integer; acheck : in out Check) returns Boolean; and call it from AnalyseRecord", py::arg("num"), py::arg("anent"), py::arg("acheck"));
cls_Interface_FileReaderTool.def("EndRead", (void (Interface_FileReaderTool::*)(const opencascade::handle<Interface_InterfaceModel> &)) &Interface_FileReaderTool::EndRead, "Ends file reading after reading all the entities default is doing nothing; redefinable as necessary", py::arg("amodel"));
cls_Interface_FileReaderTool.def("Clear", (void (Interface_FileReaderTool::*)()) &Interface_FileReaderTool::Clear, "Clear filelds");

// Enums

}