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
#include <TopoDS_Shape.hxx>
#include <TopoDS_Face.hxx>
#include <Standard_Handle.hxx>
#include <Poly_Triangulation.hxx>
#include <Poly_Connect.hxx>
#include <TColgp_Array1OfDir.hxx>
#include <Prs3d_Drawer.hxx>
#include <StdPrs_ToolTriangulatedShape.hxx>

void bind_StdPrs_ToolTriangulatedShape(py::module &mod){

py::class_<StdPrs_ToolTriangulatedShape> cls_StdPrs_ToolTriangulatedShape(mod, "StdPrs_ToolTriangulatedShape", "None");

// Constructors

// Fields

// Methods
cls_StdPrs_ToolTriangulatedShape.def_static("IsTriangulated_", (Standard_Boolean (*)(const TopoDS_Shape &)) &StdPrs_ToolTriangulatedShape::IsTriangulated, "Similar to BRepTools::Triangulation() but without extra checks.", py::arg("theShape"));
cls_StdPrs_ToolTriangulatedShape.def_static("IsClosed_", (Standard_Boolean (*)(const TopoDS_Shape &)) &StdPrs_ToolTriangulatedShape::IsClosed, "Checks back faces visibility for specified shape (to activate back-face culling).", py::arg("theShape"));
cls_StdPrs_ToolTriangulatedShape.def_static("ComputeNormals_", (void (*)(const TopoDS_Face &, const opencascade::handle<Poly_Triangulation> &)) &StdPrs_ToolTriangulatedShape::ComputeNormals, "Computes nodal normals for Poly_Triangulation structure using UV coordinates and surface. Does nothing if triangulation already defines normals.", py::arg("theFace"), py::arg("theTris"));
cls_StdPrs_ToolTriangulatedShape.def_static("ComputeNormals_", (void (*)(const TopoDS_Face &, const opencascade::handle<Poly_Triangulation> &, Poly_Connect &)) &StdPrs_ToolTriangulatedShape::ComputeNormals, "Computes nodal normals for Poly_Triangulation structure using UV coordinates and surface. Does nothing if triangulation already defines normals.", py::arg("theFace"), py::arg("theTris"), py::arg("thePolyConnect"));
cls_StdPrs_ToolTriangulatedShape.def_static("Normal_", (void (*)(const TopoDS_Face &, Poly_Connect &, TColgp_Array1OfDir &)) &StdPrs_ToolTriangulatedShape::Normal, "Evaluate normals for a triangle of a face.", py::arg("theFace"), py::arg("thePolyConnect"), py::arg("theNormals"));
cls_StdPrs_ToolTriangulatedShape.def_static("IsTessellated_", (Standard_Boolean (*)(const TopoDS_Shape &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_ToolTriangulatedShape::IsTessellated, "Checks whether the shape is properly triangulated for a given display settings.", py::arg("theShape"), py::arg("theDrawer"));
cls_StdPrs_ToolTriangulatedShape.def_static("Tessellate_", (Standard_Boolean (*)(const TopoDS_Shape &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_ToolTriangulatedShape::Tessellate, "Validates triangulation within the shape and performs tessellation if necessary.", py::arg("theShape"), py::arg("theDrawer"));
cls_StdPrs_ToolTriangulatedShape.def_static("ClearOnOwnDeflectionChange_", (void (*)(const TopoDS_Shape &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Boolean)) &StdPrs_ToolTriangulatedShape::ClearOnOwnDeflectionChange, "If presentation has own deviation coefficient and IsAutoTriangulation() is true, function will compare actual coefficients with previous values and will clear triangulation on their change (regardless actual tessellation quality). Function is placed here for compatibility reasons - new code should avoid using IsAutoTriangulation().", py::arg("theShape"), py::arg("theDrawer"), py::arg("theToResetCoeff"));

// Enums

}