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
#include <TCollection_HAsciiString.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <IGESDimen_DimensionDisplayData.hxx>
#include <Standard_Type.hxx>

void bind_IGESDimen_DimensionDisplayData(py::module &mod){

py::class_<IGESDimen_DimensionDisplayData, opencascade::handle<IGESDimen_DimensionDisplayData>, IGESData_IGESEntity> cls_IGESDimen_DimensionDisplayData(mod, "IGESDimen_DimensionDisplayData", "Defines IGES Dimension Display Data, Type <406> Form <30>, in package IGESDimen The Dimensional Display Data Property is optional but when present must be referenced by a dimension entity. The information it contains could be extracted from the text, leader and witness line data with difficulty.");

// Constructors
cls_IGESDimen_DimensionDisplayData.def(py::init<>());

// Fields

// Methods
cls_IGESDimen_DimensionDisplayData.def("Init", (void (IGESDimen_DimensionDisplayData::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const Standard_Real, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &)) &IGESDimen_DimensionDisplayData::Init, "None", py::arg("numProps"), py::arg("aDimType"), py::arg("aLabelPos"), py::arg("aCharSet"), py::arg("aString"), py::arg("aSymbol"), py::arg("anAng"), py::arg("anAlign"), py::arg("aLevel"), py::arg("aPlace"), py::arg("anOrient"), py::arg("initVal"), py::arg("notes"), py::arg("startInd"), py::arg("endInd"));
cls_IGESDimen_DimensionDisplayData.def("NbPropertyValues", (Standard_Integer (IGESDimen_DimensionDisplayData::*)() const) &IGESDimen_DimensionDisplayData::NbPropertyValues, "returns the number of property values (14)");
cls_IGESDimen_DimensionDisplayData.def("DimensionType", (Standard_Integer (IGESDimen_DimensionDisplayData::*)() const) &IGESDimen_DimensionDisplayData::DimensionType, "returns the dimension type");
cls_IGESDimen_DimensionDisplayData.def("LabelPosition", (Standard_Integer (IGESDimen_DimensionDisplayData::*)() const) &IGESDimen_DimensionDisplayData::LabelPosition, "returns the preferred label position");
cls_IGESDimen_DimensionDisplayData.def("CharacterSet", (Standard_Integer (IGESDimen_DimensionDisplayData::*)() const) &IGESDimen_DimensionDisplayData::CharacterSet, "returns the character set interpretation");
cls_IGESDimen_DimensionDisplayData.def("LString", (opencascade::handle<TCollection_HAsciiString> (IGESDimen_DimensionDisplayData::*)() const) &IGESDimen_DimensionDisplayData::LString, "returns e.g., 8HDIAMETER");
cls_IGESDimen_DimensionDisplayData.def("DecimalSymbol", (Standard_Integer (IGESDimen_DimensionDisplayData::*)() const) &IGESDimen_DimensionDisplayData::DecimalSymbol, "None");
cls_IGESDimen_DimensionDisplayData.def("WitnessLineAngle", (Standard_Real (IGESDimen_DimensionDisplayData::*)() const) &IGESDimen_DimensionDisplayData::WitnessLineAngle, "returns the witness line angle in radians");
cls_IGESDimen_DimensionDisplayData.def("TextAlignment", (Standard_Integer (IGESDimen_DimensionDisplayData::*)() const) &IGESDimen_DimensionDisplayData::TextAlignment, "returns the text alignment");
cls_IGESDimen_DimensionDisplayData.def("TextLevel", (Standard_Integer (IGESDimen_DimensionDisplayData::*)() const) &IGESDimen_DimensionDisplayData::TextLevel, "returns the text level");
cls_IGESDimen_DimensionDisplayData.def("TextPlacement", (Standard_Integer (IGESDimen_DimensionDisplayData::*)() const) &IGESDimen_DimensionDisplayData::TextPlacement, "returns the preferred text placement");
cls_IGESDimen_DimensionDisplayData.def("ArrowHeadOrientation", (Standard_Integer (IGESDimen_DimensionDisplayData::*)() const) &IGESDimen_DimensionDisplayData::ArrowHeadOrientation, "returns the arrowhead orientation");
cls_IGESDimen_DimensionDisplayData.def("InitialValue", (Standard_Real (IGESDimen_DimensionDisplayData::*)() const) &IGESDimen_DimensionDisplayData::InitialValue, "returns the primary dimension initial value");
cls_IGESDimen_DimensionDisplayData.def("NbSupplementaryNotes", (Standard_Integer (IGESDimen_DimensionDisplayData::*)() const) &IGESDimen_DimensionDisplayData::NbSupplementaryNotes, "returns the number of supplementary notes or zero");
cls_IGESDimen_DimensionDisplayData.def("SupplementaryNote", (Standard_Integer (IGESDimen_DimensionDisplayData::*)(const Standard_Integer) const) &IGESDimen_DimensionDisplayData::SupplementaryNote, "returns the Index'th supplementary note raises exception if Index <= 0 or Index > NbSupplementaryNotes()", py::arg("Index"));
cls_IGESDimen_DimensionDisplayData.def("StartIndex", (Standard_Integer (IGESDimen_DimensionDisplayData::*)(const Standard_Integer) const) &IGESDimen_DimensionDisplayData::StartIndex, "returns the Index'th note start index raises exception if Index <= 0 or Index > NbSupplementaryNotes()", py::arg("Index"));
cls_IGESDimen_DimensionDisplayData.def("EndIndex", (Standard_Integer (IGESDimen_DimensionDisplayData::*)(const Standard_Integer) const) &IGESDimen_DimensionDisplayData::EndIndex, "returns the Index'th note end index raises exception if Index <= 0 or Index > NbSupplemetaryNotes()", py::arg("Index"));
cls_IGESDimen_DimensionDisplayData.def_static("get_type_name_", (const char * (*)()) &IGESDimen_DimensionDisplayData::get_type_name, "None");
cls_IGESDimen_DimensionDisplayData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_DimensionDisplayData::get_type_descriptor, "None");
cls_IGESDimen_DimensionDisplayData.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_DimensionDisplayData::*)() const) &IGESDimen_DimensionDisplayData::DynamicType, "None");

// Enums

}