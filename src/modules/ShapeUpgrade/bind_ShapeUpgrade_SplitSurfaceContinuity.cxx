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
#include <ShapeUpgrade_SplitSurface.hxx>
#include <GeomAbs_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <ShapeUpgrade_SplitSurfaceContinuity.hxx>
#include <Standard_Type.hxx>

void bind_ShapeUpgrade_SplitSurfaceContinuity(py::module &mod){

py::class_<ShapeUpgrade_SplitSurfaceContinuity, opencascade::handle<ShapeUpgrade_SplitSurfaceContinuity>, ShapeUpgrade_SplitSurface> cls_ShapeUpgrade_SplitSurfaceContinuity(mod, "ShapeUpgrade_SplitSurfaceContinuity", "Splits a Surface with a continuity criterion. At the present moment C1 criterion is used only. This tool works with tolerance. If C0 surface can be corrected at a knot with given tolerance then the surface is corrected, otherwise it is spltted at that knot.");

// Constructors
cls_ShapeUpgrade_SplitSurfaceContinuity.def(py::init<>());

// Fields

// Methods
cls_ShapeUpgrade_SplitSurfaceContinuity.def("SetCriterion", (void (ShapeUpgrade_SplitSurfaceContinuity::*)(const GeomAbs_Shape)) &ShapeUpgrade_SplitSurfaceContinuity::SetCriterion, "Sets criterion for splitting.", py::arg("Criterion"));
cls_ShapeUpgrade_SplitSurfaceContinuity.def("SetTolerance", (void (ShapeUpgrade_SplitSurfaceContinuity::*)(const Standard_Real)) &ShapeUpgrade_SplitSurfaceContinuity::SetTolerance, "Sets tolerance.", py::arg("Tol"));
cls_ShapeUpgrade_SplitSurfaceContinuity.def("Compute", (void (ShapeUpgrade_SplitSurfaceContinuity::*)(const Standard_Boolean)) &ShapeUpgrade_SplitSurfaceContinuity::Compute, "None", py::arg("Segment"));
cls_ShapeUpgrade_SplitSurfaceContinuity.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_SplitSurfaceContinuity::get_type_name, "None");
cls_ShapeUpgrade_SplitSurfaceContinuity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_SplitSurfaceContinuity::get_type_descriptor, "None");
cls_ShapeUpgrade_SplitSurfaceContinuity.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_SplitSurfaceContinuity::*)() const) &ShapeUpgrade_SplitSurfaceContinuity::DynamicType, "None");

// Enums

}