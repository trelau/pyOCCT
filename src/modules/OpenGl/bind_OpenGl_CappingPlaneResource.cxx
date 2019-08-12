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
#include <OpenGl_Resource.hxx>
#include <Standard_Handle.hxx>
#include <Graphic3d_ClipPlane.hxx>
#include <OpenGl_Context.hxx>
#include <Graphic3d_AspectFillArea3d.hxx>
#include <NCollection_SparseArrayBase.hxx>
#include <OpenGl_AspectFace.hxx>
#include <OpenGl_Matrix.hxx>
#include <OpenGl_PrimitiveArray.hxx>
#include <OpenGl_CappingPlaneResource.hxx>
#include <Standard_Type.hxx>

void bind_OpenGl_CappingPlaneResource(py::module &mod){

py::class_<OpenGl_CappingPlaneResource, opencascade::handle<OpenGl_CappingPlaneResource>, OpenGl_Resource> cls_OpenGl_CappingPlaneResource(mod, "OpenGl_CappingPlaneResource", "Container of graphical resources for rendering capping plane associated to graphical clipping plane. This resource holds data necessary for OpenGl_CappingAlgo. This object is implemented as OpenGl resource for the following reasons: - one instance should be shared between contexts. - instance associated to Graphic3d_ClipPlane data by id. - should created and released within context (owns OpenGl elements and resources).");

// Constructors
cls_OpenGl_CappingPlaneResource.def(py::init<const opencascade::handle<Graphic3d_ClipPlane> &>(), py::arg("thePlane"));

// Fields

// Methods
cls_OpenGl_CappingPlaneResource.def("Update", (void (OpenGl_CappingPlaneResource::*)(const opencascade::handle<OpenGl_Context> &, const opencascade::handle<Graphic3d_AspectFillArea3d> &)) &OpenGl_CappingPlaneResource::Update, "Update resource data in the passed context.", py::arg("theContext"), py::arg("theObjAspect"));
cls_OpenGl_CappingPlaneResource.def("Release", (void (OpenGl_CappingPlaneResource::*)(OpenGl_Context *)) &OpenGl_CappingPlaneResource::Release, "Release associated OpenGl resources.", py::arg("theContext"));
cls_OpenGl_CappingPlaneResource.def("EstimatedDataSize", (Standard_Size (OpenGl_CappingPlaneResource::*)() const) &OpenGl_CappingPlaneResource::EstimatedDataSize, "Returns estimated GPU memory usage - not implemented.");
cls_OpenGl_CappingPlaneResource.def("Plane", (const opencascade::handle<Graphic3d_ClipPlane> & (OpenGl_CappingPlaneResource::*)() const) &OpenGl_CappingPlaneResource::Plane, "Return parent clipping plane structure.");
cls_OpenGl_CappingPlaneResource.def("AspectFace", (const OpenGl_AspectFace * (OpenGl_CappingPlaneResource::*)() const) &OpenGl_CappingPlaneResource::AspectFace, "Returns aspect face for rendering capping surface.");
cls_OpenGl_CappingPlaneResource.def("Orientation", (const OpenGl_Matrix * (OpenGl_CappingPlaneResource::*)() const) &OpenGl_CappingPlaneResource::Orientation, "Returns evaluated orientation matrix to transform infinite plane.");
cls_OpenGl_CappingPlaneResource.def("Primitives", (const OpenGl_PrimitiveArray & (OpenGl_CappingPlaneResource::*)() const) &OpenGl_CappingPlaneResource::Primitives, "Returns primitive array of vertices to render infinite plane.");
cls_OpenGl_CappingPlaneResource.def_static("get_type_name_", (const char * (*)()) &OpenGl_CappingPlaneResource::get_type_name, "None");
cls_OpenGl_CappingPlaneResource.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_CappingPlaneResource::get_type_descriptor, "None");
cls_OpenGl_CappingPlaneResource.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_CappingPlaneResource::*)() const) &OpenGl_CappingPlaneResource::DynamicType, "None");

// Enums

}