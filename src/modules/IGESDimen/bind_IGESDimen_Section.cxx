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
#include <IGESDimen_Section.hxx>
#include <Standard_Type.hxx>

void bind_IGESDimen_Section(py::module &mod){

py::class_<IGESDimen_Section, opencascade::handle<IGESDimen_Section>, IGESData_IGESEntity> cls_IGESDimen_Section(mod, "IGESDimen_Section", "defines Section, Type <106> Form <31-38> in package IGESDimen Contains information to display sectioned sides");

// Constructors
cls_IGESDimen_Section.def(py::init<>());

// Fields

// Methods
cls_IGESDimen_Section.def("Init", (void (IGESDimen_Section::*)(const Standard_Integer, const Standard_Real, const opencascade::handle<TColgp_HArray1OfXY> &)) &IGESDimen_Section::Init, "This method is used to set the fields of the class Section - dataType : Interpretation Flag, always = 1 - aDisp : Common z displacement - dataPoints : Data points", py::arg("dataType"), py::arg("aDisp"), py::arg("dataPoints"));
cls_IGESDimen_Section.def("SetFormNumber", (void (IGESDimen_Section::*)(const Standard_Integer)) &IGESDimen_Section::SetFormNumber, "Changes FormNumber (indicates the Type of the Hatches) Error if not in range [31-38]", py::arg("form"));
cls_IGESDimen_Section.def("Datatype", (Standard_Integer (IGESDimen_Section::*)() const) &IGESDimen_Section::Datatype, "returns Interpretation Flag, always = 1");
cls_IGESDimen_Section.def("NbPoints", (Standard_Integer (IGESDimen_Section::*)() const) &IGESDimen_Section::NbPoints, "returns number of Data Points");
cls_IGESDimen_Section.def("ZDisplacement", (Standard_Real (IGESDimen_Section::*)() const) &IGESDimen_Section::ZDisplacement, "returns common Z displacement");
cls_IGESDimen_Section.def("Point", (gp_Pnt (IGESDimen_Section::*)(const Standard_Integer) const) &IGESDimen_Section::Point, "returns Index'th data point raises exception if Index <= 0 or Index > NbPoints()", py::arg("Index"));
cls_IGESDimen_Section.def("TransformedPoint", (gp_Pnt (IGESDimen_Section::*)(const Standard_Integer) const) &IGESDimen_Section::TransformedPoint, "returns Index'th data point after Transformation raises exception if Index <= 0 or Index > NbPoints()", py::arg("Index"));
cls_IGESDimen_Section.def_static("get_type_name_", (const char * (*)()) &IGESDimen_Section::get_type_name, "None");
cls_IGESDimen_Section.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_Section::get_type_descriptor, "None");
cls_IGESDimen_Section.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_Section::*)() const) &IGESDimen_Section::DynamicType, "None");

// Enums

}