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
#include <Standard_Handle.hxx>
#include <XSControl_TransferReader.hxx>
#include <Transfer_ActorOfTransientProcess.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Transient.hxx>
#include <Interface_InterfaceModel.hxx>
#include <TCollection_AsciiString.hxx>
#include <XSControl_SelectForTransfer.hxx>
#include <Standard_Type.hxx>

void bind_XSControl_SelectForTransfer(py::module &mod){

py::class_<XSControl_SelectForTransfer, opencascade::handle<XSControl_SelectForTransfer>, IFSelect_SelectExtract> cls_XSControl_SelectForTransfer(mod, "XSControl_SelectForTransfer", "This selection selects the entities which are recognised for transfer by an Actor for Read : current one or another one.");

// Constructors
cls_XSControl_SelectForTransfer.def(py::init<>());
cls_XSControl_SelectForTransfer.def(py::init<const opencascade::handle<XSControl_TransferReader> &>(), py::arg("TR"));

// Fields

// Methods
cls_XSControl_SelectForTransfer.def("SetReader", (void (XSControl_SelectForTransfer::*)(const opencascade::handle<XSControl_TransferReader> &)) &XSControl_SelectForTransfer::SetReader, "Sets a TransferReader to sort entities : it brings the Actor, which may change, while the TransferReader does not", py::arg("TR"));
cls_XSControl_SelectForTransfer.def("SetActor", (void (XSControl_SelectForTransfer::*)(const opencascade::handle<Transfer_ActorOfTransientProcess> &)) &XSControl_SelectForTransfer::SetActor, "Sets a precise actor to sort entities This definition oversedes the creation with a TransferReader", py::arg("act"));
cls_XSControl_SelectForTransfer.def("Actor", (opencascade::handle<Transfer_ActorOfTransientProcess> (XSControl_SelectForTransfer::*)() const) &XSControl_SelectForTransfer::Actor, "Returns the Actor used as precised one. Returns a Null Handle for a creation from a TransferReader without any further setting");
cls_XSControl_SelectForTransfer.def("Reader", (opencascade::handle<XSControl_TransferReader> (XSControl_SelectForTransfer::*)() const) &XSControl_SelectForTransfer::Reader, "Returns the Reader (if created with a Reader) Returns a Null Handle if not created with a Reader");
cls_XSControl_SelectForTransfer.def("Sort", (Standard_Boolean (XSControl_SelectForTransfer::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &XSControl_SelectForTransfer::Sort, "Returns True for an Entity which is recognized by the Actor, either the precised one, or the one defined by TransferReader", py::arg("rank"), py::arg("ent"), py::arg("model"));
cls_XSControl_SelectForTransfer.def("ExtractLabel", (TCollection_AsciiString (XSControl_SelectForTransfer::*)() const) &XSControl_SelectForTransfer::ExtractLabel, "Returns a text defining the criterium : 'Recognized for Transfer [(current actor)]'");
cls_XSControl_SelectForTransfer.def_static("get_type_name_", (const char * (*)()) &XSControl_SelectForTransfer::get_type_name, "None");
cls_XSControl_SelectForTransfer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XSControl_SelectForTransfer::get_type_descriptor, "None");
cls_XSControl_SelectForTransfer.def("DynamicType", (const opencascade::handle<Standard_Type> & (XSControl_SelectForTransfer::*)() const) &XSControl_SelectForTransfer::DynamicType, "None");

// Enums

}