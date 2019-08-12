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
#include <TColgp_HArray1OfXY.hxx>
#include <gp_Pnt.hxx>
#include <IGESDimen_WitnessLine.hxx>
#include <Standard_Type.hxx>

void bind_IGESDimen_WitnessLine(py::module &mod){

py::class_<IGESDimen_WitnessLine, opencascade::handle<IGESDimen_WitnessLine>, IGESData_IGESEntity> cls_IGESDimen_WitnessLine(mod, "IGESDimen_WitnessLine", "defines WitnessLine, Type <106> Form <40> in package IGESDimen Contains one or more straight line segments associated with drafting entities of various types");

// Constructors
cls_IGESDimen_WitnessLine.def(py::init<>());

// Fields

// Methods
cls_IGESDimen_WitnessLine.def("Init", (void (IGESDimen_WitnessLine::*)(const Standard_Integer, const Standard_Real, const opencascade::handle<TColgp_HArray1OfXY> &)) &IGESDimen_WitnessLine::Init, "This method is used to set the fields of the class WitnessLine - dataType : Interpretation Flag, always = 1 - aDispl : Common z displacement - dataPoints : Data points", py::arg("dataType"), py::arg("aDisp"), py::arg("dataPoints"));
cls_IGESDimen_WitnessLine.def("Datatype", (Standard_Integer (IGESDimen_WitnessLine::*)() const) &IGESDimen_WitnessLine::Datatype, "returns Interpretation Flag, always = 1");
cls_IGESDimen_WitnessLine.def("NbPoints", (Standard_Integer (IGESDimen_WitnessLine::*)() const) &IGESDimen_WitnessLine::NbPoints, "returns number of Data Points");
cls_IGESDimen_WitnessLine.def("ZDisplacement", (Standard_Real (IGESDimen_WitnessLine::*)() const) &IGESDimen_WitnessLine::ZDisplacement, "returns common Z displacement");
cls_IGESDimen_WitnessLine.def("Point", (gp_Pnt (IGESDimen_WitnessLine::*)(const Standard_Integer) const) &IGESDimen_WitnessLine::Point, "returns Index'th. data point raises exception if Index <= 0 or Index > NbPoints", py::arg("Index"));
cls_IGESDimen_WitnessLine.def("TransformedPoint", (gp_Pnt (IGESDimen_WitnessLine::*)(const Standard_Integer) const) &IGESDimen_WitnessLine::TransformedPoint, "returns data point after Transformation. raises exception if Index <= 0 or Index > NbPoints", py::arg("Index"));
cls_IGESDimen_WitnessLine.def_static("get_type_name_", (const char * (*)()) &IGESDimen_WitnessLine::get_type_name, "None");
cls_IGESDimen_WitnessLine.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_WitnessLine::get_type_descriptor, "None");
cls_IGESDimen_WitnessLine.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_WitnessLine::*)() const) &IGESDimen_WitnessLine::DynamicType, "None");

// Enums

}