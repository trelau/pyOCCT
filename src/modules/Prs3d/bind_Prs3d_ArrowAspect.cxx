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
#include <Prs3d_BasicAspect.hxx>
#include <Standard_Handle.hxx>
#include <Prs3d_ArrowAspect.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_AspectLine3d.hxx>
#include <Quantity_Color.hxx>

void bind_Prs3d_ArrowAspect(py::module &mod){

py::class_<Prs3d_ArrowAspect, opencascade::handle<Prs3d_ArrowAspect>, Prs3d_BasicAspect> cls_Prs3d_ArrowAspect(mod, "Prs3d_ArrowAspect", "A framework for displaying arrows in representations of dimensions and relations.");

// Constructors
cls_Prs3d_ArrowAspect.def(py::init<>());
cls_Prs3d_ArrowAspect.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("anAngle"), py::arg("aLength"));
cls_Prs3d_ArrowAspect.def(py::init<const opencascade::handle<Graphic3d_AspectLine3d> &>(), py::arg("theAspect"));

// Fields

// Methods
cls_Prs3d_ArrowAspect.def_static("get_type_name_", (const char * (*)()) &Prs3d_ArrowAspect::get_type_name, "None");
cls_Prs3d_ArrowAspect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Prs3d_ArrowAspect::get_type_descriptor, "None");
cls_Prs3d_ArrowAspect.def("DynamicType", (const opencascade::handle<Standard_Type> & (Prs3d_ArrowAspect::*)() const) &Prs3d_ArrowAspect::DynamicType, "None");
cls_Prs3d_ArrowAspect.def("SetAngle", (void (Prs3d_ArrowAspect::*)(const Standard_Real)) &Prs3d_ArrowAspect::SetAngle, "defines the angle of the arrows.", py::arg("anAngle"));
cls_Prs3d_ArrowAspect.def("Angle", (Standard_Real (Prs3d_ArrowAspect::*)() const) &Prs3d_ArrowAspect::Angle, "returns the current value of the angle used when drawing an arrow.");
cls_Prs3d_ArrowAspect.def("SetLength", (void (Prs3d_ArrowAspect::*)(const Standard_Real)) &Prs3d_ArrowAspect::SetLength, "Defines the length of the arrows.", py::arg("theLength"));
cls_Prs3d_ArrowAspect.def("Length", (Standard_Real (Prs3d_ArrowAspect::*)() const) &Prs3d_ArrowAspect::Length, "Returns the current value of the length used when drawing an arrow.");
cls_Prs3d_ArrowAspect.def("SetColor", (void (Prs3d_ArrowAspect::*)(const Quantity_Color &)) &Prs3d_ArrowAspect::SetColor, "None", py::arg("theColor"));
cls_Prs3d_ArrowAspect.def("Aspect", (const opencascade::handle<Graphic3d_AspectLine3d> & (Prs3d_ArrowAspect::*)() const) &Prs3d_ArrowAspect::Aspect, "None");
cls_Prs3d_ArrowAspect.def("SetAspect", (void (Prs3d_ArrowAspect::*)(const opencascade::handle<Graphic3d_AspectLine3d> &)) &Prs3d_ArrowAspect::SetAspect, "None", py::arg("theAspect"));

// Enums

}