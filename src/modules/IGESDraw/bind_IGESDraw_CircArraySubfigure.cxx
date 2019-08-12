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
#include <IGESDraw_CircArraySubfigure.hxx>
#include <Standard_Type.hxx>

void bind_IGESDraw_CircArraySubfigure(py::module &mod){

py::class_<IGESDraw_CircArraySubfigure, opencascade::handle<IGESDraw_CircArraySubfigure>, IGESData_IGESEntity> cls_IGESDraw_CircArraySubfigure(mod, "IGESDraw_CircArraySubfigure", "Defines IGES Circular Array Subfigure Instance Entity, Type <414> Form Number <0> in package IGESDraw");

// Constructors
cls_IGESDraw_CircArraySubfigure.def(py::init<>());

// Fields

// Methods
cls_IGESDraw_CircArraySubfigure.def("Init", (void (IGESDraw_CircArraySubfigure::*)(const opencascade::handle<IGESData_IGESEntity> &, const Standard_Integer, const gp_XYZ &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const opencascade::handle<TColStd_HArray1OfInteger> &)) &IGESDraw_CircArraySubfigure::Init, "This method is used to set the fields of the class CircArraySubfigure - aBase : Base entity - aNumLocs : Total number of possible instance locations - aCenter : Coordinates of Center of imaginary circle - aRadius : Radius of imaginary circle - aStAngle : Start angle in radians - aDelAngle : Delta angle in radians - aFlag : DO-DON'T flag to control which portion to display - allNumPos : All position to be or not to be processed", py::arg("aBase"), py::arg("aNumLocs"), py::arg("aCenter"), py::arg("aRadius"), py::arg("aStAngle"), py::arg("aDelAngle"), py::arg("aFlag"), py::arg("allNumPos"));
cls_IGESDraw_CircArraySubfigure.def("BaseEntity", (opencascade::handle<IGESData_IGESEntity> (IGESDraw_CircArraySubfigure::*)() const) &IGESDraw_CircArraySubfigure::BaseEntity, "returns the base entity, copies of which are produced");
cls_IGESDraw_CircArraySubfigure.def("NbLocations", (Standard_Integer (IGESDraw_CircArraySubfigure::*)() const) &IGESDraw_CircArraySubfigure::NbLocations, "returns total number of possible instance locations");
cls_IGESDraw_CircArraySubfigure.def("CenterPoint", (gp_Pnt (IGESDraw_CircArraySubfigure::*)() const) &IGESDraw_CircArraySubfigure::CenterPoint, "returns the center of the imaginary circle");
cls_IGESDraw_CircArraySubfigure.def("TransformedCenterPoint", (gp_Pnt (IGESDraw_CircArraySubfigure::*)() const) &IGESDraw_CircArraySubfigure::TransformedCenterPoint, "returns the Transformed center of the imaginary circle");
cls_IGESDraw_CircArraySubfigure.def("CircleRadius", (Standard_Real (IGESDraw_CircArraySubfigure::*)() const) &IGESDraw_CircArraySubfigure::CircleRadius, "returns the radius of the imaginary circle");
cls_IGESDraw_CircArraySubfigure.def("StartAngle", (Standard_Real (IGESDraw_CircArraySubfigure::*)() const) &IGESDraw_CircArraySubfigure::StartAngle, "returns the start angle in radians");
cls_IGESDraw_CircArraySubfigure.def("DeltaAngle", (Standard_Real (IGESDraw_CircArraySubfigure::*)() const) &IGESDraw_CircArraySubfigure::DeltaAngle, "returns the delta angle in radians");
cls_IGESDraw_CircArraySubfigure.def("ListCount", (Standard_Integer (IGESDraw_CircArraySubfigure::*)() const) &IGESDraw_CircArraySubfigure::ListCount, "returns 0 if all elements to be displayed");
cls_IGESDraw_CircArraySubfigure.def("DisplayFlag", (Standard_Boolean (IGESDraw_CircArraySubfigure::*)() const) &IGESDraw_CircArraySubfigure::DisplayFlag, "returns True if (ListCount = 0) all elements are to be displayed");
cls_IGESDraw_CircArraySubfigure.def("DoDontFlag", (Standard_Boolean (IGESDraw_CircArraySubfigure::*)() const) &IGESDraw_CircArraySubfigure::DoDontFlag, "returns 0 if half or fewer of the elements of the array are defined 1 if half or more of the elements are defined");
cls_IGESDraw_CircArraySubfigure.def("PositionNum", (Standard_Boolean (IGESDraw_CircArraySubfigure::*)(const Standard_Integer) const) &IGESDraw_CircArraySubfigure::PositionNum, "returns whether Index is to be processed (DO) or not to be processed(DON'T) if (ListCount = 0) return theDoDontFlag raises exception if Index <= 0 or Index > ListCount().", py::arg("Index"));
cls_IGESDraw_CircArraySubfigure.def("ListPosition", (Standard_Integer (IGESDraw_CircArraySubfigure::*)(const Standard_Integer) const) &IGESDraw_CircArraySubfigure::ListPosition, "returns the Index'th value position raises exception if Index <= 0 or Index > ListCount().", py::arg("Index"));
cls_IGESDraw_CircArraySubfigure.def_static("get_type_name_", (const char * (*)()) &IGESDraw_CircArraySubfigure::get_type_name, "None");
cls_IGESDraw_CircArraySubfigure.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDraw_CircArraySubfigure::get_type_descriptor, "None");
cls_IGESDraw_CircArraySubfigure.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDraw_CircArraySubfigure::*)() const) &IGESDraw_CircArraySubfigure::DynamicType, "None");

// Enums

}