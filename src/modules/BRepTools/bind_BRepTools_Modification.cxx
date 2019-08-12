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
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Face.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <TopLoc_Location.hxx>
#include <Poly_Triangulation.hxx>
#include <TopoDS_Edge.hxx>
#include <Geom_Curve.hxx>
#include <Poly_Polygon3D.hxx>
#include <Poly_PolygonOnTriangulation.hxx>
#include <TopoDS_Vertex.hxx>
#include <gp_Pnt.hxx>
#include <Geom2d_Curve.hxx>
#include <GeomAbs_Shape.hxx>
#include <BRepTools_Modification.hxx>
#include <Standard_Type.hxx>

void bind_BRepTools_Modification(py::module &mod){

py::class_<BRepTools_Modification, opencascade::handle<BRepTools_Modification>, Standard_Transient> cls_BRepTools_Modification(mod, "BRepTools_Modification", "Defines geometric modifications to a shape, i.e. changes to faces, edges and vertices.");

// Fields

// Methods
cls_BRepTools_Modification.def("NewSurface", [](BRepTools_Modification &self, const TopoDS_Face & F, opencascade::handle<Geom_Surface> & S, TopLoc_Location & L, Standard_Real & Tol, Standard_Boolean & RevWires, Standard_Boolean & RevFace){ Standard_Boolean rv = self.NewSurface(F, S, L, Tol, RevWires, RevFace); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Boolean &, Standard_Boolean &>(rv, Tol, RevWires, RevFace); }, "Returns true if the face, F, has been modified. If the face has been modified: - S is the new geometry of the face, - L is its new location, and - Tol is the new tolerance. The flag, RevWires, is set to true when the modification reverses the normal of the surface, (i.e. the wires have to be reversed). The flag, RevFace, is set to true if the orientation of the modified face changes in the shells which contain it. If the face has not been modified this function returns false, and the values of S, L, Tol, RevWires and RevFace are not significant.", py::arg("F"), py::arg("S"), py::arg("L"), py::arg("Tol"), py::arg("RevWires"), py::arg("RevFace"));
cls_BRepTools_Modification.def("NewTriangulation", (Standard_Boolean (BRepTools_Modification::*)(const TopoDS_Face &, opencascade::handle<Poly_Triangulation> &)) &BRepTools_Modification::NewTriangulation, "Returns true if the face has been modified according to changed triangulation. If the face has been modified: - T is a new triangulation on the face", py::arg("F"), py::arg("T"));
cls_BRepTools_Modification.def("NewCurve", [](BRepTools_Modification &self, const TopoDS_Edge & E, opencascade::handle<Geom_Curve> & C, TopLoc_Location & L, Standard_Real & Tol){ Standard_Boolean rv = self.NewCurve(E, C, L, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Returns true if the edge, E, has been modified. If the edge has been modified: - C is the new geometry associated with the edge, - L is its new location, and - Tol is the new tolerance. If the edge has not been modified, this function returns false, and the values of C, L and Tol are not significant.", py::arg("E"), py::arg("C"), py::arg("L"), py::arg("Tol"));
cls_BRepTools_Modification.def("NewPolygon", (Standard_Boolean (BRepTools_Modification::*)(const TopoDS_Edge &, opencascade::handle<Poly_Polygon3D> &)) &BRepTools_Modification::NewPolygon, "Returns true if the edge has been modified according to changed polygon. If the edge has been modified: - P is a new polygon", py::arg("E"), py::arg("P"));
cls_BRepTools_Modification.def("NewPolygonOnTriangulation", (Standard_Boolean (BRepTools_Modification::*)(const TopoDS_Edge &, const TopoDS_Face &, opencascade::handle<Poly_PolygonOnTriangulation> &)) &BRepTools_Modification::NewPolygonOnTriangulation, "Returns true if the edge has been modified according to changed polygon on triangulation. If the edge has been modified: - P is a new polygon on triangulation", py::arg("E"), py::arg("F"), py::arg("P"));
cls_BRepTools_Modification.def("NewPoint", [](BRepTools_Modification &self, const TopoDS_Vertex & V, gp_Pnt & P, Standard_Real & Tol){ Standard_Boolean rv = self.NewPoint(V, P, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Returns true if the vertex V has been modified. If V has been modified: - P is the new geometry of the vertex, and - Tol is the new tolerance. If the vertex has not been modified this function returns false, and the values of P and Tol are not significant.", py::arg("V"), py::arg("P"), py::arg("Tol"));
cls_BRepTools_Modification.def("NewCurve2d", [](BRepTools_Modification &self, const TopoDS_Edge & E, const TopoDS_Face & F, const TopoDS_Edge & NewE, const TopoDS_Face & NewF, opencascade::handle<Geom2d_Curve> & C, Standard_Real & Tol){ Standard_Boolean rv = self.NewCurve2d(E, F, NewE, NewF, C, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Returns true if the edge, E, has a new curve on surface on the face, F. If a new curve exists: - C is the new geometry of the edge, - L is the new location, and - Tol is the new tolerance. NewE is the new edge created from E, and NewF is the new face created from F. If there is no new curve on the face, this function returns false, and the values of C, L and Tol are not significant.", py::arg("E"), py::arg("F"), py::arg("NewE"), py::arg("NewF"), py::arg("C"), py::arg("Tol"));
cls_BRepTools_Modification.def("NewParameter", [](BRepTools_Modification &self, const TopoDS_Vertex & V, const TopoDS_Edge & E, Standard_Real & P, Standard_Real & Tol){ Standard_Boolean rv = self.NewParameter(V, E, P, Tol); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, P, Tol); }, "Returns true if the vertex V has a new parameter on the edge E. If a new parameter exists: - P is the parameter, and - Tol is the new tolerance. If there is no new parameter this function returns false, and the values of P and Tol are not significant.", py::arg("V"), py::arg("E"), py::arg("P"), py::arg("Tol"));
cls_BRepTools_Modification.def("Continuity", (GeomAbs_Shape (BRepTools_Modification::*)(const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &, const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &)) &BRepTools_Modification::Continuity, "Returns the continuity of <NewE> between <NewF1> and <NewF2>. <NewE> is the new edge created from <E>. <NewF1> (resp. <NewF2>) is the new face created from <F1> (resp. <F2>).", py::arg("E"), py::arg("F1"), py::arg("F2"), py::arg("NewE"), py::arg("NewF1"), py::arg("NewF2"));
cls_BRepTools_Modification.def_static("get_type_name_", (const char * (*)()) &BRepTools_Modification::get_type_name, "None");
cls_BRepTools_Modification.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepTools_Modification::get_type_descriptor, "None");
cls_BRepTools_Modification.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepTools_Modification::*)() const) &BRepTools_Modification::DynamicType, "None");

// Enums

}