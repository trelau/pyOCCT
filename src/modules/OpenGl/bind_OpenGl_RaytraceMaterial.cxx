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
#include <BVH_Types.hxx>
#include <Standard_TypeDef.hxx>
#include <OpenGl_SceneGeometry.hxx>

void bind_OpenGl_RaytraceMaterial(py::module &mod){

/*
py::class_<OpenGl_RaytraceMaterial> cls_OpenGl_RaytraceMaterial(mod, "OpenGl_RaytraceMaterial", "Stores properties of surface material.");

// Constructors
cls_OpenGl_RaytraceMaterial.def(py::init<>());
cls_OpenGl_RaytraceMaterial.def(py::init<const BVH_Vec4f &, const BVH_Vec4f &, const BVH_Vec4f &>(), py::arg("theAmbient"), py::arg("theDiffuse"), py::arg("theSpecular"));
cls_OpenGl_RaytraceMaterial.def(py::init<const BVH_Vec4f &, const BVH_Vec4f &, const BVH_Vec4f &, const BVH_Vec4f &, const BVH_Vec4f &>(), py::arg("theAmbient"), py::arg("theDiffuse"), py::arg("theSpecular"), py::arg("theEmission"), py::arg("theTranspar"));
cls_OpenGl_RaytraceMaterial.def(py::init<const BVH_Vec4f &, const BVH_Vec4f &, const BVH_Vec4f &, const BVH_Vec4f &, const BVH_Vec4f &, const BVH_Vec4f &, const BVH_Vec4f &>(), py::arg("theAmbient"), py::arg("theDiffuse"), py::arg("theSpecular"), py::arg("theEmission"), py::arg("theTranspar"), py::arg("theReflection"), py::arg("theRefraction"));

// Fields
cls_OpenGl_RaytraceMaterial.def_readwrite("Ambient", &OpenGl_RaytraceMaterial::Ambient, "Ambient reflection coefficient.");
cls_OpenGl_RaytraceMaterial.def_readwrite("Diffuse", &OpenGl_RaytraceMaterial::Diffuse, "Diffuse reflection coefficient.");
cls_OpenGl_RaytraceMaterial.def_readwrite("Specular", &OpenGl_RaytraceMaterial::Specular, "Glossy reflection coefficient.");
cls_OpenGl_RaytraceMaterial.def_readwrite("Emission", &OpenGl_RaytraceMaterial::Emission, "Material emission.");
cls_OpenGl_RaytraceMaterial.def_readwrite("Reflection", &OpenGl_RaytraceMaterial::Reflection, "Specular reflection coefficient.");
cls_OpenGl_RaytraceMaterial.def_readwrite("Refraction", &OpenGl_RaytraceMaterial::Refraction, "Specular refraction coefficient.");
cls_OpenGl_RaytraceMaterial.def_readwrite("Transparency", &OpenGl_RaytraceMaterial::Transparency, "Material transparency.");
cls_OpenGl_RaytraceMaterial.def_readwrite("TextureTransform", &OpenGl_RaytraceMaterial::TextureTransform, "Texture transformation matrix.");
cls_OpenGl_RaytraceMaterial.def_readwrite("BSDF", &OpenGl_RaytraceMaterial::BSDF, "None");

// Methods
cls_OpenGl_RaytraceMaterial.def("Packed", (const Standard_ShortReal * (OpenGl_RaytraceMaterial::*)()) &OpenGl_RaytraceMaterial::Packed, "Returns packed (serialized) representation of material.");

// Enums
*/

}