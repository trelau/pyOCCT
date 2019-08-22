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
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <gp_Ax2.hxx>
#include <Geom2d_Curve.hxx>
#include <gp_GTrsf2d.hxx>
#include <Standard_TypeDef.hxx>
#include <Adaptor3d_CurveOnSurface.hxx>
#include <GeomAbs_Shape.hxx>
#include <Geom_BoundedCurve.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <Geom_BoundedSurface.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <gp_Dir.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <Adaptor3d_Curve.hxx>
#include <Geom_BSplineSurface.hxx>
#include <Geom_Surface.hxx>
#include <gp_Pnt2d.hxx>
#include <Geom_BezierSurface.hxx>
#include <GeomLib_MakeCurvefromApprox.hxx>
#include <GeomLib_Interpolate.hxx>
#include <GeomLib_DenominatorMultiplier.hxx>
#include <GeomLib_CheckBSplineCurve.hxx>
#include <GeomLib_Check2dBSplineCurve.hxx>
#include <GeomLib_IsPlanarSurface.hxx>
#include <GeomLib_Tool.hxx>
#include <GeomLib_PolyFunc.hxx>
#include <GeomLib_LogSample.hxx>
#include <GeomLib.hxx>

void bind_GeomLib(py::module &mod){

py::class_<GeomLib> cls_GeomLib(mod, "GeomLib", "Geom Library. This package provides an implementation of functions for basic computation on geometric entity from packages Geom and Geom2d.");

// Constructors

// Fields

// Methods
// cls_GeomLib.def_static("operator new_", (void * (*)(size_t)) &GeomLib::operator new, "None", py::arg("theSize"));
// cls_GeomLib.def_static("operator delete_", (void (*)(void *)) &GeomLib::operator delete, "None", py::arg("theAddress"));
// cls_GeomLib.def_static("operator new[]_", (void * (*)(size_t)) &GeomLib::operator new[], "None", py::arg("theSize"));
// cls_GeomLib.def_static("operator delete[]_", (void (*)(void *)) &GeomLib::operator delete[], "None", py::arg("theAddress"));
// cls_GeomLib.def_static("operator new_", (void * (*)(size_t, void *)) &GeomLib::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomLib.def_static("operator delete_", (void (*)(void *, void *)) &GeomLib::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomLib.def_static("To3d_", (opencascade::handle<Geom_Curve> (*)(const gp_Ax2 &, const opencascade::handle<Geom2d_Curve> &)) &GeomLib::To3d, "Computes the curve 3d from package Geom corresponding to curve 2d from package Geom2d, on the plan defined with the local coordinate system Position.", py::arg("Position"), py::arg("Curve2d"));
cls_GeomLib.def_static("GTransform_", (opencascade::handle<Geom2d_Curve> (*)(const opencascade::handle<Geom2d_Curve> &, const gp_GTrsf2d &)) &GeomLib::GTransform, "Computes the curve 3d from package Geom corresponding to the curve 3d from package Geom, transformed with the transformation <GTrsf> WARNING : this method may return a null Handle if it's impossible to compute the transformation of a curve. It's not implemented when : 1) the curve is an infinite parabola or hyperbola 2) the curve is an offsetcurve", py::arg("Curve"), py::arg("GTrsf"));
cls_GeomLib.def_static("SameRange_", (void (*)(const Standard_Real, const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, opencascade::handle<Geom2d_Curve> &)) &GeomLib::SameRange, "Make the curve Curve2dPtr have the imposed range First to List the most economic way, that is if it can change the range without changing the nature of the curve it will try to do that. Otherwise it will produce a Bspline curve that has the required range", py::arg("Tolerance"), py::arg("Curve2dPtr"), py::arg("First"), py::arg("Last"), py::arg("RequestedFirst"), py::arg("RequestedLast"), py::arg("NewCurve2dPtr"));
cls_GeomLib.def_static("BuildCurve3d_", [](const Standard_Real Tolerance, Adaptor3d_CurveOnSurface & CurvePtr, const Standard_Real FirstParameter, const Standard_Real LastParameter, opencascade::handle<Geom_Curve> & NewCurvePtr, Standard_Real & MaxDeviation, Standard_Real & AverageDeviation, const GeomAbs_Shape Continuity, const Standard_Integer MaxDegree, const Standard_Integer MaxSegment){ GeomLib::BuildCurve3d(Tolerance, CurvePtr, FirstParameter, LastParameter, NewCurvePtr, MaxDeviation, AverageDeviation, Continuity, MaxDegree, MaxSegment); return std::tuple<Standard_Real &, Standard_Real &>(MaxDeviation, AverageDeviation); }, "None", py::arg("Tolerance"), py::arg("CurvePtr"), py::arg("FirstParameter"), py::arg("LastParameter"), py::arg("NewCurvePtr"), py::arg("MaxDeviation"), py::arg("AverageDeviation"), py::arg("Continuity"), py::arg("MaxDegree"), py::arg("MaxSegment"));
cls_GeomLib.def_static("AdjustExtremity_", (void (*)(opencascade::handle<Geom_BoundedCurve> &, const gp_Pnt &, const gp_Pnt &, const gp_Vec &, const gp_Vec &)) &GeomLib::AdjustExtremity, "None", py::arg("Curve"), py::arg("P1"), py::arg("P2"), py::arg("T1"), py::arg("T2"));
cls_GeomLib.def_static("ExtendCurveToPoint_", (void (*)(opencascade::handle<Geom_BoundedCurve> &, const gp_Pnt &, const Standard_Integer, const Standard_Boolean)) &GeomLib::ExtendCurveToPoint, "Extends the bounded curve Curve to the point Point. The extension is built: - at the end of the curve if After equals true, or - at the beginning of the curve if After equals false. The extension is performed according to a degree of continuity equal to Cont, which in its turn must be equal to 1, 2 or 3. This function converts the bounded curve Curve into a BSpline curve. Warning - Nothing is done, and Curve is not modified if Cont is not equal to 1, 2 or 3. - It is recommended that the extension should not be too large with respect to the size of the bounded curve Curve: Point must not be located too far from one of the extremities of Curve.", py::arg("Curve"), py::arg("Point"), py::arg("Cont"), py::arg("After"));
cls_GeomLib.def_static("ExtendSurfByLength_", (void (*)(opencascade::handle<Geom_BoundedSurface> &, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Standard_Boolean)) &GeomLib::ExtendSurfByLength, "Extends the bounded surface Surf along one of its boundaries. The chord length of the extension is equal to Length. The direction of the extension is given as: - the u parametric direction of Surf, if InU equals true, or - the v parametric direction of Surf, if InU equals false. In this parametric direction, the extension is built on the side of: - the last parameter of Surf, if After equals true, or - the first parameter of Surf, if After equals false. The extension is performed according to a degree of continuity equal to Cont, which in its turn must be equal to 1, 2 or 3. This function converts the bounded surface Surf into a BSpline surface. Warning - Nothing is done, and Surf is not modified if Cont is not equal to 1, 2 or 3. - It is recommended that Length, the size of the extension should not be too large with respect to the size of the bounded surface Surf. - Surf must not be a periodic BSpline surface in the parametric direction corresponding to the direction of extension.", py::arg("Surf"), py::arg("Length"), py::arg("Cont"), py::arg("InU"), py::arg("After"));
cls_GeomLib.def_static("AxeOfInertia_", [](const TColgp_Array1OfPnt & Points, gp_Ax2 & Axe, Standard_Boolean & IsSingular, const Standard_Real Tol){ GeomLib::AxeOfInertia(Points, Axe, IsSingular, Tol); return IsSingular; }, "Compute axes of inertia, of some points -- -- -- <Axe>.Location() is the BaryCentre -- -- -- -- -- <Axe>.XDirection is the axe of upper inertia -- -- -- -- <Axe>.Direction is the Normal to the average plane -- -- -- IsSingular is True if points are on line -- Tol is used to determine singular cases.", py::arg("Points"), py::arg("Axe"), py::arg("IsSingular"), py::arg("Tol"));
cls_GeomLib.def_static("Inertia_", [](const TColgp_Array1OfPnt & Points, gp_Pnt & Bary, gp_Dir & XDir, gp_Dir & YDir, Standard_Real & Xgap, Standard_Real & YGap, Standard_Real & ZGap){ GeomLib::Inertia(Points, Bary, XDir, YDir, Xgap, YGap, ZGap); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(Xgap, YGap, ZGap); }, "Compute principale axes of inertia, and dispertion value of some points.", py::arg("Points"), py::arg("Bary"), py::arg("XDir"), py::arg("YDir"), py::arg("Xgap"), py::arg("YGap"), py::arg("ZGap"));
cls_GeomLib.def_static("RemovePointsFromArray_", (void (*)(const Standard_Integer, const TColStd_Array1OfReal &, opencascade::handle<TColStd_HArray1OfReal> &)) &GeomLib::RemovePointsFromArray, "Warning! This assume that the InParameter is an increasing sequence of real number and it will not check for that : Unpredictable result can happen if this is not satisfied. It is the caller responsability to check for that property.", py::arg("NumPoints"), py::arg("InParameters"), py::arg("OutParameters"));
cls_GeomLib.def_static("DensifyArray1OfReal_", (void (*)(const Standard_Integer, const TColStd_Array1OfReal &, opencascade::handle<TColStd_HArray1OfReal> &)) &GeomLib::DensifyArray1OfReal, "this makes sure that there is at least MinNumPoints in OutParameters taking into account the parameters in the InParameters array provided those are in order, that is the sequence of real in the InParameter is strictly non decreasing", py::arg("MinNumPoints"), py::arg("InParameters"), py::arg("OutParameters"));
cls_GeomLib.def_static("FuseIntervals_", [](const TColStd_Array1OfReal & a0, const TColStd_Array1OfReal & a1, TColStd_SequenceOfReal & a2) -> void { return GeomLib::FuseIntervals(a0, a1, a2); });
cls_GeomLib.def_static("FuseIntervals_", (void (*)(const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, TColStd_SequenceOfReal &, const Standard_Real)) &GeomLib::FuseIntervals, "None", py::arg("Interval1"), py::arg("Interval2"), py::arg("Fusion"), py::arg("Confusion"));
cls_GeomLib.def_static("EvalMaxParametricDistance_", [](const Adaptor3d_Curve & Curve, const Adaptor3d_Curve & AReferenceCurve, const Standard_Real Tolerance, const TColStd_Array1OfReal & Parameters, Standard_Real & MaxDistance){ GeomLib::EvalMaxParametricDistance(Curve, AReferenceCurve, Tolerance, Parameters, MaxDistance); return MaxDistance; }, "this will compute the maximum distance at the parameters given in the Parameters array by evaluating each parameter the two curves and taking the maximum of the evaluated distance", py::arg("Curve"), py::arg("AReferenceCurve"), py::arg("Tolerance"), py::arg("Parameters"), py::arg("MaxDistance"));
cls_GeomLib.def_static("EvalMaxDistanceAlongParameter_", [](const Adaptor3d_Curve & Curve, const Adaptor3d_Curve & AReferenceCurve, const Standard_Real Tolerance, const TColStd_Array1OfReal & Parameters, Standard_Real & MaxDistance){ GeomLib::EvalMaxDistanceAlongParameter(Curve, AReferenceCurve, Tolerance, Parameters, MaxDistance); return MaxDistance; }, "this will compute the maximum distancef at the parameters given in the Parameters array by projecting from the Curve to the reference curve and taking the minimum distance Than the maximum will be taken on those minimas.", py::arg("Curve"), py::arg("AReferenceCurve"), py::arg("Tolerance"), py::arg("Parameters"), py::arg("MaxDistance"));
cls_GeomLib.def_static("CancelDenominatorDerivative_", (void (*)(opencascade::handle<Geom_BSplineSurface> &, const Standard_Boolean, const Standard_Boolean)) &GeomLib::CancelDenominatorDerivative, "Cancel,on the boudaries,the denominator first derivative in the directions wished by the user and set its value to 1.", py::arg("BSurf"), py::arg("UDirection"), py::arg("VDirection"));
cls_GeomLib.def_static("NormEstim_", (Standard_Integer (*)(const opencascade::handle<Geom_Surface> &, const gp_Pnt2d &, const Standard_Real, gp_Dir &)) &GeomLib::NormEstim, "None", py::arg("S"), py::arg("UV"), py::arg("Tol"), py::arg("N"));
cls_GeomLib.def_static("IsClosed_", [](const opencascade::handle<Geom_Surface> & S, const Standard_Real Tol, Standard_Boolean & isUClosed, Standard_Boolean & isVClosed){ GeomLib::IsClosed(S, Tol, isUClosed, isVClosed); return std::tuple<Standard_Boolean &, Standard_Boolean &>(isUClosed, isVClosed); }, "This method defines if opposite boundaries of surface coincide with given tolerance", py::arg("S"), py::arg("Tol"), py::arg("isUClosed"), py::arg("isVClosed"));
cls_GeomLib.def_static("IsBSplUClosed_", (Standard_Boolean (*)(const opencascade::handle<Geom_BSplineSurface> &, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomLib::IsBSplUClosed, "Returns true if the poles of U1 isoline and the poles of U2 isoline of surface are identical according to tolerance criterion. For rational surfaces Weights(i)*Poles(i) are checked.", py::arg("S"), py::arg("U1"), py::arg("U2"), py::arg("Tol"));
cls_GeomLib.def_static("IsBSplVClosed_", (Standard_Boolean (*)(const opencascade::handle<Geom_BSplineSurface> &, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomLib::IsBSplVClosed, "Returns true if the poles of V1 isoline and the poles of V2 isoline of surface are identical according to tolerance criterion. For rational surfaces Weights(i)*Poles(i) are checked.", py::arg("S"), py::arg("V1"), py::arg("V2"), py::arg("Tol"));
cls_GeomLib.def_static("IsBzUClosed_", (Standard_Boolean (*)(const opencascade::handle<Geom_BezierSurface> &, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomLib::IsBzUClosed, "Returns true if the poles of U1 isoline and the poles of U2 isoline of surface are identical according to tolerance criterion.", py::arg("S"), py::arg("U1"), py::arg("U2"), py::arg("Tol"));
cls_GeomLib.def_static("IsBzVClosed_", (Standard_Boolean (*)(const opencascade::handle<Geom_BezierSurface> &, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomLib::IsBzVClosed, "Returns true if the poles of V1 isoline and the poles of V2 isoline of surface are identical according to tolerance criterion.", py::arg("S"), py::arg("V1"), py::arg("V2"), py::arg("Tol"));

// Enums

}