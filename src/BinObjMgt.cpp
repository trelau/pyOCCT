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

#include <BinObjMgt_PChar.hxx>
#include <BinObjMgt_PByte.hxx>
#include <BinObjMgt_PExtChar.hxx>
#include <BinObjMgt_PInteger.hxx>
#include <BinObjMgt_PReal.hxx>
#include <BinObjMgt_PShortReal.hxx>
#include <BinObjMgt_Persistent.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_AsciiString.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TDF_Label.hxx>
#include <Standard_GUID.hxx>
#include <Standard_Handle.hxx>
#include <TDF_Data.hxx>
#include <Standard_OStream.hxx>
#include <Standard_IStream.hxx>
#include <BinObjMgt_RRelocationTable.hxx>
#include <BinObjMgt_SRelocationTable.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(BinObjMgt, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.TDF");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS
	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\BinObjMgt_Persistent.lxx
	mod.def("bits_left", (Standard_OStream & (*)(Standard_OStream &, BinObjMgt_Persistent &)) &operator<<, py::is_operator(), "None", py::arg("theOS"), py::arg("theObj"));
	*/
	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\BinObjMgt_Persistent.lxx
	mod.def("bits_right", (Standard_IStream & (*)(Standard_IStream &, BinObjMgt_Persistent &)) &operator>>, py::is_operator(), "None", py::arg("theIS"), py::arg("theObj"));
	*/

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\BinObjMgt_Persistent.hxx
	py::class_<BinObjMgt_Persistent, std::unique_ptr<BinObjMgt_Persistent, Deleter<BinObjMgt_Persistent>>> cls_BinObjMgt_Persistent(mod, "BinObjMgt_Persistent", "Binary persistent representation of an object. Really it is used as a buffer for read/write an object.");
	cls_BinObjMgt_Persistent.def(py::init<>());
	cls_BinObjMgt_Persistent.def("PutCharacter", (BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(const Standard_Character)) &BinObjMgt_Persistent::PutCharacter, "None", py::arg("theValue"));
	// FIXME cls_BinObjMgt_Persistent.def("bits_left", (BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(const Standard_Character)) &BinObjMgt_Persistent::operator<<, py::is_operator(), "None", py::arg("theValue"));
	cls_BinObjMgt_Persistent.def("PutByte", (BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(const Standard_Byte)) &BinObjMgt_Persistent::PutByte, "None", py::arg("theValue"));
	// FIXME cls_BinObjMgt_Persistent.def("bits_left", (BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(const Standard_Byte)) &BinObjMgt_Persistent::operator<<, py::is_operator(), "None", py::arg("theValue"));
	cls_BinObjMgt_Persistent.def("PutExtCharacter", (BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(const Standard_ExtCharacter)) &BinObjMgt_Persistent::PutExtCharacter, "None", py::arg("theValue"));
	// FIXME cls_BinObjMgt_Persistent.def("bits_left", (BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(const Standard_ExtCharacter)) &BinObjMgt_Persistent::operator<<, py::is_operator(), "None", py::arg("theValue"));
	cls_BinObjMgt_Persistent.def("PutInteger", (BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(const Standard_Integer)) &BinObjMgt_Persistent::PutInteger, "None", py::arg("theValue"));
	// FIXME cls_BinObjMgt_Persistent.def("bits_left", (BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(const Standard_Integer)) &BinObjMgt_Persistent::operator<<, py::is_operator(), "None", py::arg("theValue"));
	cls_BinObjMgt_Persistent.def("PutBoolean", (BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(const Standard_Boolean)) &BinObjMgt_Persistent::PutBoolean, "None", py::arg("theValue"));
	// FIXME cls_BinObjMgt_Persistent.def("bits_left", (BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(const Standard_Boolean)) &BinObjMgt_Persistent::operator<<, py::is_operator(), "None", py::arg("theValue"));
	cls_BinObjMgt_Persistent.def("PutReal", (BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(const Standard_Real)) &BinObjMgt_Persistent::PutReal, "None", py::arg("theValue"));
	// FIXME cls_BinObjMgt_Persistent.def("bits_left", (BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(const Standard_Real)) &BinObjMgt_Persistent::operator<<, py::is_operator(), "None", py::arg("theValue"));
	cls_BinObjMgt_Persistent.def("PutShortReal", (BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(const Standard_ShortReal)) &BinObjMgt_Persistent::PutShortReal, "None", py::arg("theValue"));
	// FIXME cls_BinObjMgt_Persistent.def("bits_left", (BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(const Standard_ShortReal)) &BinObjMgt_Persistent::operator<<, py::is_operator(), "None", py::arg("theValue"));
	cls_BinObjMgt_Persistent.def("PutCString", (BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(const Standard_CString)) &BinObjMgt_Persistent::PutCString, "Offset in output buffer is not aligned", py::arg("theValue"));
	// FIXME cls_BinObjMgt_Persistent.def("bits_left", (BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(const Standard_CString)) &BinObjMgt_Persistent::operator<<, py::is_operator(), "None", py::arg("theValue"));
	cls_BinObjMgt_Persistent.def("PutAsciiString", (BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(const TCollection_AsciiString &)) &BinObjMgt_Persistent::PutAsciiString, "Offset in output buffer is word-aligned", py::arg("theValue"));
	// FIXME cls_BinObjMgt_Persistent.def("bits_left", (BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(const TCollection_AsciiString &)) &BinObjMgt_Persistent::operator<<, py::is_operator(), "None", py::arg("theValue"));
	cls_BinObjMgt_Persistent.def("PutExtendedString", (BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(const TCollection_ExtendedString &)) &BinObjMgt_Persistent::PutExtendedString, "Offset in output buffer is word-aligned", py::arg("theValue"));
	// FIXME cls_BinObjMgt_Persistent.def("bits_left", (BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(const TCollection_ExtendedString &)) &BinObjMgt_Persistent::operator<<, py::is_operator(), "None", py::arg("theValue"));
	cls_BinObjMgt_Persistent.def("PutLabel", (BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(const TDF_Label &)) &BinObjMgt_Persistent::PutLabel, "None", py::arg("theValue"));
	// FIXME cls_BinObjMgt_Persistent.def("bits_left", (BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(const TDF_Label &)) &BinObjMgt_Persistent::operator<<, py::is_operator(), "None", py::arg("theValue"));
	cls_BinObjMgt_Persistent.def("PutGUID", (BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(const Standard_GUID &)) &BinObjMgt_Persistent::PutGUID, "None", py::arg("theValue"));
	// FIXME cls_BinObjMgt_Persistent.def("bits_left", (BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(const Standard_GUID &)) &BinObjMgt_Persistent::operator<<, py::is_operator(), "None", py::arg("theValue"));
	cls_BinObjMgt_Persistent.def("PutCharArray", (BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(const BinObjMgt_PChar, const Standard_Integer)) &BinObjMgt_Persistent::PutCharArray, "Put C array of char, theLength is the number of elements", py::arg("theArray"), py::arg("theLength"));
	cls_BinObjMgt_Persistent.def("PutByteArray", (BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(const BinObjMgt_PByte, const Standard_Integer)) &BinObjMgt_Persistent::PutByteArray, "Put C array of unsigned chars, theLength is the number of elements", py::arg("theArray"), py::arg("theLength"));
	cls_BinObjMgt_Persistent.def("PutExtCharArray", (BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(const BinObjMgt_PExtChar, const Standard_Integer)) &BinObjMgt_Persistent::PutExtCharArray, "Put C array of ExtCharacter, theLength is the number of elements", py::arg("theArray"), py::arg("theLength"));
	cls_BinObjMgt_Persistent.def("PutIntArray", (BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(const BinObjMgt_PInteger, const Standard_Integer)) &BinObjMgt_Persistent::PutIntArray, "Put C array of int, theLength is the number of elements", py::arg("theArray"), py::arg("theLength"));
	cls_BinObjMgt_Persistent.def("PutRealArray", (BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(const BinObjMgt_PReal, const Standard_Integer)) &BinObjMgt_Persistent::PutRealArray, "Put C array of double, theLength is the number of elements", py::arg("theArray"), py::arg("theLength"));
	cls_BinObjMgt_Persistent.def("PutShortRealArray", (BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(const BinObjMgt_PShortReal, const Standard_Integer)) &BinObjMgt_Persistent::PutShortRealArray, "Put C array of float, theLength is the number of elements", py::arg("theArray"), py::arg("theLength"));
	// FIXME cls_BinObjMgt_Persistent.def("GetCharacter", (const BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(Standard_Character &) const ) &BinObjMgt_Persistent::GetCharacter, "None", py::arg("theValue"));
	// FIXME cls_BinObjMgt_Persistent.def("bits_right", (const BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(Standard_Character &) const ) &BinObjMgt_Persistent::operator>>, py::is_operator(), "None", py::arg("theValue"));
	cls_BinObjMgt_Persistent.def("GetByte", (const BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(Standard_Byte &) const ) &BinObjMgt_Persistent::GetByte, "None", py::arg("theValue"));
	// FIXME cls_BinObjMgt_Persistent.def("bits_right", (const BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(Standard_Byte &) const ) &BinObjMgt_Persistent::operator>>, py::is_operator(), "None", py::arg("theValue"));
	// FIXME cls_BinObjMgt_Persistent.def("GetExtCharacter", (const BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(Standard_ExtCharacter &) const ) &BinObjMgt_Persistent::GetExtCharacter, "None", py::arg("theValue"));
	// FIXME cls_BinObjMgt_Persistent.def("bits_right", (const BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(Standard_ExtCharacter &) const ) &BinObjMgt_Persistent::operator>>, py::is_operator(), "None", py::arg("theValue"));
	cls_BinObjMgt_Persistent.def("GetInteger", [](BinObjMgt_Persistent &self, Standard_Integer & theValue){ const BinObjMgt_Persistent & rv = self.GetInteger(theValue); return std::tuple<const BinObjMgt_Persistent &, Standard_Integer &>(rv, theValue); }, "None", py::arg("theValue"));
	// FIXME cls_BinObjMgt_Persistent.def("bits_right", (const BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(Standard_Integer &) const ) &BinObjMgt_Persistent::operator>>, py::is_operator(), "None", py::arg("theValue"));
	cls_BinObjMgt_Persistent.def("GetBoolean", [](BinObjMgt_Persistent &self, Standard_Boolean & theValue){ const BinObjMgt_Persistent & rv = self.GetBoolean(theValue); return std::tuple<const BinObjMgt_Persistent &, Standard_Boolean &>(rv, theValue); }, "None", py::arg("theValue"));
	// FIXME cls_BinObjMgt_Persistent.def("bits_right", (const BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(Standard_Boolean &) const ) &BinObjMgt_Persistent::operator>>, py::is_operator(), "None", py::arg("theValue"));
	cls_BinObjMgt_Persistent.def("GetReal", [](BinObjMgt_Persistent &self, Standard_Real & theValue){ const BinObjMgt_Persistent & rv = self.GetReal(theValue); return std::tuple<const BinObjMgt_Persistent &, Standard_Real &>(rv, theValue); }, "None", py::arg("theValue"));
	// FIXME cls_BinObjMgt_Persistent.def("bits_right", (const BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(Standard_Real &) const ) &BinObjMgt_Persistent::operator>>, py::is_operator(), "None", py::arg("theValue"));
	cls_BinObjMgt_Persistent.def("GetShortReal", (const BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(Standard_ShortReal &) const ) &BinObjMgt_Persistent::GetShortReal, "None", py::arg("theValue"));
	// FIXME cls_BinObjMgt_Persistent.def("bits_right", (const BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(Standard_ShortReal &) const ) &BinObjMgt_Persistent::operator>>, py::is_operator(), "None", py::arg("theValue"));
	cls_BinObjMgt_Persistent.def("GetAsciiString", (const BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(TCollection_AsciiString &) const ) &BinObjMgt_Persistent::GetAsciiString, "None", py::arg("theValue"));
	// FIXME cls_BinObjMgt_Persistent.def("bits_right", (const BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(TCollection_AsciiString &) const ) &BinObjMgt_Persistent::operator>>, py::is_operator(), "None", py::arg("theValue"));
	cls_BinObjMgt_Persistent.def("GetExtendedString", (const BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(TCollection_ExtendedString &) const ) &BinObjMgt_Persistent::GetExtendedString, "None", py::arg("theValue"));
	// FIXME cls_BinObjMgt_Persistent.def("bits_right", (const BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(TCollection_ExtendedString &) const ) &BinObjMgt_Persistent::operator>>, py::is_operator(), "None", py::arg("theValue"));
	cls_BinObjMgt_Persistent.def("GetLabel", (const BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(const opencascade::handle<TDF_Data> &, TDF_Label &) const ) &BinObjMgt_Persistent::GetLabel, "None", py::arg("theDS"), py::arg("theValue"));
	cls_BinObjMgt_Persistent.def("GetGUID", (const BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(Standard_GUID &) const ) &BinObjMgt_Persistent::GetGUID, "None", py::arg("theValue"));
	// FIXME cls_BinObjMgt_Persistent.def("bits_right", (const BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(Standard_GUID &) const ) &BinObjMgt_Persistent::operator>>, py::is_operator(), "None", py::arg("theValue"));
	cls_BinObjMgt_Persistent.def("GetCharArray", (const BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(const BinObjMgt_PChar, const Standard_Integer) const ) &BinObjMgt_Persistent::GetCharArray, "Get C array of char, theLength is the number of elements; theArray must point to a space enough to place theLength elements", py::arg("theArray"), py::arg("theLength"));
	cls_BinObjMgt_Persistent.def("GetByteArray", (const BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(const BinObjMgt_PByte, const Standard_Integer) const ) &BinObjMgt_Persistent::GetByteArray, "Get C array of unsigned chars, theLength is the number of elements; theArray must point to a space enough to place theLength elements", py::arg("theArray"), py::arg("theLength"));
	cls_BinObjMgt_Persistent.def("GetExtCharArray", (const BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(const BinObjMgt_PExtChar, const Standard_Integer) const ) &BinObjMgt_Persistent::GetExtCharArray, "Get C array of ExtCharacter, theLength is the number of elements; theArray must point to a space enough to place theLength elements", py::arg("theArray"), py::arg("theLength"));
	cls_BinObjMgt_Persistent.def("GetIntArray", (const BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(const BinObjMgt_PInteger, const Standard_Integer) const ) &BinObjMgt_Persistent::GetIntArray, "Get C array of int, theLength is the number of elements; theArray must point to a space enough to place theLength elements", py::arg("theArray"), py::arg("theLength"));
	cls_BinObjMgt_Persistent.def("GetRealArray", (const BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(const BinObjMgt_PReal, const Standard_Integer) const ) &BinObjMgt_Persistent::GetRealArray, "Get C array of double, theLength is the number of elements; theArray must point to a space enough to place theLength elements", py::arg("theArray"), py::arg("theLength"));
	cls_BinObjMgt_Persistent.def("GetShortRealArray", (const BinObjMgt_Persistent & (BinObjMgt_Persistent::*)(const BinObjMgt_PShortReal, const Standard_Integer) const ) &BinObjMgt_Persistent::GetShortRealArray, "Get C array of float, theLength is the number of elements; theArray must point to a space enough to place theLength elements", py::arg("theArray"), py::arg("theLength"));
	cls_BinObjMgt_Persistent.def("Position", (Standard_Integer (BinObjMgt_Persistent::*)() const ) &BinObjMgt_Persistent::Position, "Tells the current position for get/put");
	cls_BinObjMgt_Persistent.def("SetPosition", (Standard_Boolean (BinObjMgt_Persistent::*)(const Standard_Integer) const ) &BinObjMgt_Persistent::SetPosition, "Sets the current position for get/put. Resets an error state depending on the validity of thePos. Returns the new state (value of IsOK())", py::arg("thePos"));
	cls_BinObjMgt_Persistent.def("Truncate", (void (BinObjMgt_Persistent::*)()) &BinObjMgt_Persistent::Truncate, "Truncates the buffer by current position, i.e. updates mySize");
	cls_BinObjMgt_Persistent.def("IsError", (Standard_Boolean (BinObjMgt_Persistent::*)() const ) &BinObjMgt_Persistent::IsError, "Indicates an error after Get methods or SetPosition");
	cls_BinObjMgt_Persistent.def("operator!", (Standard_Boolean (BinObjMgt_Persistent::*)() const ) &BinObjMgt_Persistent::operator!, "None");
	cls_BinObjMgt_Persistent.def("IsOK", (Standard_Boolean (BinObjMgt_Persistent::*)() const ) &BinObjMgt_Persistent::IsOK, "Indicates a good state after Get methods or SetPosition");
	cls_BinObjMgt_Persistent.def("Init", (void (BinObjMgt_Persistent::*)()) &BinObjMgt_Persistent::Init, "Initializes me to reuse again");
	cls_BinObjMgt_Persistent.def("SetId", (void (BinObjMgt_Persistent::*)(const Standard_Integer)) &BinObjMgt_Persistent::SetId, "Sets the Id of the object", py::arg("theId"));
	cls_BinObjMgt_Persistent.def("SetTypeId", (void (BinObjMgt_Persistent::*)(const Standard_Integer)) &BinObjMgt_Persistent::SetTypeId, "Sets the Id of the type of the object", py::arg("theId"));
	cls_BinObjMgt_Persistent.def("Id", (Standard_Integer (BinObjMgt_Persistent::*)() const ) &BinObjMgt_Persistent::Id, "Returns the Id of the object");
	cls_BinObjMgt_Persistent.def("TypeId", (Standard_Integer (BinObjMgt_Persistent::*)() const ) &BinObjMgt_Persistent::TypeId, "Returns the Id of the type of the object");
	cls_BinObjMgt_Persistent.def("Length", (Standard_Integer (BinObjMgt_Persistent::*)() const ) &BinObjMgt_Persistent::Length, "Returns the length of data");
	cls_BinObjMgt_Persistent.def("Write", (Standard_OStream & (BinObjMgt_Persistent::*)(Standard_OStream &)) &BinObjMgt_Persistent::Write, "Stores <me> to the stream. inline Standard_OStream& operator<< (Standard_OStream&, BinObjMgt_Persistent&) is also available", py::arg("theOS"));
	cls_BinObjMgt_Persistent.def("Read", (Standard_IStream & (BinObjMgt_Persistent::*)(Standard_IStream &)) &BinObjMgt_Persistent::Read, "Retrieves <me> from the stream. inline Standard_IStream& operator>> (Standard_IStream&, BinObjMgt_Persistent&) is also available", py::arg("theIS"));
	cls_BinObjMgt_Persistent.def("Destroy", (void (BinObjMgt_Persistent::*)()) &BinObjMgt_Persistent::Destroy, "Frees the allocated memory; This object can be reused after call to Init");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinObjMgt_PChar.hxx
	other_mod = py::module::import("OCCT.AdvApp2Var");
	if (py::hasattr(other_mod, "address")) {
		mod.attr("BinObjMgt_PChar") = other_mod.attr("address");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinObjMgt_PByte.hxx
	other_mod = py::module::import("OCCT.Standard");
	if (py::hasattr(other_mod, "Standard_PByte")) {
		mod.attr("BinObjMgt_PByte") = other_mod.attr("Standard_PByte");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinObjMgt_PExtChar.hxx
	other_mod = py::module::import("OCCT.Standard");
	if (py::hasattr(other_mod, "Standard_PExtCharacter")) {
		mod.attr("BinObjMgt_PExtChar") = other_mod.attr("Standard_PExtCharacter");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinObjMgt_PInteger.hxx
	other_mod = py::module::import("OCCT.BOPCol");
	if (py::hasattr(other_mod, "BOPCol_PInteger")) {
		mod.attr("BinObjMgt_PInteger") = other_mod.attr("BOPCol_PInteger");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinObjMgt_PReal.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\BinObjMgt_PShortReal.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\BinObjMgt_RRelocationTable.hxx
	other_mod = py::module::import("OCCT.TColStd");
	if (py::hasattr(other_mod, "TColStd_DataMapOfIntegerTransient")) {
		mod.attr("BinObjMgt_RRelocationTable") = other_mod.attr("TColStd_DataMapOfIntegerTransient");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinObjMgt_SRelocationTable.hxx
	other_mod = py::module::import("OCCT.TColStd");
	if (py::hasattr(other_mod, "TColStd_IndexedMapOfTransient")) {
		mod.attr("BinObjMgt_SRelocationTable") = other_mod.attr("TColStd_IndexedMapOfTransient");
	}


}
