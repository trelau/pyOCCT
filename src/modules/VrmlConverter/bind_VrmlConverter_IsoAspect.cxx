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
#include <VrmlConverter_LineAspect.hxx>
#include <Standard_Handle.hxx>
#include <Vrml_Material.hxx>
#include <Standard_TypeDef.hxx>
#include <VrmlConverter_IsoAspect.hxx>
#include <Standard_Type.hxx>

void bind_VrmlConverter_IsoAspect(py::module &mod){

py::class_<VrmlConverter_IsoAspect, opencascade::handle<VrmlConverter_IsoAspect>, VrmlConverter_LineAspect> cls_VrmlConverter_IsoAspect(mod, "VrmlConverter_IsoAspect", "qualifies the aspect properties for the VRML conversation of iso curves .");

// Constructors
cls_VrmlConverter_IsoAspect.def(py::init<>());
cls_VrmlConverter_IsoAspect.def(py::init<const opencascade::handle<Vrml_Material> &, const Standard_Boolean, const Standard_Integer>(), py::arg("aMaterial"), py::arg("OnOff"), py::arg("aNumber"));

// Fields

// Methods
cls_VrmlConverter_IsoAspect.def("SetNumber", (void (VrmlConverter_IsoAspect::*)(const Standard_Integer)) &VrmlConverter_IsoAspect::SetNumber, "None", py::arg("aNumber"));
cls_VrmlConverter_IsoAspect.def("Number", (Standard_Integer (VrmlConverter_IsoAspect::*)() const) &VrmlConverter_IsoAspect::Number, "returns the number of U or V isoparametric curves drawn for a single face.");
cls_VrmlConverter_IsoAspect.def_static("get_type_name_", (const char * (*)()) &VrmlConverter_IsoAspect::get_type_name, "None");
cls_VrmlConverter_IsoAspect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlConverter_IsoAspect::get_type_descriptor, "None");
cls_VrmlConverter_IsoAspect.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlConverter_IsoAspect::*)() const) &VrmlConverter_IsoAspect::DynamicType, "None");

// Enums

}