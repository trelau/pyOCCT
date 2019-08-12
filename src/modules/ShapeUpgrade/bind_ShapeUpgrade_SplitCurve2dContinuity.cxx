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
#include <ShapeUpgrade_SplitCurve2d.hxx>
#include <GeomAbs_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <ShapeUpgrade_SplitCurve2dContinuity.hxx>
#include <Standard_Type.hxx>

void bind_ShapeUpgrade_SplitCurve2dContinuity(py::module &mod){

py::class_<ShapeUpgrade_SplitCurve2dContinuity, opencascade::handle<ShapeUpgrade_SplitCurve2dContinuity>, ShapeUpgrade_SplitCurve2d> cls_ShapeUpgrade_SplitCurve2dContinuity(mod, "ShapeUpgrade_SplitCurve2dContinuity", "Corrects/splits a 2d curve with a continuity criterion. Tolerance is used to correct the curve at a knot that respects geometrically the criterion, in order to reduce the multiplicity of the knot.");

// Constructors
cls_ShapeUpgrade_SplitCurve2dContinuity.def(py::init<>());

// Fields

// Methods
cls_ShapeUpgrade_SplitCurve2dContinuity.def("SetCriterion", (void (ShapeUpgrade_SplitCurve2dContinuity::*)(const GeomAbs_Shape)) &ShapeUpgrade_SplitCurve2dContinuity::SetCriterion, "Sets criterion for splitting.", py::arg("Criterion"));
cls_ShapeUpgrade_SplitCurve2dContinuity.def("SetTolerance", (void (ShapeUpgrade_SplitCurve2dContinuity::*)(const Standard_Real)) &ShapeUpgrade_SplitCurve2dContinuity::SetTolerance, "Sets tolerance.", py::arg("Tol"));
cls_ShapeUpgrade_SplitCurve2dContinuity.def("Compute", (void (ShapeUpgrade_SplitCurve2dContinuity::*)()) &ShapeUpgrade_SplitCurve2dContinuity::Compute, "Calculates points for correction/splitting of the curve");
cls_ShapeUpgrade_SplitCurve2dContinuity.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_SplitCurve2dContinuity::get_type_name, "None");
cls_ShapeUpgrade_SplitCurve2dContinuity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_SplitCurve2dContinuity::get_type_descriptor, "None");
cls_ShapeUpgrade_SplitCurve2dContinuity.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_SplitCurve2dContinuity::*)() const) &ShapeUpgrade_SplitCurve2dContinuity::DynamicType, "None");

// Enums

}