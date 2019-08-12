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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HSequenceOfReal.hxx>
#include <ShapeUpgrade_ConvertCurve2dToBezier.hxx>
#include <Standard_Type.hxx>
#include <TColGeom2d_HSequenceOfCurve.hxx>

void bind_ShapeUpgrade_ConvertCurve2dToBezier(py::module &mod){

py::class_<ShapeUpgrade_ConvertCurve2dToBezier, opencascade::handle<ShapeUpgrade_ConvertCurve2dToBezier>, ShapeUpgrade_SplitCurve2d> cls_ShapeUpgrade_ConvertCurve2dToBezier(mod, "ShapeUpgrade_ConvertCurve2dToBezier", "converts/splits a 2d curve to a list of beziers");

// Constructors
cls_ShapeUpgrade_ConvertCurve2dToBezier.def(py::init<>());

// Fields

// Methods
cls_ShapeUpgrade_ConvertCurve2dToBezier.def("Compute", (void (ShapeUpgrade_ConvertCurve2dToBezier::*)()) &ShapeUpgrade_ConvertCurve2dToBezier::Compute, "Converts curve into a list of beziers, and stores the splitting parameters on original curve.");
cls_ShapeUpgrade_ConvertCurve2dToBezier.def("Build", (void (ShapeUpgrade_ConvertCurve2dToBezier::*)(const Standard_Boolean)) &ShapeUpgrade_ConvertCurve2dToBezier::Build, "Splits a list of beziers computed by Compute method according the split values and splitting parameters.", py::arg("Segment"));
cls_ShapeUpgrade_ConvertCurve2dToBezier.def("SplitParams", (opencascade::handle<TColStd_HSequenceOfReal> (ShapeUpgrade_ConvertCurve2dToBezier::*)() const) &ShapeUpgrade_ConvertCurve2dToBezier::SplitParams, "Returns the list of splitted parameters in original curve parametrisation.");
cls_ShapeUpgrade_ConvertCurve2dToBezier.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_ConvertCurve2dToBezier::get_type_name, "None");
cls_ShapeUpgrade_ConvertCurve2dToBezier.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_ConvertCurve2dToBezier::get_type_descriptor, "None");
cls_ShapeUpgrade_ConvertCurve2dToBezier.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_ConvertCurve2dToBezier::*)() const) &ShapeUpgrade_ConvertCurve2dToBezier::DynamicType, "None");

// Enums

}