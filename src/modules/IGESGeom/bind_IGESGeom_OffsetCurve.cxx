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
#include <IGESData_IGESEntity.hxx>
#include <Standard_Handle.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_XYZ.hxx>
#include <gp_Vec.hxx>
#include <IGESGeom_OffsetCurve.hxx>
#include <Standard_Type.hxx>

void bind_IGESGeom_OffsetCurve(py::module &mod){

py::class_<IGESGeom_OffsetCurve, opencascade::handle<IGESGeom_OffsetCurve>, IGESData_IGESEntity> cls_IGESGeom_OffsetCurve(mod, "IGESGeom_OffsetCurve", "defines IGESOffsetCurve, Type <130> Form <0> in package IGESGeom An OffsetCurve entity contains the data necessary to determine the offset of a given curve C. This entity points to the base curve to be offset and contains offset distance and other pertinent information.");

// Constructors
cls_IGESGeom_OffsetCurve.def(py::init<>());

// Fields

// Methods
cls_IGESGeom_OffsetCurve.def("Init", (void (IGESGeom_OffsetCurve::*)(const opencascade::handle<IGESData_IGESEntity> &, const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const gp_XYZ &, const Standard_Real, const Standard_Real)) &IGESGeom_OffsetCurve::Init, "This method is used to set the fields of the class OffsetCurve - aBaseCurve : The curve entity to be offset - anOffsetType : Offset distance flag 1 = Single value, uniform distance 2 = Varying linearly 3 = As a specified function - aFunction : Curve entity, one coordinate of which describes offset as a function of its parameter (0 unless OffsetType = 3) - aFunctionCoord : Particular coordinate of curve describing offset as function of its parameters. (used if OffsetType = 3) - aTaperedOffsetType : Tapered offset type flag 1 = Function of arc length 2 = Function of parameter (Only used if OffsetType = 2 or 3) - offDistance1 : First offset distance (Only used if OffsetType = 1 or 2) - arcLength1 : Arc length or parameter value of first offset distance (Only used if OffsetType = 2) - offDistance2 : Second offset distance - arcLength2 : Arc length or parameter value of second offset distance (Only used if OffsetType = 2) - aNormalVec : Unit vector normal to plane containing curve to be offset - anOffsetParam : Start parameter value of offset curve - anotherOffsetParam : End parameter value of offset curve", py::arg("aBaseCurve"), py::arg("anOffsetType"), py::arg("aFunction"), py::arg("aFunctionCoord"), py::arg("aTaperedOffsetType"), py::arg("offDistance1"), py::arg("arcLength1"), py::arg("offDistance2"), py::arg("arcLength2"), py::arg("aNormalVec"), py::arg("anOffsetParam"), py::arg("anotherOffsetParam"));
cls_IGESGeom_OffsetCurve.def("BaseCurve", (opencascade::handle<IGESData_IGESEntity> (IGESGeom_OffsetCurve::*)() const) &IGESGeom_OffsetCurve::BaseCurve, "returns the curve to be offset");
cls_IGESGeom_OffsetCurve.def("OffsetType", (Standard_Integer (IGESGeom_OffsetCurve::*)() const) &IGESGeom_OffsetCurve::OffsetType, "returns the offset distance flag 1 = Single value offset (uniform distance) 2 = Offset distance varying linearly 3 = Offset distance specified as a function");
cls_IGESGeom_OffsetCurve.def("Function", (opencascade::handle<IGESData_IGESEntity> (IGESGeom_OffsetCurve::*)() const) &IGESGeom_OffsetCurve::Function, "returns the function defining the offset if at all the offset is described as a function or Null Handle.");
cls_IGESGeom_OffsetCurve.def("HasFunction", (Standard_Boolean (IGESGeom_OffsetCurve::*)() const) &IGESGeom_OffsetCurve::HasFunction, "returns True if function defining the offset is present.");
cls_IGESGeom_OffsetCurve.def("FunctionParameter", (Standard_Integer (IGESGeom_OffsetCurve::*)() const) &IGESGeom_OffsetCurve::FunctionParameter, "returns particular coordinate of the curve which describes offset as a function of its parameters. (only used if OffsetType() = 3)");
cls_IGESGeom_OffsetCurve.def("TaperedOffsetType", (Standard_Integer (IGESGeom_OffsetCurve::*)() const) &IGESGeom_OffsetCurve::TaperedOffsetType, "returns tapered offset type flag (only used if OffsetType() = 2 or 3) 1 = Function of arc length 2 = Function of parameter");
cls_IGESGeom_OffsetCurve.def("FirstOffsetDistance", (Standard_Real (IGESGeom_OffsetCurve::*)() const) &IGESGeom_OffsetCurve::FirstOffsetDistance, "returns first offset distance (only used if OffsetType() = 1 or 2)");
cls_IGESGeom_OffsetCurve.def("ArcLength1", (Standard_Real (IGESGeom_OffsetCurve::*)() const) &IGESGeom_OffsetCurve::ArcLength1, "returns arc length or parameter value (depending on value of offset distance flag) of first offset distance (only used if OffsetType() = 2)");
cls_IGESGeom_OffsetCurve.def("SecondOffsetDistance", (Standard_Real (IGESGeom_OffsetCurve::*)() const) &IGESGeom_OffsetCurve::SecondOffsetDistance, "returns the second offset distance");
cls_IGESGeom_OffsetCurve.def("ArcLength2", (Standard_Real (IGESGeom_OffsetCurve::*)() const) &IGESGeom_OffsetCurve::ArcLength2, "returns arc length or parameter value (depending on value of offset distance flag) of second offset distance (only used if OffsetType() = 2)");
cls_IGESGeom_OffsetCurve.def("NormalVector", (gp_Vec (IGESGeom_OffsetCurve::*)() const) &IGESGeom_OffsetCurve::NormalVector, "returns unit vector normal to plane containing curve to be offset");
cls_IGESGeom_OffsetCurve.def("TransformedNormalVector", (gp_Vec (IGESGeom_OffsetCurve::*)() const) &IGESGeom_OffsetCurve::TransformedNormalVector, "returns unit vector normal to plane containing curve to be offset after applying Transf. Matrix");
cls_IGESGeom_OffsetCurve.def("Parameters", [](IGESGeom_OffsetCurve &self, Standard_Real & StartParam, Standard_Real & EndParam){ self.Parameters(StartParam, EndParam); return std::tuple<Standard_Real &, Standard_Real &>(StartParam, EndParam); }, "None", py::arg("StartParam"), py::arg("EndParam"));
cls_IGESGeom_OffsetCurve.def("StartParameter", (Standard_Real (IGESGeom_OffsetCurve::*)() const) &IGESGeom_OffsetCurve::StartParameter, "returns Start Parameter value of the offset curve");
cls_IGESGeom_OffsetCurve.def("EndParameter", (Standard_Real (IGESGeom_OffsetCurve::*)() const) &IGESGeom_OffsetCurve::EndParameter, "returns End Parameter value of the offset curve");
cls_IGESGeom_OffsetCurve.def_static("get_type_name_", (const char * (*)()) &IGESGeom_OffsetCurve::get_type_name, "None");
cls_IGESGeom_OffsetCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGeom_OffsetCurve::get_type_descriptor, "None");
cls_IGESGeom_OffsetCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGeom_OffsetCurve::*)() const) &IGESGeom_OffsetCurve::DynamicType, "None");

// Enums

}