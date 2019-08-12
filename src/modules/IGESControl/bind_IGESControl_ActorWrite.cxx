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
#include <Transfer_ActorOfFinderProcess.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Transfer_Finder.hxx>
#include <Transfer_Binder.hxx>
#include <Transfer_FinderProcess.hxx>
#include <IGESControl_ActorWrite.hxx>
#include <Standard_Type.hxx>

void bind_IGESControl_ActorWrite(py::module &mod){

py::class_<IGESControl_ActorWrite, opencascade::handle<IGESControl_ActorWrite>, Transfer_ActorOfFinderProcess> cls_IGESControl_ActorWrite(mod, "IGESControl_ActorWrite", "Actor to write Shape to IGES");

// Constructors
cls_IGESControl_ActorWrite.def(py::init<>());

// Fields

// Methods
cls_IGESControl_ActorWrite.def("Recognize", (Standard_Boolean (IGESControl_ActorWrite::*)(const opencascade::handle<Transfer_Finder> &)) &IGESControl_ActorWrite::Recognize, "Recognizes a ShapeMapper", py::arg("start"));
cls_IGESControl_ActorWrite.def("Transfer", (opencascade::handle<Transfer_Binder> (IGESControl_ActorWrite::*)(const opencascade::handle<Transfer_Finder> &, const opencascade::handle<Transfer_FinderProcess> &)) &IGESControl_ActorWrite::Transfer, "Transfers Shape to IGES Entities", py::arg("start"), py::arg("FP"));
cls_IGESControl_ActorWrite.def_static("get_type_name_", (const char * (*)()) &IGESControl_ActorWrite::get_type_name, "None");
cls_IGESControl_ActorWrite.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESControl_ActorWrite::get_type_descriptor, "None");
cls_IGESControl_ActorWrite.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESControl_ActorWrite::*)() const) &IGESControl_ActorWrite::DynamicType, "None");

// Enums

}