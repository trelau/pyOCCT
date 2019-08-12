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
#include <Bisector_Curve.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt2d.hxx>
#include <Bisector_BisecCC.hxx>
#include <Geom2d_Geometry.hxx>
#include <gp_Trsf2d.hxx>
#include <GeomAbs_Shape.hxx>
#include <gp_Vec2d.hxx>
#include <Bisector_PolyBis.hxx>
#include <Standard_Type.hxx>
#include <TColStd_SequenceOfReal.hxx>

void bind_Bisector_BisecCC(py::module &mod){

py::class_<Bisector_BisecCC, opencascade::handle<Bisector_BisecCC>, Bisector_Curve> cls_Bisector_BisecCC(mod, "Bisector_BisecCC", "Construct the bisector between two curves. The curves can intersect only in their extremities.");

// Constructors
cls_Bisector_BisecCC.def(py::init<>());
cls_Bisector_BisecCC.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real, const gp_Pnt2d &>(), py::arg("Cu1"), py::arg("Cu2"), py::arg("Side1"), py::arg("Side2"), py::arg("Origin"));
cls_Bisector_BisecCC.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real, const gp_Pnt2d &, const Standard_Real>(), py::arg("Cu1"), py::arg("Cu2"), py::arg("Side1"), py::arg("Side2"), py::arg("Origin"), py::arg("DistMax"));

// Fields

// Methods
cls_Bisector_BisecCC.def("Perform", [](Bisector_BisecCC &self, const opencascade::handle<Geom2d_Curve> & a0, const opencascade::handle<Geom2d_Curve> & a1, const Standard_Real a2, const Standard_Real a3, const gp_Pnt2d & a4) -> void { return self.Perform(a0, a1, a2, a3, a4); });
cls_Bisector_BisecCC.def("Perform", (void (Bisector_BisecCC::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real, const gp_Pnt2d &, const Standard_Real)) &Bisector_BisecCC::Perform, "Computes the bisector between the curves <Cu1> and <Cu2>.", py::arg("Cu1"), py::arg("Cu2"), py::arg("Side1"), py::arg("Side2"), py::arg("Origin"), py::arg("DistMax"));
cls_Bisector_BisecCC.def("IsExtendAtStart", (Standard_Boolean (Bisector_BisecCC::*)() const) &Bisector_BisecCC::IsExtendAtStart, "None");
cls_Bisector_BisecCC.def("IsExtendAtEnd", (Standard_Boolean (Bisector_BisecCC::*)() const) &Bisector_BisecCC::IsExtendAtEnd, "None");
cls_Bisector_BisecCC.def("Reverse", (void (Bisector_BisecCC::*)()) &Bisector_BisecCC::Reverse, "None");
cls_Bisector_BisecCC.def("ReversedParameter", (Standard_Real (Bisector_BisecCC::*)(const Standard_Real) const) &Bisector_BisecCC::ReversedParameter, "None", py::arg("U"));
cls_Bisector_BisecCC.def("IsCN", (Standard_Boolean (Bisector_BisecCC::*)(const Standard_Integer) const) &Bisector_BisecCC::IsCN, "Returns the order of continuity of the curve. Raised if N < 0.", py::arg("N"));
cls_Bisector_BisecCC.def("ChangeGuide", (opencascade::handle<Bisector_BisecCC> (Bisector_BisecCC::*)() const) &Bisector_BisecCC::ChangeGuide, "The parameter on <me> is linked to the parameter on the first curve. This method creates the same bisector where the curves are inversed.");
cls_Bisector_BisecCC.def("Copy", (opencascade::handle<Geom2d_Geometry> (Bisector_BisecCC::*)() const) &Bisector_BisecCC::Copy, "None");
cls_Bisector_BisecCC.def("Transform", (void (Bisector_BisecCC::*)(const gp_Trsf2d &)) &Bisector_BisecCC::Transform, "Transformation of a geometric object. This tansformation can be a translation, a rotation, a symmetry, a scaling or a complex transformation obtained by combination of the previous elementaries transformations.", py::arg("T"));
cls_Bisector_BisecCC.def("FirstParameter", (Standard_Real (Bisector_BisecCC::*)() const) &Bisector_BisecCC::FirstParameter, "None");
cls_Bisector_BisecCC.def("LastParameter", (Standard_Real (Bisector_BisecCC::*)() const) &Bisector_BisecCC::LastParameter, "None");
cls_Bisector_BisecCC.def("Continuity", (GeomAbs_Shape (Bisector_BisecCC::*)() const) &Bisector_BisecCC::Continuity, "None");
cls_Bisector_BisecCC.def("NbIntervals", (Standard_Integer (Bisector_BisecCC::*)() const) &Bisector_BisecCC::NbIntervals, "If necessary, breaks the curve in intervals of continuity <C1>. And returns the number of intervals.");
cls_Bisector_BisecCC.def("IntervalFirst", (Standard_Real (Bisector_BisecCC::*)(const Standard_Integer) const) &Bisector_BisecCC::IntervalFirst, "Returns the first parameter of the current interval.", py::arg("Index"));
cls_Bisector_BisecCC.def("IntervalLast", (Standard_Real (Bisector_BisecCC::*)(const Standard_Integer) const) &Bisector_BisecCC::IntervalLast, "Returns the last parameter of the current interval.", py::arg("Index"));
cls_Bisector_BisecCC.def("IntervalContinuity", (GeomAbs_Shape (Bisector_BisecCC::*)() const) &Bisector_BisecCC::IntervalContinuity, "None");
cls_Bisector_BisecCC.def("IsClosed", (Standard_Boolean (Bisector_BisecCC::*)() const) &Bisector_BisecCC::IsClosed, "None");
cls_Bisector_BisecCC.def("IsPeriodic", (Standard_Boolean (Bisector_BisecCC::*)() const) &Bisector_BisecCC::IsPeriodic, "None");
cls_Bisector_BisecCC.def("ValueAndDist", [](Bisector_BisecCC &self, const Standard_Real U, Standard_Real & U1, Standard_Real & U2, Standard_Real & Distance){ gp_Pnt2d rv = self.ValueAndDist(U, U1, U2, Distance); return std::tuple<gp_Pnt2d, Standard_Real &, Standard_Real &, Standard_Real &>(rv, U1, U2, Distance); }, "Returns the point of parameter U. Computes the distance between the current point and the two curves I separate. Computes the parameters on each curve corresponding of the projection of the current point.", py::arg("U"), py::arg("U1"), py::arg("U2"), py::arg("Distance"));
cls_Bisector_BisecCC.def("ValueByInt", [](Bisector_BisecCC &self, const Standard_Real U, Standard_Real & U1, Standard_Real & U2, Standard_Real & Distance){ gp_Pnt2d rv = self.ValueByInt(U, U1, U2, Distance); return std::tuple<gp_Pnt2d, Standard_Real &, Standard_Real &, Standard_Real &>(rv, U1, U2, Distance); }, "Returns the point of parameter U. Computes the distance between the current point and the two curves I separate. Computes the parameters on each curve corresponding of the projection of the current point.", py::arg("U"), py::arg("U1"), py::arg("U2"), py::arg("Distance"));
cls_Bisector_BisecCC.def("D0", (void (Bisector_BisecCC::*)(const Standard_Real, gp_Pnt2d &) const) &Bisector_BisecCC::D0, "None", py::arg("U"), py::arg("P"));
cls_Bisector_BisecCC.def("D1", (void (Bisector_BisecCC::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const) &Bisector_BisecCC::D1, "None", py::arg("U"), py::arg("P"), py::arg("V"));
cls_Bisector_BisecCC.def("D2", (void (Bisector_BisecCC::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const) &Bisector_BisecCC::D2, "None", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_Bisector_BisecCC.def("D3", (void (Bisector_BisecCC::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &) const) &Bisector_BisecCC::D3, "None", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_Bisector_BisecCC.def("DN", (gp_Vec2d (Bisector_BisecCC::*)(const Standard_Real, const Standard_Integer) const) &Bisector_BisecCC::DN, "None", py::arg("U"), py::arg("N"));
cls_Bisector_BisecCC.def("IsEmpty", (Standard_Boolean (Bisector_BisecCC::*)() const) &Bisector_BisecCC::IsEmpty, "None");
cls_Bisector_BisecCC.def("LinkBisCurve", (Standard_Real (Bisector_BisecCC::*)(const Standard_Real) const) &Bisector_BisecCC::LinkBisCurve, "Returns the parameter on the curve1 of the projection of the point of parameter U on <me>.", py::arg("U"));
cls_Bisector_BisecCC.def("LinkCurveBis", (Standard_Real (Bisector_BisecCC::*)(const Standard_Real) const) &Bisector_BisecCC::LinkCurveBis, "Returns the reciproque of LinkBisCurve.", py::arg("U"));
cls_Bisector_BisecCC.def("Parameter", (Standard_Real (Bisector_BisecCC::*)(const gp_Pnt2d &) const) &Bisector_BisecCC::Parameter, "None", py::arg("P"));
cls_Bisector_BisecCC.def("Curve", (opencascade::handle<Geom2d_Curve> (Bisector_BisecCC::*)(const Standard_Integer) const) &Bisector_BisecCC::Curve, "None", py::arg("IndCurve"));
cls_Bisector_BisecCC.def("Polygon", (const Bisector_PolyBis & (Bisector_BisecCC::*)() const) &Bisector_BisecCC::Polygon, "None");
cls_Bisector_BisecCC.def("Dump", [](Bisector_BisecCC &self) -> void { return self.Dump(); });
cls_Bisector_BisecCC.def("Dump", [](Bisector_BisecCC &self, const Standard_Integer a0) -> void { return self.Dump(a0); });
cls_Bisector_BisecCC.def("Dump", (void (Bisector_BisecCC::*)(const Standard_Integer, const Standard_Integer) const) &Bisector_BisecCC::Dump, "None", py::arg("Deep"), py::arg("Offset"));
cls_Bisector_BisecCC.def_static("get_type_name_", (const char * (*)()) &Bisector_BisecCC::get_type_name, "None");
cls_Bisector_BisecCC.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Bisector_BisecCC::get_type_descriptor, "None");
cls_Bisector_BisecCC.def("DynamicType", (const opencascade::handle<Standard_Type> & (Bisector_BisecCC::*)() const) &Bisector_BisecCC::DynamicType, "None");

// Enums

}