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
#include <TopoDS_Face.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_JoinType.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <TopoDS_Edge.hxx>
#include <GeomAbs_Shape.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepOffset_Status.hxx>
#include <BRepOffset_Offset.hxx>

void bind_BRepOffset_Offset(py::module &mod){

py::class_<BRepOffset_Offset, std::unique_ptr<BRepOffset_Offset, Deleter<BRepOffset_Offset>>> cls_BRepOffset_Offset(mod, "BRepOffset_Offset", "This class compute elemenary offset surface. Evaluate the offset generated : 1 - from a face. 2 - from an edge. 3 - from a vertex.");

// Constructors
cls_BRepOffset_Offset.def(py::init<>());
cls_BRepOffset_Offset.def(py::init<const TopoDS_Face &, const Standard_Real>(), py::arg("Face"), py::arg("Offset"));
cls_BRepOffset_Offset.def(py::init<const TopoDS_Face &, const Standard_Real, const Standard_Boolean>(), py::arg("Face"), py::arg("Offset"), py::arg("OffsetOutside"));
cls_BRepOffset_Offset.def(py::init<const TopoDS_Face &, const Standard_Real, const Standard_Boolean, const GeomAbs_JoinType>(), py::arg("Face"), py::arg("Offset"), py::arg("OffsetOutside"), py::arg("JoinType"));
cls_BRepOffset_Offset.def(py::init<const TopoDS_Face &, const Standard_Real, const TopTools_DataMapOfShapeShape &>(), py::arg("Face"), py::arg("Offset"), py::arg("Created"));
cls_BRepOffset_Offset.def(py::init<const TopoDS_Face &, const Standard_Real, const TopTools_DataMapOfShapeShape &, const Standard_Boolean>(), py::arg("Face"), py::arg("Offset"), py::arg("Created"), py::arg("OffsetOutside"));
cls_BRepOffset_Offset.def(py::init<const TopoDS_Face &, const Standard_Real, const TopTools_DataMapOfShapeShape &, const Standard_Boolean, const GeomAbs_JoinType>(), py::arg("Face"), py::arg("Offset"), py::arg("Created"), py::arg("OffsetOutside"), py::arg("JoinType"));
cls_BRepOffset_Offset.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Real>(), py::arg("Path"), py::arg("Edge1"), py::arg("Edge2"), py::arg("Offset"));
cls_BRepOffset_Offset.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Real, const Standard_Boolean>(), py::arg("Path"), py::arg("Edge1"), py::arg("Edge2"), py::arg("Offset"), py::arg("Polynomial"));
cls_BRepOffset_Offset.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Real, const Standard_Boolean, const Standard_Real>(), py::arg("Path"), py::arg("Edge1"), py::arg("Edge2"), py::arg("Offset"), py::arg("Polynomial"), py::arg("Tol"));
cls_BRepOffset_Offset.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Real, const Standard_Boolean, const Standard_Real, const GeomAbs_Shape>(), py::arg("Path"), py::arg("Edge1"), py::arg("Edge2"), py::arg("Offset"), py::arg("Polynomial"), py::arg("Tol"), py::arg("Conti"));
cls_BRepOffset_Offset.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Real, const TopoDS_Edge &, const TopoDS_Edge &>(), py::arg("Path"), py::arg("Edge1"), py::arg("Edge2"), py::arg("Offset"), py::arg("FirstEdge"), py::arg("LastEdge"));
cls_BRepOffset_Offset.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Real, const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Boolean>(), py::arg("Path"), py::arg("Edge1"), py::arg("Edge2"), py::arg("Offset"), py::arg("FirstEdge"), py::arg("LastEdge"), py::arg("Polynomial"));
cls_BRepOffset_Offset.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Real, const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Boolean, const Standard_Real>(), py::arg("Path"), py::arg("Edge1"), py::arg("Edge2"), py::arg("Offset"), py::arg("FirstEdge"), py::arg("LastEdge"), py::arg("Polynomial"), py::arg("Tol"));
cls_BRepOffset_Offset.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Real, const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Boolean, const Standard_Real, const GeomAbs_Shape>(), py::arg("Path"), py::arg("Edge1"), py::arg("Edge2"), py::arg("Offset"), py::arg("FirstEdge"), py::arg("LastEdge"), py::arg("Polynomial"), py::arg("Tol"), py::arg("Conti"));
cls_BRepOffset_Offset.def(py::init<const TopoDS_Vertex &, const TopTools_ListOfShape &, const Standard_Real>(), py::arg("Vertex"), py::arg("LEdge"), py::arg("Offset"));
cls_BRepOffset_Offset.def(py::init<const TopoDS_Vertex &, const TopTools_ListOfShape &, const Standard_Real, const Standard_Boolean>(), py::arg("Vertex"), py::arg("LEdge"), py::arg("Offset"), py::arg("Polynomial"));
cls_BRepOffset_Offset.def(py::init<const TopoDS_Vertex &, const TopTools_ListOfShape &, const Standard_Real, const Standard_Boolean, const Standard_Real>(), py::arg("Vertex"), py::arg("LEdge"), py::arg("Offset"), py::arg("Polynomial"), py::arg("Tol"));
cls_BRepOffset_Offset.def(py::init<const TopoDS_Vertex &, const TopTools_ListOfShape &, const Standard_Real, const Standard_Boolean, const Standard_Real, const GeomAbs_Shape>(), py::arg("Vertex"), py::arg("LEdge"), py::arg("Offset"), py::arg("Polynomial"), py::arg("Tol"), py::arg("Conti"));

// Fields

// Methods
// cls_BRepOffset_Offset.def_static("operator new_", (void * (*)(size_t)) &BRepOffset_Offset::operator new, "None", py::arg("theSize"));
// cls_BRepOffset_Offset.def_static("operator delete_", (void (*)(void *)) &BRepOffset_Offset::operator delete, "None", py::arg("theAddress"));
// cls_BRepOffset_Offset.def_static("operator new[]_", (void * (*)(size_t)) &BRepOffset_Offset::operator new[], "None", py::arg("theSize"));
// cls_BRepOffset_Offset.def_static("operator delete[]_", (void (*)(void *)) &BRepOffset_Offset::operator delete[], "None", py::arg("theAddress"));
// cls_BRepOffset_Offset.def_static("operator new_", (void * (*)(size_t, void *)) &BRepOffset_Offset::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepOffset_Offset.def_static("operator delete_", (void (*)(void *, void *)) &BRepOffset_Offset::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepOffset_Offset.def("Init", [](BRepOffset_Offset &self, const TopoDS_Face & a0, const Standard_Real a1) -> void { return self.Init(a0, a1); });
cls_BRepOffset_Offset.def("Init", [](BRepOffset_Offset &self, const TopoDS_Face & a0, const Standard_Real a1, const Standard_Boolean a2) -> void { return self.Init(a0, a1, a2); });
cls_BRepOffset_Offset.def("Init", (void (BRepOffset_Offset::*)(const TopoDS_Face &, const Standard_Real, const Standard_Boolean, const GeomAbs_JoinType)) &BRepOffset_Offset::Init, "None", py::arg("Face"), py::arg("Offset"), py::arg("OffsetOutside"), py::arg("JoinType"));
cls_BRepOffset_Offset.def("Init", [](BRepOffset_Offset &self, const TopoDS_Face & a0, const Standard_Real a1, const TopTools_DataMapOfShapeShape & a2) -> void { return self.Init(a0, a1, a2); });
cls_BRepOffset_Offset.def("Init", [](BRepOffset_Offset &self, const TopoDS_Face & a0, const Standard_Real a1, const TopTools_DataMapOfShapeShape & a2, const Standard_Boolean a3) -> void { return self.Init(a0, a1, a2, a3); });
cls_BRepOffset_Offset.def("Init", (void (BRepOffset_Offset::*)(const TopoDS_Face &, const Standard_Real, const TopTools_DataMapOfShapeShape &, const Standard_Boolean, const GeomAbs_JoinType)) &BRepOffset_Offset::Init, "None", py::arg("Face"), py::arg("Offset"), py::arg("Created"), py::arg("OffsetOutside"), py::arg("JoinType"));
cls_BRepOffset_Offset.def("Init", [](BRepOffset_Offset &self, const TopoDS_Edge & a0, const TopoDS_Edge & a1, const TopoDS_Edge & a2, const Standard_Real a3) -> void { return self.Init(a0, a1, a2, a3); });
cls_BRepOffset_Offset.def("Init", [](BRepOffset_Offset &self, const TopoDS_Edge & a0, const TopoDS_Edge & a1, const TopoDS_Edge & a2, const Standard_Real a3, const Standard_Boolean a4) -> void { return self.Init(a0, a1, a2, a3, a4); });
cls_BRepOffset_Offset.def("Init", [](BRepOffset_Offset &self, const TopoDS_Edge & a0, const TopoDS_Edge & a1, const TopoDS_Edge & a2, const Standard_Real a3, const Standard_Boolean a4, const Standard_Real a5) -> void { return self.Init(a0, a1, a2, a3, a4, a5); });
cls_BRepOffset_Offset.def("Init", (void (BRepOffset_Offset::*)(const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Real, const Standard_Boolean, const Standard_Real, const GeomAbs_Shape)) &BRepOffset_Offset::Init, "None", py::arg("Path"), py::arg("Edge1"), py::arg("Edge2"), py::arg("Offset"), py::arg("Polynomial"), py::arg("Tol"), py::arg("Conti"));
cls_BRepOffset_Offset.def("Init", [](BRepOffset_Offset &self, const TopoDS_Edge & a0, const TopoDS_Edge & a1, const TopoDS_Edge & a2, const Standard_Real a3, const TopoDS_Edge & a4, const TopoDS_Edge & a5) -> void { return self.Init(a0, a1, a2, a3, a4, a5); });
cls_BRepOffset_Offset.def("Init", [](BRepOffset_Offset &self, const TopoDS_Edge & a0, const TopoDS_Edge & a1, const TopoDS_Edge & a2, const Standard_Real a3, const TopoDS_Edge & a4, const TopoDS_Edge & a5, const Standard_Boolean a6) -> void { return self.Init(a0, a1, a2, a3, a4, a5, a6); });
cls_BRepOffset_Offset.def("Init", [](BRepOffset_Offset &self, const TopoDS_Edge & a0, const TopoDS_Edge & a1, const TopoDS_Edge & a2, const Standard_Real a3, const TopoDS_Edge & a4, const TopoDS_Edge & a5, const Standard_Boolean a6, const Standard_Real a7) -> void { return self.Init(a0, a1, a2, a3, a4, a5, a6, a7); });
cls_BRepOffset_Offset.def("Init", (void (BRepOffset_Offset::*)(const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Real, const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Boolean, const Standard_Real, const GeomAbs_Shape)) &BRepOffset_Offset::Init, "None", py::arg("Path"), py::arg("Edge1"), py::arg("Edge2"), py::arg("Offset"), py::arg("FirstEdge"), py::arg("LastEdge"), py::arg("Polynomial"), py::arg("Tol"), py::arg("Conti"));
cls_BRepOffset_Offset.def("Init", [](BRepOffset_Offset &self, const TopoDS_Vertex & a0, const TopTools_ListOfShape & a1, const Standard_Real a2) -> void { return self.Init(a0, a1, a2); });
cls_BRepOffset_Offset.def("Init", [](BRepOffset_Offset &self, const TopoDS_Vertex & a0, const TopTools_ListOfShape & a1, const Standard_Real a2, const Standard_Boolean a3) -> void { return self.Init(a0, a1, a2, a3); });
cls_BRepOffset_Offset.def("Init", [](BRepOffset_Offset &self, const TopoDS_Vertex & a0, const TopTools_ListOfShape & a1, const Standard_Real a2, const Standard_Boolean a3, const Standard_Real a4) -> void { return self.Init(a0, a1, a2, a3, a4); });
cls_BRepOffset_Offset.def("Init", (void (BRepOffset_Offset::*)(const TopoDS_Vertex &, const TopTools_ListOfShape &, const Standard_Real, const Standard_Boolean, const Standard_Real, const GeomAbs_Shape)) &BRepOffset_Offset::Init, "Tol and Conti are only used if Polynomial is True (Used to perfrom the approximation)", py::arg("Vertex"), py::arg("LEdge"), py::arg("Offset"), py::arg("Polynomial"), py::arg("Tol"), py::arg("Conti"));
cls_BRepOffset_Offset.def("Init", (void (BRepOffset_Offset::*)(const TopoDS_Edge &, const Standard_Real)) &BRepOffset_Offset::Init, "Only used in Rolling Ball. Pipe on Free Boundary", py::arg("Edge"), py::arg("Offset"));
cls_BRepOffset_Offset.def("InitialShape", (const TopoDS_Shape & (BRepOffset_Offset::*)() const) &BRepOffset_Offset::InitialShape, "None");
cls_BRepOffset_Offset.def("Face", (const TopoDS_Face & (BRepOffset_Offset::*)() const) &BRepOffset_Offset::Face, "None");
cls_BRepOffset_Offset.def("Generated", (TopoDS_Shape (BRepOffset_Offset::*)(const TopoDS_Shape &) const) &BRepOffset_Offset::Generated, "None", py::arg("Shape"));
cls_BRepOffset_Offset.def("Status", (BRepOffset_Status (BRepOffset_Offset::*)() const) &BRepOffset_Offset::Status, "None");

// Enums

}