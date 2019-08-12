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
#include <BRepMesh_DiscretRoot.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepMesh_FastDiscret.hxx>
#include <Standard_Handle.hxx>
#include <BRepMesh_IncrementalMesh.hxx>
#include <Standard_Type.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <BRepMesh.hxx>
#include <TopTools_DataMapOfShapeReal.hxx>
#include <NCollection_Vector.hxx>

void bind_BRepMesh_IncrementalMesh(py::module &mod){

py::class_<BRepMesh_IncrementalMesh, opencascade::handle<BRepMesh_IncrementalMesh>, BRepMesh_DiscretRoot> cls_BRepMesh_IncrementalMesh(mod, "BRepMesh_IncrementalMesh", "Builds the mesh of a shape with respect of their correctly triangulated parts");

// Constructors
cls_BRepMesh_IncrementalMesh.def(py::init<>());
cls_BRepMesh_IncrementalMesh.def(py::init<const TopoDS_Shape &, const Standard_Real>(), py::arg("theShape"), py::arg("theLinDeflection"));
cls_BRepMesh_IncrementalMesh.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Boolean>(), py::arg("theShape"), py::arg("theLinDeflection"), py::arg("isRelative"));
cls_BRepMesh_IncrementalMesh.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Boolean, const Standard_Real>(), py::arg("theShape"), py::arg("theLinDeflection"), py::arg("isRelative"), py::arg("theAngDeflection"));
cls_BRepMesh_IncrementalMesh.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Boolean, const Standard_Real, const Standard_Boolean>(), py::arg("theShape"), py::arg("theLinDeflection"), py::arg("isRelative"), py::arg("theAngDeflection"), py::arg("isInParallel"));
cls_BRepMesh_IncrementalMesh.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Boolean, const Standard_Real, const Standard_Boolean, const Standard_Boolean>(), py::arg("theShape"), py::arg("theLinDeflection"), py::arg("isRelative"), py::arg("theAngDeflection"), py::arg("isInParallel"), py::arg("adaptiveMin"));
cls_BRepMesh_IncrementalMesh.def(py::init<const TopoDS_Shape &, const BRepMesh_FastDiscret::Parameters &>(), py::arg("theShape"), py::arg("theParameters"));

// Fields

// Methods
cls_BRepMesh_IncrementalMesh.def("Perform", (void (BRepMesh_IncrementalMesh::*)()) &BRepMesh_IncrementalMesh::Perform, "Performs meshing ot the shape.");
cls_BRepMesh_IncrementalMesh.def("Parameters", (const BRepMesh_FastDiscret::Parameters & (BRepMesh_IncrementalMesh::*)() const) &BRepMesh_IncrementalMesh::Parameters, "Returns meshing parameters");
cls_BRepMesh_IncrementalMesh.def("ChangeParameters", (BRepMesh_FastDiscret::Parameters & (BRepMesh_IncrementalMesh::*)()) &BRepMesh_IncrementalMesh::ChangeParameters, "Returns modifiable meshing parameters");
cls_BRepMesh_IncrementalMesh.def("IsModified", (Standard_Boolean (BRepMesh_IncrementalMesh::*)() const) &BRepMesh_IncrementalMesh::IsModified, "Returns modified flag.");
cls_BRepMesh_IncrementalMesh.def("GetStatusFlags", (Standard_Integer (BRepMesh_IncrementalMesh::*)() const) &BRepMesh_IncrementalMesh::GetStatusFlags, "Returns accumulated status flags faced during meshing.");
// cls_BRepMesh_IncrementalMesh.def_static("Discret_", (Standard_Integer (*)(const TopoDS_Shape &, const Standard_Real, const Standard_Real, BRepMesh_DiscretRoot *&)) &BRepMesh_IncrementalMesh::Discret, "Plugin interface for the Mesh Factories. Initializes meshing algorithm with the given parameters.", py::arg("theShape"), py::arg("theLinDeflection"), py::arg("theAngDeflection"), py::arg("theAlgo"));
cls_BRepMesh_IncrementalMesh.def_static("IsParallelDefault_", (Standard_Boolean (*)()) &BRepMesh_IncrementalMesh::IsParallelDefault, "Returns multi-threading usage flag set by default in Discret() static method (thus applied only to Mesh Factories).");
cls_BRepMesh_IncrementalMesh.def_static("SetParallelDefault_", (void (*)(const Standard_Boolean)) &BRepMesh_IncrementalMesh::SetParallelDefault, "Setup multi-threading usage flag set by default in Discret() static method (thus applied only to Mesh Factories).", py::arg("isInParallel"));
cls_BRepMesh_IncrementalMesh.def_static("get_type_name_", (const char * (*)()) &BRepMesh_IncrementalMesh::get_type_name, "None");
cls_BRepMesh_IncrementalMesh.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_IncrementalMesh::get_type_descriptor, "None");
cls_BRepMesh_IncrementalMesh.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_IncrementalMesh::*)() const) &BRepMesh_IncrementalMesh::DynamicType, "None");

// Enums

}