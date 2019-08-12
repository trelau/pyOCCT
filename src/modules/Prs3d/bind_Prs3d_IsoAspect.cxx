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
#include <Prs3d_LineAspect.hxx>
#include <Standard_Handle.hxx>
#include <Prs3d_IsoAspect.hxx>
#include <Standard_Type.hxx>
#include <Quantity_Color.hxx>
#include <Aspect_TypeOfLine.hxx>
#include <Standard_TypeDef.hxx>

void bind_Prs3d_IsoAspect(py::module &mod){

py::class_<Prs3d_IsoAspect, opencascade::handle<Prs3d_IsoAspect>, Prs3d_LineAspect> cls_Prs3d_IsoAspect(mod, "Prs3d_IsoAspect", "A framework to define the display attributes of isoparameters. This framework can be used to modify the default setting for isoparameters in Prs3d_Drawer.");

// Constructors
cls_Prs3d_IsoAspect.def(py::init<const Quantity_Color &, const Aspect_TypeOfLine, const Standard_Real, const Standard_Integer>(), py::arg("theColor"), py::arg("theType"), py::arg("theWidth"), py::arg("theNumber"));

// Fields

// Methods
cls_Prs3d_IsoAspect.def_static("get_type_name_", (const char * (*)()) &Prs3d_IsoAspect::get_type_name, "None");
cls_Prs3d_IsoAspect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Prs3d_IsoAspect::get_type_descriptor, "None");
cls_Prs3d_IsoAspect.def("DynamicType", (const opencascade::handle<Standard_Type> & (Prs3d_IsoAspect::*)() const) &Prs3d_IsoAspect::DynamicType, "None");
cls_Prs3d_IsoAspect.def("SetNumber", (void (Prs3d_IsoAspect::*)(const Standard_Integer)) &Prs3d_IsoAspect::SetNumber, "defines the number of U or V isoparametric curves to be drawn for a single face. Default value: 10", py::arg("theNumber"));
cls_Prs3d_IsoAspect.def("Number", (Standard_Integer (Prs3d_IsoAspect::*)() const) &Prs3d_IsoAspect::Number, "returns the number of U or V isoparametric curves drawn for a single face.");

// Enums

}