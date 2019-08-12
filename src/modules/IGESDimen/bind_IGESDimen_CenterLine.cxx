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
#include <IGESDimen_CenterLine.hxx>
#include <Standard_Type.hxx>

void bind_IGESDimen_CenterLine(py::module &mod){

py::class_<IGESDimen_CenterLine, opencascade::handle<IGESDimen_CenterLine>, IGESData_IGESEntity> cls_IGESDimen_CenterLine(mod, "IGESDimen_CenterLine", "defines CenterLine, Type <106> Form <20-21> in package IGESDimen Is an entity appearing as crosshairs or as a construction between 2 positions");

// Constructors
cls_IGESDimen_CenterLine.def(py::init<>());

// Fields

// Methods
cls_IGESDimen_CenterLine.def("Init", (void (IGESDimen_CenterLine::*)(const Standard_Integer, const Standard_Real, const opencascade::handle<TColgp_HArray1OfXY> &)) &IGESDimen_CenterLine::Init, "This method is used to set the fields of the class CenterLine - aDataType : Interpretation Flag, always = 1 - aZDisplacement : Common z displacement - dataPnts : Data points (x and y)", py::arg("aDataType"), py::arg("aZdisp"), py::arg("dataPnts"));
cls_IGESDimen_CenterLine.def("SetCrossHair", (void (IGESDimen_CenterLine::*)(const Standard_Boolean)) &IGESDimen_CenterLine::SetCrossHair, "Sets FormNumber to 20 if <mode> is True, 21 else", py::arg("mode"));
cls_IGESDimen_CenterLine.def("Datatype", (Standard_Integer (IGESDimen_CenterLine::*)() const) &IGESDimen_CenterLine::Datatype, "returns Interpretation Flag : IP = 1.");
cls_IGESDimen_CenterLine.def("NbPoints", (Standard_Integer (IGESDimen_CenterLine::*)() const) &IGESDimen_CenterLine::NbPoints, "returns Number of Data Points.");
cls_IGESDimen_CenterLine.def("ZDisplacement", (Standard_Real (IGESDimen_CenterLine::*)() const) &IGESDimen_CenterLine::ZDisplacement, "returns Common Z displacement.");
cls_IGESDimen_CenterLine.def("Point", (gp_Pnt (IGESDimen_CenterLine::*)(const Standard_Integer) const) &IGESDimen_CenterLine::Point, "returns the data point as Pnt from gp. raises exception if Index <= 0 or Index > NbPoints()", py::arg("Index"));
cls_IGESDimen_CenterLine.def("TransformedPoint", (gp_Pnt (IGESDimen_CenterLine::*)(const Standard_Integer) const) &IGESDimen_CenterLine::TransformedPoint, "returns the data point as Pnt from gp after Transformation. raises exception if Index <= 0 or Index > NbPoints()", py::arg("Index"));
cls_IGESDimen_CenterLine.def("IsCrossHair", (Standard_Boolean (IGESDimen_CenterLine::*)() const) &IGESDimen_CenterLine::IsCrossHair, "returns True if Form is 20.");
cls_IGESDimen_CenterLine.def_static("get_type_name_", (const char * (*)()) &IGESDimen_CenterLine::get_type_name, "None");
cls_IGESDimen_CenterLine.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_CenterLine::get_type_descriptor, "None");
cls_IGESDimen_CenterLine.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_CenterLine::*)() const) &IGESDimen_CenterLine::DynamicType, "None");

// Enums

}