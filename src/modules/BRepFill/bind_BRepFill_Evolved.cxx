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
#include <gp_Ax3.hxx>
#include <GeomAbs_JoinType.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <BRepMAT2d_BisectingLocus.hxx>
#include <BRepMAT2d_LinkTopoBilo.hxx>
#include <BRepFill_DataMapOfShapeDataMapOfShapeListOfShape.hxx>
#include <BRepFill_Evolved.hxx>
#include <BRepTools_Quilt.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <TopLoc_Location.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Vertex.hxx>

void bind_BRepFill_Evolved(py::module &mod){

py::class_<BRepFill_Evolved, std::unique_ptr<BRepFill_Evolved, Deleter<BRepFill_Evolved>>> cls_BRepFill_Evolved(mod, "BRepFill_Evolved", "Constructs an evolved volume from a spine (wire or face) and a profile ( wire).");

// Constructors
cls_BRepFill_Evolved.def(py::init<>());
cls_BRepFill_Evolved.def(py::init<const TopoDS_Wire &, const TopoDS_Wire &, const gp_Ax3 &>(), py::arg("Spine"), py::arg("Profile"), py::arg("AxeProf"));
cls_BRepFill_Evolved.def(py::init<const TopoDS_Wire &, const TopoDS_Wire &, const gp_Ax3 &, const GeomAbs_JoinType>(), py::arg("Spine"), py::arg("Profile"), py::arg("AxeProf"), py::arg("Join"));
cls_BRepFill_Evolved.def(py::init<const TopoDS_Wire &, const TopoDS_Wire &, const gp_Ax3 &, const GeomAbs_JoinType, const Standard_Boolean>(), py::arg("Spine"), py::arg("Profile"), py::arg("AxeProf"), py::arg("Join"), py::arg("Solid"));
cls_BRepFill_Evolved.def(py::init<const TopoDS_Face &, const TopoDS_Wire &, const gp_Ax3 &>(), py::arg("Spine"), py::arg("Profile"), py::arg("AxeProf"));
cls_BRepFill_Evolved.def(py::init<const TopoDS_Face &, const TopoDS_Wire &, const gp_Ax3 &, const GeomAbs_JoinType>(), py::arg("Spine"), py::arg("Profile"), py::arg("AxeProf"), py::arg("Join"));
cls_BRepFill_Evolved.def(py::init<const TopoDS_Face &, const TopoDS_Wire &, const gp_Ax3 &, const GeomAbs_JoinType, const Standard_Boolean>(), py::arg("Spine"), py::arg("Profile"), py::arg("AxeProf"), py::arg("Join"), py::arg("Solid"));

// Fields

// Methods
// cls_BRepFill_Evolved.def_static("operator new_", (void * (*)(size_t)) &BRepFill_Evolved::operator new, "None", py::arg("theSize"));
// cls_BRepFill_Evolved.def_static("operator delete_", (void (*)(void *)) &BRepFill_Evolved::operator delete, "None", py::arg("theAddress"));
// cls_BRepFill_Evolved.def_static("operator new[]_", (void * (*)(size_t)) &BRepFill_Evolved::operator new[], "None", py::arg("theSize"));
// cls_BRepFill_Evolved.def_static("operator delete[]_", (void (*)(void *)) &BRepFill_Evolved::operator delete[], "None", py::arg("theAddress"));
// cls_BRepFill_Evolved.def_static("operator new_", (void * (*)(size_t, void *)) &BRepFill_Evolved::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepFill_Evolved.def_static("operator delete_", (void (*)(void *, void *)) &BRepFill_Evolved::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepFill_Evolved.def("Perform", [](BRepFill_Evolved &self, const TopoDS_Wire & a0, const TopoDS_Wire & a1, const gp_Ax3 & a2) -> void { return self.Perform(a0, a1, a2); });
cls_BRepFill_Evolved.def("Perform", [](BRepFill_Evolved &self, const TopoDS_Wire & a0, const TopoDS_Wire & a1, const gp_Ax3 & a2, const GeomAbs_JoinType a3) -> void { return self.Perform(a0, a1, a2, a3); });
cls_BRepFill_Evolved.def("Perform", (void (BRepFill_Evolved::*)(const TopoDS_Wire &, const TopoDS_Wire &, const gp_Ax3 &, const GeomAbs_JoinType, const Standard_Boolean)) &BRepFill_Evolved::Perform, "Performs an evolved shape by sweeping the <Profile> along the <Spine>", py::arg("Spine"), py::arg("Profile"), py::arg("AxeProf"), py::arg("Join"), py::arg("Solid"));
cls_BRepFill_Evolved.def("Perform", [](BRepFill_Evolved &self, const TopoDS_Face & a0, const TopoDS_Wire & a1, const gp_Ax3 & a2) -> void { return self.Perform(a0, a1, a2); });
cls_BRepFill_Evolved.def("Perform", [](BRepFill_Evolved &self, const TopoDS_Face & a0, const TopoDS_Wire & a1, const gp_Ax3 & a2, const GeomAbs_JoinType a3) -> void { return self.Perform(a0, a1, a2, a3); });
cls_BRepFill_Evolved.def("Perform", (void (BRepFill_Evolved::*)(const TopoDS_Face &, const TopoDS_Wire &, const gp_Ax3 &, const GeomAbs_JoinType, const Standard_Boolean)) &BRepFill_Evolved::Perform, "Performs an evolved shape by sweeping the <Profile> along the <Spine>", py::arg("Spine"), py::arg("Profile"), py::arg("AxeProf"), py::arg("Join"), py::arg("Solid"));
cls_BRepFill_Evolved.def("IsDone", (Standard_Boolean (BRepFill_Evolved::*)() const) &BRepFill_Evolved::IsDone, "None");
cls_BRepFill_Evolved.def("Shape", (const TopoDS_Shape & (BRepFill_Evolved::*)() const) &BRepFill_Evolved::Shape, "returns the generated shape.");
cls_BRepFill_Evolved.def("GeneratedShapes", (const TopTools_ListOfShape & (BRepFill_Evolved::*)(const TopoDS_Shape &, const TopoDS_Shape &) const) &BRepFill_Evolved::GeneratedShapes, "Returns the shapes created from a subshape <SpineShape> of the spine and a subshape <ProfShape> on the profile.", py::arg("SpineShape"), py::arg("ProfShape"));
cls_BRepFill_Evolved.def("JoinType", (GeomAbs_JoinType (BRepFill_Evolved::*)() const) &BRepFill_Evolved::JoinType, "None");
cls_BRepFill_Evolved.def("Top", (const TopoDS_Shape & (BRepFill_Evolved::*)() const) &BRepFill_Evolved::Top, "Return the face Top if <Solid> is True in the constructor.");
cls_BRepFill_Evolved.def("Bottom", (const TopoDS_Shape & (BRepFill_Evolved::*)() const) &BRepFill_Evolved::Bottom, "Return the face Bottom if <Solid> is True in the constructor.");

// Enums

}