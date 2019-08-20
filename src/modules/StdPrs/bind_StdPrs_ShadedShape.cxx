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
#include <StdPrs_Volume.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt2d.hxx>
#include <BRep_Builder.hxx>
#include <TopoDS_Compound.hxx>
#include <Graphic3d_ArrayOfTriangles.hxx>
#include <Graphic3d_ArrayOfSegments.hxx>
#include <StdPrs_ShadedShape.hxx>

void bind_StdPrs_ShadedShape(py::module &mod){

py::class_<StdPrs_ShadedShape, std::unique_ptr<StdPrs_ShadedShape>, Prs3d_Root> cls_StdPrs_ShadedShape(mod, "StdPrs_ShadedShape", "Auxiliary procedures to prepare Shaded presentation of specified shape.");

// Constructors

// Fields

// Methods
cls_StdPrs_ShadedShape.def_static("Add_", [](const opencascade::handle<Prs3d_Presentation> & a0, const TopoDS_Shape & a1, const opencascade::handle<Prs3d_Drawer> & a2) -> void { return StdPrs_ShadedShape::Add(a0, a1, a2); });
cls_StdPrs_ShadedShape.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const TopoDS_Shape &, const opencascade::handle<Prs3d_Drawer> &, const StdPrs_Volume)) &StdPrs_ShadedShape::Add, "Shades <theShape>.", py::arg("thePresentation"), py::arg("theShape"), py::arg("theDrawer"), py::arg("theVolume"));
cls_StdPrs_ShadedShape.def_static("Add_", [](const opencascade::handle<Prs3d_Presentation> & a0, const TopoDS_Shape & a1, const opencascade::handle<Prs3d_Drawer> & a2, const Standard_Boolean a3, const gp_Pnt2d & a4, const gp_Pnt2d & a5, const gp_Pnt2d & a6) -> void { return StdPrs_ShadedShape::Add(a0, a1, a2, a3, a4, a5, a6); });
cls_StdPrs_ShadedShape.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const TopoDS_Shape &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Boolean, const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &, const StdPrs_Volume)) &StdPrs_ShadedShape::Add, "Shades <theShape> with texture coordinates.", py::arg("thePresentation"), py::arg("theShape"), py::arg("theDrawer"), py::arg("theHasTexels"), py::arg("theUVOrigin"), py::arg("theUVRepeat"), py::arg("theUVScale"), py::arg("theVolume"));
cls_StdPrs_ShadedShape.def_static("ExploreSolids_", (void (*)(const TopoDS_Shape &, const BRep_Builder &, TopoDS_Compound &, TopoDS_Compound &, const Standard_Boolean)) &StdPrs_ShadedShape::ExploreSolids, "Searches closed and unclosed subshapes in shape structure and puts them into two compounds for separate processing of closed and unclosed sub-shapes", py::arg("theShape"), py::arg("theBuilder"), py::arg("theClosed"), py::arg("theOpened"), py::arg("theIgnore1DSubShape"));
cls_StdPrs_ShadedShape.def_static("AddWireframeForFreeElements_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const TopoDS_Shape &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_ShadedShape::AddWireframeForFreeElements, "Computes wireframe presentation for free wires and vertices", py::arg("thePrs"), py::arg("theShape"), py::arg("theDrawer"));
cls_StdPrs_ShadedShape.def_static("AddWireframeForFacesWithoutTriangles_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const TopoDS_Shape &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_ShadedShape::AddWireframeForFacesWithoutTriangles, "Computes special wireframe presentation for faces without triangulation.", py::arg("thePrs"), py::arg("theShape"), py::arg("theDrawer"));
cls_StdPrs_ShadedShape.def_static("FillTriangles_", (opencascade::handle<Graphic3d_ArrayOfTriangles> (*)(const TopoDS_Shape &)) &StdPrs_ShadedShape::FillTriangles, "Create primitive array with triangles for specified shape.", py::arg("theShape"));
cls_StdPrs_ShadedShape.def_static("FillTriangles_", (opencascade::handle<Graphic3d_ArrayOfTriangles> (*)(const TopoDS_Shape &, const Standard_Boolean, const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &)) &StdPrs_ShadedShape::FillTriangles, "Create primitive array of triangles for specified shape.", py::arg("theShape"), py::arg("theHasTexels"), py::arg("theUVOrigin"), py::arg("theUVRepeat"), py::arg("theUVScale"));
cls_StdPrs_ShadedShape.def_static("FillFaceBoundaries_", (opencascade::handle<Graphic3d_ArrayOfSegments> (*)(const TopoDS_Shape &)) &StdPrs_ShadedShape::FillFaceBoundaries, "Define primitive array of boundary segments for specified shape.", py::arg("theShape"));

// Enums

}