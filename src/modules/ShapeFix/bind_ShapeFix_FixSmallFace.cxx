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
#include <ShapeFix_Root.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Compound.hxx>
#include <Standard_Handle.hxx>
#include <ShapeFix_FixSmallFace.hxx>
#include <Standard_Type.hxx>
#include <ShapeAnalysis_CheckSmallFace.hxx>

void bind_ShapeFix_FixSmallFace(py::module &mod){

py::class_<ShapeFix_FixSmallFace, opencascade::handle<ShapeFix_FixSmallFace>, ShapeFix_Root> cls_ShapeFix_FixSmallFace(mod, "ShapeFix_FixSmallFace", "Fixing face with small size");

// Constructors
cls_ShapeFix_FixSmallFace.def(py::init<>());

// Fields

// Methods
cls_ShapeFix_FixSmallFace.def("Init", (void (ShapeFix_FixSmallFace::*)(const TopoDS_Shape &)) &ShapeFix_FixSmallFace::Init, "None", py::arg("S"));
cls_ShapeFix_FixSmallFace.def("Perform", (void (ShapeFix_FixSmallFace::*)()) &ShapeFix_FixSmallFace::Perform, "Fixing case of spot face");
cls_ShapeFix_FixSmallFace.def("FixSpotFace", (TopoDS_Shape (ShapeFix_FixSmallFace::*)()) &ShapeFix_FixSmallFace::FixSpotFace, "Fixing case of spot face, if tol = -1 used local tolerance.");
cls_ShapeFix_FixSmallFace.def("ReplaceVerticesInCaseOfSpot", (Standard_Boolean (ShapeFix_FixSmallFace::*)(TopoDS_Face &, const Standard_Real) const) &ShapeFix_FixSmallFace::ReplaceVerticesInCaseOfSpot, "Compute average vertex and replacing vertices by new one.", py::arg("F"), py::arg("tol"));
cls_ShapeFix_FixSmallFace.def("RemoveFacesInCaseOfSpot", (Standard_Boolean (ShapeFix_FixSmallFace::*)(const TopoDS_Face &) const) &ShapeFix_FixSmallFace::RemoveFacesInCaseOfSpot, "Remove spot face from compound", py::arg("F"));
cls_ShapeFix_FixSmallFace.def("FixStripFace", [](ShapeFix_FixSmallFace &self) -> TopoDS_Shape { return self.FixStripFace(); });
cls_ShapeFix_FixSmallFace.def("FixStripFace", (TopoDS_Shape (ShapeFix_FixSmallFace::*)(const Standard_Boolean)) &ShapeFix_FixSmallFace::FixStripFace, "Fixing case of strip face, if tol = -1 used local tolerance", py::arg("wasdone"));
cls_ShapeFix_FixSmallFace.def("ReplaceInCaseOfStrip", (Standard_Boolean (ShapeFix_FixSmallFace::*)(TopoDS_Face &, TopoDS_Edge &, TopoDS_Edge &, const Standard_Real) const) &ShapeFix_FixSmallFace::ReplaceInCaseOfStrip, "Replace veretces and edges.", py::arg("F"), py::arg("E1"), py::arg("E2"), py::arg("tol"));
cls_ShapeFix_FixSmallFace.def("RemoveFacesInCaseOfStrip", (Standard_Boolean (ShapeFix_FixSmallFace::*)(const TopoDS_Face &) const) &ShapeFix_FixSmallFace::RemoveFacesInCaseOfStrip, "Remove strip face from compound.", py::arg("F"));
cls_ShapeFix_FixSmallFace.def("ComputeSharedEdgeForStripFace", (TopoDS_Edge (ShapeFix_FixSmallFace::*)(const TopoDS_Face &, const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Face &, const Standard_Real) const) &ShapeFix_FixSmallFace::ComputeSharedEdgeForStripFace, "Compute average edge for strip face", py::arg("F"), py::arg("E1"), py::arg("E2"), py::arg("F1"), py::arg("tol"));
cls_ShapeFix_FixSmallFace.def("FixSplitFace", (TopoDS_Shape (ShapeFix_FixSmallFace::*)(const TopoDS_Shape &)) &ShapeFix_FixSmallFace::FixSplitFace, "None", py::arg("S"));
cls_ShapeFix_FixSmallFace.def("SplitOneFace", (Standard_Boolean (ShapeFix_FixSmallFace::*)(TopoDS_Face &, TopoDS_Compound &)) &ShapeFix_FixSmallFace::SplitOneFace, "Compute data for face splitting.", py::arg("F"), py::arg("theSplittedFaces"));
cls_ShapeFix_FixSmallFace.def("FixFace", (TopoDS_Face (ShapeFix_FixSmallFace::*)(const TopoDS_Face &)) &ShapeFix_FixSmallFace::FixFace, "None", py::arg("F"));
cls_ShapeFix_FixSmallFace.def("FixShape", (TopoDS_Shape (ShapeFix_FixSmallFace::*)()) &ShapeFix_FixSmallFace::FixShape, "None");
cls_ShapeFix_FixSmallFace.def("Shape", (TopoDS_Shape (ShapeFix_FixSmallFace::*)()) &ShapeFix_FixSmallFace::Shape, "None");
cls_ShapeFix_FixSmallFace.def("FixPinFace", (Standard_Boolean (ShapeFix_FixSmallFace::*)(TopoDS_Face &)) &ShapeFix_FixSmallFace::FixPinFace, "None", py::arg("F"));
cls_ShapeFix_FixSmallFace.def_static("get_type_name_", (const char * (*)()) &ShapeFix_FixSmallFace::get_type_name, "None");
cls_ShapeFix_FixSmallFace.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeFix_FixSmallFace::get_type_descriptor, "None");
cls_ShapeFix_FixSmallFace.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeFix_FixSmallFace::*)() const) &ShapeFix_FixSmallFace::DynamicType, "None");

// Enums

}