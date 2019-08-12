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
#include <AIS_Relation.hxx>
#include <AIS_KindOfDimension.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <AIS_EllipseRadiusDimension.hxx>
#include <Standard_Type.hxx>
#include <TopoDS_Shape.hxx>
#include <TCollection_ExtendedString.hxx>
#include <gp_Elips.hxx>
#include <Geom_OffsetCurve.hxx>
#include <AIS_KindOfSurface.hxx>
#include <Geom_Surface.hxx>

void bind_AIS_EllipseRadiusDimension(py::module &mod){

py::class_<AIS_EllipseRadiusDimension, opencascade::handle<AIS_EllipseRadiusDimension>, AIS_Relation> cls_AIS_EllipseRadiusDimension(mod, "AIS_EllipseRadiusDimension", "Computes geometry ( basis curve and plane of dimension) for input shape aShape from TopoDS Root class for MinRadiusDimension and MaxRadiusDimension");

// Fields

// Methods
cls_AIS_EllipseRadiusDimension.def("KindOfDimension", (AIS_KindOfDimension (AIS_EllipseRadiusDimension::*)() const) &AIS_EllipseRadiusDimension::KindOfDimension, "None");
cls_AIS_EllipseRadiusDimension.def("IsMovable", (Standard_Boolean (AIS_EllipseRadiusDimension::*)() const) &AIS_EllipseRadiusDimension::IsMovable, "None");
cls_AIS_EllipseRadiusDimension.def("ComputeGeometry", (void (AIS_EllipseRadiusDimension::*)()) &AIS_EllipseRadiusDimension::ComputeGeometry, "None");
cls_AIS_EllipseRadiusDimension.def_static("get_type_name_", (const char * (*)()) &AIS_EllipseRadiusDimension::get_type_name, "None");
cls_AIS_EllipseRadiusDimension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_EllipseRadiusDimension::get_type_descriptor, "None");
cls_AIS_EllipseRadiusDimension.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_EllipseRadiusDimension::*)() const) &AIS_EllipseRadiusDimension::DynamicType, "None");

// Enums

}