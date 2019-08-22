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
#include <BRepBuilderAPI_MakeShape.hxx>
#include <Standard.hxx>
#include <TopoDS_Edge.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Vertex.hxx>
#include <Standard_Handle.hxx>
#include <ChFiDS_SecHArray1.hxx>
#include <BRepFilletAPI_LocalOperation.hxx>

void bind_BRepFilletAPI_LocalOperation(py::module &mod){

py::class_<BRepFilletAPI_LocalOperation, BRepBuilderAPI_MakeShape> cls_BRepFilletAPI_LocalOperation(mod, "BRepFilletAPI_LocalOperation", "Construction of fillets on the edges of a Shell.");

// Fields

// Methods
// cls_BRepFilletAPI_LocalOperation.def_static("operator new_", (void * (*)(size_t)) &BRepFilletAPI_LocalOperation::operator new, "None", py::arg("theSize"));
// cls_BRepFilletAPI_LocalOperation.def_static("operator delete_", (void (*)(void *)) &BRepFilletAPI_LocalOperation::operator delete, "None", py::arg("theAddress"));
// cls_BRepFilletAPI_LocalOperation.def_static("operator new[]_", (void * (*)(size_t)) &BRepFilletAPI_LocalOperation::operator new[], "None", py::arg("theSize"));
// cls_BRepFilletAPI_LocalOperation.def_static("operator delete[]_", (void (*)(void *)) &BRepFilletAPI_LocalOperation::operator delete[], "None", py::arg("theAddress"));
// cls_BRepFilletAPI_LocalOperation.def_static("operator new_", (void * (*)(size_t, void *)) &BRepFilletAPI_LocalOperation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepFilletAPI_LocalOperation.def_static("operator delete_", (void (*)(void *, void *)) &BRepFilletAPI_LocalOperation::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepFilletAPI_LocalOperation.def("Add", (void (BRepFilletAPI_LocalOperation::*)(const TopoDS_Edge &)) &BRepFilletAPI_LocalOperation::Add, "Adds a contour in the builder (builds a contour of tangent edges).", py::arg("E"));
cls_BRepFilletAPI_LocalOperation.def("ResetContour", (void (BRepFilletAPI_LocalOperation::*)(const Standard_Integer)) &BRepFilletAPI_LocalOperation::ResetContour, "Reset the contour of index IC, there is nomore information in the contour.", py::arg("IC"));
cls_BRepFilletAPI_LocalOperation.def("NbContours", (Standard_Integer (BRepFilletAPI_LocalOperation::*)() const) &BRepFilletAPI_LocalOperation::NbContours, "Number of contours.");
cls_BRepFilletAPI_LocalOperation.def("Contour", (Standard_Integer (BRepFilletAPI_LocalOperation::*)(const TopoDS_Edge &) const) &BRepFilletAPI_LocalOperation::Contour, "Returns the index of the contour containing the edge E, returns 0 if E doesn't belong to any contour.", py::arg("E"));
cls_BRepFilletAPI_LocalOperation.def("NbEdges", (Standard_Integer (BRepFilletAPI_LocalOperation::*)(const Standard_Integer) const) &BRepFilletAPI_LocalOperation::NbEdges, "Number of Edges in the contour I.", py::arg("I"));
cls_BRepFilletAPI_LocalOperation.def("Edge", (const TopoDS_Edge & (BRepFilletAPI_LocalOperation::*)(const Standard_Integer, const Standard_Integer) const) &BRepFilletAPI_LocalOperation::Edge, "Returns the Edge J in the contour I.", py::arg("I"), py::arg("J"));
cls_BRepFilletAPI_LocalOperation.def("Remove", (void (BRepFilletAPI_LocalOperation::*)(const TopoDS_Edge &)) &BRepFilletAPI_LocalOperation::Remove, "remove the contour containing the Edge E.", py::arg("E"));
cls_BRepFilletAPI_LocalOperation.def("Length", (Standard_Real (BRepFilletAPI_LocalOperation::*)(const Standard_Integer) const) &BRepFilletAPI_LocalOperation::Length, "returns the length the contour of index IC.", py::arg("IC"));
cls_BRepFilletAPI_LocalOperation.def("FirstVertex", (TopoDS_Vertex (BRepFilletAPI_LocalOperation::*)(const Standard_Integer) const) &BRepFilletAPI_LocalOperation::FirstVertex, "Returns the first Vertex of the contour of index IC.", py::arg("IC"));
cls_BRepFilletAPI_LocalOperation.def("LastVertex", (TopoDS_Vertex (BRepFilletAPI_LocalOperation::*)(const Standard_Integer) const) &BRepFilletAPI_LocalOperation::LastVertex, "Returns the last Vertex of the contour of index IC.", py::arg("IC"));
cls_BRepFilletAPI_LocalOperation.def("Abscissa", (Standard_Real (BRepFilletAPI_LocalOperation::*)(const Standard_Integer, const TopoDS_Vertex &) const) &BRepFilletAPI_LocalOperation::Abscissa, "returns the abscissa of the vertex V on the contour of index IC.", py::arg("IC"), py::arg("V"));
cls_BRepFilletAPI_LocalOperation.def("RelativeAbscissa", (Standard_Real (BRepFilletAPI_LocalOperation::*)(const Standard_Integer, const TopoDS_Vertex &) const) &BRepFilletAPI_LocalOperation::RelativeAbscissa, "returns the relative abscissa([0.,1.]) of the vertex V on the contour of index IC.", py::arg("IC"), py::arg("V"));
cls_BRepFilletAPI_LocalOperation.def("ClosedAndTangent", (Standard_Boolean (BRepFilletAPI_LocalOperation::*)(const Standard_Integer) const) &BRepFilletAPI_LocalOperation::ClosedAndTangent, "returns true if the contour of index IC is closed an tangent.", py::arg("IC"));
cls_BRepFilletAPI_LocalOperation.def("Closed", (Standard_Boolean (BRepFilletAPI_LocalOperation::*)(const Standard_Integer) const) &BRepFilletAPI_LocalOperation::Closed, "returns true if the contour of index IC is closed", py::arg("IC"));
cls_BRepFilletAPI_LocalOperation.def("Reset", (void (BRepFilletAPI_LocalOperation::*)()) &BRepFilletAPI_LocalOperation::Reset, "Reset all the fields updated by Build operation and leave the algorithm in the same state than before build call. It allows contours and radius modifications to build the result another time.");
cls_BRepFilletAPI_LocalOperation.def("Simulate", (void (BRepFilletAPI_LocalOperation::*)(const Standard_Integer)) &BRepFilletAPI_LocalOperation::Simulate, "None", py::arg("IC"));
cls_BRepFilletAPI_LocalOperation.def("NbSurf", (Standard_Integer (BRepFilletAPI_LocalOperation::*)(const Standard_Integer) const) &BRepFilletAPI_LocalOperation::NbSurf, "None", py::arg("IC"));
cls_BRepFilletAPI_LocalOperation.def("Sect", (opencascade::handle<ChFiDS_SecHArray1> (BRepFilletAPI_LocalOperation::*)(const Standard_Integer, const Standard_Integer) const) &BRepFilletAPI_LocalOperation::Sect, "None", py::arg("IC"), py::arg("IS"));

// Enums

}