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
#include <TopoDS_Shape.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepDS_Interference.hxx>
#include <TopOpeBRepDS_Point.hxx>
#include <TopAbs_Orientation.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTrans_CurveTransition.hxx>
#include <TopOpeBRepDS_EdgeInterferenceTool.hxx>

void bind_TopOpeBRepDS_EdgeInterferenceTool(py::module &mod){

py::class_<TopOpeBRepDS_EdgeInterferenceTool, std::unique_ptr<TopOpeBRepDS_EdgeInterferenceTool>> cls_TopOpeBRepDS_EdgeInterferenceTool(mod, "TopOpeBRepDS_EdgeInterferenceTool", "a tool computing complex transition on Edge.");

// Constructors
cls_TopOpeBRepDS_EdgeInterferenceTool.def(py::init<>());

// Fields

// Methods
// cls_TopOpeBRepDS_EdgeInterferenceTool.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_EdgeInterferenceTool::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_EdgeInterferenceTool.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_EdgeInterferenceTool::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_EdgeInterferenceTool.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_EdgeInterferenceTool::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_EdgeInterferenceTool.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_EdgeInterferenceTool::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_EdgeInterferenceTool.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_EdgeInterferenceTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_EdgeInterferenceTool.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_EdgeInterferenceTool::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_EdgeInterferenceTool.def("Init", (void (TopOpeBRepDS_EdgeInterferenceTool::*)(const TopoDS_Shape &, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_EdgeInterferenceTool::Init, "None", py::arg("E"), py::arg("I"));
cls_TopOpeBRepDS_EdgeInterferenceTool.def("Add", (void (TopOpeBRepDS_EdgeInterferenceTool::*)(const TopoDS_Shape &, const TopoDS_Shape &, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_EdgeInterferenceTool::Add, "None", py::arg("E"), py::arg("V"), py::arg("I"));
cls_TopOpeBRepDS_EdgeInterferenceTool.def("Add", (void (TopOpeBRepDS_EdgeInterferenceTool::*)(const TopoDS_Shape &, const TopOpeBRepDS_Point &, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_EdgeInterferenceTool::Add, "None", py::arg("E"), py::arg("P"), py::arg("I"));
cls_TopOpeBRepDS_EdgeInterferenceTool.def("Transition", (void (TopOpeBRepDS_EdgeInterferenceTool::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const) &TopOpeBRepDS_EdgeInterferenceTool::Transition, "None", py::arg("I"));

// Enums

}