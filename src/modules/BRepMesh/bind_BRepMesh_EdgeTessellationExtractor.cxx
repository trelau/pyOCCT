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
#include <BRepMesh_IEdgeTool.hxx>
#include <TopoDS_Edge.hxx>
#include <Standard_Handle.hxx>
#include <Geom2dAdaptor_HCurve.hxx>
#include <TopoDS_Face.hxx>
#include <Poly_Triangulation.hxx>
#include <Poly_PolygonOnTriangulation.hxx>
#include <TopLoc_Location.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Pnt2d.hxx>
#include <BRepMesh_EdgeTessellationExtractor.hxx>
#include <Standard_Type.hxx>
#include <BRepMesh_EdgeParameterProvider.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColStd_Array1OfInteger.hxx>

void bind_BRepMesh_EdgeTessellationExtractor(py::module &mod){

py::class_<BRepMesh_EdgeTessellationExtractor, opencascade::handle<BRepMesh_EdgeTessellationExtractor>, BRepMesh_IEdgeTool> cls_BRepMesh_EdgeTessellationExtractor(mod, "BRepMesh_EdgeTessellationExtractor", "Auxiliary class implements functionality retrieving tessellated representation of an edge stored in polygon.");

// Constructors
// cls_BRepMesh_EdgeTessellationExtractor.def(py::init<const TopoDS_Edge &, const opencascade::handle<Geom2dAdaptor_HCurve> &, const TopoDS_Face &, const opencascade::handle<Poly_Triangulation> &, const opencascade::handle<Poly_PolygonOnTriangulation> &, const TopLoc_Location &>(), py::arg("theEdge"), py::arg("thePCurve"), py::arg("theFace"), py::arg("theTriangulation"), py::arg("thePolygon"), py::arg("theLocation"));

// Fields

// Methods
cls_BRepMesh_EdgeTessellationExtractor.def("NbPoints", (Standard_Integer (BRepMesh_EdgeTessellationExtractor::*)() const) &BRepMesh_EdgeTessellationExtractor::NbPoints, "Returns number of dicretization points.");
cls_BRepMesh_EdgeTessellationExtractor.def("Value", [](BRepMesh_EdgeTessellationExtractor &self, const Standard_Integer theIndex, Standard_Real & theParameter, gp_Pnt & thePoint, gp_Pnt2d & theUV){ Standard_Boolean rv = self.Value(theIndex, theParameter, thePoint, theUV); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theParameter); }, "Returns parameters of solution with the given index.", py::arg("theIndex"), py::arg("theParameter"), py::arg("thePoint"), py::arg("theUV"));
cls_BRepMesh_EdgeTessellationExtractor.def_static("get_type_name_", (const char * (*)()) &BRepMesh_EdgeTessellationExtractor::get_type_name, "None");
cls_BRepMesh_EdgeTessellationExtractor.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_EdgeTessellationExtractor::get_type_descriptor, "None");
cls_BRepMesh_EdgeTessellationExtractor.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_EdgeTessellationExtractor::*)() const) &BRepMesh_EdgeTessellationExtractor::DynamicType, "None");

// Enums

}