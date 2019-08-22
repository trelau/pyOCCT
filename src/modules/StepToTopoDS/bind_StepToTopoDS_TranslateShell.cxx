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
#include <StepShape_ConnectedFaceSet.hxx>
#include <StepToTopoDS_Tool.hxx>
#include <StepToTopoDS_NMTool.hxx>
#include <TopoDS_Shape.hxx>
#include <StepToTopoDS_TranslateShellError.hxx>
#include <StepToTopoDS_TranslateShell.hxx>

void bind_StepToTopoDS_TranslateShell(py::module &mod){

py::class_<StepToTopoDS_TranslateShell, StepToTopoDS_Root> cls_StepToTopoDS_TranslateShell(mod, "StepToTopoDS_TranslateShell", "None");

// Constructors
cls_StepToTopoDS_TranslateShell.def(py::init<>());
cls_StepToTopoDS_TranslateShell.def(py::init<const opencascade::handle<StepShape_ConnectedFaceSet> &, StepToTopoDS_Tool &, StepToTopoDS_NMTool &>(), py::arg("CFS"), py::arg("T"), py::arg("NMTool"));

// Fields

// Methods
// cls_StepToTopoDS_TranslateShell.def_static("operator new_", (void * (*)(size_t)) &StepToTopoDS_TranslateShell::operator new, "None", py::arg("theSize"));
// cls_StepToTopoDS_TranslateShell.def_static("operator delete_", (void (*)(void *)) &StepToTopoDS_TranslateShell::operator delete, "None", py::arg("theAddress"));
// cls_StepToTopoDS_TranslateShell.def_static("operator new[]_", (void * (*)(size_t)) &StepToTopoDS_TranslateShell::operator new[], "None", py::arg("theSize"));
// cls_StepToTopoDS_TranslateShell.def_static("operator delete[]_", (void (*)(void *)) &StepToTopoDS_TranslateShell::operator delete[], "None", py::arg("theAddress"));
// cls_StepToTopoDS_TranslateShell.def_static("operator new_", (void * (*)(size_t, void *)) &StepToTopoDS_TranslateShell::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepToTopoDS_TranslateShell.def_static("operator delete_", (void (*)(void *, void *)) &StepToTopoDS_TranslateShell::operator delete, "None", py::arg(""), py::arg(""));
cls_StepToTopoDS_TranslateShell.def("Init", (void (StepToTopoDS_TranslateShell::*)(const opencascade::handle<StepShape_ConnectedFaceSet> &, StepToTopoDS_Tool &, StepToTopoDS_NMTool &)) &StepToTopoDS_TranslateShell::Init, "None", py::arg("CFS"), py::arg("T"), py::arg("NMTool"));
cls_StepToTopoDS_TranslateShell.def("Value", (const TopoDS_Shape & (StepToTopoDS_TranslateShell::*)() const) &StepToTopoDS_TranslateShell::Value, "None");
cls_StepToTopoDS_TranslateShell.def("Error", (StepToTopoDS_TranslateShellError (StepToTopoDS_TranslateShell::*)() const) &StepToTopoDS_TranslateShell::Error, "None");

// Enums

}