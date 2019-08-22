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
#include <TopoDS_Wire.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Shape.hxx>
#include <TColgp_SequenceOfPnt.hxx>
#include <LocOpe_SplitShape.hxx>
#include <LocOpe_WiresOnShape.hxx>
#include <LocOpe_Spliter.hxx>
#include <LocOpe_Generator.hxx>
#include <LocOpe_GeneratedShape.hxx>
#include <LocOpe_GluedShape.hxx>
#include <LocOpe_Prism.hxx>
#include <LocOpe_Revol.hxx>
#include <LocOpe_Pipe.hxx>
#include <LocOpe_DPrism.hxx>
#include <LocOpe_LinearForm.hxx>
#include <LocOpe_RevolutionForm.hxx>
#include <LocOpe_Gluer.hxx>
#include <LocOpe_FindEdges.hxx>
#include <LocOpe_FindEdgesInFace.hxx>
#include <LocOpe_PntFace.hxx>
#include <LocOpe_CurveShapeIntersector.hxx>
#include <LocOpe_CSIntersector.hxx>
#include <LocOpe_BuildShape.hxx>
#include <LocOpe_SplitDrafts.hxx>
#include <LocOpe_BuildWires.hxx>
#include <LocOpe.hxx>

void bind_LocOpe(py::module &mod){

py::class_<LocOpe> cls_LocOpe(mod, "LocOpe", "Provides tools to implement local topological operations on a shape.");

// Constructors

// Fields

// Methods
// cls_LocOpe.def_static("operator new_", (void * (*)(size_t)) &LocOpe::operator new, "None", py::arg("theSize"));
// cls_LocOpe.def_static("operator delete_", (void (*)(void *)) &LocOpe::operator delete, "None", py::arg("theAddress"));
// cls_LocOpe.def_static("operator new[]_", (void * (*)(size_t)) &LocOpe::operator new[], "None", py::arg("theSize"));
// cls_LocOpe.def_static("operator delete[]_", (void (*)(void *)) &LocOpe::operator delete[], "None", py::arg("theAddress"));
// cls_LocOpe.def_static("operator new_", (void * (*)(size_t, void *)) &LocOpe::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocOpe.def_static("operator delete_", (void (*)(void *, void *)) &LocOpe::operator delete, "None", py::arg(""), py::arg(""));
cls_LocOpe.def_static("Closed_", (Standard_Boolean (*)(const TopoDS_Wire &, const TopoDS_Face &)) &LocOpe::Closed, "Returns Standard_True when the wire <W> is closed on the face <OnF>.", py::arg("W"), py::arg("OnF"));
cls_LocOpe.def_static("Closed_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Face &)) &LocOpe::Closed, "Returns Standard_True when the edge <E> is closed on the face <OnF>.", py::arg("E"), py::arg("OnF"));
cls_LocOpe.def_static("TgtFaces_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &)) &LocOpe::TgtFaces, "Returns Standard_True when the faces are tangent", py::arg("E"), py::arg("F1"), py::arg("F2"));
cls_LocOpe.def_static("SampleEdges_", (void (*)(const TopoDS_Shape &, TColgp_SequenceOfPnt &)) &LocOpe::SampleEdges, "None", py::arg("S"), py::arg("Pt"));

// Enums

}