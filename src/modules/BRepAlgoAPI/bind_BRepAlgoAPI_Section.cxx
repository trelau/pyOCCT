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
#include <BRepAlgoAPI_BooleanOperation.hxx>
#include <Standard.hxx>
#include <BOPAlgo_PaveFiller.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pln.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <BRepAlgoAPI_Section.hxx>

void bind_BRepAlgoAPI_Section(py::module &mod){

py::class_<BRepAlgoAPI_Section, BRepAlgoAPI_BooleanOperation> cls_BRepAlgoAPI_Section(mod, "BRepAlgoAPI_Section", "The algorithm is to build a Secton operation between arguments and tools. The result of Section operation consists of vertices and edges. The result of Section operation contains: 1. new vertices that are subjects of V/V, E/E, E/F, F/F interferences 2. vertices that are subjects of V/E, V/F interferences 3. new edges that are subjects of F/F interferences 4. edges that are Common Blocks");

// Constructors
cls_BRepAlgoAPI_Section.def(py::init<>());
cls_BRepAlgoAPI_Section.def(py::init<const BOPAlgo_PaveFiller &>(), py::arg("PF"));
cls_BRepAlgoAPI_Section.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("S1"), py::arg("S2"));
cls_BRepAlgoAPI_Section.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Boolean>(), py::arg("S1"), py::arg("S2"), py::arg("PerformNow"));
cls_BRepAlgoAPI_Section.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const BOPAlgo_PaveFiller &>(), py::arg("S1"), py::arg("S2"), py::arg("aDSF"));
cls_BRepAlgoAPI_Section.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const BOPAlgo_PaveFiller &, const Standard_Boolean>(), py::arg("S1"), py::arg("S2"), py::arg("aDSF"), py::arg("PerformNow"));
cls_BRepAlgoAPI_Section.def(py::init<const TopoDS_Shape &, const gp_Pln &>(), py::arg("S1"), py::arg("Pl"));
cls_BRepAlgoAPI_Section.def(py::init<const TopoDS_Shape &, const gp_Pln &, const Standard_Boolean>(), py::arg("S1"), py::arg("Pl"), py::arg("PerformNow"));
cls_BRepAlgoAPI_Section.def(py::init<const TopoDS_Shape &, const opencascade::handle<Geom_Surface> &>(), py::arg("S1"), py::arg("Sf"));
cls_BRepAlgoAPI_Section.def(py::init<const TopoDS_Shape &, const opencascade::handle<Geom_Surface> &, const Standard_Boolean>(), py::arg("S1"), py::arg("Sf"), py::arg("PerformNow"));
cls_BRepAlgoAPI_Section.def(py::init<const opencascade::handle<Geom_Surface> &, const TopoDS_Shape &>(), py::arg("Sf"), py::arg("S2"));
cls_BRepAlgoAPI_Section.def(py::init<const opencascade::handle<Geom_Surface> &, const TopoDS_Shape &, const Standard_Boolean>(), py::arg("Sf"), py::arg("S2"), py::arg("PerformNow"));
cls_BRepAlgoAPI_Section.def(py::init<const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &>(), py::arg("Sf1"), py::arg("Sf2"));
cls_BRepAlgoAPI_Section.def(py::init<const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const Standard_Boolean>(), py::arg("Sf1"), py::arg("Sf2"), py::arg("PerformNow"));

// Fields

// Methods
// cls_BRepAlgoAPI_Section.def_static("operator new_", (void * (*)(size_t)) &BRepAlgoAPI_Section::operator new, "None", py::arg("theSize"));
// cls_BRepAlgoAPI_Section.def_static("operator delete_", (void (*)(void *)) &BRepAlgoAPI_Section::operator delete, "None", py::arg("theAddress"));
// cls_BRepAlgoAPI_Section.def_static("operator new[]_", (void * (*)(size_t)) &BRepAlgoAPI_Section::operator new[], "None", py::arg("theSize"));
// cls_BRepAlgoAPI_Section.def_static("operator delete[]_", (void (*)(void *)) &BRepAlgoAPI_Section::operator delete[], "None", py::arg("theAddress"));
// cls_BRepAlgoAPI_Section.def_static("operator new_", (void * (*)(size_t, void *)) &BRepAlgoAPI_Section::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepAlgoAPI_Section.def_static("operator delete_", (void (*)(void *, void *)) &BRepAlgoAPI_Section::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepAlgoAPI_Section.def("Init1", (void (BRepAlgoAPI_Section::*)(const TopoDS_Shape &)) &BRepAlgoAPI_Section::Init1, "initialize the argument <S1> - argument Obsolete", py::arg("S1"));
cls_BRepAlgoAPI_Section.def("Init1", (void (BRepAlgoAPI_Section::*)(const gp_Pln &)) &BRepAlgoAPI_Section::Init1, "initialize the argument <Pl> - argument Obsolete", py::arg("Pl"));
cls_BRepAlgoAPI_Section.def("Init1", (void (BRepAlgoAPI_Section::*)(const opencascade::handle<Geom_Surface> &)) &BRepAlgoAPI_Section::Init1, "initialize the argument <Sf> - argument Obsolete", py::arg("Sf"));
cls_BRepAlgoAPI_Section.def("Init2", (void (BRepAlgoAPI_Section::*)(const TopoDS_Shape &)) &BRepAlgoAPI_Section::Init2, "initialize the tool <S2> - tool Obsolete", py::arg("S2"));
cls_BRepAlgoAPI_Section.def("Init2", (void (BRepAlgoAPI_Section::*)(const gp_Pln &)) &BRepAlgoAPI_Section::Init2, "initialize the tool <Pl> - tool Obsolete", py::arg("Pl"));
cls_BRepAlgoAPI_Section.def("Init2", (void (BRepAlgoAPI_Section::*)(const opencascade::handle<Geom_Surface> &)) &BRepAlgoAPI_Section::Init2, "initialize the tool <Sf> - tool Obsolete", py::arg("Sf"));
cls_BRepAlgoAPI_Section.def("Approximation", (void (BRepAlgoAPI_Section::*)(const Standard_Boolean)) &BRepAlgoAPI_Section::Approximation, "None", py::arg("B"));
cls_BRepAlgoAPI_Section.def("ComputePCurveOn1", (void (BRepAlgoAPI_Section::*)(const Standard_Boolean)) &BRepAlgoAPI_Section::ComputePCurveOn1, "Indicates whether the P-Curve should be (or not) performed on the argument. By default, no parametric 2D curve (pcurve) is defined for the edges of the result. If ComputePCurve1 equals true, further computations performed to attach an P-Curve in the parametric space of the argument to the constructed edges. Obsolete", py::arg("B"));
cls_BRepAlgoAPI_Section.def("ComputePCurveOn2", (void (BRepAlgoAPI_Section::*)(const Standard_Boolean)) &BRepAlgoAPI_Section::ComputePCurveOn2, "Indicates whether the P-Curve should be (or not) performed on the tool. By default, no parametric 2D curve (pcurve) is defined for the edges of the result. If ComputePCurve1 equals true, further computations performed to attach an P-Curve in the parametric space of the tool to the constructed edges. Obsolete", py::arg("B"));
cls_BRepAlgoAPI_Section.def("Build", (void (BRepAlgoAPI_Section::*)()) &BRepAlgoAPI_Section::Build, "Performs the algorithm Filling interference Data Structure (if it is necessary) Building the result of the operation.");
cls_BRepAlgoAPI_Section.def("HasAncestorFaceOn1", (Standard_Boolean (BRepAlgoAPI_Section::*)(const TopoDS_Shape &, TopoDS_Shape &) const) &BRepAlgoAPI_Section::HasAncestorFaceOn1, "get the face of the first part giving section edge <E>. Returns True on the 3 following conditions : 1/ <E> is an edge returned by the Shape() metwod. 2/ First part of section performed is a shape. 3/ <E> is built on a intersection curve (i.e <E> is not the result of common edges) When False, F remains untouched. Obsolete", py::arg("E"), py::arg("F"));
cls_BRepAlgoAPI_Section.def("HasAncestorFaceOn2", (Standard_Boolean (BRepAlgoAPI_Section::*)(const TopoDS_Shape &, TopoDS_Shape &) const) &BRepAlgoAPI_Section::HasAncestorFaceOn2, "Identifies the ancestor faces of the intersection edge E resulting from the last computation performed in this framework, that is, the faces of the two original shapes on which the edge E lies: - HasAncestorFaceOn1 gives the ancestor face in the first shape, and - HasAncestorFaceOn2 gives the ancestor face in the second shape. These functions return true if an ancestor face F is found, or false if not. An ancestor face is identifiable for the edge E if the following conditions are satisfied: - the first part on which this algorithm performed its last computation is a shape, that is, it was not given as a surface or a plane at the time of construction of this algorithm or at a later time by the Init1 function, - E is one of the elementary edges built by the last computation of this section algorithm. To use these functions properly, you have to test the returned Boolean value before using the ancestor face: F is significant only if the returned Boolean value equals true. Obsolete", py::arg("E"), py::arg("F"));

// Enums

}