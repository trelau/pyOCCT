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
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepDS_Interference.hxx>
#include <TopTrans_SurfaceTransition.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <TopOpeBRepDS_Edge3dInterferenceTool.hxx>

void bind_TopOpeBRepDS_Edge3dInterferenceTool(py::module &mod){

py::class_<TopOpeBRepDS_Edge3dInterferenceTool, std::unique_ptr<TopOpeBRepDS_Edge3dInterferenceTool>> cls_TopOpeBRepDS_Edge3dInterferenceTool(mod, "TopOpeBRepDS_Edge3dInterferenceTool", "a tool computing edge / face complex transition, Interferences of edge reference are given by I = (T on face, G = point or vertex, S = edge)");

// Constructors
cls_TopOpeBRepDS_Edge3dInterferenceTool.def(py::init<>());

// Fields

// Methods
// cls_TopOpeBRepDS_Edge3dInterferenceTool.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_Edge3dInterferenceTool::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_Edge3dInterferenceTool.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_Edge3dInterferenceTool::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_Edge3dInterferenceTool.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_Edge3dInterferenceTool::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_Edge3dInterferenceTool.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_Edge3dInterferenceTool::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_Edge3dInterferenceTool.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_Edge3dInterferenceTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_Edge3dInterferenceTool.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_Edge3dInterferenceTool::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_Edge3dInterferenceTool.def("InitPointVertex", (void (TopOpeBRepDS_Edge3dInterferenceTool::*)(const Standard_Integer, const TopoDS_Shape &)) &TopOpeBRepDS_Edge3dInterferenceTool::InitPointVertex, "None", py::arg("IsVertex"), py::arg("VonOO"));
cls_TopOpeBRepDS_Edge3dInterferenceTool.def("Init", (void (TopOpeBRepDS_Edge3dInterferenceTool::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_Edge3dInterferenceTool::Init, "None", py::arg("Eref"), py::arg("E"), py::arg("F"), py::arg("I"));
cls_TopOpeBRepDS_Edge3dInterferenceTool.def("Add", (void (TopOpeBRepDS_Edge3dInterferenceTool::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_Edge3dInterferenceTool::Add, "None", py::arg("Eref"), py::arg("E"), py::arg("F"), py::arg("I"));
cls_TopOpeBRepDS_Edge3dInterferenceTool.def("Transition", (void (TopOpeBRepDS_Edge3dInterferenceTool::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const) &TopOpeBRepDS_Edge3dInterferenceTool::Transition, "None", py::arg("I"));

// Enums

}