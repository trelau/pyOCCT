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
#include <HLRAlgo_Projector.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <TopoDS_Edge.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Dir2d.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <gp_Vec2d.hxx>
#include <GeomAbs_CurveType.hxx>
#include <gp_Lin2d.hxx>
#include <gp_Circ2d.hxx>
#include <gp_Elips2d.hxx>
#include <gp_Hypr2d.hxx>
#include <gp_Parab2d.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <Standard_Handle.hxx>
#include <Geom_BSplineCurve.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <HLRBRep_Curve.hxx>

void bind_HLRBRep_Curve(py::module &mod){

py::class_<HLRBRep_Curve> cls_HLRBRep_Curve(mod, "HLRBRep_Curve", "Defines a 2d curve by projection of a 3D curve on a plane with an optional perspective transformation.");

// Constructors
cls_HLRBRep_Curve.def(py::init<>());

// Fields

// Methods
// cls_HLRBRep_Curve.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_Curve::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_Curve.def_static("operator delete_", (void (*)(void *)) &HLRBRep_Curve::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_Curve.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_Curve::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_Curve.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_Curve::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_Curve.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_Curve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_Curve.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_Curve::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_Curve.def("Projector", (void (HLRBRep_Curve::*)(const HLRAlgo_Projector *)) &HLRBRep_Curve::Projector, "None", py::arg("Proj"));
cls_HLRBRep_Curve.def("Curve", (BRepAdaptor_Curve & (HLRBRep_Curve::*)()) &HLRBRep_Curve::Curve, "Returns the 3D curve.");
cls_HLRBRep_Curve.def("Curve", (void (HLRBRep_Curve::*)(const TopoDS_Edge &)) &HLRBRep_Curve::Curve, "Sets the 3D curve to be projected.", py::arg("E"));
cls_HLRBRep_Curve.def("GetCurve", (const BRepAdaptor_Curve & (HLRBRep_Curve::*)() const) &HLRBRep_Curve::GetCurve, "Returns the 3D curve.");
cls_HLRBRep_Curve.def("Parameter2d", (Standard_Real (HLRBRep_Curve::*)(const Standard_Real) const) &HLRBRep_Curve::Parameter2d, "Returns the parameter on the 2d curve from the parameter on the 3d curve.", py::arg("P3d"));
cls_HLRBRep_Curve.def("Parameter3d", (Standard_Real (HLRBRep_Curve::*)(const Standard_Real) const) &HLRBRep_Curve::Parameter3d, "Returns the parameter on the 3d curve from the parameter on the 2d curve.", py::arg("P2d"));
// cls_HLRBRep_Curve.def("Update", (Standard_Real (HLRBRep_Curve::*)(Standard_Real [16], Standard_Real [16])) &HLRBRep_Curve::Update, "Update the minmax and the internal data", py::arg("TotMin"), py::arg("TotMax"));
// cls_HLRBRep_Curve.def("UpdateMinMax", (Standard_Real (HLRBRep_Curve::*)(Standard_Real [16], Standard_Real [16])) &HLRBRep_Curve::UpdateMinMax, "Update the minmax returns tol for enlarge;", py::arg("TotMin"), py::arg("TotMax"));
cls_HLRBRep_Curve.def("Z", (Standard_Real (HLRBRep_Curve::*)(const Standard_Real) const) &HLRBRep_Curve::Z, "Computes the Z coordinate of the point of parameter U on the curve in the viewing coordinate system", py::arg("U"));
cls_HLRBRep_Curve.def("Value3D", (gp_Pnt (HLRBRep_Curve::*)(const Standard_Real) const) &HLRBRep_Curve::Value3D, "Computes the 3D point of parameter U on the curve.", py::arg("U"));
cls_HLRBRep_Curve.def("D0", (void (HLRBRep_Curve::*)(const Standard_Real, gp_Pnt &) const) &HLRBRep_Curve::D0, "Computes the 3D point of parameter U on the curve.", py::arg("U"), py::arg("P"));
cls_HLRBRep_Curve.def("D1", (void (HLRBRep_Curve::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const) &HLRBRep_Curve::D1, "Computes the point of parameter U on the curve with its first derivative.", py::arg("U"), py::arg("P"), py::arg("V"));
cls_HLRBRep_Curve.def("Tangent", (void (HLRBRep_Curve::*)(const Standard_Boolean, gp_Pnt2d &, gp_Dir2d &) const) &HLRBRep_Curve::Tangent, "Depending on <AtStart> computes the 2D point and tangent on the curve at sart (or at end). If the first derivative is null look after at start (or before at end) with the second derivative.", py::arg("AtStart"), py::arg("P"), py::arg("D"));
cls_HLRBRep_Curve.def("FirstParameter", (Standard_Real (HLRBRep_Curve::*)() const) &HLRBRep_Curve::FirstParameter, "None");
cls_HLRBRep_Curve.def("LastParameter", (Standard_Real (HLRBRep_Curve::*)() const) &HLRBRep_Curve::LastParameter, "None");
cls_HLRBRep_Curve.def("Continuity", (GeomAbs_Shape (HLRBRep_Curve::*)() const) &HLRBRep_Curve::Continuity, "None");
cls_HLRBRep_Curve.def("NbIntervals", (Standard_Integer (HLRBRep_Curve::*)(const GeomAbs_Shape) const) &HLRBRep_Curve::NbIntervals, "If necessary, breaks the curve in intervals of continuity <S>. And returns the number of intervals.", py::arg("S"));
cls_HLRBRep_Curve.def("Intervals", (void (HLRBRep_Curve::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &HLRBRep_Curve::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_HLRBRep_Curve.def("IsClosed", (Standard_Boolean (HLRBRep_Curve::*)() const) &HLRBRep_Curve::IsClosed, "None");
cls_HLRBRep_Curve.def("IsPeriodic", (Standard_Boolean (HLRBRep_Curve::*)() const) &HLRBRep_Curve::IsPeriodic, "None");
cls_HLRBRep_Curve.def("Period", (Standard_Real (HLRBRep_Curve::*)() const) &HLRBRep_Curve::Period, "None");
cls_HLRBRep_Curve.def("Value", (gp_Pnt2d (HLRBRep_Curve::*)(const Standard_Real) const) &HLRBRep_Curve::Value, "Computes the point of parameter U on the curve.", py::arg("U"));
cls_HLRBRep_Curve.def("D0", (void (HLRBRep_Curve::*)(const Standard_Real, gp_Pnt2d &) const) &HLRBRep_Curve::D0, "Computes the point of parameter U on the curve.", py::arg("U"), py::arg("P"));
cls_HLRBRep_Curve.def("D1", (void (HLRBRep_Curve::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const) &HLRBRep_Curve::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("U"), py::arg("P"), py::arg("V"));
cls_HLRBRep_Curve.def("D2", (void (HLRBRep_Curve::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const) &HLRBRep_Curve::D2, "Raised if the continuity of the current interval is not C2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_HLRBRep_Curve.def("D3", (void (HLRBRep_Curve::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &) const) &HLRBRep_Curve::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C3.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_HLRBRep_Curve.def("DN", (gp_Vec2d (HLRBRep_Curve::*)(const Standard_Real, const Standard_Integer) const) &HLRBRep_Curve::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if the continuity of the current interval is not CN. Raised if N < 1.", py::arg("U"), py::arg("N"));
cls_HLRBRep_Curve.def("Resolution", (Standard_Real (HLRBRep_Curve::*)(const Standard_Real) const) &HLRBRep_Curve::Resolution, "Returns the parametric resolution corresponding to the real space resolution <R3d>.", py::arg("R3d"));
cls_HLRBRep_Curve.def("GetType", (GeomAbs_CurveType (HLRBRep_Curve::*)() const) &HLRBRep_Curve::GetType, "Returns the type of the curve in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.");
cls_HLRBRep_Curve.def("Line", (gp_Lin2d (HLRBRep_Curve::*)() const) &HLRBRep_Curve::Line, "None");
cls_HLRBRep_Curve.def("Circle", (gp_Circ2d (HLRBRep_Curve::*)() const) &HLRBRep_Curve::Circle, "None");
cls_HLRBRep_Curve.def("Ellipse", (gp_Elips2d (HLRBRep_Curve::*)() const) &HLRBRep_Curve::Ellipse, "None");
cls_HLRBRep_Curve.def("Hyperbola", (gp_Hypr2d (HLRBRep_Curve::*)() const) &HLRBRep_Curve::Hyperbola, "None");
cls_HLRBRep_Curve.def("Parabola", (gp_Parab2d (HLRBRep_Curve::*)() const) &HLRBRep_Curve::Parabola, "None");
cls_HLRBRep_Curve.def("IsRational", (Standard_Boolean (HLRBRep_Curve::*)() const) &HLRBRep_Curve::IsRational, "None");
cls_HLRBRep_Curve.def("Degree", (Standard_Integer (HLRBRep_Curve::*)() const) &HLRBRep_Curve::Degree, "None");
cls_HLRBRep_Curve.def("NbPoles", (Standard_Integer (HLRBRep_Curve::*)() const) &HLRBRep_Curve::NbPoles, "None");
cls_HLRBRep_Curve.def("Poles", (void (HLRBRep_Curve::*)(TColgp_Array1OfPnt2d &) const) &HLRBRep_Curve::Poles, "None", py::arg("TP"));
cls_HLRBRep_Curve.def("Poles", (void (HLRBRep_Curve::*)(const opencascade::handle<Geom_BSplineCurve> &, TColgp_Array1OfPnt2d &) const) &HLRBRep_Curve::Poles, "None", py::arg("aCurve"), py::arg("TP"));
cls_HLRBRep_Curve.def("PolesAndWeights", (void (HLRBRep_Curve::*)(TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &) const) &HLRBRep_Curve::PolesAndWeights, "None", py::arg("TP"), py::arg("TW"));
cls_HLRBRep_Curve.def("PolesAndWeights", (void (HLRBRep_Curve::*)(const opencascade::handle<Geom_BSplineCurve> &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &) const) &HLRBRep_Curve::PolesAndWeights, "None", py::arg("aCurve"), py::arg("TP"), py::arg("TW"));
cls_HLRBRep_Curve.def("NbKnots", (Standard_Integer (HLRBRep_Curve::*)() const) &HLRBRep_Curve::NbKnots, "None");
cls_HLRBRep_Curve.def("Knots", (void (HLRBRep_Curve::*)(TColStd_Array1OfReal &) const) &HLRBRep_Curve::Knots, "None", py::arg("kn"));
cls_HLRBRep_Curve.def("Multiplicities", (void (HLRBRep_Curve::*)(TColStd_Array1OfInteger &) const) &HLRBRep_Curve::Multiplicities, "None", py::arg("mu"));

// Enums

}