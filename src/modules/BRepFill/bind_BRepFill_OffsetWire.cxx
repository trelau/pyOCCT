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
#include <GeomAbs_JoinType.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepMAT2d_BisectingLocus.hxx>
#include <BRepMAT2d_LinkTopoBilo.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <BRepFill_IndexedDataMapOfOrientedShapeListOfShape.hxx>
#include <BRepFill_OffsetWire.hxx>
#include <BRepFill_DataMapOfOrientedShapeListOfShape.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <TColgp_SequenceOfPnt.hxx>
#include <Bisector_Bisec.hxx>
#include <BRepFill_TrimEdgeTool.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>

void bind_BRepFill_OffsetWire(py::module &mod){

py::class_<BRepFill_OffsetWire, std::unique_ptr<BRepFill_OffsetWire, Deleter<BRepFill_OffsetWire>>> cls_BRepFill_OffsetWire(mod, "BRepFill_OffsetWire", "Constructs a Offset Wire to a spine (wire or face). Offset direction will be to outer region in case of positive offset value and to inner region in case of negative offset value. Inner/Outer region for open wire is defined by the following rule: when we go along the wire (taking into account of edges orientation) then outer region will be on the right side, inner region will be on the left side. In case of closed wire, inner region will always be inside the wire (at that, edges orientation is not taken into account). The Wire or the Face must be planar and oriented correctly.");

// Constructors
cls_BRepFill_OffsetWire.def(py::init<>());
cls_BRepFill_OffsetWire.def(py::init<const TopoDS_Face &>(), py::arg("Spine"));
cls_BRepFill_OffsetWire.def(py::init<const TopoDS_Face &, const GeomAbs_JoinType>(), py::arg("Spine"), py::arg("Join"));
cls_BRepFill_OffsetWire.def(py::init<const TopoDS_Face &, const GeomAbs_JoinType, const Standard_Boolean>(), py::arg("Spine"), py::arg("Join"), py::arg("IsOpenResult"));

// Fields

// Methods
// cls_BRepFill_OffsetWire.def_static("operator new_", (void * (*)(size_t)) &BRepFill_OffsetWire::operator new, "None", py::arg("theSize"));
// cls_BRepFill_OffsetWire.def_static("operator delete_", (void (*)(void *)) &BRepFill_OffsetWire::operator delete, "None", py::arg("theAddress"));
// cls_BRepFill_OffsetWire.def_static("operator new[]_", (void * (*)(size_t)) &BRepFill_OffsetWire::operator new[], "None", py::arg("theSize"));
// cls_BRepFill_OffsetWire.def_static("operator delete[]_", (void (*)(void *)) &BRepFill_OffsetWire::operator delete[], "None", py::arg("theAddress"));
// cls_BRepFill_OffsetWire.def_static("operator new_", (void * (*)(size_t, void *)) &BRepFill_OffsetWire::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepFill_OffsetWire.def_static("operator delete_", (void (*)(void *, void *)) &BRepFill_OffsetWire::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepFill_OffsetWire.def("Init", [](BRepFill_OffsetWire &self, const TopoDS_Face & a0) -> void { return self.Init(a0); });
cls_BRepFill_OffsetWire.def("Init", [](BRepFill_OffsetWire &self, const TopoDS_Face & a0, const GeomAbs_JoinType a1) -> void { return self.Init(a0, a1); });
cls_BRepFill_OffsetWire.def("Init", (void (BRepFill_OffsetWire::*)(const TopoDS_Face &, const GeomAbs_JoinType, const Standard_Boolean)) &BRepFill_OffsetWire::Init, "Initialize the evaluation of Offseting.", py::arg("Spine"), py::arg("Join"), py::arg("IsOpenResult"));
cls_BRepFill_OffsetWire.def("Perform", [](BRepFill_OffsetWire &self, const Standard_Real a0) -> void { return self.Perform(a0); });
cls_BRepFill_OffsetWire.def("Perform", (void (BRepFill_OffsetWire::*)(const Standard_Real, const Standard_Real)) &BRepFill_OffsetWire::Perform, "Performs an OffsetWire at an altitude <Alt> from the face ( According to the orientation of the face)", py::arg("Offset"), py::arg("Alt"));
cls_BRepFill_OffsetWire.def("PerformWithBiLo", [](BRepFill_OffsetWire &self, const TopoDS_Face & a0, const Standard_Real a1, const BRepMAT2d_BisectingLocus & a2, BRepMAT2d_LinkTopoBilo & a3) -> void { return self.PerformWithBiLo(a0, a1, a2, a3); });
cls_BRepFill_OffsetWire.def("PerformWithBiLo", [](BRepFill_OffsetWire &self, const TopoDS_Face & a0, const Standard_Real a1, const BRepMAT2d_BisectingLocus & a2, BRepMAT2d_LinkTopoBilo & a3, const GeomAbs_JoinType a4) -> void { return self.PerformWithBiLo(a0, a1, a2, a3, a4); });
cls_BRepFill_OffsetWire.def("PerformWithBiLo", (void (BRepFill_OffsetWire::*)(const TopoDS_Face &, const Standard_Real, const BRepMAT2d_BisectingLocus &, BRepMAT2d_LinkTopoBilo &, const GeomAbs_JoinType, const Standard_Real)) &BRepFill_OffsetWire::PerformWithBiLo, "Performs an OffsetWire", py::arg("WSP"), py::arg("Offset"), py::arg("Locus"), py::arg("Link"), py::arg("Join"), py::arg("Alt"));
cls_BRepFill_OffsetWire.def("IsDone", (Standard_Boolean (BRepFill_OffsetWire::*)() const) &BRepFill_OffsetWire::IsDone, "None");
cls_BRepFill_OffsetWire.def("Spine", (const TopoDS_Face & (BRepFill_OffsetWire::*)() const) &BRepFill_OffsetWire::Spine, "None");
cls_BRepFill_OffsetWire.def("Shape", (const TopoDS_Shape & (BRepFill_OffsetWire::*)() const) &BRepFill_OffsetWire::Shape, "returns the generated shape.");
cls_BRepFill_OffsetWire.def("GeneratedShapes", (const TopTools_ListOfShape & (BRepFill_OffsetWire::*)(const TopoDS_Shape &)) &BRepFill_OffsetWire::GeneratedShapes, "Returns the shapes created from a subshape <SpineShape> of the spine. Returns the last computed Offset.", py::arg("SpineShape"));
cls_BRepFill_OffsetWire.def("JoinType", (GeomAbs_JoinType (BRepFill_OffsetWire::*)() const) &BRepFill_OffsetWire::JoinType, "None");

// Enums

}