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
#include <StepToTopoDS_DataMapOfRI.hxx>
#include <StepToTopoDS_DataMapOfRINames.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <StepRepr_RepresentationItem.hxx>
#include <TCollection_AsciiString.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <StepToTopoDS_NMTool.hxx>

void bind_StepToTopoDS_NMTool(py::module &mod){

py::class_<StepToTopoDS_NMTool, std::unique_ptr<StepToTopoDS_NMTool, Deleter<StepToTopoDS_NMTool>>> cls_StepToTopoDS_NMTool(mod, "StepToTopoDS_NMTool", "Provides data to process non-manifold topology when reading from STEP.");

// Constructors
cls_StepToTopoDS_NMTool.def(py::init<>());
cls_StepToTopoDS_NMTool.def(py::init<const StepToTopoDS_DataMapOfRI &, const StepToTopoDS_DataMapOfRINames &>(), py::arg("MapOfRI"), py::arg("MapOfRINames"));

// Fields

// Methods
// cls_StepToTopoDS_NMTool.def_static("operator new_", (void * (*)(size_t)) &StepToTopoDS_NMTool::operator new, "None", py::arg("theSize"));
// cls_StepToTopoDS_NMTool.def_static("operator delete_", (void (*)(void *)) &StepToTopoDS_NMTool::operator delete, "None", py::arg("theAddress"));
// cls_StepToTopoDS_NMTool.def_static("operator new[]_", (void * (*)(size_t)) &StepToTopoDS_NMTool::operator new[], "None", py::arg("theSize"));
// cls_StepToTopoDS_NMTool.def_static("operator delete[]_", (void (*)(void *)) &StepToTopoDS_NMTool::operator delete[], "None", py::arg("theAddress"));
// cls_StepToTopoDS_NMTool.def_static("operator new_", (void * (*)(size_t, void *)) &StepToTopoDS_NMTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepToTopoDS_NMTool.def_static("operator delete_", (void (*)(void *, void *)) &StepToTopoDS_NMTool::operator delete, "None", py::arg(""), py::arg(""));
cls_StepToTopoDS_NMTool.def("Init", (void (StepToTopoDS_NMTool::*)(const StepToTopoDS_DataMapOfRI &, const StepToTopoDS_DataMapOfRINames &)) &StepToTopoDS_NMTool::Init, "None", py::arg("MapOfRI"), py::arg("MapOfRINames"));
cls_StepToTopoDS_NMTool.def("SetActive", (void (StepToTopoDS_NMTool::*)(const Standard_Boolean)) &StepToTopoDS_NMTool::SetActive, "None", py::arg("isActive"));
cls_StepToTopoDS_NMTool.def("IsActive", (Standard_Boolean (StepToTopoDS_NMTool::*)()) &StepToTopoDS_NMTool::IsActive, "None");
cls_StepToTopoDS_NMTool.def("CleanUp", (void (StepToTopoDS_NMTool::*)()) &StepToTopoDS_NMTool::CleanUp, "None");
cls_StepToTopoDS_NMTool.def("IsBound", (Standard_Boolean (StepToTopoDS_NMTool::*)(const opencascade::handle<StepRepr_RepresentationItem> &)) &StepToTopoDS_NMTool::IsBound, "None", py::arg("RI"));
cls_StepToTopoDS_NMTool.def("IsBound", (Standard_Boolean (StepToTopoDS_NMTool::*)(const TCollection_AsciiString &)) &StepToTopoDS_NMTool::IsBound, "None", py::arg("RIName"));
cls_StepToTopoDS_NMTool.def("Bind", (void (StepToTopoDS_NMTool::*)(const opencascade::handle<StepRepr_RepresentationItem> &, const TopoDS_Shape &)) &StepToTopoDS_NMTool::Bind, "None", py::arg("RI"), py::arg("S"));
cls_StepToTopoDS_NMTool.def("Bind", (void (StepToTopoDS_NMTool::*)(const TCollection_AsciiString &, const TopoDS_Shape &)) &StepToTopoDS_NMTool::Bind, "None", py::arg("RIName"), py::arg("S"));
cls_StepToTopoDS_NMTool.def("Find", (const TopoDS_Shape & (StepToTopoDS_NMTool::*)(const opencascade::handle<StepRepr_RepresentationItem> &)) &StepToTopoDS_NMTool::Find, "None", py::arg("RI"));
cls_StepToTopoDS_NMTool.def("Find", (const TopoDS_Shape & (StepToTopoDS_NMTool::*)(const TCollection_AsciiString &)) &StepToTopoDS_NMTool::Find, "None", py::arg("RIName"));
cls_StepToTopoDS_NMTool.def("RegisterNMEdge", (void (StepToTopoDS_NMTool::*)(const TopoDS_Shape &)) &StepToTopoDS_NMTool::RegisterNMEdge, "None", py::arg("Edge"));
cls_StepToTopoDS_NMTool.def("IsSuspectedAsClosing", (Standard_Boolean (StepToTopoDS_NMTool::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &StepToTopoDS_NMTool::IsSuspectedAsClosing, "None", py::arg("BaseShell"), py::arg("SuspectedShell"));
cls_StepToTopoDS_NMTool.def("IsPureNMShell", (Standard_Boolean (StepToTopoDS_NMTool::*)(const TopoDS_Shape &)) &StepToTopoDS_NMTool::IsPureNMShell, "None", py::arg("Shell"));
cls_StepToTopoDS_NMTool.def("SetIDEASCase", (void (StepToTopoDS_NMTool::*)(const Standard_Boolean)) &StepToTopoDS_NMTool::SetIDEASCase, "None", py::arg("IDEASCase"));
cls_StepToTopoDS_NMTool.def("IsIDEASCase", (Standard_Boolean (StepToTopoDS_NMTool::*)()) &StepToTopoDS_NMTool::IsIDEASCase, "None");

// Enums

}