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
#include <Standard_Handle.hxx>
#include <BRepFill_SectionLaw.hxx>
#include <BRepFill_LocationLaw.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Wire.hxx>
#include <TopTools_MapOfShape.hxx>
#include <BRepFill_DataMapOfShapeHArray2OfShape.hxx>
#include <BRepFill_TransitionStyle.hxx>
#include <GeomAbs_Shape.hxx>
#include <GeomFill_ApproxStyle.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_HArray2OfShape.hxx>
#include <TopoDS_Edge.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopTools_HArray1OfShape.hxx>
#include <BRepFill_Sweep.hxx>

void bind_BRepFill_Sweep(py::module &mod){

py::class_<BRepFill_Sweep> cls_BRepFill_Sweep(mod, "BRepFill_Sweep", "Topological Sweep Algorithm Computes an Sweep shell using a generating wire, an SectionLaw and an LocationLaw.");

// Constructors
cls_BRepFill_Sweep.def(py::init<const opencascade::handle<BRepFill_SectionLaw> &, const opencascade::handle<BRepFill_LocationLaw> &, const Standard_Boolean>(), py::arg("Section"), py::arg("Location"), py::arg("WithKPart"));

// Fields

// Methods
// cls_BRepFill_Sweep.def_static("operator new_", (void * (*)(size_t)) &BRepFill_Sweep::operator new, "None", py::arg("theSize"));
// cls_BRepFill_Sweep.def_static("operator delete_", (void (*)(void *)) &BRepFill_Sweep::operator delete, "None", py::arg("theAddress"));
// cls_BRepFill_Sweep.def_static("operator new[]_", (void * (*)(size_t)) &BRepFill_Sweep::operator new[], "None", py::arg("theSize"));
// cls_BRepFill_Sweep.def_static("operator delete[]_", (void (*)(void *)) &BRepFill_Sweep::operator delete[], "None", py::arg("theAddress"));
// cls_BRepFill_Sweep.def_static("operator new_", (void * (*)(size_t, void *)) &BRepFill_Sweep::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepFill_Sweep.def_static("operator delete_", (void (*)(void *, void *)) &BRepFill_Sweep::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepFill_Sweep.def("SetBounds", (void (BRepFill_Sweep::*)(const TopoDS_Wire &, const TopoDS_Wire &)) &BRepFill_Sweep::SetBounds, "None", py::arg("FirstShape"), py::arg("LastShape"));
cls_BRepFill_Sweep.def("SetTolerance", [](BRepFill_Sweep &self, const Standard_Real a0) -> void { return self.SetTolerance(a0); });
cls_BRepFill_Sweep.def("SetTolerance", [](BRepFill_Sweep &self, const Standard_Real a0, const Standard_Real a1) -> void { return self.SetTolerance(a0, a1); });
cls_BRepFill_Sweep.def("SetTolerance", [](BRepFill_Sweep &self, const Standard_Real a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.SetTolerance(a0, a1, a2); });
cls_BRepFill_Sweep.def("SetTolerance", (void (BRepFill_Sweep::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &BRepFill_Sweep::SetTolerance, "Set Approximation Tolerance Tol3d : Tolerance to surface approximation Tol2d : Tolerance used to perform curve approximation Normaly the 2d curve are approximated with a tolerance given by the resolution on support surfaces, but if this tolerance is too large Tol2d is used. TolAngular : Tolerance (in radian) to control the angle beetween tangents on the section law and tangent of iso-v on approximed surface", py::arg("Tol3d"), py::arg("BoundTol"), py::arg("Tol2d"), py::arg("TolAngular"));
cls_BRepFill_Sweep.def("SetAngularControl", [](BRepFill_Sweep &self) -> void { return self.SetAngularControl(); });
cls_BRepFill_Sweep.def("SetAngularControl", [](BRepFill_Sweep &self, const Standard_Real a0) -> void { return self.SetAngularControl(a0); });
cls_BRepFill_Sweep.def("SetAngularControl", (void (BRepFill_Sweep::*)(const Standard_Real, const Standard_Real)) &BRepFill_Sweep::SetAngularControl, "Tolerance To controle Corner management.", py::arg("AngleMin"), py::arg("AngleMax"));
cls_BRepFill_Sweep.def("SetForceApproxC1", (void (BRepFill_Sweep::*)(const Standard_Boolean)) &BRepFill_Sweep::SetForceApproxC1, "Set the flag that indicates attempt to approximate a C1-continuous surface if a swept surface proved to be C0.", py::arg("ForceApproxC1"));
cls_BRepFill_Sweep.def("Build", [](BRepFill_Sweep &self, TopTools_MapOfShape & a0, BRepFill_DataMapOfShapeHArray2OfShape & a1, BRepFill_DataMapOfShapeHArray2OfShape & a2) -> void { return self.Build(a0, a1, a2); });
cls_BRepFill_Sweep.def("Build", [](BRepFill_Sweep &self, TopTools_MapOfShape & a0, BRepFill_DataMapOfShapeHArray2OfShape & a1, BRepFill_DataMapOfShapeHArray2OfShape & a2, const BRepFill_TransitionStyle a3) -> void { return self.Build(a0, a1, a2, a3); });
cls_BRepFill_Sweep.def("Build", [](BRepFill_Sweep &self, TopTools_MapOfShape & a0, BRepFill_DataMapOfShapeHArray2OfShape & a1, BRepFill_DataMapOfShapeHArray2OfShape & a2, const BRepFill_TransitionStyle a3, const GeomAbs_Shape a4) -> void { return self.Build(a0, a1, a2, a3, a4); });
cls_BRepFill_Sweep.def("Build", [](BRepFill_Sweep &self, TopTools_MapOfShape & a0, BRepFill_DataMapOfShapeHArray2OfShape & a1, BRepFill_DataMapOfShapeHArray2OfShape & a2, const BRepFill_TransitionStyle a3, const GeomAbs_Shape a4, const GeomFill_ApproxStyle a5) -> void { return self.Build(a0, a1, a2, a3, a4, a5); });
cls_BRepFill_Sweep.def("Build", [](BRepFill_Sweep &self, TopTools_MapOfShape & a0, BRepFill_DataMapOfShapeHArray2OfShape & a1, BRepFill_DataMapOfShapeHArray2OfShape & a2, const BRepFill_TransitionStyle a3, const GeomAbs_Shape a4, const GeomFill_ApproxStyle a5, const Standard_Integer a6) -> void { return self.Build(a0, a1, a2, a3, a4, a5, a6); });
cls_BRepFill_Sweep.def("Build", (void (BRepFill_Sweep::*)(TopTools_MapOfShape &, BRepFill_DataMapOfShapeHArray2OfShape &, BRepFill_DataMapOfShapeHArray2OfShape &, const BRepFill_TransitionStyle, const GeomAbs_Shape, const GeomFill_ApproxStyle, const Standard_Integer, const Standard_Integer)) &BRepFill_Sweep::Build, "Build the Sweeep Surface Transition define Transition strategy Approx define Approximation Strategy - GeomFill_Section : The composed Function Location X Section is directly approximed. - GeomFill_Location : The location law is approximed, and the SweepSurface is bulid algebric composition of approximed location law and section law This option is Ok, if Section.Surface() methode is effective. Continuity : The continuity in v waiting on the surface Degmax : The maximum degree in v requiered on the surface Segmax : The maximum number of span in v requiered on the surface.", py::arg("ReversedEdges"), py::arg("Tapes"), py::arg("Rails"), py::arg("Transition"), py::arg("Continuity"), py::arg("Approx"), py::arg("Degmax"), py::arg("Segmax"));
cls_BRepFill_Sweep.def("IsDone", (Standard_Boolean (BRepFill_Sweep::*)() const) &BRepFill_Sweep::IsDone, "Say if the Shape is Build.");
cls_BRepFill_Sweep.def("Shape", (TopoDS_Shape (BRepFill_Sweep::*)() const) &BRepFill_Sweep::Shape, "returns the Sweeping Shape");
cls_BRepFill_Sweep.def("ErrorOnSurface", (Standard_Real (BRepFill_Sweep::*)() const) &BRepFill_Sweep::ErrorOnSurface, "Get the Approximation error.");
cls_BRepFill_Sweep.def("SubShape", (opencascade::handle<TopTools_HArray2OfShape> (BRepFill_Sweep::*)() const) &BRepFill_Sweep::SubShape, "None");
cls_BRepFill_Sweep.def("InterFaces", (opencascade::handle<TopTools_HArray2OfShape> (BRepFill_Sweep::*)() const) &BRepFill_Sweep::InterFaces, "None");
cls_BRepFill_Sweep.def("Sections", (opencascade::handle<TopTools_HArray2OfShape> (BRepFill_Sweep::*)() const) &BRepFill_Sweep::Sections, "None");
cls_BRepFill_Sweep.def("Tape", (TopoDS_Shape (BRepFill_Sweep::*)(const Standard_Integer) const) &BRepFill_Sweep::Tape, "returns the Tape corresponding to Index-th edge of section", py::arg("Index"));

// Enums

}