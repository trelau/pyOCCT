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
#include <TopoDSToStep_Root.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDSToStep_Tool.hxx>
#include <Standard_Handle.hxx>
#include <Transfer_FinderProcess.hxx>
#include <TopoDSToStep_BuilderError.hxx>
#include <TColStd_HSequenceOfTransient.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <MoniTool_DataMapOfShapeTransient.hxx>
#include <TopoDSToStep_WireframeBuilder.hxx>

void bind_TopoDSToStep_WireframeBuilder(py::module &mod){

py::class_<TopoDSToStep_WireframeBuilder, TopoDSToStep_Root> cls_TopoDSToStep_WireframeBuilder(mod, "TopoDSToStep_WireframeBuilder", "This builder Class provides services to build a ProSTEP Wireframemodel from a Cas.Cad BRep.");

// Constructors
cls_TopoDSToStep_WireframeBuilder.def(py::init<>());
cls_TopoDSToStep_WireframeBuilder.def(py::init<const TopoDS_Shape &, TopoDSToStep_Tool &, const opencascade::handle<Transfer_FinderProcess> &>(), py::arg("S"), py::arg("T"), py::arg("FP"));

// Fields

// Methods
// cls_TopoDSToStep_WireframeBuilder.def_static("operator new_", (void * (*)(size_t)) &TopoDSToStep_WireframeBuilder::operator new, "None", py::arg("theSize"));
// cls_TopoDSToStep_WireframeBuilder.def_static("operator delete_", (void (*)(void *)) &TopoDSToStep_WireframeBuilder::operator delete, "None", py::arg("theAddress"));
// cls_TopoDSToStep_WireframeBuilder.def_static("operator new[]_", (void * (*)(size_t)) &TopoDSToStep_WireframeBuilder::operator new[], "None", py::arg("theSize"));
// cls_TopoDSToStep_WireframeBuilder.def_static("operator delete[]_", (void (*)(void *)) &TopoDSToStep_WireframeBuilder::operator delete[], "None", py::arg("theAddress"));
// cls_TopoDSToStep_WireframeBuilder.def_static("operator new_", (void * (*)(size_t, void *)) &TopoDSToStep_WireframeBuilder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopoDSToStep_WireframeBuilder.def_static("operator delete_", (void (*)(void *, void *)) &TopoDSToStep_WireframeBuilder::operator delete, "None", py::arg(""), py::arg(""));
cls_TopoDSToStep_WireframeBuilder.def("Init", (void (TopoDSToStep_WireframeBuilder::*)(const TopoDS_Shape &, TopoDSToStep_Tool &, const opencascade::handle<Transfer_FinderProcess> &)) &TopoDSToStep_WireframeBuilder::Init, "None", py::arg("S"), py::arg("T"), py::arg("FP"));
cls_TopoDSToStep_WireframeBuilder.def("Error", (TopoDSToStep_BuilderError (TopoDSToStep_WireframeBuilder::*)() const) &TopoDSToStep_WireframeBuilder::Error, "None");
cls_TopoDSToStep_WireframeBuilder.def("Value", (const opencascade::handle<TColStd_HSequenceOfTransient> & (TopoDSToStep_WireframeBuilder::*)() const) &TopoDSToStep_WireframeBuilder::Value, "None");
cls_TopoDSToStep_WireframeBuilder.def("GetTrimmedCurveFromEdge", (Standard_Boolean (TopoDSToStep_WireframeBuilder::*)(const TopoDS_Edge &, const TopoDS_Face &, MoniTool_DataMapOfShapeTransient &, opencascade::handle<TColStd_HSequenceOfTransient> &) const) &TopoDSToStep_WireframeBuilder::GetTrimmedCurveFromEdge, "Extraction of Trimmed Curves from TopoDS_Edge for the Creation of a GeometricallyBoundedWireframeRepresentation", py::arg("E"), py::arg("F"), py::arg("M"), py::arg("L"));
cls_TopoDSToStep_WireframeBuilder.def("GetTrimmedCurveFromFace", (Standard_Boolean (TopoDSToStep_WireframeBuilder::*)(const TopoDS_Face &, MoniTool_DataMapOfShapeTransient &, opencascade::handle<TColStd_HSequenceOfTransient> &) const) &TopoDSToStep_WireframeBuilder::GetTrimmedCurveFromFace, "Extraction of Trimmed Curves from TopoDS_Face for the Creation of a GeometricallyBoundedWireframeRepresentation", py::arg("F"), py::arg("M"), py::arg("L"));
cls_TopoDSToStep_WireframeBuilder.def("GetTrimmedCurveFromShape", (Standard_Boolean (TopoDSToStep_WireframeBuilder::*)(const TopoDS_Shape &, MoniTool_DataMapOfShapeTransient &, opencascade::handle<TColStd_HSequenceOfTransient> &) const) &TopoDSToStep_WireframeBuilder::GetTrimmedCurveFromShape, "Extraction of Trimmed Curves from any TopoDS_Shape for the Creation of a GeometricallyBoundedWireframeRepresentation", py::arg("S"), py::arg("M"), py::arg("L"));

// Enums

}