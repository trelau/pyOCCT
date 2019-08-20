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
#include <StdObjMgt_ReadData.hxx>
#include <Storage_BaseDriver.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <StdObjMgt_Persistent.hxx>
#include <NCollection_Array1.hxx>

void bind_StdObjMgt_ReadData(py::module &mod){

py::class_<StdObjMgt_ReadData, std::unique_ptr<StdObjMgt_ReadData>> cls_StdObjMgt_ReadData(mod, "StdObjMgt_ReadData", "Auxiliary data used to read persistent objects from a file.");

// Constructors
cls_StdObjMgt_ReadData.def(py::init<Storage_BaseDriver &, const Standard_Integer>(), py::arg("theDriver"), py::arg("theNumberOfObjects"));

// Fields

// Methods
cls_StdObjMgt_ReadData.def("ReadPersistentObject", (void (StdObjMgt_ReadData::*)(const Standard_Integer)) &StdObjMgt_ReadData::ReadPersistentObject, "None", py::arg("theRef"));
cls_StdObjMgt_ReadData.def("PersistentObject", (opencascade::handle<StdObjMgt_Persistent> (StdObjMgt_ReadData::*)(const Standard_Integer) const) &StdObjMgt_ReadData::PersistentObject, "None", py::arg("theRef"));
cls_StdObjMgt_ReadData.def("ReadReference", (opencascade::handle<StdObjMgt_Persistent> (StdObjMgt_ReadData::*)()) &StdObjMgt_ReadData::ReadReference, "None");
cls_StdObjMgt_ReadData.def("bits_right", (StdObjMgt_ReadData & (StdObjMgt_ReadData::*)(opencascade::handle<StdObjMgt_Persistent> &)) &StdObjMgt_ReadData::operator>>, py::is_operator(), "None", py::arg("theTarget"));
cls_StdObjMgt_ReadData.def("bits_right", (StdObjMgt_ReadData & (StdObjMgt_ReadData::*)(Standard_Character &)) &StdObjMgt_ReadData::operator>>, py::is_operator(), "None", py::arg("theValue"));
cls_StdObjMgt_ReadData.def("bits_right", (StdObjMgt_ReadData & (StdObjMgt_ReadData::*)(Standard_ExtCharacter &)) &StdObjMgt_ReadData::operator>>, py::is_operator(), "None", py::arg("theValue"));
cls_StdObjMgt_ReadData.def("bits_right", [](StdObjMgt_ReadData &self, Standard_Integer & theValue){ StdObjMgt_ReadData & rv = self.operator>>(theValue); return std::tuple<StdObjMgt_ReadData &, Standard_Integer &>(rv, theValue); }, "None", py::arg("theValue"));
cls_StdObjMgt_ReadData.def("bits_right", [](StdObjMgt_ReadData &self, Standard_Boolean & theValue){ StdObjMgt_ReadData & rv = self.operator>>(theValue); return std::tuple<StdObjMgt_ReadData &, Standard_Boolean &>(rv, theValue); }, "None", py::arg("theValue"));
cls_StdObjMgt_ReadData.def("bits_right", [](StdObjMgt_ReadData &self, Standard_Real & theValue){ StdObjMgt_ReadData & rv = self.operator>>(theValue); return std::tuple<StdObjMgt_ReadData &, Standard_Real &>(rv, theValue); }, "None", py::arg("theValue"));
cls_StdObjMgt_ReadData.def("bits_right", (StdObjMgt_ReadData & (StdObjMgt_ReadData::*)(Standard_ShortReal &)) &StdObjMgt_ReadData::operator>>, py::is_operator(), "None", py::arg("theValue"));

// Enums

}