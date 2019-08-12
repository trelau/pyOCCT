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
#include <GeomFill_LocationLaw.hxx>
#include <Standard_Handle.hxx>
#include <GeomFill_TrihedronLaw.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <gp_Mat.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Vec.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColgp_Array1OfVec2d.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <gp_Pnt.hxx>
#include <GeomFill_CurveAndTrihedron.hxx>
#include <Standard_Type.hxx>

void bind_GeomFill_CurveAndTrihedron(py::module &mod){

py::class_<GeomFill_CurveAndTrihedron, opencascade::handle<GeomFill_CurveAndTrihedron>, GeomFill_LocationLaw> cls_GeomFill_CurveAndTrihedron(mod, "GeomFill_CurveAndTrihedron", "Define location law with an TrihedronLaw and an curve Definition Location is : transformed section coordinates in (Curve(v)), (Normal(v), BiNormal(v), Tangente(v))) systeme are the same like section shape coordinates in (O,(OX, OY, OZ)) systeme.");

// Constructors
cls_GeomFill_CurveAndTrihedron.def(py::init<const opencascade::handle<GeomFill_TrihedronLaw> &>(), py::arg("Trihedron"));

// Fields

// Methods
cls_GeomFill_CurveAndTrihedron.def("SetCurve", (void (GeomFill_CurveAndTrihedron::*)(const opencascade::handle<Adaptor3d_HCurve> &)) &GeomFill_CurveAndTrihedron::SetCurve, "None", py::arg("C"));
cls_GeomFill_CurveAndTrihedron.def("GetCurve", (const opencascade::handle<Adaptor3d_HCurve> & (GeomFill_CurveAndTrihedron::*)() const) &GeomFill_CurveAndTrihedron::GetCurve, "None");
cls_GeomFill_CurveAndTrihedron.def("SetTrsf", (void (GeomFill_CurveAndTrihedron::*)(const gp_Mat &)) &GeomFill_CurveAndTrihedron::SetTrsf, "Set a transformation Matrix like the law M(t) become Mat * M(t)", py::arg("Transfo"));
cls_GeomFill_CurveAndTrihedron.def("Copy", (opencascade::handle<GeomFill_LocationLaw> (GeomFill_CurveAndTrihedron::*)() const) &GeomFill_CurveAndTrihedron::Copy, "None");
cls_GeomFill_CurveAndTrihedron.def("D0", (Standard_Boolean (GeomFill_CurveAndTrihedron::*)(const Standard_Real, gp_Mat &, gp_Vec &)) &GeomFill_CurveAndTrihedron::D0, "compute Location and 2d points", py::arg("Param"), py::arg("M"), py::arg("V"));
cls_GeomFill_CurveAndTrihedron.def("D0", (Standard_Boolean (GeomFill_CurveAndTrihedron::*)(const Standard_Real, gp_Mat &, gp_Vec &, TColgp_Array1OfPnt2d &)) &GeomFill_CurveAndTrihedron::D0, "compute Location and 2d points", py::arg("Param"), py::arg("M"), py::arg("V"), py::arg("Poles2d"));
cls_GeomFill_CurveAndTrihedron.def("D1", (Standard_Boolean (GeomFill_CurveAndTrihedron::*)(const Standard_Real, gp_Mat &, gp_Vec &, gp_Mat &, gp_Vec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &)) &GeomFill_CurveAndTrihedron::D1, "compute location 2d points and associated first derivatives. Warning : It used only for C1 or C2 aproximation", py::arg("Param"), py::arg("M"), py::arg("V"), py::arg("DM"), py::arg("DV"), py::arg("Poles2d"), py::arg("DPoles2d"));
cls_GeomFill_CurveAndTrihedron.def("D2", (Standard_Boolean (GeomFill_CurveAndTrihedron::*)(const Standard_Real, gp_Mat &, gp_Vec &, gp_Mat &, gp_Vec &, gp_Mat &, gp_Vec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &)) &GeomFill_CurveAndTrihedron::D2, "compute location 2d points and associated first and seconde derivatives. Warning : It used only for C2 aproximation", py::arg("Param"), py::arg("M"), py::arg("V"), py::arg("DM"), py::arg("DV"), py::arg("D2M"), py::arg("D2V"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"));
cls_GeomFill_CurveAndTrihedron.def("NbIntervals", (Standard_Integer (GeomFill_CurveAndTrihedron::*)(const GeomAbs_Shape) const) &GeomFill_CurveAndTrihedron::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_GeomFill_CurveAndTrihedron.def("Intervals", (void (GeomFill_CurveAndTrihedron::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &GeomFill_CurveAndTrihedron::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_GeomFill_CurveAndTrihedron.def("SetInterval", (void (GeomFill_CurveAndTrihedron::*)(const Standard_Real, const Standard_Real)) &GeomFill_CurveAndTrihedron::SetInterval, "Sets the bounds of the parametric interval on the function This determines the derivatives in these values if the function is not Cn.", py::arg("First"), py::arg("Last"));
cls_GeomFill_CurveAndTrihedron.def("GetInterval", [](GeomFill_CurveAndTrihedron &self, Standard_Real & First, Standard_Real & Last){ self.GetInterval(First, Last); return std::tuple<Standard_Real &, Standard_Real &>(First, Last); }, "Gets the bounds of the parametric interval on the function", py::arg("First"), py::arg("Last"));
cls_GeomFill_CurveAndTrihedron.def("GetDomain", [](GeomFill_CurveAndTrihedron &self, Standard_Real & First, Standard_Real & Last){ self.GetDomain(First, Last); return std::tuple<Standard_Real &, Standard_Real &>(First, Last); }, "Gets the bounds of the function parametric domain. Warning: This domain it is not modified by the SetValue method", py::arg("First"), py::arg("Last"));
cls_GeomFill_CurveAndTrihedron.def("GetMaximalNorm", (Standard_Real (GeomFill_CurveAndTrihedron::*)()) &GeomFill_CurveAndTrihedron::GetMaximalNorm, "Get the maximum Norm of the matrix-location part. It is usful to find an good Tolerance to approx M(t).");
cls_GeomFill_CurveAndTrihedron.def("GetAverageLaw", (void (GeomFill_CurveAndTrihedron::*)(gp_Mat &, gp_Vec &)) &GeomFill_CurveAndTrihedron::GetAverageLaw, "Get average value of M(t) and V(t) it is usfull to make fast approximation of rational surfaces.", py::arg("AM"), py::arg("AV"));
cls_GeomFill_CurveAndTrihedron.def("IsTranslation", [](GeomFill_CurveAndTrihedron &self, Standard_Real & Error){ Standard_Boolean rv = self.IsTranslation(Error); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Error); }, "Say if the Location Law, is an translation of Location The default implementation is ' returns False '.", py::arg("Error"));
cls_GeomFill_CurveAndTrihedron.def("IsRotation", [](GeomFill_CurveAndTrihedron &self, Standard_Real & Error){ Standard_Boolean rv = self.IsRotation(Error); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Error); }, "Say if the Location Law, is a rotation of Location The default implementation is ' returns False '.", py::arg("Error"));
cls_GeomFill_CurveAndTrihedron.def("Rotation", (void (GeomFill_CurveAndTrihedron::*)(gp_Pnt &) const) &GeomFill_CurveAndTrihedron::Rotation, "None", py::arg("Center"));
cls_GeomFill_CurveAndTrihedron.def_static("get_type_name_", (const char * (*)()) &GeomFill_CurveAndTrihedron::get_type_name, "None");
cls_GeomFill_CurveAndTrihedron.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_CurveAndTrihedron::get_type_descriptor, "None");
cls_GeomFill_CurveAndTrihedron.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_CurveAndTrihedron::*)() const) &GeomFill_CurveAndTrihedron::DynamicType, "None");

// Enums

}