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
#include <BVH_Geometry.hxx>
#include <Standard_TypeDef.hxx>
#include <OpenGl_SceneGeometry.hxx>
#include <NCollection_StdAllocator.hxx>
#include <BVH_Types.hxx>
#include <Standard_Handle.hxx>
#include <OpenGl_Texture.hxx>
#include <OpenGl_Context.hxx>
#include <NCollection_Vector.hxx>

void bind_OpenGl_RaytraceGeometry(py::module &mod){

/*
py::class_<OpenGl_RaytraceGeometry, std::unique_ptr<OpenGl_RaytraceGeometry, Deleter<OpenGl_RaytraceGeometry>>, BVH_Geometry<Standard_ShortReal, 3>> cls_OpenGl_RaytraceGeometry(mod, "OpenGl_RaytraceGeometry", "Stores geometry of ray-tracing scene.");

// Constructors
cls_OpenGl_RaytraceGeometry.def(py::init<>());

// Fields
cls_OpenGl_RaytraceGeometry.def_readwrite("Sources", &OpenGl_RaytraceGeometry::Sources, "Array of properties of light sources.");
cls_OpenGl_RaytraceGeometry.def_readwrite("Materials", &OpenGl_RaytraceGeometry::Materials, "Array of 'front' material properties.");
cls_OpenGl_RaytraceGeometry.def_readwrite("Ambient", &OpenGl_RaytraceGeometry::Ambient, "Global ambient from all light sources.");

// Methods
cls_OpenGl_RaytraceGeometry.def("ClearMaterials", (void (OpenGl_RaytraceGeometry::*)()) &OpenGl_RaytraceGeometry::ClearMaterials, "Clears only ray-tracing materials.");
cls_OpenGl_RaytraceGeometry.def("Clear", (void (OpenGl_RaytraceGeometry::*)()) &OpenGl_RaytraceGeometry::Clear, "Clears ray-tracing geometry.");
cls_OpenGl_RaytraceGeometry.def("ProcessAcceleration", (Standard_Boolean (OpenGl_RaytraceGeometry::*)()) &OpenGl_RaytraceGeometry::ProcessAcceleration, "Performs post-processing of high-level scene BVH.");
cls_OpenGl_RaytraceGeometry.def("AccelerationOffset", (Standard_Integer (OpenGl_RaytraceGeometry::*)(Standard_Integer)) &OpenGl_RaytraceGeometry::AccelerationOffset, "Returns offset of bottom-level BVH for given leaf node. If the node index is not valid the function returns -1.", py::arg("theNodeIdx"));
cls_OpenGl_RaytraceGeometry.def("VerticesOffset", (Standard_Integer (OpenGl_RaytraceGeometry::*)(Standard_Integer)) &OpenGl_RaytraceGeometry::VerticesOffset, "Returns offset of triangulation vertices for given leaf node. If the node index is not valid the function returns -1.", py::arg("theNodeIdx"));
cls_OpenGl_RaytraceGeometry.def("ElementsOffset", (Standard_Integer (OpenGl_RaytraceGeometry::*)(Standard_Integer)) &OpenGl_RaytraceGeometry::ElementsOffset, "Returns offset of triangulation elements for given leaf node. If the node index is not valid the function returns -1.", py::arg("theNodeIdx"));
cls_OpenGl_RaytraceGeometry.def("TriangleSet", (OpenGl_TriangleSet * (OpenGl_RaytraceGeometry::*)(Standard_Integer)) &OpenGl_RaytraceGeometry::TriangleSet, "Returns triangulation data for given leaf node. If the node index is not valid the function returns NULL.", py::arg("theNodeIdx"));
cls_OpenGl_RaytraceGeometry.def("QuadBVH", (const QuadBvhHandle & (OpenGl_RaytraceGeometry::*)()) &OpenGl_RaytraceGeometry::QuadBVH, "Returns quad BVH (QBVH) tree produced from binary BVH.");
cls_OpenGl_RaytraceGeometry.def("HasTextures", (Standard_Boolean (OpenGl_RaytraceGeometry::*)() const) &OpenGl_RaytraceGeometry::HasTextures, "Checks if scene contains textured objects.");
cls_OpenGl_RaytraceGeometry.def("AddTexture", (Standard_Integer (OpenGl_RaytraceGeometry::*)(const opencascade::handle<OpenGl_Texture> &)) &OpenGl_RaytraceGeometry::AddTexture, "Adds new OpenGL texture to the scene and returns its index.", py::arg("theTexture"));
cls_OpenGl_RaytraceGeometry.def("UpdateTextureHandles", (Standard_Boolean (OpenGl_RaytraceGeometry::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_RaytraceGeometry::UpdateTextureHandles, "Updates unique 64-bit texture handles to use in shaders.", py::arg("theContext"));
cls_OpenGl_RaytraceGeometry.def("AcquireTextures", (Standard_Boolean (OpenGl_RaytraceGeometry::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_RaytraceGeometry::AcquireTextures, "Makes the OpenGL texture handles resident (must be called before using).", py::arg("theContext"));
cls_OpenGl_RaytraceGeometry.def("ReleaseTextures", (Standard_Boolean (OpenGl_RaytraceGeometry::*)(const opencascade::handle<OpenGl_Context> &) const) &OpenGl_RaytraceGeometry::ReleaseTextures, "Makes the OpenGL texture handles non-resident (must be called after using).", py::arg("theContext"));
cls_OpenGl_RaytraceGeometry.def("TextureHandles", (const std::vector<GLuint64> & (OpenGl_RaytraceGeometry::*)() const) &OpenGl_RaytraceGeometry::TextureHandles, "Returns array of texture handles.");
cls_OpenGl_RaytraceGeometry.def("ReleaseResources", (void (OpenGl_RaytraceGeometry::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_RaytraceGeometry::ReleaseResources, "Releases OpenGL resources.", py::arg(""));
cls_OpenGl_RaytraceGeometry.def("TopLevelTreeDepth", (Standard_Integer (OpenGl_RaytraceGeometry::*)() const) &OpenGl_RaytraceGeometry::TopLevelTreeDepth, "Returns depth of top-level scene BVH from last build.");
cls_OpenGl_RaytraceGeometry.def("BotLevelTreeDepth", (Standard_Integer (OpenGl_RaytraceGeometry::*)() const) &OpenGl_RaytraceGeometry::BotLevelTreeDepth, "Returns maximum depth of bottom-level scene BVHs from last build.");

// Enums
*/

}