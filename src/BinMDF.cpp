/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#include <pyOCCT_Common.hpp>

#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <BinMDF_ADriver.hxx>
#include <TColStd_IndexedMapOfTransient.hxx>
#include <TColStd_SequenceOfAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Type.hxx>
#include <BinMDF_ADriverTable.hxx>
#include <TDF_Attribute.hxx>
#include <TCollection_AsciiString.hxx>
#include <BinObjMgt_Persistent.hxx>
#include <BinObjMgt_RRelocationTable.hxx>
#include <BinObjMgt_SRelocationTable.hxx>
#include <TCollection_ExtendedString.hxx>
#include <CDM_MessageDriver.hxx>
#include <BinMDF_ReferenceDriver.hxx>
#include <BinMDF_TagSourceDriver.hxx>
#include <BinMDF.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_DataMap.hxx>
#include <BinMDF_TypeADriverMap.hxx>
#include <NCollection_DoubleMap.hxx>
#include <BinMDF_TypeIdMap.hxx>
#include <BinMDF_StringIdMap.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(BinMDF, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.TDF");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.BinObjMgt");
	py::module::import("OCCT.CDM");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDF_ADriverTable.hxx
	py::class_<BinMDF_ADriverTable, opencascade::handle<BinMDF_ADriverTable>, Standard_Transient> cls_BinMDF_ADriverTable(mod, "BinMDF_ADriverTable", "A driver table is an object building links between object types and object drivers. In the translation process, a driver table is asked to give a translation driver for each current object to be translated.");
	cls_BinMDF_ADriverTable.def(py::init<>());
	cls_BinMDF_ADriverTable.def("AddDriver", (void (BinMDF_ADriverTable::*)(const opencascade::handle<BinMDF_ADriver> &)) &BinMDF_ADriverTable::AddDriver, "Adds a translation driver <theDriver>.", py::arg("theDriver"));
	cls_BinMDF_ADriverTable.def("AssignIds", (void (BinMDF_ADriverTable::*)(const TColStd_IndexedMapOfTransient &)) &BinMDF_ADriverTable::AssignIds, "Assigns the IDs to the drivers of the given Types. It uses indices in the map as IDs. Useful in storage procedure.", py::arg("theTypes"));
	cls_BinMDF_ADriverTable.def("AssignIds", (void (BinMDF_ADriverTable::*)(const TColStd_SequenceOfAsciiString &)) &BinMDF_ADriverTable::AssignIds, "Assigns the IDs to the drivers of the given Type Names; It uses indices in the sequence as IDs. Useful in retrieval procedure.", py::arg("theTypeNames"));
	cls_BinMDF_ADriverTable.def("GetDriver", (Standard_Integer (BinMDF_ADriverTable::*)(const opencascade::handle<Standard_Type> &, opencascade::handle<BinMDF_ADriver> &) const ) &BinMDF_ADriverTable::GetDriver, "Gets a driver <theDriver> according to <theType>. Returns Type ID if the driver was assigned an ID; 0 otherwise.", py::arg("theType"), py::arg("theDriver"));
	cls_BinMDF_ADriverTable.def("GetDriver", (opencascade::handle<BinMDF_ADriver> (BinMDF_ADriverTable::*)(const Standard_Integer) const ) &BinMDF_ADriverTable::GetDriver, "Returns a driver according to <theTypeId>. Returns null handle if a driver is not found", py::arg("theTypeId"));
	cls_BinMDF_ADriverTable.def_static("get_type_name_", (const char * (*)()) &BinMDF_ADriverTable::get_type_name, "None");
	cls_BinMDF_ADriverTable.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDF_ADriverTable::get_type_descriptor, "None");
	cls_BinMDF_ADriverTable.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDF_ADriverTable::*)() const ) &BinMDF_ADriverTable::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDF_ADriver.hxx
	py::class_<BinMDF_ADriver, opencascade::handle<BinMDF_ADriver>, Standard_Transient> cls_BinMDF_ADriver(mod, "BinMDF_ADriver", "Attribute Storage/Retrieval Driver.");
	cls_BinMDF_ADriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDF_ADriver::*)() const ) &BinMDF_ADriver::NewEmpty, "Creates a new attribute from TDF.");
	cls_BinMDF_ADriver.def("SourceType", (const opencascade::handle<Standard_Type> & (BinMDF_ADriver::*)() const ) &BinMDF_ADriver::SourceType, "Returns the type of source object, inheriting from Attribute from TDF.");
	cls_BinMDF_ADriver.def("TypeName", (const TCollection_AsciiString & (BinMDF_ADriver::*)() const ) &BinMDF_ADriver::TypeName, "Returns the type name of the attribute object");
	cls_BinMDF_ADriver.def("Paste", (Standard_Boolean (BinMDF_ADriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDF_ADriver::Paste, "Translate the contents of <aSource> and put it into <aTarget>, using the relocation table <aRelocTable> to keep the sharings.", py::arg("aSource"), py::arg("aTarget"), py::arg("aRelocTable"));
	cls_BinMDF_ADriver.def("Paste", (void (BinMDF_ADriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDF_ADriver::Paste, "Translate the contents of <aSource> and put it into <aTarget>, using the relocation table <aRelocTable> to keep the sharings.", py::arg("aSource"), py::arg("aTarget"), py::arg("aRelocTable"));
	cls_BinMDF_ADriver.def("WriteMessage", (void (BinMDF_ADriver::*)(const TCollection_ExtendedString &) const ) &BinMDF_ADriver::WriteMessage, "Send message to Application (usually when error occurres)", py::arg("theMessage"));
	cls_BinMDF_ADriver.def_static("get_type_name_", (const char * (*)()) &BinMDF_ADriver::get_type_name, "None");
	cls_BinMDF_ADriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDF_ADriver::get_type_descriptor, "None");
	cls_BinMDF_ADriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDF_ADriver::*)() const ) &BinMDF_ADriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDF_ReferenceDriver.hxx
	py::class_<BinMDF_ReferenceDriver, opencascade::handle<BinMDF_ReferenceDriver>, BinMDF_ADriver> cls_BinMDF_ReferenceDriver(mod, "BinMDF_ReferenceDriver", "Reference attribute Driver.");
	cls_BinMDF_ReferenceDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDF_ReferenceDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDF_ReferenceDriver::*)() const ) &BinMDF_ReferenceDriver::NewEmpty, "None");
	cls_BinMDF_ReferenceDriver.def("Paste", (Standard_Boolean (BinMDF_ReferenceDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDF_ReferenceDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDF_ReferenceDriver.def("Paste", (void (BinMDF_ReferenceDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDF_ReferenceDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDF_ReferenceDriver.def_static("get_type_name_", (const char * (*)()) &BinMDF_ReferenceDriver::get_type_name, "None");
	cls_BinMDF_ReferenceDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDF_ReferenceDriver::get_type_descriptor, "None");
	cls_BinMDF_ReferenceDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDF_ReferenceDriver::*)() const ) &BinMDF_ReferenceDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDF_TagSourceDriver.hxx
	py::class_<BinMDF_TagSourceDriver, opencascade::handle<BinMDF_TagSourceDriver>, BinMDF_ADriver> cls_BinMDF_TagSourceDriver(mod, "BinMDF_TagSourceDriver", "TDF_TagSource Driver.");
	cls_BinMDF_TagSourceDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDF_TagSourceDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDF_TagSourceDriver::*)() const ) &BinMDF_TagSourceDriver::NewEmpty, "None");
	cls_BinMDF_TagSourceDriver.def("Paste", (Standard_Boolean (BinMDF_TagSourceDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDF_TagSourceDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDF_TagSourceDriver.def("Paste", (void (BinMDF_TagSourceDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDF_TagSourceDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDF_TagSourceDriver.def_static("get_type_name_", (const char * (*)()) &BinMDF_TagSourceDriver::get_type_name, "None");
	cls_BinMDF_TagSourceDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDF_TagSourceDriver::get_type_descriptor, "None");
	cls_BinMDF_TagSourceDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDF_TagSourceDriver::*)() const ) &BinMDF_TagSourceDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDF.hxx
	py::class_<BinMDF, std::unique_ptr<BinMDF, Deleter<BinMDF>>> cls_BinMDF(mod, "BinMDF", "This package provides classes and methods to translate a transient DF into a persistent one and vice versa.");
	cls_BinMDF.def(py::init<>());
	cls_BinMDF.def_static("AddDrivers_", (void (*)(const opencascade::handle<BinMDF_ADriverTable> &, const opencascade::handle<CDM_MessageDriver> &)) &BinMDF::AddDrivers, "Adds the attribute storage drivers to <aDriverTable>.", py::arg("aDriverTable"), py::arg("aMsgDrv"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDF_TypeADriverMap.hxx
	bind_NCollection_DataMap<opencascade::handle<Standard_Type>, opencascade::handle<BinMDF_ADriver>, NCollection_DefaultHasher<opencascade::handle<Standard_Transient> > >(mod, "BinMDF_TypeADriverMap");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDF_TypeIdMap.hxx
	bind_NCollection_DoubleMap<opencascade::handle<Standard_Type>, int, NCollection_DefaultHasher<opencascade::handle<Standard_Transient> >, NCollection_DefaultHasher<int> >(mod, "BinMDF_TypeIdMap");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDF_StringIdMap.hxx
	other_mod = py::module::import("OCCT.TColStd");
	if (py::hasattr(other_mod, "TColStd_DataMapOfAsciiStringInteger")) {
		mod.attr("BinMDF_StringIdMap") = other_mod.attr("TColStd_DataMapOfAsciiStringInteger");
	}


}
