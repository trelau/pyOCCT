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
#include <GeomAbs_Shape.hxx>
#include <TopoDS_Edge.hxx>
#include <Standard_Handle.hxx>
#include <ChFiDS_Spine.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <Geom_Surface.hxx>
#include <ChFiDS_ErrorStatus.hxx>
#include <TopOpeBRepBuild_HBuilder.hxx>
#include <ChFiDS_SurfData.hxx>
#include <ChFiDS_SequenceOfSurfData.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor3d_TopolTool.hxx>
#include <ChFiDS_HElSpine.hxx>
#include <BRepAdaptor_HSurface.hxx>
#include <math_Vector.hxx>
#include <BRepAdaptor_HCurve2d.hxx>
#include <TopAbs_Orientation.hxx>
#include <BRepBlend_Line.hxx>
#include <Blend_Function.hxx>
#include <Blend_FuncInv.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <Blend_SurfRstFunction.hxx>
#include <Blend_SurfPointFuncInv.hxx>
#include <Blend_SurfCurvFuncInv.hxx>
#include <Blend_RstRstFunction.hxx>
#include <Blend_CurvPointFuncInv.hxx>
#include <ChFiDS_Stripe.hxx>
#include <gp_Pnt2d.hxx>
#include <ChFiDS_ListOfStripe.hxx>
#include <TopAbs_State.hxx>
#include <ChFiDS_CommonPoint.hxx>
#include <TopoDS_Face.hxx>
#include <AppBlend_Approx.hxx>
#include <Geom2d_Curve.hxx>
#include <ChFiDS_Map.hxx>
#include <TopOpeBRepDS_HDataStructure.hxx>
#include <ChFiDS_StripeMap.hxx>
#include <ChFiDS_Regularities.hxx>
#include <TopTools_DataMapOfShapeListOfInteger.hxx>
#include <BRepTopAdaptor_TopolTool.hxx>
#include <ChFi3d_Builder.hxx>

void bind_ChFi3d_Builder(py::module &mod){

py::class_<ChFi3d_Builder, std::unique_ptr<ChFi3d_Builder, Deleter<ChFi3d_Builder>>> cls_ChFi3d_Builder(mod, "ChFi3d_Builder", "Root class for calculation of surfaces (fillets, chamfers) destined to smooth edges of a gap on a Shape and the reconstruction of the Shape.");

// Fields

// Methods
// cls_ChFi3d_Builder.def_static("operator new_", (void * (*)(size_t)) &ChFi3d_Builder::operator new, "None", py::arg("theSize"));
// cls_ChFi3d_Builder.def_static("operator delete_", (void (*)(void *)) &ChFi3d_Builder::operator delete, "None", py::arg("theAddress"));
// cls_ChFi3d_Builder.def_static("operator new[]_", (void * (*)(size_t)) &ChFi3d_Builder::operator new[], "None", py::arg("theSize"));
// cls_ChFi3d_Builder.def_static("operator delete[]_", (void (*)(void *)) &ChFi3d_Builder::operator delete[], "None", py::arg("theAddress"));
// cls_ChFi3d_Builder.def_static("operator new_", (void * (*)(size_t, void *)) &ChFi3d_Builder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ChFi3d_Builder.def_static("operator delete_", (void (*)(void *, void *)) &ChFi3d_Builder::operator delete, "None", py::arg(""), py::arg(""));
cls_ChFi3d_Builder.def("SetParams", (void (ChFi3d_Builder::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &ChFi3d_Builder::SetParams, "None", py::arg("Tang"), py::arg("Tesp"), py::arg("T2d"), py::arg("TApp3d"), py::arg("TolApp2d"), py::arg("Fleche"));
cls_ChFi3d_Builder.def("SetContinuity", (void (ChFi3d_Builder::*)(const GeomAbs_Shape, const Standard_Real)) &ChFi3d_Builder::SetContinuity, "None", py::arg("InternalContinuity"), py::arg("AngularTolerance"));
cls_ChFi3d_Builder.def("Remove", (void (ChFi3d_Builder::*)(const TopoDS_Edge &)) &ChFi3d_Builder::Remove, "extracts from the list the contour containing edge E.", py::arg("E"));
cls_ChFi3d_Builder.def("Contains", (Standard_Integer (ChFi3d_Builder::*)(const TopoDS_Edge &) const) &ChFi3d_Builder::Contains, "gives the number of the contour containing E or 0 if E does not belong to any contour.", py::arg("E"));
cls_ChFi3d_Builder.def("Contains", [](ChFi3d_Builder &self, const TopoDS_Edge & E, Standard_Integer & IndexInSpine){ Standard_Integer rv = self.Contains(E, IndexInSpine); return std::tuple<Standard_Integer, Standard_Integer &>(rv, IndexInSpine); }, "gives the number of the contour containing E or 0 if E does not belong to any contour. Sets in IndexInSpine the index of E in the contour if it's found", py::arg("E"), py::arg("IndexInSpine"));
cls_ChFi3d_Builder.def("NbElements", (Standard_Integer (ChFi3d_Builder::*)() const) &ChFi3d_Builder::NbElements, "gives the number of disjoint contours on which the fillets are calculated");
cls_ChFi3d_Builder.def("Value", (opencascade::handle<ChFiDS_Spine> (ChFi3d_Builder::*)(const Standard_Integer) const) &ChFi3d_Builder::Value, "gives the n'th set of edges (contour) if I >NbElements()", py::arg("I"));
cls_ChFi3d_Builder.def("Length", (Standard_Real (ChFi3d_Builder::*)(const Standard_Integer) const) &ChFi3d_Builder::Length, "returns the length of the contour of index IC.", py::arg("IC"));
cls_ChFi3d_Builder.def("FirstVertex", (TopoDS_Vertex (ChFi3d_Builder::*)(const Standard_Integer) const) &ChFi3d_Builder::FirstVertex, "returns the First vertex V of the contour of index IC.", py::arg("IC"));
cls_ChFi3d_Builder.def("LastVertex", (TopoDS_Vertex (ChFi3d_Builder::*)(const Standard_Integer) const) &ChFi3d_Builder::LastVertex, "returns the Last vertex V of the contour of index IC.", py::arg("IC"));
cls_ChFi3d_Builder.def("Abscissa", (Standard_Real (ChFi3d_Builder::*)(const Standard_Integer, const TopoDS_Vertex &) const) &ChFi3d_Builder::Abscissa, "returns the abscissa of the vertex V on the contour of index IC.", py::arg("IC"), py::arg("V"));
cls_ChFi3d_Builder.def("RelativeAbscissa", (Standard_Real (ChFi3d_Builder::*)(const Standard_Integer, const TopoDS_Vertex &) const) &ChFi3d_Builder::RelativeAbscissa, "returns the relative abscissa([0.,1.]) of the vertex V on the contour of index IC.", py::arg("IC"), py::arg("V"));
cls_ChFi3d_Builder.def("ClosedAndTangent", (Standard_Boolean (ChFi3d_Builder::*)(const Standard_Integer) const) &ChFi3d_Builder::ClosedAndTangent, "returns true if the contour of index IC is closed an tangent.", py::arg("IC"));
cls_ChFi3d_Builder.def("Closed", (Standard_Boolean (ChFi3d_Builder::*)(const Standard_Integer) const) &ChFi3d_Builder::Closed, "returns true if the contour of index IC is closed", py::arg("IC"));
cls_ChFi3d_Builder.def("Compute", (void (ChFi3d_Builder::*)()) &ChFi3d_Builder::Compute, "general calculation of geometry on all edges, topologic reconstruction.");
cls_ChFi3d_Builder.def("IsDone", (Standard_Boolean (ChFi3d_Builder::*)() const) &ChFi3d_Builder::IsDone, "returns True if the computation is success");
cls_ChFi3d_Builder.def("Shape", (TopoDS_Shape (ChFi3d_Builder::*)() const) &ChFi3d_Builder::Shape, "if (Isdone()) makes the result. if (!Isdone())");
cls_ChFi3d_Builder.def("Generated", (const TopTools_ListOfShape & (ChFi3d_Builder::*)(const TopoDS_Shape &)) &ChFi3d_Builder::Generated, "Advanced function for the history", py::arg("EouV"));
cls_ChFi3d_Builder.def("NbFaultyContours", (Standard_Integer (ChFi3d_Builder::*)() const) &ChFi3d_Builder::NbFaultyContours, "Returns the number of contours on which the calculation has failed.");
cls_ChFi3d_Builder.def("FaultyContour", (Standard_Integer (ChFi3d_Builder::*)(const Standard_Integer) const) &ChFi3d_Builder::FaultyContour, "Returns the number of I'th contour on which the calculation has failed.", py::arg("I"));
cls_ChFi3d_Builder.def("NbComputedSurfaces", (Standard_Integer (ChFi3d_Builder::*)(const Standard_Integer) const) &ChFi3d_Builder::NbComputedSurfaces, "Returns the number of surfaces calculated on the contour IC.", py::arg("IC"));
cls_ChFi3d_Builder.def("ComputedSurface", (opencascade::handle<Geom_Surface> (ChFi3d_Builder::*)(const Standard_Integer, const Standard_Integer) const) &ChFi3d_Builder::ComputedSurface, "Returns the IS'th surface calculated on the contour IC.", py::arg("IC"), py::arg("IS"));
cls_ChFi3d_Builder.def("NbFaultyVertices", (Standard_Integer (ChFi3d_Builder::*)() const) &ChFi3d_Builder::NbFaultyVertices, "Returns the number of vertices on which the calculation has failed.");
cls_ChFi3d_Builder.def("FaultyVertex", (TopoDS_Vertex (ChFi3d_Builder::*)(const Standard_Integer) const) &ChFi3d_Builder::FaultyVertex, "Returns the IV'th vertex on which the calculation has failed.", py::arg("IV"));
cls_ChFi3d_Builder.def("HasResult", (Standard_Boolean (ChFi3d_Builder::*)() const) &ChFi3d_Builder::HasResult, "returns True if a partial result has been calculated");
cls_ChFi3d_Builder.def("BadShape", (TopoDS_Shape (ChFi3d_Builder::*)() const) &ChFi3d_Builder::BadShape, "if (HasResult()) returns partial result if (!HasResult())");
cls_ChFi3d_Builder.def("StripeStatus", (ChFiDS_ErrorStatus (ChFi3d_Builder::*)(const Standard_Integer) const) &ChFi3d_Builder::StripeStatus, "for the stripe IC ,indication on the cause of failure WalkingFailure,TwistedSurface,Error, Ok", py::arg("IC"));
cls_ChFi3d_Builder.def("Reset", (void (ChFi3d_Builder::*)()) &ChFi3d_Builder::Reset, "Reset all results of compute and returns the algorythm in the state of the last acquisition to enable modification of contours or areas.");
cls_ChFi3d_Builder.def("Builder", (opencascade::handle<TopOpeBRepBuild_HBuilder> (ChFi3d_Builder::*)() const) &ChFi3d_Builder::Builder, "Returns the Builder of topologic operations.");
cls_ChFi3d_Builder.def("SplitKPart", [](ChFi3d_Builder &self, const opencascade::handle<ChFiDS_SurfData> & Data, ChFiDS_SequenceOfSurfData & SetData, const opencascade::handle<ChFiDS_Spine> & Spine, const Standard_Integer Iedge, const opencascade::handle<Adaptor3d_HSurface> & S1, const opencascade::handle<Adaptor3d_TopolTool> & I1, const opencascade::handle<Adaptor3d_HSurface> & S2, const opencascade::handle<Adaptor3d_TopolTool> & I2, Standard_Boolean & Intf, Standard_Boolean & Intl){ Standard_Boolean rv = self.SplitKPart(Data, SetData, Spine, Iedge, S1, I1, S2, I2, Intf, Intl); return std::tuple<Standard_Boolean, Standard_Boolean &, Standard_Boolean &>(rv, Intf, Intl); }, "Method, implemented in the inheritants, calculates the elements of construction of the surface (fillet or chamfer).", py::arg("Data"), py::arg("SetData"), py::arg("Spine"), py::arg("Iedge"), py::arg("S1"), py::arg("I1"), py::arg("S2"), py::arg("I2"), py::arg("Intf"), py::arg("Intl"));
cls_ChFi3d_Builder.def("PerformTwoCornerbyInter", (Standard_Boolean (ChFi3d_Builder::*)(const Standard_Integer)) &ChFi3d_Builder::PerformTwoCornerbyInter, "None", py::arg("Index"));

// Enums

}