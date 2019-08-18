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
#include <OpenGl_SceneGeometry.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_SparseArrayBase.hxx>
#include <BVH_Builder.hxx>
#include <BVH_Set.hxx>
#include <BVH_Triangulation.hxx>
#include <BVH_Types.hxx>

void bind_OpenGl_TriangleSet(py::module &mod){

py::class_<OpenGl_TriangleSet, opencascade::handle<OpenGl_TriangleSet>> cls_OpenGl_TriangleSet(mod, "OpenGl_TriangleSet", "Triangulation of single OpenGL primitive array.");

// Constructors
// cls_OpenGl_TriangleSet.def(py::init<const Standard_Size, const opencascade::handle<BVH_Builder<Standard_ShortReal, 3> > &>(), py::arg("theArrayID"), py::arg("theBuilder"));

// Fields
cls_OpenGl_TriangleSet.def_readwrite("Normals", &OpenGl_TriangleSet::Normals, "Array of vertex normals.");
cls_OpenGl_TriangleSet.def_readwrite("TexCrds", &OpenGl_TriangleSet::TexCrds, "Array of texture coords.");

// Methods
cls_OpenGl_TriangleSet.def_static("get_type_name_", (const char * (*)()) &OpenGl_TriangleSet::get_type_name, "None");
cls_OpenGl_TriangleSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_TriangleSet::get_type_descriptor, "None");
cls_OpenGl_TriangleSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_TriangleSet::*)() const) &OpenGl_TriangleSet::DynamicType, "None");
cls_OpenGl_TriangleSet.def("AssociatedPArrayID", (Standard_Size (OpenGl_TriangleSet::*)() const) &OpenGl_TriangleSet::AssociatedPArrayID, "Returns ID of associated primitive array.");
cls_OpenGl_TriangleSet.def("MaterialIndex", (Standard_Integer (OpenGl_TriangleSet::*)() const) &OpenGl_TriangleSet::MaterialIndex, "Returns material index of triangle set.");
cls_OpenGl_TriangleSet.def("SetMaterialIndex", (void (OpenGl_TriangleSet::*)(Standard_Integer)) &OpenGl_TriangleSet::SetMaterialIndex, "Sets material index for entire triangle set.", py::arg("theMatID"));
cls_OpenGl_TriangleSet.def("Box", (BVH_Set<float, 3>::BVH_BoxNt (OpenGl_TriangleSet::*)() const) &OpenGl_TriangleSet::Box, "Returns AABB of primitive set.");
cls_OpenGl_TriangleSet.def("Center", (Standard_ShortReal (OpenGl_TriangleSet::*)(const Standard_Integer, const Standard_Integer) const) &OpenGl_TriangleSet::Center, "Returns centroid position along the given axis.", py::arg("theIndex"), py::arg("theAxis"));
// cls_OpenGl_TriangleSet.def("QuadBVH", (const QuadBvhHandle & (OpenGl_TriangleSet::*)()) &OpenGl_TriangleSet::QuadBVH, "Returns quad BVH (QBVH) tree produced from binary BVH.");

// Enums

}