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
#include <XSControl_WorkSession.hxx>
#include <IFSelect_SessionPilot.hxx>
#include <XSControl_Vars.hxx>
#include <XSControl_Controller.hxx>
#include <XSControl_TransferReader.hxx>
#include <XSControl_TransferWriter.hxx>
#include <XSControl_SelectForTransfer.hxx>
#include <XSControl_SignTransferStatus.hxx>
#include <XSControl_ConnectedShapes.hxx>
#include <XSControl_Reader.hxx>
#include <XSControl_Writer.hxx>
#include <XSControl_Functions.hxx>
#include <XSControl_FuncShape.hxx>
#include <XSControl_Utils.hxx>
#include <XSControl.hxx>

void bind_XSControl(py::module &mod){

py::class_<XSControl, std::unique_ptr<XSControl, Deleter<XSControl>>> cls_XSControl(mod, "XSControl", "This package provides complements to IFSelect & Co for control of a session");

// Constructors

// Fields

// Methods
// cls_XSControl.def_static("operator new_", (void * (*)(size_t)) &XSControl::operator new, "None", py::arg("theSize"));
// cls_XSControl.def_static("operator delete_", (void (*)(void *)) &XSControl::operator delete, "None", py::arg("theAddress"));
// cls_XSControl.def_static("operator new[]_", (void * (*)(size_t)) &XSControl::operator new[], "None", py::arg("theSize"));
// cls_XSControl.def_static("operator delete[]_", (void (*)(void *)) &XSControl::operator delete[], "None", py::arg("theAddress"));
// cls_XSControl.def_static("operator new_", (void * (*)(size_t, void *)) &XSControl::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_XSControl.def_static("operator delete_", (void (*)(void *, void *)) &XSControl::operator delete, "None", py::arg(""), py::arg(""));
cls_XSControl.def_static("Session_", (opencascade::handle<XSControl_WorkSession> (*)(const opencascade::handle<IFSelect_SessionPilot> &)) &XSControl::Session, "Returns the WorkSession of a SessionPilot, but casts it as from XSControl : it then gives access to Control & Transfers", py::arg("pilot"));
cls_XSControl.def_static("Vars_", (opencascade::handle<XSControl_Vars> (*)(const opencascade::handle<IFSelect_SessionPilot> &)) &XSControl::Vars, "Returns the Vars of a SessionPilot, it is brought by Session it provides access to external variables", py::arg("pilot"));

// Enums

}