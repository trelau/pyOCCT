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

void bind_OpenGl_RaytraceLight(py::module &mod){

py::class_<OpenGl_RaytraceLight> cls_OpenGl_RaytraceLight(mod, "OpenGl_RaytraceLight", "Stores properties of OpenGL light source.");

// Constructors
// cls_OpenGl_RaytraceLight.def(py::init<>());
// cls_OpenGl_RaytraceLight.def(py::init<const BVH_Vec4f &, const BVH_Vec4f &>(), py::arg("theEmission"), py::arg("thePosition"));

// Fields
cls_OpenGl_RaytraceLight.def_readwrite("Emission", &OpenGl_RaytraceLight::Emission, "Diffuse intensity (in terms of OpenGL).");
cls_OpenGl_RaytraceLight.def_readwrite("Position", &OpenGl_RaytraceLight::Position, "Position of light source (in terms of OpenGL).");

// Methods
cls_OpenGl_RaytraceLight.def("Packed", (const Standard_ShortReal * (OpenGl_RaytraceLight::*)()) &OpenGl_RaytraceLight::Packed, "Returns packed (serialized) representation of light source.");

// Enums

}