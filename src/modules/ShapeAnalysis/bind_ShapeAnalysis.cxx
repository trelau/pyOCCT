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
#include <TopoDS_Wire.hxx>
#include <TopoDS_Face.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <ShapeExtend_WireData.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Vertex.hxx>
#include <ShapeAnalysis_Geom.hxx>
#include <ShapeAnalysis_Curve.hxx>
#include <ShapeAnalysis_Surface.hxx>
#include <ShapeAnalysis_Edge.hxx>
#include <ShapeAnalysis_Wire.hxx>
#include <ShapeAnalysis_WireOrder.hxx>
#include <ShapeAnalysis_WireVertex.hxx>
#include <ShapeAnalysis_CheckSmallFace.hxx>
#include <ShapeAnalysis_Shell.hxx>
#include <ShapeAnalysis_ShapeTolerance.hxx>
#include <ShapeAnalysis_ShapeContents.hxx>
#include <ShapeAnalysis_FreeBounds.hxx>
#include <ShapeAnalysis_FreeBoundData.hxx>
#include <ShapeAnalysis_FreeBoundsProperties.hxx>
#include <ShapeAnalysis_TransferParameters.hxx>
#include <ShapeAnalysis_TransferParametersProj.hxx>
#include <ShapeAnalysis.hxx>

void bind_ShapeAnalysis(py::module &mod){

py::class_<ShapeAnalysis> cls_ShapeAnalysis(mod, "ShapeAnalysis", "This package is intended to analyze geometrical objects and topological shapes. Analysis domain includes both exploring geometrical and topological properties of shapes and checking their conformance to Open CASCADE requirements. The directions of analysis provided by tools of this package are: computing quantities of subshapes, computing parameters of points on curve and surface, computing surface singularities, checking edge and wire consistency, checking edges order in the wire, checking face bounds orientation, checking small faces, analyzing shape tolerances, analyzing of free bounds of the shape.");

// Constructors

// Fields

// Methods
// cls_ShapeAnalysis.def_static("operator new_", (void * (*)(size_t)) &ShapeAnalysis::operator new, "None", py::arg("theSize"));
// cls_ShapeAnalysis.def_static("operator delete_", (void (*)(void *)) &ShapeAnalysis::operator delete, "None", py::arg("theAddress"));
// cls_ShapeAnalysis.def_static("operator new[]_", (void * (*)(size_t)) &ShapeAnalysis::operator new[], "None", py::arg("theSize"));
// cls_ShapeAnalysis.def_static("operator delete[]_", (void (*)(void *)) &ShapeAnalysis::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeAnalysis.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeAnalysis::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeAnalysis.def_static("operator delete_", (void (*)(void *, void *)) &ShapeAnalysis::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeAnalysis.def_static("OuterWire_", (TopoDS_Wire (*)(const TopoDS_Face &)) &ShapeAnalysis::OuterWire, "Returns the outer wire on the face <Face>. This is replacement of the method BRepTools::OuterWire until it works badly. Returns the first wire oriented as outer according to FClass2d_Classifier. If none, last wire is returned.", py::arg("face"));
cls_ShapeAnalysis.def_static("TotCross2D_", (Standard_Real (*)(const opencascade::handle<ShapeExtend_WireData> &, const TopoDS_Face &)) &ShapeAnalysis::TotCross2D, "Returns a total area of 2d wire", py::arg("sewd"), py::arg("aFace"));
cls_ShapeAnalysis.def_static("ContourArea_", (Standard_Real (*)(const TopoDS_Wire &)) &ShapeAnalysis::ContourArea, "Returns a total area of 3d wire", py::arg("theWire"));
cls_ShapeAnalysis.def_static("IsOuterBound_", (Standard_Boolean (*)(const TopoDS_Face &)) &ShapeAnalysis::IsOuterBound, "Returns True if <F> has outer bound.", py::arg("face"));
cls_ShapeAnalysis.def_static("AdjustByPeriod_", (Standard_Real (*)(const Standard_Real, const Standard_Real, const Standard_Real)) &ShapeAnalysis::AdjustByPeriod, "Returns a shift required to move point <Val> to the range [ToVal-Period/2,ToVal+Period/2]. This shift will be the divisible by Period. Intended for adjusting parameters on periodic surfaces.", py::arg("Val"), py::arg("ToVal"), py::arg("Period"));
cls_ShapeAnalysis.def_static("AdjustToPeriod_", (Standard_Real (*)(const Standard_Real, const Standard_Real, const Standard_Real)) &ShapeAnalysis::AdjustToPeriod, "Returns a shift required to move point <Val> to the range [ValMin,ValMax]. This shift will be the divisible by Period with Period = ValMax - ValMin. Intended for adjusting parameters on periodic surfaces.", py::arg("Val"), py::arg("ValMin"), py::arg("ValMax"));
cls_ShapeAnalysis.def_static("FindBounds_", (void (*)(const TopoDS_Shape &, TopoDS_Vertex &, TopoDS_Vertex &)) &ShapeAnalysis::FindBounds, "Finds the start and end vertices of the shape Shape can be of the following type: vertex: V1 and V2 are the same and equal to <shape>, edge : V1 is start and V2 is end vertex (see ShapeAnalysis_Edge methods FirstVertex and LastVertex), wire : V1 is start vertex of the first edge, V2 is end vertex of the last edge (also see ShapeAnalysis_Edge). If wire contains no edges V1 and V2 are nullified If none of the above V1 and V2 are nullified", py::arg("shape"), py::arg("V1"), py::arg("V2"));
cls_ShapeAnalysis.def_static("GetFaceUVBounds_", [](const TopoDS_Face & F, Standard_Real & Umin, Standard_Real & Umax, Standard_Real & Vmin, Standard_Real & Vmax){ ShapeAnalysis::GetFaceUVBounds(F, Umin, Umax, Vmin, Vmax); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(Umin, Umax, Vmin, Vmax); }, "Computes exact UV bounds of all wires on the face", py::arg("F"), py::arg("Umin"), py::arg("Umax"), py::arg("Vmin"), py::arg("Vmax"));

// Enums

}