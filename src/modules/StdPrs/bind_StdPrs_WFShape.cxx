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
#include <Prs3d_Root.hxx>
#include <Standard_Handle.hxx>
#include <Prs3d_Presentation.hxx>
#include <TopoDS_Shape.hxx>
#include <Prs3d_Drawer.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_ArrayOfPrimitives.hxx>
#include <TColgp_SequenceOfPnt.hxx>
#include <TopTools_ListOfShape.hxx>
#include <Prs3d_NListOfSequenceOfPnt.hxx>
#include <Prs3d_PointAspect.hxx>
#include <StdPrs_WFShape.hxx>

void bind_StdPrs_WFShape(py::module &mod){

py::class_<StdPrs_WFShape, Prs3d_Root> cls_StdPrs_WFShape(mod, "StdPrs_WFShape", "Tool for computing wireframe presentation of a TopoDS_Shape.");

// Constructors

// Fields

// Methods
cls_StdPrs_WFShape.def_static("Add_", [](const opencascade::handle<Prs3d_Presentation> & a0, const TopoDS_Shape & a1, const opencascade::handle<Prs3d_Drawer> & a2) -> void { return StdPrs_WFShape::Add(a0, a1, a2); });
cls_StdPrs_WFShape.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const TopoDS_Shape &, const opencascade::handle<Prs3d_Drawer> &, Standard_Boolean)) &StdPrs_WFShape::Add, "Computes wireframe presentation of a shape.", py::arg("thePresentation"), py::arg("theShape"), py::arg("theDrawer"), py::arg("theIsParallel"));
cls_StdPrs_WFShape.def_static("AddEdgesOnTriangulation_", [](const TopoDS_Shape & a0) -> opencascade::handle<Graphic3d_ArrayOfPrimitives> { return StdPrs_WFShape::AddEdgesOnTriangulation(a0); });
cls_StdPrs_WFShape.def_static("AddEdgesOnTriangulation_", (opencascade::handle<Graphic3d_ArrayOfPrimitives> (*)(const TopoDS_Shape &, const Standard_Boolean)) &StdPrs_WFShape::AddEdgesOnTriangulation, "Compute free and boundary edges on a triangulation of each face in the given shape.", py::arg("theShape"), py::arg("theToExcludeGeometric"));
cls_StdPrs_WFShape.def_static("AddEdgesOnTriangulation_", [](TColgp_SequenceOfPnt & a0, const TopoDS_Shape & a1) -> void { return StdPrs_WFShape::AddEdgesOnTriangulation(a0, a1); });
cls_StdPrs_WFShape.def_static("AddEdgesOnTriangulation_", (void (*)(TColgp_SequenceOfPnt &, const TopoDS_Shape &, const Standard_Boolean)) &StdPrs_WFShape::AddEdgesOnTriangulation, "Compute free and boundary edges on a triangulation of each face in the given shape.", py::arg("theSegments"), py::arg("theShape"), py::arg("theToExcludeGeometric"));

// Enums

}