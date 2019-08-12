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
#include <Interface_FileReaderData.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HSequenceOfHAsciiString.hxx>
#include <Interface_ParamType.hxx>
#include <IGESData_GlobalSection.hxx>
#include <IGESData_DirPart.hxx>
#include <IGESData_IGESType.hxx>
#include <Interface_Check.hxx>
#include <IGESData_IGESReaderData.hxx>
#include <Standard_Type.hxx>
#include <Interface_ParamSet.hxx>
#include <IGESData_Array1OfDirPart.hxx>
#include <IGESData_ReadStage.hxx>

void bind_IGESData_IGESReaderData(py::module &mod){

py::class_<IGESData_IGESReaderData, opencascade::handle<IGESData_IGESReaderData>, Interface_FileReaderData> cls_IGESData_IGESReaderData(mod, "IGESData_IGESReaderData", "specific FileReaderData for IGES contains header as GlobalSection, and for each Entity, its directory part as DirPart, list of Parameters as ParamSet Each Item has a DirPart, plus classically a ParamSet and the correspondant recognized Entity (inherited from FileReaderData) Parameters are accessed through specific objects, ParamReaders");

// Constructors
cls_IGESData_IGESReaderData.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("nbe"), py::arg("nbp"));

// Fields

// Methods
cls_IGESData_IGESReaderData.def("AddStartLine", (void (IGESData_IGESReaderData::*)(const Standard_CString)) &IGESData_IGESReaderData::AddStartLine, "adds a start line to start section", py::arg("aval"));
cls_IGESData_IGESReaderData.def("StartSection", (opencascade::handle<TColStd_HSequenceOfHAsciiString> (IGESData_IGESReaderData::*)() const) &IGESData_IGESReaderData::StartSection, "Returns the Start Section in once");
cls_IGESData_IGESReaderData.def("AddGlobal", (void (IGESData_IGESReaderData::*)(const Interface_ParamType, const Standard_CString)) &IGESData_IGESReaderData::AddGlobal, "adds a parameter to global section's parameter list", py::arg("atype"), py::arg("aval"));
cls_IGESData_IGESReaderData.def("SetGlobalSection", (void (IGESData_IGESReaderData::*)()) &IGESData_IGESReaderData::SetGlobalSection, "reads header (as GlobalSection) content from the ParamSet after it has been filled by successive calls to AddGlobal");
cls_IGESData_IGESReaderData.def("GlobalSection", (const IGESData_GlobalSection & (IGESData_IGESReaderData::*)() const) &IGESData_IGESReaderData::GlobalSection, "returns header as GlobalSection");
cls_IGESData_IGESReaderData.def("SetDirPart", (void (IGESData_IGESReaderData::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_CString, const Standard_CString, const Standard_CString, const Standard_CString)) &IGESData_IGESReaderData::SetDirPart, "fills a DirPart, designated by its rank (that is, (N+1)/2 if N is its first number in section D)", py::arg("num"), py::arg("i1"), py::arg("i2"), py::arg("i3"), py::arg("i4"), py::arg("i5"), py::arg("i6"), py::arg("i7"), py::arg("i8"), py::arg("i9"), py::arg("i10"), py::arg("i11"), py::arg("i12"), py::arg("i13"), py::arg("i14"), py::arg("i15"), py::arg("i16"), py::arg("i17"), py::arg("res1"), py::arg("res2"), py::arg("label"), py::arg("subs"));
cls_IGESData_IGESReaderData.def("DirPart", (const IGESData_DirPart & (IGESData_IGESReaderData::*)(const Standard_Integer) const) &IGESData_IGESReaderData::DirPart, "returns DirPart identified by record no (half Dsect number)", py::arg("num"));
// cls_IGESData_IGESReaderData.def("DirValues", [](IGESData_IGESReaderData &self, const Standard_Integer num, Standard_Integer & i1, Standard_Integer & i2, Standard_Integer & i3, Standard_Integer & i4, Standard_Integer & i5, Standard_Integer & i6, Standard_Integer & i7, Standard_Integer & i8, Standard_Integer & i9, Standard_Integer & i10, Standard_Integer & i11, Standard_Integer & i12, Standard_Integer & i13, Standard_Integer & i14, Standard_Integer & i15, Standard_Integer & i16, Standard_Integer & i17, Standard_CString & res1, Standard_CString & res2, Standard_CString & label, Standard_CString & subs){ self.DirValues(num, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, res1, res2, label, subs); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_CString &, Standard_CString &, Standard_CString &, Standard_CString &>(i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, res1, res2, label, subs); }, "returns values recorded in directory part n0 <num>", py::arg("num"), py::arg("i1"), py::arg("i2"), py::arg("i3"), py::arg("i4"), py::arg("i5"), py::arg("i6"), py::arg("i7"), py::arg("i8"), py::arg("i9"), py::arg("i10"), py::arg("i11"), py::arg("i12"), py::arg("i13"), py::arg("i14"), py::arg("i15"), py::arg("i16"), py::arg("i17"), py::arg("res1"), py::arg("res2"), py::arg("label"), py::arg("subs"));
cls_IGESData_IGESReaderData.def("DirType", (IGESData_IGESType (IGESData_IGESReaderData::*)(const Standard_Integer) const) &IGESData_IGESReaderData::DirType, "returns 'type' and 'form' info from a directory part", py::arg("num"));
cls_IGESData_IGESReaderData.def("NbEntities", (Standard_Integer (IGESData_IGESReaderData::*)() const) &IGESData_IGESReaderData::NbEntities, "Returns count of recorded Entities (i.e. size of Directory)");
cls_IGESData_IGESReaderData.def("FindNextRecord", (Standard_Integer (IGESData_IGESReaderData::*)(const Standard_Integer) const) &IGESData_IGESReaderData::FindNextRecord, "determines next suitable record from num; that is num+1 except for last one which gives 0", py::arg("num"));
cls_IGESData_IGESReaderData.def("SetEntityNumbers", (void (IGESData_IGESReaderData::*)()) &IGESData_IGESReaderData::SetEntityNumbers, "determines reference numbers in EntityNumber fields (called by SetEntities from IGESReaderTool) works on 'Integer' type Parameters, because IGES does not distinguish Integer and Entity Refs : every Integer which is odd and less than twice NbRecords can be an Entity Ref ... (Ref Number is then (N+1)/2 if N is the Integer Value)");
cls_IGESData_IGESReaderData.def("GlobalCheck", (opencascade::handle<Interface_Check> (IGESData_IGESReaderData::*)() const) &IGESData_IGESReaderData::GlobalCheck, "Returns the recorded Global Check");
cls_IGESData_IGESReaderData.def("SetDefaultLineWeight", (void (IGESData_IGESReaderData::*)(const Standard_Real)) &IGESData_IGESReaderData::SetDefaultLineWeight, "allows to set a default line weight, will be later applied at load time, on Entities which have no specified line weight", py::arg("defw"));
cls_IGESData_IGESReaderData.def("DefaultLineWeight", (Standard_Real (IGESData_IGESReaderData::*)() const) &IGESData_IGESReaderData::DefaultLineWeight, "Returns the recorded Default Line Weight, if there is (else, returns 0)");
cls_IGESData_IGESReaderData.def_static("get_type_name_", (const char * (*)()) &IGESData_IGESReaderData::get_type_name, "None");
cls_IGESData_IGESReaderData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_IGESReaderData::get_type_descriptor, "None");
cls_IGESData_IGESReaderData.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_IGESReaderData::*)() const) &IGESData_IGESReaderData::DynamicType, "None");

// Enums

}