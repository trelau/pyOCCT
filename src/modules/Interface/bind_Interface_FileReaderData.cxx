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
#include <Standard_TypeDef.hxx>
#include <Interface_ParamType.hxx>
#include <TCollection_AsciiString.hxx>
#include <Interface_FileParameter.hxx>
#include <Standard_Handle.hxx>
#include <Interface_ParamList.hxx>
#include <Interface_FileReaderData.hxx>
#include <Standard_Type.hxx>
#include <Interface_ParamSet.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColStd_Array1OfTransient.hxx>

void bind_Interface_FileReaderData(py::module &mod){

py::class_<Interface_FileReaderData, opencascade::handle<Interface_FileReaderData>, Standard_Transient> cls_Interface_FileReaderData(mod, "Interface_FileReaderData", "This class defines services which permit to access Data issued from a File, in a form which does not depend of physical format : thus, each Record has an attached ParamList (to be managed) and resulting Entity.");

// Fields

// Methods
cls_Interface_FileReaderData.def("NbRecords", (Standard_Integer (Interface_FileReaderData::*)() const) &Interface_FileReaderData::NbRecords, "Returns the count of registered records That is, value given for Initialization (can be redefined)");
cls_Interface_FileReaderData.def("NbEntities", (Standard_Integer (Interface_FileReaderData::*)() const) &Interface_FileReaderData::NbEntities, "Returns the count of entities. Depending of each norm, records can be Entities or SubParts (SubList in STEP, SubGroup in SET ...). NbEntities counts only Entities, not Subs Used for memory reservation in InterfaceModel Default implementation uses FindNextRecord Can be redefined into a more performant way");
cls_Interface_FileReaderData.def("FindNextRecord", (Standard_Integer (Interface_FileReaderData::*)(const Standard_Integer) const) &Interface_FileReaderData::FindNextRecord, "Determines the record number defining an Entity following a given record number. Specific to each sub-class of FileReaderData. Returning zero means no record found", py::arg("num"));
cls_Interface_FileReaderData.def("InitParams", (void (Interface_FileReaderData::*)(const Standard_Integer)) &Interface_FileReaderData::InitParams, "attaches an empty ParamList to a Record", py::arg("num"));
cls_Interface_FileReaderData.def("AddParam", [](Interface_FileReaderData &self, const Standard_Integer a0, const Standard_CString a1, const Interface_ParamType a2) -> void { return self.AddParam(a0, a1, a2); });
cls_Interface_FileReaderData.def("AddParam", (void (Interface_FileReaderData::*)(const Standard_Integer, const Standard_CString, const Interface_ParamType, const Standard_Integer)) &Interface_FileReaderData::AddParam, "Adds a parameter to record no 'num' and fills its fields (EntityNumber is optional) Warning : <aval> is assumed to be memory-managed elsewhere : it is NOT copied. This gives a best speed : strings remain stored in pages of characters", py::arg("num"), py::arg("aval"), py::arg("atype"), py::arg("nument"));
cls_Interface_FileReaderData.def("AddParam", [](Interface_FileReaderData &self, const Standard_Integer a0, const TCollection_AsciiString & a1, const Interface_ParamType a2) -> void { return self.AddParam(a0, a1, a2); });
cls_Interface_FileReaderData.def("AddParam", (void (Interface_FileReaderData::*)(const Standard_Integer, const TCollection_AsciiString &, const Interface_ParamType, const Standard_Integer)) &Interface_FileReaderData::AddParam, "Same as above, but gets a AsciiString from TCollection Remark that the content of the AsciiString is locally copied (because its content is most often lost after using)", py::arg("num"), py::arg("aval"), py::arg("atype"), py::arg("nument"));
cls_Interface_FileReaderData.def("AddParam", (void (Interface_FileReaderData::*)(const Standard_Integer, const Interface_FileParameter &)) &Interface_FileReaderData::AddParam, "Same as above, but gets a complete FileParameter Warning : Content of <FP> is NOT copied : its original address and space in memory are assumed to be managed elsewhere (see ParamSet)", py::arg("num"), py::arg("FP"));
cls_Interface_FileReaderData.def("SetParam", (void (Interface_FileReaderData::*)(const Standard_Integer, const Standard_Integer, const Interface_FileParameter &)) &Interface_FileReaderData::SetParam, "Sets a new value for a parameter of a record, given by : num : record number; nump : parameter number in the record", py::arg("num"), py::arg("nump"), py::arg("FP"));
cls_Interface_FileReaderData.def("NbParams", (Standard_Integer (Interface_FileReaderData::*)(const Standard_Integer) const) &Interface_FileReaderData::NbParams, "Returns count of parameters attached to record 'num' If <num> = 0, returns the total recorded count of parameters", py::arg("num"));
cls_Interface_FileReaderData.def("Params", (opencascade::handle<Interface_ParamList> (Interface_FileReaderData::*)(const Standard_Integer) const) &Interface_FileReaderData::Params, "Returns the complete ParamList of a record (read only) num = 0 to return the whole param list for the file", py::arg("num"));
cls_Interface_FileReaderData.def("Param", (const Interface_FileParameter & (Interface_FileReaderData::*)(const Standard_Integer, const Standard_Integer) const) &Interface_FileReaderData::Param, "Returns parameter 'nump' of record 'num', as a complete FileParameter", py::arg("num"), py::arg("nump"));
cls_Interface_FileReaderData.def("ChangeParam", (Interface_FileParameter & (Interface_FileReaderData::*)(const Standard_Integer, const Standard_Integer)) &Interface_FileReaderData::ChangeParam, "Same as above, but in order to be modified on place", py::arg("num"), py::arg("nump"));
cls_Interface_FileReaderData.def("ParamType", (Interface_ParamType (Interface_FileReaderData::*)(const Standard_Integer, const Standard_Integer) const) &Interface_FileReaderData::ParamType, "Returns type of parameter 'nump' of record 'num' Returns literal value of parameter 'nump' of record 'num' was C++ : return const &", py::arg("num"), py::arg("nump"));
cls_Interface_FileReaderData.def("ParamCValue", (Standard_CString (Interface_FileReaderData::*)(const Standard_Integer, const Standard_Integer) const) &Interface_FileReaderData::ParamCValue, "Same as above, but as a CString was C++ : return const", py::arg("num"), py::arg("nump"));
cls_Interface_FileReaderData.def("IsParamDefined", (Standard_Boolean (Interface_FileReaderData::*)(const Standard_Integer, const Standard_Integer) const) &Interface_FileReaderData::IsParamDefined, "Returns True if parameter 'nump' of record 'num' is defined (it is not if its type is ParamVoid)", py::arg("num"), py::arg("nump"));
cls_Interface_FileReaderData.def("ParamNumber", (Standard_Integer (Interface_FileReaderData::*)(const Standard_Integer, const Standard_Integer) const) &Interface_FileReaderData::ParamNumber, "Returns record number of an entity referenced by a parameter of type Ident; 0 if no EntityNumber has been determined Note that it is used to reference Entities but also Sublists (sublists are not objects, but internal descriptions)", py::arg("num"), py::arg("nump"));
cls_Interface_FileReaderData.def("ParamEntity", (const opencascade::handle<Standard_Transient> & (Interface_FileReaderData::*)(const Standard_Integer, const Standard_Integer) const) &Interface_FileReaderData::ParamEntity, "Returns the StepEntity referenced by a parameter Error if none", py::arg("num"), py::arg("nump"));
cls_Interface_FileReaderData.def("ParamFirstRank", (Standard_Integer (Interface_FileReaderData::*)(const Standard_Integer) const) &Interface_FileReaderData::ParamFirstRank, "Returns the absolute rank of the beginning of a record (its lsit is from ParamFirstRank+1 to ParamFirstRank+NbParams)", py::arg("num"));
cls_Interface_FileReaderData.def("BoundEntity", (const opencascade::handle<Standard_Transient> & (Interface_FileReaderData::*)(const Standard_Integer) const) &Interface_FileReaderData::BoundEntity, "Returns the entity bound to a record, set by SetEntities", py::arg("num"));
cls_Interface_FileReaderData.def("BindEntity", (void (Interface_FileReaderData::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &)) &Interface_FileReaderData::BindEntity, "Binds an entity to a record", py::arg("num"), py::arg("ent"));
cls_Interface_FileReaderData.def("SetErrorLoad", (void (Interface_FileReaderData::*)(const Standard_Boolean)) &Interface_FileReaderData::SetErrorLoad, "Sets the status 'Error Load' on, to overside check fails <val> True : declares unloaded <val> False : declares loaded If not called before loading (see FileReaderTool), check fails give the status IsErrorLoad says if SetErrorLoad has been called by user ResetErrorLoad resets it (called by FileReaderTool) This allows to specify that the currently loaded entity remains unloaded (because of syntactic fail)", py::arg("val"));
cls_Interface_FileReaderData.def("IsErrorLoad", (Standard_Boolean (Interface_FileReaderData::*)() const) &Interface_FileReaderData::IsErrorLoad, "Returns True if the status 'Error Load' has been set (to True or False)");
cls_Interface_FileReaderData.def("ResetErrorLoad", (Standard_Boolean (Interface_FileReaderData::*)()) &Interface_FileReaderData::ResetErrorLoad, "Returns the former value of status 'Error Load' then resets it Used to read the status then ensure it is reset");
cls_Interface_FileReaderData.def("Destroy", (void (Interface_FileReaderData::*)()) &Interface_FileReaderData::Destroy, "Destructor (waiting for memory management)");
cls_Interface_FileReaderData.def_static("Fastof_", (Standard_Real (*)(const Standard_CString)) &Interface_FileReaderData::Fastof, "Same spec.s as standard <atof> but 5 times faster", py::arg("str"));
cls_Interface_FileReaderData.def_static("get_type_name_", (const char * (*)()) &Interface_FileReaderData::get_type_name, "None");
cls_Interface_FileReaderData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_FileReaderData::get_type_descriptor, "None");
cls_Interface_FileReaderData.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_FileReaderData::*)() const) &Interface_FileReaderData::DynamicType, "None");

// Enums

}