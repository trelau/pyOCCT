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
#include <MoniTool_DataMapOfShapeTransient.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Handle.hxx>
#include <StepShape_TopologicalRepresentationItem.hxx>
#include <TopoDS_Shell.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDSToStep_Tool.hxx>

void bind_TopoDSToStep_Tool(py::module &mod){

py::class_<TopoDSToStep_Tool, std::unique_ptr<TopoDSToStep_Tool, Deleter<TopoDSToStep_Tool>>> cls_TopoDSToStep_Tool(mod, "TopoDSToStep_Tool", "This Tool Class provides Information to build a ProSTEP Shape model from a Cas.Cad BRep.");

// Constructors
cls_TopoDSToStep_Tool.def(py::init<>());
cls_TopoDSToStep_Tool.def(py::init<const MoniTool_DataMapOfShapeTransient &, const Standard_Boolean>(), py::arg("M"), py::arg("FacetedContext"));

// Fields

// Methods
// cls_TopoDSToStep_Tool.def_static("operator new_", (void * (*)(size_t)) &TopoDSToStep_Tool::operator new, "None", py::arg("theSize"));
// cls_TopoDSToStep_Tool.def_static("operator delete_", (void (*)(void *)) &TopoDSToStep_Tool::operator delete, "None", py::arg("theAddress"));
// cls_TopoDSToStep_Tool.def_static("operator new[]_", (void * (*)(size_t)) &TopoDSToStep_Tool::operator new[], "None", py::arg("theSize"));
// cls_TopoDSToStep_Tool.def_static("operator delete[]_", (void (*)(void *)) &TopoDSToStep_Tool::operator delete[], "None", py::arg("theAddress"));
// cls_TopoDSToStep_Tool.def_static("operator new_", (void * (*)(size_t, void *)) &TopoDSToStep_Tool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopoDSToStep_Tool.def_static("operator delete_", (void (*)(void *, void *)) &TopoDSToStep_Tool::operator delete, "None", py::arg(""), py::arg(""));
cls_TopoDSToStep_Tool.def("Init", (void (TopoDSToStep_Tool::*)(const MoniTool_DataMapOfShapeTransient &, const Standard_Boolean)) &TopoDSToStep_Tool::Init, "None", py::arg("M"), py::arg("FacetedContext"));
cls_TopoDSToStep_Tool.def("IsBound", (Standard_Boolean (TopoDSToStep_Tool::*)(const TopoDS_Shape &)) &TopoDSToStep_Tool::IsBound, "None", py::arg("S"));
cls_TopoDSToStep_Tool.def("Bind", (void (TopoDSToStep_Tool::*)(const TopoDS_Shape &, const opencascade::handle<StepShape_TopologicalRepresentationItem> &)) &TopoDSToStep_Tool::Bind, "None", py::arg("S"), py::arg("T"));
cls_TopoDSToStep_Tool.def("Find", (opencascade::handle<StepShape_TopologicalRepresentationItem> (TopoDSToStep_Tool::*)(const TopoDS_Shape &)) &TopoDSToStep_Tool::Find, "None", py::arg("S"));
cls_TopoDSToStep_Tool.def("Faceted", (Standard_Boolean (TopoDSToStep_Tool::*)() const) &TopoDSToStep_Tool::Faceted, "None");
cls_TopoDSToStep_Tool.def("SetCurrentShell", (void (TopoDSToStep_Tool::*)(const TopoDS_Shell &)) &TopoDSToStep_Tool::SetCurrentShell, "None", py::arg("S"));
cls_TopoDSToStep_Tool.def("CurrentShell", (const TopoDS_Shell & (TopoDSToStep_Tool::*)() const) &TopoDSToStep_Tool::CurrentShell, "None");
cls_TopoDSToStep_Tool.def("SetCurrentFace", (void (TopoDSToStep_Tool::*)(const TopoDS_Face &)) &TopoDSToStep_Tool::SetCurrentFace, "None", py::arg("F"));
cls_TopoDSToStep_Tool.def("CurrentFace", (const TopoDS_Face & (TopoDSToStep_Tool::*)() const) &TopoDSToStep_Tool::CurrentFace, "None");
cls_TopoDSToStep_Tool.def("SetCurrentWire", (void (TopoDSToStep_Tool::*)(const TopoDS_Wire &)) &TopoDSToStep_Tool::SetCurrentWire, "None", py::arg("W"));
cls_TopoDSToStep_Tool.def("CurrentWire", (const TopoDS_Wire & (TopoDSToStep_Tool::*)() const) &TopoDSToStep_Tool::CurrentWire, "None");
cls_TopoDSToStep_Tool.def("SetCurrentEdge", (void (TopoDSToStep_Tool::*)(const TopoDS_Edge &)) &TopoDSToStep_Tool::SetCurrentEdge, "None", py::arg("E"));
cls_TopoDSToStep_Tool.def("CurrentEdge", (const TopoDS_Edge & (TopoDSToStep_Tool::*)() const) &TopoDSToStep_Tool::CurrentEdge, "None");
cls_TopoDSToStep_Tool.def("SetCurrentVertex", (void (TopoDSToStep_Tool::*)(const TopoDS_Vertex &)) &TopoDSToStep_Tool::SetCurrentVertex, "None", py::arg("V"));
cls_TopoDSToStep_Tool.def("CurrentVertex", (const TopoDS_Vertex & (TopoDSToStep_Tool::*)() const) &TopoDSToStep_Tool::CurrentVertex, "None");
cls_TopoDSToStep_Tool.def("Lowest3DTolerance", (Standard_Real (TopoDSToStep_Tool::*)() const) &TopoDSToStep_Tool::Lowest3DTolerance, "None");
cls_TopoDSToStep_Tool.def("SetSurfaceReversed", (void (TopoDSToStep_Tool::*)(const Standard_Boolean)) &TopoDSToStep_Tool::SetSurfaceReversed, "None", py::arg("B"));
cls_TopoDSToStep_Tool.def("SurfaceReversed", (Standard_Boolean (TopoDSToStep_Tool::*)() const) &TopoDSToStep_Tool::SurfaceReversed, "None");
cls_TopoDSToStep_Tool.def("Map", (const MoniTool_DataMapOfShapeTransient & (TopoDSToStep_Tool::*)() const) &TopoDSToStep_Tool::Map, "None");
cls_TopoDSToStep_Tool.def("PCurveMode", (Standard_Integer (TopoDSToStep_Tool::*)() const) &TopoDSToStep_Tool::PCurveMode, "Returns mode for writing pcurves (initialized by parameter write.surfacecurve.mode)");

// Enums

}