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
#include <TopOpeBRepDS_DataStructure.hxx>
#include <Standard.hxx>
#include <TopOpeBRepDS_PDataStructure.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepDS_Interference.hxx>
#include <TopOpeBRepDS_Curve.hxx>
#include <gp_Pnt.hxx>
#include <TopAbs_Orientation.hxx>
#include <TopTrans_SurfaceTransition.hxx>
#include <TopOpeBRepDS_FaceInterferenceTool.hxx>

void bind_TopOpeBRepDS_FaceInterferenceTool(py::module &mod){

py::class_<TopOpeBRepDS_FaceInterferenceTool, std::unique_ptr<TopOpeBRepDS_FaceInterferenceTool, Deleter<TopOpeBRepDS_FaceInterferenceTool>>> cls_TopOpeBRepDS_FaceInterferenceTool(mod, "TopOpeBRepDS_FaceInterferenceTool", "a tool computing complex transition on Face.");

// Constructors
cls_TopOpeBRepDS_FaceInterferenceTool.def(py::init<const TopOpeBRepDS_PDataStructure &>(), py::arg("P"));

// Fields

// Methods
// cls_TopOpeBRepDS_FaceInterferenceTool.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_FaceInterferenceTool::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_FaceInterferenceTool.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_FaceInterferenceTool::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_FaceInterferenceTool.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_FaceInterferenceTool::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_FaceInterferenceTool.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_FaceInterferenceTool::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_FaceInterferenceTool.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_FaceInterferenceTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_FaceInterferenceTool.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_FaceInterferenceTool::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_FaceInterferenceTool.def("Init", (void (TopOpeBRepDS_FaceInterferenceTool::*)(const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Boolean, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_FaceInterferenceTool::Init, "Eisnew = true if E is a new edge built on edge I->Geometry() false if E is shape <=> I->Geometry()", py::arg("FI"), py::arg("E"), py::arg("Eisnew"), py::arg("I"));
cls_TopOpeBRepDS_FaceInterferenceTool.def("Add", (void (TopOpeBRepDS_FaceInterferenceTool::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Boolean, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_FaceInterferenceTool::Add, "Eisnew = true if E is a new edge built on edge I->Geometry() false if E is shape <=> I->Geometry()", py::arg("FI"), py::arg("F"), py::arg("E"), py::arg("Eisnew"), py::arg("I"));
cls_TopOpeBRepDS_FaceInterferenceTool.def("Add", (void (TopOpeBRepDS_FaceInterferenceTool::*)(const TopoDS_Shape &, const TopOpeBRepDS_Curve &, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_FaceInterferenceTool::Add, "None", py::arg("E"), py::arg("C"), py::arg("I"));
cls_TopOpeBRepDS_FaceInterferenceTool.def("SetEdgePntPar", (void (TopOpeBRepDS_FaceInterferenceTool::*)(const gp_Pnt &, const Standard_Real)) &TopOpeBRepDS_FaceInterferenceTool::SetEdgePntPar, "None", py::arg("P"), py::arg("par"));
cls_TopOpeBRepDS_FaceInterferenceTool.def("GetEdgePntPar", [](TopOpeBRepDS_FaceInterferenceTool &self, gp_Pnt & P, Standard_Real & par){ self.GetEdgePntPar(P, par); return par; }, "None", py::arg("P"), py::arg("par"));
cls_TopOpeBRepDS_FaceInterferenceTool.def("IsEdgePntParDef", (Standard_Boolean (TopOpeBRepDS_FaceInterferenceTool::*)() const) &TopOpeBRepDS_FaceInterferenceTool::IsEdgePntParDef, "None");
cls_TopOpeBRepDS_FaceInterferenceTool.def("Transition", (void (TopOpeBRepDS_FaceInterferenceTool::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const) &TopOpeBRepDS_FaceInterferenceTool::Transition, "None", py::arg("I"));

// Enums

}