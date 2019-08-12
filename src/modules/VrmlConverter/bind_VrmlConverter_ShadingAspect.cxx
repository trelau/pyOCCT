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
#include <Vrml_ShapeHints.hxx>
#include <Standard_TypeDef.hxx>
#include <VrmlConverter_ShadingAspect.hxx>
#include <Standard_Type.hxx>

void bind_VrmlConverter_ShadingAspect(py::module &mod){

py::class_<VrmlConverter_ShadingAspect, opencascade::handle<VrmlConverter_ShadingAspect>, Standard_Transient> cls_VrmlConverter_ShadingAspect(mod, "VrmlConverter_ShadingAspect", "qualifies the aspect properties for the VRML conversation of ShadedShape .");

// Constructors
cls_VrmlConverter_ShadingAspect.def(py::init<>());

// Fields

// Methods
cls_VrmlConverter_ShadingAspect.def("SetFrontMaterial", (void (VrmlConverter_ShadingAspect::*)(const opencascade::handle<Vrml_Material> &)) &VrmlConverter_ShadingAspect::SetFrontMaterial, "None", py::arg("aMaterial"));
cls_VrmlConverter_ShadingAspect.def("FrontMaterial", (opencascade::handle<Vrml_Material> (VrmlConverter_ShadingAspect::*)() const) &VrmlConverter_ShadingAspect::FrontMaterial, "None");
cls_VrmlConverter_ShadingAspect.def("SetShapeHints", (void (VrmlConverter_ShadingAspect::*)(const Vrml_ShapeHints &)) &VrmlConverter_ShadingAspect::SetShapeHints, "None", py::arg("aShapeHints"));
cls_VrmlConverter_ShadingAspect.def("ShapeHints", (Vrml_ShapeHints (VrmlConverter_ShadingAspect::*)() const) &VrmlConverter_ShadingAspect::ShapeHints, "None");
cls_VrmlConverter_ShadingAspect.def("SetHasNormals", (void (VrmlConverter_ShadingAspect::*)(const Standard_Boolean)) &VrmlConverter_ShadingAspect::SetHasNormals, "defines necessary of a calculation of normals for ShadedShape to more accurately display curved surfaces, pacticularly when smoooth or phong shading is used in VRML viewer. By default False - the normals are not calculated, True - the normals are calculated. Warning: If normals are calculated the resulting VRML file will be substantially lager.", py::arg("OnOff"));
cls_VrmlConverter_ShadingAspect.def("HasNormals", (Standard_Boolean (VrmlConverter_ShadingAspect::*)() const) &VrmlConverter_ShadingAspect::HasNormals, "returns True if the normals are calculating");
cls_VrmlConverter_ShadingAspect.def("SetHasMaterial", (void (VrmlConverter_ShadingAspect::*)(const Standard_Boolean)) &VrmlConverter_ShadingAspect::SetHasMaterial, "defines necessary of writing Material from Vrml into output OStream. By default False - the material is not writing into OStream, True - the material is writing.", py::arg("OnOff"));
cls_VrmlConverter_ShadingAspect.def("HasMaterial", (Standard_Boolean (VrmlConverter_ShadingAspect::*)() const) &VrmlConverter_ShadingAspect::HasMaterial, "returns True if the materials is writing into OStream.");
cls_VrmlConverter_ShadingAspect.def_static("get_type_name_", (const char * (*)()) &VrmlConverter_ShadingAspect::get_type_name, "None");
cls_VrmlConverter_ShadingAspect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlConverter_ShadingAspect::get_type_descriptor, "None");
cls_VrmlConverter_ShadingAspect.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlConverter_ShadingAspect::*)() const) &VrmlConverter_ShadingAspect::DynamicType, "None");

// Enums

}