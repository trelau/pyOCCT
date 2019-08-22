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
#include <TopoDS_Edge.hxx>
#include <IntTools_SequenceOfRoots.hxx>
#include <gp_Pnt.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <IntTools_CArray1OfReal.hxx>
#include <IntTools_Context.hxx>
#include <IntTools_ShrunkRange.hxx>
#include <IntTools_Range.hxx>
#include <IntTools_CommonPrt.hxx>
#include <IntTools_Root.hxx>
#include <IntTools_EdgeEdge.hxx>
#include <IntTools_EdgeFace.hxx>
#include <IntTools_FClass2d.hxx>
#include <IntTools_MarkedRangeSet.hxx>
#include <IntTools_BaseRangeSample.hxx>
#include <IntTools_CurveRangeSample.hxx>
#include <IntTools_SurfaceRangeSample.hxx>
#include <IntTools_CurveRangeLocalizeData.hxx>
#include <IntTools_SurfaceRangeLocalizeData.hxx>
#include <IntTools_BeanFaceIntersector.hxx>
#include <IntTools_Curve.hxx>
#include <IntTools_PntOnFace.hxx>
#include <IntTools_PntOn2Faces.hxx>
#include <IntTools_TopolTool.hxx>
#include <IntTools_FaceFace.hxx>
#include <IntTools_Tools.hxx>
#include <IntTools_CArray1OfInteger.hxx>
#include <IntTools_CurveRangeSampleMapHasher.hxx>
#include <IntTools_SurfaceRangeSampleMapHasher.hxx>
#include <IntTools.hxx>

void bind_IntTools(py::module &mod){

py::class_<IntTools> cls_IntTools(mod, "IntTools", "Contains classes for intersection and classification purposes and accompanying classes");

// Constructors

// Fields

// Methods
// cls_IntTools.def_static("operator new_", (void * (*)(size_t)) &IntTools::operator new, "None", py::arg("theSize"));
// cls_IntTools.def_static("operator delete_", (void (*)(void *)) &IntTools::operator delete, "None", py::arg("theAddress"));
// cls_IntTools.def_static("operator new[]_", (void * (*)(size_t)) &IntTools::operator new[], "None", py::arg("theSize"));
// cls_IntTools.def_static("operator delete[]_", (void (*)(void *)) &IntTools::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools.def_static("operator delete_", (void (*)(void *, void *)) &IntTools::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools.def_static("Length_", (Standard_Real (*)(const TopoDS_Edge &)) &IntTools::Length, "returns the length of the edge;", py::arg("E"));
cls_IntTools.def_static("RemoveIdenticalRoots_", (void (*)(IntTools_SequenceOfRoots &, const Standard_Real)) &IntTools::RemoveIdenticalRoots, "Remove from the sequence aSeq the Roots that have values ti and tj such as |ti-tj] < anEpsT.", py::arg("aSeq"), py::arg("anEpsT"));
cls_IntTools.def_static("SortRoots_", (void (*)(IntTools_SequenceOfRoots &, const Standard_Real)) &IntTools::SortRoots, "Sort the sequence aSeq of the Roots to arrange the Roons in increasing order", py::arg("aSeq"), py::arg("anEpsT"));
cls_IntTools.def_static("FindRootStates_", (void (*)(IntTools_SequenceOfRoots &, const Standard_Real)) &IntTools::FindRootStates, "Find the states (before and after) for each Root from the sequence aSeq", py::arg("aSeq"), py::arg("anEpsNull"));
cls_IntTools.def_static("Parameter_", [](const gp_Pnt & P, const opencascade::handle<Geom_Curve> & Curve, Standard_Real & aParm){ Standard_Integer rv = IntTools::Parameter(P, Curve, aParm); return std::tuple<Standard_Integer, Standard_Real &>(rv, aParm); }, "None", py::arg("P"), py::arg("Curve"), py::arg("aParm"));
cls_IntTools.def_static("GetRadius_", [](const BRepAdaptor_Curve & C, const Standard_Real t1, const Standard_Real t3, Standard_Real & R){ Standard_Integer rv = IntTools::GetRadius(C, t1, t3, R); return std::tuple<Standard_Integer, Standard_Real &>(rv, R); }, "None", py::arg("C"), py::arg("t1"), py::arg("t3"), py::arg("R"));
cls_IntTools.def_static("PrepareArgs_", (Standard_Integer (*)(BRepAdaptor_Curve &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real, IntTools_CArray1OfReal &)) &IntTools::PrepareArgs, "None", py::arg("C"), py::arg("tMax"), py::arg("tMin"), py::arg("Discret"), py::arg("Deflect"), py::arg("anArgs"));

// Enums

}