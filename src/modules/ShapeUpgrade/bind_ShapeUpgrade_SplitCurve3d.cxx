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
#include <ShapeUpgrade_SplitCurve.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <TColGeom_HArray1OfCurve.hxx>
#include <ShapeUpgrade_SplitCurve3d.hxx>
#include <Standard_Type.hxx>

void bind_ShapeUpgrade_SplitCurve3d(py::module &mod){

py::class_<ShapeUpgrade_SplitCurve3d, opencascade::handle<ShapeUpgrade_SplitCurve3d>, ShapeUpgrade_SplitCurve> cls_ShapeUpgrade_SplitCurve3d(mod, "ShapeUpgrade_SplitCurve3d", "Splits a 3d curve with a criterion.");

// Constructors
cls_ShapeUpgrade_SplitCurve3d.def(py::init<>());

// Fields

// Methods
cls_ShapeUpgrade_SplitCurve3d.def("Init", (void (ShapeUpgrade_SplitCurve3d::*)(const opencascade::handle<Geom_Curve> &)) &ShapeUpgrade_SplitCurve3d::Init, "Initializes with curve with its first and last parameters.", py::arg("C"));
cls_ShapeUpgrade_SplitCurve3d.def("Init", (void (ShapeUpgrade_SplitCurve3d::*)(const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real)) &ShapeUpgrade_SplitCurve3d::Init, "Initializes with curve with its parameters.", py::arg("C"), py::arg("First"), py::arg("Last"));
cls_ShapeUpgrade_SplitCurve3d.def("Build", (void (ShapeUpgrade_SplitCurve3d::*)(const Standard_Boolean)) &ShapeUpgrade_SplitCurve3d::Build, "If Segment is True, the result is composed with segments of the curve bounded by the SplitValues. If Segment is False, the result is composed with trimmed Curves all based on the same complete curve.", py::arg("Segment"));
cls_ShapeUpgrade_SplitCurve3d.def("GetCurves", (const opencascade::handle<TColGeom_HArray1OfCurve> & (ShapeUpgrade_SplitCurve3d::*)() const) &ShapeUpgrade_SplitCurve3d::GetCurves, "None");
cls_ShapeUpgrade_SplitCurve3d.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_SplitCurve3d::get_type_name, "None");
cls_ShapeUpgrade_SplitCurve3d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_SplitCurve3d::get_type_descriptor, "None");
cls_ShapeUpgrade_SplitCurve3d.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_SplitCurve3d::*)() const) &ShapeUpgrade_SplitCurve3d::DynamicType, "None");

// Enums

}