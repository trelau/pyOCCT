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
#include <BOPAlgo_Algo.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <BOPAlgo_Operation.hxx>
#include <Standard_TypeDef.hxx>
#include <BOPAlgo_ListOfCheckResult.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <BOPAlgo_ArgumentAnalyzer.hxx>

void bind_BOPAlgo_ArgumentAnalyzer(py::module &mod){

py::class_<BOPAlgo_ArgumentAnalyzer, BOPAlgo_Algo> cls_BOPAlgo_ArgumentAnalyzer(mod, "BOPAlgo_ArgumentAnalyzer", "check the validity of argument(s) for Boolean Operations");

// Constructors
cls_BOPAlgo_ArgumentAnalyzer.def(py::init<>());

// Fields

// Methods
// cls_BOPAlgo_ArgumentAnalyzer.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_ArgumentAnalyzer::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_ArgumentAnalyzer.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_ArgumentAnalyzer::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_ArgumentAnalyzer.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_ArgumentAnalyzer::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_ArgumentAnalyzer.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_ArgumentAnalyzer::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_ArgumentAnalyzer.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_ArgumentAnalyzer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_ArgumentAnalyzer.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_ArgumentAnalyzer::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_ArgumentAnalyzer.def("SetShape1", (void (BOPAlgo_ArgumentAnalyzer::*)(const TopoDS_Shape &)) &BOPAlgo_ArgumentAnalyzer::SetShape1, "sets object shape", py::arg("TheShape"));
cls_BOPAlgo_ArgumentAnalyzer.def("SetShape2", (void (BOPAlgo_ArgumentAnalyzer::*)(const TopoDS_Shape &)) &BOPAlgo_ArgumentAnalyzer::SetShape2, "sets tool shape", py::arg("TheShape"));
cls_BOPAlgo_ArgumentAnalyzer.def("GetShape1", (const TopoDS_Shape & (BOPAlgo_ArgumentAnalyzer::*)() const) &BOPAlgo_ArgumentAnalyzer::GetShape1, "returns object shape;");
cls_BOPAlgo_ArgumentAnalyzer.def("GetShape2", (const TopoDS_Shape & (BOPAlgo_ArgumentAnalyzer::*)() const) &BOPAlgo_ArgumentAnalyzer::GetShape2, "returns tool shape");
cls_BOPAlgo_ArgumentAnalyzer.def("OperationType", (BOPAlgo_Operation & (BOPAlgo_ArgumentAnalyzer::*)()) &BOPAlgo_ArgumentAnalyzer::OperationType, "returns ref");
cls_BOPAlgo_ArgumentAnalyzer.def("StopOnFirstFaulty", (Standard_Boolean & (BOPAlgo_ArgumentAnalyzer::*)()) &BOPAlgo_ArgumentAnalyzer::StopOnFirstFaulty, "returns ref");
cls_BOPAlgo_ArgumentAnalyzer.def("ArgumentTypeMode", (Standard_Boolean & (BOPAlgo_ArgumentAnalyzer::*)()) &BOPAlgo_ArgumentAnalyzer::ArgumentTypeMode, "Returns (modifiable) mode that means checking types of shapes.");
cls_BOPAlgo_ArgumentAnalyzer.def("SelfInterMode", (Standard_Boolean & (BOPAlgo_ArgumentAnalyzer::*)()) &BOPAlgo_ArgumentAnalyzer::SelfInterMode, "Returns (modifiable) mode that means checking of self-intersection of shapes.");
cls_BOPAlgo_ArgumentAnalyzer.def("SmallEdgeMode", (Standard_Boolean & (BOPAlgo_ArgumentAnalyzer::*)()) &BOPAlgo_ArgumentAnalyzer::SmallEdgeMode, "Returns (modifiable) mode that means checking of small edges.");
cls_BOPAlgo_ArgumentAnalyzer.def("RebuildFaceMode", (Standard_Boolean & (BOPAlgo_ArgumentAnalyzer::*)()) &BOPAlgo_ArgumentAnalyzer::RebuildFaceMode, "Returns (modifiable) mode that means checking of possibility to split or rebuild faces.");
cls_BOPAlgo_ArgumentAnalyzer.def("TangentMode", (Standard_Boolean & (BOPAlgo_ArgumentAnalyzer::*)()) &BOPAlgo_ArgumentAnalyzer::TangentMode, "Returns (modifiable) mode that means checking of tangency between subshapes.");
cls_BOPAlgo_ArgumentAnalyzer.def("MergeVertexMode", (Standard_Boolean & (BOPAlgo_ArgumentAnalyzer::*)()) &BOPAlgo_ArgumentAnalyzer::MergeVertexMode, "Returns (modifiable) mode that means checking of problem of merging vertices.");
cls_BOPAlgo_ArgumentAnalyzer.def("MergeEdgeMode", (Standard_Boolean & (BOPAlgo_ArgumentAnalyzer::*)()) &BOPAlgo_ArgumentAnalyzer::MergeEdgeMode, "Returns (modifiable) mode that means checking of problem of merging edges.");
cls_BOPAlgo_ArgumentAnalyzer.def("ContinuityMode", (Standard_Boolean & (BOPAlgo_ArgumentAnalyzer::*)()) &BOPAlgo_ArgumentAnalyzer::ContinuityMode, "Returns (modifiable) mode that means checking of problem of continuity of the shape.");
cls_BOPAlgo_ArgumentAnalyzer.def("CurveOnSurfaceMode", (Standard_Boolean & (BOPAlgo_ArgumentAnalyzer::*)()) &BOPAlgo_ArgumentAnalyzer::CurveOnSurfaceMode, "Returns (modifiable) mode that means checking of problem of invalid curve on surface.");
cls_BOPAlgo_ArgumentAnalyzer.def("Perform", (void (BOPAlgo_ArgumentAnalyzer::*)()) &BOPAlgo_ArgumentAnalyzer::Perform, "performs analysis");
cls_BOPAlgo_ArgumentAnalyzer.def("HasFaulty", (Standard_Boolean (BOPAlgo_ArgumentAnalyzer::*)() const) &BOPAlgo_ArgumentAnalyzer::HasFaulty, "result of test");
cls_BOPAlgo_ArgumentAnalyzer.def("GetCheckResult", (const BOPAlgo_ListOfCheckResult & (BOPAlgo_ArgumentAnalyzer::*)() const) &BOPAlgo_ArgumentAnalyzer::GetCheckResult, "returns a result of test");

// Enums

}