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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HSequenceOfReal.hxx>
#include <ShapeUpgrade_ConvertCurve3dToBezier.hxx>
#include <Standard_Type.hxx>
#include <TColGeom_HSequenceOfCurve.hxx>

void bind_ShapeUpgrade_ConvertCurve3dToBezier(py::module &mod){

py::class_<ShapeUpgrade_ConvertCurve3dToBezier, opencascade::handle<ShapeUpgrade_ConvertCurve3dToBezier>, ShapeUpgrade_SplitCurve3d> cls_ShapeUpgrade_ConvertCurve3dToBezier(mod, "ShapeUpgrade_ConvertCurve3dToBezier", "converts/splits a 3d curve of any type to a list of beziers");

// Constructors
cls_ShapeUpgrade_ConvertCurve3dToBezier.def(py::init<>());

// Fields

// Methods
cls_ShapeUpgrade_ConvertCurve3dToBezier.def("SetLineMode", (void (ShapeUpgrade_ConvertCurve3dToBezier::*)(const Standard_Boolean)) &ShapeUpgrade_ConvertCurve3dToBezier::SetLineMode, "Sets mode for conversion Geom_Line to bezier.", py::arg("mode"));
cls_ShapeUpgrade_ConvertCurve3dToBezier.def("GetLineMode", (Standard_Boolean (ShapeUpgrade_ConvertCurve3dToBezier::*)() const) &ShapeUpgrade_ConvertCurve3dToBezier::GetLineMode, "Returns the Geom_Line conversion mode.");
cls_ShapeUpgrade_ConvertCurve3dToBezier.def("SetCircleMode", (void (ShapeUpgrade_ConvertCurve3dToBezier::*)(const Standard_Boolean)) &ShapeUpgrade_ConvertCurve3dToBezier::SetCircleMode, "Sets mode for conversion Geom_Circle to bezier.", py::arg("mode"));
cls_ShapeUpgrade_ConvertCurve3dToBezier.def("GetCircleMode", (Standard_Boolean (ShapeUpgrade_ConvertCurve3dToBezier::*)() const) &ShapeUpgrade_ConvertCurve3dToBezier::GetCircleMode, "Returns the Geom_Circle conversion mode.");
cls_ShapeUpgrade_ConvertCurve3dToBezier.def("SetConicMode", (void (ShapeUpgrade_ConvertCurve3dToBezier::*)(const Standard_Boolean)) &ShapeUpgrade_ConvertCurve3dToBezier::SetConicMode, "Returns the Geom_Conic conversion mode.", py::arg("mode"));
cls_ShapeUpgrade_ConvertCurve3dToBezier.def("GetConicMode", (Standard_Boolean (ShapeUpgrade_ConvertCurve3dToBezier::*)() const) &ShapeUpgrade_ConvertCurve3dToBezier::GetConicMode, "Performs converting and computes the resulting shape.");
cls_ShapeUpgrade_ConvertCurve3dToBezier.def("Compute", (void (ShapeUpgrade_ConvertCurve3dToBezier::*)()) &ShapeUpgrade_ConvertCurve3dToBezier::Compute, "Converts curve into a list of beziers, and stores the splitting parameters on original curve.");
cls_ShapeUpgrade_ConvertCurve3dToBezier.def("Build", (void (ShapeUpgrade_ConvertCurve3dToBezier::*)(const Standard_Boolean)) &ShapeUpgrade_ConvertCurve3dToBezier::Build, "Splits a list of beziers computed by Compute method according the split values and splitting parameters.", py::arg("Segment"));
cls_ShapeUpgrade_ConvertCurve3dToBezier.def("SplitParams", (opencascade::handle<TColStd_HSequenceOfReal> (ShapeUpgrade_ConvertCurve3dToBezier::*)() const) &ShapeUpgrade_ConvertCurve3dToBezier::SplitParams, "Returns the list of splitted parameters in original curve parametrisation.");
cls_ShapeUpgrade_ConvertCurve3dToBezier.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_ConvertCurve3dToBezier::get_type_name, "None");
cls_ShapeUpgrade_ConvertCurve3dToBezier.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_ConvertCurve3dToBezier::get_type_descriptor, "None");
cls_ShapeUpgrade_ConvertCurve3dToBezier.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_ConvertCurve3dToBezier::*)() const) &ShapeUpgrade_ConvertCurve3dToBezier::DynamicType, "None");

// Enums

}