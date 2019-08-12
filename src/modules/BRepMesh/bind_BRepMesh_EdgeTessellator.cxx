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
#include <BRepMesh_FaceAttribute.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Pnt2d.hxx>
#include <BRepMesh_EdgeTessellator.hxx>
#include <Standard_Type.hxx>
#include <Adaptor3d_Surface.hxx>
#include <Geom2dAdaptor_Curve.hxx>
#include <NCollection_Handle.hxx>
#include <BRepMesh_GeomTool.hxx>
#include <BRepAdaptor_HSurface.hxx>
#include <BRepAdaptor_Curve.hxx>

void bind_BRepMesh_EdgeTessellator(py::module &mod){

py::class_<BRepMesh_EdgeTessellator, opencascade::handle<BRepMesh_EdgeTessellator>, BRepMesh_IEdgeTool> cls_BRepMesh_EdgeTessellator(mod, "BRepMesh_EdgeTessellator", "Auxiliary class implements functionality producing tessellated representation of an edge based on edge geometry.");

// Constructors
// cls_BRepMesh_EdgeTessellator.def(py::init<const TopoDS_Edge &, const opencascade::handle<BRepMesh_FaceAttribute> &, const TopTools_IndexedDataMapOfShapeListOfShape &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theEdge"), py::arg("theFaceAttribute"), py::arg("theMapOfSharedFaces"), py::arg("theLinDeflection"), py::arg("theAngDeflection"), py::arg("theMinSize"));

// Fields

// Methods
cls_BRepMesh_EdgeTessellator.def("NbPoints", (Standard_Integer (BRepMesh_EdgeTessellator::*)() const) &BRepMesh_EdgeTessellator::NbPoints, "Returns number of dicretization points.");
cls_BRepMesh_EdgeTessellator.def("Value", [](BRepMesh_EdgeTessellator &self, const Standard_Integer theIndex, Standard_Real & theParameter, gp_Pnt & thePoint, gp_Pnt2d & theUV){ Standard_Boolean rv = self.Value(theIndex, theParameter, thePoint, theUV); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theParameter); }, "Returns parameters of solution with the given index.", py::arg("theIndex"), py::arg("theParameter"), py::arg("thePoint"), py::arg("theUV"));
cls_BRepMesh_EdgeTessellator.def_static("get_type_name_", (const char * (*)()) &BRepMesh_EdgeTessellator::get_type_name, "None");
cls_BRepMesh_EdgeTessellator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_EdgeTessellator::get_type_descriptor, "None");
cls_BRepMesh_EdgeTessellator.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_EdgeTessellator::*)() const) &BRepMesh_EdgeTessellator::DynamicType, "None");

// Enums

}