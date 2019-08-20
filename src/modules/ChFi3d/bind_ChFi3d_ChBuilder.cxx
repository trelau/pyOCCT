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
#include <ChFi3d_Builder.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <ChFiDS_ChamfMethod.hxx>
#include <Standard_Handle.hxx>
#include <ChFiDS_SecHArray1.hxx>
#include <ChFiDS_SurfData.hxx>
#include <ChFiDS_HElSpine.hxx>
#include <ChFiDS_Spine.hxx>
#include <BRepAdaptor_HSurface.hxx>
#include <Adaptor3d_TopolTool.hxx>
#include <BRepAdaptor_HCurve2d.hxx>
#include <TopAbs_Orientation.hxx>
#include <math_Vector.hxx>
#include <ChFiDS_SequenceOfSurfData.hxx>
#include <TopAbs_State.hxx>
#include <TopoDS_Vertex.hxx>
#include <ChFiDS_Stripe.hxx>
#include <ChFiDS_ListOfStripe.hxx>
#include <ChFi3d_ChBuilder.hxx>

void bind_ChFi3d_ChBuilder(py::module &mod){

py::class_<ChFi3d_ChBuilder, std::unique_ptr<ChFi3d_ChBuilder>, ChFi3d_Builder> cls_ChFi3d_ChBuilder(mod, "ChFi3d_ChBuilder", "construction tool for 3D chamfers on edges (on a solid).");

// Constructors
cls_ChFi3d_ChBuilder.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
cls_ChFi3d_ChBuilder.def(py::init<const TopoDS_Shape &, const Standard_Real>(), py::arg("S"), py::arg("Ta"));

// Fields

// Methods
// cls_ChFi3d_ChBuilder.def_static("operator new_", (void * (*)(size_t)) &ChFi3d_ChBuilder::operator new, "None", py::arg("theSize"));
// cls_ChFi3d_ChBuilder.def_static("operator delete_", (void (*)(void *)) &ChFi3d_ChBuilder::operator delete, "None", py::arg("theAddress"));
// cls_ChFi3d_ChBuilder.def_static("operator new[]_", (void * (*)(size_t)) &ChFi3d_ChBuilder::operator new[], "None", py::arg("theSize"));
// cls_ChFi3d_ChBuilder.def_static("operator delete[]_", (void (*)(void *)) &ChFi3d_ChBuilder::operator delete[], "None", py::arg("theAddress"));
// cls_ChFi3d_ChBuilder.def_static("operator new_", (void * (*)(size_t, void *)) &ChFi3d_ChBuilder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ChFi3d_ChBuilder.def_static("operator delete_", (void (*)(void *, void *)) &ChFi3d_ChBuilder::operator delete, "None", py::arg(""), py::arg(""));
cls_ChFi3d_ChBuilder.def("Add", (void (ChFi3d_ChBuilder::*)(const TopoDS_Edge &)) &ChFi3d_ChBuilder::Add, "initializes a contour with the edge <E> as first (the next are found by propagation ). The two distances (parameters of the chamfer) must be set after. if the edge <E> has more than 2 adjacent faces", py::arg("E"));
cls_ChFi3d_ChBuilder.def("Add", (void (ChFi3d_ChBuilder::*)(const Standard_Real, const TopoDS_Edge &, const TopoDS_Face &)) &ChFi3d_ChBuilder::Add, "initializes a new contour with the edge <E> as first (the next are found by propagation ), and the distance <Dis> if the edge <E> has more than 2 adjacent faces", py::arg("Dis"), py::arg("E"), py::arg("F"));
cls_ChFi3d_ChBuilder.def("SetDist", (void (ChFi3d_ChBuilder::*)(const Standard_Real, const Standard_Integer, const TopoDS_Face &)) &ChFi3d_ChBuilder::SetDist, "set the distance <Dis> of the fillet contour of index <IC> in the DS with <Dis> on <F>. if the face <F> is not one of common faces of an edge of the contour <IC>", py::arg("Dis"), py::arg("IC"), py::arg("F"));
cls_ChFi3d_ChBuilder.def("GetDist", [](ChFi3d_ChBuilder &self, const Standard_Integer IC, Standard_Real & Dis){ self.GetDist(IC, Dis); return Dis; }, "gives the distances <Dis> of the fillet contour of index <IC> in the DS", py::arg("IC"), py::arg("Dis"));
cls_ChFi3d_ChBuilder.def("Add", (void (ChFi3d_ChBuilder::*)(const Standard_Real, const Standard_Real, const TopoDS_Edge &, const TopoDS_Face &)) &ChFi3d_ChBuilder::Add, "initializes a new contour with the edge <E> as first (the next are found by propagation ), and the distance <Dis1> and <Dis2> if the edge <E> has more than 2 adjacent faces", py::arg("Dis1"), py::arg("Dis2"), py::arg("E"), py::arg("F"));
cls_ChFi3d_ChBuilder.def("SetDists", (void (ChFi3d_ChBuilder::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const TopoDS_Face &)) &ChFi3d_ChBuilder::SetDists, "set the distances <Dis1> and <Dis2> of the fillet contour of index <IC> in the DS with <Dis1> on <F>. if the face <F> is not one of common faces of an edge of the contour <IC>", py::arg("Dis1"), py::arg("Dis2"), py::arg("IC"), py::arg("F"));
cls_ChFi3d_ChBuilder.def("Dists", [](ChFi3d_ChBuilder &self, const Standard_Integer IC, Standard_Real & Dis1, Standard_Real & Dis2){ self.Dists(IC, Dis1, Dis2); return std::tuple<Standard_Real &, Standard_Real &>(Dis1, Dis2); }, "gives the distances <Dis1> and <Dis2> of the fillet contour of index <IC> in the DS", py::arg("IC"), py::arg("Dis1"), py::arg("Dis2"));
cls_ChFi3d_ChBuilder.def("AddDA", (void (ChFi3d_ChBuilder::*)(const Standard_Real, const Standard_Real, const TopoDS_Edge &, const TopoDS_Face &)) &ChFi3d_ChBuilder::AddDA, "initializes a new contour with the edge <E> as first (the next are found by propagation ), and the distance <Dis1> and <Angle> if the edge <E> has more than 2 adjacent faces", py::arg("Dis"), py::arg("Angle"), py::arg("E"), py::arg("F"));
cls_ChFi3d_ChBuilder.def("SetDistAngle", (void (ChFi3d_ChBuilder::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const TopoDS_Face &)) &ChFi3d_ChBuilder::SetDistAngle, "set the distance <Dis> and <Angle> of the fillet contour of index <IC> in the DS with <Dis> on <F>. if the face <F> is not one of common faces of an edge of the contour <IC>", py::arg("Dis"), py::arg("Angle"), py::arg("IC"), py::arg("F"));
cls_ChFi3d_ChBuilder.def("GetDistAngle", [](ChFi3d_ChBuilder &self, const Standard_Integer IC, Standard_Real & Dis, Standard_Real & Angle, Standard_Boolean & DisOnFace1){ self.GetDistAngle(IC, Dis, Angle, DisOnFace1); return std::tuple<Standard_Real &, Standard_Real &, Standard_Boolean &>(Dis, Angle, DisOnFace1); }, "gives the distances <Dis> and <Angle> of the fillet contour of index <IC> in the DS", py::arg("IC"), py::arg("Dis"), py::arg("Angle"), py::arg("DisOnFace1"));
cls_ChFi3d_ChBuilder.def("IsChamfer", (ChFiDS_ChamfMethod (ChFi3d_ChBuilder::*)(const Standard_Integer) const) &ChFi3d_ChBuilder::IsChamfer, "renvoi la methode des chanfreins utilisee", py::arg("IC"));
cls_ChFi3d_ChBuilder.def("ResetContour", (void (ChFi3d_ChBuilder::*)(const Standard_Integer)) &ChFi3d_ChBuilder::ResetContour, "Reset tous rayons du contour IC.", py::arg("IC"));
cls_ChFi3d_ChBuilder.def("Simulate", (void (ChFi3d_ChBuilder::*)(const Standard_Integer)) &ChFi3d_ChBuilder::Simulate, "None", py::arg("IC"));
cls_ChFi3d_ChBuilder.def("NbSurf", (Standard_Integer (ChFi3d_ChBuilder::*)(const Standard_Integer) const) &ChFi3d_ChBuilder::NbSurf, "None", py::arg("IC"));
cls_ChFi3d_ChBuilder.def("Sect", (opencascade::handle<ChFiDS_SecHArray1> (ChFi3d_ChBuilder::*)(const Standard_Integer, const Standard_Integer) const) &ChFi3d_ChBuilder::Sect, "None", py::arg("IC"), py::arg("IS"));
cls_ChFi3d_ChBuilder.def("SimulSurf", [](ChFi3d_ChBuilder &self, opencascade::handle<ChFiDS_SurfData> & Data, const opencascade::handle<ChFiDS_HElSpine> & Guide, const opencascade::handle<ChFiDS_Spine> & Spine, const Standard_Integer Choix, const opencascade::handle<BRepAdaptor_HSurface> & S1, const opencascade::handle<Adaptor3d_TopolTool> & I1, const opencascade::handle<BRepAdaptor_HCurve2d> & PC1, const opencascade::handle<BRepAdaptor_HSurface> & Sref1, const opencascade::handle<BRepAdaptor_HCurve2d> & PCref1, Standard_Boolean & Decroch1, const opencascade::handle<BRepAdaptor_HSurface> & S2, const opencascade::handle<Adaptor3d_TopolTool> & I2, const TopAbs_Orientation Or2, const Standard_Real Fleche, const Standard_Real TolGuide, Standard_Real & First, Standard_Real & Last, const Standard_Boolean Inside, const Standard_Boolean Appro, const Standard_Boolean Forward, const Standard_Boolean RecP, const Standard_Boolean RecS, const Standard_Boolean RecRst, const math_Vector & Soldep){ self.SimulSurf(Data, Guide, Spine, Choix, S1, I1, PC1, Sref1, PCref1, Decroch1, S2, I2, Or2, Fleche, TolGuide, First, Last, Inside, Appro, Forward, RecP, RecS, RecRst, Soldep); return std::tuple<Standard_Boolean &, Standard_Real &, Standard_Real &>(Decroch1, First, Last); }, "None", py::arg("Data"), py::arg("Guide"), py::arg("Spine"), py::arg("Choix"), py::arg("S1"), py::arg("I1"), py::arg("PC1"), py::arg("Sref1"), py::arg("PCref1"), py::arg("Decroch1"), py::arg("S2"), py::arg("I2"), py::arg("Or2"), py::arg("Fleche"), py::arg("TolGuide"), py::arg("First"), py::arg("Last"), py::arg("Inside"), py::arg("Appro"), py::arg("Forward"), py::arg("RecP"), py::arg("RecS"), py::arg("RecRst"), py::arg("Soldep"));
cls_ChFi3d_ChBuilder.def("SimulSurf", [](ChFi3d_ChBuilder &self, opencascade::handle<ChFiDS_SurfData> & Data, const opencascade::handle<ChFiDS_HElSpine> & Guide, const opencascade::handle<ChFiDS_Spine> & Spine, const Standard_Integer Choix, const opencascade::handle<BRepAdaptor_HSurface> & S1, const opencascade::handle<Adaptor3d_TopolTool> & I1, const TopAbs_Orientation Or1, const opencascade::handle<BRepAdaptor_HSurface> & S2, const opencascade::handle<Adaptor3d_TopolTool> & I2, const opencascade::handle<BRepAdaptor_HCurve2d> & PC2, const opencascade::handle<BRepAdaptor_HSurface> & Sref2, const opencascade::handle<BRepAdaptor_HCurve2d> & PCref2, Standard_Boolean & Decroch2, const Standard_Real Fleche, const Standard_Real TolGuide, Standard_Real & First, Standard_Real & Last, const Standard_Boolean Inside, const Standard_Boolean Appro, const Standard_Boolean Forward, const Standard_Boolean RecP, const Standard_Boolean RecS, const Standard_Boolean RecRst, const math_Vector & Soldep){ self.SimulSurf(Data, Guide, Spine, Choix, S1, I1, Or1, S2, I2, PC2, Sref2, PCref2, Decroch2, Fleche, TolGuide, First, Last, Inside, Appro, Forward, RecP, RecS, RecRst, Soldep); return std::tuple<Standard_Boolean &, Standard_Real &, Standard_Real &>(Decroch2, First, Last); }, "None", py::arg("Data"), py::arg("Guide"), py::arg("Spine"), py::arg("Choix"), py::arg("S1"), py::arg("I1"), py::arg("Or1"), py::arg("S2"), py::arg("I2"), py::arg("PC2"), py::arg("Sref2"), py::arg("PCref2"), py::arg("Decroch2"), py::arg("Fleche"), py::arg("TolGuide"), py::arg("First"), py::arg("Last"), py::arg("Inside"), py::arg("Appro"), py::arg("Forward"), py::arg("RecP"), py::arg("RecS"), py::arg("RecRst"), py::arg("Soldep"));
cls_ChFi3d_ChBuilder.def("SimulSurf", [](ChFi3d_ChBuilder &self, opencascade::handle<ChFiDS_SurfData> & Data, const opencascade::handle<ChFiDS_HElSpine> & Guide, const opencascade::handle<ChFiDS_Spine> & Spine, const Standard_Integer Choix, const opencascade::handle<BRepAdaptor_HSurface> & S1, const opencascade::handle<Adaptor3d_TopolTool> & I1, const opencascade::handle<BRepAdaptor_HCurve2d> & PC1, const opencascade::handle<BRepAdaptor_HSurface> & Sref1, const opencascade::handle<BRepAdaptor_HCurve2d> & PCref1, Standard_Boolean & Decroch1, const TopAbs_Orientation Or1, const opencascade::handle<BRepAdaptor_HSurface> & S2, const opencascade::handle<Adaptor3d_TopolTool> & I2, const opencascade::handle<BRepAdaptor_HCurve2d> & PC2, const opencascade::handle<BRepAdaptor_HSurface> & Sref2, const opencascade::handle<BRepAdaptor_HCurve2d> & PCref2, Standard_Boolean & Decroch2, const TopAbs_Orientation Or2, const Standard_Real Fleche, const Standard_Real TolGuide, Standard_Real & First, Standard_Real & Last, const Standard_Boolean Inside, const Standard_Boolean Appro, const Standard_Boolean Forward, const Standard_Boolean RecP1, const Standard_Boolean RecRst1, const Standard_Boolean RecP2, const Standard_Boolean RecRst2, const math_Vector & Soldep){ self.SimulSurf(Data, Guide, Spine, Choix, S1, I1, PC1, Sref1, PCref1, Decroch1, Or1, S2, I2, PC2, Sref2, PCref2, Decroch2, Or2, Fleche, TolGuide, First, Last, Inside, Appro, Forward, RecP1, RecRst1, RecP2, RecRst2, Soldep); return std::tuple<Standard_Boolean &, Standard_Boolean &, Standard_Real &, Standard_Real &>(Decroch1, Decroch2, First, Last); }, "None", py::arg("Data"), py::arg("Guide"), py::arg("Spine"), py::arg("Choix"), py::arg("S1"), py::arg("I1"), py::arg("PC1"), py::arg("Sref1"), py::arg("PCref1"), py::arg("Decroch1"), py::arg("Or1"), py::arg("S2"), py::arg("I2"), py::arg("PC2"), py::arg("Sref2"), py::arg("PCref2"), py::arg("Decroch2"), py::arg("Or2"), py::arg("Fleche"), py::arg("TolGuide"), py::arg("First"), py::arg("Last"), py::arg("Inside"), py::arg("Appro"), py::arg("Forward"), py::arg("RecP1"), py::arg("RecRst1"), py::arg("RecP2"), py::arg("RecRst2"), py::arg("Soldep"));
cls_ChFi3d_ChBuilder.def("PerformSurf", [](ChFi3d_ChBuilder &self, ChFiDS_SequenceOfSurfData & Data, const opencascade::handle<ChFiDS_HElSpine> & Guide, const opencascade::handle<ChFiDS_Spine> & Spine, const Standard_Integer Choix, const opencascade::handle<BRepAdaptor_HSurface> & S1, const opencascade::handle<Adaptor3d_TopolTool> & I1, const opencascade::handle<BRepAdaptor_HSurface> & S2, const opencascade::handle<Adaptor3d_TopolTool> & I2, const Standard_Real MaxStep, const Standard_Real Fleche, const Standard_Real TolGuide, Standard_Real & First, Standard_Real & Last, const Standard_Boolean Inside, const Standard_Boolean Appro, const Standard_Boolean Forward, const Standard_Boolean RecOnS1, const Standard_Boolean RecOnS2, const math_Vector & Soldep, Standard_Integer & Intf, Standard_Integer & Intl){ Standard_Boolean rv = self.PerformSurf(Data, Guide, Spine, Choix, S1, I1, S2, I2, MaxStep, Fleche, TolGuide, First, Last, Inside, Appro, Forward, RecOnS1, RecOnS2, Soldep, Intf, Intl); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &, Standard_Integer &, Standard_Integer &>(rv, First, Last, Intf, Intl); }, "Methode, implemented in inheritants, calculates the elements of construction of the surface (fillet or chamfer).", py::arg("Data"), py::arg("Guide"), py::arg("Spine"), py::arg("Choix"), py::arg("S1"), py::arg("I1"), py::arg("S2"), py::arg("I2"), py::arg("MaxStep"), py::arg("Fleche"), py::arg("TolGuide"), py::arg("First"), py::arg("Last"), py::arg("Inside"), py::arg("Appro"), py::arg("Forward"), py::arg("RecOnS1"), py::arg("RecOnS2"), py::arg("Soldep"), py::arg("Intf"), py::arg("Intl"));
cls_ChFi3d_ChBuilder.def("PerformSurf", [](ChFi3d_ChBuilder &self, ChFiDS_SequenceOfSurfData & Data, const opencascade::handle<ChFiDS_HElSpine> & Guide, const opencascade::handle<ChFiDS_Spine> & Spine, const Standard_Integer Choix, const opencascade::handle<BRepAdaptor_HSurface> & S1, const opencascade::handle<Adaptor3d_TopolTool> & I1, const opencascade::handle<BRepAdaptor_HCurve2d> & PC1, const opencascade::handle<BRepAdaptor_HSurface> & Sref1, const opencascade::handle<BRepAdaptor_HCurve2d> & PCref1, Standard_Boolean & Decroch1, const opencascade::handle<BRepAdaptor_HSurface> & S2, const opencascade::handle<Adaptor3d_TopolTool> & I2, const TopAbs_Orientation Or2, const Standard_Real MaxStep, const Standard_Real Fleche, const Standard_Real TolGuide, Standard_Real & First, Standard_Real & Last, const Standard_Boolean Inside, const Standard_Boolean Appro, const Standard_Boolean Forward, const Standard_Boolean RecP, const Standard_Boolean RecS, const Standard_Boolean RecRst, const math_Vector & Soldep){ self.PerformSurf(Data, Guide, Spine, Choix, S1, I1, PC1, Sref1, PCref1, Decroch1, S2, I2, Or2, MaxStep, Fleche, TolGuide, First, Last, Inside, Appro, Forward, RecP, RecS, RecRst, Soldep); return std::tuple<Standard_Boolean &, Standard_Real &, Standard_Real &>(Decroch1, First, Last); }, "Method, implemented in the inheritants, calculates the elements of construction of the surface (fillet or chamfer) contact edge/face.", py::arg("Data"), py::arg("Guide"), py::arg("Spine"), py::arg("Choix"), py::arg("S1"), py::arg("I1"), py::arg("PC1"), py::arg("Sref1"), py::arg("PCref1"), py::arg("Decroch1"), py::arg("S2"), py::arg("I2"), py::arg("Or2"), py::arg("MaxStep"), py::arg("Fleche"), py::arg("TolGuide"), py::arg("First"), py::arg("Last"), py::arg("Inside"), py::arg("Appro"), py::arg("Forward"), py::arg("RecP"), py::arg("RecS"), py::arg("RecRst"), py::arg("Soldep"));
cls_ChFi3d_ChBuilder.def("PerformSurf", [](ChFi3d_ChBuilder &self, ChFiDS_SequenceOfSurfData & Data, const opencascade::handle<ChFiDS_HElSpine> & Guide, const opencascade::handle<ChFiDS_Spine> & Spine, const Standard_Integer Choix, const opencascade::handle<BRepAdaptor_HSurface> & S1, const opencascade::handle<Adaptor3d_TopolTool> & I1, const TopAbs_Orientation Or1, const opencascade::handle<BRepAdaptor_HSurface> & S2, const opencascade::handle<Adaptor3d_TopolTool> & I2, const opencascade::handle<BRepAdaptor_HCurve2d> & PC2, const opencascade::handle<BRepAdaptor_HSurface> & Sref2, const opencascade::handle<BRepAdaptor_HCurve2d> & PCref2, Standard_Boolean & Decroch2, const Standard_Real MaxStep, const Standard_Real Fleche, const Standard_Real TolGuide, Standard_Real & First, Standard_Real & Last, const Standard_Boolean Inside, const Standard_Boolean Appro, const Standard_Boolean Forward, const Standard_Boolean RecP, const Standard_Boolean RecS, const Standard_Boolean RecRst, const math_Vector & Soldep){ self.PerformSurf(Data, Guide, Spine, Choix, S1, I1, Or1, S2, I2, PC2, Sref2, PCref2, Decroch2, MaxStep, Fleche, TolGuide, First, Last, Inside, Appro, Forward, RecP, RecS, RecRst, Soldep); return std::tuple<Standard_Boolean &, Standard_Real &, Standard_Real &>(Decroch2, First, Last); }, "Method, implemented in inheritants, calculates the elements of construction of the surface (fillet or chamfer) contact edge/face.", py::arg("Data"), py::arg("Guide"), py::arg("Spine"), py::arg("Choix"), py::arg("S1"), py::arg("I1"), py::arg("Or1"), py::arg("S2"), py::arg("I2"), py::arg("PC2"), py::arg("Sref2"), py::arg("PCref2"), py::arg("Decroch2"), py::arg("MaxStep"), py::arg("Fleche"), py::arg("TolGuide"), py::arg("First"), py::arg("Last"), py::arg("Inside"), py::arg("Appro"), py::arg("Forward"), py::arg("RecP"), py::arg("RecS"), py::arg("RecRst"), py::arg("Soldep"));
cls_ChFi3d_ChBuilder.def("PerformSurf", [](ChFi3d_ChBuilder &self, ChFiDS_SequenceOfSurfData & Data, const opencascade::handle<ChFiDS_HElSpine> & Guide, const opencascade::handle<ChFiDS_Spine> & Spine, const Standard_Integer Choix, const opencascade::handle<BRepAdaptor_HSurface> & S1, const opencascade::handle<Adaptor3d_TopolTool> & I1, const opencascade::handle<BRepAdaptor_HCurve2d> & PC1, const opencascade::handle<BRepAdaptor_HSurface> & Sref1, const opencascade::handle<BRepAdaptor_HCurve2d> & PCref1, Standard_Boolean & Decroch1, const TopAbs_Orientation Or1, const opencascade::handle<BRepAdaptor_HSurface> & S2, const opencascade::handle<Adaptor3d_TopolTool> & I2, const opencascade::handle<BRepAdaptor_HCurve2d> & PC2, const opencascade::handle<BRepAdaptor_HSurface> & Sref2, const opencascade::handle<BRepAdaptor_HCurve2d> & PCref2, Standard_Boolean & Decroch2, const TopAbs_Orientation Or2, const Standard_Real MaxStep, const Standard_Real Fleche, const Standard_Real TolGuide, Standard_Real & First, Standard_Real & Last, const Standard_Boolean Inside, const Standard_Boolean Appro, const Standard_Boolean Forward, const Standard_Boolean RecP1, const Standard_Boolean RecRst1, const Standard_Boolean RecP2, const Standard_Boolean RecRst2, const math_Vector & Soldep){ self.PerformSurf(Data, Guide, Spine, Choix, S1, I1, PC1, Sref1, PCref1, Decroch1, Or1, S2, I2, PC2, Sref2, PCref2, Decroch2, Or2, MaxStep, Fleche, TolGuide, First, Last, Inside, Appro, Forward, RecP1, RecRst1, RecP2, RecRst2, Soldep); return std::tuple<Standard_Boolean &, Standard_Boolean &, Standard_Real &, Standard_Real &>(Decroch1, Decroch2, First, Last); }, "Method, implemented in inheritants, calculates the elements of construction of the surface (fillet or chamfer) contact edge/edge.", py::arg("Data"), py::arg("Guide"), py::arg("Spine"), py::arg("Choix"), py::arg("S1"), py::arg("I1"), py::arg("PC1"), py::arg("Sref1"), py::arg("PCref1"), py::arg("Decroch1"), py::arg("Or1"), py::arg("S2"), py::arg("I2"), py::arg("PC2"), py::arg("Sref2"), py::arg("PCref2"), py::arg("Decroch2"), py::arg("Or2"), py::arg("MaxStep"), py::arg("Fleche"), py::arg("TolGuide"), py::arg("First"), py::arg("Last"), py::arg("Inside"), py::arg("Appro"), py::arg("Forward"), py::arg("RecP1"), py::arg("RecRst1"), py::arg("RecP2"), py::arg("RecRst2"), py::arg("Soldep"));
cls_ChFi3d_ChBuilder.def("FindChoiceDistAngle", (Standard_Integer (ChFi3d_ChBuilder::*)(const Standard_Integer, const Standard_Boolean) const) &ChFi3d_ChBuilder::FindChoiceDistAngle, "None", py::arg("Choice"), py::arg("DisOnF1"));

// Enums

}