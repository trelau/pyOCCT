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
#include <TColStd_HArray1OfInteger.hxx>
#include <gp_Pnt.hxx>
#include <IGESDraw_RectArraySubfigure.hxx>
#include <Standard_Type.hxx>

void bind_IGESDraw_RectArraySubfigure(py::module &mod){

py::class_<IGESDraw_RectArraySubfigure, opencascade::handle<IGESDraw_RectArraySubfigure>, IGESData_IGESEntity> cls_IGESDraw_RectArraySubfigure(mod, "IGESDraw_RectArraySubfigure", "Defines IGES Rectangular Array Subfigure Instance Entity, Type <412> Form Number <0> in package IGESDraw Used to produce copies of object called the base entity, arranging them in equally spaced rows and columns");

// Constructors
cls_IGESDraw_RectArraySubfigure.def(py::init<>());

// Fields

// Methods
cls_IGESDraw_RectArraySubfigure.def("Init", (void (IGESDraw_RectArraySubfigure::*)(const opencascade::handle<IGESData_IGESEntity> &, const Standard_Real, const gp_XYZ &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const opencascade::handle<TColStd_HArray1OfInteger> &)) &IGESDraw_RectArraySubfigure::Init, "This method is used to set the fields of the class RectArraySubfigure - aBase : a base entity which is replicated - aScale : Scale Factor - aCorner : lower left hand corner for the entire array - nbCols : Number of columns of the array - nbRows : Number of rows of the array - hDisp : Column separations - vtDisp : Row separation - rotationAngle : Rotation angle specified in radians - allDont : DO-DON'T flag to control which portion to display - allNumPos : List of positions to be or not to be displayed", py::arg("aBase"), py::arg("aScale"), py::arg("aCorner"), py::arg("nbCols"), py::arg("nbRows"), py::arg("hDisp"), py::arg("vtDisp"), py::arg("rotationAngle"), py::arg("doDont"), py::arg("allNumPos"));
cls_IGESDraw_RectArraySubfigure.def("BaseEntity", (opencascade::handle<IGESData_IGESEntity> (IGESDraw_RectArraySubfigure::*)() const) &IGESDraw_RectArraySubfigure::BaseEntity, "returns the base entity, copies of which are produced");
cls_IGESDraw_RectArraySubfigure.def("ScaleFactor", (Standard_Real (IGESDraw_RectArraySubfigure::*)() const) &IGESDraw_RectArraySubfigure::ScaleFactor, "returns the scale factor");
cls_IGESDraw_RectArraySubfigure.def("LowerLeftCorner", (gp_Pnt (IGESDraw_RectArraySubfigure::*)() const) &IGESDraw_RectArraySubfigure::LowerLeftCorner, "returns coordinates of lower left hand corner for the entire array");
cls_IGESDraw_RectArraySubfigure.def("TransformedLowerLeftCorner", (gp_Pnt (IGESDraw_RectArraySubfigure::*)() const) &IGESDraw_RectArraySubfigure::TransformedLowerLeftCorner, "returns Transformed coordinates of lower left corner for the array");
cls_IGESDraw_RectArraySubfigure.def("NbColumns", (Standard_Integer (IGESDraw_RectArraySubfigure::*)() const) &IGESDraw_RectArraySubfigure::NbColumns, "returns number of columns in the array");
cls_IGESDraw_RectArraySubfigure.def("NbRows", (Standard_Integer (IGESDraw_RectArraySubfigure::*)() const) &IGESDraw_RectArraySubfigure::NbRows, "returns number of rows in the array");
cls_IGESDraw_RectArraySubfigure.def("ColumnSeparation", (Standard_Real (IGESDraw_RectArraySubfigure::*)() const) &IGESDraw_RectArraySubfigure::ColumnSeparation, "returns horizontal distance between columns");
cls_IGESDraw_RectArraySubfigure.def("RowSeparation", (Standard_Real (IGESDraw_RectArraySubfigure::*)() const) &IGESDraw_RectArraySubfigure::RowSeparation, "returns vertical distance between rows");
cls_IGESDraw_RectArraySubfigure.def("RotationAngle", (Standard_Real (IGESDraw_RectArraySubfigure::*)() const) &IGESDraw_RectArraySubfigure::RotationAngle, "returns rotation angle in radians");
cls_IGESDraw_RectArraySubfigure.def("DisplayFlag", (Standard_Boolean (IGESDraw_RectArraySubfigure::*)() const) &IGESDraw_RectArraySubfigure::DisplayFlag, "returns True if (ListCount = 0) i.e., all elements to be displayed");
cls_IGESDraw_RectArraySubfigure.def("ListCount", (Standard_Integer (IGESDraw_RectArraySubfigure::*)() const) &IGESDraw_RectArraySubfigure::ListCount, "returns 0 if all replicated entities to be displayed");
cls_IGESDraw_RectArraySubfigure.def("DoDontFlag", (Standard_Boolean (IGESDraw_RectArraySubfigure::*)() const) &IGESDraw_RectArraySubfigure::DoDontFlag, "returns 0 if half or fewer of the elements of the array are defined 1 if half or more of the elements are defined");
cls_IGESDraw_RectArraySubfigure.def("PositionNum", (Standard_Boolean (IGESDraw_RectArraySubfigure::*)(const Standard_Integer) const) &IGESDraw_RectArraySubfigure::PositionNum, "returns whether Index is to be processed (DO) or not to be processed(DON'T) if (ListCount = 0) return theDoDontFlag", py::arg("Index"));
cls_IGESDraw_RectArraySubfigure.def("ListPosition", (Standard_Integer (IGESDraw_RectArraySubfigure::*)(const Standard_Integer) const) &IGESDraw_RectArraySubfigure::ListPosition, "returns the Index'th value position raises exception if Index <= 0 or Index > ListCount()", py::arg("Index"));
cls_IGESDraw_RectArraySubfigure.def_static("get_type_name_", (const char * (*)()) &IGESDraw_RectArraySubfigure::get_type_name, "None");
cls_IGESDraw_RectArraySubfigure.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDraw_RectArraySubfigure::get_type_descriptor, "None");
cls_IGESDraw_RectArraySubfigure.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDraw_RectArraySubfigure::*)() const) &IGESDraw_RectArraySubfigure::DynamicType, "None");

// Enums

}