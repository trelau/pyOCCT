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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <StdObjMgt_Persistent.hxx>
#include <StdObjMgt_ReadData.hxx>
#include <StdObjMgt_WriteData.hxx>
#include <NCollection_Sequence.hxx>
#include <Standard_TypeDef.hxx>
#include <TDocStd_Document.hxx>
#include <TDF_Attribute.hxx>
#include <TCollection_HAsciiString.hxx>
#include <TCollection_HExtendedString.hxx>
#include <TDF_Label.hxx>
#include <TDF_Data.hxx>
#include <StdObjMgt_SharedObject.hxx>
#include <Storage_BaseDriver.hxx>
#include <NCollection_Array1.hxx>
#include <NCollection_DataMap.hxx>
#include <StdObjMgt_TransientPersistentMap.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard.hxx>
#include <StdObjMgt_MapOfInstantiators.hxx>
#include <bind_NCollection_DataMap.hxx>

PYBIND11_MODULE(StdObjMgt, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TDocStd");
py::module::import("OCCT.TDF");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.Storage");

// CLASS: STDOBJMGT_PERSISTENT
py::class_<StdObjMgt_Persistent, opencascade::handle<StdObjMgt_Persistent>, Standard_Transient> cls_StdObjMgt_Persistent(mod, "StdObjMgt_Persistent", "Root class for a temporary persistent object that reads data from a file and then creates transient object using the data.");

// Methods
cls_StdObjMgt_Persistent.def("Read", (void (StdObjMgt_Persistent::*)(StdObjMgt_ReadData &)) &StdObjMgt_Persistent::Read, "Read persistent data from a file.", py::arg("theReadData"));
cls_StdObjMgt_Persistent.def("Write", (void (StdObjMgt_Persistent::*)(StdObjMgt_WriteData &) const) &StdObjMgt_Persistent::Write, "Write persistent data to a file.", py::arg("theWriteData"));
cls_StdObjMgt_Persistent.def("PChildren", (void (StdObjMgt_Persistent::*)(StdObjMgt_Persistent::SequenceOfPersistent &) const) &StdObjMgt_Persistent::PChildren, "Gets persistent child objects", py::arg(""));
cls_StdObjMgt_Persistent.def("PName", (Standard_CString (StdObjMgt_Persistent::*)() const) &StdObjMgt_Persistent::PName, "Returns persistent type name");
cls_StdObjMgt_Persistent.def("ImportDocument", (void (StdObjMgt_Persistent::*)(const opencascade::handle<TDocStd_Document> &) const) &StdObjMgt_Persistent::ImportDocument, "Import transient document from the persistent data (to be overriden by document class; does nothing by default for other classes).", py::arg("theDocument"));
cls_StdObjMgt_Persistent.def("CreateAttribute", (opencascade::handle<TDF_Attribute> (StdObjMgt_Persistent::*)()) &StdObjMgt_Persistent::CreateAttribute, "Create an empty transient attribuite (to be overriden by attribute classes; does nothing and returns a null handle by default for other classes).");
cls_StdObjMgt_Persistent.def("GetAttribute", (opencascade::handle<TDF_Attribute> (StdObjMgt_Persistent::*)() const) &StdObjMgt_Persistent::GetAttribute, "Get transient attribuite for the persistent data (to be overriden by attribute classes; returns a null handle by default for non-attribute classes).");
cls_StdObjMgt_Persistent.def("ImportAttribute", (void (StdObjMgt_Persistent::*)()) &StdObjMgt_Persistent::ImportAttribute, "Import transient attribuite from the persistent data (to be overriden by attribute classes; does nothing by default for non-attribute classes).");
cls_StdObjMgt_Persistent.def("AsciiString", (opencascade::handle<TCollection_HAsciiString> (StdObjMgt_Persistent::*)() const) &StdObjMgt_Persistent::AsciiString, "Get referenced ASCII string (to be overriden by ASCII string class; returns a null handle by default for other classes).");
cls_StdObjMgt_Persistent.def("ExtString", (opencascade::handle<TCollection_HExtendedString> (StdObjMgt_Persistent::*)() const) &StdObjMgt_Persistent::ExtString, "Get referenced extended string (to be overriden by extended string class; returns a null handle by default for other classes).");
cls_StdObjMgt_Persistent.def("Label", (TDF_Label (StdObjMgt_Persistent::*)(const opencascade::handle<TDF_Data> &) const) &StdObjMgt_Persistent::Label, "Get a label expressed by referenced extended string (to be overriden by extended string class; returns a null label by default for other classes).", py::arg("theDF"));
cls_StdObjMgt_Persistent.def("TypeNum", (Standard_Integer (StdObjMgt_Persistent::*)() const) &StdObjMgt_Persistent::TypeNum, "Returns the assigned persistent type number");
cls_StdObjMgt_Persistent.def("TypeNum", (void (StdObjMgt_Persistent::*)(Standard_Integer)) &StdObjMgt_Persistent::TypeNum, "Assigns a persistent type number to the object", py::arg("theTypeNum"));
cls_StdObjMgt_Persistent.def("RefNum", (Standard_Integer (StdObjMgt_Persistent::*)() const) &StdObjMgt_Persistent::RefNum, "Returns the object reference number");
cls_StdObjMgt_Persistent.def("RefNum", (void (StdObjMgt_Persistent::*)(Standard_Integer)) &StdObjMgt_Persistent::RefNum, "Sets an object reference number", py::arg("theRefNum"));

// CLASS: STDOBJMGT_SHAREDOBJECT
py::class_<StdObjMgt_SharedObject> cls_StdObjMgt_SharedObject(mod, "StdObjMgt_SharedObject", "None");

// Constructors
cls_StdObjMgt_SharedObject.def(py::init<>());

// CLASS: STDOBJMGT_READDATA
py::class_<StdObjMgt_ReadData> cls_StdObjMgt_ReadData(mod, "StdObjMgt_ReadData", "Auxiliary data used to read persistent objects from a file.");

// Constructors
cls_StdObjMgt_ReadData.def(py::init<Storage_BaseDriver &, const Standard_Integer>(), py::arg("theDriver"), py::arg("theNumberOfObjects"));

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

// CLASS: STDOBJMGT_WRITEDATA
py::class_<StdObjMgt_WriteData> cls_StdObjMgt_WriteData(mod, "StdObjMgt_WriteData", "Auxiliary data used to write persistent objects to a file.");

// Constructors
cls_StdObjMgt_WriteData.def(py::init<Storage_BaseDriver &>(), py::arg("theDriver"));

// Methods
cls_StdObjMgt_WriteData.def("WritePersistentObject", (void (StdObjMgt_WriteData::*)(const opencascade::handle<StdObjMgt_Persistent> &)) &StdObjMgt_WriteData::WritePersistentObject, "None", py::arg("thePersistent"));
cls_StdObjMgt_WriteData.def("bits_left", (StdObjMgt_WriteData & (StdObjMgt_WriteData::*)(const opencascade::handle<StdObjMgt_Persistent> &)) &StdObjMgt_WriteData::operator<<, py::is_operator(), "None", py::arg("thePersistent"));
cls_StdObjMgt_WriteData.def("bits_left", (StdObjMgt_WriteData & (StdObjMgt_WriteData::*)(const Standard_Character &)) &StdObjMgt_WriteData::operator<<, py::is_operator(), "None", py::arg("theValue"));
cls_StdObjMgt_WriteData.def("bits_left", (StdObjMgt_WriteData & (StdObjMgt_WriteData::*)(const Standard_ExtCharacter &)) &StdObjMgt_WriteData::operator<<, py::is_operator(), "None", py::arg("theValue"));
cls_StdObjMgt_WriteData.def("bits_left", (StdObjMgt_WriteData & (StdObjMgt_WriteData::*)(const Standard_Integer &)) &StdObjMgt_WriteData::operator<<, py::is_operator(), "None", py::arg("theValue"));
cls_StdObjMgt_WriteData.def("bits_left", (StdObjMgt_WriteData & (StdObjMgt_WriteData::*)(const Standard_Boolean &)) &StdObjMgt_WriteData::operator<<, py::is_operator(), "None", py::arg("theValue"));
cls_StdObjMgt_WriteData.def("bits_left", (StdObjMgt_WriteData & (StdObjMgt_WriteData::*)(const Standard_Real &)) &StdObjMgt_WriteData::operator<<, py::is_operator(), "None", py::arg("theValue"));
cls_StdObjMgt_WriteData.def("bits_left", (StdObjMgt_WriteData & (StdObjMgt_WriteData::*)(const Standard_ShortReal &)) &StdObjMgt_WriteData::operator<<, py::is_operator(), "None", py::arg("theValue"));

// TYPEDEF: STDOBJMGT_TRANSIENTPERSISTENTMAP
bind_NCollection_DataMap<opencascade::handle<Standard_Transient>, opencascade::handle<StdObjMgt_Persistent>, NCollection_DefaultHasher<opencascade::handle<Standard_Transient> > >(mod, "StdObjMgt_TransientPersistentMap", py::module_local(false));

// CLASS: STDOBJMGT_MAPOFINSTANTIATORS
py::class_<StdObjMgt_MapOfInstantiators> cls_StdObjMgt_MapOfInstantiators(mod, "StdObjMgt_MapOfInstantiators", "None");

// Constructors
cls_StdObjMgt_MapOfInstantiators.def(py::init<>());

// Methods
// cls_StdObjMgt_MapOfInstantiators.def_static("operator new_", (void * (*)(size_t)) &StdObjMgt_MapOfInstantiators::operator new, "None", py::arg("theSize"));
// cls_StdObjMgt_MapOfInstantiators.def_static("operator delete_", (void (*)(void *)) &StdObjMgt_MapOfInstantiators::operator delete, "None", py::arg("theAddress"));
// cls_StdObjMgt_MapOfInstantiators.def_static("operator new[]_", (void * (*)(size_t)) &StdObjMgt_MapOfInstantiators::operator new[], "None", py::arg("theSize"));
// cls_StdObjMgt_MapOfInstantiators.def_static("operator delete[]_", (void (*)(void *)) &StdObjMgt_MapOfInstantiators::operator delete[], "None", py::arg("theAddress"));
// cls_StdObjMgt_MapOfInstantiators.def_static("operator new_", (void * (*)(size_t, void *)) &StdObjMgt_MapOfInstantiators::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StdObjMgt_MapOfInstantiators.def_static("operator delete_", (void (*)(void *, void *)) &StdObjMgt_MapOfInstantiators::operator delete, "None", py::arg(""), py::arg(""));


}
