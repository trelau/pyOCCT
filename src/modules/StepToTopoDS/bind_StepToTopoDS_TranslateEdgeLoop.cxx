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
#include <StepToTopoDS_Root.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <StepShape_FaceBound.hxx>
#include <TopoDS_Face.hxx>
#include <Geom_Surface.hxx>
#include <StepGeom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <StepToTopoDS_Tool.hxx>
#include <StepToTopoDS_NMTool.hxx>
#include <TopoDS_Shape.hxx>
#include <StepToTopoDS_TranslateEdgeLoopError.hxx>
#include <StepToTopoDS_TranslateEdgeLoop.hxx>

void bind_StepToTopoDS_TranslateEdgeLoop(py::module &mod){

py::class_<StepToTopoDS_TranslateEdgeLoop, StepToTopoDS_Root> cls_StepToTopoDS_TranslateEdgeLoop(mod, "StepToTopoDS_TranslateEdgeLoop", "None");

// Constructors
cls_StepToTopoDS_TranslateEdgeLoop.def(py::init<>());
cls_StepToTopoDS_TranslateEdgeLoop.def(py::init<const opencascade::handle<StepShape_FaceBound> &, const TopoDS_Face &, const opencascade::handle<Geom_Surface> &, const opencascade::handle<StepGeom_Surface> &, const Standard_Boolean, StepToTopoDS_Tool &, StepToTopoDS_NMTool &>(), py::arg("FB"), py::arg("F"), py::arg("S"), py::arg("SS"), py::arg("ss"), py::arg("T"), py::arg("NMTool"));

// Fields

// Methods
// cls_StepToTopoDS_TranslateEdgeLoop.def_static("operator new_", (void * (*)(size_t)) &StepToTopoDS_TranslateEdgeLoop::operator new, "None", py::arg("theSize"));
// cls_StepToTopoDS_TranslateEdgeLoop.def_static("operator delete_", (void (*)(void *)) &StepToTopoDS_TranslateEdgeLoop::operator delete, "None", py::arg("theAddress"));
// cls_StepToTopoDS_TranslateEdgeLoop.def_static("operator new[]_", (void * (*)(size_t)) &StepToTopoDS_TranslateEdgeLoop::operator new[], "None", py::arg("theSize"));
// cls_StepToTopoDS_TranslateEdgeLoop.def_static("operator delete[]_", (void (*)(void *)) &StepToTopoDS_TranslateEdgeLoop::operator delete[], "None", py::arg("theAddress"));
// cls_StepToTopoDS_TranslateEdgeLoop.def_static("operator new_", (void * (*)(size_t, void *)) &StepToTopoDS_TranslateEdgeLoop::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepToTopoDS_TranslateEdgeLoop.def_static("operator delete_", (void (*)(void *, void *)) &StepToTopoDS_TranslateEdgeLoop::operator delete, "None", py::arg(""), py::arg(""));
cls_StepToTopoDS_TranslateEdgeLoop.def("Init", (void (StepToTopoDS_TranslateEdgeLoop::*)(const opencascade::handle<StepShape_FaceBound> &, const TopoDS_Face &, const opencascade::handle<Geom_Surface> &, const opencascade::handle<StepGeom_Surface> &, const Standard_Boolean, StepToTopoDS_Tool &, StepToTopoDS_NMTool &)) &StepToTopoDS_TranslateEdgeLoop::Init, "None", py::arg("FB"), py::arg("F"), py::arg("S"), py::arg("SS"), py::arg("ss"), py::arg("T"), py::arg("NMTool"));
cls_StepToTopoDS_TranslateEdgeLoop.def("Value", (const TopoDS_Shape & (StepToTopoDS_TranslateEdgeLoop::*)() const) &StepToTopoDS_TranslateEdgeLoop::Value, "None");
cls_StepToTopoDS_TranslateEdgeLoop.def("Error", (StepToTopoDS_TranslateEdgeLoopError (StepToTopoDS_TranslateEdgeLoop::*)() const) &StepToTopoDS_TranslateEdgeLoop::Error, "None");

// Enums

}