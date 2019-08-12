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
#include <Geom_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <gp_Trsf.hxx>
#include <GeomAbs_Shape.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <ShapeExtend_ComplexCurve.hxx>
#include <Standard_Type.hxx>

void bind_ShapeExtend_ComplexCurve(py::module &mod){

py::class_<ShapeExtend_ComplexCurve, opencascade::handle<ShapeExtend_ComplexCurve>, Geom_Curve> cls_ShapeExtend_ComplexCurve(mod, "ShapeExtend_ComplexCurve", "Defines a curve which consists of several segments. Implements basic interface to it.");

// Fields

// Methods
cls_ShapeExtend_ComplexCurve.def("NbCurves", (Standard_Integer (ShapeExtend_ComplexCurve::*)() const) &ShapeExtend_ComplexCurve::NbCurves, "Returns number of curves");
cls_ShapeExtend_ComplexCurve.def("Curve", (const opencascade::handle<Geom_Curve> & (ShapeExtend_ComplexCurve::*)(const Standard_Integer) const) &ShapeExtend_ComplexCurve::Curve, "Returns curve given by its index", py::arg("index"));
cls_ShapeExtend_ComplexCurve.def("LocateParameter", [](ShapeExtend_ComplexCurve &self, const Standard_Real U, Standard_Real & UOut){ Standard_Integer rv = self.LocateParameter(U, UOut); return std::tuple<Standard_Integer, Standard_Real &>(rv, UOut); }, "Returns number of the curve for the given parameter U and local paramete r UOut for the found curve", py::arg("U"), py::arg("UOut"));
cls_ShapeExtend_ComplexCurve.def("LocalToGlobal", (Standard_Real (ShapeExtend_ComplexCurve::*)(const Standard_Integer, const Standard_Real) const) &ShapeExtend_ComplexCurve::LocalToGlobal, "Returns global parameter for the whole curve according to the segment and local parameter on it", py::arg("index"), py::arg("Ulocal"));
cls_ShapeExtend_ComplexCurve.def("Transform", (void (ShapeExtend_ComplexCurve::*)(const gp_Trsf &)) &ShapeExtend_ComplexCurve::Transform, "Applies transformation to each curve", py::arg("T"));
cls_ShapeExtend_ComplexCurve.def("ReversedParameter", (Standard_Real (ShapeExtend_ComplexCurve::*)(const Standard_Real) const) &ShapeExtend_ComplexCurve::ReversedParameter, "Returns 1 - U", py::arg("U"));
cls_ShapeExtend_ComplexCurve.def("FirstParameter", (Standard_Real (ShapeExtend_ComplexCurve::*)() const) &ShapeExtend_ComplexCurve::FirstParameter, "Returns 0");
cls_ShapeExtend_ComplexCurve.def("LastParameter", (Standard_Real (ShapeExtend_ComplexCurve::*)() const) &ShapeExtend_ComplexCurve::LastParameter, "Returns 1");
cls_ShapeExtend_ComplexCurve.def("IsClosed", (Standard_Boolean (ShapeExtend_ComplexCurve::*)() const) &ShapeExtend_ComplexCurve::IsClosed, "Returns True if the curve is closed");
cls_ShapeExtend_ComplexCurve.def("IsPeriodic", (Standard_Boolean (ShapeExtend_ComplexCurve::*)() const) &ShapeExtend_ComplexCurve::IsPeriodic, "Returns False");
cls_ShapeExtend_ComplexCurve.def("Continuity", (GeomAbs_Shape (ShapeExtend_ComplexCurve::*)() const) &ShapeExtend_ComplexCurve::Continuity, "Returns GeomAbs_C0");
cls_ShapeExtend_ComplexCurve.def("IsCN", (Standard_Boolean (ShapeExtend_ComplexCurve::*)(const Standard_Integer) const) &ShapeExtend_ComplexCurve::IsCN, "Returns False if N > 0", py::arg("N"));
cls_ShapeExtend_ComplexCurve.def("D0", (void (ShapeExtend_ComplexCurve::*)(const Standard_Real, gp_Pnt &) const) &ShapeExtend_ComplexCurve::D0, "Returns point at parameter U. Finds appropriate curve and local parameter on it.", py::arg("U"), py::arg("P"));
cls_ShapeExtend_ComplexCurve.def("D1", (void (ShapeExtend_ComplexCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const) &ShapeExtend_ComplexCurve::D1, "None", py::arg("U"), py::arg("P"), py::arg("V1"));
cls_ShapeExtend_ComplexCurve.def("D2", (void (ShapeExtend_ComplexCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &ShapeExtend_ComplexCurve::D2, "None", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_ShapeExtend_ComplexCurve.def("D3", (void (ShapeExtend_ComplexCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const) &ShapeExtend_ComplexCurve::D3, "None", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_ShapeExtend_ComplexCurve.def("DN", (gp_Vec (ShapeExtend_ComplexCurve::*)(const Standard_Real, const Standard_Integer) const) &ShapeExtend_ComplexCurve::DN, "None", py::arg("U"), py::arg("N"));
cls_ShapeExtend_ComplexCurve.def("GetScaleFactor", (Standard_Real (ShapeExtend_ComplexCurve::*)(const Standard_Integer) const) &ShapeExtend_ComplexCurve::GetScaleFactor, "Returns scale factor for recomputing of deviatives.", py::arg("ind"));
cls_ShapeExtend_ComplexCurve.def("CheckConnectivity", (Standard_Boolean (ShapeExtend_ComplexCurve::*)(const Standard_Real)) &ShapeExtend_ComplexCurve::CheckConnectivity, "Checks geometrical connectivity of the curves, including closure (sets fields myClosed)", py::arg("Preci"));
cls_ShapeExtend_ComplexCurve.def_static("get_type_name_", (const char * (*)()) &ShapeExtend_ComplexCurve::get_type_name, "None");
cls_ShapeExtend_ComplexCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeExtend_ComplexCurve::get_type_descriptor, "None");
cls_ShapeExtend_ComplexCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeExtend_ComplexCurve::*)() const) &ShapeExtend_ComplexCurve::DynamicType, "None");

// Enums

}