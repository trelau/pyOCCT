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
#include <STEPControl_ActorWrite.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Handle.hxx>
#include <STEPCAFControl_ActorWrite.hxx>
#include <Standard_Type.hxx>
#include <TopTools_MapOfShape.hxx>

void bind_STEPCAFControl_ActorWrite(py::module &mod){

py::class_<STEPCAFControl_ActorWrite, opencascade::handle<STEPCAFControl_ActorWrite>, STEPControl_ActorWrite> cls_STEPCAFControl_ActorWrite(mod, "STEPCAFControl_ActorWrite", "Extends ActorWrite from STEPControl by analysis of whether shape is assembly (based on information from DECAF)");

// Constructors
cls_STEPCAFControl_ActorWrite.def(py::init<>());

// Fields

// Methods
cls_STEPCAFControl_ActorWrite.def("IsAssembly", (Standard_Boolean (STEPCAFControl_ActorWrite::*)(TopoDS_Shape &) const) &STEPCAFControl_ActorWrite::IsAssembly, "Check whether shape S is assembly Returns True if shape is registered in assemblies map", py::arg("S"));
cls_STEPCAFControl_ActorWrite.def("SetStdMode", [](STEPCAFControl_ActorWrite &self) -> void { return self.SetStdMode(); });
cls_STEPCAFControl_ActorWrite.def("SetStdMode", (void (STEPCAFControl_ActorWrite::*)(const Standard_Boolean)) &STEPCAFControl_ActorWrite::SetStdMode, "Set standard mode of work In standard mode Actor (default) behaves exactly as its ancestor, also map is cleared", py::arg("stdmode"));
cls_STEPCAFControl_ActorWrite.def("ClearMap", (void (STEPCAFControl_ActorWrite::*)()) &STEPCAFControl_ActorWrite::ClearMap, "Clears map of shapes registered as assemblies");
cls_STEPCAFControl_ActorWrite.def("RegisterAssembly", (void (STEPCAFControl_ActorWrite::*)(const TopoDS_Shape &)) &STEPCAFControl_ActorWrite::RegisterAssembly, "Registers shape to be written as assembly The shape should be TopoDS_Compound (else does nothing)", py::arg("S"));
cls_STEPCAFControl_ActorWrite.def_static("get_type_name_", (const char * (*)()) &STEPCAFControl_ActorWrite::get_type_name, "None");
cls_STEPCAFControl_ActorWrite.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &STEPCAFControl_ActorWrite::get_type_descriptor, "None");
cls_STEPCAFControl_ActorWrite.def("DynamicType", (const opencascade::handle<Standard_Type> & (STEPCAFControl_ActorWrite::*)() const) &STEPCAFControl_ActorWrite::DynamicType, "None");

// Enums

}