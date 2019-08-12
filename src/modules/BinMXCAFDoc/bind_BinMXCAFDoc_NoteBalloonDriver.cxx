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
#include <BinMXCAFDoc_NoteCommentDriver.hxx>
#include <Standard_Handle.hxx>
#include <Message_Messenger.hxx>
#include <TDF_Attribute.hxx>
#include <BinMXCAFDoc_NoteBalloonDriver.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>

void bind_BinMXCAFDoc_NoteBalloonDriver(py::module &mod){

py::class_<BinMXCAFDoc_NoteBalloonDriver, opencascade::handle<BinMXCAFDoc_NoteBalloonDriver>, BinMXCAFDoc_NoteCommentDriver> cls_BinMXCAFDoc_NoteBalloonDriver(mod, "BinMXCAFDoc_NoteBalloonDriver", "None");

// Constructors
cls_BinMXCAFDoc_NoteBalloonDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMsgDriver"));

// Fields

// Methods
cls_BinMXCAFDoc_NoteBalloonDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMXCAFDoc_NoteBalloonDriver::*)() const) &BinMXCAFDoc_NoteBalloonDriver::NewEmpty, "None");
cls_BinMXCAFDoc_NoteBalloonDriver.def_static("get_type_name_", (const char * (*)()) &BinMXCAFDoc_NoteBalloonDriver::get_type_name, "None");
cls_BinMXCAFDoc_NoteBalloonDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMXCAFDoc_NoteBalloonDriver::get_type_descriptor, "None");
cls_BinMXCAFDoc_NoteBalloonDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMXCAFDoc_NoteBalloonDriver::*)() const) &BinMXCAFDoc_NoteBalloonDriver::DynamicType, "None");

// Enums

}