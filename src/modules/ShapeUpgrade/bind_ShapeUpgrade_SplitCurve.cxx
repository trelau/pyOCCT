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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HSequenceOfReal.hxx>
#include <ShapeExtend_Status.hxx>
#include <ShapeUpgrade_SplitCurve.hxx>
#include <Standard_Type.hxx>

void bind_ShapeUpgrade_SplitCurve(py::module &mod){

py::class_<ShapeUpgrade_SplitCurve, opencascade::handle<ShapeUpgrade_SplitCurve>, Standard_Transient> cls_ShapeUpgrade_SplitCurve(mod, "ShapeUpgrade_SplitCurve", "Splits a curve with a criterion.");

// Constructors
cls_ShapeUpgrade_SplitCurve.def(py::init<>());

// Fields

// Methods
cls_ShapeUpgrade_SplitCurve.def("Init", (void (ShapeUpgrade_SplitCurve::*)(const Standard_Real, const Standard_Real)) &ShapeUpgrade_SplitCurve::Init, "Initializes with curve first and last parameters.", py::arg("First"), py::arg("Last"));
cls_ShapeUpgrade_SplitCurve.def("SetSplitValues", (void (ShapeUpgrade_SplitCurve::*)(const opencascade::handle<TColStd_HSequenceOfReal> &)) &ShapeUpgrade_SplitCurve::SetSplitValues, "Sets the parameters where splitting has to be done.", py::arg("SplitValues"));
cls_ShapeUpgrade_SplitCurve.def("Build", (void (ShapeUpgrade_SplitCurve::*)(const Standard_Boolean)) &ShapeUpgrade_SplitCurve::Build, "If Segment is True, the result is composed with segments of the curve bounded by the SplitValues. If Segment is False, the result is composed with trimmed Curves all based on the same complete curve.", py::arg("Segment"));
cls_ShapeUpgrade_SplitCurve.def("SplitValues", (const opencascade::handle<TColStd_HSequenceOfReal> & (ShapeUpgrade_SplitCurve::*)() const) &ShapeUpgrade_SplitCurve::SplitValues, "returns all the splitting values including the First and Last parameters of the input curve Merges input split values and new ones into myGlobalKnots");
cls_ShapeUpgrade_SplitCurve.def("Compute", (void (ShapeUpgrade_SplitCurve::*)()) &ShapeUpgrade_SplitCurve::Compute, "Calculates points for correction/splitting of the curve");
cls_ShapeUpgrade_SplitCurve.def("Perform", [](ShapeUpgrade_SplitCurve &self) -> void { return self.Perform(); });
cls_ShapeUpgrade_SplitCurve.def("Perform", (void (ShapeUpgrade_SplitCurve::*)(const Standard_Boolean)) &ShapeUpgrade_SplitCurve::Perform, "Performs correction/splitting of the curve. First defines splitting values by method Compute(), then calls method Build().", py::arg("Segment"));
cls_ShapeUpgrade_SplitCurve.def("Status", (Standard_Boolean (ShapeUpgrade_SplitCurve::*)(const ShapeExtend_Status) const) &ShapeUpgrade_SplitCurve::Status, "Returns the status OK - no splitting is needed DONE1 - splitting required and gives more than one segment DONE2 - splitting is required, but gives only one segment (initial) DONE3 - geometric form of the curve or parametrisation is modified", py::arg("status"));
cls_ShapeUpgrade_SplitCurve.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_SplitCurve::get_type_name, "None");
cls_ShapeUpgrade_SplitCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_SplitCurve::get_type_descriptor, "None");
cls_ShapeUpgrade_SplitCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_SplitCurve::*)() const) &ShapeUpgrade_SplitCurve::DynamicType, "None");

// Enums

}