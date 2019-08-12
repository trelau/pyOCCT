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
#include <StepShape_Vertex.hxx>
#include <StepToTopoDS_Tool.hxx>
#include <StepToTopoDS_NMTool.hxx>
#include <TopoDS_Shape.hxx>
#include <StepToTopoDS_TranslateVertexError.hxx>
#include <StepToTopoDS_TranslateVertex.hxx>

void bind_StepToTopoDS_TranslateVertex(py::module &mod){

py::class_<StepToTopoDS_TranslateVertex, std::unique_ptr<StepToTopoDS_TranslateVertex, Deleter<StepToTopoDS_TranslateVertex>>, StepToTopoDS_Root> cls_StepToTopoDS_TranslateVertex(mod, "StepToTopoDS_TranslateVertex", "None");

// Constructors
cls_StepToTopoDS_TranslateVertex.def(py::init<>());
cls_StepToTopoDS_TranslateVertex.def(py::init<const opencascade::handle<StepShape_Vertex> &, StepToTopoDS_Tool &, StepToTopoDS_NMTool &>(), py::arg("V"), py::arg("T"), py::arg("NMTool"));

// Fields

// Methods
// cls_StepToTopoDS_TranslateVertex.def_static("operator new_", (void * (*)(size_t)) &StepToTopoDS_TranslateVertex::operator new, "None", py::arg("theSize"));
// cls_StepToTopoDS_TranslateVertex.def_static("operator delete_", (void (*)(void *)) &StepToTopoDS_TranslateVertex::operator delete, "None", py::arg("theAddress"));
// cls_StepToTopoDS_TranslateVertex.def_static("operator new[]_", (void * (*)(size_t)) &StepToTopoDS_TranslateVertex::operator new[], "None", py::arg("theSize"));
// cls_StepToTopoDS_TranslateVertex.def_static("operator delete[]_", (void (*)(void *)) &StepToTopoDS_TranslateVertex::operator delete[], "None", py::arg("theAddress"));
// cls_StepToTopoDS_TranslateVertex.def_static("operator new_", (void * (*)(size_t, void *)) &StepToTopoDS_TranslateVertex::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepToTopoDS_TranslateVertex.def_static("operator delete_", (void (*)(void *, void *)) &StepToTopoDS_TranslateVertex::operator delete, "None", py::arg(""), py::arg(""));
cls_StepToTopoDS_TranslateVertex.def("Init", (void (StepToTopoDS_TranslateVertex::*)(const opencascade::handle<StepShape_Vertex> &, StepToTopoDS_Tool &, StepToTopoDS_NMTool &)) &StepToTopoDS_TranslateVertex::Init, "None", py::arg("V"), py::arg("T"), py::arg("NMTool"));
cls_StepToTopoDS_TranslateVertex.def("Value", (const TopoDS_Shape & (StepToTopoDS_TranslateVertex::*)() const) &StepToTopoDS_TranslateVertex::Value, "None");
cls_StepToTopoDS_TranslateVertex.def("Error", (StepToTopoDS_TranslateVertexError (StepToTopoDS_TranslateVertex::*)() const) &StepToTopoDS_TranslateVertex::Error, "None");

// Enums

}