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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <Vrml_Material.hxx>
#include <Standard_TypeDef.hxx>
#include <VrmlConverter_LineAspect.hxx>
#include <Standard_Type.hxx>

void bind_VrmlConverter_LineAspect(py::module &mod){

py::class_<VrmlConverter_LineAspect, opencascade::handle<VrmlConverter_LineAspect>, Standard_Transient> cls_VrmlConverter_LineAspect(mod, "VrmlConverter_LineAspect", "qualifies the aspect properties for the VRML conversation of a Curve and a DeflectionCurve .");

// Constructors
cls_VrmlConverter_LineAspect.def(py::init<>());
cls_VrmlConverter_LineAspect.def(py::init<const opencascade::handle<Vrml_Material> &, const Standard_Boolean>(), py::arg("aMaterial"), py::arg("OnOff"));

// Fields

// Methods
cls_VrmlConverter_LineAspect.def("SetMaterial", (void (VrmlConverter_LineAspect::*)(const opencascade::handle<Vrml_Material> &)) &VrmlConverter_LineAspect::SetMaterial, "None", py::arg("aMaterial"));
cls_VrmlConverter_LineAspect.def("Material", (opencascade::handle<Vrml_Material> (VrmlConverter_LineAspect::*)() const) &VrmlConverter_LineAspect::Material, "None");
cls_VrmlConverter_LineAspect.def("SetHasMaterial", (void (VrmlConverter_LineAspect::*)(const Standard_Boolean)) &VrmlConverter_LineAspect::SetHasMaterial, "defines the necessary of writing own Material from Vrml into output OStream. By default False - the material is not writing into OStream, True - the material is writing.", py::arg("OnOff"));
cls_VrmlConverter_LineAspect.def("HasMaterial", (Standard_Boolean (VrmlConverter_LineAspect::*)() const) &VrmlConverter_LineAspect::HasMaterial, "returns True if the materials is writing into OStream.");
cls_VrmlConverter_LineAspect.def_static("get_type_name_", (const char * (*)()) &VrmlConverter_LineAspect::get_type_name, "None");
cls_VrmlConverter_LineAspect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlConverter_LineAspect::get_type_descriptor, "None");
cls_VrmlConverter_LineAspect.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlConverter_LineAspect::*)() const) &VrmlConverter_LineAspect::DynamicType, "None");

// Enums

}