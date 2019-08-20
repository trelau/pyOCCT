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
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Face.hxx>
#include <Bnd_Box.hxx>
#include <TopoDS_Edge.hxx>
#include <gp_XY.hxx>
#include <gp_Pnt2d.hxx>
#include <Standard_Handle.hxx>
#include <BRepMesh_FaceAttribute.hxx>
#include <Poly_Triangulation.hxx>
#include <TopLoc_Location.hxx>
#include <Poly_PolygonOnTriangulation.hxx>
#include <gp_Pnt.hxx>
#include <BRepMesh_ShapeTool.hxx>

void bind_BRepMesh_ShapeTool(py::module &mod){

py::class_<BRepMesh_ShapeTool, std::unique_ptr<BRepMesh_ShapeTool>> cls_BRepMesh_ShapeTool(mod, "BRepMesh_ShapeTool", "None");

// Constructors

// Fields

// Methods
// cls_BRepMesh_ShapeTool.def_static("operator new_", (void * (*)(size_t)) &BRepMesh_ShapeTool::operator new, "None", py::arg("theSize"));
// cls_BRepMesh_ShapeTool.def_static("operator delete_", (void (*)(void *)) &BRepMesh_ShapeTool::operator delete, "None", py::arg("theAddress"));
// cls_BRepMesh_ShapeTool.def_static("operator new[]_", (void * (*)(size_t)) &BRepMesh_ShapeTool::operator new[], "None", py::arg("theSize"));
// cls_BRepMesh_ShapeTool.def_static("operator delete[]_", (void (*)(void *)) &BRepMesh_ShapeTool::operator delete[], "None", py::arg("theAddress"));
// cls_BRepMesh_ShapeTool.def_static("operator new_", (void * (*)(size_t, void *)) &BRepMesh_ShapeTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepMesh_ShapeTool.def_static("operator delete_", (void (*)(void *, void *)) &BRepMesh_ShapeTool::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepMesh_ShapeTool.def_static("MaxFaceTolerance_", (Standard_Real (*)(const TopoDS_Face &)) &BRepMesh_ShapeTool::MaxFaceTolerance, "Returns maximum tolerance of the given face. Considers tolerances of edges and vertices contained in the given face.", py::arg("theFace"));
cls_BRepMesh_ShapeTool.def_static("BoxMaxDimension_", [](const Bnd_Box & theBox, Standard_Real & theMaxDimension){ BRepMesh_ShapeTool::BoxMaxDimension(theBox, theMaxDimension); return theMaxDimension; }, "Gets the maximum dimension of the given bounding box. If the given bounding box is void leaves the resulting value unchanged.", py::arg("theBox"), py::arg("theMaxDimension"));
cls_BRepMesh_ShapeTool.def_static("RelativeEdgeDeflection_", [](const TopoDS_Edge & theEdge, const Standard_Real theDeflection, const Standard_Real theMaxShapeSize, Standard_Real & theAdjustmentCoefficient){ Standard_Real rv = BRepMesh_ShapeTool::RelativeEdgeDeflection(theEdge, theDeflection, theMaxShapeSize, theAdjustmentCoefficient); return std::tuple<Standard_Real, Standard_Real &>(rv, theAdjustmentCoefficient); }, "Returns relative deflection for edge with respect to shape size.", py::arg("theEdge"), py::arg("theDeflection"), py::arg("theMaxShapeSize"), py::arg("theAdjustmentCoefficient"));
cls_BRepMesh_ShapeTool.def_static("FindUV_", (gp_XY (*)(const Standard_Integer, const gp_Pnt2d &, const Standard_Real, const opencascade::handle<BRepMesh_FaceAttribute> &)) &BRepMesh_ShapeTool::FindUV, "Checks 2d representations of 3d point with the given index for equality to avoid duplications.", py::arg("theIndexOfPnt3d"), py::arg("thePnt2d"), py::arg("theMinDistance"), py::arg("theFaceAttribute"));
cls_BRepMesh_ShapeTool.def_static("AddInFace_", (void (*)(const TopoDS_Face &, opencascade::handle<Poly_Triangulation> &)) &BRepMesh_ShapeTool::AddInFace, "Stores the given triangulation into the given face.", py::arg("theFace"), py::arg("theTriangulation"));
cls_BRepMesh_ShapeTool.def_static("NullifyFace_", (void (*)(const TopoDS_Face &)) &BRepMesh_ShapeTool::NullifyFace, "Nullifies triangulation stored in the face.", py::arg("theFace"));
cls_BRepMesh_ShapeTool.def_static("NullifyEdge_", (void (*)(const TopoDS_Edge &, const opencascade::handle<Poly_Triangulation> &, const TopLoc_Location &)) &BRepMesh_ShapeTool::NullifyEdge, "Nullifies polygon on triangulation stored in the edge.", py::arg("theEdge"), py::arg("theTriangulation"), py::arg("theLocation"));
cls_BRepMesh_ShapeTool.def_static("UpdateEdge_", (void (*)(const TopoDS_Edge &, const opencascade::handle<Poly_PolygonOnTriangulation> &, const opencascade::handle<Poly_Triangulation> &, const TopLoc_Location &)) &BRepMesh_ShapeTool::UpdateEdge, "Updates the given edge by the given tessellated representation.", py::arg("theEdge"), py::arg("thePolygon"), py::arg("theTriangulation"), py::arg("theLocation"));
cls_BRepMesh_ShapeTool.def_static("UpdateEdge_", (void (*)(const TopoDS_Edge &, const opencascade::handle<Poly_PolygonOnTriangulation> &, const opencascade::handle<Poly_PolygonOnTriangulation> &, const opencascade::handle<Poly_Triangulation> &, const TopLoc_Location &)) &BRepMesh_ShapeTool::UpdateEdge, "Updates the given seam edge by the given tessellated representations.", py::arg("theEdge"), py::arg("thePolygon1"), py::arg("thePolygon2"), py::arg("theTriangulation"), py::arg("theLocation"));
cls_BRepMesh_ShapeTool.def_static("UseLocation_", (gp_Pnt (*)(const gp_Pnt &, const TopLoc_Location &)) &BRepMesh_ShapeTool::UseLocation, "Applies location to the given point and return result.", py::arg("thePnt"), py::arg("theLoc"));
cls_BRepMesh_ShapeTool.def_static("IsDegenerated_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Face &)) &BRepMesh_ShapeTool::IsDegenerated, "Checks is the given edge degenerated. Checks geometrical parameters in case if IsDegenerated flag is not set.", py::arg("theEdge"), py::arg("theFace"));

// Enums

}