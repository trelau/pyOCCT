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
#include <TopOpeBRepBuild_LoopClassifier.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <TopAbs_State.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepBuild_Loop.hxx>
#include <Standard_TypeDef.hxx>
#include <TopAbs_Orientation.hxx>
#include <TopoDS_Edge.hxx>
#include <TopOpeBRepBuild_PaveClassifier.hxx>

void bind_TopOpeBRepBuild_PaveClassifier(py::module &mod){

py::class_<TopOpeBRepBuild_PaveClassifier, std::unique_ptr<TopOpeBRepBuild_PaveClassifier, Deleter<TopOpeBRepBuild_PaveClassifier>>, TopOpeBRepBuild_LoopClassifier> cls_TopOpeBRepBuild_PaveClassifier(mod, "TopOpeBRepBuild_PaveClassifier", "This class compares vertices on an edge.");

// Constructors
cls_TopOpeBRepBuild_PaveClassifier.def(py::init<const TopoDS_Shape &>(), py::arg("E"));

// Fields

// Methods
// cls_TopOpeBRepBuild_PaveClassifier.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_PaveClassifier::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_PaveClassifier.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_PaveClassifier::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_PaveClassifier.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_PaveClassifier::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_PaveClassifier.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_PaveClassifier::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_PaveClassifier.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_PaveClassifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_PaveClassifier.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_PaveClassifier::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_PaveClassifier.def("Compare", (TopAbs_State (TopOpeBRepBuild_PaveClassifier::*)(const opencascade::handle<TopOpeBRepBuild_Loop> &, const opencascade::handle<TopOpeBRepBuild_Loop> &)) &TopOpeBRepBuild_PaveClassifier::Compare, "Returns state of vertex <L1> compared with <L2>.", py::arg("L1"), py::arg("L2"));
cls_TopOpeBRepBuild_PaveClassifier.def("SetFirstParameter", (void (TopOpeBRepBuild_PaveClassifier::*)(const Standard_Real)) &TopOpeBRepBuild_PaveClassifier::SetFirstParameter, "None", py::arg("P"));
cls_TopOpeBRepBuild_PaveClassifier.def("ClosedVertices", (void (TopOpeBRepBuild_PaveClassifier::*)(const Standard_Boolean)) &TopOpeBRepBuild_PaveClassifier::ClosedVertices, "None", py::arg("B"));
cls_TopOpeBRepBuild_PaveClassifier.def_static("AdjustCase_", [](const Standard_Real p1, const TopAbs_Orientation o, const Standard_Real first, const Standard_Real period, const Standard_Real tol, Standard_Integer & cas){ Standard_Real rv = TopOpeBRepBuild_PaveClassifier::AdjustCase(p1, o, first, period, tol, cas); return std::tuple<Standard_Real, Standard_Integer &>(rv, cas); }, "None", py::arg("p1"), py::arg("o"), py::arg("first"), py::arg("period"), py::arg("tol"), py::arg("cas"));

// Enums

}