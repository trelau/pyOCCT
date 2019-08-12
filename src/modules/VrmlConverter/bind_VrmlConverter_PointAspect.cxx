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
#include <VrmlConverter_PointAspect.hxx>
#include <Standard_Type.hxx>

void bind_VrmlConverter_PointAspect(py::module &mod){

py::class_<VrmlConverter_PointAspect, opencascade::handle<VrmlConverter_PointAspect>, Standard_Transient> cls_VrmlConverter_PointAspect(mod, "VrmlConverter_PointAspect", "qualifies the aspect properties for the VRML conversation of a Point Set.");

// Constructors
cls_VrmlConverter_PointAspect.def(py::init<>());
cls_VrmlConverter_PointAspect.def(py::init<const opencascade::handle<Vrml_Material> &, const Standard_Boolean>(), py::arg("aMaterial"), py::arg("OnOff"));

// Fields

// Methods
cls_VrmlConverter_PointAspect.def("SetMaterial", (void (VrmlConverter_PointAspect::*)(const opencascade::handle<Vrml_Material> &)) &VrmlConverter_PointAspect::SetMaterial, "None", py::arg("aMaterial"));
cls_VrmlConverter_PointAspect.def("Material", (opencascade::handle<Vrml_Material> (VrmlConverter_PointAspect::*)() const) &VrmlConverter_PointAspect::Material, "None");
cls_VrmlConverter_PointAspect.def("SetHasMaterial", (void (VrmlConverter_PointAspect::*)(const Standard_Boolean)) &VrmlConverter_PointAspect::SetHasMaterial, "defines the necessary of writing own Material from Vrml into output OStream. By default False - the material is not writing into OStream, True - the material is writing.", py::arg("OnOff"));
cls_VrmlConverter_PointAspect.def("HasMaterial", (Standard_Boolean (VrmlConverter_PointAspect::*)() const) &VrmlConverter_PointAspect::HasMaterial, "returns True if the materials is writing into OStream.");
cls_VrmlConverter_PointAspect.def_static("get_type_name_", (const char * (*)()) &VrmlConverter_PointAspect::get_type_name, "None");
cls_VrmlConverter_PointAspect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlConverter_PointAspect::get_type_descriptor, "None");
cls_VrmlConverter_PointAspect.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlConverter_PointAspect::*)() const) &VrmlConverter_PointAspect::DynamicType, "None");

// Enums

}