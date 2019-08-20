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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Graphic3d_Camera.hxx>
#include <OpenGl_BVHTreeSelector.hxx>
#include <OpenGl_Vec.hxx>
#include <Graphic3d_WorldViewProjState.hxx>
#include <Graphic3d_Vec3.hxx>

void bind_OpenGl_BVHTreeSelector(py::module &mod){

py::class_<OpenGl_BVHTreeSelector, std::unique_ptr<OpenGl_BVHTreeSelector>> cls_OpenGl_BVHTreeSelector(mod, "OpenGl_BVHTreeSelector", "BVHTreeSelector class provides a possibility to store parameters of view volume, such as its vertices and equations, and contains methods detecting if given AABB overlaps view volume.");

// Constructors
cls_OpenGl_BVHTreeSelector.def(py::init<>());

// Fields

// Methods
cls_OpenGl_BVHTreeSelector.def("SetViewVolume", (void (OpenGl_BVHTreeSelector::*)(const opencascade::handle<Graphic3d_Camera> &)) &OpenGl_BVHTreeSelector::SetViewVolume, "Retrieves view volume's planes equations and its vertices from projection and world-view matrices.", py::arg("theCamera"));
cls_OpenGl_BVHTreeSelector.def("SetViewportSize", (void (OpenGl_BVHTreeSelector::*)(Standard_Integer, Standard_Integer, Standard_Real)) &OpenGl_BVHTreeSelector::SetViewportSize, "None", py::arg("theViewportWidth"), py::arg("theViewportHeight"), py::arg("theResolutionRatio"));
cls_OpenGl_BVHTreeSelector.def("SetCullingDistance", (void (OpenGl_BVHTreeSelector::*)(OpenGl_BVHTreeSelector::CullingContext &, Standard_Real) const) &OpenGl_BVHTreeSelector::SetCullingDistance, "Setup distance culling.", py::arg("theCtx"), py::arg("theDistance"));
cls_OpenGl_BVHTreeSelector.def("SetCullingSize", (void (OpenGl_BVHTreeSelector::*)(OpenGl_BVHTreeSelector::CullingContext &, Standard_Real) const) &OpenGl_BVHTreeSelector::SetCullingSize, "Setup size culling.", py::arg("theCtx"), py::arg("theSize"));
cls_OpenGl_BVHTreeSelector.def("CacheClipPtsProjections", (void (OpenGl_BVHTreeSelector::*)()) &OpenGl_BVHTreeSelector::CacheClipPtsProjections, "Caches view volume's vertices projections along its normals and AABBs dimensions. Must be called at the beginning of each BVH tree traverse loop.");
cls_OpenGl_BVHTreeSelector.def("IsCulled", (bool (OpenGl_BVHTreeSelector::*)(const OpenGl_BVHTreeSelector::CullingContext &, const OpenGl_Vec3d &, const OpenGl_Vec3d &) const) &OpenGl_BVHTreeSelector::IsCulled, "Checks whether given AABB should be entirely culled or not.", py::arg("theCtx"), py::arg("theMinPt"), py::arg("theMaxPt"));
cls_OpenGl_BVHTreeSelector.def("Camera", (const opencascade::handle<Graphic3d_Camera> & (OpenGl_BVHTreeSelector::*)() const) &OpenGl_BVHTreeSelector::Camera, "Return the camera definition.");
cls_OpenGl_BVHTreeSelector.def("ProjectionMatrix", (const OpenGl_Mat4d & (OpenGl_BVHTreeSelector::*)() const) &OpenGl_BVHTreeSelector::ProjectionMatrix, "Returns current projection matrix.");
cls_OpenGl_BVHTreeSelector.def("WorldViewMatrix", (const OpenGl_Mat4d & (OpenGl_BVHTreeSelector::*)() const) &OpenGl_BVHTreeSelector::WorldViewMatrix, "Returns current world view transformation matrix.");
cls_OpenGl_BVHTreeSelector.def("ViewportWidth", (Standard_Integer (OpenGl_BVHTreeSelector::*)() const) &OpenGl_BVHTreeSelector::ViewportWidth, "None");
cls_OpenGl_BVHTreeSelector.def("ViewportHeight", (Standard_Integer (OpenGl_BVHTreeSelector::*)() const) &OpenGl_BVHTreeSelector::ViewportHeight, "None");
cls_OpenGl_BVHTreeSelector.def("WorldViewProjState", (const Graphic3d_WorldViewProjState & (OpenGl_BVHTreeSelector::*)() const) &OpenGl_BVHTreeSelector::WorldViewProjState, "Returns state of current world view projection transformation matrices.");

// Enums

}