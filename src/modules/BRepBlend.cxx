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
#include <math_Matrix.hxx>
#include <gp_Lin.hxx>
#include <Blend_Point.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <gp_Ax1.hxx>
#include <gp_Circ.hxx>
#include <Law_Function.hxx>
#include <Approx_SweepFunction.hxx>
#include <Standard_TypeDef.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColgp_Array1OfVec.hxx>
#include <TColgp_Array1OfVec2d.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <GeomAbs_Shape.hxx>
#include <gp_Pnt.hxx>
#include <Blend_AppFunction.hxx>
#include <math_Vector.hxx>
#include <Standard_Handle.hxx>
#include <BRepBlend_AppFuncRoot.hxx>
#include <Standard_Type.hxx>
#include <BRepBlend_Line.hxx>
#include <Blend_Function.hxx>
#include <BRepBlend_AppFunc.hxx>
#include <Blend_SurfRstFunction.hxx>
#include <BRepBlend_AppFuncRst.hxx>
#include <Blend_RstRstFunction.hxx>
#include <BRepBlend_AppFuncRstRst.hxx>
#include <AppBlend_Approx.hxx>
#include <Standard.hxx>
#include <Approx_ParametrizationType.hxx>
#include <TColgp_Array2OfPnt.hxx>
#include <TColStd_Array2OfReal.hxx>
#include <TColgp_HArray2OfPnt.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <TColgp_SequenceOfArray1OfPnt2d.hxx>
#include <BRepBlend_AppSurf.hxx>
#include <Standard_OStream.hxx>
#include <Approx_SweepApproximation.hxx>
#include <BRepBlend_AppSurface.hxx>
#include <gp_Pnt2d.hxx>
#include <Adaptor3d_HVertex.hxx>
#include <BRepBlend_BlendTool.hxx>
#include <BlendFunc_Chamfer.hxx>
#include <BRepBlend_Chamfer.hxx>
#include <BlendFunc_ChamfInv.hxx>
#include <BRepBlend_ChamfInv.hxx>
#include <BlendFunc_ChAsym.hxx>
#include <BRepBlend_ChAsym.hxx>
#include <BlendFunc_ChAsymInv.hxx>
#include <BRepBlend_ChAsymInv.hxx>
#include <BlendFunc_ConstRad.hxx>
#include <BRepBlend_ConstRad.hxx>
#include <BlendFunc_ConstRadInv.hxx>
#include <BRepBlend_ConstRadInv.hxx>
#include <BlendFunc_CSCircular.hxx>
#include <BRepBlend_CSCircular.hxx>
#include <BlendFunc_CSConstRad.hxx>
#include <BRepBlend_CSConstRad.hxx>
#include <IntSurf_Transition.hxx>
#include <BRepBlend_PointOnRst.hxx>
#include <NCollection_Sequence.hxx>
#include <BRepBlend_SequenceOfPointOnRst.hxx>
#include <Adaptor3d_TopolTool.hxx>
#include <Blend_CSFunction.hxx>
#include <BRepBlend_Extremity.hxx>
#include <Blend_Status.hxx>
#include <gp_Vec.hxx>
#include <gp_Vec2d.hxx>
#include <BRepBlend_CSWalking.hxx>
#include <Blend_CurvPointFuncInv.hxx>
#include <BRepBlend_CurvPointRadInv.hxx>
#include <BlendFunc_EvolRad.hxx>
#include <BRepBlend_EvolRad.hxx>
#include <BlendFunc_EvolRadInv.hxx>
#include <BRepBlend_EvolRadInv.hxx>
#include <GeomAbs_CurveType.hxx>
#include <gp_Lin2d.hxx>
#include <gp_Circ2d.hxx>
#include <gp_Elips2d.hxx>
#include <gp_Hypr2d.hxx>
#include <gp_Parab2d.hxx>
#include <Geom2d_BezierCurve.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <BRepBlend_HCurve2dTool.hxx>
#include <gp_Elips.hxx>
#include <gp_Hypr.hxx>
#include <gp_Parab.hxx>
#include <Geom_BezierCurve.hxx>
#include <Geom_BSplineCurve.hxx>
#include <BRepBlend_HCurveTool.hxx>
#include <Standard_Transient.hxx>
#include <IntSurf_TypeTrans.hxx>
#include <Blend_SequenceOfPoint.hxx>
#include <Blend_DecrochStatus.hxx>
#include <BlendFunc_SectionShape.hxx>
#include <Adaptor3d_CurveOnSurface.hxx>
#include <Convert_ParameterisationType.hxx>
#include <BRepBlend_RstRstConstRad.hxx>
#include <BRepBlend_RstRstEvolRad.hxx>
#include <Blend_SurfCurvFuncInv.hxx>
#include <TopAbs_State.hxx>
#include <BRepBlend_RstRstLineBuilder.hxx>
#include <BlendFunc_Ruled.hxx>
#include <BRepBlend_Ruled.hxx>
#include <BlendFunc_RuledInv.hxx>
#include <BRepBlend_RuledInv.hxx>
#include <BRepBlend_SequenceOfLine.hxx>
#include <BRepBlend_SurfCurvConstRadInv.hxx>
#include <BRepBlend_SurfCurvEvolRadInv.hxx>
#include <Blend_SurfPointFuncInv.hxx>
#include <BRepBlend_SurfPointConstRadInv.hxx>
#include <BRepBlend_SurfPointEvolRadInv.hxx>
#include <BRepBlend_SurfRstConstRad.hxx>
#include <BRepBlend_SurfRstEvolRad.hxx>
#include <Blend_FuncInv.hxx>
#include <BRepBlend_SurfRstLineBuilder.hxx>
#include <ChFiDS_HElSpine.hxx>
#include <BRepBlend_Walking.hxx>
#include <bind_NCollection_Sequence.hxx>

PYBIND11_MODULE(BRepBlend, mod) {

py::module::import("OCCT.math");
py::module::import("OCCT.gp");
py::module::import("OCCT.Blend");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.Adaptor2d");
py::module::import("OCCT.Law");
py::module::import("OCCT.Approx");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.AppBlend");
py::module::import("OCCT.BlendFunc");
py::module::import("OCCT.IntSurf");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.Geom");
py::module::import("OCCT.Convert");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.ChFiDS");

// CLASS: BREPBLEND_APPFUNCROOT
py::class_<BRepBlend_AppFuncRoot, opencascade::handle<BRepBlend_AppFuncRoot>, Approx_SweepFunction> cls_BRepBlend_AppFuncRoot(mod, "BRepBlend_AppFuncRoot", "Function to approximate by AppSurface");

// Methods
cls_BRepBlend_AppFuncRoot.def("D0", (Standard_Boolean (BRepBlend_AppFuncRoot::*)(const Standard_Real, const Standard_Real, const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &)) &BRepBlend_AppFuncRoot::D0, "compute the section for v = param", py::arg("Param"), py::arg("First"), py::arg("Last"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
cls_BRepBlend_AppFuncRoot.def("D1", (Standard_Boolean (BRepBlend_AppFuncRoot::*)(const Standard_Real, const Standard_Real, const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BRepBlend_AppFuncRoot::D1, "compute the first derivative in v direction of the section for v = param", py::arg("Param"), py::arg("First"), py::arg("Last"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
cls_BRepBlend_AppFuncRoot.def("D2", (Standard_Boolean (BRepBlend_AppFuncRoot::*)(const Standard_Real, const Standard_Real, const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BRepBlend_AppFuncRoot::D2, "compute the second derivative in v direction of the section for v = param", py::arg("Param"), py::arg("First"), py::arg("Last"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
cls_BRepBlend_AppFuncRoot.def("Nb2dCurves", (Standard_Integer (BRepBlend_AppFuncRoot::*)() const) &BRepBlend_AppFuncRoot::Nb2dCurves, "get the number of 2d curves to approximate.");
cls_BRepBlend_AppFuncRoot.def("SectionShape", [](BRepBlend_AppFuncRoot &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree){ self.SectionShape(NbPoles, NbKnots, Degree); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree); }, "get the format of an section", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"));
cls_BRepBlend_AppFuncRoot.def("Knots", (void (BRepBlend_AppFuncRoot::*)(TColStd_Array1OfReal &) const) &BRepBlend_AppFuncRoot::Knots, "get the Knots of the section", py::arg("TKnots"));
cls_BRepBlend_AppFuncRoot.def("Mults", (void (BRepBlend_AppFuncRoot::*)(TColStd_Array1OfInteger &) const) &BRepBlend_AppFuncRoot::Mults, "get the Multplicities of the section", py::arg("TMults"));
cls_BRepBlend_AppFuncRoot.def("IsRational", (Standard_Boolean (BRepBlend_AppFuncRoot::*)() const) &BRepBlend_AppFuncRoot::IsRational, "Returns if the section is rationnal or not");
cls_BRepBlend_AppFuncRoot.def("NbIntervals", (Standard_Integer (BRepBlend_AppFuncRoot::*)(const GeomAbs_Shape) const) &BRepBlend_AppFuncRoot::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_BRepBlend_AppFuncRoot.def("Intervals", (void (BRepBlend_AppFuncRoot::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &BRepBlend_AppFuncRoot::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_BRepBlend_AppFuncRoot.def("SetInterval", (void (BRepBlend_AppFuncRoot::*)(const Standard_Real, const Standard_Real)) &BRepBlend_AppFuncRoot::SetInterval, "Sets the bounds of the parametric interval on the fonction This determines the derivatives in these values if the function is not Cn.", py::arg("First"), py::arg("Last"));
cls_BRepBlend_AppFuncRoot.def("Resolution", [](BRepBlend_AppFuncRoot &self, const Standard_Integer Index, const Standard_Real Tol, Standard_Real & TolU, Standard_Real & TolV){ self.Resolution(Index, Tol, TolU, TolV); return std::tuple<Standard_Real &, Standard_Real &>(TolU, TolV); }, "Returns the resolutions in the sub-space 2d <Index> -- This information is usfull to find an good tolerance in 2d approximation", py::arg("Index"), py::arg("Tol"), py::arg("TolU"), py::arg("TolV"));
cls_BRepBlend_AppFuncRoot.def("GetTolerance", (void (BRepBlend_AppFuncRoot::*)(const Standard_Real, const Standard_Real, const Standard_Real, TColStd_Array1OfReal &) const) &BRepBlend_AppFuncRoot::GetTolerance, "Returns the tolerance to reach in approximation to respecte BoundTol error at the Boundary AngleTol tangent error at the Boundary (in radian) SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"));
cls_BRepBlend_AppFuncRoot.def("SetTolerance", (void (BRepBlend_AppFuncRoot::*)(const Standard_Real, const Standard_Real)) &BRepBlend_AppFuncRoot::SetTolerance, "Is usfull, if (me) have to be run numerical algorithme to perform D0, D1 or D2", py::arg("Tol3d"), py::arg("Tol2d"));
cls_BRepBlend_AppFuncRoot.def("BarycentreOfSurf", (gp_Pnt (BRepBlend_AppFuncRoot::*)() const) &BRepBlend_AppFuncRoot::BarycentreOfSurf, "Get the barycentre of Surface. An very poor estimation is sufficent. This information is usefull to perform well conditionned rational approximation.");
cls_BRepBlend_AppFuncRoot.def("MaximalSection", (Standard_Real (BRepBlend_AppFuncRoot::*)() const) &BRepBlend_AppFuncRoot::MaximalSection, "Returns the length of the maximum section. This information is usefull to perform well conditionned rational approximation.");
cls_BRepBlend_AppFuncRoot.def("GetMinimalWeight", (void (BRepBlend_AppFuncRoot::*)(TColStd_Array1OfReal &) const) &BRepBlend_AppFuncRoot::GetMinimalWeight, "Compute the minimal value of weight for each poles of all sections. This information is usefull to perform well conditionned rational approximation.", py::arg("Weigths"));
cls_BRepBlend_AppFuncRoot.def("Point", (void (BRepBlend_AppFuncRoot::*)(const Blend_AppFunction &, const Standard_Real, const math_Vector &, Blend_Point &) const) &BRepBlend_AppFuncRoot::Point, "None", py::arg("Func"), py::arg("Param"), py::arg("Sol"), py::arg("Pnt"));
cls_BRepBlend_AppFuncRoot.def("Vec", (void (BRepBlend_AppFuncRoot::*)(math_Vector &, const Blend_Point &) const) &BRepBlend_AppFuncRoot::Vec, "None", py::arg("Sol"), py::arg("Pnt"));
cls_BRepBlend_AppFuncRoot.def_static("get_type_name_", (const char * (*)()) &BRepBlend_AppFuncRoot::get_type_name, "None");
cls_BRepBlend_AppFuncRoot.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepBlend_AppFuncRoot::get_type_descriptor, "None");
cls_BRepBlend_AppFuncRoot.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepBlend_AppFuncRoot::*)() const) &BRepBlend_AppFuncRoot::DynamicType, "None");

// CLASS: BREPBLEND_APPFUNC
py::class_<BRepBlend_AppFunc, opencascade::handle<BRepBlend_AppFunc>, BRepBlend_AppFuncRoot> cls_BRepBlend_AppFunc(mod, "BRepBlend_AppFunc", "Function to approximate by AppSurface for Surface/Surface contact.");

// Constructors
cls_BRepBlend_AppFunc.def(py::init<opencascade::handle<BRepBlend_Line> &, Blend_Function &, const Standard_Real, const Standard_Real>(), py::arg("Line"), py::arg("Func"), py::arg("Tol3d"), py::arg("Tol2d"));

// Methods
cls_BRepBlend_AppFunc.def("Point", (void (BRepBlend_AppFunc::*)(const Blend_AppFunction &, const Standard_Real, const math_Vector &, Blend_Point &) const) &BRepBlend_AppFunc::Point, "None", py::arg("Func"), py::arg("Param"), py::arg("Sol"), py::arg("Pnt"));
cls_BRepBlend_AppFunc.def("Vec", (void (BRepBlend_AppFunc::*)(math_Vector &, const Blend_Point &) const) &BRepBlend_AppFunc::Vec, "None", py::arg("Sol"), py::arg("Pnt"));
cls_BRepBlend_AppFunc.def_static("get_type_name_", (const char * (*)()) &BRepBlend_AppFunc::get_type_name, "None");
cls_BRepBlend_AppFunc.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepBlend_AppFunc::get_type_descriptor, "None");
cls_BRepBlend_AppFunc.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepBlend_AppFunc::*)() const) &BRepBlend_AppFunc::DynamicType, "None");

// CLASS: BREPBLEND_APPFUNCRST
py::class_<BRepBlend_AppFuncRst, opencascade::handle<BRepBlend_AppFuncRst>, BRepBlend_AppFuncRoot> cls_BRepBlend_AppFuncRst(mod, "BRepBlend_AppFuncRst", "Function to approximate by AppSurface for Curve/Surface contact.");

// Constructors
cls_BRepBlend_AppFuncRst.def(py::init<opencascade::handle<BRepBlend_Line> &, Blend_SurfRstFunction &, const Standard_Real, const Standard_Real>(), py::arg("Line"), py::arg("Func"), py::arg("Tol3d"), py::arg("Tol2d"));

// Methods
cls_BRepBlend_AppFuncRst.def("Point", (void (BRepBlend_AppFuncRst::*)(const Blend_AppFunction &, const Standard_Real, const math_Vector &, Blend_Point &) const) &BRepBlend_AppFuncRst::Point, "None", py::arg("Func"), py::arg("Param"), py::arg("Sol"), py::arg("Pnt"));
cls_BRepBlend_AppFuncRst.def("Vec", (void (BRepBlend_AppFuncRst::*)(math_Vector &, const Blend_Point &) const) &BRepBlend_AppFuncRst::Vec, "None", py::arg("Sol"), py::arg("Pnt"));
cls_BRepBlend_AppFuncRst.def_static("get_type_name_", (const char * (*)()) &BRepBlend_AppFuncRst::get_type_name, "None");
cls_BRepBlend_AppFuncRst.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepBlend_AppFuncRst::get_type_descriptor, "None");
cls_BRepBlend_AppFuncRst.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepBlend_AppFuncRst::*)() const) &BRepBlend_AppFuncRst::DynamicType, "None");

// CLASS: BREPBLEND_APPFUNCRSTRST
py::class_<BRepBlend_AppFuncRstRst, opencascade::handle<BRepBlend_AppFuncRstRst>, BRepBlend_AppFuncRoot> cls_BRepBlend_AppFuncRstRst(mod, "BRepBlend_AppFuncRstRst", "Function to approximate by AppSurface for Edge/Face (Curve/Curve contact).");

// Constructors
cls_BRepBlend_AppFuncRstRst.def(py::init<opencascade::handle<BRepBlend_Line> &, Blend_RstRstFunction &, const Standard_Real, const Standard_Real>(), py::arg("Line"), py::arg("Func"), py::arg("Tol3d"), py::arg("Tol2d"));

// Methods
cls_BRepBlend_AppFuncRstRst.def("Point", (void (BRepBlend_AppFuncRstRst::*)(const Blend_AppFunction &, const Standard_Real, const math_Vector &, Blend_Point &) const) &BRepBlend_AppFuncRstRst::Point, "None", py::arg("Func"), py::arg("Param"), py::arg("Sol"), py::arg("Pnt"));
cls_BRepBlend_AppFuncRstRst.def("Vec", (void (BRepBlend_AppFuncRstRst::*)(math_Vector &, const Blend_Point &) const) &BRepBlend_AppFuncRstRst::Vec, "None", py::arg("Sol"), py::arg("Pnt"));
cls_BRepBlend_AppFuncRstRst.def_static("get_type_name_", (const char * (*)()) &BRepBlend_AppFuncRstRst::get_type_name, "None");
cls_BRepBlend_AppFuncRstRst.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepBlend_AppFuncRstRst::get_type_descriptor, "None");
cls_BRepBlend_AppFuncRstRst.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepBlend_AppFuncRstRst::*)() const) &BRepBlend_AppFuncRstRst::DynamicType, "None");

// CLASS: BREPBLEND_APPSURF
py::class_<BRepBlend_AppSurf, AppBlend_Approx> cls_BRepBlend_AppSurf(mod, "BRepBlend_AppSurf", "None");

// Constructors
cls_BRepBlend_AppSurf.def(py::init<>());
cls_BRepBlend_AppSurf.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Degmin"), py::arg("Degmax"), py::arg("Tol3d"), py::arg("Tol2d"), py::arg("NbIt"));
cls_BRepBlend_AppSurf.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("Degmin"), py::arg("Degmax"), py::arg("Tol3d"), py::arg("Tol2d"), py::arg("NbIt"), py::arg("KnownParameters"));

// Methods
// cls_BRepBlend_AppSurf.def_static("operator new_", (void * (*)(size_t)) &BRepBlend_AppSurf::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_AppSurf.def_static("operator delete_", (void (*)(void *)) &BRepBlend_AppSurf::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_AppSurf.def_static("operator new[]_", (void * (*)(size_t)) &BRepBlend_AppSurf::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_AppSurf.def_static("operator delete[]_", (void (*)(void *)) &BRepBlend_AppSurf::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_AppSurf.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBlend_AppSurf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_AppSurf.def_static("operator delete_", (void (*)(void *, void *)) &BRepBlend_AppSurf::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_AppSurf.def("Init", [](BRepBlend_AppSurf &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3, const Standard_Integer a4) -> void { return self.Init(a0, a1, a2, a3, a4); });
cls_BRepBlend_AppSurf.def("Init", (void (BRepBlend_AppSurf::*)(const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean)) &BRepBlend_AppSurf::Init, "None", py::arg("Degmin"), py::arg("Degmax"), py::arg("Tol3d"), py::arg("Tol2d"), py::arg("NbIt"), py::arg("KnownParameters"));
cls_BRepBlend_AppSurf.def("SetParType", (void (BRepBlend_AppSurf::*)(const Approx_ParametrizationType)) &BRepBlend_AppSurf::SetParType, "Define the type of parametrization used in the approximation", py::arg("ParType"));
cls_BRepBlend_AppSurf.def("SetContinuity", (void (BRepBlend_AppSurf::*)(const GeomAbs_Shape)) &BRepBlend_AppSurf::SetContinuity, "Define the Continuity used in the approximation", py::arg("C"));
cls_BRepBlend_AppSurf.def("SetCriteriumWeight", (void (BRepBlend_AppSurf::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &BRepBlend_AppSurf::SetCriteriumWeight, "define the Weights associed to the criterium used in the optimization.", py::arg("W1"), py::arg("W2"), py::arg("W3"));
cls_BRepBlend_AppSurf.def("ParType", (Approx_ParametrizationType (BRepBlend_AppSurf::*)() const) &BRepBlend_AppSurf::ParType, "returns the type of parametrization used in the approximation");
cls_BRepBlend_AppSurf.def("Continuity", (GeomAbs_Shape (BRepBlend_AppSurf::*)() const) &BRepBlend_AppSurf::Continuity, "returns the Continuity used in the approximation");
cls_BRepBlend_AppSurf.def("CriteriumWeight", [](BRepBlend_AppSurf &self, Standard_Real & W1, Standard_Real & W2, Standard_Real & W3){ self.CriteriumWeight(W1, W2, W3); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(W1, W2, W3); }, "returns the Weights (as percent) associed to the criterium used in the optimization.", py::arg("W1"), py::arg("W2"), py::arg("W3"));
cls_BRepBlend_AppSurf.def("Perform", [](BRepBlend_AppSurf &self, const opencascade::handle<BRepBlend_Line> & a0, Blend_AppFunction & a1) -> void { return self.Perform(a0, a1); });
cls_BRepBlend_AppSurf.def("Perform", (void (BRepBlend_AppSurf::*)(const opencascade::handle<BRepBlend_Line> &, Blend_AppFunction &, const Standard_Boolean)) &BRepBlend_AppSurf::Perform, "None", py::arg("Lin"), py::arg("SecGen"), py::arg("SpApprox"));
cls_BRepBlend_AppSurf.def("PerformSmoothing", (void (BRepBlend_AppSurf::*)(const opencascade::handle<BRepBlend_Line> &, Blend_AppFunction &)) &BRepBlend_AppSurf::PerformSmoothing, "None", py::arg("Lin"), py::arg("SecGen"));
cls_BRepBlend_AppSurf.def("Perform", (void (BRepBlend_AppSurf::*)(const opencascade::handle<BRepBlend_Line> &, Blend_AppFunction &, const Standard_Integer)) &BRepBlend_AppSurf::Perform, "None", py::arg("Lin"), py::arg("SecGen"), py::arg("NbMaxP"));
cls_BRepBlend_AppSurf.def("IsDone", (Standard_Boolean (BRepBlend_AppSurf::*)() const) &BRepBlend_AppSurf::IsDone, "None");
cls_BRepBlend_AppSurf.def("SurfShape", [](BRepBlend_AppSurf &self, Standard_Integer & UDegree, Standard_Integer & VDegree, Standard_Integer & NbUPoles, Standard_Integer & NbVPoles, Standard_Integer & NbUKnots, Standard_Integer & NbVKnots){ self.SurfShape(UDegree, VDegree, NbUPoles, NbVPoles, NbUKnots, NbVKnots); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(UDegree, VDegree, NbUPoles, NbVPoles, NbUKnots, NbVKnots); }, "None", py::arg("UDegree"), py::arg("VDegree"), py::arg("NbUPoles"), py::arg("NbVPoles"), py::arg("NbUKnots"), py::arg("NbVKnots"));
cls_BRepBlend_AppSurf.def("Surface", (void (BRepBlend_AppSurf::*)(TColgp_Array2OfPnt &, TColStd_Array2OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfInteger &, TColStd_Array1OfInteger &) const) &BRepBlend_AppSurf::Surface, "None", py::arg("TPoles"), py::arg("TWeights"), py::arg("TUKnots"), py::arg("TVKnots"), py::arg("TUMults"), py::arg("TVMults"));
cls_BRepBlend_AppSurf.def("UDegree", (Standard_Integer (BRepBlend_AppSurf::*)() const) &BRepBlend_AppSurf::UDegree, "None");
cls_BRepBlend_AppSurf.def("VDegree", (Standard_Integer (BRepBlend_AppSurf::*)() const) &BRepBlend_AppSurf::VDegree, "None");
cls_BRepBlend_AppSurf.def("SurfPoles", (const TColgp_Array2OfPnt & (BRepBlend_AppSurf::*)() const) &BRepBlend_AppSurf::SurfPoles, "None");
cls_BRepBlend_AppSurf.def("SurfWeights", (const TColStd_Array2OfReal & (BRepBlend_AppSurf::*)() const) &BRepBlend_AppSurf::SurfWeights, "None");
cls_BRepBlend_AppSurf.def("SurfUKnots", (const TColStd_Array1OfReal & (BRepBlend_AppSurf::*)() const) &BRepBlend_AppSurf::SurfUKnots, "None");
cls_BRepBlend_AppSurf.def("SurfVKnots", (const TColStd_Array1OfReal & (BRepBlend_AppSurf::*)() const) &BRepBlend_AppSurf::SurfVKnots, "None");
cls_BRepBlend_AppSurf.def("SurfUMults", (const TColStd_Array1OfInteger & (BRepBlend_AppSurf::*)() const) &BRepBlend_AppSurf::SurfUMults, "None");
cls_BRepBlend_AppSurf.def("SurfVMults", (const TColStd_Array1OfInteger & (BRepBlend_AppSurf::*)() const) &BRepBlend_AppSurf::SurfVMults, "None");
cls_BRepBlend_AppSurf.def("NbCurves2d", (Standard_Integer (BRepBlend_AppSurf::*)() const) &BRepBlend_AppSurf::NbCurves2d, "None");
cls_BRepBlend_AppSurf.def("Curves2dShape", [](BRepBlend_AppSurf &self, Standard_Integer & Degree, Standard_Integer & NbPoles, Standard_Integer & NbKnots){ self.Curves2dShape(Degree, NbPoles, NbKnots); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(Degree, NbPoles, NbKnots); }, "None", py::arg("Degree"), py::arg("NbPoles"), py::arg("NbKnots"));
cls_BRepBlend_AppSurf.def("Curve2d", (void (BRepBlend_AppSurf::*)(const Standard_Integer, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &, TColStd_Array1OfInteger &) const) &BRepBlend_AppSurf::Curve2d, "None", py::arg("Index"), py::arg("TPoles"), py::arg("TKnots"), py::arg("TMults"));
cls_BRepBlend_AppSurf.def("Curves2dDegree", (Standard_Integer (BRepBlend_AppSurf::*)() const) &BRepBlend_AppSurf::Curves2dDegree, "None");
cls_BRepBlend_AppSurf.def("Curve2dPoles", (const TColgp_Array1OfPnt2d & (BRepBlend_AppSurf::*)(const Standard_Integer) const) &BRepBlend_AppSurf::Curve2dPoles, "None", py::arg("Index"));
cls_BRepBlend_AppSurf.def("Curves2dKnots", (const TColStd_Array1OfReal & (BRepBlend_AppSurf::*)() const) &BRepBlend_AppSurf::Curves2dKnots, "None");
cls_BRepBlend_AppSurf.def("Curves2dMults", (const TColStd_Array1OfInteger & (BRepBlend_AppSurf::*)() const) &BRepBlend_AppSurf::Curves2dMults, "None");
cls_BRepBlend_AppSurf.def("TolReached", [](BRepBlend_AppSurf &self, Standard_Real & Tol3d, Standard_Real & Tol2d){ self.TolReached(Tol3d, Tol2d); return std::tuple<Standard_Real &, Standard_Real &>(Tol3d, Tol2d); }, "None", py::arg("Tol3d"), py::arg("Tol2d"));
cls_BRepBlend_AppSurf.def("TolCurveOnSurf", (Standard_Real (BRepBlend_AppSurf::*)(const Standard_Integer) const) &BRepBlend_AppSurf::TolCurveOnSurf, "None", py::arg("Index"));

// CLASS: BREPBLEND_APPSURFACE
py::class_<BRepBlend_AppSurface, AppBlend_Approx> cls_BRepBlend_AppSurface(mod, "BRepBlend_AppSurface", "Used to Approximate the blending surfaces.");

// Constructors
cls_BRepBlend_AppSurface.def(py::init<const opencascade::handle<Approx_SweepFunction> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Funct"), py::arg("First"), py::arg("Last"), py::arg("Tol3d"), py::arg("Tol2d"), py::arg("TolAngular"));
cls_BRepBlend_AppSurface.def(py::init<const opencascade::handle<Approx_SweepFunction> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const GeomAbs_Shape>(), py::arg("Funct"), py::arg("First"), py::arg("Last"), py::arg("Tol3d"), py::arg("Tol2d"), py::arg("TolAngular"), py::arg("Continuity"));
cls_BRepBlend_AppSurface.def(py::init<const opencascade::handle<Approx_SweepFunction> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Integer>(), py::arg("Funct"), py::arg("First"), py::arg("Last"), py::arg("Tol3d"), py::arg("Tol2d"), py::arg("TolAngular"), py::arg("Continuity"), py::arg("Degmax"));
cls_BRepBlend_AppSurface.def(py::init<const opencascade::handle<Approx_SweepFunction> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer>(), py::arg("Funct"), py::arg("First"), py::arg("Last"), py::arg("Tol3d"), py::arg("Tol2d"), py::arg("TolAngular"), py::arg("Continuity"), py::arg("Degmax"), py::arg("Segmax"));

// Methods
// cls_BRepBlend_AppSurface.def_static("operator new_", (void * (*)(size_t)) &BRepBlend_AppSurface::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_AppSurface.def_static("operator delete_", (void (*)(void *)) &BRepBlend_AppSurface::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_AppSurface.def_static("operator new[]_", (void * (*)(size_t)) &BRepBlend_AppSurface::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_AppSurface.def_static("operator delete[]_", (void (*)(void *)) &BRepBlend_AppSurface::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_AppSurface.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBlend_AppSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_AppSurface.def_static("operator delete_", (void (*)(void *, void *)) &BRepBlend_AppSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_AppSurface.def("IsDone", (Standard_Boolean (BRepBlend_AppSurface::*)() const) &BRepBlend_AppSurface::IsDone, "None");
cls_BRepBlend_AppSurface.def("SurfShape", [](BRepBlend_AppSurface &self, Standard_Integer & UDegree, Standard_Integer & VDegree, Standard_Integer & NbUPoles, Standard_Integer & NbVPoles, Standard_Integer & NbUKnots, Standard_Integer & NbVKnots){ self.SurfShape(UDegree, VDegree, NbUPoles, NbVPoles, NbUKnots, NbVKnots); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(UDegree, VDegree, NbUPoles, NbVPoles, NbUKnots, NbVKnots); }, "None", py::arg("UDegree"), py::arg("VDegree"), py::arg("NbUPoles"), py::arg("NbVPoles"), py::arg("NbUKnots"), py::arg("NbVKnots"));
cls_BRepBlend_AppSurface.def("Surface", (void (BRepBlend_AppSurface::*)(TColgp_Array2OfPnt &, TColStd_Array2OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfInteger &, TColStd_Array1OfInteger &) const) &BRepBlend_AppSurface::Surface, "None", py::arg("TPoles"), py::arg("TWeights"), py::arg("TUKnots"), py::arg("TVKnots"), py::arg("TUMults"), py::arg("TVMults"));
cls_BRepBlend_AppSurface.def("UDegree", (Standard_Integer (BRepBlend_AppSurface::*)() const) &BRepBlend_AppSurface::UDegree, "None");
cls_BRepBlend_AppSurface.def("VDegree", (Standard_Integer (BRepBlend_AppSurface::*)() const) &BRepBlend_AppSurface::VDegree, "None");
cls_BRepBlend_AppSurface.def("SurfPoles", (const TColgp_Array2OfPnt & (BRepBlend_AppSurface::*)() const) &BRepBlend_AppSurface::SurfPoles, "None");
cls_BRepBlend_AppSurface.def("SurfWeights", (const TColStd_Array2OfReal & (BRepBlend_AppSurface::*)() const) &BRepBlend_AppSurface::SurfWeights, "None");
cls_BRepBlend_AppSurface.def("SurfUKnots", (const TColStd_Array1OfReal & (BRepBlend_AppSurface::*)() const) &BRepBlend_AppSurface::SurfUKnots, "None");
cls_BRepBlend_AppSurface.def("SurfVKnots", (const TColStd_Array1OfReal & (BRepBlend_AppSurface::*)() const) &BRepBlend_AppSurface::SurfVKnots, "None");
cls_BRepBlend_AppSurface.def("SurfUMults", (const TColStd_Array1OfInteger & (BRepBlend_AppSurface::*)() const) &BRepBlend_AppSurface::SurfUMults, "None");
cls_BRepBlend_AppSurface.def("SurfVMults", (const TColStd_Array1OfInteger & (BRepBlend_AppSurface::*)() const) &BRepBlend_AppSurface::SurfVMults, "None");
cls_BRepBlend_AppSurface.def("MaxErrorOnSurf", (Standard_Real (BRepBlend_AppSurface::*)() const) &BRepBlend_AppSurface::MaxErrorOnSurf, "returns the maximum error in the suface approximation.");
cls_BRepBlend_AppSurface.def("NbCurves2d", (Standard_Integer (BRepBlend_AppSurface::*)() const) &BRepBlend_AppSurface::NbCurves2d, "None");
cls_BRepBlend_AppSurface.def("Curves2dShape", [](BRepBlend_AppSurface &self, Standard_Integer & Degree, Standard_Integer & NbPoles, Standard_Integer & NbKnots){ self.Curves2dShape(Degree, NbPoles, NbKnots); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(Degree, NbPoles, NbKnots); }, "None", py::arg("Degree"), py::arg("NbPoles"), py::arg("NbKnots"));
cls_BRepBlend_AppSurface.def("Curve2d", (void (BRepBlend_AppSurface::*)(const Standard_Integer, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &, TColStd_Array1OfInteger &) const) &BRepBlend_AppSurface::Curve2d, "None", py::arg("Index"), py::arg("TPoles"), py::arg("TKnots"), py::arg("TMults"));
cls_BRepBlend_AppSurface.def("Curves2dDegree", (Standard_Integer (BRepBlend_AppSurface::*)() const) &BRepBlend_AppSurface::Curves2dDegree, "None");
cls_BRepBlend_AppSurface.def("Curve2dPoles", (const TColgp_Array1OfPnt2d & (BRepBlend_AppSurface::*)(const Standard_Integer) const) &BRepBlend_AppSurface::Curve2dPoles, "None", py::arg("Index"));
cls_BRepBlend_AppSurface.def("Curves2dKnots", (const TColStd_Array1OfReal & (BRepBlend_AppSurface::*)() const) &BRepBlend_AppSurface::Curves2dKnots, "None");
cls_BRepBlend_AppSurface.def("Curves2dMults", (const TColStd_Array1OfInteger & (BRepBlend_AppSurface::*)() const) &BRepBlend_AppSurface::Curves2dMults, "None");
cls_BRepBlend_AppSurface.def("TolReached", [](BRepBlend_AppSurface &self, Standard_Real & Tol3d, Standard_Real & Tol2d){ self.TolReached(Tol3d, Tol2d); return std::tuple<Standard_Real &, Standard_Real &>(Tol3d, Tol2d); }, "None", py::arg("Tol3d"), py::arg("Tol2d"));
cls_BRepBlend_AppSurface.def("Max2dError", (Standard_Real (BRepBlend_AppSurface::*)(const Standard_Integer) const) &BRepBlend_AppSurface::Max2dError, "returns the maximum error in the <Index> 2d curve approximation.", py::arg("Index"));
cls_BRepBlend_AppSurface.def("TolCurveOnSurf", (Standard_Real (BRepBlend_AppSurface::*)(const Standard_Integer) const) &BRepBlend_AppSurface::TolCurveOnSurf, "None", py::arg("Index"));
cls_BRepBlend_AppSurface.def("Dump", (void (BRepBlend_AppSurface::*)(Standard_OStream &) const) &BRepBlend_AppSurface::Dump, "diplay information on approximation.", py::arg("o"));

// CLASS: BREPBLEND_BLENDTOOL
py::class_<BRepBlend_BlendTool> cls_BRepBlend_BlendTool(mod, "BRepBlend_BlendTool", "None");

// Methods
// cls_BRepBlend_BlendTool.def_static("operator new_", (void * (*)(size_t)) &BRepBlend_BlendTool::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_BlendTool.def_static("operator delete_", (void (*)(void *)) &BRepBlend_BlendTool::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_BlendTool.def_static("operator new[]_", (void * (*)(size_t)) &BRepBlend_BlendTool::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_BlendTool.def_static("operator delete[]_", (void (*)(void *)) &BRepBlend_BlendTool::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_BlendTool.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBlend_BlendTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_BlendTool.def_static("operator delete_", (void (*)(void *, void *)) &BRepBlend_BlendTool::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_BlendTool.def_static("Project_", [](const gp_Pnt2d & P, const opencascade::handle<Adaptor3d_HSurface> & S, const opencascade::handle<Adaptor2d_HCurve2d> & C, Standard_Real & Paramproj, Standard_Real & Dist){ Standard_Boolean rv = BRepBlend_BlendTool::Project(P, S, C, Paramproj, Dist); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, Paramproj, Dist); }, "Projects the point P on the arc C. If the methods returns Standard_True, the projection is successful, and Paramproj is the parameter on the arc of the projected point, Dist is the distance between P and the curve.. If the method returns Standard_False, Param proj and Dist are not significant.", py::arg("P"), py::arg("S"), py::arg("C"), py::arg("Paramproj"), py::arg("Dist"));
cls_BRepBlend_BlendTool.def_static("Inters_", [](const gp_Pnt2d & P1, const gp_Pnt2d & P2, const opencascade::handle<Adaptor3d_HSurface> & S, const opencascade::handle<Adaptor2d_HCurve2d> & C, Standard_Real & Param, Standard_Real & Dist){ Standard_Boolean rv = BRepBlend_BlendTool::Inters(P1, P2, S, C, Param, Dist); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, Param, Dist); }, "None", py::arg("P1"), py::arg("P2"), py::arg("S"), py::arg("C"), py::arg("Param"), py::arg("Dist"));
cls_BRepBlend_BlendTool.def_static("Parameter_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HVertex> &, const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_BlendTool::Parameter, "Returns the parameter of the vertex V on the edge A.", py::arg("V"), py::arg("A"));
cls_BRepBlend_BlendTool.def_static("Tolerance_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HVertex> &, const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_BlendTool::Tolerance, "Returns the parametric tolerance on the arc A used to consider that the vertex and another point meet, i-e if Abs(Parameter(Vertex)-Parameter(OtherPnt))<= Tolerance, the points are 'merged'.", py::arg("V"), py::arg("A"));
cls_BRepBlend_BlendTool.def_static("SingularOnUMin_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &BRepBlend_BlendTool::SingularOnUMin, "None", py::arg("S"));
cls_BRepBlend_BlendTool.def_static("SingularOnUMax_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &BRepBlend_BlendTool::SingularOnUMax, "None", py::arg("S"));
cls_BRepBlend_BlendTool.def_static("SingularOnVMin_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &BRepBlend_BlendTool::SingularOnVMin, "None", py::arg("S"));
cls_BRepBlend_BlendTool.def_static("SingularOnVMax_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &BRepBlend_BlendTool::SingularOnVMax, "None", py::arg("S"));
cls_BRepBlend_BlendTool.def_static("NbSamplesU_", (Standard_Integer (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real)) &BRepBlend_BlendTool::NbSamplesU, "None", py::arg("S"), py::arg("u1"), py::arg("u2"));
cls_BRepBlend_BlendTool.def_static("NbSamplesV_", (Standard_Integer (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real)) &BRepBlend_BlendTool::NbSamplesV, "None", py::arg("S"), py::arg("v1"), py::arg("v2"));
cls_BRepBlend_BlendTool.def_static("Bounds_", [](const opencascade::handle<Adaptor2d_HCurve2d> & C, Standard_Real & Ufirst, Standard_Real & Ulast){ BRepBlend_BlendTool::Bounds(C, Ufirst, Ulast); return std::tuple<Standard_Real &, Standard_Real &>(Ufirst, Ulast); }, "Returns the parametric limits on the arc C. These limits must be finite : they are either the real limits of the arc, for a finite arc, or a bounding box for an infinite arc.", py::arg("C"), py::arg("Ufirst"), py::arg("Ulast"));
cls_BRepBlend_BlendTool.def_static("CurveOnSurf_", (opencascade::handle<Adaptor2d_HCurve2d> (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HSurface> &)) &BRepBlend_BlendTool::CurveOnSurf, "None", py::arg("C"), py::arg("S"));

// TYPEDEF: BREPBLEND_CHAMFER
py::class_<BlendFunc_Chamfer, Blend_Function> cls_BRepBlend_Chamfer(mod, "BRepBlend_Chamfer", "None", py::module_local());

// Constructors
cls_BRepBlend_Chamfer.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S1"), py::arg("S2"), py::arg("CG"));

// Methods
// cls_BRepBlend_Chamfer.def_static("operator new_", (void * (*)(size_t)) &BlendFunc_Chamfer::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_Chamfer.def_static("operator delete_", (void (*)(void *)) &BlendFunc_Chamfer::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_Chamfer.def_static("operator new[]_", (void * (*)(size_t)) &BlendFunc_Chamfer::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_Chamfer.def_static("operator delete[]_", (void (*)(void *)) &BlendFunc_Chamfer::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_Chamfer.def_static("operator new_", (void * (*)(size_t, void *)) &BlendFunc_Chamfer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_Chamfer.def_static("operator delete_", (void (*)(void *, void *)) &BlendFunc_Chamfer::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_Chamfer.def("NbEquations", (Standard_Integer (BlendFunc_Chamfer::*)() const) &BlendFunc_Chamfer::NbEquations, "returns the number of equations of the function.");
cls_BRepBlend_Chamfer.def("Value", (Standard_Boolean (BlendFunc_Chamfer::*)(const math_Vector &, math_Vector &)) &BlendFunc_Chamfer::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_BRepBlend_Chamfer.def("Derivatives", (Standard_Boolean (BlendFunc_Chamfer::*)(const math_Vector &, math_Matrix &)) &BlendFunc_Chamfer::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_BRepBlend_Chamfer.def("Values", (Standard_Boolean (BlendFunc_Chamfer::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BlendFunc_Chamfer::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_BRepBlend_Chamfer.def("Set", (void (BlendFunc_Chamfer::*)(const Standard_Real)) &BlendFunc_Chamfer::Set, "None", py::arg("Param"));
cls_BRepBlend_Chamfer.def("Set", (void (BlendFunc_Chamfer::*)(const Standard_Real, const Standard_Real)) &BlendFunc_Chamfer::Set, "None", py::arg("First"), py::arg("Last"));
cls_BRepBlend_Chamfer.def("GetTolerance", (void (BlendFunc_Chamfer::*)(math_Vector &, const Standard_Real) const) &BlendFunc_Chamfer::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
cls_BRepBlend_Chamfer.def("GetBounds", (void (BlendFunc_Chamfer::*)(math_Vector &, math_Vector &) const) &BlendFunc_Chamfer::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
cls_BRepBlend_Chamfer.def("IsSolution", (Standard_Boolean (BlendFunc_Chamfer::*)(const math_Vector &, const Standard_Real)) &BlendFunc_Chamfer::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
cls_BRepBlend_Chamfer.def("GetMinimalDistance", (Standard_Real (BlendFunc_Chamfer::*)() const) &BlendFunc_Chamfer::GetMinimalDistance, "Returns the minimal Distance beetween two extremitys of calculed sections.");
cls_BRepBlend_Chamfer.def("PointOnS1", (const gp_Pnt & (BlendFunc_Chamfer::*)() const) &BlendFunc_Chamfer::PointOnS1, "None");
cls_BRepBlend_Chamfer.def("PointOnS2", (const gp_Pnt & (BlendFunc_Chamfer::*)() const) &BlendFunc_Chamfer::PointOnS2, "None");
cls_BRepBlend_Chamfer.def("IsTangencyPoint", (Standard_Boolean (BlendFunc_Chamfer::*)() const) &BlendFunc_Chamfer::IsTangencyPoint, "None");
cls_BRepBlend_Chamfer.def("TangentOnS1", (const gp_Vec & (BlendFunc_Chamfer::*)() const) &BlendFunc_Chamfer::TangentOnS1, "None");
cls_BRepBlend_Chamfer.def("Tangent2dOnS1", (const gp_Vec2d & (BlendFunc_Chamfer::*)() const) &BlendFunc_Chamfer::Tangent2dOnS1, "None");
cls_BRepBlend_Chamfer.def("TangentOnS2", (const gp_Vec & (BlendFunc_Chamfer::*)() const) &BlendFunc_Chamfer::TangentOnS2, "None");
cls_BRepBlend_Chamfer.def("Tangent2dOnS2", (const gp_Vec2d & (BlendFunc_Chamfer::*)() const) &BlendFunc_Chamfer::Tangent2dOnS2, "None");
cls_BRepBlend_Chamfer.def("Tangent", (void (BlendFunc_Chamfer::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &BlendFunc_Chamfer::Tangent, "Returns the tangent vector at the section, at the beginning and the end of the section, and returns the normal (of the surfaces) at these points.", py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("TgFirst"), py::arg("TgLast"), py::arg("NormFirst"), py::arg("NormLast"));
cls_BRepBlend_Chamfer.def("Set", (void (BlendFunc_Chamfer::*)(const Standard_Real, const Standard_Real, const Standard_Integer)) &BlendFunc_Chamfer::Set, "Sets the distances and the 'quadrant'.", py::arg("Dist1"), py::arg("Dist2"), py::arg("Choix"));
cls_BRepBlend_Chamfer.def("IsRational", (Standard_Boolean (BlendFunc_Chamfer::*)() const) &BlendFunc_Chamfer::IsRational, "Returns False");
cls_BRepBlend_Chamfer.def("GetSectionSize", (Standard_Real (BlendFunc_Chamfer::*)() const) &BlendFunc_Chamfer::GetSectionSize, "Returns the length of the maximum section");
cls_BRepBlend_Chamfer.def("GetMinimalWeight", (void (BlendFunc_Chamfer::*)(TColStd_Array1OfReal &) const) &BlendFunc_Chamfer::GetMinimalWeight, "Compute the minimal value of weight for each poles of all sections.", py::arg("Weigths"));
cls_BRepBlend_Chamfer.def("NbIntervals", (Standard_Integer (BlendFunc_Chamfer::*)(const GeomAbs_Shape) const) &BlendFunc_Chamfer::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_BRepBlend_Chamfer.def("Intervals", (void (BlendFunc_Chamfer::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &BlendFunc_Chamfer::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_BRepBlend_Chamfer.def("GetShape", [](BlendFunc_Chamfer &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree, Standard_Integer & NbPoles2d){ self.GetShape(NbPoles, NbKnots, Degree, NbPoles2d); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree, NbPoles2d); }, "None", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"), py::arg("NbPoles2d"));
cls_BRepBlend_Chamfer.def("GetTolerance", (void (BlendFunc_Chamfer::*)(const Standard_Real, const Standard_Real, const Standard_Real, math_Vector &, math_Vector &) const) &BlendFunc_Chamfer::GetTolerance, "Returns the tolerance to reach in approximation to respecte BoundTol error at the Boundary AngleTol tangent error at the Boundary SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"), py::arg("Tol1D"));
cls_BRepBlend_Chamfer.def("Knots", (void (BlendFunc_Chamfer::*)(TColStd_Array1OfReal &)) &BlendFunc_Chamfer::Knots, "None", py::arg("TKnots"));
cls_BRepBlend_Chamfer.def("Mults", (void (BlendFunc_Chamfer::*)(TColStd_Array1OfInteger &)) &BlendFunc_Chamfer::Mults, "None", py::arg("TMults"));
cls_BRepBlend_Chamfer.def("Section", [](BlendFunc_Chamfer &self, const Standard_Real Param, const Standard_Real U1, const Standard_Real V1, const Standard_Real U2, const Standard_Real V2, Standard_Real & Pdeb, Standard_Real & Pfin, gp_Lin & C){ self.Section(Param, U1, V1, U2, V2, Pdeb, Pfin, C); return std::tuple<Standard_Real &, Standard_Real &>(Pdeb, Pfin); }, "Obsolete method", py::arg("Param"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("Pdeb"), py::arg("Pfin"), py::arg("C"));
cls_BRepBlend_Chamfer.def("Section", (Standard_Boolean (BlendFunc_Chamfer::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_Chamfer::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
cls_BRepBlend_Chamfer.def("Section", (Standard_Boolean (BlendFunc_Chamfer::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_Chamfer::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
cls_BRepBlend_Chamfer.def("Section", (void (BlendFunc_Chamfer::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &)) &BlendFunc_Chamfer::Section, "None", py::arg("P"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
cls_BRepBlend_Chamfer.def("Resolution", [](BlendFunc_Chamfer &self, const Standard_Integer IC2d, const Standard_Real Tol, Standard_Real & TolU, Standard_Real & TolV){ self.Resolution(IC2d, Tol, TolU, TolV); return std::tuple<Standard_Real &, Standard_Real &>(TolU, TolV); }, "None", py::arg("IC2d"), py::arg("Tol"), py::arg("TolU"), py::arg("TolV"));

// TYPEDEF: BREPBLEND_CHAMFINV
py::class_<BlendFunc_ChamfInv, Blend_FuncInv> cls_BRepBlend_ChamfInv(mod, "BRepBlend_ChamfInv", "None", py::module_local());

// Constructors
cls_BRepBlend_ChamfInv.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S1"), py::arg("S2"), py::arg("C"));

// Methods
// cls_BRepBlend_ChamfInv.def_static("operator new_", (void * (*)(size_t)) &BlendFunc_ChamfInv::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_ChamfInv.def_static("operator delete_", (void (*)(void *)) &BlendFunc_ChamfInv::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_ChamfInv.def_static("operator new[]_", (void * (*)(size_t)) &BlendFunc_ChamfInv::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_ChamfInv.def_static("operator delete[]_", (void (*)(void *)) &BlendFunc_ChamfInv::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_ChamfInv.def_static("operator new_", (void * (*)(size_t, void *)) &BlendFunc_ChamfInv::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_ChamfInv.def_static("operator delete_", (void (*)(void *, void *)) &BlendFunc_ChamfInv::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_ChamfInv.def("Set", (void (BlendFunc_ChamfInv::*)(const Standard_Boolean, const opencascade::handle<Adaptor2d_HCurve2d> &)) &BlendFunc_ChamfInv::Set, "None", py::arg("OnFirst"), py::arg("COnSurf"));
cls_BRepBlend_ChamfInv.def("GetTolerance", (void (BlendFunc_ChamfInv::*)(math_Vector &, const Standard_Real) const) &BlendFunc_ChamfInv::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
cls_BRepBlend_ChamfInv.def("GetBounds", (void (BlendFunc_ChamfInv::*)(math_Vector &, math_Vector &) const) &BlendFunc_ChamfInv::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
cls_BRepBlend_ChamfInv.def("IsSolution", (Standard_Boolean (BlendFunc_ChamfInv::*)(const math_Vector &, const Standard_Real)) &BlendFunc_ChamfInv::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
cls_BRepBlend_ChamfInv.def("NbEquations", (Standard_Integer (BlendFunc_ChamfInv::*)() const) &BlendFunc_ChamfInv::NbEquations, "returns the number of equations of the function.");
cls_BRepBlend_ChamfInv.def("Value", (Standard_Boolean (BlendFunc_ChamfInv::*)(const math_Vector &, math_Vector &)) &BlendFunc_ChamfInv::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_BRepBlend_ChamfInv.def("Derivatives", (Standard_Boolean (BlendFunc_ChamfInv::*)(const math_Vector &, math_Matrix &)) &BlendFunc_ChamfInv::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_BRepBlend_ChamfInv.def("Values", (Standard_Boolean (BlendFunc_ChamfInv::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BlendFunc_ChamfInv::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_BRepBlend_ChamfInv.def("Set", (void (BlendFunc_ChamfInv::*)(const Standard_Real, const Standard_Real, const Standard_Integer)) &BlendFunc_ChamfInv::Set, "None", py::arg("Dist1"), py::arg("Dist2"), py::arg("Choix"));

// TYPEDEF: BREPBLEND_CHASYM
py::class_<BlendFunc_ChAsym, Blend_Function> cls_BRepBlend_ChAsym(mod, "BRepBlend_ChAsym", "None", py::module_local());

// Constructors
cls_BRepBlend_ChAsym.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S1"), py::arg("S2"), py::arg("C"));

// Methods
// cls_BRepBlend_ChAsym.def_static("operator new_", (void * (*)(size_t)) &BlendFunc_ChAsym::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_ChAsym.def_static("operator delete_", (void (*)(void *)) &BlendFunc_ChAsym::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_ChAsym.def_static("operator new[]_", (void * (*)(size_t)) &BlendFunc_ChAsym::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_ChAsym.def_static("operator delete[]_", (void (*)(void *)) &BlendFunc_ChAsym::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_ChAsym.def_static("operator new_", (void * (*)(size_t, void *)) &BlendFunc_ChAsym::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_ChAsym.def_static("operator delete_", (void (*)(void *, void *)) &BlendFunc_ChAsym::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_ChAsym.def("NbEquations", (Standard_Integer (BlendFunc_ChAsym::*)() const) &BlendFunc_ChAsym::NbEquations, "returns the number of equations of the function.");
cls_BRepBlend_ChAsym.def("Set", (void (BlendFunc_ChAsym::*)(const Standard_Real)) &BlendFunc_ChAsym::Set, "None", py::arg("Param"));
cls_BRepBlend_ChAsym.def("Set", (void (BlendFunc_ChAsym::*)(const Standard_Real, const Standard_Real)) &BlendFunc_ChAsym::Set, "None", py::arg("First"), py::arg("Last"));
cls_BRepBlend_ChAsym.def("GetTolerance", (void (BlendFunc_ChAsym::*)(math_Vector &, const Standard_Real) const) &BlendFunc_ChAsym::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
cls_BRepBlend_ChAsym.def("GetBounds", (void (BlendFunc_ChAsym::*)(math_Vector &, math_Vector &) const) &BlendFunc_ChAsym::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
cls_BRepBlend_ChAsym.def("IsSolution", (Standard_Boolean (BlendFunc_ChAsym::*)(const math_Vector &, const Standard_Real)) &BlendFunc_ChAsym::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
cls_BRepBlend_ChAsym.def("GetMinimalDistance", (Standard_Real (BlendFunc_ChAsym::*)() const) &BlendFunc_ChAsym::GetMinimalDistance, "Returns the minimal Distance beetween two extremitys of calculed sections.");
cls_BRepBlend_ChAsym.def("ComputeValues", (Standard_Boolean (BlendFunc_ChAsym::*)(const math_Vector &, const Standard_Integer, const Standard_Integer)) &BlendFunc_ChAsym::ComputeValues, "computes the values <F> of the derivatives for the variable <X> between DegF and DegL. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("DegF"), py::arg("DegL"));
cls_BRepBlend_ChAsym.def("Value", (Standard_Boolean (BlendFunc_ChAsym::*)(const math_Vector &, math_Vector &)) &BlendFunc_ChAsym::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_BRepBlend_ChAsym.def("Derivatives", (Standard_Boolean (BlendFunc_ChAsym::*)(const math_Vector &, math_Matrix &)) &BlendFunc_ChAsym::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_BRepBlend_ChAsym.def("Values", (Standard_Boolean (BlendFunc_ChAsym::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BlendFunc_ChAsym::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_BRepBlend_ChAsym.def("PointOnS1", (const gp_Pnt & (BlendFunc_ChAsym::*)() const) &BlendFunc_ChAsym::PointOnS1, "None");
cls_BRepBlend_ChAsym.def("PointOnS2", (const gp_Pnt & (BlendFunc_ChAsym::*)() const) &BlendFunc_ChAsym::PointOnS2, "None");
cls_BRepBlend_ChAsym.def("IsTangencyPoint", (Standard_Boolean (BlendFunc_ChAsym::*)() const) &BlendFunc_ChAsym::IsTangencyPoint, "None");
cls_BRepBlend_ChAsym.def("TangentOnS1", (const gp_Vec & (BlendFunc_ChAsym::*)() const) &BlendFunc_ChAsym::TangentOnS1, "None");
cls_BRepBlend_ChAsym.def("Tangent2dOnS1", (const gp_Vec2d & (BlendFunc_ChAsym::*)() const) &BlendFunc_ChAsym::Tangent2dOnS1, "None");
cls_BRepBlend_ChAsym.def("TangentOnS2", (const gp_Vec & (BlendFunc_ChAsym::*)() const) &BlendFunc_ChAsym::TangentOnS2, "None");
cls_BRepBlend_ChAsym.def("Tangent2dOnS2", (const gp_Vec2d & (BlendFunc_ChAsym::*)() const) &BlendFunc_ChAsym::Tangent2dOnS2, "None");
cls_BRepBlend_ChAsym.def("TwistOnS1", (Standard_Boolean (BlendFunc_ChAsym::*)() const) &BlendFunc_ChAsym::TwistOnS1, "None");
cls_BRepBlend_ChAsym.def("TwistOnS2", (Standard_Boolean (BlendFunc_ChAsym::*)() const) &BlendFunc_ChAsym::TwistOnS2, "None");
cls_BRepBlend_ChAsym.def("Tangent", (void (BlendFunc_ChAsym::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &BlendFunc_ChAsym::Tangent, "Returns the tangent vector at the section, at the beginning and the end of the section, and returns the normal (of the surfaces) at these points.", py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("TgFirst"), py::arg("TgLast"), py::arg("NormFirst"), py::arg("NormLast"));
cls_BRepBlend_ChAsym.def("Section", [](BlendFunc_ChAsym &self, const Standard_Real Param, const Standard_Real U1, const Standard_Real V1, const Standard_Real U2, const Standard_Real V2, Standard_Real & Pdeb, Standard_Real & Pfin, gp_Lin & C){ self.Section(Param, U1, V1, U2, V2, Pdeb, Pfin, C); return std::tuple<Standard_Real &, Standard_Real &>(Pdeb, Pfin); }, "Utile pour une visu rapide et approximative de la surface.", py::arg("Param"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("Pdeb"), py::arg("Pfin"), py::arg("C"));
cls_BRepBlend_ChAsym.def("IsRational", (Standard_Boolean (BlendFunc_ChAsym::*)() const) &BlendFunc_ChAsym::IsRational, "Returns if the section is rationnal");
cls_BRepBlend_ChAsym.def("GetSectionSize", (Standard_Real (BlendFunc_ChAsym::*)() const) &BlendFunc_ChAsym::GetSectionSize, "Returns the length of the maximum section");
cls_BRepBlend_ChAsym.def("GetMinimalWeight", (void (BlendFunc_ChAsym::*)(TColStd_Array1OfReal &) const) &BlendFunc_ChAsym::GetMinimalWeight, "Compute the minimal value of weight for each poles of all sections.", py::arg("Weigths"));
cls_BRepBlend_ChAsym.def("NbIntervals", (Standard_Integer (BlendFunc_ChAsym::*)(const GeomAbs_Shape) const) &BlendFunc_ChAsym::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_BRepBlend_ChAsym.def("Intervals", (void (BlendFunc_ChAsym::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &BlendFunc_ChAsym::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_BRepBlend_ChAsym.def("GetShape", [](BlendFunc_ChAsym &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree, Standard_Integer & NbPoles2d){ self.GetShape(NbPoles, NbKnots, Degree, NbPoles2d); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree, NbPoles2d); }, "None", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"), py::arg("NbPoles2d"));
cls_BRepBlend_ChAsym.def("GetTolerance", (void (BlendFunc_ChAsym::*)(const Standard_Real, const Standard_Real, const Standard_Real, math_Vector &, math_Vector &) const) &BlendFunc_ChAsym::GetTolerance, "Returns the tolerance to reach in approximation to respecte BoundTol error at the Boundary AngleTol tangent error at the Boundary SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"), py::arg("Tol1D"));
cls_BRepBlend_ChAsym.def("Knots", (void (BlendFunc_ChAsym::*)(TColStd_Array1OfReal &)) &BlendFunc_ChAsym::Knots, "None", py::arg("TKnots"));
cls_BRepBlend_ChAsym.def("Mults", (void (BlendFunc_ChAsym::*)(TColStd_Array1OfInteger &)) &BlendFunc_ChAsym::Mults, "None", py::arg("TMults"));
cls_BRepBlend_ChAsym.def("Section", (void (BlendFunc_ChAsym::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &)) &BlendFunc_ChAsym::Section, "None", py::arg("P"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
cls_BRepBlend_ChAsym.def("Section", (Standard_Boolean (BlendFunc_ChAsym::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_ChAsym::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
cls_BRepBlend_ChAsym.def("Section", (Standard_Boolean (BlendFunc_ChAsym::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_ChAsym::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
cls_BRepBlend_ChAsym.def("Resolution", [](BlendFunc_ChAsym &self, const Standard_Integer IC2d, const Standard_Real Tol, Standard_Real & TolU, Standard_Real & TolV){ self.Resolution(IC2d, Tol, TolU, TolV); return std::tuple<Standard_Real &, Standard_Real &>(TolU, TolV); }, "None", py::arg("IC2d"), py::arg("Tol"), py::arg("TolU"), py::arg("TolV"));
cls_BRepBlend_ChAsym.def("Set", (void (BlendFunc_ChAsym::*)(const Standard_Real, const Standard_Real, const Standard_Integer)) &BlendFunc_ChAsym::Set, "Sets the distances and the angle.", py::arg("Dist1"), py::arg("Angle"), py::arg("Choix"));

// TYPEDEF: BREPBLEND_CHASYMINV
py::class_<BlendFunc_ChAsymInv, Blend_FuncInv> cls_BRepBlend_ChAsymInv(mod, "BRepBlend_ChAsymInv", "None", py::module_local());

// Constructors
cls_BRepBlend_ChAsymInv.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S1"), py::arg("S2"), py::arg("C"));

// Methods
// cls_BRepBlend_ChAsymInv.def_static("operator new_", (void * (*)(size_t)) &BlendFunc_ChAsymInv::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_ChAsymInv.def_static("operator delete_", (void (*)(void *)) &BlendFunc_ChAsymInv::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_ChAsymInv.def_static("operator new[]_", (void * (*)(size_t)) &BlendFunc_ChAsymInv::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_ChAsymInv.def_static("operator delete[]_", (void (*)(void *)) &BlendFunc_ChAsymInv::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_ChAsymInv.def_static("operator new_", (void * (*)(size_t, void *)) &BlendFunc_ChAsymInv::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_ChAsymInv.def_static("operator delete_", (void (*)(void *, void *)) &BlendFunc_ChAsymInv::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_ChAsymInv.def("Set", (void (BlendFunc_ChAsymInv::*)(const Standard_Boolean, const opencascade::handle<Adaptor2d_HCurve2d> &)) &BlendFunc_ChAsymInv::Set, "None", py::arg("OnFirst"), py::arg("COnSurf"));
cls_BRepBlend_ChAsymInv.def("GetTolerance", (void (BlendFunc_ChAsymInv::*)(math_Vector &, const Standard_Real) const) &BlendFunc_ChAsymInv::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
cls_BRepBlend_ChAsymInv.def("GetBounds", (void (BlendFunc_ChAsymInv::*)(math_Vector &, math_Vector &) const) &BlendFunc_ChAsymInv::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
cls_BRepBlend_ChAsymInv.def("IsSolution", (Standard_Boolean (BlendFunc_ChAsymInv::*)(const math_Vector &, const Standard_Real)) &BlendFunc_ChAsymInv::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
cls_BRepBlend_ChAsymInv.def("NbEquations", (Standard_Integer (BlendFunc_ChAsymInv::*)() const) &BlendFunc_ChAsymInv::NbEquations, "returns the number of equations of the function.");
cls_BRepBlend_ChAsymInv.def("ComputeValues", (Standard_Boolean (BlendFunc_ChAsymInv::*)(const math_Vector &, const Standard_Integer, const Standard_Integer)) &BlendFunc_ChAsymInv::ComputeValues, "computes the values <F> of the derivatives for the variable <X> between DegF and DegL. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("DegF"), py::arg("DegL"));
cls_BRepBlend_ChAsymInv.def("Value", (Standard_Boolean (BlendFunc_ChAsymInv::*)(const math_Vector &, math_Vector &)) &BlendFunc_ChAsymInv::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_BRepBlend_ChAsymInv.def("Derivatives", (Standard_Boolean (BlendFunc_ChAsymInv::*)(const math_Vector &, math_Matrix &)) &BlendFunc_ChAsymInv::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_BRepBlend_ChAsymInv.def("Values", (Standard_Boolean (BlendFunc_ChAsymInv::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BlendFunc_ChAsymInv::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_BRepBlend_ChAsymInv.def("Set", (void (BlendFunc_ChAsymInv::*)(const Standard_Real, const Standard_Real, const Standard_Integer)) &BlendFunc_ChAsymInv::Set, "None", py::arg("Dist1"), py::arg("Angle"), py::arg("Choix"));

// TYPEDEF: BREPBLEND_CONSTRAD
py::class_<BlendFunc_ConstRad, Blend_Function> cls_BRepBlend_ConstRad(mod, "BRepBlend_ConstRad", "None", py::module_local());

// Constructors
cls_BRepBlend_ConstRad.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S1"), py::arg("S2"), py::arg("C"));

// Methods
// cls_BRepBlend_ConstRad.def_static("operator new_", (void * (*)(size_t)) &BlendFunc_ConstRad::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_ConstRad.def_static("operator delete_", (void (*)(void *)) &BlendFunc_ConstRad::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_ConstRad.def_static("operator new[]_", (void * (*)(size_t)) &BlendFunc_ConstRad::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_ConstRad.def_static("operator delete[]_", (void (*)(void *)) &BlendFunc_ConstRad::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_ConstRad.def_static("operator new_", (void * (*)(size_t, void *)) &BlendFunc_ConstRad::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_ConstRad.def_static("operator delete_", (void (*)(void *, void *)) &BlendFunc_ConstRad::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_ConstRad.def("NbEquations", (Standard_Integer (BlendFunc_ConstRad::*)() const) &BlendFunc_ConstRad::NbEquations, "returns the number of equations of the function.");
cls_BRepBlend_ConstRad.def("Value", (Standard_Boolean (BlendFunc_ConstRad::*)(const math_Vector &, math_Vector &)) &BlendFunc_ConstRad::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_BRepBlend_ConstRad.def("Derivatives", (Standard_Boolean (BlendFunc_ConstRad::*)(const math_Vector &, math_Matrix &)) &BlendFunc_ConstRad::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_BRepBlend_ConstRad.def("Values", (Standard_Boolean (BlendFunc_ConstRad::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BlendFunc_ConstRad::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_BRepBlend_ConstRad.def("Set", (void (BlendFunc_ConstRad::*)(const Standard_Real)) &BlendFunc_ConstRad::Set, "None", py::arg("Param"));
cls_BRepBlend_ConstRad.def("Set", (void (BlendFunc_ConstRad::*)(const Standard_Real, const Standard_Real)) &BlendFunc_ConstRad::Set, "None", py::arg("First"), py::arg("Last"));
cls_BRepBlend_ConstRad.def("GetTolerance", (void (BlendFunc_ConstRad::*)(math_Vector &, const Standard_Real) const) &BlendFunc_ConstRad::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
cls_BRepBlend_ConstRad.def("GetBounds", (void (BlendFunc_ConstRad::*)(math_Vector &, math_Vector &) const) &BlendFunc_ConstRad::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
cls_BRepBlend_ConstRad.def("IsSolution", (Standard_Boolean (BlendFunc_ConstRad::*)(const math_Vector &, const Standard_Real)) &BlendFunc_ConstRad::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
cls_BRepBlend_ConstRad.def("GetMinimalDistance", (Standard_Real (BlendFunc_ConstRad::*)() const) &BlendFunc_ConstRad::GetMinimalDistance, "Returns the minimal Distance beetween two extremitys of calculed sections.");
cls_BRepBlend_ConstRad.def("PointOnS1", (const gp_Pnt & (BlendFunc_ConstRad::*)() const) &BlendFunc_ConstRad::PointOnS1, "None");
cls_BRepBlend_ConstRad.def("PointOnS2", (const gp_Pnt & (BlendFunc_ConstRad::*)() const) &BlendFunc_ConstRad::PointOnS2, "None");
cls_BRepBlend_ConstRad.def("IsTangencyPoint", (Standard_Boolean (BlendFunc_ConstRad::*)() const) &BlendFunc_ConstRad::IsTangencyPoint, "None");
cls_BRepBlend_ConstRad.def("TangentOnS1", (const gp_Vec & (BlendFunc_ConstRad::*)() const) &BlendFunc_ConstRad::TangentOnS1, "None");
cls_BRepBlend_ConstRad.def("Tangent2dOnS1", (const gp_Vec2d & (BlendFunc_ConstRad::*)() const) &BlendFunc_ConstRad::Tangent2dOnS1, "None");
cls_BRepBlend_ConstRad.def("TangentOnS2", (const gp_Vec & (BlendFunc_ConstRad::*)() const) &BlendFunc_ConstRad::TangentOnS2, "None");
cls_BRepBlend_ConstRad.def("Tangent2dOnS2", (const gp_Vec2d & (BlendFunc_ConstRad::*)() const) &BlendFunc_ConstRad::Tangent2dOnS2, "None");
cls_BRepBlend_ConstRad.def("Tangent", (void (BlendFunc_ConstRad::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &BlendFunc_ConstRad::Tangent, "Returns the tangent vector at the section, at the beginning and the end of the section, and returns the normal (of the surfaces) at these points.", py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("TgFirst"), py::arg("TgLast"), py::arg("NormFirst"), py::arg("NormLast"));
cls_BRepBlend_ConstRad.def("TwistOnS1", (Standard_Boolean (BlendFunc_ConstRad::*)() const) &BlendFunc_ConstRad::TwistOnS1, "None");
cls_BRepBlend_ConstRad.def("TwistOnS2", (Standard_Boolean (BlendFunc_ConstRad::*)() const) &BlendFunc_ConstRad::TwistOnS2, "None");
cls_BRepBlend_ConstRad.def("Set", (void (BlendFunc_ConstRad::*)(const Standard_Real, const Standard_Integer)) &BlendFunc_ConstRad::Set, "Inits the value of radius, and the 'quadrant'.", py::arg("Radius"), py::arg("Choix"));
cls_BRepBlend_ConstRad.def("Set", (void (BlendFunc_ConstRad::*)(const BlendFunc_SectionShape)) &BlendFunc_ConstRad::Set, "Sets the type of section generation for the approximations.", py::arg("TypeSection"));
cls_BRepBlend_ConstRad.def("Section", [](BlendFunc_ConstRad &self, const Standard_Real Param, const Standard_Real U1, const Standard_Real V1, const Standard_Real U2, const Standard_Real V2, Standard_Real & Pdeb, Standard_Real & Pfin, gp_Circ & C){ self.Section(Param, U1, V1, U2, V2, Pdeb, Pfin, C); return std::tuple<Standard_Real &, Standard_Real &>(Pdeb, Pfin); }, "Utile pour une visu rapide et approximative de la surface.", py::arg("Param"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("Pdeb"), py::arg("Pfin"), py::arg("C"));
cls_BRepBlend_ConstRad.def("IsRational", (Standard_Boolean (BlendFunc_ConstRad::*)() const) &BlendFunc_ConstRad::IsRational, "Returns if the section is rationnal");
cls_BRepBlend_ConstRad.def("GetSectionSize", (Standard_Real (BlendFunc_ConstRad::*)() const) &BlendFunc_ConstRad::GetSectionSize, "Returns the length of the maximum section");
cls_BRepBlend_ConstRad.def("GetMinimalWeight", (void (BlendFunc_ConstRad::*)(TColStd_Array1OfReal &) const) &BlendFunc_ConstRad::GetMinimalWeight, "Compute the minimal value of weight for each poles of all sections.", py::arg("Weigths"));
cls_BRepBlend_ConstRad.def("NbIntervals", (Standard_Integer (BlendFunc_ConstRad::*)(const GeomAbs_Shape) const) &BlendFunc_ConstRad::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_BRepBlend_ConstRad.def("Intervals", (void (BlendFunc_ConstRad::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &BlendFunc_ConstRad::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_BRepBlend_ConstRad.def("GetShape", [](BlendFunc_ConstRad &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree, Standard_Integer & NbPoles2d){ self.GetShape(NbPoles, NbKnots, Degree, NbPoles2d); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree, NbPoles2d); }, "None", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"), py::arg("NbPoles2d"));
cls_BRepBlend_ConstRad.def("GetTolerance", (void (BlendFunc_ConstRad::*)(const Standard_Real, const Standard_Real, const Standard_Real, math_Vector &, math_Vector &) const) &BlendFunc_ConstRad::GetTolerance, "Returns the tolerance to reach in approximation to respecte BoundTol error at the Boundary AngleTol tangent error at the Boundary SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"), py::arg("Tol1D"));
cls_BRepBlend_ConstRad.def("Knots", (void (BlendFunc_ConstRad::*)(TColStd_Array1OfReal &)) &BlendFunc_ConstRad::Knots, "None", py::arg("TKnots"));
cls_BRepBlend_ConstRad.def("Mults", (void (BlendFunc_ConstRad::*)(TColStd_Array1OfInteger &)) &BlendFunc_ConstRad::Mults, "None", py::arg("TMults"));
cls_BRepBlend_ConstRad.def("Section", (Standard_Boolean (BlendFunc_ConstRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_ConstRad::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
cls_BRepBlend_ConstRad.def("Section", (Standard_Boolean (BlendFunc_ConstRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_ConstRad::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
cls_BRepBlend_ConstRad.def("Section", (void (BlendFunc_ConstRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &)) &BlendFunc_ConstRad::Section, "None", py::arg("P"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
cls_BRepBlend_ConstRad.def("AxeRot", (gp_Ax1 (BlendFunc_ConstRad::*)(const Standard_Real)) &BlendFunc_ConstRad::AxeRot, "None", py::arg("Prm"));
cls_BRepBlend_ConstRad.def("Resolution", [](BlendFunc_ConstRad &self, const Standard_Integer IC2d, const Standard_Real Tol, Standard_Real & TolU, Standard_Real & TolV){ self.Resolution(IC2d, Tol, TolU, TolV); return std::tuple<Standard_Real &, Standard_Real &>(TolU, TolV); }, "None", py::arg("IC2d"), py::arg("Tol"), py::arg("TolU"), py::arg("TolV"));

// TYPEDEF: BREPBLEND_CONSTRADINV
py::class_<BlendFunc_ConstRadInv, Blend_FuncInv> cls_BRepBlend_ConstRadInv(mod, "BRepBlend_ConstRadInv", "None", py::module_local());

// Constructors
cls_BRepBlend_ConstRadInv.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S1"), py::arg("S2"), py::arg("C"));

// Methods
// cls_BRepBlend_ConstRadInv.def_static("operator new_", (void * (*)(size_t)) &BlendFunc_ConstRadInv::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_ConstRadInv.def_static("operator delete_", (void (*)(void *)) &BlendFunc_ConstRadInv::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_ConstRadInv.def_static("operator new[]_", (void * (*)(size_t)) &BlendFunc_ConstRadInv::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_ConstRadInv.def_static("operator delete[]_", (void (*)(void *)) &BlendFunc_ConstRadInv::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_ConstRadInv.def_static("operator new_", (void * (*)(size_t, void *)) &BlendFunc_ConstRadInv::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_ConstRadInv.def_static("operator delete_", (void (*)(void *, void *)) &BlendFunc_ConstRadInv::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_ConstRadInv.def("Set", (void (BlendFunc_ConstRadInv::*)(const Standard_Boolean, const opencascade::handle<Adaptor2d_HCurve2d> &)) &BlendFunc_ConstRadInv::Set, "None", py::arg("OnFirst"), py::arg("COnSurf"));
cls_BRepBlend_ConstRadInv.def("GetTolerance", (void (BlendFunc_ConstRadInv::*)(math_Vector &, const Standard_Real) const) &BlendFunc_ConstRadInv::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
cls_BRepBlend_ConstRadInv.def("GetBounds", (void (BlendFunc_ConstRadInv::*)(math_Vector &, math_Vector &) const) &BlendFunc_ConstRadInv::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
cls_BRepBlend_ConstRadInv.def("IsSolution", (Standard_Boolean (BlendFunc_ConstRadInv::*)(const math_Vector &, const Standard_Real)) &BlendFunc_ConstRadInv::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
cls_BRepBlend_ConstRadInv.def("NbEquations", (Standard_Integer (BlendFunc_ConstRadInv::*)() const) &BlendFunc_ConstRadInv::NbEquations, "returns the number of equations of the function.");
cls_BRepBlend_ConstRadInv.def("Value", (Standard_Boolean (BlendFunc_ConstRadInv::*)(const math_Vector &, math_Vector &)) &BlendFunc_ConstRadInv::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_BRepBlend_ConstRadInv.def("Derivatives", (Standard_Boolean (BlendFunc_ConstRadInv::*)(const math_Vector &, math_Matrix &)) &BlendFunc_ConstRadInv::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_BRepBlend_ConstRadInv.def("Values", (Standard_Boolean (BlendFunc_ConstRadInv::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BlendFunc_ConstRadInv::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_BRepBlend_ConstRadInv.def("Set", (void (BlendFunc_ConstRadInv::*)(const Standard_Real, const Standard_Integer)) &BlendFunc_ConstRadInv::Set, "None", py::arg("R"), py::arg("Choix"));

// TYPEDEF: BREPBLEND_CSCIRCULAR
py::class_<BlendFunc_CSCircular, Blend_CSFunction> cls_BRepBlend_CSCircular(mod, "BRepBlend_CSCircular", "None", py::module_local());

// Constructors
cls_BRepBlend_CSCircular.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Law_Function> &>(), py::arg("S"), py::arg("C"), py::arg("CGuide"), py::arg("L"));

// Methods
// cls_BRepBlend_CSCircular.def_static("operator new_", (void * (*)(size_t)) &BlendFunc_CSCircular::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_CSCircular.def_static("operator delete_", (void (*)(void *)) &BlendFunc_CSCircular::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_CSCircular.def_static("operator new[]_", (void * (*)(size_t)) &BlendFunc_CSCircular::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_CSCircular.def_static("operator delete[]_", (void (*)(void *)) &BlendFunc_CSCircular::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_CSCircular.def_static("operator new_", (void * (*)(size_t, void *)) &BlendFunc_CSCircular::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_CSCircular.def_static("operator delete_", (void (*)(void *, void *)) &BlendFunc_CSCircular::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_CSCircular.def("NbVariables", (Standard_Integer (BlendFunc_CSCircular::*)() const) &BlendFunc_CSCircular::NbVariables, "None");
cls_BRepBlend_CSCircular.def("NbEquations", (Standard_Integer (BlendFunc_CSCircular::*)() const) &BlendFunc_CSCircular::NbEquations, "returns the number of equations of the function (3).");
cls_BRepBlend_CSCircular.def("Value", (Standard_Boolean (BlendFunc_CSCircular::*)(const math_Vector &, math_Vector &)) &BlendFunc_CSCircular::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_BRepBlend_CSCircular.def("Derivatives", (Standard_Boolean (BlendFunc_CSCircular::*)(const math_Vector &, math_Matrix &)) &BlendFunc_CSCircular::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_BRepBlend_CSCircular.def("Values", (Standard_Boolean (BlendFunc_CSCircular::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BlendFunc_CSCircular::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_BRepBlend_CSCircular.def("Set", (void (BlendFunc_CSCircular::*)(const Standard_Real)) &BlendFunc_CSCircular::Set, "None", py::arg("Param"));
cls_BRepBlend_CSCircular.def("Set", (void (BlendFunc_CSCircular::*)(const Standard_Real, const Standard_Real)) &BlendFunc_CSCircular::Set, "None", py::arg("First"), py::arg("Last"));
cls_BRepBlend_CSCircular.def("GetTolerance", (void (BlendFunc_CSCircular::*)(math_Vector &, const Standard_Real) const) &BlendFunc_CSCircular::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
cls_BRepBlend_CSCircular.def("GetBounds", (void (BlendFunc_CSCircular::*)(math_Vector &, math_Vector &) const) &BlendFunc_CSCircular::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
cls_BRepBlend_CSCircular.def("IsSolution", (Standard_Boolean (BlendFunc_CSCircular::*)(const math_Vector &, const Standard_Real)) &BlendFunc_CSCircular::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
cls_BRepBlend_CSCircular.def("PointOnS", (const gp_Pnt & (BlendFunc_CSCircular::*)() const) &BlendFunc_CSCircular::PointOnS, "None");
cls_BRepBlend_CSCircular.def("PointOnC", (const gp_Pnt & (BlendFunc_CSCircular::*)() const) &BlendFunc_CSCircular::PointOnC, "None");
cls_BRepBlend_CSCircular.def("Pnt2d", (const gp_Pnt2d & (BlendFunc_CSCircular::*)() const) &BlendFunc_CSCircular::Pnt2d, "Returns U,V coordinates of the point on the surface.");
cls_BRepBlend_CSCircular.def("ParameterOnC", (Standard_Real (BlendFunc_CSCircular::*)() const) &BlendFunc_CSCircular::ParameterOnC, "Returns parameter of the point on the curve.");
cls_BRepBlend_CSCircular.def("IsTangencyPoint", (Standard_Boolean (BlendFunc_CSCircular::*)() const) &BlendFunc_CSCircular::IsTangencyPoint, "None");
cls_BRepBlend_CSCircular.def("TangentOnS", (const gp_Vec & (BlendFunc_CSCircular::*)() const) &BlendFunc_CSCircular::TangentOnS, "None");
cls_BRepBlend_CSCircular.def("Tangent2d", (const gp_Vec2d & (BlendFunc_CSCircular::*)() const) &BlendFunc_CSCircular::Tangent2d, "None");
cls_BRepBlend_CSCircular.def("TangentOnC", (const gp_Vec & (BlendFunc_CSCircular::*)() const) &BlendFunc_CSCircular::TangentOnC, "None");
cls_BRepBlend_CSCircular.def("Tangent", (void (BlendFunc_CSCircular::*)(const Standard_Real, const Standard_Real, gp_Vec &, gp_Vec &) const) &BlendFunc_CSCircular::Tangent, "Returns the tangent vector at the section, at the beginning and the end of the section, and returns the normal (of the surface) at these points.", py::arg("U"), py::arg("V"), py::arg("TgS"), py::arg("NormS"));
cls_BRepBlend_CSCircular.def("Set", (void (BlendFunc_CSCircular::*)(const Standard_Real, const Standard_Integer)) &BlendFunc_CSCircular::Set, "None", py::arg("Radius"), py::arg("Choix"));
cls_BRepBlend_CSCircular.def("Set", (void (BlendFunc_CSCircular::*)(const BlendFunc_SectionShape)) &BlendFunc_CSCircular::Set, "Sets the type of section generation for the approximations.", py::arg("TypeSection"));
cls_BRepBlend_CSCircular.def("Section", [](BlendFunc_CSCircular &self, const Standard_Real Param, const Standard_Real U, const Standard_Real V, const Standard_Real W, Standard_Real & Pdeb, Standard_Real & Pfin, gp_Circ & C){ self.Section(Param, U, V, W, Pdeb, Pfin, C); return std::tuple<Standard_Real &, Standard_Real &>(Pdeb, Pfin); }, "None", py::arg("Param"), py::arg("U"), py::arg("V"), py::arg("W"), py::arg("Pdeb"), py::arg("Pfin"), py::arg("C"));
cls_BRepBlend_CSCircular.def("Section", (Standard_Boolean (BlendFunc_CSCircular::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_CSCircular::Section, "Used for the first and last section The method returns Standard_True if the derivatives are computed, otherwise it returns Standard_False.", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
cls_BRepBlend_CSCircular.def("GetSection", (Standard_Boolean (BlendFunc_CSCircular::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfVec &)) &BlendFunc_CSCircular::GetSection, "None", py::arg("Param"), py::arg("U"), py::arg("V"), py::arg("W"), py::arg("tabP"), py::arg("tabV"));
cls_BRepBlend_CSCircular.def("IsRational", (Standard_Boolean (BlendFunc_CSCircular::*)() const) &BlendFunc_CSCircular::IsRational, "Returns if the section is rationnal");
cls_BRepBlend_CSCircular.def("GetSectionSize", (Standard_Real (BlendFunc_CSCircular::*)() const) &BlendFunc_CSCircular::GetSectionSize, "Returns the length of the maximum section");
cls_BRepBlend_CSCircular.def("GetMinimalWeight", (void (BlendFunc_CSCircular::*)(TColStd_Array1OfReal &) const) &BlendFunc_CSCircular::GetMinimalWeight, "Compute the minimal value of weight for each poles of all sections.", py::arg("Weigths"));
cls_BRepBlend_CSCircular.def("NbIntervals", (Standard_Integer (BlendFunc_CSCircular::*)(const GeomAbs_Shape) const) &BlendFunc_CSCircular::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_BRepBlend_CSCircular.def("Intervals", (void (BlendFunc_CSCircular::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &BlendFunc_CSCircular::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_BRepBlend_CSCircular.def("GetShape", [](BlendFunc_CSCircular &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree, Standard_Integer & NbPoles2d){ self.GetShape(NbPoles, NbKnots, Degree, NbPoles2d); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree, NbPoles2d); }, "None", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"), py::arg("NbPoles2d"));
cls_BRepBlend_CSCircular.def("GetTolerance", (void (BlendFunc_CSCircular::*)(const Standard_Real, const Standard_Real, const Standard_Real, math_Vector &, math_Vector &) const) &BlendFunc_CSCircular::GetTolerance, "Returns the tolerance to reach in approximation to respecte BoundTol error at the Boundary AngleTol tangent error at the Boundary SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"), py::arg("Tol1D"));
cls_BRepBlend_CSCircular.def("Knots", (void (BlendFunc_CSCircular::*)(TColStd_Array1OfReal &)) &BlendFunc_CSCircular::Knots, "None", py::arg("TKnots"));
cls_BRepBlend_CSCircular.def("Mults", (void (BlendFunc_CSCircular::*)(TColStd_Array1OfInteger &)) &BlendFunc_CSCircular::Mults, "None", py::arg("TMults"));
cls_BRepBlend_CSCircular.def("Section", (Standard_Boolean (BlendFunc_CSCircular::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_CSCircular::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
cls_BRepBlend_CSCircular.def("Section", (void (BlendFunc_CSCircular::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &)) &BlendFunc_CSCircular::Section, "None", py::arg("P"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
cls_BRepBlend_CSCircular.def("Resolution", [](BlendFunc_CSCircular &self, const Standard_Integer IC2d, const Standard_Real Tol, Standard_Real & TolU, Standard_Real & TolV){ self.Resolution(IC2d, Tol, TolU, TolV); return std::tuple<Standard_Real &, Standard_Real &>(TolU, TolV); }, "None", py::arg("IC2d"), py::arg("Tol"), py::arg("TolU"), py::arg("TolV"));

// TYPEDEF: BREPBLEND_CSCONSTRAD
py::class_<BlendFunc_CSConstRad, Blend_CSFunction> cls_BRepBlend_CSConstRad(mod, "BRepBlend_CSConstRad", "None", py::module_local());

// Constructors
cls_BRepBlend_CSConstRad.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S"), py::arg("C"), py::arg("CGuide"));

// Methods
// cls_BRepBlend_CSConstRad.def_static("operator new_", (void * (*)(size_t)) &BlendFunc_CSConstRad::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_CSConstRad.def_static("operator delete_", (void (*)(void *)) &BlendFunc_CSConstRad::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_CSConstRad.def_static("operator new[]_", (void * (*)(size_t)) &BlendFunc_CSConstRad::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_CSConstRad.def_static("operator delete[]_", (void (*)(void *)) &BlendFunc_CSConstRad::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_CSConstRad.def_static("operator new_", (void * (*)(size_t, void *)) &BlendFunc_CSConstRad::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_CSConstRad.def_static("operator delete_", (void (*)(void *, void *)) &BlendFunc_CSConstRad::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_CSConstRad.def("NbEquations", (Standard_Integer (BlendFunc_CSConstRad::*)() const) &BlendFunc_CSConstRad::NbEquations, "returns the number of equations of the function (3).");
cls_BRepBlend_CSConstRad.def("Value", (Standard_Boolean (BlendFunc_CSConstRad::*)(const math_Vector &, math_Vector &)) &BlendFunc_CSConstRad::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_BRepBlend_CSConstRad.def("Derivatives", (Standard_Boolean (BlendFunc_CSConstRad::*)(const math_Vector &, math_Matrix &)) &BlendFunc_CSConstRad::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_BRepBlend_CSConstRad.def("Values", (Standard_Boolean (BlendFunc_CSConstRad::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BlendFunc_CSConstRad::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_BRepBlend_CSConstRad.def("Set", (void (BlendFunc_CSConstRad::*)(const Standard_Real)) &BlendFunc_CSConstRad::Set, "None", py::arg("Param"));
cls_BRepBlend_CSConstRad.def("Set", (void (BlendFunc_CSConstRad::*)(const Standard_Real, const Standard_Real)) &BlendFunc_CSConstRad::Set, "None", py::arg("First"), py::arg("Last"));
cls_BRepBlend_CSConstRad.def("GetTolerance", (void (BlendFunc_CSConstRad::*)(math_Vector &, const Standard_Real) const) &BlendFunc_CSConstRad::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
cls_BRepBlend_CSConstRad.def("GetBounds", (void (BlendFunc_CSConstRad::*)(math_Vector &, math_Vector &) const) &BlendFunc_CSConstRad::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
cls_BRepBlend_CSConstRad.def("IsSolution", (Standard_Boolean (BlendFunc_CSConstRad::*)(const math_Vector &, const Standard_Real)) &BlendFunc_CSConstRad::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
cls_BRepBlend_CSConstRad.def("PointOnS", (const gp_Pnt & (BlendFunc_CSConstRad::*)() const) &BlendFunc_CSConstRad::PointOnS, "None");
cls_BRepBlend_CSConstRad.def("PointOnC", (const gp_Pnt & (BlendFunc_CSConstRad::*)() const) &BlendFunc_CSConstRad::PointOnC, "None");
cls_BRepBlend_CSConstRad.def("Pnt2d", (const gp_Pnt2d & (BlendFunc_CSConstRad::*)() const) &BlendFunc_CSConstRad::Pnt2d, "Returns U,V coordinates of the point on the surface.");
cls_BRepBlend_CSConstRad.def("ParameterOnC", (Standard_Real (BlendFunc_CSConstRad::*)() const) &BlendFunc_CSConstRad::ParameterOnC, "Returns parameter of the point on the curve.");
cls_BRepBlend_CSConstRad.def("IsTangencyPoint", (Standard_Boolean (BlendFunc_CSConstRad::*)() const) &BlendFunc_CSConstRad::IsTangencyPoint, "None");
cls_BRepBlend_CSConstRad.def("TangentOnS", (const gp_Vec & (BlendFunc_CSConstRad::*)() const) &BlendFunc_CSConstRad::TangentOnS, "None");
cls_BRepBlend_CSConstRad.def("Tangent2d", (const gp_Vec2d & (BlendFunc_CSConstRad::*)() const) &BlendFunc_CSConstRad::Tangent2d, "None");
cls_BRepBlend_CSConstRad.def("TangentOnC", (const gp_Vec & (BlendFunc_CSConstRad::*)() const) &BlendFunc_CSConstRad::TangentOnC, "None");
cls_BRepBlend_CSConstRad.def("Tangent", (void (BlendFunc_CSConstRad::*)(const Standard_Real, const Standard_Real, gp_Vec &, gp_Vec &) const) &BlendFunc_CSConstRad::Tangent, "Returns the tangent vector at the section, at the beginning and the end of the section, and returns the normal (of the surface) at these points.", py::arg("U"), py::arg("V"), py::arg("TgS"), py::arg("NormS"));
cls_BRepBlend_CSConstRad.def("Set", (void (BlendFunc_CSConstRad::*)(const Standard_Real, const Standard_Integer)) &BlendFunc_CSConstRad::Set, "None", py::arg("Radius"), py::arg("Choix"));
cls_BRepBlend_CSConstRad.def("Set", (void (BlendFunc_CSConstRad::*)(const BlendFunc_SectionShape)) &BlendFunc_CSConstRad::Set, "Sets the type of section generation for the approximations.", py::arg("TypeSection"));
cls_BRepBlend_CSConstRad.def("Section", [](BlendFunc_CSConstRad &self, const Standard_Real Param, const Standard_Real U, const Standard_Real V, const Standard_Real W, Standard_Real & Pdeb, Standard_Real & Pfin, gp_Circ & C){ self.Section(Param, U, V, W, Pdeb, Pfin, C); return std::tuple<Standard_Real &, Standard_Real &>(Pdeb, Pfin); }, "None", py::arg("Param"), py::arg("U"), py::arg("V"), py::arg("W"), py::arg("Pdeb"), py::arg("Pfin"), py::arg("C"));
cls_BRepBlend_CSConstRad.def("Section", (Standard_Boolean (BlendFunc_CSConstRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_CSConstRad::Section, "Used for the first and last section The method returns Standard_True if the derivatives are computed, otherwise it returns Standard_False.", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
cls_BRepBlend_CSConstRad.def("GetSection", (Standard_Boolean (BlendFunc_CSConstRad::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfVec &)) &BlendFunc_CSConstRad::GetSection, "None", py::arg("Param"), py::arg("U"), py::arg("V"), py::arg("W"), py::arg("tabP"), py::arg("tabV"));
cls_BRepBlend_CSConstRad.def("IsRational", (Standard_Boolean (BlendFunc_CSConstRad::*)() const) &BlendFunc_CSConstRad::IsRational, "Returns if the section is rationnal");
cls_BRepBlend_CSConstRad.def("GetSectionSize", (Standard_Real (BlendFunc_CSConstRad::*)() const) &BlendFunc_CSConstRad::GetSectionSize, "Returns the length of the maximum section");
cls_BRepBlend_CSConstRad.def("GetMinimalWeight", (void (BlendFunc_CSConstRad::*)(TColStd_Array1OfReal &) const) &BlendFunc_CSConstRad::GetMinimalWeight, "Compute the minimal value of weight for each poles of all sections.", py::arg("Weigths"));
cls_BRepBlend_CSConstRad.def("NbIntervals", (Standard_Integer (BlendFunc_CSConstRad::*)(const GeomAbs_Shape) const) &BlendFunc_CSConstRad::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_BRepBlend_CSConstRad.def("Intervals", (void (BlendFunc_CSConstRad::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &BlendFunc_CSConstRad::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>. The array must provide enough room to accomodate for the parameters. i.e. T.Length() > NbIntervals() raises OutOfRange from Standard", py::arg("T"), py::arg("S"));
cls_BRepBlend_CSConstRad.def("GetShape", [](BlendFunc_CSConstRad &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree, Standard_Integer & NbPoles2d){ self.GetShape(NbPoles, NbKnots, Degree, NbPoles2d); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree, NbPoles2d); }, "None", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"), py::arg("NbPoles2d"));
cls_BRepBlend_CSConstRad.def("GetTolerance", (void (BlendFunc_CSConstRad::*)(const Standard_Real, const Standard_Real, const Standard_Real, math_Vector &, math_Vector &) const) &BlendFunc_CSConstRad::GetTolerance, "Returns the tolerance to reach in approximation to respecte BoundTol error at the Boundary AngleTol tangent error at the Boundary SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"), py::arg("Tol1D"));
cls_BRepBlend_CSConstRad.def("Knots", (void (BlendFunc_CSConstRad::*)(TColStd_Array1OfReal &)) &BlendFunc_CSConstRad::Knots, "None", py::arg("TKnots"));
cls_BRepBlend_CSConstRad.def("Mults", (void (BlendFunc_CSConstRad::*)(TColStd_Array1OfInteger &)) &BlendFunc_CSConstRad::Mults, "None", py::arg("TMults"));
cls_BRepBlend_CSConstRad.def("Section", (Standard_Boolean (BlendFunc_CSConstRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_CSConstRad::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
cls_BRepBlend_CSConstRad.def("Section", (void (BlendFunc_CSConstRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &)) &BlendFunc_CSConstRad::Section, "None", py::arg("P"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
cls_BRepBlend_CSConstRad.def("Resolution", [](BlendFunc_CSConstRad &self, const Standard_Integer IC2d, const Standard_Real Tol, Standard_Real & TolU, Standard_Real & TolV){ self.Resolution(IC2d, Tol, TolU, TolV); return std::tuple<Standard_Real &, Standard_Real &>(TolU, TolV); }, "None", py::arg("IC2d"), py::arg("Tol"), py::arg("TolU"), py::arg("TolV"));

// CLASS: BREPBLEND_POINTONRST
py::class_<BRepBlend_PointOnRst> cls_BRepBlend_PointOnRst(mod, "BRepBlend_PointOnRst", "Definition of an intersection point between a line and a restriction on a surface. Such a point is contains geometrical informations (see the Value method) and logical informations.");

// Constructors
cls_BRepBlend_PointOnRst.def(py::init<>());
cls_BRepBlend_PointOnRst.def(py::init<const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, const IntSurf_Transition &, const IntSurf_Transition &>(), py::arg("A"), py::arg("Param"), py::arg("TLine"), py::arg("TArc"));

// Methods
// cls_BRepBlend_PointOnRst.def_static("operator new_", (void * (*)(size_t)) &BRepBlend_PointOnRst::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_PointOnRst.def_static("operator delete_", (void (*)(void *)) &BRepBlend_PointOnRst::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_PointOnRst.def_static("operator new[]_", (void * (*)(size_t)) &BRepBlend_PointOnRst::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_PointOnRst.def_static("operator delete[]_", (void (*)(void *)) &BRepBlend_PointOnRst::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_PointOnRst.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBlend_PointOnRst::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_PointOnRst.def_static("operator delete_", (void (*)(void *, void *)) &BRepBlend_PointOnRst::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_PointOnRst.def("SetArc", (void (BRepBlend_PointOnRst::*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, const IntSurf_Transition &, const IntSurf_Transition &)) &BRepBlend_PointOnRst::SetArc, "Sets the values of a point which is on the arc A, at parameter Param.", py::arg("A"), py::arg("Param"), py::arg("TLine"), py::arg("TArc"));
cls_BRepBlend_PointOnRst.def("Arc", (const opencascade::handle<Adaptor2d_HCurve2d> & (BRepBlend_PointOnRst::*)() const) &BRepBlend_PointOnRst::Arc, "Returns the arc of restriction containing the vertex.");
cls_BRepBlend_PointOnRst.def("TransitionOnLine", (const IntSurf_Transition & (BRepBlend_PointOnRst::*)() const) &BRepBlend_PointOnRst::TransitionOnLine, "Returns the transition of the point on the line on surface.");
cls_BRepBlend_PointOnRst.def("TransitionOnArc", (const IntSurf_Transition & (BRepBlend_PointOnRst::*)() const) &BRepBlend_PointOnRst::TransitionOnArc, "Returns the transition of the point on the arc returned by Arc().");
cls_BRepBlend_PointOnRst.def("ParameterOnArc", (Standard_Real (BRepBlend_PointOnRst::*)() const) &BRepBlend_PointOnRst::ParameterOnArc, "Returns the parameter of the point on the arc returned by the method Arc().");

// TYPEDEF: BREPBLEND_SEQUENCEOFPOINTONRST
bind_NCollection_Sequence<BRepBlend_PointOnRst>(mod, "BRepBlend_SequenceOfPointOnRst", py::module_local(false));

// CLASS: BREPBLEND_CSWALKING
py::class_<BRepBlend_CSWalking> cls_BRepBlend_CSWalking(mod, "BRepBlend_CSWalking", "None");

// Constructors
cls_BRepBlend_CSWalking.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &>(), py::arg("Curv"), py::arg("Surf"), py::arg("Domain"));

// Methods
// cls_BRepBlend_CSWalking.def_static("operator new_", (void * (*)(size_t)) &BRepBlend_CSWalking::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_CSWalking.def_static("operator delete_", (void (*)(void *)) &BRepBlend_CSWalking::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_CSWalking.def_static("operator new[]_", (void * (*)(size_t)) &BRepBlend_CSWalking::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_CSWalking.def_static("operator delete[]_", (void (*)(void *)) &BRepBlend_CSWalking::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_CSWalking.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBlend_CSWalking::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_CSWalking.def_static("operator delete_", (void (*)(void *, void *)) &BRepBlend_CSWalking::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_CSWalking.def("Perform", [](BRepBlend_CSWalking &self, Blend_CSFunction & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, const math_Vector & a5, const Standard_Real a6, const Standard_Real a7) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6, a7); });
cls_BRepBlend_CSWalking.def("Perform", (void (BRepBlend_CSWalking::*)(Blend_CSFunction &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const math_Vector &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &BRepBlend_CSWalking::Perform, "None", py::arg("F"), py::arg("Pdep"), py::arg("Pmax"), py::arg("MaxStep"), py::arg("TolGuide"), py::arg("Soldep"), py::arg("Tolesp"), py::arg("Fleche"), py::arg("Appro"));
cls_BRepBlend_CSWalking.def("Complete", (Standard_Boolean (BRepBlend_CSWalking::*)(Blend_CSFunction &, const Standard_Real)) &BRepBlend_CSWalking::Complete, "None", py::arg("F"), py::arg("Pmin"));
cls_BRepBlend_CSWalking.def("IsDone", (Standard_Boolean (BRepBlend_CSWalking::*)() const) &BRepBlend_CSWalking::IsDone, "None");
cls_BRepBlend_CSWalking.def("Line", (const opencascade::handle<BRepBlend_Line> & (BRepBlend_CSWalking::*)() const) &BRepBlend_CSWalking::Line, "None");

// CLASS: BREPBLEND_CURVPOINTRADINV
py::class_<BRepBlend_CurvPointRadInv, Blend_CurvPointFuncInv> cls_BRepBlend_CurvPointRadInv(mod, "BRepBlend_CurvPointRadInv", "Function of reframing between a point and a curve. valid in cases of constant and progressive radius. This function is used to find a solution on a done point of the curve 1 when using RstRstConsRad or CSConstRad... The vector <X> used in Value, Values and Derivatives methods has to be the vector of the parametric coordinates w, U where w is the parameter on the guide line, U are the parametric coordinates of a point on the partner curve 2.");

// Constructors
cls_BRepBlend_CurvPointRadInv.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("C1"), py::arg("C2"));

// Methods
// cls_BRepBlend_CurvPointRadInv.def_static("operator new_", (void * (*)(size_t)) &BRepBlend_CurvPointRadInv::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_CurvPointRadInv.def_static("operator delete_", (void (*)(void *)) &BRepBlend_CurvPointRadInv::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_CurvPointRadInv.def_static("operator new[]_", (void * (*)(size_t)) &BRepBlend_CurvPointRadInv::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_CurvPointRadInv.def_static("operator delete[]_", (void (*)(void *)) &BRepBlend_CurvPointRadInv::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_CurvPointRadInv.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBlend_CurvPointRadInv::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_CurvPointRadInv.def_static("operator delete_", (void (*)(void *, void *)) &BRepBlend_CurvPointRadInv::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_CurvPointRadInv.def("Set", (void (BRepBlend_CurvPointRadInv::*)(const Standard_Integer)) &BRepBlend_CurvPointRadInv::Set, "None", py::arg("Choix"));
cls_BRepBlend_CurvPointRadInv.def("NbEquations", (Standard_Integer (BRepBlend_CurvPointRadInv::*)() const) &BRepBlend_CurvPointRadInv::NbEquations, "returns 2.");
cls_BRepBlend_CurvPointRadInv.def("Value", (Standard_Boolean (BRepBlend_CurvPointRadInv::*)(const math_Vector &, math_Vector &)) &BRepBlend_CurvPointRadInv::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_BRepBlend_CurvPointRadInv.def("Derivatives", (Standard_Boolean (BRepBlend_CurvPointRadInv::*)(const math_Vector &, math_Matrix &)) &BRepBlend_CurvPointRadInv::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_BRepBlend_CurvPointRadInv.def("Values", (Standard_Boolean (BRepBlend_CurvPointRadInv::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BRepBlend_CurvPointRadInv::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_BRepBlend_CurvPointRadInv.def("Set", (void (BRepBlend_CurvPointRadInv::*)(const gp_Pnt &)) &BRepBlend_CurvPointRadInv::Set, "Set the Point on which a solution has to be found.", py::arg("P"));
cls_BRepBlend_CurvPointRadInv.def("GetTolerance", (void (BRepBlend_CurvPointRadInv::*)(math_Vector &, const Standard_Real) const) &BRepBlend_CurvPointRadInv::GetTolerance, "Returns in the vector Tolerance the parametric tolerance for each of the 3 variables; Tol is the tolerance used in 3d space.", py::arg("Tolerance"), py::arg("Tol"));
cls_BRepBlend_CurvPointRadInv.def("GetBounds", (void (BRepBlend_CurvPointRadInv::*)(math_Vector &, math_Vector &) const) &BRepBlend_CurvPointRadInv::GetBounds, "Returns in the vector InfBound the lowest values allowed for each of the 3 variables. Returns in the vector SupBound the greatest values allowed for each of the 3 variables.", py::arg("InfBound"), py::arg("SupBound"));
cls_BRepBlend_CurvPointRadInv.def("IsSolution", (Standard_Boolean (BRepBlend_CurvPointRadInv::*)(const math_Vector &, const Standard_Real)) &BRepBlend_CurvPointRadInv::IsSolution, "Returns Standard_True if Sol is a zero of the function. Tol is the tolerance used in 3d space.", py::arg("Sol"), py::arg("Tol"));

// TYPEDEF: BREPBLEND_EVOLRAD
py::class_<BlendFunc_EvolRad, Blend_Function> cls_BRepBlend_EvolRad(mod, "BRepBlend_EvolRad", "None", py::module_local());

// Constructors
cls_BRepBlend_EvolRad.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Law_Function> &>(), py::arg("S1"), py::arg("S2"), py::arg("C"), py::arg("Law"));

// Methods
// cls_BRepBlend_EvolRad.def_static("operator new_", (void * (*)(size_t)) &BlendFunc_EvolRad::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_EvolRad.def_static("operator delete_", (void (*)(void *)) &BlendFunc_EvolRad::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_EvolRad.def_static("operator new[]_", (void * (*)(size_t)) &BlendFunc_EvolRad::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_EvolRad.def_static("operator delete[]_", (void (*)(void *)) &BlendFunc_EvolRad::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_EvolRad.def_static("operator new_", (void * (*)(size_t, void *)) &BlendFunc_EvolRad::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_EvolRad.def_static("operator delete_", (void (*)(void *, void *)) &BlendFunc_EvolRad::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_EvolRad.def("NbEquations", (Standard_Integer (BlendFunc_EvolRad::*)() const) &BlendFunc_EvolRad::NbEquations, "returns the number of equations of the function.");
cls_BRepBlend_EvolRad.def("Value", (Standard_Boolean (BlendFunc_EvolRad::*)(const math_Vector &, math_Vector &)) &BlendFunc_EvolRad::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_BRepBlend_EvolRad.def("Derivatives", (Standard_Boolean (BlendFunc_EvolRad::*)(const math_Vector &, math_Matrix &)) &BlendFunc_EvolRad::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_BRepBlend_EvolRad.def("Values", (Standard_Boolean (BlendFunc_EvolRad::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BlendFunc_EvolRad::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_BRepBlend_EvolRad.def("Set", (void (BlendFunc_EvolRad::*)(const Standard_Real)) &BlendFunc_EvolRad::Set, "None", py::arg("Param"));
cls_BRepBlend_EvolRad.def("Set", (void (BlendFunc_EvolRad::*)(const Standard_Real, const Standard_Real)) &BlendFunc_EvolRad::Set, "None", py::arg("First"), py::arg("Last"));
cls_BRepBlend_EvolRad.def("GetTolerance", (void (BlendFunc_EvolRad::*)(math_Vector &, const Standard_Real) const) &BlendFunc_EvolRad::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
cls_BRepBlend_EvolRad.def("GetBounds", (void (BlendFunc_EvolRad::*)(math_Vector &, math_Vector &) const) &BlendFunc_EvolRad::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
cls_BRepBlend_EvolRad.def("IsSolution", (Standard_Boolean (BlendFunc_EvolRad::*)(const math_Vector &, const Standard_Real)) &BlendFunc_EvolRad::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
cls_BRepBlend_EvolRad.def("GetMinimalDistance", (Standard_Real (BlendFunc_EvolRad::*)() const) &BlendFunc_EvolRad::GetMinimalDistance, "Returns the minimal Distance beetween two extremitys of calculed sections.");
cls_BRepBlend_EvolRad.def("PointOnS1", (const gp_Pnt & (BlendFunc_EvolRad::*)() const) &BlendFunc_EvolRad::PointOnS1, "None");
cls_BRepBlend_EvolRad.def("PointOnS2", (const gp_Pnt & (BlendFunc_EvolRad::*)() const) &BlendFunc_EvolRad::PointOnS2, "None");
cls_BRepBlend_EvolRad.def("IsTangencyPoint", (Standard_Boolean (BlendFunc_EvolRad::*)() const) &BlendFunc_EvolRad::IsTangencyPoint, "None");
cls_BRepBlend_EvolRad.def("TangentOnS1", (const gp_Vec & (BlendFunc_EvolRad::*)() const) &BlendFunc_EvolRad::TangentOnS1, "None");
cls_BRepBlend_EvolRad.def("Tangent2dOnS1", (const gp_Vec2d & (BlendFunc_EvolRad::*)() const) &BlendFunc_EvolRad::Tangent2dOnS1, "None");
cls_BRepBlend_EvolRad.def("TangentOnS2", (const gp_Vec & (BlendFunc_EvolRad::*)() const) &BlendFunc_EvolRad::TangentOnS2, "None");
cls_BRepBlend_EvolRad.def("Tangent2dOnS2", (const gp_Vec2d & (BlendFunc_EvolRad::*)() const) &BlendFunc_EvolRad::Tangent2dOnS2, "None");
cls_BRepBlend_EvolRad.def("Tangent", (void (BlendFunc_EvolRad::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &BlendFunc_EvolRad::Tangent, "Returns the tangent vector at the section, at the beginning and the end of the section, and returns the normal (of the surfaces) at these points.", py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("TgFirst"), py::arg("TgLast"), py::arg("NormFirst"), py::arg("NormLast"));
cls_BRepBlend_EvolRad.def("TwistOnS1", (Standard_Boolean (BlendFunc_EvolRad::*)() const) &BlendFunc_EvolRad::TwistOnS1, "None");
cls_BRepBlend_EvolRad.def("TwistOnS2", (Standard_Boolean (BlendFunc_EvolRad::*)() const) &BlendFunc_EvolRad::TwistOnS2, "None");
cls_BRepBlend_EvolRad.def("Set", (void (BlendFunc_EvolRad::*)(const Standard_Integer)) &BlendFunc_EvolRad::Set, "None", py::arg("Choix"));
cls_BRepBlend_EvolRad.def("Set", (void (BlendFunc_EvolRad::*)(const BlendFunc_SectionShape)) &BlendFunc_EvolRad::Set, "Sets the type of section generation for the approximations.", py::arg("TypeSection"));
cls_BRepBlend_EvolRad.def("Section", [](BlendFunc_EvolRad &self, const Standard_Real Param, const Standard_Real U1, const Standard_Real V1, const Standard_Real U2, const Standard_Real V2, Standard_Real & Pdeb, Standard_Real & Pfin, gp_Circ & C){ self.Section(Param, U1, V1, U2, V2, Pdeb, Pfin, C); return std::tuple<Standard_Real &, Standard_Real &>(Pdeb, Pfin); }, "Method for graphic traces", py::arg("Param"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("Pdeb"), py::arg("Pfin"), py::arg("C"));
cls_BRepBlend_EvolRad.def("IsRational", (Standard_Boolean (BlendFunc_EvolRad::*)() const) &BlendFunc_EvolRad::IsRational, "Returns if the section is rationnal");
cls_BRepBlend_EvolRad.def("GetSectionSize", (Standard_Real (BlendFunc_EvolRad::*)() const) &BlendFunc_EvolRad::GetSectionSize, "Returns the length of the maximum section");
cls_BRepBlend_EvolRad.def("GetMinimalWeight", (void (BlendFunc_EvolRad::*)(TColStd_Array1OfReal &) const) &BlendFunc_EvolRad::GetMinimalWeight, "Compute the minimal value of weight for each poles of all sections.", py::arg("Weigths"));
cls_BRepBlend_EvolRad.def("NbIntervals", (Standard_Integer (BlendFunc_EvolRad::*)(const GeomAbs_Shape) const) &BlendFunc_EvolRad::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_BRepBlend_EvolRad.def("Intervals", (void (BlendFunc_EvolRad::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &BlendFunc_EvolRad::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_BRepBlend_EvolRad.def("GetShape", [](BlendFunc_EvolRad &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree, Standard_Integer & NbPoles2d){ self.GetShape(NbPoles, NbKnots, Degree, NbPoles2d); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree, NbPoles2d); }, "None", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"), py::arg("NbPoles2d"));
cls_BRepBlend_EvolRad.def("GetTolerance", (void (BlendFunc_EvolRad::*)(const Standard_Real, const Standard_Real, const Standard_Real, math_Vector &, math_Vector &) const) &BlendFunc_EvolRad::GetTolerance, "Returns the tolerance to reach in approximation to respecte BoundTol error at the Boundary AngleTol tangent error at the Boundary SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"), py::arg("Tol1D"));
cls_BRepBlend_EvolRad.def("Knots", (void (BlendFunc_EvolRad::*)(TColStd_Array1OfReal &)) &BlendFunc_EvolRad::Knots, "None", py::arg("TKnots"));
cls_BRepBlend_EvolRad.def("Mults", (void (BlendFunc_EvolRad::*)(TColStd_Array1OfInteger &)) &BlendFunc_EvolRad::Mults, "None", py::arg("TMults"));
cls_BRepBlend_EvolRad.def("Section", (Standard_Boolean (BlendFunc_EvolRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_EvolRad::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
cls_BRepBlend_EvolRad.def("Section", (Standard_Boolean (BlendFunc_EvolRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_EvolRad::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
cls_BRepBlend_EvolRad.def("Section", (void (BlendFunc_EvolRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &)) &BlendFunc_EvolRad::Section, "None", py::arg("P"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
cls_BRepBlend_EvolRad.def("Resolution", [](BlendFunc_EvolRad &self, const Standard_Integer IC2d, const Standard_Real Tol, Standard_Real & TolU, Standard_Real & TolV){ self.Resolution(IC2d, Tol, TolU, TolV); return std::tuple<Standard_Real &, Standard_Real &>(TolU, TolV); }, "None", py::arg("IC2d"), py::arg("Tol"), py::arg("TolU"), py::arg("TolV"));

// TYPEDEF: BREPBLEND_EVOLRADINV
py::class_<BlendFunc_EvolRadInv, Blend_FuncInv> cls_BRepBlend_EvolRadInv(mod, "BRepBlend_EvolRadInv", "None", py::module_local());

// Constructors
cls_BRepBlend_EvolRadInv.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Law_Function> &>(), py::arg("S1"), py::arg("S2"), py::arg("C"), py::arg("Law"));

// Methods
// cls_BRepBlend_EvolRadInv.def_static("operator new_", (void * (*)(size_t)) &BlendFunc_EvolRadInv::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_EvolRadInv.def_static("operator delete_", (void (*)(void *)) &BlendFunc_EvolRadInv::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_EvolRadInv.def_static("operator new[]_", (void * (*)(size_t)) &BlendFunc_EvolRadInv::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_EvolRadInv.def_static("operator delete[]_", (void (*)(void *)) &BlendFunc_EvolRadInv::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_EvolRadInv.def_static("operator new_", (void * (*)(size_t, void *)) &BlendFunc_EvolRadInv::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_EvolRadInv.def_static("operator delete_", (void (*)(void *, void *)) &BlendFunc_EvolRadInv::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_EvolRadInv.def("Set", (void (BlendFunc_EvolRadInv::*)(const Standard_Boolean, const opencascade::handle<Adaptor2d_HCurve2d> &)) &BlendFunc_EvolRadInv::Set, "None", py::arg("OnFirst"), py::arg("COnSurf"));
cls_BRepBlend_EvolRadInv.def("GetTolerance", (void (BlendFunc_EvolRadInv::*)(math_Vector &, const Standard_Real) const) &BlendFunc_EvolRadInv::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
cls_BRepBlend_EvolRadInv.def("GetBounds", (void (BlendFunc_EvolRadInv::*)(math_Vector &, math_Vector &) const) &BlendFunc_EvolRadInv::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
cls_BRepBlend_EvolRadInv.def("IsSolution", (Standard_Boolean (BlendFunc_EvolRadInv::*)(const math_Vector &, const Standard_Real)) &BlendFunc_EvolRadInv::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
cls_BRepBlend_EvolRadInv.def("NbEquations", (Standard_Integer (BlendFunc_EvolRadInv::*)() const) &BlendFunc_EvolRadInv::NbEquations, "returns the number of equations of the function.");
cls_BRepBlend_EvolRadInv.def("Value", (Standard_Boolean (BlendFunc_EvolRadInv::*)(const math_Vector &, math_Vector &)) &BlendFunc_EvolRadInv::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_BRepBlend_EvolRadInv.def("Derivatives", (Standard_Boolean (BlendFunc_EvolRadInv::*)(const math_Vector &, math_Matrix &)) &BlendFunc_EvolRadInv::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_BRepBlend_EvolRadInv.def("Values", (Standard_Boolean (BlendFunc_EvolRadInv::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BlendFunc_EvolRadInv::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_BRepBlend_EvolRadInv.def("Set", (void (BlendFunc_EvolRadInv::*)(const Standard_Integer)) &BlendFunc_EvolRadInv::Set, "None", py::arg("Choix"));

// CLASS: BREPBLEND_EXTREMITY
py::class_<BRepBlend_Extremity> cls_BRepBlend_Extremity(mod, "BRepBlend_Extremity", "None");

// Constructors
cls_BRepBlend_Extremity.def(py::init<>());
cls_BRepBlend_Extremity.def(py::init<const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("U"), py::arg("V"), py::arg("Param"), py::arg("Tol"));
cls_BRepBlend_Extremity.def(py::init<const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const opencascade::handle<Adaptor3d_HVertex> &>(), py::arg("P"), py::arg("U"), py::arg("V"), py::arg("Param"), py::arg("Tol"), py::arg("Vtx"));
cls_BRepBlend_Extremity.def(py::init<const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("W"), py::arg("Param"), py::arg("Tol"));

// Methods
// cls_BRepBlend_Extremity.def_static("operator new_", (void * (*)(size_t)) &BRepBlend_Extremity::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_Extremity.def_static("operator delete_", (void (*)(void *)) &BRepBlend_Extremity::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_Extremity.def_static("operator new[]_", (void * (*)(size_t)) &BRepBlend_Extremity::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_Extremity.def_static("operator delete[]_", (void (*)(void *)) &BRepBlend_Extremity::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_Extremity.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBlend_Extremity::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_Extremity.def_static("operator delete_", (void (*)(void *, void *)) &BRepBlend_Extremity::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_Extremity.def("SetValue", (void (BRepBlend_Extremity::*)(const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &BRepBlend_Extremity::SetValue, "Set the values for an extremity on a surface.", py::arg("P"), py::arg("U"), py::arg("V"), py::arg("Param"), py::arg("Tol"));
cls_BRepBlend_Extremity.def("SetValue", (void (BRepBlend_Extremity::*)(const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const opencascade::handle<Adaptor3d_HVertex> &)) &BRepBlend_Extremity::SetValue, "Set the values for an extremity on a surface.This extremity matches the vertex <Vtx>.", py::arg("P"), py::arg("U"), py::arg("V"), py::arg("Param"), py::arg("Tol"), py::arg("Vtx"));
cls_BRepBlend_Extremity.def("SetValue", (void (BRepBlend_Extremity::*)(const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real)) &BRepBlend_Extremity::SetValue, "Set the values for an extremity on curve.", py::arg("P"), py::arg("W"), py::arg("Param"), py::arg("Tol"));
cls_BRepBlend_Extremity.def("Value", (const gp_Pnt & (BRepBlend_Extremity::*)() const) &BRepBlend_Extremity::Value, "This method returns the value of the point in 3d space.");
cls_BRepBlend_Extremity.def("SetTangent", (void (BRepBlend_Extremity::*)(const gp_Vec &)) &BRepBlend_Extremity::SetTangent, "Set the tangent vector for an extremity on a surface.", py::arg("Tangent"));
cls_BRepBlend_Extremity.def("HasTangent", (Standard_Boolean (BRepBlend_Extremity::*)() const) &BRepBlend_Extremity::HasTangent, "Returns TRUE if the Tangent is stored.");
cls_BRepBlend_Extremity.def("Tangent", (const gp_Vec & (BRepBlend_Extremity::*)() const) &BRepBlend_Extremity::Tangent, "This method returns the value of tangent in 3d space.");
cls_BRepBlend_Extremity.def("Tolerance", (Standard_Real (BRepBlend_Extremity::*)() const) &BRepBlend_Extremity::Tolerance, "This method returns the fuzziness on the point in 3d space.");
cls_BRepBlend_Extremity.def("SetVertex", (void (BRepBlend_Extremity::*)(const opencascade::handle<Adaptor3d_HVertex> &)) &BRepBlend_Extremity::SetVertex, "Set the values for an extremity on a curve.", py::arg("V"));
cls_BRepBlend_Extremity.def("AddArc", (void (BRepBlend_Extremity::*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, const IntSurf_Transition &, const IntSurf_Transition &)) &BRepBlend_Extremity::AddArc, "Sets the values of a point which is on the arc A, at parameter Param.", py::arg("A"), py::arg("Param"), py::arg("TLine"), py::arg("TArc"));
cls_BRepBlend_Extremity.def("Parameters", [](BRepBlend_Extremity &self, Standard_Real & U, Standard_Real & V){ self.Parameters(U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "This method returns the parameters of the point on the concerned surface.", py::arg("U"), py::arg("V"));
cls_BRepBlend_Extremity.def("IsVertex", (Standard_Boolean (BRepBlend_Extremity::*)() const) &BRepBlend_Extremity::IsVertex, "Returns Standard_True when the point coincide with an existing vertex.");
cls_BRepBlend_Extremity.def("Vertex", (const opencascade::handle<Adaptor3d_HVertex> & (BRepBlend_Extremity::*)() const) &BRepBlend_Extremity::Vertex, "Returns the vertex when IsVertex returns Standard_True.");
cls_BRepBlend_Extremity.def("NbPointOnRst", (Standard_Integer (BRepBlend_Extremity::*)() const) &BRepBlend_Extremity::NbPointOnRst, "Returns the number of arc containing the extremity. If the method returns 0, the point is inside the surface. Otherwise, the extremity lies on at least 1 arc, and all the information (arc, parameter, transitions) are given by the point on restriction (PointOnRst) returned by the next method.");
cls_BRepBlend_Extremity.def("PointOnRst", (const BRepBlend_PointOnRst & (BRepBlend_Extremity::*)(const Standard_Integer) const) &BRepBlend_Extremity::PointOnRst, "None", py::arg("Index"));
cls_BRepBlend_Extremity.def("Parameter", (Standard_Real (BRepBlend_Extremity::*)() const) &BRepBlend_Extremity::Parameter, "None");
cls_BRepBlend_Extremity.def("ParameterOnGuide", (Standard_Real (BRepBlend_Extremity::*)() const) &BRepBlend_Extremity::ParameterOnGuide, "None");

// CLASS: BREPBLEND_HCURVE2DTOOL
py::class_<BRepBlend_HCurve2dTool> cls_BRepBlend_HCurve2dTool(mod, "BRepBlend_HCurve2dTool", "None");

// Methods
// cls_BRepBlend_HCurve2dTool.def_static("operator new_", (void * (*)(size_t)) &BRepBlend_HCurve2dTool::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_HCurve2dTool.def_static("operator delete_", (void (*)(void *)) &BRepBlend_HCurve2dTool::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_HCurve2dTool.def_static("operator new[]_", (void * (*)(size_t)) &BRepBlend_HCurve2dTool::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_HCurve2dTool.def_static("operator delete[]_", (void (*)(void *)) &BRepBlend_HCurve2dTool::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_HCurve2dTool.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBlend_HCurve2dTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_HCurve2dTool.def_static("operator delete_", (void (*)(void *, void *)) &BRepBlend_HCurve2dTool::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_HCurve2dTool.def_static("FirstParameter_", (Standard_Real (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_HCurve2dTool::FirstParameter, "None", py::arg("C"));
cls_BRepBlend_HCurve2dTool.def_static("LastParameter_", (Standard_Real (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_HCurve2dTool::LastParameter, "None", py::arg("C"));
cls_BRepBlend_HCurve2dTool.def_static("Continuity_", (GeomAbs_Shape (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_HCurve2dTool::Continuity, "None", py::arg("C"));
cls_BRepBlend_HCurve2dTool.def_static("NbIntervals_", (Standard_Integer (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const GeomAbs_Shape)) &BRepBlend_HCurve2dTool::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(myclass) >= <S>", py::arg("C"), py::arg("S"));
cls_BRepBlend_HCurve2dTool.def_static("Intervals_", (void (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, TColStd_Array1OfReal &, const GeomAbs_Shape)) &BRepBlend_HCurve2dTool::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("C"), py::arg("T"), py::arg("S"));
cls_BRepBlend_HCurve2dTool.def_static("IsClosed_", (Standard_Boolean (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_HCurve2dTool::IsClosed, "None", py::arg("C"));
cls_BRepBlend_HCurve2dTool.def_static("IsPeriodic_", (Standard_Boolean (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_HCurve2dTool::IsPeriodic, "None", py::arg("C"));
cls_BRepBlend_HCurve2dTool.def_static("Period_", (Standard_Real (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_HCurve2dTool::Period, "None", py::arg("C"));
cls_BRepBlend_HCurve2dTool.def_static("Value_", (gp_Pnt2d (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real)) &BRepBlend_HCurve2dTool::Value, "Computes the point of parameter U on the curve.", py::arg("C"), py::arg("U"));
cls_BRepBlend_HCurve2dTool.def_static("D0_", (void (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, gp_Pnt2d &)) &BRepBlend_HCurve2dTool::D0, "Computes the point of parameter U on the curve.", py::arg("C"), py::arg("U"), py::arg("P"));
cls_BRepBlend_HCurve2dTool.def_static("D1_", (void (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, gp_Pnt2d &, gp_Vec2d &)) &BRepBlend_HCurve2dTool::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V"));
cls_BRepBlend_HCurve2dTool.def_static("D2_", (void (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &)) &BRepBlend_HCurve2dTool::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_BRepBlend_HCurve2dTool.def_static("D3_", (void (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &)) &BRepBlend_HCurve2dTool::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C3.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_BRepBlend_HCurve2dTool.def_static("DN_", (gp_Vec2d (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, const Standard_Integer)) &BRepBlend_HCurve2dTool::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if the continuity of the current interval is not CN. Raised if N < 1.", py::arg("C"), py::arg("U"), py::arg("N"));
cls_BRepBlend_HCurve2dTool.def_static("Resolution_", (Standard_Real (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real)) &BRepBlend_HCurve2dTool::Resolution, "Returns the parametric resolution corresponding to the real space resolution <R3d>.", py::arg("C"), py::arg("R3d"));
cls_BRepBlend_HCurve2dTool.def_static("GetType_", (GeomAbs_CurveType (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_HCurve2dTool::GetType, "Returns the type of the curve in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.", py::arg("C"));
cls_BRepBlend_HCurve2dTool.def_static("Line_", (gp_Lin2d (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_HCurve2dTool::Line, "None", py::arg("C"));
cls_BRepBlend_HCurve2dTool.def_static("Circle_", (gp_Circ2d (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_HCurve2dTool::Circle, "None", py::arg("C"));
cls_BRepBlend_HCurve2dTool.def_static("Ellipse_", (gp_Elips2d (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_HCurve2dTool::Ellipse, "None", py::arg("C"));
cls_BRepBlend_HCurve2dTool.def_static("Hyperbola_", (gp_Hypr2d (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_HCurve2dTool::Hyperbola, "None", py::arg("C"));
cls_BRepBlend_HCurve2dTool.def_static("Parabola_", (gp_Parab2d (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_HCurve2dTool::Parabola, "None", py::arg("C"));
cls_BRepBlend_HCurve2dTool.def_static("Bezier_", (opencascade::handle<Geom2d_BezierCurve> (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_HCurve2dTool::Bezier, "None", py::arg("C"));
cls_BRepBlend_HCurve2dTool.def_static("BSpline_", (opencascade::handle<Geom2d_BSplineCurve> (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_HCurve2dTool::BSpline, "None", py::arg("C"));
cls_BRepBlend_HCurve2dTool.def_static("NbSamples_", (Standard_Integer (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, const Standard_Real)) &BRepBlend_HCurve2dTool::NbSamples, "None", py::arg("C"), py::arg("U0"), py::arg("U1"));

// CLASS: BREPBLEND_HCURVETOOL
py::class_<BRepBlend_HCurveTool> cls_BRepBlend_HCurveTool(mod, "BRepBlend_HCurveTool", "None");

// Methods
// cls_BRepBlend_HCurveTool.def_static("operator new_", (void * (*)(size_t)) &BRepBlend_HCurveTool::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_HCurveTool.def_static("operator delete_", (void (*)(void *)) &BRepBlend_HCurveTool::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_HCurveTool.def_static("operator new[]_", (void * (*)(size_t)) &BRepBlend_HCurveTool::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_HCurveTool.def_static("operator delete[]_", (void (*)(void *)) &BRepBlend_HCurveTool::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_HCurveTool.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBlend_HCurveTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_HCurveTool.def_static("operator delete_", (void (*)(void *, void *)) &BRepBlend_HCurveTool::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_HCurveTool.def_static("FirstParameter_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &BRepBlend_HCurveTool::FirstParameter, "None", py::arg("C"));
cls_BRepBlend_HCurveTool.def_static("LastParameter_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &BRepBlend_HCurveTool::LastParameter, "None", py::arg("C"));
cls_BRepBlend_HCurveTool.def_static("Continuity_", (GeomAbs_Shape (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &BRepBlend_HCurveTool::Continuity, "None", py::arg("C"));
cls_BRepBlend_HCurveTool.def_static("NbIntervals_", (Standard_Integer (*)(const opencascade::handle<Adaptor3d_HCurve> &, const GeomAbs_Shape)) &BRepBlend_HCurveTool::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(myclass) >= <S>", py::arg("C"), py::arg("S"));
cls_BRepBlend_HCurveTool.def_static("Intervals_", (void (*)(const opencascade::handle<Adaptor3d_HCurve> &, TColStd_Array1OfReal &, const GeomAbs_Shape)) &BRepBlend_HCurveTool::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("C"), py::arg("T"), py::arg("S"));
cls_BRepBlend_HCurveTool.def_static("IsClosed_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &BRepBlend_HCurveTool::IsClosed, "None", py::arg("C"));
cls_BRepBlend_HCurveTool.def_static("IsPeriodic_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &BRepBlend_HCurveTool::IsPeriodic, "None", py::arg("C"));
cls_BRepBlend_HCurveTool.def_static("Period_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &BRepBlend_HCurveTool::Period, "None", py::arg("C"));
cls_BRepBlend_HCurveTool.def_static("Value_", (gp_Pnt (*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real)) &BRepBlend_HCurveTool::Value, "Computes the point of parameter U on the curve.", py::arg("C"), py::arg("U"));
cls_BRepBlend_HCurveTool.def_static("D0_", (void (*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, gp_Pnt &)) &BRepBlend_HCurveTool::D0, "Computes the point of parameter U on the curve.", py::arg("C"), py::arg("U"), py::arg("P"));
cls_BRepBlend_HCurveTool.def_static("D1_", (void (*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, gp_Pnt &, gp_Vec &)) &BRepBlend_HCurveTool::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V"));
cls_BRepBlend_HCurveTool.def_static("D2_", (void (*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &)) &BRepBlend_HCurveTool::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_BRepBlend_HCurveTool.def_static("D3_", (void (*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &)) &BRepBlend_HCurveTool::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C3.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_BRepBlend_HCurveTool.def_static("DN_", (gp_Vec (*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, const Standard_Integer)) &BRepBlend_HCurveTool::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if the continuity of the current interval is not CN. Raised if N < 1.", py::arg("C"), py::arg("U"), py::arg("N"));
cls_BRepBlend_HCurveTool.def_static("Resolution_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real)) &BRepBlend_HCurveTool::Resolution, "Returns the parametric resolution corresponding to the real space resolution <R3d>.", py::arg("C"), py::arg("R3d"));
cls_BRepBlend_HCurveTool.def_static("GetType_", (GeomAbs_CurveType (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &BRepBlend_HCurveTool::GetType, "Returns the type of the curve in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.", py::arg("C"));
cls_BRepBlend_HCurveTool.def_static("Line_", (gp_Lin (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &BRepBlend_HCurveTool::Line, "None", py::arg("C"));
cls_BRepBlend_HCurveTool.def_static("Circle_", (gp_Circ (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &BRepBlend_HCurveTool::Circle, "None", py::arg("C"));
cls_BRepBlend_HCurveTool.def_static("Ellipse_", (gp_Elips (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &BRepBlend_HCurveTool::Ellipse, "None", py::arg("C"));
cls_BRepBlend_HCurveTool.def_static("Hyperbola_", (gp_Hypr (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &BRepBlend_HCurveTool::Hyperbola, "None", py::arg("C"));
cls_BRepBlend_HCurveTool.def_static("Parabola_", (gp_Parab (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &BRepBlend_HCurveTool::Parabola, "None", py::arg("C"));
cls_BRepBlend_HCurveTool.def_static("Bezier_", (opencascade::handle<Geom_BezierCurve> (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &BRepBlend_HCurveTool::Bezier, "None", py::arg("C"));
cls_BRepBlend_HCurveTool.def_static("BSpline_", (opencascade::handle<Geom_BSplineCurve> (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &BRepBlend_HCurveTool::BSpline, "None", py::arg("C"));
cls_BRepBlend_HCurveTool.def_static("NbSamples_", (Standard_Integer (*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, const Standard_Real)) &BRepBlend_HCurveTool::NbSamples, "None", py::arg("C"), py::arg("U0"), py::arg("U1"));

// CLASS: BREPBLEND_LINE
py::class_<BRepBlend_Line, opencascade::handle<BRepBlend_Line>, Standard_Transient> cls_BRepBlend_Line(mod, "BRepBlend_Line", "None");

// Constructors
cls_BRepBlend_Line.def(py::init<>());

// Methods
cls_BRepBlend_Line.def("Clear", (void (BRepBlend_Line::*)()) &BRepBlend_Line::Clear, "Clears the content of the line.");
cls_BRepBlend_Line.def("Append", (void (BRepBlend_Line::*)(const Blend_Point &)) &BRepBlend_Line::Append, "Adds a point in the line.", py::arg("P"));
cls_BRepBlend_Line.def("Prepend", (void (BRepBlend_Line::*)(const Blend_Point &)) &BRepBlend_Line::Prepend, "Adds a point in the line at the first place.", py::arg("P"));
cls_BRepBlend_Line.def("InsertBefore", (void (BRepBlend_Line::*)(const Standard_Integer, const Blend_Point &)) &BRepBlend_Line::InsertBefore, "Adds a point in the line at the first place.", py::arg("Index"), py::arg("P"));
cls_BRepBlend_Line.def("Remove", (void (BRepBlend_Line::*)(const Standard_Integer, const Standard_Integer)) &BRepBlend_Line::Remove, "Removes from <me> all the items of positions between <FromIndex> and <ToIndex>. Raises an exception if the indices are out of bounds.", py::arg("FromIndex"), py::arg("ToIndex"));
cls_BRepBlend_Line.def("Set", (void (BRepBlend_Line::*)(const IntSurf_TypeTrans, const IntSurf_TypeTrans)) &BRepBlend_Line::Set, "Sets the value of the transition of the line on S1 and the line on S2.", py::arg("TranS1"), py::arg("TranS2"));
cls_BRepBlend_Line.def("Set", (void (BRepBlend_Line::*)(const IntSurf_TypeTrans)) &BRepBlend_Line::Set, "Sets the value of the transition of the line on a surface", py::arg("Trans"));
cls_BRepBlend_Line.def("SetStartPoints", (void (BRepBlend_Line::*)(const BRepBlend_Extremity &, const BRepBlend_Extremity &)) &BRepBlend_Line::SetStartPoints, "Sets the values of the start points for the line.", py::arg("StartPt1"), py::arg("StartPt2"));
cls_BRepBlend_Line.def("SetEndPoints", (void (BRepBlend_Line::*)(const BRepBlend_Extremity &, const BRepBlend_Extremity &)) &BRepBlend_Line::SetEndPoints, "Sets tne values of the end points for the line.", py::arg("EndPt1"), py::arg("EndPt2"));
cls_BRepBlend_Line.def("NbPoints", (Standard_Integer (BRepBlend_Line::*)() const) &BRepBlend_Line::NbPoints, "Returns the number of points in the line.");
cls_BRepBlend_Line.def("Point", (const Blend_Point & (BRepBlend_Line::*)(const Standard_Integer) const) &BRepBlend_Line::Point, "Returns the point of range Index.", py::arg("Index"));
cls_BRepBlend_Line.def("TransitionOnS1", (IntSurf_TypeTrans (BRepBlend_Line::*)() const) &BRepBlend_Line::TransitionOnS1, "Returns the type of the transition of the line defined on the first surface. The transition is 'constant' along the line. The transition is IN if the line is oriented in such a way that the system of vectors (N,DRac,T) is right-handed, where N is the normal to the first surface at a point P, DRac is a vector tangent to the blending patch, oriented towards the valid part of this patch, T is the tangent to the line on S1 at P. The transitioon is OUT when the system of vectors is left-handed.");
cls_BRepBlend_Line.def("TransitionOnS2", (IntSurf_TypeTrans (BRepBlend_Line::*)() const) &BRepBlend_Line::TransitionOnS2, "Returns the type of the transition of the line defined on the second surface. The transition is 'constant' along the line.");
cls_BRepBlend_Line.def("StartPointOnFirst", (const BRepBlend_Extremity & (BRepBlend_Line::*)() const) &BRepBlend_Line::StartPointOnFirst, "Returns the start point on S1.");
cls_BRepBlend_Line.def("StartPointOnSecond", (const BRepBlend_Extremity & (BRepBlend_Line::*)() const) &BRepBlend_Line::StartPointOnSecond, "Returns the start point on S2");
cls_BRepBlend_Line.def("EndPointOnFirst", (const BRepBlend_Extremity & (BRepBlend_Line::*)() const) &BRepBlend_Line::EndPointOnFirst, "Returns the end point on S1.");
cls_BRepBlend_Line.def("EndPointOnSecond", (const BRepBlend_Extremity & (BRepBlend_Line::*)() const) &BRepBlend_Line::EndPointOnSecond, "Returns the point on S2.");
cls_BRepBlend_Line.def("TransitionOnS", (IntSurf_TypeTrans (BRepBlend_Line::*)() const) &BRepBlend_Line::TransitionOnS, "Returns the type of the transition of the line defined on the surface.");
cls_BRepBlend_Line.def_static("get_type_name_", (const char * (*)()) &BRepBlend_Line::get_type_name, "None");
cls_BRepBlend_Line.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepBlend_Line::get_type_descriptor, "None");
cls_BRepBlend_Line.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepBlend_Line::*)() const) &BRepBlend_Line::DynamicType, "None");

// CLASS: BREPBLEND_RSTRSTCONSTRAD
py::class_<BRepBlend_RstRstConstRad, Blend_RstRstFunction> cls_BRepBlend_RstRstConstRad(mod, "BRepBlend_RstRstConstRad", "Copy of CSConstRad with a pcurve on surface as support.");

// Constructors
cls_BRepBlend_RstRstConstRad.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("Surf1"), py::arg("Rst1"), py::arg("Surf2"), py::arg("Rst2"), py::arg("CGuide"));

// Methods
// cls_BRepBlend_RstRstConstRad.def_static("operator new_", (void * (*)(size_t)) &BRepBlend_RstRstConstRad::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_RstRstConstRad.def_static("operator delete_", (void (*)(void *)) &BRepBlend_RstRstConstRad::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_RstRstConstRad.def_static("operator new[]_", (void * (*)(size_t)) &BRepBlend_RstRstConstRad::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_RstRstConstRad.def_static("operator delete[]_", (void (*)(void *)) &BRepBlend_RstRstConstRad::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_RstRstConstRad.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBlend_RstRstConstRad::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_RstRstConstRad.def_static("operator delete_", (void (*)(void *, void *)) &BRepBlend_RstRstConstRad::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_RstRstConstRad.def("NbVariables", (Standard_Integer (BRepBlend_RstRstConstRad::*)() const) &BRepBlend_RstRstConstRad::NbVariables, "Returns 2.");
cls_BRepBlend_RstRstConstRad.def("NbEquations", (Standard_Integer (BRepBlend_RstRstConstRad::*)() const) &BRepBlend_RstRstConstRad::NbEquations, "Returns 2.");
cls_BRepBlend_RstRstConstRad.def("Value", (Standard_Boolean (BRepBlend_RstRstConstRad::*)(const math_Vector &, math_Vector &)) &BRepBlend_RstRstConstRad::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_BRepBlend_RstRstConstRad.def("Derivatives", (Standard_Boolean (BRepBlend_RstRstConstRad::*)(const math_Vector &, math_Matrix &)) &BRepBlend_RstRstConstRad::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_BRepBlend_RstRstConstRad.def("Values", (Standard_Boolean (BRepBlend_RstRstConstRad::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BRepBlend_RstRstConstRad::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_BRepBlend_RstRstConstRad.def("Set", (void (BRepBlend_RstRstConstRad::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_RstRstConstRad::Set, "None", py::arg("SurfRef1"), py::arg("RstRef1"), py::arg("SurfRef2"), py::arg("RstRef2"));
cls_BRepBlend_RstRstConstRad.def("Set", (void (BRepBlend_RstRstConstRad::*)(const Standard_Real)) &BRepBlend_RstRstConstRad::Set, "None", py::arg("Param"));
cls_BRepBlend_RstRstConstRad.def("Set", (void (BRepBlend_RstRstConstRad::*)(const Standard_Real, const Standard_Real)) &BRepBlend_RstRstConstRad::Set, "Sets the bounds of the parametric interval on the guide line. This determines the derivatives in these values if the function is not Cn.", py::arg("First"), py::arg("Last"));
cls_BRepBlend_RstRstConstRad.def("GetTolerance", (void (BRepBlend_RstRstConstRad::*)(math_Vector &, const Standard_Real) const) &BRepBlend_RstRstConstRad::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
cls_BRepBlend_RstRstConstRad.def("GetBounds", (void (BRepBlend_RstRstConstRad::*)(math_Vector &, math_Vector &) const) &BRepBlend_RstRstConstRad::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
cls_BRepBlend_RstRstConstRad.def("IsSolution", (Standard_Boolean (BRepBlend_RstRstConstRad::*)(const math_Vector &, const Standard_Real)) &BRepBlend_RstRstConstRad::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
cls_BRepBlend_RstRstConstRad.def("GetMinimalDistance", (Standard_Real (BRepBlend_RstRstConstRad::*)() const) &BRepBlend_RstRstConstRad::GetMinimalDistance, "Returns the minimal Distance beetween two extremitys of calculed sections.");
cls_BRepBlend_RstRstConstRad.def("PointOnRst1", (const gp_Pnt & (BRepBlend_RstRstConstRad::*)() const) &BRepBlend_RstRstConstRad::PointOnRst1, "None");
cls_BRepBlend_RstRstConstRad.def("PointOnRst2", (const gp_Pnt & (BRepBlend_RstRstConstRad::*)() const) &BRepBlend_RstRstConstRad::PointOnRst2, "None");
cls_BRepBlend_RstRstConstRad.def("Pnt2dOnRst1", (const gp_Pnt2d & (BRepBlend_RstRstConstRad::*)() const) &BRepBlend_RstRstConstRad::Pnt2dOnRst1, "Returns U,V coordinates of the point on the surface.");
cls_BRepBlend_RstRstConstRad.def("Pnt2dOnRst2", (const gp_Pnt2d & (BRepBlend_RstRstConstRad::*)() const) &BRepBlend_RstRstConstRad::Pnt2dOnRst2, "Returns U,V coordinates of the point on the curve on surface.");
cls_BRepBlend_RstRstConstRad.def("ParameterOnRst1", (Standard_Real (BRepBlend_RstRstConstRad::*)() const) &BRepBlend_RstRstConstRad::ParameterOnRst1, "Returns parameter of the point on the curve.");
cls_BRepBlend_RstRstConstRad.def("ParameterOnRst2", (Standard_Real (BRepBlend_RstRstConstRad::*)() const) &BRepBlend_RstRstConstRad::ParameterOnRst2, "Returns parameter of the point on the curve.");
cls_BRepBlend_RstRstConstRad.def("IsTangencyPoint", (Standard_Boolean (BRepBlend_RstRstConstRad::*)() const) &BRepBlend_RstRstConstRad::IsTangencyPoint, "None");
cls_BRepBlend_RstRstConstRad.def("TangentOnRst1", (const gp_Vec & (BRepBlend_RstRstConstRad::*)() const) &BRepBlend_RstRstConstRad::TangentOnRst1, "None");
cls_BRepBlend_RstRstConstRad.def("Tangent2dOnRst1", (const gp_Vec2d & (BRepBlend_RstRstConstRad::*)() const) &BRepBlend_RstRstConstRad::Tangent2dOnRst1, "None");
cls_BRepBlend_RstRstConstRad.def("TangentOnRst2", (const gp_Vec & (BRepBlend_RstRstConstRad::*)() const) &BRepBlend_RstRstConstRad::TangentOnRst2, "None");
cls_BRepBlend_RstRstConstRad.def("Tangent2dOnRst2", (const gp_Vec2d & (BRepBlend_RstRstConstRad::*)() const) &BRepBlend_RstRstConstRad::Tangent2dOnRst2, "None");
cls_BRepBlend_RstRstConstRad.def("Decroch", (Blend_DecrochStatus (BRepBlend_RstRstConstRad::*)(const math_Vector &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &BRepBlend_RstRstConstRad::Decroch, "Permet d ' implementer un critere de decrochage specifique a la fonction.", py::arg("Sol"), py::arg("NRst1"), py::arg("TgRst1"), py::arg("NRst2"), py::arg("TgRst2"));
cls_BRepBlend_RstRstConstRad.def("Set", (void (BRepBlend_RstRstConstRad::*)(const Standard_Real, const Standard_Integer)) &BRepBlend_RstRstConstRad::Set, "None", py::arg("Radius"), py::arg("Choix"));
cls_BRepBlend_RstRstConstRad.def("Set", (void (BRepBlend_RstRstConstRad::*)(const BlendFunc_SectionShape)) &BRepBlend_RstRstConstRad::Set, "Sets the type of section generation for the approximations.", py::arg("TypeSection"));
cls_BRepBlend_RstRstConstRad.def("CenterCircleRst1Rst2", (Standard_Boolean (BRepBlend_RstRstConstRad::*)(const gp_Pnt &, const gp_Pnt &, const gp_Vec &, gp_Pnt &, gp_Vec &) const) &BRepBlend_RstRstConstRad::CenterCircleRst1Rst2, "Give the center of circle define by PtRst1, PtRst2 and radius ray.", py::arg("PtRst1"), py::arg("PtRst2"), py::arg("np"), py::arg("Center"), py::arg("VdMed"));
cls_BRepBlend_RstRstConstRad.def("Section", [](BRepBlend_RstRstConstRad &self, const Standard_Real Param, const Standard_Real U, const Standard_Real V, Standard_Real & Pdeb, Standard_Real & Pfin, gp_Circ & C){ self.Section(Param, U, V, Pdeb, Pfin, C); return std::tuple<Standard_Real &, Standard_Real &>(Pdeb, Pfin); }, "None", py::arg("Param"), py::arg("U"), py::arg("V"), py::arg("Pdeb"), py::arg("Pfin"), py::arg("C"));
cls_BRepBlend_RstRstConstRad.def("IsRational", (Standard_Boolean (BRepBlend_RstRstConstRad::*)() const) &BRepBlend_RstRstConstRad::IsRational, "Returns if the section is rationnal");
cls_BRepBlend_RstRstConstRad.def("GetSectionSize", (Standard_Real (BRepBlend_RstRstConstRad::*)() const) &BRepBlend_RstRstConstRad::GetSectionSize, "Returns the length of the maximum section");
cls_BRepBlend_RstRstConstRad.def("GetMinimalWeight", (void (BRepBlend_RstRstConstRad::*)(TColStd_Array1OfReal &) const) &BRepBlend_RstRstConstRad::GetMinimalWeight, "Compute the minimal value of weight for each poles of all sections.", py::arg("Weigths"));
cls_BRepBlend_RstRstConstRad.def("NbIntervals", (Standard_Integer (BRepBlend_RstRstConstRad::*)(const GeomAbs_Shape) const) &BRepBlend_RstRstConstRad::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_BRepBlend_RstRstConstRad.def("Intervals", (void (BRepBlend_RstRstConstRad::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &BRepBlend_RstRstConstRad::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>. The array must provide enough room to accomodate for the parameters. i.e. T.Length() > NbIntervals()", py::arg("T"), py::arg("S"));
cls_BRepBlend_RstRstConstRad.def("GetShape", [](BRepBlend_RstRstConstRad &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree, Standard_Integer & NbPoles2d){ self.GetShape(NbPoles, NbKnots, Degree, NbPoles2d); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree, NbPoles2d); }, "None", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"), py::arg("NbPoles2d"));
cls_BRepBlend_RstRstConstRad.def("GetTolerance", (void (BRepBlend_RstRstConstRad::*)(const Standard_Real, const Standard_Real, const Standard_Real, math_Vector &, math_Vector &) const) &BRepBlend_RstRstConstRad::GetTolerance, "Returns the tolerance to reach in approximation to respecte BoundTol error at the Boundary AngleTol tangent error at the Boundary SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"), py::arg("Tol1D"));
cls_BRepBlend_RstRstConstRad.def("Knots", (void (BRepBlend_RstRstConstRad::*)(TColStd_Array1OfReal &)) &BRepBlend_RstRstConstRad::Knots, "None", py::arg("TKnots"));
cls_BRepBlend_RstRstConstRad.def("Mults", (void (BRepBlend_RstRstConstRad::*)(TColStd_Array1OfInteger &)) &BRepBlend_RstRstConstRad::Mults, "None", py::arg("TMults"));
cls_BRepBlend_RstRstConstRad.def("Section", (Standard_Boolean (BRepBlend_RstRstConstRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BRepBlend_RstRstConstRad::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
cls_BRepBlend_RstRstConstRad.def("Section", (void (BRepBlend_RstRstConstRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &)) &BRepBlend_RstRstConstRad::Section, "None", py::arg("P"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
cls_BRepBlend_RstRstConstRad.def("Section", (Standard_Boolean (BRepBlend_RstRstConstRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BRepBlend_RstRstConstRad::Section, "Used for the first and last section The method returns Standard_True if the derivatives are computed, otherwise it returns Standard_False.", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
cls_BRepBlend_RstRstConstRad.def("Resolution", [](BRepBlend_RstRstConstRad &self, const Standard_Integer IC2d, const Standard_Real Tol, Standard_Real & TolU, Standard_Real & TolV){ self.Resolution(IC2d, Tol, TolU, TolV); return std::tuple<Standard_Real &, Standard_Real &>(TolU, TolV); }, "None", py::arg("IC2d"), py::arg("Tol"), py::arg("TolU"), py::arg("TolV"));

// CLASS: BREPBLEND_RSTRSTEVOLRAD
py::class_<BRepBlend_RstRstEvolRad, Blend_RstRstFunction> cls_BRepBlend_RstRstEvolRad(mod, "BRepBlend_RstRstEvolRad", "Function to approximate by AppSurface for Edge/Edge and evolutif radius");

// Constructors
cls_BRepBlend_RstRstEvolRad.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Law_Function> &>(), py::arg("Surf1"), py::arg("Rst1"), py::arg("Surf2"), py::arg("Rst2"), py::arg("CGuide"), py::arg("Evol"));

// Methods
// cls_BRepBlend_RstRstEvolRad.def_static("operator new_", (void * (*)(size_t)) &BRepBlend_RstRstEvolRad::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_RstRstEvolRad.def_static("operator delete_", (void (*)(void *)) &BRepBlend_RstRstEvolRad::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_RstRstEvolRad.def_static("operator new[]_", (void * (*)(size_t)) &BRepBlend_RstRstEvolRad::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_RstRstEvolRad.def_static("operator delete[]_", (void (*)(void *)) &BRepBlend_RstRstEvolRad::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_RstRstEvolRad.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBlend_RstRstEvolRad::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_RstRstEvolRad.def_static("operator delete_", (void (*)(void *, void *)) &BRepBlend_RstRstEvolRad::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_RstRstEvolRad.def("NbVariables", (Standard_Integer (BRepBlend_RstRstEvolRad::*)() const) &BRepBlend_RstRstEvolRad::NbVariables, "Returns 2.");
cls_BRepBlend_RstRstEvolRad.def("NbEquations", (Standard_Integer (BRepBlend_RstRstEvolRad::*)() const) &BRepBlend_RstRstEvolRad::NbEquations, "Returns 2.");
cls_BRepBlend_RstRstEvolRad.def("Value", (Standard_Boolean (BRepBlend_RstRstEvolRad::*)(const math_Vector &, math_Vector &)) &BRepBlend_RstRstEvolRad::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_BRepBlend_RstRstEvolRad.def("Derivatives", (Standard_Boolean (BRepBlend_RstRstEvolRad::*)(const math_Vector &, math_Matrix &)) &BRepBlend_RstRstEvolRad::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_BRepBlend_RstRstEvolRad.def("Values", (Standard_Boolean (BRepBlend_RstRstEvolRad::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BRepBlend_RstRstEvolRad::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_BRepBlend_RstRstEvolRad.def("Set", (void (BRepBlend_RstRstEvolRad::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_RstRstEvolRad::Set, "None", py::arg("SurfRef1"), py::arg("RstRef1"), py::arg("SurfRef2"), py::arg("RstRef2"));
cls_BRepBlend_RstRstEvolRad.def("Set", (void (BRepBlend_RstRstEvolRad::*)(const Standard_Real)) &BRepBlend_RstRstEvolRad::Set, "None", py::arg("Param"));
cls_BRepBlend_RstRstEvolRad.def("Set", (void (BRepBlend_RstRstEvolRad::*)(const Standard_Real, const Standard_Real)) &BRepBlend_RstRstEvolRad::Set, "Sets the bounds of the parametric interval on the guide line. This determines the derivatives in these values if the function is not Cn.", py::arg("First"), py::arg("Last"));
cls_BRepBlend_RstRstEvolRad.def("GetTolerance", (void (BRepBlend_RstRstEvolRad::*)(math_Vector &, const Standard_Real) const) &BRepBlend_RstRstEvolRad::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
cls_BRepBlend_RstRstEvolRad.def("GetBounds", (void (BRepBlend_RstRstEvolRad::*)(math_Vector &, math_Vector &) const) &BRepBlend_RstRstEvolRad::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
cls_BRepBlend_RstRstEvolRad.def("IsSolution", (Standard_Boolean (BRepBlend_RstRstEvolRad::*)(const math_Vector &, const Standard_Real)) &BRepBlend_RstRstEvolRad::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
cls_BRepBlend_RstRstEvolRad.def("GetMinimalDistance", (Standard_Real (BRepBlend_RstRstEvolRad::*)() const) &BRepBlend_RstRstEvolRad::GetMinimalDistance, "Returns the minimal Distance beetween two extremitys of calculed sections.");
cls_BRepBlend_RstRstEvolRad.def("PointOnRst1", (const gp_Pnt & (BRepBlend_RstRstEvolRad::*)() const) &BRepBlend_RstRstEvolRad::PointOnRst1, "None");
cls_BRepBlend_RstRstEvolRad.def("PointOnRst2", (const gp_Pnt & (BRepBlend_RstRstEvolRad::*)() const) &BRepBlend_RstRstEvolRad::PointOnRst2, "None");
cls_BRepBlend_RstRstEvolRad.def("Pnt2dOnRst1", (const gp_Pnt2d & (BRepBlend_RstRstEvolRad::*)() const) &BRepBlend_RstRstEvolRad::Pnt2dOnRst1, "Returns U,V coordinates of the point on the surface.");
cls_BRepBlend_RstRstEvolRad.def("Pnt2dOnRst2", (const gp_Pnt2d & (BRepBlend_RstRstEvolRad::*)() const) &BRepBlend_RstRstEvolRad::Pnt2dOnRst2, "Returns U,V coordinates of the point on the curve on surface.");
cls_BRepBlend_RstRstEvolRad.def("ParameterOnRst1", (Standard_Real (BRepBlend_RstRstEvolRad::*)() const) &BRepBlend_RstRstEvolRad::ParameterOnRst1, "Returns parameter of the point on the curve.");
cls_BRepBlend_RstRstEvolRad.def("ParameterOnRst2", (Standard_Real (BRepBlend_RstRstEvolRad::*)() const) &BRepBlend_RstRstEvolRad::ParameterOnRst2, "Returns parameter of the point on the curve.");
cls_BRepBlend_RstRstEvolRad.def("IsTangencyPoint", (Standard_Boolean (BRepBlend_RstRstEvolRad::*)() const) &BRepBlend_RstRstEvolRad::IsTangencyPoint, "None");
cls_BRepBlend_RstRstEvolRad.def("TangentOnRst1", (const gp_Vec & (BRepBlend_RstRstEvolRad::*)() const) &BRepBlend_RstRstEvolRad::TangentOnRst1, "None");
cls_BRepBlend_RstRstEvolRad.def("Tangent2dOnRst1", (const gp_Vec2d & (BRepBlend_RstRstEvolRad::*)() const) &BRepBlend_RstRstEvolRad::Tangent2dOnRst1, "None");
cls_BRepBlend_RstRstEvolRad.def("TangentOnRst2", (const gp_Vec & (BRepBlend_RstRstEvolRad::*)() const) &BRepBlend_RstRstEvolRad::TangentOnRst2, "None");
cls_BRepBlend_RstRstEvolRad.def("Tangent2dOnRst2", (const gp_Vec2d & (BRepBlend_RstRstEvolRad::*)() const) &BRepBlend_RstRstEvolRad::Tangent2dOnRst2, "None");
cls_BRepBlend_RstRstEvolRad.def("Decroch", (Blend_DecrochStatus (BRepBlend_RstRstEvolRad::*)(const math_Vector &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &BRepBlend_RstRstEvolRad::Decroch, "Enables implementation of a criterion of decrochage specific to the function.", py::arg("Sol"), py::arg("NRst1"), py::arg("TgRst1"), py::arg("NRst2"), py::arg("TgRst2"));
cls_BRepBlend_RstRstEvolRad.def("Set", (void (BRepBlend_RstRstEvolRad::*)(const Standard_Integer)) &BRepBlend_RstRstEvolRad::Set, "None", py::arg("Choix"));
cls_BRepBlend_RstRstEvolRad.def("Set", (void (BRepBlend_RstRstEvolRad::*)(const BlendFunc_SectionShape)) &BRepBlend_RstRstEvolRad::Set, "Sets the type of section generation for the approximations.", py::arg("TypeSection"));
cls_BRepBlend_RstRstEvolRad.def("CenterCircleRst1Rst2", (Standard_Boolean (BRepBlend_RstRstEvolRad::*)(const gp_Pnt &, const gp_Pnt &, const gp_Vec &, gp_Pnt &, gp_Vec &) const) &BRepBlend_RstRstEvolRad::CenterCircleRst1Rst2, "Gives the center of circle defined by PtRst1, PtRst2 and radius ray.", py::arg("PtRst1"), py::arg("PtRst2"), py::arg("np"), py::arg("Center"), py::arg("VdMed"));
cls_BRepBlend_RstRstEvolRad.def("Section", [](BRepBlend_RstRstEvolRad &self, const Standard_Real Param, const Standard_Real U, const Standard_Real V, Standard_Real & Pdeb, Standard_Real & Pfin, gp_Circ & C){ self.Section(Param, U, V, Pdeb, Pfin, C); return std::tuple<Standard_Real &, Standard_Real &>(Pdeb, Pfin); }, "None", py::arg("Param"), py::arg("U"), py::arg("V"), py::arg("Pdeb"), py::arg("Pfin"), py::arg("C"));
cls_BRepBlend_RstRstEvolRad.def("IsRational", (Standard_Boolean (BRepBlend_RstRstEvolRad::*)() const) &BRepBlend_RstRstEvolRad::IsRational, "Returns if the section is rationnal");
cls_BRepBlend_RstRstEvolRad.def("GetSectionSize", (Standard_Real (BRepBlend_RstRstEvolRad::*)() const) &BRepBlend_RstRstEvolRad::GetSectionSize, "Returns the length of the maximum section");
cls_BRepBlend_RstRstEvolRad.def("GetMinimalWeight", (void (BRepBlend_RstRstEvolRad::*)(TColStd_Array1OfReal &) const) &BRepBlend_RstRstEvolRad::GetMinimalWeight, "Compute the minimal value of weight for each poles of all sections.", py::arg("Weigths"));
cls_BRepBlend_RstRstEvolRad.def("NbIntervals", (Standard_Integer (BRepBlend_RstRstEvolRad::*)(const GeomAbs_Shape) const) &BRepBlend_RstRstEvolRad::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_BRepBlend_RstRstEvolRad.def("Intervals", (void (BRepBlend_RstRstEvolRad::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &BRepBlend_RstRstEvolRad::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>. The array must provide enough room to accomodate for the parameters. i.e. T.Length() > NbIntervals()", py::arg("T"), py::arg("S"));
cls_BRepBlend_RstRstEvolRad.def("GetShape", [](BRepBlend_RstRstEvolRad &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree, Standard_Integer & NbPoles2d){ self.GetShape(NbPoles, NbKnots, Degree, NbPoles2d); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree, NbPoles2d); }, "None", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"), py::arg("NbPoles2d"));
cls_BRepBlend_RstRstEvolRad.def("GetTolerance", (void (BRepBlend_RstRstEvolRad::*)(const Standard_Real, const Standard_Real, const Standard_Real, math_Vector &, math_Vector &) const) &BRepBlend_RstRstEvolRad::GetTolerance, "Returns the tolerance to reach in approximation to respecte BoundTol error at the Boundary AngleTol tangent error at the Boundary SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"), py::arg("Tol1D"));
cls_BRepBlend_RstRstEvolRad.def("Knots", (void (BRepBlend_RstRstEvolRad::*)(TColStd_Array1OfReal &)) &BRepBlend_RstRstEvolRad::Knots, "None", py::arg("TKnots"));
cls_BRepBlend_RstRstEvolRad.def("Mults", (void (BRepBlend_RstRstEvolRad::*)(TColStd_Array1OfInteger &)) &BRepBlend_RstRstEvolRad::Mults, "None", py::arg("TMults"));
cls_BRepBlend_RstRstEvolRad.def("Section", (Standard_Boolean (BRepBlend_RstRstEvolRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BRepBlend_RstRstEvolRad::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
cls_BRepBlend_RstRstEvolRad.def("Section", (void (BRepBlend_RstRstEvolRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &)) &BRepBlend_RstRstEvolRad::Section, "None", py::arg("P"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
cls_BRepBlend_RstRstEvolRad.def("Section", (Standard_Boolean (BRepBlend_RstRstEvolRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BRepBlend_RstRstEvolRad::Section, "Used for the first and last section The method returns Standard_True if the derivatives are computed, otherwise it returns Standard_False.", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
cls_BRepBlend_RstRstEvolRad.def("Resolution", [](BRepBlend_RstRstEvolRad &self, const Standard_Integer IC2d, const Standard_Real Tol, Standard_Real & TolU, Standard_Real & TolV){ self.Resolution(IC2d, Tol, TolU, TolV); return std::tuple<Standard_Real &, Standard_Real &>(TolU, TolV); }, "None", py::arg("IC2d"), py::arg("Tol"), py::arg("TolU"), py::arg("TolV"));

// CLASS: BREPBLEND_RSTRSTLINEBUILDER
py::class_<BRepBlend_RstRstLineBuilder> cls_BRepBlend_RstRstLineBuilder(mod, "BRepBlend_RstRstLineBuilder", "This class processes the data resulting from Blend_CSWalking but it takes in consideration the Surface supporting the curve to detect the breakpoint.");

// Constructors
cls_BRepBlend_RstRstLineBuilder.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_TopolTool> &>(), py::arg("Surf1"), py::arg("Rst1"), py::arg("Domain1"), py::arg("Surf2"), py::arg("Rst2"), py::arg("Domain2"));

// Methods
// cls_BRepBlend_RstRstLineBuilder.def_static("operator new_", (void * (*)(size_t)) &BRepBlend_RstRstLineBuilder::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_RstRstLineBuilder.def_static("operator delete_", (void (*)(void *)) &BRepBlend_RstRstLineBuilder::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_RstRstLineBuilder.def_static("operator new[]_", (void * (*)(size_t)) &BRepBlend_RstRstLineBuilder::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_RstRstLineBuilder.def_static("operator delete[]_", (void (*)(void *)) &BRepBlend_RstRstLineBuilder::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_RstRstLineBuilder.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBlend_RstRstLineBuilder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_RstRstLineBuilder.def_static("operator delete_", (void (*)(void *, void *)) &BRepBlend_RstRstLineBuilder::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_RstRstLineBuilder.def("Perform", [](BRepBlend_RstRstLineBuilder &self, Blend_RstRstFunction & a0, Blend_SurfCurvFuncInv & a1, Blend_CurvPointFuncInv & a2, Blend_SurfCurvFuncInv & a3, Blend_CurvPointFuncInv & a4, const Standard_Real a5, const Standard_Real a6, const Standard_Real a7, const Standard_Real a8, const math_Vector & a9, const Standard_Real a10, const Standard_Real a11) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11); });
cls_BRepBlend_RstRstLineBuilder.def("Perform", (void (BRepBlend_RstRstLineBuilder::*)(Blend_RstRstFunction &, Blend_SurfCurvFuncInv &, Blend_CurvPointFuncInv &, Blend_SurfCurvFuncInv &, Blend_CurvPointFuncInv &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const math_Vector &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &BRepBlend_RstRstLineBuilder::Perform, "None", py::arg("Func"), py::arg("Finv1"), py::arg("FinvP1"), py::arg("Finv2"), py::arg("FinvP2"), py::arg("Pdep"), py::arg("Pmax"), py::arg("MaxStep"), py::arg("TolGuide"), py::arg("Soldep"), py::arg("Tolesp"), py::arg("Fleche"), py::arg("Appro"));
cls_BRepBlend_RstRstLineBuilder.def("PerformFirstSection", [](BRepBlend_RstRstLineBuilder &self, Blend_RstRstFunction & Func, Blend_SurfCurvFuncInv & Finv1, Blend_CurvPointFuncInv & FinvP1, Blend_SurfCurvFuncInv & Finv2, Blend_CurvPointFuncInv & FinvP2, const Standard_Real Pdep, const Standard_Real Pmax, const math_Vector & Soldep, const Standard_Real Tolesp, const Standard_Real TolGuide, const Standard_Boolean RecRst1, const Standard_Boolean RecP1, const Standard_Boolean RecRst2, const Standard_Boolean RecP2, Standard_Real & Psol, math_Vector & ParSol){ Standard_Boolean rv = self.PerformFirstSection(Func, Finv1, FinvP1, Finv2, FinvP2, Pdep, Pmax, Soldep, Tolesp, TolGuide, RecRst1, RecP1, RecRst2, RecP2, Psol, ParSol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Psol); }, "None", py::arg("Func"), py::arg("Finv1"), py::arg("FinvP1"), py::arg("Finv2"), py::arg("FinvP2"), py::arg("Pdep"), py::arg("Pmax"), py::arg("Soldep"), py::arg("Tolesp"), py::arg("TolGuide"), py::arg("RecRst1"), py::arg("RecP1"), py::arg("RecRst2"), py::arg("RecP2"), py::arg("Psol"), py::arg("ParSol"));
cls_BRepBlend_RstRstLineBuilder.def("Complete", (Standard_Boolean (BRepBlend_RstRstLineBuilder::*)(Blend_RstRstFunction &, Blend_SurfCurvFuncInv &, Blend_CurvPointFuncInv &, Blend_SurfCurvFuncInv &, Blend_CurvPointFuncInv &, const Standard_Real)) &BRepBlend_RstRstLineBuilder::Complete, "None", py::arg("Func"), py::arg("Finv1"), py::arg("FinvP1"), py::arg("Finv2"), py::arg("FinvP2"), py::arg("Pmin"));
cls_BRepBlend_RstRstLineBuilder.def("IsDone", (Standard_Boolean (BRepBlend_RstRstLineBuilder::*)() const) &BRepBlend_RstRstLineBuilder::IsDone, "None");
cls_BRepBlend_RstRstLineBuilder.def("Line", (const opencascade::handle<BRepBlend_Line> & (BRepBlend_RstRstLineBuilder::*)() const) &BRepBlend_RstRstLineBuilder::Line, "None");
cls_BRepBlend_RstRstLineBuilder.def("Decroch1Start", (Standard_Boolean (BRepBlend_RstRstLineBuilder::*)() const) &BRepBlend_RstRstLineBuilder::Decroch1Start, "None");
cls_BRepBlend_RstRstLineBuilder.def("Decroch1End", (Standard_Boolean (BRepBlend_RstRstLineBuilder::*)() const) &BRepBlend_RstRstLineBuilder::Decroch1End, "None");
cls_BRepBlend_RstRstLineBuilder.def("Decroch2Start", (Standard_Boolean (BRepBlend_RstRstLineBuilder::*)() const) &BRepBlend_RstRstLineBuilder::Decroch2Start, "None");
cls_BRepBlend_RstRstLineBuilder.def("Decroch2End", (Standard_Boolean (BRepBlend_RstRstLineBuilder::*)() const) &BRepBlend_RstRstLineBuilder::Decroch2End, "None");

// TYPEDEF: BREPBLEND_RULED
py::class_<BlendFunc_Ruled, Blend_Function> cls_BRepBlend_Ruled(mod, "BRepBlend_Ruled", "None", py::module_local());

// Constructors
cls_BRepBlend_Ruled.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S1"), py::arg("S2"), py::arg("C"));

// Methods
// cls_BRepBlend_Ruled.def_static("operator new_", (void * (*)(size_t)) &BlendFunc_Ruled::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_Ruled.def_static("operator delete_", (void (*)(void *)) &BlendFunc_Ruled::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_Ruled.def_static("operator new[]_", (void * (*)(size_t)) &BlendFunc_Ruled::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_Ruled.def_static("operator delete[]_", (void (*)(void *)) &BlendFunc_Ruled::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_Ruled.def_static("operator new_", (void * (*)(size_t, void *)) &BlendFunc_Ruled::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_Ruled.def_static("operator delete_", (void (*)(void *, void *)) &BlendFunc_Ruled::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_Ruled.def("NbEquations", (Standard_Integer (BlendFunc_Ruled::*)() const) &BlendFunc_Ruled::NbEquations, "returns the number of equations of the function.");
cls_BRepBlend_Ruled.def("Value", (Standard_Boolean (BlendFunc_Ruled::*)(const math_Vector &, math_Vector &)) &BlendFunc_Ruled::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_BRepBlend_Ruled.def("Derivatives", (Standard_Boolean (BlendFunc_Ruled::*)(const math_Vector &, math_Matrix &)) &BlendFunc_Ruled::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_BRepBlend_Ruled.def("Values", (Standard_Boolean (BlendFunc_Ruled::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BlendFunc_Ruled::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_BRepBlend_Ruled.def("Set", (void (BlendFunc_Ruled::*)(const Standard_Real)) &BlendFunc_Ruled::Set, "None", py::arg("Param"));
cls_BRepBlend_Ruled.def("Set", (void (BlendFunc_Ruled::*)(const Standard_Real, const Standard_Real)) &BlendFunc_Ruled::Set, "None", py::arg("First"), py::arg("Last"));
cls_BRepBlend_Ruled.def("GetTolerance", (void (BlendFunc_Ruled::*)(math_Vector &, const Standard_Real) const) &BlendFunc_Ruled::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
cls_BRepBlend_Ruled.def("GetBounds", (void (BlendFunc_Ruled::*)(math_Vector &, math_Vector &) const) &BlendFunc_Ruled::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
cls_BRepBlend_Ruled.def("IsSolution", (Standard_Boolean (BlendFunc_Ruled::*)(const math_Vector &, const Standard_Real)) &BlendFunc_Ruled::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
cls_BRepBlend_Ruled.def("GetMinimalDistance", (Standard_Real (BlendFunc_Ruled::*)() const) &BlendFunc_Ruled::GetMinimalDistance, "Returns the minimal Distance beetween two extremitys of calculed sections.");
cls_BRepBlend_Ruled.def("PointOnS1", (const gp_Pnt & (BlendFunc_Ruled::*)() const) &BlendFunc_Ruled::PointOnS1, "None");
cls_BRepBlend_Ruled.def("PointOnS2", (const gp_Pnt & (BlendFunc_Ruled::*)() const) &BlendFunc_Ruled::PointOnS2, "None");
cls_BRepBlend_Ruled.def("IsTangencyPoint", (Standard_Boolean (BlendFunc_Ruled::*)() const) &BlendFunc_Ruled::IsTangencyPoint, "None");
cls_BRepBlend_Ruled.def("TangentOnS1", (const gp_Vec & (BlendFunc_Ruled::*)() const) &BlendFunc_Ruled::TangentOnS1, "None");
cls_BRepBlend_Ruled.def("Tangent2dOnS1", (const gp_Vec2d & (BlendFunc_Ruled::*)() const) &BlendFunc_Ruled::Tangent2dOnS1, "None");
cls_BRepBlend_Ruled.def("TangentOnS2", (const gp_Vec & (BlendFunc_Ruled::*)() const) &BlendFunc_Ruled::TangentOnS2, "None");
cls_BRepBlend_Ruled.def("Tangent2dOnS2", (const gp_Vec2d & (BlendFunc_Ruled::*)() const) &BlendFunc_Ruled::Tangent2dOnS2, "None");
cls_BRepBlend_Ruled.def("Tangent", (void (BlendFunc_Ruled::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &BlendFunc_Ruled::Tangent, "Returns the tangent vector at the section, at the beginning and the end of the section, and returns the normal (of the surfaces) at these points.", py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("TgFirst"), py::arg("TgLast"), py::arg("NormFirst"), py::arg("NormLast"));
cls_BRepBlend_Ruled.def("GetSection", (Standard_Boolean (BlendFunc_Ruled::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfVec &)) &BlendFunc_Ruled::GetSection, "None", py::arg("Param"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("tabP"), py::arg("tabV"));
cls_BRepBlend_Ruled.def("IsRational", (Standard_Boolean (BlendFunc_Ruled::*)() const) &BlendFunc_Ruled::IsRational, "Returns False");
cls_BRepBlend_Ruled.def("GetSectionSize", (Standard_Real (BlendFunc_Ruled::*)() const) &BlendFunc_Ruled::GetSectionSize, "Returns the length of the maximum section");
cls_BRepBlend_Ruled.def("GetMinimalWeight", (void (BlendFunc_Ruled::*)(TColStd_Array1OfReal &) const) &BlendFunc_Ruled::GetMinimalWeight, "Compute the minimal value of weight for each poles of all sections.", py::arg("Weigths"));
cls_BRepBlend_Ruled.def("NbIntervals", (Standard_Integer (BlendFunc_Ruled::*)(const GeomAbs_Shape) const) &BlendFunc_Ruled::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_BRepBlend_Ruled.def("Intervals", (void (BlendFunc_Ruled::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &BlendFunc_Ruled::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_BRepBlend_Ruled.def("GetShape", [](BlendFunc_Ruled &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree, Standard_Integer & NbPoles2d){ self.GetShape(NbPoles, NbKnots, Degree, NbPoles2d); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree, NbPoles2d); }, "None", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"), py::arg("NbPoles2d"));
cls_BRepBlend_Ruled.def("GetTolerance", (void (BlendFunc_Ruled::*)(const Standard_Real, const Standard_Real, const Standard_Real, math_Vector &, math_Vector &) const) &BlendFunc_Ruled::GetTolerance, "Returns the tolerance to reach in approximation to respecte BoundTol error at the Boundary AngleTol tangent error at the Boundary SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"), py::arg("Tol1D"));
cls_BRepBlend_Ruled.def("Knots", (void (BlendFunc_Ruled::*)(TColStd_Array1OfReal &)) &BlendFunc_Ruled::Knots, "None", py::arg("TKnots"));
cls_BRepBlend_Ruled.def("Mults", (void (BlendFunc_Ruled::*)(TColStd_Array1OfInteger &)) &BlendFunc_Ruled::Mults, "None", py::arg("TMults"));
cls_BRepBlend_Ruled.def("Section", (Standard_Boolean (BlendFunc_Ruled::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_Ruled::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
cls_BRepBlend_Ruled.def("Section", (Standard_Boolean (BlendFunc_Ruled::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_Ruled::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
cls_BRepBlend_Ruled.def("Section", (void (BlendFunc_Ruled::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &)) &BlendFunc_Ruled::Section, "None", py::arg("P"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
cls_BRepBlend_Ruled.def("AxeRot", (gp_Ax1 (BlendFunc_Ruled::*)(const Standard_Real)) &BlendFunc_Ruled::AxeRot, "None", py::arg("Prm"));
cls_BRepBlend_Ruled.def("Resolution", [](BlendFunc_Ruled &self, const Standard_Integer IC2d, const Standard_Real Tol, Standard_Real & TolU, Standard_Real & TolV){ self.Resolution(IC2d, Tol, TolU, TolV); return std::tuple<Standard_Real &, Standard_Real &>(TolU, TolV); }, "None", py::arg("IC2d"), py::arg("Tol"), py::arg("TolU"), py::arg("TolV"));

// TYPEDEF: BREPBLEND_RULEDINV
py::class_<BlendFunc_RuledInv, Blend_FuncInv> cls_BRepBlend_RuledInv(mod, "BRepBlend_RuledInv", "None", py::module_local());

// Constructors
cls_BRepBlend_RuledInv.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S1"), py::arg("S2"), py::arg("C"));

// Methods
// cls_BRepBlend_RuledInv.def_static("operator new_", (void * (*)(size_t)) &BlendFunc_RuledInv::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_RuledInv.def_static("operator delete_", (void (*)(void *)) &BlendFunc_RuledInv::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_RuledInv.def_static("operator new[]_", (void * (*)(size_t)) &BlendFunc_RuledInv::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_RuledInv.def_static("operator delete[]_", (void (*)(void *)) &BlendFunc_RuledInv::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_RuledInv.def_static("operator new_", (void * (*)(size_t, void *)) &BlendFunc_RuledInv::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_RuledInv.def_static("operator delete_", (void (*)(void *, void *)) &BlendFunc_RuledInv::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_RuledInv.def("Set", (void (BlendFunc_RuledInv::*)(const Standard_Boolean, const opencascade::handle<Adaptor2d_HCurve2d> &)) &BlendFunc_RuledInv::Set, "None", py::arg("OnFirst"), py::arg("COnSurf"));
cls_BRepBlend_RuledInv.def("GetTolerance", (void (BlendFunc_RuledInv::*)(math_Vector &, const Standard_Real) const) &BlendFunc_RuledInv::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
cls_BRepBlend_RuledInv.def("GetBounds", (void (BlendFunc_RuledInv::*)(math_Vector &, math_Vector &) const) &BlendFunc_RuledInv::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
cls_BRepBlend_RuledInv.def("IsSolution", (Standard_Boolean (BlendFunc_RuledInv::*)(const math_Vector &, const Standard_Real)) &BlendFunc_RuledInv::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
cls_BRepBlend_RuledInv.def("NbEquations", (Standard_Integer (BlendFunc_RuledInv::*)() const) &BlendFunc_RuledInv::NbEquations, "returns the number of equations of the function.");
cls_BRepBlend_RuledInv.def("Value", (Standard_Boolean (BlendFunc_RuledInv::*)(const math_Vector &, math_Vector &)) &BlendFunc_RuledInv::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_BRepBlend_RuledInv.def("Derivatives", (Standard_Boolean (BlendFunc_RuledInv::*)(const math_Vector &, math_Matrix &)) &BlendFunc_RuledInv::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_BRepBlend_RuledInv.def("Values", (Standard_Boolean (BlendFunc_RuledInv::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BlendFunc_RuledInv::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));

// TYPEDEF: BREPBLEND_SEQUENCEOFLINE
bind_NCollection_Sequence<opencascade::handle<BRepBlend_Line> >(mod, "BRepBlend_SequenceOfLine", py::module_local(false));

// CLASS: BREPBLEND_SURFCURVCONSTRADINV
py::class_<BRepBlend_SurfCurvConstRadInv, Blend_SurfCurvFuncInv> cls_BRepBlend_SurfCurvConstRadInv(mod, "BRepBlend_SurfCurvConstRadInv", "Function of reframing between a restriction surface of the surface and a curve. Class used to compute a solution of the surfRstConstRad problem on a done restriction of the surface. The vector <X> used in Value, Values and Derivatives methods has to be the vector of the parametric coordinates wguide, wcurv, wrst where wguide is the parameter on the guide line, wcurv is the parameter on the curve, wrst is the parameter on the restriction on the surface.");

// Constructors
cls_BRepBlend_SurfCurvConstRadInv.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S"), py::arg("C"), py::arg("Cg"));

// Methods
// cls_BRepBlend_SurfCurvConstRadInv.def_static("operator new_", (void * (*)(size_t)) &BRepBlend_SurfCurvConstRadInv::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_SurfCurvConstRadInv.def_static("operator delete_", (void (*)(void *)) &BRepBlend_SurfCurvConstRadInv::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_SurfCurvConstRadInv.def_static("operator new[]_", (void * (*)(size_t)) &BRepBlend_SurfCurvConstRadInv::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_SurfCurvConstRadInv.def_static("operator delete[]_", (void (*)(void *)) &BRepBlend_SurfCurvConstRadInv::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_SurfCurvConstRadInv.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBlend_SurfCurvConstRadInv::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_SurfCurvConstRadInv.def_static("operator delete_", (void (*)(void *, void *)) &BRepBlend_SurfCurvConstRadInv::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_SurfCurvConstRadInv.def("Set", (void (BRepBlend_SurfCurvConstRadInv::*)(const Standard_Real, const Standard_Integer)) &BRepBlend_SurfCurvConstRadInv::Set, "None", py::arg("R"), py::arg("Choix"));
cls_BRepBlend_SurfCurvConstRadInv.def("NbEquations", (Standard_Integer (BRepBlend_SurfCurvConstRadInv::*)() const) &BRepBlend_SurfCurvConstRadInv::NbEquations, "returns 3.");
cls_BRepBlend_SurfCurvConstRadInv.def("Value", (Standard_Boolean (BRepBlend_SurfCurvConstRadInv::*)(const math_Vector &, math_Vector &)) &BRepBlend_SurfCurvConstRadInv::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_BRepBlend_SurfCurvConstRadInv.def("Derivatives", (Standard_Boolean (BRepBlend_SurfCurvConstRadInv::*)(const math_Vector &, math_Matrix &)) &BRepBlend_SurfCurvConstRadInv::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_BRepBlend_SurfCurvConstRadInv.def("Values", (Standard_Boolean (BRepBlend_SurfCurvConstRadInv::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BRepBlend_SurfCurvConstRadInv::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_BRepBlend_SurfCurvConstRadInv.def("Set", (void (BRepBlend_SurfCurvConstRadInv::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_SurfCurvConstRadInv::Set, "Set the restriction on which a solution has to be found.", py::arg("Rst"));
cls_BRepBlend_SurfCurvConstRadInv.def("GetTolerance", (void (BRepBlend_SurfCurvConstRadInv::*)(math_Vector &, const Standard_Real) const) &BRepBlend_SurfCurvConstRadInv::GetTolerance, "Returns in the vector Tolerance the parametric tolerance for each of the 3 variables; Tol is the tolerance used in 3d space.", py::arg("Tolerance"), py::arg("Tol"));
cls_BRepBlend_SurfCurvConstRadInv.def("GetBounds", (void (BRepBlend_SurfCurvConstRadInv::*)(math_Vector &, math_Vector &) const) &BRepBlend_SurfCurvConstRadInv::GetBounds, "Returns in the vector InfBound the lowest values allowed for each of the 3 variables. Returns in the vector SupBound the greatest values allowed for each of the 3 variables.", py::arg("InfBound"), py::arg("SupBound"));
cls_BRepBlend_SurfCurvConstRadInv.def("IsSolution", (Standard_Boolean (BRepBlend_SurfCurvConstRadInv::*)(const math_Vector &, const Standard_Real)) &BRepBlend_SurfCurvConstRadInv::IsSolution, "Returns Standard_True if Sol is a zero of the function. Tol is the tolerance used in 3d space.", py::arg("Sol"), py::arg("Tol"));

// CLASS: BREPBLEND_SURFCURVEVOLRADINV
py::class_<BRepBlend_SurfCurvEvolRadInv, Blend_SurfCurvFuncInv> cls_BRepBlend_SurfCurvEvolRadInv(mod, "BRepBlend_SurfCurvEvolRadInv", "Function of reframing between a surface restriction of the surface and a curve. Class used to compute a solution of the surfRstConstRad problem on a done restriction of the surface. The vector <X> used in Value, Values and Derivatives methods has to be the vector of the parametric coordinates wguide, wcurv, wrst where wguide is the parameter on the guide line, wcurv is the parameter on the curve, wrst is the parameter on the restriction on the surface.");

// Constructors
cls_BRepBlend_SurfCurvEvolRadInv.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Law_Function> &>(), py::arg("S"), py::arg("C"), py::arg("Cg"), py::arg("Evol"));

// Methods
// cls_BRepBlend_SurfCurvEvolRadInv.def_static("operator new_", (void * (*)(size_t)) &BRepBlend_SurfCurvEvolRadInv::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_SurfCurvEvolRadInv.def_static("operator delete_", (void (*)(void *)) &BRepBlend_SurfCurvEvolRadInv::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_SurfCurvEvolRadInv.def_static("operator new[]_", (void * (*)(size_t)) &BRepBlend_SurfCurvEvolRadInv::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_SurfCurvEvolRadInv.def_static("operator delete[]_", (void (*)(void *)) &BRepBlend_SurfCurvEvolRadInv::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_SurfCurvEvolRadInv.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBlend_SurfCurvEvolRadInv::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_SurfCurvEvolRadInv.def_static("operator delete_", (void (*)(void *, void *)) &BRepBlend_SurfCurvEvolRadInv::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_SurfCurvEvolRadInv.def("Set", (void (BRepBlend_SurfCurvEvolRadInv::*)(const Standard_Integer)) &BRepBlend_SurfCurvEvolRadInv::Set, "None", py::arg("Choix"));
cls_BRepBlend_SurfCurvEvolRadInv.def("NbEquations", (Standard_Integer (BRepBlend_SurfCurvEvolRadInv::*)() const) &BRepBlend_SurfCurvEvolRadInv::NbEquations, "returns 3.");
cls_BRepBlend_SurfCurvEvolRadInv.def("Value", (Standard_Boolean (BRepBlend_SurfCurvEvolRadInv::*)(const math_Vector &, math_Vector &)) &BRepBlend_SurfCurvEvolRadInv::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_BRepBlend_SurfCurvEvolRadInv.def("Derivatives", (Standard_Boolean (BRepBlend_SurfCurvEvolRadInv::*)(const math_Vector &, math_Matrix &)) &BRepBlend_SurfCurvEvolRadInv::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_BRepBlend_SurfCurvEvolRadInv.def("Values", (Standard_Boolean (BRepBlend_SurfCurvEvolRadInv::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BRepBlend_SurfCurvEvolRadInv::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_BRepBlend_SurfCurvEvolRadInv.def("Set", (void (BRepBlend_SurfCurvEvolRadInv::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_SurfCurvEvolRadInv::Set, "Set the restriction on which a solution has to be found.", py::arg("Rst"));
cls_BRepBlend_SurfCurvEvolRadInv.def("GetTolerance", (void (BRepBlend_SurfCurvEvolRadInv::*)(math_Vector &, const Standard_Real) const) &BRepBlend_SurfCurvEvolRadInv::GetTolerance, "Returns in the vector Tolerance the parametric tolerance for each of the 3 variables; Tol is the tolerance used in 3d space.", py::arg("Tolerance"), py::arg("Tol"));
cls_BRepBlend_SurfCurvEvolRadInv.def("GetBounds", (void (BRepBlend_SurfCurvEvolRadInv::*)(math_Vector &, math_Vector &) const) &BRepBlend_SurfCurvEvolRadInv::GetBounds, "Returns in the vector InfBound the lowest values allowed for each of the 3 variables. Returns in the vector SupBound the greatest values allowed for each of the 3 variables.", py::arg("InfBound"), py::arg("SupBound"));
cls_BRepBlend_SurfCurvEvolRadInv.def("IsSolution", (Standard_Boolean (BRepBlend_SurfCurvEvolRadInv::*)(const math_Vector &, const Standard_Real)) &BRepBlend_SurfCurvEvolRadInv::IsSolution, "Returns Standard_True if Sol is a zero of the function. Tol is the tolerance used in 3d space.", py::arg("Sol"), py::arg("Tol"));

// CLASS: BREPBLEND_SURFPOINTCONSTRADINV
py::class_<BRepBlend_SurfPointConstRadInv, Blend_SurfPointFuncInv> cls_BRepBlend_SurfPointConstRadInv(mod, "BRepBlend_SurfPointConstRadInv", "Function of reframing between a point and a surface. This function is used to find a solution on a done point of the curve when using SurfRstConsRad or CSConstRad... The vector <X> used in Value, Values and Derivatives methods has to be the vector of the parametric coordinates w, U, V where w is the parameter on the guide line, U,V are the parametric coordinates of a point on the partner surface.");

// Constructors
cls_BRepBlend_SurfPointConstRadInv.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S"), py::arg("C"));

// Methods
// cls_BRepBlend_SurfPointConstRadInv.def_static("operator new_", (void * (*)(size_t)) &BRepBlend_SurfPointConstRadInv::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_SurfPointConstRadInv.def_static("operator delete_", (void (*)(void *)) &BRepBlend_SurfPointConstRadInv::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_SurfPointConstRadInv.def_static("operator new[]_", (void * (*)(size_t)) &BRepBlend_SurfPointConstRadInv::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_SurfPointConstRadInv.def_static("operator delete[]_", (void (*)(void *)) &BRepBlend_SurfPointConstRadInv::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_SurfPointConstRadInv.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBlend_SurfPointConstRadInv::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_SurfPointConstRadInv.def_static("operator delete_", (void (*)(void *, void *)) &BRepBlend_SurfPointConstRadInv::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_SurfPointConstRadInv.def("Set", (void (BRepBlend_SurfPointConstRadInv::*)(const Standard_Real, const Standard_Integer)) &BRepBlend_SurfPointConstRadInv::Set, "None", py::arg("R"), py::arg("Choix"));
cls_BRepBlend_SurfPointConstRadInv.def("NbEquations", (Standard_Integer (BRepBlend_SurfPointConstRadInv::*)() const) &BRepBlend_SurfPointConstRadInv::NbEquations, "returns 3.");
cls_BRepBlend_SurfPointConstRadInv.def("Value", (Standard_Boolean (BRepBlend_SurfPointConstRadInv::*)(const math_Vector &, math_Vector &)) &BRepBlend_SurfPointConstRadInv::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_BRepBlend_SurfPointConstRadInv.def("Derivatives", (Standard_Boolean (BRepBlend_SurfPointConstRadInv::*)(const math_Vector &, math_Matrix &)) &BRepBlend_SurfPointConstRadInv::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_BRepBlend_SurfPointConstRadInv.def("Values", (Standard_Boolean (BRepBlend_SurfPointConstRadInv::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BRepBlend_SurfPointConstRadInv::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_BRepBlend_SurfPointConstRadInv.def("Set", (void (BRepBlend_SurfPointConstRadInv::*)(const gp_Pnt &)) &BRepBlend_SurfPointConstRadInv::Set, "Set the Point on which a solution has to be found.", py::arg("P"));
cls_BRepBlend_SurfPointConstRadInv.def("GetTolerance", (void (BRepBlend_SurfPointConstRadInv::*)(math_Vector &, const Standard_Real) const) &BRepBlend_SurfPointConstRadInv::GetTolerance, "Returns in the vector Tolerance the parametric tolerance for each of the 3 variables; Tol is the tolerance used in 3d space.", py::arg("Tolerance"), py::arg("Tol"));
cls_BRepBlend_SurfPointConstRadInv.def("GetBounds", (void (BRepBlend_SurfPointConstRadInv::*)(math_Vector &, math_Vector &) const) &BRepBlend_SurfPointConstRadInv::GetBounds, "Returns in the vector InfBound the lowest values allowed for each of the 3 variables. Returns in the vector SupBound the greatest values allowed for each of the 3 variables.", py::arg("InfBound"), py::arg("SupBound"));
cls_BRepBlend_SurfPointConstRadInv.def("IsSolution", (Standard_Boolean (BRepBlend_SurfPointConstRadInv::*)(const math_Vector &, const Standard_Real)) &BRepBlend_SurfPointConstRadInv::IsSolution, "Returns Standard_True if Sol is a zero of the function. Tol is the tolerance used in 3d space.", py::arg("Sol"), py::arg("Tol"));

// CLASS: BREPBLEND_SURFPOINTEVOLRADINV
py::class_<BRepBlend_SurfPointEvolRadInv, Blend_SurfPointFuncInv> cls_BRepBlend_SurfPointEvolRadInv(mod, "BRepBlend_SurfPointEvolRadInv", "Function of reframing between a point and a surface. This function is used to find a solution on a done point of the curve when using SurfRstConsRad or CSConstRad... The vector <X> used in Value, Values and Derivatives methods has to be the vector of the parametric coordinates w, U, V where w is the parameter on the guide line, U,V are the parametric coordinates of a point on the partner surface.");

// Constructors
cls_BRepBlend_SurfPointEvolRadInv.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Law_Function> &>(), py::arg("S"), py::arg("C"), py::arg("Evol"));

// Methods
// cls_BRepBlend_SurfPointEvolRadInv.def_static("operator new_", (void * (*)(size_t)) &BRepBlend_SurfPointEvolRadInv::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_SurfPointEvolRadInv.def_static("operator delete_", (void (*)(void *)) &BRepBlend_SurfPointEvolRadInv::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_SurfPointEvolRadInv.def_static("operator new[]_", (void * (*)(size_t)) &BRepBlend_SurfPointEvolRadInv::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_SurfPointEvolRadInv.def_static("operator delete[]_", (void (*)(void *)) &BRepBlend_SurfPointEvolRadInv::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_SurfPointEvolRadInv.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBlend_SurfPointEvolRadInv::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_SurfPointEvolRadInv.def_static("operator delete_", (void (*)(void *, void *)) &BRepBlend_SurfPointEvolRadInv::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_SurfPointEvolRadInv.def("Set", (void (BRepBlend_SurfPointEvolRadInv::*)(const Standard_Integer)) &BRepBlend_SurfPointEvolRadInv::Set, "None", py::arg("Choix"));
cls_BRepBlend_SurfPointEvolRadInv.def("NbEquations", (Standard_Integer (BRepBlend_SurfPointEvolRadInv::*)() const) &BRepBlend_SurfPointEvolRadInv::NbEquations, "returns 3.");
cls_BRepBlend_SurfPointEvolRadInv.def("Value", (Standard_Boolean (BRepBlend_SurfPointEvolRadInv::*)(const math_Vector &, math_Vector &)) &BRepBlend_SurfPointEvolRadInv::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_BRepBlend_SurfPointEvolRadInv.def("Derivatives", (Standard_Boolean (BRepBlend_SurfPointEvolRadInv::*)(const math_Vector &, math_Matrix &)) &BRepBlend_SurfPointEvolRadInv::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_BRepBlend_SurfPointEvolRadInv.def("Values", (Standard_Boolean (BRepBlend_SurfPointEvolRadInv::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BRepBlend_SurfPointEvolRadInv::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_BRepBlend_SurfPointEvolRadInv.def("Set", (void (BRepBlend_SurfPointEvolRadInv::*)(const gp_Pnt &)) &BRepBlend_SurfPointEvolRadInv::Set, "Set the Point on which a solution has to be found.", py::arg("P"));
cls_BRepBlend_SurfPointEvolRadInv.def("GetTolerance", (void (BRepBlend_SurfPointEvolRadInv::*)(math_Vector &, const Standard_Real) const) &BRepBlend_SurfPointEvolRadInv::GetTolerance, "Returns in the vector Tolerance the parametric tolerance for each of the 3 variables; Tol is the tolerance used in 3d space.", py::arg("Tolerance"), py::arg("Tol"));
cls_BRepBlend_SurfPointEvolRadInv.def("GetBounds", (void (BRepBlend_SurfPointEvolRadInv::*)(math_Vector &, math_Vector &) const) &BRepBlend_SurfPointEvolRadInv::GetBounds, "Returns in the vector InfBound the lowest values allowed for each of the 3 variables. Returns in the vector SupBound the greatest values allowed for each of the 3 variables.", py::arg("InfBound"), py::arg("SupBound"));
cls_BRepBlend_SurfPointEvolRadInv.def("IsSolution", (Standard_Boolean (BRepBlend_SurfPointEvolRadInv::*)(const math_Vector &, const Standard_Real)) &BRepBlend_SurfPointEvolRadInv::IsSolution, "Returns Standard_True if Sol is a zero of the function. Tol is the tolerance used in 3d space.", py::arg("Sol"), py::arg("Tol"));

// CLASS: BREPBLEND_SURFRSTCONSTRAD
py::class_<BRepBlend_SurfRstConstRad, Blend_SurfRstFunction> cls_BRepBlend_SurfRstConstRad(mod, "BRepBlend_SurfRstConstRad", "Copy of CSConstRad with pcurve on surface as support.");

// Constructors
cls_BRepBlend_SurfRstConstRad.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("Surf"), py::arg("SurfRst"), py::arg("Rst"), py::arg("CGuide"));

// Methods
// cls_BRepBlend_SurfRstConstRad.def_static("operator new_", (void * (*)(size_t)) &BRepBlend_SurfRstConstRad::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_SurfRstConstRad.def_static("operator delete_", (void (*)(void *)) &BRepBlend_SurfRstConstRad::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_SurfRstConstRad.def_static("operator new[]_", (void * (*)(size_t)) &BRepBlend_SurfRstConstRad::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_SurfRstConstRad.def_static("operator delete[]_", (void (*)(void *)) &BRepBlend_SurfRstConstRad::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_SurfRstConstRad.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBlend_SurfRstConstRad::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_SurfRstConstRad.def_static("operator delete_", (void (*)(void *, void *)) &BRepBlend_SurfRstConstRad::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_SurfRstConstRad.def("NbVariables", (Standard_Integer (BRepBlend_SurfRstConstRad::*)() const) &BRepBlend_SurfRstConstRad::NbVariables, "Returns 3.");
cls_BRepBlend_SurfRstConstRad.def("NbEquations", (Standard_Integer (BRepBlend_SurfRstConstRad::*)() const) &BRepBlend_SurfRstConstRad::NbEquations, "Returns 3.");
cls_BRepBlend_SurfRstConstRad.def("Value", (Standard_Boolean (BRepBlend_SurfRstConstRad::*)(const math_Vector &, math_Vector &)) &BRepBlend_SurfRstConstRad::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_BRepBlend_SurfRstConstRad.def("Derivatives", (Standard_Boolean (BRepBlend_SurfRstConstRad::*)(const math_Vector &, math_Matrix &)) &BRepBlend_SurfRstConstRad::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_BRepBlend_SurfRstConstRad.def("Values", (Standard_Boolean (BRepBlend_SurfRstConstRad::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BRepBlend_SurfRstConstRad::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_BRepBlend_SurfRstConstRad.def("Set", (void (BRepBlend_SurfRstConstRad::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_SurfRstConstRad::Set, "None", py::arg("SurfRef"), py::arg("RstRef"));
cls_BRepBlend_SurfRstConstRad.def("Set", (void (BRepBlend_SurfRstConstRad::*)(const Standard_Real)) &BRepBlend_SurfRstConstRad::Set, "None", py::arg("Param"));
cls_BRepBlend_SurfRstConstRad.def("Set", (void (BRepBlend_SurfRstConstRad::*)(const Standard_Real, const Standard_Real)) &BRepBlend_SurfRstConstRad::Set, "Sets the bounds of the parametric interval on the guide line. This determines the derivatives in these values if the function is not Cn.", py::arg("First"), py::arg("Last"));
cls_BRepBlend_SurfRstConstRad.def("GetTolerance", (void (BRepBlend_SurfRstConstRad::*)(math_Vector &, const Standard_Real) const) &BRepBlend_SurfRstConstRad::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
cls_BRepBlend_SurfRstConstRad.def("GetBounds", (void (BRepBlend_SurfRstConstRad::*)(math_Vector &, math_Vector &) const) &BRepBlend_SurfRstConstRad::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
cls_BRepBlend_SurfRstConstRad.def("IsSolution", (Standard_Boolean (BRepBlend_SurfRstConstRad::*)(const math_Vector &, const Standard_Real)) &BRepBlend_SurfRstConstRad::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
cls_BRepBlend_SurfRstConstRad.def("GetMinimalDistance", (Standard_Real (BRepBlend_SurfRstConstRad::*)() const) &BRepBlend_SurfRstConstRad::GetMinimalDistance, "Returns the minimal Distance beetween two extremitys of calculed sections.");
cls_BRepBlend_SurfRstConstRad.def("PointOnS", (const gp_Pnt & (BRepBlend_SurfRstConstRad::*)() const) &BRepBlend_SurfRstConstRad::PointOnS, "None");
cls_BRepBlend_SurfRstConstRad.def("PointOnRst", (const gp_Pnt & (BRepBlend_SurfRstConstRad::*)() const) &BRepBlend_SurfRstConstRad::PointOnRst, "None");
cls_BRepBlend_SurfRstConstRad.def("Pnt2dOnS", (const gp_Pnt2d & (BRepBlend_SurfRstConstRad::*)() const) &BRepBlend_SurfRstConstRad::Pnt2dOnS, "Returns U,V coordinates of the point on the surface.");
cls_BRepBlend_SurfRstConstRad.def("Pnt2dOnRst", (const gp_Pnt2d & (BRepBlend_SurfRstConstRad::*)() const) &BRepBlend_SurfRstConstRad::Pnt2dOnRst, "Returns U,V coordinates of the point on the curve on surface.");
cls_BRepBlend_SurfRstConstRad.def("ParameterOnRst", (Standard_Real (BRepBlend_SurfRstConstRad::*)() const) &BRepBlend_SurfRstConstRad::ParameterOnRst, "Returns parameter of the point on the curve.");
cls_BRepBlend_SurfRstConstRad.def("IsTangencyPoint", (Standard_Boolean (BRepBlend_SurfRstConstRad::*)() const) &BRepBlend_SurfRstConstRad::IsTangencyPoint, "None");
cls_BRepBlend_SurfRstConstRad.def("TangentOnS", (const gp_Vec & (BRepBlend_SurfRstConstRad::*)() const) &BRepBlend_SurfRstConstRad::TangentOnS, "None");
cls_BRepBlend_SurfRstConstRad.def("Tangent2dOnS", (const gp_Vec2d & (BRepBlend_SurfRstConstRad::*)() const) &BRepBlend_SurfRstConstRad::Tangent2dOnS, "None");
cls_BRepBlend_SurfRstConstRad.def("TangentOnRst", (const gp_Vec & (BRepBlend_SurfRstConstRad::*)() const) &BRepBlend_SurfRstConstRad::TangentOnRst, "None");
cls_BRepBlend_SurfRstConstRad.def("Tangent2dOnRst", (const gp_Vec2d & (BRepBlend_SurfRstConstRad::*)() const) &BRepBlend_SurfRstConstRad::Tangent2dOnRst, "None");
cls_BRepBlend_SurfRstConstRad.def("Decroch", (Standard_Boolean (BRepBlend_SurfRstConstRad::*)(const math_Vector &, gp_Vec &, gp_Vec &) const) &BRepBlend_SurfRstConstRad::Decroch, "Enables implementation of a criterion of decrochage specific to the function. Warning: Can be called without previous call of issolution but the values calculated can be senseless.", py::arg("Sol"), py::arg("NS"), py::arg("TgS"));
cls_BRepBlend_SurfRstConstRad.def("Set", (void (BRepBlend_SurfRstConstRad::*)(const Standard_Real, const Standard_Integer)) &BRepBlend_SurfRstConstRad::Set, "None", py::arg("Radius"), py::arg("Choix"));
cls_BRepBlend_SurfRstConstRad.def("Set", (void (BRepBlend_SurfRstConstRad::*)(const BlendFunc_SectionShape)) &BRepBlend_SurfRstConstRad::Set, "Sets the type of section generation for the approximations.", py::arg("TypeSection"));
cls_BRepBlend_SurfRstConstRad.def("Section", [](BRepBlend_SurfRstConstRad &self, const Standard_Real Param, const Standard_Real U, const Standard_Real V, const Standard_Real W, Standard_Real & Pdeb, Standard_Real & Pfin, gp_Circ & C){ self.Section(Param, U, V, W, Pdeb, Pfin, C); return std::tuple<Standard_Real &, Standard_Real &>(Pdeb, Pfin); }, "None", py::arg("Param"), py::arg("U"), py::arg("V"), py::arg("W"), py::arg("Pdeb"), py::arg("Pfin"), py::arg("C"));
cls_BRepBlend_SurfRstConstRad.def("IsRational", (Standard_Boolean (BRepBlend_SurfRstConstRad::*)() const) &BRepBlend_SurfRstConstRad::IsRational, "Returns if the section is rationnal");
cls_BRepBlend_SurfRstConstRad.def("GetSectionSize", (Standard_Real (BRepBlend_SurfRstConstRad::*)() const) &BRepBlend_SurfRstConstRad::GetSectionSize, "Returns the length of the maximum section");
cls_BRepBlend_SurfRstConstRad.def("GetMinimalWeight", (void (BRepBlend_SurfRstConstRad::*)(TColStd_Array1OfReal &) const) &BRepBlend_SurfRstConstRad::GetMinimalWeight, "Compute the minimal value of weight for each poles of all sections.", py::arg("Weigths"));
cls_BRepBlend_SurfRstConstRad.def("NbIntervals", (Standard_Integer (BRepBlend_SurfRstConstRad::*)(const GeomAbs_Shape) const) &BRepBlend_SurfRstConstRad::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_BRepBlend_SurfRstConstRad.def("Intervals", (void (BRepBlend_SurfRstConstRad::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &BRepBlend_SurfRstConstRad::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>. The array must provide enough room to accomodate for the parameters. i.e. T.Length() > NbIntervals()", py::arg("T"), py::arg("S"));
cls_BRepBlend_SurfRstConstRad.def("GetShape", [](BRepBlend_SurfRstConstRad &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree, Standard_Integer & NbPoles2d){ self.GetShape(NbPoles, NbKnots, Degree, NbPoles2d); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree, NbPoles2d); }, "None", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"), py::arg("NbPoles2d"));
cls_BRepBlend_SurfRstConstRad.def("GetTolerance", (void (BRepBlend_SurfRstConstRad::*)(const Standard_Real, const Standard_Real, const Standard_Real, math_Vector &, math_Vector &) const) &BRepBlend_SurfRstConstRad::GetTolerance, "Returns the tolerance to reach in approximation to respecte BoundTol error at the Boundary AngleTol tangent error at the Boundary SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"), py::arg("Tol1D"));
cls_BRepBlend_SurfRstConstRad.def("Knots", (void (BRepBlend_SurfRstConstRad::*)(TColStd_Array1OfReal &)) &BRepBlend_SurfRstConstRad::Knots, "None", py::arg("TKnots"));
cls_BRepBlend_SurfRstConstRad.def("Mults", (void (BRepBlend_SurfRstConstRad::*)(TColStd_Array1OfInteger &)) &BRepBlend_SurfRstConstRad::Mults, "None", py::arg("TMults"));
cls_BRepBlend_SurfRstConstRad.def("Section", (Standard_Boolean (BRepBlend_SurfRstConstRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BRepBlend_SurfRstConstRad::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
cls_BRepBlend_SurfRstConstRad.def("Section", (Standard_Boolean (BRepBlend_SurfRstConstRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BRepBlend_SurfRstConstRad::Section, "Used for the first and last section The method returns Standard_True if the derivatives are computed, otherwise it returns Standard_False.", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
cls_BRepBlend_SurfRstConstRad.def("Section", (void (BRepBlend_SurfRstConstRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &)) &BRepBlend_SurfRstConstRad::Section, "None", py::arg("P"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
cls_BRepBlend_SurfRstConstRad.def("Resolution", [](BRepBlend_SurfRstConstRad &self, const Standard_Integer IC2d, const Standard_Real Tol, Standard_Real & TolU, Standard_Real & TolV){ self.Resolution(IC2d, Tol, TolU, TolV); return std::tuple<Standard_Real &, Standard_Real &>(TolU, TolV); }, "None", py::arg("IC2d"), py::arg("Tol"), py::arg("TolU"), py::arg("TolV"));

// CLASS: BREPBLEND_SURFRSTEVOLRAD
py::class_<BRepBlend_SurfRstEvolRad, Blend_SurfRstFunction> cls_BRepBlend_SurfRstEvolRad(mod, "BRepBlend_SurfRstEvolRad", "Function to approximate by AppSurface for Edge/Face and evolutif radius");

// Constructors
cls_BRepBlend_SurfRstEvolRad.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Law_Function> &>(), py::arg("Surf"), py::arg("SurfRst"), py::arg("Rst"), py::arg("CGuide"), py::arg("Evol"));

// Methods
// cls_BRepBlend_SurfRstEvolRad.def_static("operator new_", (void * (*)(size_t)) &BRepBlend_SurfRstEvolRad::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_SurfRstEvolRad.def_static("operator delete_", (void (*)(void *)) &BRepBlend_SurfRstEvolRad::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_SurfRstEvolRad.def_static("operator new[]_", (void * (*)(size_t)) &BRepBlend_SurfRstEvolRad::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_SurfRstEvolRad.def_static("operator delete[]_", (void (*)(void *)) &BRepBlend_SurfRstEvolRad::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_SurfRstEvolRad.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBlend_SurfRstEvolRad::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_SurfRstEvolRad.def_static("operator delete_", (void (*)(void *, void *)) &BRepBlend_SurfRstEvolRad::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_SurfRstEvolRad.def("NbVariables", (Standard_Integer (BRepBlend_SurfRstEvolRad::*)() const) &BRepBlend_SurfRstEvolRad::NbVariables, "Returns 3.");
cls_BRepBlend_SurfRstEvolRad.def("NbEquations", (Standard_Integer (BRepBlend_SurfRstEvolRad::*)() const) &BRepBlend_SurfRstEvolRad::NbEquations, "Returns 3.");
cls_BRepBlend_SurfRstEvolRad.def("Value", (Standard_Boolean (BRepBlend_SurfRstEvolRad::*)(const math_Vector &, math_Vector &)) &BRepBlend_SurfRstEvolRad::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_BRepBlend_SurfRstEvolRad.def("Derivatives", (Standard_Boolean (BRepBlend_SurfRstEvolRad::*)(const math_Vector &, math_Matrix &)) &BRepBlend_SurfRstEvolRad::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_BRepBlend_SurfRstEvolRad.def("Values", (Standard_Boolean (BRepBlend_SurfRstEvolRad::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BRepBlend_SurfRstEvolRad::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_BRepBlend_SurfRstEvolRad.def("Set", (void (BRepBlend_SurfRstEvolRad::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_SurfRstEvolRad::Set, "None", py::arg("SurfRef"), py::arg("RstRef"));
cls_BRepBlend_SurfRstEvolRad.def("Set", (void (BRepBlend_SurfRstEvolRad::*)(const Standard_Real)) &BRepBlend_SurfRstEvolRad::Set, "None", py::arg("Param"));
cls_BRepBlend_SurfRstEvolRad.def("Set", (void (BRepBlend_SurfRstEvolRad::*)(const Standard_Real, const Standard_Real)) &BRepBlend_SurfRstEvolRad::Set, "Sets the bounds of the parametric interval on the guide line. This determines the derivatives in these values if the function is not Cn.", py::arg("First"), py::arg("Last"));
cls_BRepBlend_SurfRstEvolRad.def("GetTolerance", (void (BRepBlend_SurfRstEvolRad::*)(math_Vector &, const Standard_Real) const) &BRepBlend_SurfRstEvolRad::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
cls_BRepBlend_SurfRstEvolRad.def("GetBounds", (void (BRepBlend_SurfRstEvolRad::*)(math_Vector &, math_Vector &) const) &BRepBlend_SurfRstEvolRad::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
cls_BRepBlend_SurfRstEvolRad.def("IsSolution", (Standard_Boolean (BRepBlend_SurfRstEvolRad::*)(const math_Vector &, const Standard_Real)) &BRepBlend_SurfRstEvolRad::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
cls_BRepBlend_SurfRstEvolRad.def("GetMinimalDistance", (Standard_Real (BRepBlend_SurfRstEvolRad::*)() const) &BRepBlend_SurfRstEvolRad::GetMinimalDistance, "Returns the minimal Distance beetween two extremitys of calculed sections.");
cls_BRepBlend_SurfRstEvolRad.def("PointOnS", (const gp_Pnt & (BRepBlend_SurfRstEvolRad::*)() const) &BRepBlend_SurfRstEvolRad::PointOnS, "None");
cls_BRepBlend_SurfRstEvolRad.def("PointOnRst", (const gp_Pnt & (BRepBlend_SurfRstEvolRad::*)() const) &BRepBlend_SurfRstEvolRad::PointOnRst, "None");
cls_BRepBlend_SurfRstEvolRad.def("Pnt2dOnS", (const gp_Pnt2d & (BRepBlend_SurfRstEvolRad::*)() const) &BRepBlend_SurfRstEvolRad::Pnt2dOnS, "Returns U,V coordinates of the point on the surface.");
cls_BRepBlend_SurfRstEvolRad.def("Pnt2dOnRst", (const gp_Pnt2d & (BRepBlend_SurfRstEvolRad::*)() const) &BRepBlend_SurfRstEvolRad::Pnt2dOnRst, "Returns U,V coordinates of the point on the curve on surface.");
cls_BRepBlend_SurfRstEvolRad.def("ParameterOnRst", (Standard_Real (BRepBlend_SurfRstEvolRad::*)() const) &BRepBlend_SurfRstEvolRad::ParameterOnRst, "Returns parameter of the point on the curve.");
cls_BRepBlend_SurfRstEvolRad.def("IsTangencyPoint", (Standard_Boolean (BRepBlend_SurfRstEvolRad::*)() const) &BRepBlend_SurfRstEvolRad::IsTangencyPoint, "None");
cls_BRepBlend_SurfRstEvolRad.def("TangentOnS", (const gp_Vec & (BRepBlend_SurfRstEvolRad::*)() const) &BRepBlend_SurfRstEvolRad::TangentOnS, "None");
cls_BRepBlend_SurfRstEvolRad.def("Tangent2dOnS", (const gp_Vec2d & (BRepBlend_SurfRstEvolRad::*)() const) &BRepBlend_SurfRstEvolRad::Tangent2dOnS, "None");
cls_BRepBlend_SurfRstEvolRad.def("TangentOnRst", (const gp_Vec & (BRepBlend_SurfRstEvolRad::*)() const) &BRepBlend_SurfRstEvolRad::TangentOnRst, "None");
cls_BRepBlend_SurfRstEvolRad.def("Tangent2dOnRst", (const gp_Vec2d & (BRepBlend_SurfRstEvolRad::*)() const) &BRepBlend_SurfRstEvolRad::Tangent2dOnRst, "None");
cls_BRepBlend_SurfRstEvolRad.def("Decroch", (Standard_Boolean (BRepBlend_SurfRstEvolRad::*)(const math_Vector &, gp_Vec &, gp_Vec &) const) &BRepBlend_SurfRstEvolRad::Decroch, "Permet d ' implementer un critere de decrochage specifique a la fonction.", py::arg("Sol"), py::arg("NS"), py::arg("TgS"));
cls_BRepBlend_SurfRstEvolRad.def("Set", (void (BRepBlend_SurfRstEvolRad::*)(const Standard_Integer)) &BRepBlend_SurfRstEvolRad::Set, "None", py::arg("Choix"));
cls_BRepBlend_SurfRstEvolRad.def("Set", (void (BRepBlend_SurfRstEvolRad::*)(const BlendFunc_SectionShape)) &BRepBlend_SurfRstEvolRad::Set, "Sets the type of section generation for the approximations.", py::arg("TypeSection"));
cls_BRepBlend_SurfRstEvolRad.def("Section", [](BRepBlend_SurfRstEvolRad &self, const Standard_Real Param, const Standard_Real U, const Standard_Real V, const Standard_Real W, Standard_Real & Pdeb, Standard_Real & Pfin, gp_Circ & C){ self.Section(Param, U, V, W, Pdeb, Pfin, C); return std::tuple<Standard_Real &, Standard_Real &>(Pdeb, Pfin); }, "None", py::arg("Param"), py::arg("U"), py::arg("V"), py::arg("W"), py::arg("Pdeb"), py::arg("Pfin"), py::arg("C"));
cls_BRepBlend_SurfRstEvolRad.def("IsRational", (Standard_Boolean (BRepBlend_SurfRstEvolRad::*)() const) &BRepBlend_SurfRstEvolRad::IsRational, "Returns if the section is rationnal");
cls_BRepBlend_SurfRstEvolRad.def("GetSectionSize", (Standard_Real (BRepBlend_SurfRstEvolRad::*)() const) &BRepBlend_SurfRstEvolRad::GetSectionSize, "Returns the length of the maximum section");
cls_BRepBlend_SurfRstEvolRad.def("GetMinimalWeight", (void (BRepBlend_SurfRstEvolRad::*)(TColStd_Array1OfReal &) const) &BRepBlend_SurfRstEvolRad::GetMinimalWeight, "Compute the minimal value of weight for each poles of all sections.", py::arg("Weigths"));
cls_BRepBlend_SurfRstEvolRad.def("NbIntervals", (Standard_Integer (BRepBlend_SurfRstEvolRad::*)(const GeomAbs_Shape) const) &BRepBlend_SurfRstEvolRad::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_BRepBlend_SurfRstEvolRad.def("Intervals", (void (BRepBlend_SurfRstEvolRad::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &BRepBlend_SurfRstEvolRad::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>. The array must provide enough room to accomodate for the parameters. i.e. T.Length() > NbIntervals()", py::arg("T"), py::arg("S"));
cls_BRepBlend_SurfRstEvolRad.def("GetShape", [](BRepBlend_SurfRstEvolRad &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree, Standard_Integer & NbPoles2d){ self.GetShape(NbPoles, NbKnots, Degree, NbPoles2d); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree, NbPoles2d); }, "None", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"), py::arg("NbPoles2d"));
cls_BRepBlend_SurfRstEvolRad.def("GetTolerance", (void (BRepBlend_SurfRstEvolRad::*)(const Standard_Real, const Standard_Real, const Standard_Real, math_Vector &, math_Vector &) const) &BRepBlend_SurfRstEvolRad::GetTolerance, "Returns the tolerance to reach in approximation to respecte BoundTol error at the Boundary AngleTol tangent error at the Boundary SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"), py::arg("Tol1D"));
cls_BRepBlend_SurfRstEvolRad.def("Knots", (void (BRepBlend_SurfRstEvolRad::*)(TColStd_Array1OfReal &)) &BRepBlend_SurfRstEvolRad::Knots, "None", py::arg("TKnots"));
cls_BRepBlend_SurfRstEvolRad.def("Mults", (void (BRepBlend_SurfRstEvolRad::*)(TColStd_Array1OfInteger &)) &BRepBlend_SurfRstEvolRad::Mults, "None", py::arg("TMults"));
cls_BRepBlend_SurfRstEvolRad.def("Section", (Standard_Boolean (BRepBlend_SurfRstEvolRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BRepBlend_SurfRstEvolRad::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
cls_BRepBlend_SurfRstEvolRad.def("Section", (Standard_Boolean (BRepBlend_SurfRstEvolRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BRepBlend_SurfRstEvolRad::Section, "Used for the first and last section The method returns Standard_True if the derivatives are computed, otherwise it returns Standard_False.", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
cls_BRepBlend_SurfRstEvolRad.def("Section", (void (BRepBlend_SurfRstEvolRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &)) &BRepBlend_SurfRstEvolRad::Section, "None", py::arg("P"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
cls_BRepBlend_SurfRstEvolRad.def("Resolution", [](BRepBlend_SurfRstEvolRad &self, const Standard_Integer IC2d, const Standard_Real Tol, Standard_Real & TolU, Standard_Real & TolV){ self.Resolution(IC2d, Tol, TolU, TolV); return std::tuple<Standard_Real &, Standard_Real &>(TolU, TolV); }, "None", py::arg("IC2d"), py::arg("Tol"), py::arg("TolU"), py::arg("TolV"));

// CLASS: BREPBLEND_SURFRSTLINEBUILDER
py::class_<BRepBlend_SurfRstLineBuilder> cls_BRepBlend_SurfRstLineBuilder(mod, "BRepBlend_SurfRstLineBuilder", "This class processes data resulting from Blend_CSWalking taking in consideration the Surface supporting the curve to detect the breakpoint.");

// Constructors
cls_BRepBlend_SurfRstLineBuilder.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_TopolTool> &>(), py::arg("Surf1"), py::arg("Domain1"), py::arg("Surf2"), py::arg("Rst"), py::arg("Domain2"));

// Methods
// cls_BRepBlend_SurfRstLineBuilder.def_static("operator new_", (void * (*)(size_t)) &BRepBlend_SurfRstLineBuilder::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_SurfRstLineBuilder.def_static("operator delete_", (void (*)(void *)) &BRepBlend_SurfRstLineBuilder::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_SurfRstLineBuilder.def_static("operator new[]_", (void * (*)(size_t)) &BRepBlend_SurfRstLineBuilder::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_SurfRstLineBuilder.def_static("operator delete[]_", (void (*)(void *)) &BRepBlend_SurfRstLineBuilder::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_SurfRstLineBuilder.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBlend_SurfRstLineBuilder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_SurfRstLineBuilder.def_static("operator delete_", (void (*)(void *, void *)) &BRepBlend_SurfRstLineBuilder::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_SurfRstLineBuilder.def("Perform", [](BRepBlend_SurfRstLineBuilder &self, Blend_SurfRstFunction & a0, Blend_FuncInv & a1, Blend_SurfPointFuncInv & a2, Blend_SurfCurvFuncInv & a3, const Standard_Real a4, const Standard_Real a5, const Standard_Real a6, const Standard_Real a7, const math_Vector & a8, const Standard_Real a9, const Standard_Real a10) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10); });
cls_BRepBlend_SurfRstLineBuilder.def("Perform", (void (BRepBlend_SurfRstLineBuilder::*)(Blend_SurfRstFunction &, Blend_FuncInv &, Blend_SurfPointFuncInv &, Blend_SurfCurvFuncInv &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const math_Vector &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &BRepBlend_SurfRstLineBuilder::Perform, "None", py::arg("Func"), py::arg("Finv"), py::arg("FinvP"), py::arg("FinvC"), py::arg("Pdep"), py::arg("Pmax"), py::arg("MaxStep"), py::arg("TolGuide"), py::arg("Soldep"), py::arg("Tolesp"), py::arg("Fleche"), py::arg("Appro"));
cls_BRepBlend_SurfRstLineBuilder.def("PerformFirstSection", [](BRepBlend_SurfRstLineBuilder &self, Blend_SurfRstFunction & Func, Blend_FuncInv & Finv, Blend_SurfPointFuncInv & FinvP, Blend_SurfCurvFuncInv & FinvC, const Standard_Real Pdep, const Standard_Real Pmax, const math_Vector & Soldep, const Standard_Real Tolesp, const Standard_Real TolGuide, const Standard_Boolean RecRst, const Standard_Boolean RecP, const Standard_Boolean RecS, Standard_Real & Psol, math_Vector & ParSol){ Standard_Boolean rv = self.PerformFirstSection(Func, Finv, FinvP, FinvC, Pdep, Pmax, Soldep, Tolesp, TolGuide, RecRst, RecP, RecS, Psol, ParSol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Psol); }, "None", py::arg("Func"), py::arg("Finv"), py::arg("FinvP"), py::arg("FinvC"), py::arg("Pdep"), py::arg("Pmax"), py::arg("Soldep"), py::arg("Tolesp"), py::arg("TolGuide"), py::arg("RecRst"), py::arg("RecP"), py::arg("RecS"), py::arg("Psol"), py::arg("ParSol"));
cls_BRepBlend_SurfRstLineBuilder.def("Complete", (Standard_Boolean (BRepBlend_SurfRstLineBuilder::*)(Blend_SurfRstFunction &, Blend_FuncInv &, Blend_SurfPointFuncInv &, Blend_SurfCurvFuncInv &, const Standard_Real)) &BRepBlend_SurfRstLineBuilder::Complete, "None", py::arg("Func"), py::arg("Finv"), py::arg("FinvP"), py::arg("FinvC"), py::arg("Pmin"));
cls_BRepBlend_SurfRstLineBuilder.def("ArcToRecadre", [](BRepBlend_SurfRstLineBuilder &self, const math_Vector & Sol, const Standard_Integer PrevIndex, gp_Pnt2d & pt2d, gp_Pnt2d & lastpt2d, Standard_Real & ponarc){ Standard_Integer rv = self.ArcToRecadre(Sol, PrevIndex, pt2d, lastpt2d, ponarc); return std::tuple<Standard_Integer, Standard_Real &>(rv, ponarc); }, "None", py::arg("Sol"), py::arg("PrevIndex"), py::arg("pt2d"), py::arg("lastpt2d"), py::arg("ponarc"));
cls_BRepBlend_SurfRstLineBuilder.def("IsDone", (Standard_Boolean (BRepBlend_SurfRstLineBuilder::*)() const) &BRepBlend_SurfRstLineBuilder::IsDone, "None");
cls_BRepBlend_SurfRstLineBuilder.def("Line", (const opencascade::handle<BRepBlend_Line> & (BRepBlend_SurfRstLineBuilder::*)() const) &BRepBlend_SurfRstLineBuilder::Line, "None");
cls_BRepBlend_SurfRstLineBuilder.def("DecrochStart", (Standard_Boolean (BRepBlend_SurfRstLineBuilder::*)() const) &BRepBlend_SurfRstLineBuilder::DecrochStart, "None");
cls_BRepBlend_SurfRstLineBuilder.def("DecrochEnd", (Standard_Boolean (BRepBlend_SurfRstLineBuilder::*)() const) &BRepBlend_SurfRstLineBuilder::DecrochEnd, "None");

// CLASS: BREPBLEND_WALKING
py::class_<BRepBlend_Walking> cls_BRepBlend_Walking(mod, "BRepBlend_Walking", "None");

// Constructors
cls_BRepBlend_Walking.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<ChFiDS_HElSpine> &>(), py::arg("Surf1"), py::arg("Surf2"), py::arg("Domain1"), py::arg("Domain2"), py::arg("HGuide"));

// Methods
// cls_BRepBlend_Walking.def_static("operator new_", (void * (*)(size_t)) &BRepBlend_Walking::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_Walking.def_static("operator delete_", (void (*)(void *)) &BRepBlend_Walking::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_Walking.def_static("operator new[]_", (void * (*)(size_t)) &BRepBlend_Walking::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_Walking.def_static("operator delete[]_", (void (*)(void *)) &BRepBlend_Walking::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_Walking.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBlend_Walking::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_Walking.def_static("operator delete_", (void (*)(void *, void *)) &BRepBlend_Walking::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_Walking.def("SetDomainsToRecadre", (void (BRepBlend_Walking::*)(const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_TopolTool> &)) &BRepBlend_Walking::SetDomainsToRecadre, "To define different domains for control and clipping.", py::arg("RecDomain1"), py::arg("RecDomain2"));
cls_BRepBlend_Walking.def("AddSingularPoint", (void (BRepBlend_Walking::*)(const Blend_Point &)) &BRepBlend_Walking::AddSingularPoint, "To define singular points computed before walking.", py::arg("P"));
cls_BRepBlend_Walking.def("Perform", [](BRepBlend_Walking &self, Blend_Function & a0, Blend_FuncInv & a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, const Standard_Real a5, const math_Vector & a6, const Standard_Real a7, const Standard_Real a8) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6, a7, a8); });
cls_BRepBlend_Walking.def("Perform", (void (BRepBlend_Walking::*)(Blend_Function &, Blend_FuncInv &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const math_Vector &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &BRepBlend_Walking::Perform, "None", py::arg("F"), py::arg("FInv"), py::arg("Pdep"), py::arg("Pmax"), py::arg("MaxStep"), py::arg("TolGuide"), py::arg("Soldep"), py::arg("Tolesp"), py::arg("Fleche"), py::arg("Appro"));
cls_BRepBlend_Walking.def("PerformFirstSection", (Standard_Boolean (BRepBlend_Walking::*)(Blend_Function &, const Standard_Real, math_Vector &, const Standard_Real, const Standard_Real, TopAbs_State &, TopAbs_State &)) &BRepBlend_Walking::PerformFirstSection, "None", py::arg("F"), py::arg("Pdep"), py::arg("ParDep"), py::arg("Tolesp"), py::arg("TolGuide"), py::arg("Pos1"), py::arg("Pos2"));
cls_BRepBlend_Walking.def("PerformFirstSection", [](BRepBlend_Walking &self, Blend_Function & F, Blend_FuncInv & FInv, const Standard_Real Pdep, const Standard_Real Pmax, const math_Vector & ParDep, const Standard_Real Tolesp, const Standard_Real TolGuide, const Standard_Boolean RecOnS1, const Standard_Boolean RecOnS2, Standard_Real & Psol, math_Vector & ParSol){ Standard_Boolean rv = self.PerformFirstSection(F, FInv, Pdep, Pmax, ParDep, Tolesp, TolGuide, RecOnS1, RecOnS2, Psol, ParSol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Psol); }, "None", py::arg("F"), py::arg("FInv"), py::arg("Pdep"), py::arg("Pmax"), py::arg("ParDep"), py::arg("Tolesp"), py::arg("TolGuide"), py::arg("RecOnS1"), py::arg("RecOnS2"), py::arg("Psol"), py::arg("ParSol"));
cls_BRepBlend_Walking.def("Continu", (Standard_Boolean (BRepBlend_Walking::*)(Blend_Function &, Blend_FuncInv &, const Standard_Real)) &BRepBlend_Walking::Continu, "None", py::arg("F"), py::arg("FInv"), py::arg("P"));
cls_BRepBlend_Walking.def("Continu", (Standard_Boolean (BRepBlend_Walking::*)(Blend_Function &, Blend_FuncInv &, const Standard_Real, const Standard_Boolean)) &BRepBlend_Walking::Continu, "None", py::arg("F"), py::arg("FInv"), py::arg("P"), py::arg("OnS1"));
cls_BRepBlend_Walking.def("Complete", (Standard_Boolean (BRepBlend_Walking::*)(Blend_Function &, Blend_FuncInv &, const Standard_Real)) &BRepBlend_Walking::Complete, "None", py::arg("F"), py::arg("FInv"), py::arg("Pmin"));
cls_BRepBlend_Walking.def("ClassificationOnS1", (void (BRepBlend_Walking::*)(const Standard_Boolean)) &BRepBlend_Walking::ClassificationOnS1, "None", py::arg("C"));
cls_BRepBlend_Walking.def("ClassificationOnS2", (void (BRepBlend_Walking::*)(const Standard_Boolean)) &BRepBlend_Walking::ClassificationOnS2, "None", py::arg("C"));
cls_BRepBlend_Walking.def("Check2d", (void (BRepBlend_Walking::*)(const Standard_Boolean)) &BRepBlend_Walking::Check2d, "None", py::arg("C"));
cls_BRepBlend_Walking.def("Check", (void (BRepBlend_Walking::*)(const Standard_Boolean)) &BRepBlend_Walking::Check, "None", py::arg("C"));
cls_BRepBlend_Walking.def("TwistOnS1", (Standard_Boolean (BRepBlend_Walking::*)() const) &BRepBlend_Walking::TwistOnS1, "None");
cls_BRepBlend_Walking.def("TwistOnS2", (Standard_Boolean (BRepBlend_Walking::*)() const) &BRepBlend_Walking::TwistOnS2, "None");
cls_BRepBlend_Walking.def("IsDone", (Standard_Boolean (BRepBlend_Walking::*)() const) &BRepBlend_Walking::IsDone, "None");
cls_BRepBlend_Walking.def("Line", (const opencascade::handle<BRepBlend_Line> & (BRepBlend_Walking::*)() const) &BRepBlend_Walking::Line, "None");


}
