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
#include <Standard_Handle.hxx>
#include <Standard_Failure.hxx>
#include <TopoDS_Shape.hxx>
#include <gp_XYZ.hxx>
#include <gp_XY.hxx>
#include <Standard_Type.hxx>
#include <TCollection_AsciiString.hxx>
#include <Message_Msg.hxx>
#include <MoniTool_CaseData.hxx>
#include <TColStd_SequenceOfTransient.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <TColStd_SequenceOfAsciiString.hxx>

void bind_MoniTool_CaseData(py::module &mod){

py::class_<MoniTool_CaseData, opencascade::handle<MoniTool_CaseData>, Standard_Transient> cls_MoniTool_CaseData(mod, "MoniTool_CaseData", "This class is intended to record data attached to a case to be exploited. Cases can be : * internal, i.e. for immediate debug for instance, on an abnormal exception, fill a CaseData in a DB (see class DB) then look at its content by XSDRAW * to record abnormal situation, which cause a warning or fail message, for instance during a transfer This will allow, firstly to build a more comprehensive message (with associated data), secondly to help seeing 'what happened' * to record data in order to fix a problem If a CASE is well defined and its fix is well known too, recording a CaseData which identifies the CASE will allow to furstherly call the appropriate fix routine");

// Constructors
cls_MoniTool_CaseData.def(py::init<>());
cls_MoniTool_CaseData.def(py::init<const Standard_CString>(), py::arg("caseid"));
cls_MoniTool_CaseData.def(py::init<const Standard_CString, const Standard_CString>(), py::arg("caseid"), py::arg("name"));

// Fields

// Methods
cls_MoniTool_CaseData.def("SetCaseId", (void (MoniTool_CaseData::*)(const Standard_CString)) &MoniTool_CaseData::SetCaseId, "Sets a CaseId", py::arg("caseid"));
cls_MoniTool_CaseData.def("SetName", (void (MoniTool_CaseData::*)(const Standard_CString)) &MoniTool_CaseData::SetName, "Sets a Name", py::arg("name"));
cls_MoniTool_CaseData.def("CaseId", (Standard_CString (MoniTool_CaseData::*)() const) &MoniTool_CaseData::CaseId, "Returns the CaseId");
cls_MoniTool_CaseData.def("Name", (Standard_CString (MoniTool_CaseData::*)() const) &MoniTool_CaseData::Name, "Returns the Name");
cls_MoniTool_CaseData.def("IsCheck", (Standard_Boolean (MoniTool_CaseData::*)() const) &MoniTool_CaseData::IsCheck, "Tells if <me> is Check (Warning or Fail), else it is Info");
cls_MoniTool_CaseData.def("IsWarning", (Standard_Boolean (MoniTool_CaseData::*)() const) &MoniTool_CaseData::IsWarning, "Tells if <me> is Warning");
cls_MoniTool_CaseData.def("IsFail", (Standard_Boolean (MoniTool_CaseData::*)() const) &MoniTool_CaseData::IsFail, "Tells if <me> is Fail");
cls_MoniTool_CaseData.def("ResetCheck", (void (MoniTool_CaseData::*)()) &MoniTool_CaseData::ResetCheck, "Resets Check Status, i.e. sets <me> as Info");
cls_MoniTool_CaseData.def("SetWarning", (void (MoniTool_CaseData::*)()) &MoniTool_CaseData::SetWarning, "Sets <me> as Warning");
cls_MoniTool_CaseData.def("SetFail", (void (MoniTool_CaseData::*)()) &MoniTool_CaseData::SetFail, "Sets <me> as Fail");
cls_MoniTool_CaseData.def("SetChange", (void (MoniTool_CaseData::*)()) &MoniTool_CaseData::SetChange, "Sets the next Add... not to add but to change the data item designated by its name. If next Add... is not called with a name, SetChange is ignored Reset by next Add... , whatever <num> is correct or not");
cls_MoniTool_CaseData.def("SetReplace", (void (MoniTool_CaseData::*)(const Standard_Integer)) &MoniTool_CaseData::SetReplace, "Sets the next Add... not to add but to replace the data item <num>, if <num> is between 1 and NbData. Reset by next Add... , whatever <num> is correct or not", py::arg("num"));
cls_MoniTool_CaseData.def("AddData", [](MoniTool_CaseData &self, const opencascade::handle<Standard_Transient> & a0, const Standard_Integer a1) -> void { return self.AddData(a0, a1); });
cls_MoniTool_CaseData.def("AddData", (void (MoniTool_CaseData::*)(const opencascade::handle<Standard_Transient> &, const Standard_Integer, const Standard_CString)) &MoniTool_CaseData::AddData, "Unitary adding a data; rather internal", py::arg("val"), py::arg("kind"), py::arg("name"));
cls_MoniTool_CaseData.def("AddRaised", [](MoniTool_CaseData &self, const opencascade::handle<Standard_Failure> & a0) -> void { return self.AddRaised(a0); });
cls_MoniTool_CaseData.def("AddRaised", (void (MoniTool_CaseData::*)(const opencascade::handle<Standard_Failure> &, const Standard_CString)) &MoniTool_CaseData::AddRaised, "Adds the currently caught exception", py::arg("theException"), py::arg("name"));
cls_MoniTool_CaseData.def("AddShape", [](MoniTool_CaseData &self, const TopoDS_Shape & a0) -> void { return self.AddShape(a0); });
cls_MoniTool_CaseData.def("AddShape", (void (MoniTool_CaseData::*)(const TopoDS_Shape &, const Standard_CString)) &MoniTool_CaseData::AddShape, "Adds a Shape (recorded as a HShape)", py::arg("sh"), py::arg("name"));
cls_MoniTool_CaseData.def("AddXYZ", [](MoniTool_CaseData &self, const gp_XYZ & a0) -> void { return self.AddXYZ(a0); });
cls_MoniTool_CaseData.def("AddXYZ", (void (MoniTool_CaseData::*)(const gp_XYZ &, const Standard_CString)) &MoniTool_CaseData::AddXYZ, "Adds a XYZ", py::arg("aXYZ"), py::arg("name"));
cls_MoniTool_CaseData.def("AddXY", [](MoniTool_CaseData &self, const gp_XY & a0) -> void { return self.AddXY(a0); });
cls_MoniTool_CaseData.def("AddXY", (void (MoniTool_CaseData::*)(const gp_XY &, const Standard_CString)) &MoniTool_CaseData::AddXY, "Adds a XY", py::arg("aXY"), py::arg("name"));
cls_MoniTool_CaseData.def("AddReal", [](MoniTool_CaseData &self, const Standard_Real a0) -> void { return self.AddReal(a0); });
cls_MoniTool_CaseData.def("AddReal", (void (MoniTool_CaseData::*)(const Standard_Real, const Standard_CString)) &MoniTool_CaseData::AddReal, "Adds a Real", py::arg("val"), py::arg("name"));
cls_MoniTool_CaseData.def("AddReals", [](MoniTool_CaseData &self, const Standard_Real a0, const Standard_Real a1) -> void { return self.AddReals(a0, a1); });
cls_MoniTool_CaseData.def("AddReals", (void (MoniTool_CaseData::*)(const Standard_Real, const Standard_Real, const Standard_CString)) &MoniTool_CaseData::AddReals, "Adds two reals (for instance, two parameters)", py::arg("v1"), py::arg("v2"), py::arg("name"));
cls_MoniTool_CaseData.def("AddCPU", [](MoniTool_CaseData &self, const Standard_Real a0) -> void { return self.AddCPU(a0); });
cls_MoniTool_CaseData.def("AddCPU", [](MoniTool_CaseData &self, const Standard_Real a0, const Standard_Real a1) -> void { return self.AddCPU(a0, a1); });
cls_MoniTool_CaseData.def("AddCPU", (void (MoniTool_CaseData::*)(const Standard_Real, const Standard_Real, const Standard_CString)) &MoniTool_CaseData::AddCPU, "Adds the CPU time between lastCPU and now if <curCPU> is given, the CPU amount is curCPU-lastCPU else it is currently measured CPU - lastCPU lastCPU has been read by call to GetCPU See GetCPU to get amount, and LargeCPU to test large amount", py::arg("lastCPU"), py::arg("curCPU"), py::arg("name"));
cls_MoniTool_CaseData.def("GetCPU", (Standard_Real (MoniTool_CaseData::*)() const) &MoniTool_CaseData::GetCPU, "Returns the current amount of CPU This allows to laterly test and record CPU amount Its value has to be given to LargeCPU and AddCPU");
cls_MoniTool_CaseData.def("LargeCPU", [](MoniTool_CaseData &self, const Standard_Real a0, const Standard_Real a1) -> Standard_Boolean { return self.LargeCPU(a0, a1); });
cls_MoniTool_CaseData.def("LargeCPU", (Standard_Boolean (MoniTool_CaseData::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &MoniTool_CaseData::LargeCPU, "Tells if a CPU time amount is large <maxCPU> gives the amount over which an amount is large <lastCPU> gives the start CPU amount if <curCPU> is given, the tested CPU amount is curCPU-lastCPU else it is currently measured CPU - lastCPU", py::arg("maxCPU"), py::arg("lastCPU"), py::arg("curCPU"));
cls_MoniTool_CaseData.def("AddGeom", [](MoniTool_CaseData &self, const opencascade::handle<Standard_Transient> & a0) -> void { return self.AddGeom(a0); });
cls_MoniTool_CaseData.def("AddGeom", (void (MoniTool_CaseData::*)(const opencascade::handle<Standard_Transient> &, const Standard_CString)) &MoniTool_CaseData::AddGeom, "Adds a Geometric as a Transient (Curve, Surface ...)", py::arg("geom"), py::arg("name"));
cls_MoniTool_CaseData.def("AddEntity", [](MoniTool_CaseData &self, const opencascade::handle<Standard_Transient> & a0) -> void { return self.AddEntity(a0); });
cls_MoniTool_CaseData.def("AddEntity", (void (MoniTool_CaseData::*)(const opencascade::handle<Standard_Transient> &, const Standard_CString)) &MoniTool_CaseData::AddEntity, "Adds a Transient, as an Entity from an InterfaceModel for instance : it will then be printed with the help of a DBPE", py::arg("ent"), py::arg("name"));
cls_MoniTool_CaseData.def("AddText", [](MoniTool_CaseData &self, const Standard_CString a0) -> void { return self.AddText(a0); });
cls_MoniTool_CaseData.def("AddText", (void (MoniTool_CaseData::*)(const Standard_CString, const Standard_CString)) &MoniTool_CaseData::AddText, "Adds a Text (as HAsciiString)", py::arg("text"), py::arg("name"));
cls_MoniTool_CaseData.def("AddInteger", [](MoniTool_CaseData &self, const Standard_Integer a0) -> void { return self.AddInteger(a0); });
cls_MoniTool_CaseData.def("AddInteger", (void (MoniTool_CaseData::*)(const Standard_Integer, const Standard_CString)) &MoniTool_CaseData::AddInteger, "Adds an Integer", py::arg("val"), py::arg("name"));
cls_MoniTool_CaseData.def("AddAny", [](MoniTool_CaseData &self, const opencascade::handle<Standard_Transient> & a0) -> void { return self.AddAny(a0); });
cls_MoniTool_CaseData.def("AddAny", (void (MoniTool_CaseData::*)(const opencascade::handle<Standard_Transient> &, const Standard_CString)) &MoniTool_CaseData::AddAny, "Adds a Transient, with no more meaning", py::arg("val"), py::arg("name"));
cls_MoniTool_CaseData.def("RemoveData", (void (MoniTool_CaseData::*)(const Standard_Integer)) &MoniTool_CaseData::RemoveData, "Removes a Data from its rank. Does nothing if out of range", py::arg("num"));
cls_MoniTool_CaseData.def("NbData", (Standard_Integer (MoniTool_CaseData::*)() const) &MoniTool_CaseData::NbData, "Returns the count of data recorded to a set");
cls_MoniTool_CaseData.def("Data", (opencascade::handle<Standard_Transient> (MoniTool_CaseData::*)(const Standard_Integer) const) &MoniTool_CaseData::Data, "Returns a data item (n0 <nd> in the set <num>)", py::arg("nd"));
cls_MoniTool_CaseData.def("GetData", (Standard_Boolean (MoniTool_CaseData::*)(const Standard_Integer, const opencascade::handle<Standard_Type> &, opencascade::handle<Standard_Transient> &) const) &MoniTool_CaseData::GetData, "Returns a data item, under control of a Type If the data item is kind of this type, it is returned in <val> and the returned value is True Else, <val> is unchanged and the returned value is False", py::arg("nd"), py::arg("type"), py::arg("val"));
cls_MoniTool_CaseData.def("Kind", (Standard_Integer (MoniTool_CaseData::*)(const Standard_Integer) const) &MoniTool_CaseData::Kind, "Returns the kind of a data : KIND TYPE MEANING 0 ANY any (not one of the followings) 1 EX raised exception 2 EN entity 3 G geom 4 SH shape 5 XYZ XYZ 6 XY or UV XY 7 RR 2 reals 8 R 1 real 9 CPU CPU (1 real) 10 T text 11 I integer", py::arg("nd"));
cls_MoniTool_CaseData.def("Name", (const TCollection_AsciiString & (MoniTool_CaseData::*)(const Standard_Integer) const) &MoniTool_CaseData::Name, "Returns the name of a data. If it has no name, the string is empty (length = 0)", py::arg("nd"));
cls_MoniTool_CaseData.def("NameNum", (Standard_Integer (MoniTool_CaseData::*)(const Standard_CString) const) &MoniTool_CaseData::NameNum, "Returns the first suitable data rank for a given name Exact maching (exact case, no completion) is required Firstly checks the recorded names If not found, considers the name as follows : Name = 'TYPE' : search for the first item with this TYPE Name = 'TYPE:nn' : search for the nn.th item with this TYPE See allowed values in method Kind", py::arg("name"));
cls_MoniTool_CaseData.def("Shape", (TopoDS_Shape (MoniTool_CaseData::*)(const Standard_Integer) const) &MoniTool_CaseData::Shape, "Returns a data as a shape, Null if not a shape", py::arg("nd"));
cls_MoniTool_CaseData.def("XYZ", (Standard_Boolean (MoniTool_CaseData::*)(const Standard_Integer, gp_XYZ &) const) &MoniTool_CaseData::XYZ, "Returns a data as a XYZ (i.e. Geom_CartesianPoint) Returns False if not the good type", py::arg("nd"), py::arg("val"));
cls_MoniTool_CaseData.def("XY", (Standard_Boolean (MoniTool_CaseData::*)(const Standard_Integer, gp_XY &) const) &MoniTool_CaseData::XY, "Returns a data as a XY (i.e. Geom2d_CartesianPoint) Returns False if not the good type", py::arg("nd"), py::arg("val"));
cls_MoniTool_CaseData.def("Reals", [](MoniTool_CaseData &self, const Standard_Integer nd, Standard_Real & v1, Standard_Real & v2){ Standard_Boolean rv = self.Reals(nd, v1, v2); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, v1, v2); }, "Returns a couple of reals (stored in Geom2d_CartesianPoint)", py::arg("nd"), py::arg("v1"), py::arg("v2"));
cls_MoniTool_CaseData.def("Real", [](MoniTool_CaseData &self, const Standard_Integer nd, Standard_Real & val){ Standard_Boolean rv = self.Real(nd, val); return std::tuple<Standard_Boolean, Standard_Real &>(rv, val); }, "Returns a real or CPU amount (stored in Geom2d_CartesianPoint) (allows an Integer converted to a Real)", py::arg("nd"), py::arg("val"));
// cls_MoniTool_CaseData.def("Text", [](MoniTool_CaseData &self, const Standard_Integer nd, Standard_CString & text){ Standard_Boolean rv = self.Text(nd, text); return std::tuple<Standard_Boolean, Standard_CString &>(rv, text); }, "Returns a text (stored in TCollection_HAsciiString)", py::arg("nd"), py::arg("text"));
cls_MoniTool_CaseData.def("Integer", [](MoniTool_CaseData &self, const Standard_Integer nd, Standard_Integer & val){ Standard_Boolean rv = self.Integer(nd, val); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, val); }, "Returns an Integer", py::arg("nd"), py::arg("val"));
cls_MoniTool_CaseData.def("Msg", (Message_Msg (MoniTool_CaseData::*)() const) &MoniTool_CaseData::Msg, "Returns a Msg from a CaseData : it is build from DefMsg, which gives the message code plus the designation of items of the CaseData to be added to the Msg Empty if no message attached");
cls_MoniTool_CaseData.def_static("SetDefWarning_", (void (*)(const Standard_CString)) &MoniTool_CaseData::SetDefWarning, "Sets a Code to give a Warning", py::arg("acode"));
cls_MoniTool_CaseData.def_static("SetDefFail_", (void (*)(const Standard_CString)) &MoniTool_CaseData::SetDefFail, "Sets a Code to give a Fail", py::arg("acode"));
cls_MoniTool_CaseData.def_static("DefCheck_", (Standard_Integer (*)(const Standard_CString)) &MoniTool_CaseData::DefCheck, "Returns Check Status for a Code : 0 non/info (default), 1 warning, 2 fail", py::arg("acode"));
cls_MoniTool_CaseData.def_static("SetDefMsg_", (void (*)(const Standard_CString, const Standard_CString)) &MoniTool_CaseData::SetDefMsg, "Attaches a message definition to a case code This definition includes the message code plus designation of items of the CaseData to be added to the message (this part not yet implemented)", py::arg("casecode"), py::arg("mesdef"));
cls_MoniTool_CaseData.def_static("DefMsg_", (Standard_CString (*)(const Standard_CString)) &MoniTool_CaseData::DefMsg, "Returns the message definition for a case code Empty if no message attached", py::arg("casecode"));
cls_MoniTool_CaseData.def_static("get_type_name_", (const char * (*)()) &MoniTool_CaseData::get_type_name, "None");
cls_MoniTool_CaseData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MoniTool_CaseData::get_type_descriptor, "None");
cls_MoniTool_CaseData.def("DynamicType", (const opencascade::handle<Standard_Type> & (MoniTool_CaseData::*)() const) &MoniTool_CaseData::DynamicType, "None");

// Enums

}