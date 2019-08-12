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
#include <StepShape_Edge.hxx>
#include <StepToTopoDS_Tool.hxx>
#include <StepToTopoDS_NMTool.hxx>
#include <StepGeom_Curve.hxx>
#include <StepShape_EdgeCurve.hxx>
#include <StepShape_Vertex.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Vertex.hxx>
#include <Geom2d_Curve.hxx>
#include <StepGeom_Pcurve.hxx>
#include <Geom_Surface.hxx>
#include <TopoDS_Shape.hxx>
#include <StepToTopoDS_TranslateEdgeError.hxx>
#include <StepToTopoDS_TranslateEdge.hxx>

void bind_StepToTopoDS_TranslateEdge(py::module &mod){

py::class_<StepToTopoDS_TranslateEdge, std::unique_ptr<StepToTopoDS_TranslateEdge, Deleter<StepToTopoDS_TranslateEdge>>, StepToTopoDS_Root> cls_StepToTopoDS_TranslateEdge(mod, "StepToTopoDS_TranslateEdge", "None");

// Constructors
cls_StepToTopoDS_TranslateEdge.def(py::init<>());
cls_StepToTopoDS_TranslateEdge.def(py::init<const opencascade::handle<StepShape_Edge> &, StepToTopoDS_Tool &, StepToTopoDS_NMTool &>(), py::arg("E"), py::arg("T"), py::arg("NMTool"));

// Fields

// Methods
// cls_StepToTopoDS_TranslateEdge.def_static("operator new_", (void * (*)(size_t)) &StepToTopoDS_TranslateEdge::operator new, "None", py::arg("theSize"));
// cls_StepToTopoDS_TranslateEdge.def_static("operator delete_", (void (*)(void *)) &StepToTopoDS_TranslateEdge::operator delete, "None", py::arg("theAddress"));
// cls_StepToTopoDS_TranslateEdge.def_static("operator new[]_", (void * (*)(size_t)) &StepToTopoDS_TranslateEdge::operator new[], "None", py::arg("theSize"));
// cls_StepToTopoDS_TranslateEdge.def_static("operator delete[]_", (void (*)(void *)) &StepToTopoDS_TranslateEdge::operator delete[], "None", py::arg("theAddress"));
// cls_StepToTopoDS_TranslateEdge.def_static("operator new_", (void * (*)(size_t, void *)) &StepToTopoDS_TranslateEdge::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepToTopoDS_TranslateEdge.def_static("operator delete_", (void (*)(void *, void *)) &StepToTopoDS_TranslateEdge::operator delete, "None", py::arg(""), py::arg(""));
cls_StepToTopoDS_TranslateEdge.def("Init", (void (StepToTopoDS_TranslateEdge::*)(const opencascade::handle<StepShape_Edge> &, StepToTopoDS_Tool &, StepToTopoDS_NMTool &)) &StepToTopoDS_TranslateEdge::Init, "None", py::arg("E"), py::arg("T"), py::arg("NMTool"));
cls_StepToTopoDS_TranslateEdge.def("MakeFromCurve3D", (void (StepToTopoDS_TranslateEdge::*)(const opencascade::handle<StepGeom_Curve> &, const opencascade::handle<StepShape_EdgeCurve> &, const opencascade::handle<StepShape_Vertex> &, const Standard_Real, TopoDS_Edge &, TopoDS_Vertex &, TopoDS_Vertex &, StepToTopoDS_Tool &)) &StepToTopoDS_TranslateEdge::MakeFromCurve3D, "Warning! C3D is assumed to be a Curve 3D ... other cases to checked before calling this", py::arg("C3D"), py::arg("EC"), py::arg("Vend"), py::arg("preci"), py::arg("E"), py::arg("V1"), py::arg("V2"), py::arg("T"));
cls_StepToTopoDS_TranslateEdge.def("MakePCurve", (opencascade::handle<Geom2d_Curve> (StepToTopoDS_TranslateEdge::*)(const opencascade::handle<StepGeom_Pcurve> &, const opencascade::handle<Geom_Surface> &) const) &StepToTopoDS_TranslateEdge::MakePCurve, "None", py::arg("PCU"), py::arg("ConvSurf"));
cls_StepToTopoDS_TranslateEdge.def("Value", (const TopoDS_Shape & (StepToTopoDS_TranslateEdge::*)() const) &StepToTopoDS_TranslateEdge::Value, "None");
cls_StepToTopoDS_TranslateEdge.def("Error", (StepToTopoDS_TranslateEdgeError (StepToTopoDS_TranslateEdge::*)() const) &StepToTopoDS_TranslateEdge::Error, "None");

// Enums

}