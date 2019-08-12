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
#include <Precision.hxx>
#include <Standard_TypeDef.hxx>
#include <Bnd_Box.hxx>
#include <BRepMesh_FastDiscret.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Face.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <Standard_Handle.hxx>
#include <BRepMesh_FaceAttribute.hxx>
#include <Standard_Type.hxx>
#include <TopoDS_Vertex.hxx>
#include <gp_Pnt.hxx>
#include <BRep_Tool.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TopLoc_Location.hxx>
#include <BRepMesh_ShapeTool.hxx>
#include <gp_Pnt2d.hxx>
#include <NCollection_Handle.hxx>
#include <TopoDS_Edge.hxx>
#include <Geom2dAdaptor_HCurve.hxx>
#include <Poly_PolygonOnTriangulation.hxx>
#include <BRepMesh.hxx>
#include <TopTools_DataMapOfShapeReal.hxx>

void bind_BRepMesh_FastDiscret(py::module &mod){

py::class_<BRepMesh_FastDiscret, opencascade::handle<BRepMesh_FastDiscret>, Standard_Transient> cls_BRepMesh_FastDiscret(mod, "BRepMesh_FastDiscret", "Algorithm to mesh a shape with respect of the frontier the deflection and by option the shared components.");

// Constructors
cls_BRepMesh_FastDiscret.def(py::init<const Bnd_Box &, const BRepMesh_FastDiscret::Parameters &>(), py::arg("B"), py::arg("theParams"));

// Fields

// Methods
cls_BRepMesh_FastDiscret.def("Perform", (void (BRepMesh_FastDiscret::*)(const TopoDS_Shape &)) &BRepMesh_FastDiscret::Perform, "Build triangulation on the whole shape.", py::arg("shape"));
cls_BRepMesh_FastDiscret.def("Add", (Standard_Integer (BRepMesh_FastDiscret::*)(const TopoDS_Face &)) &BRepMesh_FastDiscret::Add, "Record a face for further processing.", py::arg("face"));
cls_BRepMesh_FastDiscret.def("Process", (void (BRepMesh_FastDiscret::*)(const TopoDS_Face &) const) &BRepMesh_FastDiscret::Process, "Triangulate a face previously recorded for processing by call to Add(). Can be executed in parallel threads.", py::arg("face"));
cls_BRepMesh_FastDiscret.def("__call__", (void (BRepMesh_FastDiscret::*)(const TopoDS_Face &) const) &BRepMesh_FastDiscret::operator(), py::is_operator(), "None", py::arg("face"));
cls_BRepMesh_FastDiscret.def("MeshParameters", (const BRepMesh_FastDiscret::Parameters & (BRepMesh_FastDiscret::*)() const) &BRepMesh_FastDiscret::MeshParameters, "Returns parameters of meshing");
cls_BRepMesh_FastDiscret.def("ChangeMeshParameters", (BRepMesh_FastDiscret::Parameters & (BRepMesh_FastDiscret::*)()) &BRepMesh_FastDiscret::ChangeMeshParameters, "Returns modificable mesh parameters");
cls_BRepMesh_FastDiscret.def("InitSharedFaces", (void (BRepMesh_FastDiscret::*)(const TopoDS_Shape &)) &BRepMesh_FastDiscret::InitSharedFaces, "None", py::arg("theShape"));
cls_BRepMesh_FastDiscret.def("SharedFaces", (const TopTools_IndexedDataMapOfShapeListOfShape & (BRepMesh_FastDiscret::*)() const) &BRepMesh_FastDiscret::SharedFaces, "None");
cls_BRepMesh_FastDiscret.def("GetFaceAttribute", [](BRepMesh_FastDiscret &self, const TopoDS_Face & a0, opencascade::handle<BRepMesh_FaceAttribute> & a1) -> Standard_Boolean { return self.GetFaceAttribute(a0, a1); });
cls_BRepMesh_FastDiscret.def("GetFaceAttribute", (Standard_Boolean (BRepMesh_FastDiscret::*)(const TopoDS_Face &, opencascade::handle<BRepMesh_FaceAttribute> &, const Standard_Boolean) const) &BRepMesh_FastDiscret::GetFaceAttribute, "Returns attribute descriptor for the given face.", py::arg("theFace"), py::arg("theAttribute"), py::arg("isForceCreate"));
cls_BRepMesh_FastDiscret.def("RemoveFaceAttribute", (void (BRepMesh_FastDiscret::*)(const TopoDS_Face &)) &BRepMesh_FastDiscret::RemoveFaceAttribute, "Remove face attribute as useless to free locate memory.", py::arg("theFace"));
cls_BRepMesh_FastDiscret.def("NbBoundaryPoints", (Standard_Integer (BRepMesh_FastDiscret::*)() const) &BRepMesh_FastDiscret::NbBoundaryPoints, "Returns number of boundary 3d points.");
cls_BRepMesh_FastDiscret.def_static("get_type_name_", (const char * (*)()) &BRepMesh_FastDiscret::get_type_name, "None");
cls_BRepMesh_FastDiscret.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_FastDiscret::get_type_descriptor, "None");
cls_BRepMesh_FastDiscret.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_FastDiscret::*)() const) &BRepMesh_FastDiscret::DynamicType, "None");

// Enums

}