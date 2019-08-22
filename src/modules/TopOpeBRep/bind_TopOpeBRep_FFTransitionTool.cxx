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
#include <TopOpeBRepDS_Transition.hxx>
#include <TopOpeBRep_VPointInter.hxx>
#include <Standard_TypeDef.hxx>
#include <TopAbs_Orientation.hxx>
#include <TopOpeBRep_LineInter.hxx>
#include <TopoDS_Shape.hxx>
#include <TopOpeBRep_FFTransitionTool.hxx>

void bind_TopOpeBRep_FFTransitionTool(py::module &mod){

py::class_<TopOpeBRep_FFTransitionTool> cls_TopOpeBRep_FFTransitionTool(mod, "TopOpeBRep_FFTransitionTool", "None");

// Constructors

// Fields

// Methods
// cls_TopOpeBRep_FFTransitionTool.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRep_FFTransitionTool::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRep_FFTransitionTool.def_static("operator delete_", (void (*)(void *)) &TopOpeBRep_FFTransitionTool::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRep_FFTransitionTool.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRep_FFTransitionTool::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRep_FFTransitionTool.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRep_FFTransitionTool::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRep_FFTransitionTool.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRep_FFTransitionTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRep_FFTransitionTool.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRep_FFTransitionTool::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRep_FFTransitionTool.def_static("ProcessLineTransition_", (TopOpeBRepDS_Transition (*)(const TopOpeBRep_VPointInter &, const Standard_Integer, const TopAbs_Orientation)) &TopOpeBRep_FFTransitionTool::ProcessLineTransition, "None", py::arg("P"), py::arg("Index"), py::arg("EdgeOrientation"));
cls_TopOpeBRep_FFTransitionTool.def_static("ProcessLineTransition_", (TopOpeBRepDS_Transition (*)(const TopOpeBRep_VPointInter &, const TopOpeBRep_LineInter &)) &TopOpeBRep_FFTransitionTool::ProcessLineTransition, "None", py::arg("P"), py::arg("L"));
cls_TopOpeBRep_FFTransitionTool.def_static("ProcessEdgeTransition_", (TopOpeBRepDS_Transition (*)(const TopOpeBRep_VPointInter &, const Standard_Integer, const TopAbs_Orientation)) &TopOpeBRep_FFTransitionTool::ProcessEdgeTransition, "None", py::arg("P"), py::arg("Index"), py::arg("LineOrientation"));
cls_TopOpeBRep_FFTransitionTool.def_static("ProcessFaceTransition_", (TopOpeBRepDS_Transition (*)(const TopOpeBRep_LineInter &, const Standard_Integer, const TopAbs_Orientation)) &TopOpeBRep_FFTransitionTool::ProcessFaceTransition, "None", py::arg("L"), py::arg("Index"), py::arg("FaceOrientation"));
cls_TopOpeBRep_FFTransitionTool.def_static("ProcessEdgeONTransition_", (TopOpeBRepDS_Transition (*)(const TopOpeBRep_VPointInter &, const Standard_Integer, const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRep_FFTransitionTool::ProcessEdgeONTransition, "compute transition on 'IntPatch_Restriction line' edge <R> when crossing edge <E> of face <F> at point <VP>. VP is given on edge <E> of face <F> of index <Index> (1 or 2). <VP> has been classified by FacesFiller as TopAbs_ON an edge <R> of the other face than <F> of current (face/face) intersection. Transition depends on the orientation of E in F. This method should be provided by IntPatch_Line (NYI)", py::arg("VP"), py::arg("Index"), py::arg("R"), py::arg("E"), py::arg("F"));

// Enums

}