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
#include <XmlMDF_ADriverTable.hxx>
#include <Message_Messenger.hxx>
#include <Standard_TypeDef.hxx>
#include <XmlMDataStd_NameDriver.hxx>
#include <XmlMDataStd_IntegerDriver.hxx>
#include <XmlMDataStd_RealDriver.hxx>
#include <XmlMDataStd_IntegerArrayDriver.hxx>
#include <XmlMDataStd_RealArrayDriver.hxx>
#include <XmlMDataStd_ExtStringArrayDriver.hxx>
#include <XmlMDataStd_UAttributeDriver.hxx>
#include <XmlMDataStd_DirectoryDriver.hxx>
#include <XmlMDataStd_CommentDriver.hxx>
#include <XmlMDataStd_VariableDriver.hxx>
#include <XmlMDataStd_ExpressionDriver.hxx>
#include <XmlMDataStd_RelationDriver.hxx>
#include <XmlMDataStd_NoteBookDriver.hxx>
#include <XmlMDataStd_TreeNodeDriver.hxx>
#include <XmlMDataStd_TickDriver.hxx>
#include <XmlMDataStd_IntegerListDriver.hxx>
#include <XmlMDataStd_RealListDriver.hxx>
#include <XmlMDataStd_ExtStringListDriver.hxx>
#include <XmlMDataStd_BooleanListDriver.hxx>
#include <XmlMDataStd_ReferenceListDriver.hxx>
#include <XmlMDataStd_BooleanArrayDriver.hxx>
#include <XmlMDataStd_ReferenceArrayDriver.hxx>
#include <XmlMDataStd_ByteArrayDriver.hxx>
#include <XmlMDataStd_NamedDataDriver.hxx>
#include <XmlMDataStd_AsciiStringDriver.hxx>
#include <XmlMDataStd_IntPackedMapDriver.hxx>
#include <XmlMDataStd.hxx>

void bind_XmlMDataStd(py::module &mod){

py::class_<XmlMDataStd, std::unique_ptr<XmlMDataStd>> cls_XmlMDataStd(mod, "XmlMDataStd", "Storage and Retrieval drivers for modelling attributes. Transient attributes are defined in package TDataStd.");

// Constructors

// Fields

// Methods
// cls_XmlMDataStd.def_static("operator new_", (void * (*)(size_t)) &XmlMDataStd::operator new, "None", py::arg("theSize"));
// cls_XmlMDataStd.def_static("operator delete_", (void (*)(void *)) &XmlMDataStd::operator delete, "None", py::arg("theAddress"));
// cls_XmlMDataStd.def_static("operator new[]_", (void * (*)(size_t)) &XmlMDataStd::operator new[], "None", py::arg("theSize"));
// cls_XmlMDataStd.def_static("operator delete[]_", (void (*)(void *)) &XmlMDataStd::operator delete[], "None", py::arg("theAddress"));
// cls_XmlMDataStd.def_static("operator new_", (void * (*)(size_t, void *)) &XmlMDataStd::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_XmlMDataStd.def_static("operator delete_", (void (*)(void *, void *)) &XmlMDataStd::operator delete, "None", py::arg(""), py::arg(""));
cls_XmlMDataStd.def_static("AddDrivers_", (void (*)(const opencascade::handle<XmlMDF_ADriverTable> &, const opencascade::handle<Message_Messenger> &)) &XmlMDataStd::AddDrivers, "Adds the attribute drivers to <aDriverTable>.", py::arg("aDriverTable"), py::arg("anMsgDrv"));
cls_XmlMDataStd.def_static("SetDocumentVersion_", (void (*)(const Standard_Integer)) &XmlMDataStd::SetDocumentVersion, "None", py::arg("DocVersion"));
cls_XmlMDataStd.def_static("DocumentVersion_", (Standard_Integer (*)()) &XmlMDataStd::DocumentVersion, "None");

// Enums

}