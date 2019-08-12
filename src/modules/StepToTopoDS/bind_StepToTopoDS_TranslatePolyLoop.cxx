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
#include <StepShape_PolyLoop.hxx>
#include <StepToTopoDS_Tool.hxx>
#include <Geom_Surface.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Shape.hxx>
#include <StepToTopoDS_TranslatePolyLoopError.hxx>
#include <StepToTopoDS_TranslatePolyLoop.hxx>

void bind_StepToTopoDS_TranslatePolyLoop(py::module &mod){

py::class_<StepToTopoDS_TranslatePolyLoop, std::unique_ptr<StepToTopoDS_TranslatePolyLoop, Deleter<StepToTopoDS_TranslatePolyLoop>>, StepToTopoDS_Root> cls_StepToTopoDS_TranslatePolyLoop(mod, "StepToTopoDS_TranslatePolyLoop", "None");

// Constructors
cls_StepToTopoDS_TranslatePolyLoop.def(py::init<>());
cls_StepToTopoDS_TranslatePolyLoop.def(py::init<const opencascade::handle<StepShape_PolyLoop> &, StepToTopoDS_Tool &, const opencascade::handle<Geom_Surface> &, const TopoDS_Face &>(), py::arg("PL"), py::arg("T"), py::arg("S"), py::arg("F"));

// Fields

// Methods
// cls_StepToTopoDS_TranslatePolyLoop.def_static("operator new_", (void * (*)(size_t)) &StepToTopoDS_TranslatePolyLoop::operator new, "None", py::arg("theSize"));
// cls_StepToTopoDS_TranslatePolyLoop.def_static("operator delete_", (void (*)(void *)) &StepToTopoDS_TranslatePolyLoop::operator delete, "None", py::arg("theAddress"));
// cls_StepToTopoDS_TranslatePolyLoop.def_static("operator new[]_", (void * (*)(size_t)) &StepToTopoDS_TranslatePolyLoop::operator new[], "None", py::arg("theSize"));
// cls_StepToTopoDS_TranslatePolyLoop.def_static("operator delete[]_", (void (*)(void *)) &StepToTopoDS_TranslatePolyLoop::operator delete[], "None", py::arg("theAddress"));
// cls_StepToTopoDS_TranslatePolyLoop.def_static("operator new_", (void * (*)(size_t, void *)) &StepToTopoDS_TranslatePolyLoop::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepToTopoDS_TranslatePolyLoop.def_static("operator delete_", (void (*)(void *, void *)) &StepToTopoDS_TranslatePolyLoop::operator delete, "None", py::arg(""), py::arg(""));
cls_StepToTopoDS_TranslatePolyLoop.def("Init", (void (StepToTopoDS_TranslatePolyLoop::*)(const opencascade::handle<StepShape_PolyLoop> &, StepToTopoDS_Tool &, const opencascade::handle<Geom_Surface> &, const TopoDS_Face &)) &StepToTopoDS_TranslatePolyLoop::Init, "None", py::arg("PL"), py::arg("T"), py::arg("S"), py::arg("F"));
cls_StepToTopoDS_TranslatePolyLoop.def("Value", (const TopoDS_Shape & (StepToTopoDS_TranslatePolyLoop::*)() const) &StepToTopoDS_TranslatePolyLoop::Value, "None");
cls_StepToTopoDS_TranslatePolyLoop.def("Error", (StepToTopoDS_TranslatePolyLoopError (StepToTopoDS_TranslatePolyLoop::*)() const) &StepToTopoDS_TranslatePolyLoop::Error, "None");

// Enums

}