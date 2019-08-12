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
#include <AIS_Animation.hxx>
#include <Standard_Handle.hxx>
#include <AIS_AnimationObject.hxx>
#include <Standard_Type.hxx>
#include <TCollection_AsciiString.hxx>
#include <AIS_InteractiveContext.hxx>
#include <AIS_InteractiveObject.hxx>
#include <gp_Trsf.hxx>
#include <gp_TrsfNLerp.hxx>

void bind_AIS_AnimationObject(py::module &mod){

py::class_<AIS_AnimationObject, opencascade::handle<AIS_AnimationObject>, AIS_Animation> cls_AIS_AnimationObject(mod, "AIS_AnimationObject", "Animation defining object transformation.");

// Constructors
cls_AIS_AnimationObject.def(py::init<const TCollection_AsciiString &, const opencascade::handle<AIS_InteractiveContext> &, const opencascade::handle<AIS_InteractiveObject> &, const gp_Trsf &, const gp_Trsf &>(), py::arg("theAnimationName"), py::arg("theContext"), py::arg("theObject"), py::arg("theTrsfStart"), py::arg("theTrsfEnd"));

// Fields

// Methods
cls_AIS_AnimationObject.def_static("get_type_name_", (const char * (*)()) &AIS_AnimationObject::get_type_name, "None");
cls_AIS_AnimationObject.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_AnimationObject::get_type_descriptor, "None");
cls_AIS_AnimationObject.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_AnimationObject::*)() const) &AIS_AnimationObject::DynamicType, "None");

// Enums

}