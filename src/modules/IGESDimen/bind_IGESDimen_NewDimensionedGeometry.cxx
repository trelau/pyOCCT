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
#include <TColStd_HArray1OfInteger.hxx>
#include <TColgp_HArray1OfXYZ.hxx>
#include <gp_Pnt.hxx>
#include <IGESDimen_NewDimensionedGeometry.hxx>
#include <Standard_Type.hxx>

void bind_IGESDimen_NewDimensionedGeometry(py::module &mod){

py::class_<IGESDimen_NewDimensionedGeometry, opencascade::handle<IGESDimen_NewDimensionedGeometry>, IGESData_IGESEntity> cls_IGESDimen_NewDimensionedGeometry(mod, "IGESDimen_NewDimensionedGeometry", "defines New Dimensioned Geometry, Type <402>, Form <21> in package IGESDimen Links a dimension entity with the geometry entities it is dimensioning, so that later, in the receiving database, the dimension can be automatically recalculated and redrawn should the geometry be changed.");

// Constructors
cls_IGESDimen_NewDimensionedGeometry.def(py::init<>());

// Fields

// Methods
cls_IGESDimen_NewDimensionedGeometry.def("Init", (void (IGESDimen_NewDimensionedGeometry::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const Standard_Integer, const Standard_Real, const opencascade::handle<IGESData_HArray1OfIGESEntity> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColgp_HArray1OfXYZ> &)) &IGESDimen_NewDimensionedGeometry::Init, "This method is used to set the fields of the class NewDimensionedGeometry - nbDimen : Number of Dimensions, default = 1 - aDimen : Dimension Entity - anOrientation : Dimension Orientation Flag - anAngle : Angle Value - allEntities : Geometric Entities - allLocations : Dimension Location Flags - allPoints : Points on the Geometry Entities exception raised if lengths of entities, locations, points are not the same", py::arg("nbDimens"), py::arg("aDimen"), py::arg("anOrientation"), py::arg("anAngle"), py::arg("allEntities"), py::arg("allLocations"), py::arg("allPoints"));
cls_IGESDimen_NewDimensionedGeometry.def("NbDimensions", (Standard_Integer (IGESDimen_NewDimensionedGeometry::*)() const) &IGESDimen_NewDimensionedGeometry::NbDimensions, "returns the number of dimensions");
cls_IGESDimen_NewDimensionedGeometry.def("NbGeometries", (Standard_Integer (IGESDimen_NewDimensionedGeometry::*)() const) &IGESDimen_NewDimensionedGeometry::NbGeometries, "returns the number of associated geometry entities");
cls_IGESDimen_NewDimensionedGeometry.def("DimensionEntity", (opencascade::handle<IGESData_IGESEntity> (IGESDimen_NewDimensionedGeometry::*)() const) &IGESDimen_NewDimensionedGeometry::DimensionEntity, "returns the dimension entity");
cls_IGESDimen_NewDimensionedGeometry.def("DimensionOrientationFlag", (Standard_Integer (IGESDimen_NewDimensionedGeometry::*)() const) &IGESDimen_NewDimensionedGeometry::DimensionOrientationFlag, "returns the dimension orientation flag");
cls_IGESDimen_NewDimensionedGeometry.def("AngleValue", (Standard_Real (IGESDimen_NewDimensionedGeometry::*)() const) &IGESDimen_NewDimensionedGeometry::AngleValue, "returns the angle value");
cls_IGESDimen_NewDimensionedGeometry.def("GeometryEntity", (opencascade::handle<IGESData_IGESEntity> (IGESDimen_NewDimensionedGeometry::*)(const Standard_Integer) const) &IGESDimen_NewDimensionedGeometry::GeometryEntity, "returns the Index'th geometry entity raises exception if Index <= 0 or Index > NbGeometries()", py::arg("Index"));
cls_IGESDimen_NewDimensionedGeometry.def("DimensionLocationFlag", (Standard_Integer (IGESDimen_NewDimensionedGeometry::*)(const Standard_Integer) const) &IGESDimen_NewDimensionedGeometry::DimensionLocationFlag, "returns the Index'th geometry entity's dimension location flag raises exception if Index <= 0 or Index > NbGeometries()", py::arg("Index"));
cls_IGESDimen_NewDimensionedGeometry.def("Point", (gp_Pnt (IGESDimen_NewDimensionedGeometry::*)(const Standard_Integer) const) &IGESDimen_NewDimensionedGeometry::Point, "coordinate of point on Index'th geometry entity raises exception if Index <= 0 or Index > NbGeometries()", py::arg("Index"));
cls_IGESDimen_NewDimensionedGeometry.def("TransformedPoint", (gp_Pnt (IGESDimen_NewDimensionedGeometry::*)(const Standard_Integer) const) &IGESDimen_NewDimensionedGeometry::TransformedPoint, "coordinate of point on Index'th geometry entity after Transformation raises exception if Index <= 0 or Index > NbGeometries()", py::arg("Index"));
cls_IGESDimen_NewDimensionedGeometry.def_static("get_type_name_", (const char * (*)()) &IGESDimen_NewDimensionedGeometry::get_type_name, "None");
cls_IGESDimen_NewDimensionedGeometry.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_NewDimensionedGeometry::get_type_descriptor, "None");
cls_IGESDimen_NewDimensionedGeometry.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_NewDimensionedGeometry::*)() const) &IGESDimen_NewDimensionedGeometry::DynamicType, "None");

// Enums

}