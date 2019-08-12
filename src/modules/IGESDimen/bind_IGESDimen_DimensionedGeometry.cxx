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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_HArray1OfIGESEntity.hxx>
#include <IGESDimen_DimensionedGeometry.hxx>
#include <Standard_Type.hxx>

void bind_IGESDimen_DimensionedGeometry(py::module &mod){

py::class_<IGESDimen_DimensionedGeometry, opencascade::handle<IGESDimen_DimensionedGeometry>, IGESData_IGESEntity> cls_IGESDimen_DimensionedGeometry(mod, "IGESDimen_DimensionedGeometry", "Defines IGES Dimensioned Geometry, Type <402> Form <13>, in package IGESDimen This entity has been replaced by the new form of Dimensioned Geometry Associativity Entity (Type 402, Form 21) and should no longer be used by preprocessors.");

// Constructors
cls_IGESDimen_DimensionedGeometry.def(py::init<>());

// Fields

// Methods
cls_IGESDimen_DimensionedGeometry.def("Init", (void (IGESDimen_DimensionedGeometry::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_HArray1OfIGESEntity> &)) &IGESDimen_DimensionedGeometry::Init, "None", py::arg("nbDims"), py::arg("aDimension"), py::arg("entities"));
cls_IGESDimen_DimensionedGeometry.def("NbDimensions", (Standard_Integer (IGESDimen_DimensionedGeometry::*)() const) &IGESDimen_DimensionedGeometry::NbDimensions, "returns the number of dimensions");
cls_IGESDimen_DimensionedGeometry.def("NbGeometryEntities", (Standard_Integer (IGESDimen_DimensionedGeometry::*)() const) &IGESDimen_DimensionedGeometry::NbGeometryEntities, "returns the number of associated geometry entities");
cls_IGESDimen_DimensionedGeometry.def("DimensionEntity", (opencascade::handle<IGESData_IGESEntity> (IGESDimen_DimensionedGeometry::*)() const) &IGESDimen_DimensionedGeometry::DimensionEntity, "returns the Dimension entity");
cls_IGESDimen_DimensionedGeometry.def("GeometryEntity", (opencascade::handle<IGESData_IGESEntity> (IGESDimen_DimensionedGeometry::*)(const Standard_Integer) const) &IGESDimen_DimensionedGeometry::GeometryEntity, "returns the num'th Geometry entity raises exception if Index <= 0 or Index > NbGeometryEntities()", py::arg("Index"));
cls_IGESDimen_DimensionedGeometry.def_static("get_type_name_", (const char * (*)()) &IGESDimen_DimensionedGeometry::get_type_name, "None");
cls_IGESDimen_DimensionedGeometry.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_DimensionedGeometry::get_type_descriptor, "None");
cls_IGESDimen_DimensionedGeometry.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_DimensionedGeometry::*)() const) &IGESDimen_DimensionedGeometry::DynamicType, "None");

// Enums

}