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
#include <ShapeUpgrade_SplitCurve3d.hxx>
#include <GeomAbs_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <ShapeUpgrade_SplitCurve3dContinuity.hxx>
#include <Standard_Type.hxx>

void bind_ShapeUpgrade_SplitCurve3dContinuity(py::module &mod){

py::class_<ShapeUpgrade_SplitCurve3dContinuity, opencascade::handle<ShapeUpgrade_SplitCurve3dContinuity>, ShapeUpgrade_SplitCurve3d> cls_ShapeUpgrade_SplitCurve3dContinuity(mod, "ShapeUpgrade_SplitCurve3dContinuity", "Corrects/splits a 2d curve with a continuity criterion. Tolerance is used to correct the curve at a knot that respects geometrically the criterion, in order to reduce the multiplicity of the knot.");

// Constructors
cls_ShapeUpgrade_SplitCurve3dContinuity.def(py::init<>());

// Fields

// Methods
cls_ShapeUpgrade_SplitCurve3dContinuity.def("SetCriterion", (void (ShapeUpgrade_SplitCurve3dContinuity::*)(const GeomAbs_Shape)) &ShapeUpgrade_SplitCurve3dContinuity::SetCriterion, "Sets criterion for splitting.", py::arg("Criterion"));
cls_ShapeUpgrade_SplitCurve3dContinuity.def("SetTolerance", (void (ShapeUpgrade_SplitCurve3dContinuity::*)(const Standard_Real)) &ShapeUpgrade_SplitCurve3dContinuity::SetTolerance, "Sets tolerance.", py::arg("Tol"));
cls_ShapeUpgrade_SplitCurve3dContinuity.def("Compute", (void (ShapeUpgrade_SplitCurve3dContinuity::*)()) &ShapeUpgrade_SplitCurve3dContinuity::Compute, "Calculates points for correction/splitting of the curve");
cls_ShapeUpgrade_SplitCurve3dContinuity.def("GetCurve", (const opencascade::handle<Geom_Curve> & (ShapeUpgrade_SplitCurve3dContinuity::*)() const) &ShapeUpgrade_SplitCurve3dContinuity::GetCurve, "None");
cls_ShapeUpgrade_SplitCurve3dContinuity.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_SplitCurve3dContinuity::get_type_name, "None");
cls_ShapeUpgrade_SplitCurve3dContinuity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_SplitCurve3dContinuity::get_type_descriptor, "None");
cls_ShapeUpgrade_SplitCurve3dContinuity.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_SplitCurve3dContinuity::*)() const) &ShapeUpgrade_SplitCurve3dContinuity::DynamicType, "None");

// Enums

}