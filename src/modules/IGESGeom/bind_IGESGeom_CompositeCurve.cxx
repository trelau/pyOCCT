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
#include <IGESData_HArray1OfIGESEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESGeom_CompositeCurve.hxx>
#include <Standard_Type.hxx>

void bind_IGESGeom_CompositeCurve(py::module &mod){

py::class_<IGESGeom_CompositeCurve, opencascade::handle<IGESGeom_CompositeCurve>, IGESData_IGESEntity> cls_IGESGeom_CompositeCurve(mod, "IGESGeom_CompositeCurve", "defines IGESCompositeCurve, Type <102> Form <0> in package IGESGeom A composite curve is defined as an ordered list of entities consisting of a point, connect point and parametrised curve entities (excluding the CompositeCurve entity).");

// Constructors
cls_IGESGeom_CompositeCurve.def(py::init<>());

// Fields

// Methods
cls_IGESGeom_CompositeCurve.def("Init", (void (IGESGeom_CompositeCurve::*)(const opencascade::handle<IGESData_HArray1OfIGESEntity> &)) &IGESGeom_CompositeCurve::Init, "This method is used to set the fields of the class CompositeCurve - allEntities : Constituent Entities of the composite curve", py::arg("allEntities"));
cls_IGESGeom_CompositeCurve.def("NbCurves", (Standard_Integer (IGESGeom_CompositeCurve::*)() const) &IGESGeom_CompositeCurve::NbCurves, "returns the number of curves contained in the CompositeCurve");
cls_IGESGeom_CompositeCurve.def("Curve", (opencascade::handle<IGESData_IGESEntity> (IGESGeom_CompositeCurve::*)(const Standard_Integer) const) &IGESGeom_CompositeCurve::Curve, "returns Component of the CompositeCurve (a curve or a point) raises exception if Index <= 0 or Index > NbCurves()", py::arg("Index"));
cls_IGESGeom_CompositeCurve.def_static("get_type_name_", (const char * (*)()) &IGESGeom_CompositeCurve::get_type_name, "None");
cls_IGESGeom_CompositeCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGeom_CompositeCurve::get_type_descriptor, "None");
cls_IGESGeom_CompositeCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGeom_CompositeCurve::*)() const) &IGESGeom_CompositeCurve::DynamicType, "None");

// Enums

}