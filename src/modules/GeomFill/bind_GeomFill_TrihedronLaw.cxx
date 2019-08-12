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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <GeomFill_TrihedronLaw.hxx>
#include <GeomFill_PipeError.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Vec.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Standard_Type.hxx>

void bind_GeomFill_TrihedronLaw(py::module &mod){

py::class_<GeomFill_TrihedronLaw, opencascade::handle<GeomFill_TrihedronLaw>, Standard_Transient> cls_GeomFill_TrihedronLaw(mod, "GeomFill_TrihedronLaw", "To define Trihedron along one Curve");

// Fields

// Methods
cls_GeomFill_TrihedronLaw.def("SetCurve", (void (GeomFill_TrihedronLaw::*)(const opencascade::handle<Adaptor3d_HCurve> &)) &GeomFill_TrihedronLaw::SetCurve, "None", py::arg("C"));
cls_GeomFill_TrihedronLaw.def("Copy", (opencascade::handle<GeomFill_TrihedronLaw> (GeomFill_TrihedronLaw::*)() const) &GeomFill_TrihedronLaw::Copy, "None");
cls_GeomFill_TrihedronLaw.def("ErrorStatus", (GeomFill_PipeError (GeomFill_TrihedronLaw::*)() const) &GeomFill_TrihedronLaw::ErrorStatus, "Give a status to the Law Returns PipeOk (default implementation)");
cls_GeomFill_TrihedronLaw.def("D0", (Standard_Boolean (GeomFill_TrihedronLaw::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_TrihedronLaw::D0, "compute Triedrhon on curve at parameter <Param>", py::arg("Param"), py::arg("Tangent"), py::arg("Normal"), py::arg("BiNormal"));
cls_GeomFill_TrihedronLaw.def("D1", (Standard_Boolean (GeomFill_TrihedronLaw::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_TrihedronLaw::D1, "compute Triedrhon and derivative Trihedron on curve at parameter <Param> Warning : It used only for C1 or C2 aproximation", py::arg("Param"), py::arg("Tangent"), py::arg("DTangent"), py::arg("Normal"), py::arg("DNormal"), py::arg("BiNormal"), py::arg("DBiNormal"));
cls_GeomFill_TrihedronLaw.def("D2", (Standard_Boolean (GeomFill_TrihedronLaw::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_TrihedronLaw::D2, "compute Trihedron on curve first and seconde derivatives. Warning : It used only for C2 aproximation", py::arg("Param"), py::arg("Tangent"), py::arg("DTangent"), py::arg("D2Tangent"), py::arg("Normal"), py::arg("DNormal"), py::arg("D2Normal"), py::arg("BiNormal"), py::arg("DBiNormal"), py::arg("D2BiNormal"));
cls_GeomFill_TrihedronLaw.def("NbIntervals", (Standard_Integer (GeomFill_TrihedronLaw::*)(const GeomAbs_Shape) const) &GeomFill_TrihedronLaw::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_GeomFill_TrihedronLaw.def("Intervals", (void (GeomFill_TrihedronLaw::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &GeomFill_TrihedronLaw::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_GeomFill_TrihedronLaw.def("SetInterval", (void (GeomFill_TrihedronLaw::*)(const Standard_Real, const Standard_Real)) &GeomFill_TrihedronLaw::SetInterval, "Sets the bounds of the parametric interval on the function This determines the derivatives in these values if the function is not Cn.", py::arg("First"), py::arg("Last"));
cls_GeomFill_TrihedronLaw.def("GetInterval", [](GeomFill_TrihedronLaw &self, Standard_Real & First, Standard_Real & Last){ self.GetInterval(First, Last); return std::tuple<Standard_Real &, Standard_Real &>(First, Last); }, "Gets the bounds of the parametric interval on the function", py::arg("First"), py::arg("Last"));
cls_GeomFill_TrihedronLaw.def("GetAverageLaw", (void (GeomFill_TrihedronLaw::*)(gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_TrihedronLaw::GetAverageLaw, "Get average value of M(t) and V(t) it is usfull to make fast approximation of rational surfaces.", py::arg("ATangent"), py::arg("ANormal"), py::arg("ABiNormal"));
cls_GeomFill_TrihedronLaw.def("IsConstant", (Standard_Boolean (GeomFill_TrihedronLaw::*)() const) &GeomFill_TrihedronLaw::IsConstant, "Say if the law is Constant");
cls_GeomFill_TrihedronLaw.def("IsOnlyBy3dCurve", (Standard_Boolean (GeomFill_TrihedronLaw::*)() const) &GeomFill_TrihedronLaw::IsOnlyBy3dCurve, "Say if the law is defined, only by the 3d Geometry of the setted Curve Return False by Default.");
cls_GeomFill_TrihedronLaw.def_static("get_type_name_", (const char * (*)()) &GeomFill_TrihedronLaw::get_type_name, "None");
cls_GeomFill_TrihedronLaw.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_TrihedronLaw::get_type_descriptor, "None");
cls_GeomFill_TrihedronLaw.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_TrihedronLaw::*)() const) &GeomFill_TrihedronLaw::DynamicType, "None");

// Enums

}