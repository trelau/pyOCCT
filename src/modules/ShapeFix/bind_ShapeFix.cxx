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
#include <Message_ProgressIndicator.hxx>
#include <ShapeExtend_BasicMsgRegistrator.hxx>
#include <ShapeBuild_ReShape.hxx>
#include <ShapeFix_Root.hxx>
#include <ShapeFix_EdgeProjAux.hxx>
#include <ShapeFix_Edge.hxx>
#include <ShapeFix_Wire.hxx>
#include <ShapeFix_Face.hxx>
#include <ShapeFix_FixSmallFace.hxx>
#include <ShapeFix_FixSmallSolid.hxx>
#include <ShapeFix_WireVertex.hxx>
#include <ShapeFix_Wireframe.hxx>
#include <ShapeFix_FreeBounds.hxx>
#include <ShapeFix_FaceConnect.hxx>
#include <ShapeFix_Shell.hxx>
#include <ShapeFix_Solid.hxx>
#include <ShapeFix_ShapeTolerance.hxx>
#include <ShapeFix_Shape.hxx>
#include <ShapeFix_EdgeConnect.hxx>
#include <ShapeFix_ComposeShell.hxx>
#include <ShapeFix_SplitCommonVertex.hxx>
#include <ShapeFix_WireSegment.hxx>
#include <ShapeFix_IntersectionTool.hxx>
#include <ShapeFix_SplitTool.hxx>
#include <ShapeFix.hxx>

void bind_ShapeFix(py::module &mod){

py::class_<ShapeFix> cls_ShapeFix(mod, "ShapeFix", "This package provides algorithms for fixing problematic (violating Open CASCADE requirements) shapes. Tools from package ShapeAnalysis are used for detecting the problems. The detecting and fixing is done taking in account various criteria implemented in BRepCheck package. Each class of package ShapeFix deals with one certain type of shapes or with some family of problems.");

// Constructors

// Fields

// Methods
// cls_ShapeFix.def_static("operator new_", (void * (*)(size_t)) &ShapeFix::operator new, "None", py::arg("theSize"));
// cls_ShapeFix.def_static("operator delete_", (void (*)(void *)) &ShapeFix::operator delete, "None", py::arg("theAddress"));
// cls_ShapeFix.def_static("operator new[]_", (void * (*)(size_t)) &ShapeFix::operator new[], "None", py::arg("theSize"));
// cls_ShapeFix.def_static("operator delete[]_", (void (*)(void *)) &ShapeFix::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeFix.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeFix::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeFix.def_static("operator delete_", (void (*)(void *, void *)) &ShapeFix::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeFix.def_static("SameParameter_", [](const TopoDS_Shape & a0, const Standard_Boolean a1) -> Standard_Boolean { return ShapeFix::SameParameter(a0, a1); });
cls_ShapeFix.def_static("SameParameter_", [](const TopoDS_Shape & a0, const Standard_Boolean a1, const Standard_Real a2) -> Standard_Boolean { return ShapeFix::SameParameter(a0, a1, a2); });
cls_ShapeFix.def_static("SameParameter_", [](const TopoDS_Shape & a0, const Standard_Boolean a1, const Standard_Real a2, const opencascade::handle<Message_ProgressIndicator> & a3) -> Standard_Boolean { return ShapeFix::SameParameter(a0, a1, a2, a3); });
cls_ShapeFix.def_static("SameParameter_", (Standard_Boolean (*)(const TopoDS_Shape &, const Standard_Boolean, const Standard_Real, const opencascade::handle<Message_ProgressIndicator> &, const opencascade::handle<ShapeExtend_BasicMsgRegistrator> &)) &ShapeFix::SameParameter, "Runs SameParameter from BRepLib with these adaptations : <enforce> forces computations, else they are made only on Edges with flag SameParameter false <preci>, if not precised, is taken for each EDge as its own Tolerance Returns True when done, False if an exception has been raised In case of exception anyway, as many edges as possible have been processed. The passed progress indicator allows user to consult the current progress stage and abort algorithm if needed.", py::arg("shape"), py::arg("enforce"), py::arg("preci"), py::arg("theProgress"), py::arg("theMsgReg"));
cls_ShapeFix.def_static("EncodeRegularity_", [](const TopoDS_Shape & a0) -> void { return ShapeFix::EncodeRegularity(a0); });
cls_ShapeFix.def_static("EncodeRegularity_", (void (*)(const TopoDS_Shape &, const Standard_Real)) &ShapeFix::EncodeRegularity, "Runs EncodeRegularity from BRepLib taking into account shared components of assemblies, so that each component is processed only once", py::arg("shape"), py::arg("tolang"));
cls_ShapeFix.def_static("RemoveSmallEdges_", (TopoDS_Shape (*)(TopoDS_Shape &, const Standard_Real, opencascade::handle<ShapeBuild_ReShape> &)) &ShapeFix::RemoveSmallEdges, "Removes edges which are less than given tolerance from shape with help of ShapeFix_Wire::FixSmall()", py::arg("shape"), py::arg("Tolerance"), py::arg("context"));
cls_ShapeFix.def_static("FixVertexPosition_", (Standard_Boolean (*)(TopoDS_Shape &, const Standard_Real, const opencascade::handle<ShapeBuild_ReShape> &)) &ShapeFix::FixVertexPosition, "Fix position of the vertices having tolerance more tnan specified one.;", py::arg("theshape"), py::arg("theTolerance"), py::arg("thecontext"));
cls_ShapeFix.def_static("LeastEdgeSize_", (Standard_Real (*)(TopoDS_Shape &)) &ShapeFix::LeastEdgeSize, "Calculate size of least edge;", py::arg("theshape"));

// Enums

}