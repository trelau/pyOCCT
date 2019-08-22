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
#include <TopoDS_Wire.hxx>
#include <GeomAbs_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <BRepAlgo_BooleanOperation.hxx>
#include <BRepAlgo_Fuse.hxx>
#include <BRepAlgo_Cut.hxx>
#include <BRepAlgo_Common.hxx>
#include <BRepAlgo_Section.hxx>
#include <BRepAlgo_Loop.hxx>
#include <BRepAlgo_Tool.hxx>
#include <BRepAlgo_Image.hxx>
#include <BRepAlgo_AsDes.hxx>
#include <BRepAlgo_FaceRestrictor.hxx>
#include <BRepAlgo_BooleanOperations.hxx>
#include <BRepAlgo_DSAccess.hxx>
#include <BRepAlgo_EdgeConnector.hxx>
#include <BRepAlgo_NormalProjection.hxx>
#include <BRepAlgo.hxx>

void bind_BRepAlgo(py::module &mod){

py::class_<BRepAlgo> cls_BRepAlgo(mod, "BRepAlgo", "The BRepAlgo package provides a full range of services to perform Old Boolean Operations in Open CASCADE. Attention: The New Boolean Operation has replaced the Old Boolean Operations algorithm in the BrepAlgoAPI package in Open CASCADE.");

// Constructors

// Fields

// Methods
// cls_BRepAlgo.def_static("operator new_", (void * (*)(size_t)) &BRepAlgo::operator new, "None", py::arg("theSize"));
// cls_BRepAlgo.def_static("operator delete_", (void (*)(void *)) &BRepAlgo::operator delete, "None", py::arg("theAddress"));
// cls_BRepAlgo.def_static("operator new[]_", (void * (*)(size_t)) &BRepAlgo::operator new[], "None", py::arg("theSize"));
// cls_BRepAlgo.def_static("operator delete[]_", (void (*)(void *)) &BRepAlgo::operator delete[], "None", py::arg("theAddress"));
// cls_BRepAlgo.def_static("operator new_", (void * (*)(size_t, void *)) &BRepAlgo::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepAlgo.def_static("operator delete_", (void (*)(void *, void *)) &BRepAlgo::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepAlgo.def_static("ConcatenateWire_", [](const TopoDS_Wire & a0, const GeomAbs_Shape a1) -> TopoDS_Wire { return BRepAlgo::ConcatenateWire(a0, a1); });
cls_BRepAlgo.def_static("ConcatenateWire_", (TopoDS_Wire (*)(const TopoDS_Wire &, const GeomAbs_Shape, const Standard_Real)) &BRepAlgo::ConcatenateWire, "this method makes a wire whose edges are C1 from a Wire whose edges could be G1. It removes a vertex between G1 edges. Option can be G1 or C1.", py::arg("Wire"), py::arg("Option"), py::arg("AngularTolerance"));
cls_BRepAlgo.def_static("ConcatenateWireC0_", (TopoDS_Edge (*)(const TopoDS_Wire &)) &BRepAlgo::ConcatenateWireC0, "this method makes an edge from a wire. Junction points between edges of wire may be sharp, resulting curve of the resulting edge may be C0.", py::arg("Wire"));
cls_BRepAlgo.def_static("IsValid_", (Standard_Boolean (*)(const TopoDS_Shape &)) &BRepAlgo::IsValid, "Checks if the shape is 'correct'. If not, returns <Standard_False>, else returns <Standard_True>.", py::arg("S"));
cls_BRepAlgo.def_static("IsValid_", [](const TopTools_ListOfShape & a0, const TopoDS_Shape & a1) -> Standard_Boolean { return BRepAlgo::IsValid(a0, a1); });
cls_BRepAlgo.def_static("IsValid_", [](const TopTools_ListOfShape & a0, const TopoDS_Shape & a1, const Standard_Boolean a2) -> Standard_Boolean { return BRepAlgo::IsValid(a0, a1, a2); });
cls_BRepAlgo.def_static("IsValid_", (Standard_Boolean (*)(const TopTools_ListOfShape &, const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean)) &BRepAlgo::IsValid, "Checks if the Generated and Modified Faces from the shapes <arguments> in the shape <result> are 'correct'. The args may be empty, then all faces will be checked. If <Closed> is True, only closed shape are valid. If <GeomCtrl> is False the geometry of new vertices and edges are not verified and the auto-intersection of new wires are not searched.", py::arg("theArgs"), py::arg("theResult"), py::arg("closedSolid"), py::arg("GeomCtrl"));
cls_BRepAlgo.def_static("IsTopologicallyValid_", (Standard_Boolean (*)(const TopoDS_Shape &)) &BRepAlgo::IsTopologicallyValid, "Checks if the shape is 'correct'. If not, returns <Standard_False>, else returns <Standard_True>. This method differs from the previous one in the fact that no geometric contols (intersection of wires, pcurve validity) are performed.", py::arg("S"));

// Enums

}