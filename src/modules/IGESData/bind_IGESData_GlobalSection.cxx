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
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Interface_ParamSet.hxx>
#include <Interface_Check.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_XYZ.hxx>
#include <IGESData_GlobalSection.hxx>

void bind_IGESData_GlobalSection(py::module &mod){

py::class_<IGESData_GlobalSection> cls_IGESData_GlobalSection(mod, "IGESData_GlobalSection", "Description of a global section (corresponds to file header) used as well in IGESModel, IGESReader and IGESWriter Warning : From IGES-5.1, a parameter is added : LastChangeDate (concerns transferred set of data, not the file itself) Of course, it can be absent if read from earlier versions (a default is then to be set to current date) From 5.3, one more : ApplicationProtocol (optional)");

// Constructors
cls_IGESData_GlobalSection.def(py::init<>());

// Fields

// Methods
// cls_IGESData_GlobalSection.def_static("operator new_", (void * (*)(size_t)) &IGESData_GlobalSection::operator new, "None", py::arg("theSize"));
// cls_IGESData_GlobalSection.def_static("operator delete_", (void (*)(void *)) &IGESData_GlobalSection::operator delete, "None", py::arg("theAddress"));
// cls_IGESData_GlobalSection.def_static("operator new[]_", (void * (*)(size_t)) &IGESData_GlobalSection::operator new[], "None", py::arg("theSize"));
// cls_IGESData_GlobalSection.def_static("operator delete[]_", (void (*)(void *)) &IGESData_GlobalSection::operator delete[], "None", py::arg("theAddress"));
// cls_IGESData_GlobalSection.def_static("operator new_", (void * (*)(size_t, void *)) &IGESData_GlobalSection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESData_GlobalSection.def_static("operator delete_", (void (*)(void *, void *)) &IGESData_GlobalSection::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESData_GlobalSection.def("Init", (void (IGESData_GlobalSection::*)(const opencascade::handle<Interface_ParamSet> &, opencascade::handle<Interface_Check> &)) &IGESData_GlobalSection::Init, "Fills GlobalSection from a ParamSet (i.e. taken from file) undefined parameters do not change default values when defined Fills Check about Corrections or Fails", py::arg("params"), py::arg("ach"));
cls_IGESData_GlobalSection.def("CopyRefs", (void (IGESData_GlobalSection::*)()) &IGESData_GlobalSection::CopyRefs, "Copies data referenced by Handle (that is, Strings) usefull to 'isolate' a GlobalSection after copy by '=' (from a Model to another Model for instance)");
cls_IGESData_GlobalSection.def("Params", (opencascade::handle<Interface_ParamSet> (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::Params, "Returns all contained data in the form of a ParamSet Remark : Strings are given under Hollerith form");
cls_IGESData_GlobalSection.def("TranslatedFromHollerith", (opencascade::handle<TCollection_HAsciiString> (IGESData_GlobalSection::*)(const opencascade::handle<TCollection_HAsciiString> &) const) &IGESData_GlobalSection::TranslatedFromHollerith, "Returns a string withpout its Hollerith marks (nnnH ahead). Remark : all strings stored in GlobalSection are expurged from Hollerith informations (without nnnH) If <astr> is not Hollerith form, it is simply copied", py::arg("astr"));
cls_IGESData_GlobalSection.def("Separator", (Standard_Character (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::Separator, "Returns the parameter delimiter character.");
cls_IGESData_GlobalSection.def("EndMark", (Standard_Character (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::EndMark, "Returns the record delimiter character.");
cls_IGESData_GlobalSection.def("SendName", (opencascade::handle<TCollection_HAsciiString> (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::SendName, "Returns the name of the sending system.");
cls_IGESData_GlobalSection.def("FileName", (opencascade::handle<TCollection_HAsciiString> (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::FileName, "Returns the name of the IGES file.");
cls_IGESData_GlobalSection.def("SystemId", (opencascade::handle<TCollection_HAsciiString> (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::SystemId, "Returns the Native System ID of the system that created the IGES file.");
cls_IGESData_GlobalSection.def("InterfaceVersion", (opencascade::handle<TCollection_HAsciiString> (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::InterfaceVersion, "Returns the name of the pre-processor used to write the IGES file.");
cls_IGESData_GlobalSection.def("IntegerBits", (Standard_Integer (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::IntegerBits, "Returns the number of binary bits for integer representations.");
cls_IGESData_GlobalSection.def("MaxPower10Single", (Standard_Integer (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::MaxPower10Single, "Returns the maximum power of a decimal representation of a single-precision floating point number in the sending system.");
cls_IGESData_GlobalSection.def("MaxDigitsSingle", (Standard_Integer (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::MaxDigitsSingle, "None");
cls_IGESData_GlobalSection.def("MaxPower10Double", (Standard_Integer (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::MaxPower10Double, "Returns the maximum power of a decimal representation of a double-precision floating point number in the sending system.");
cls_IGESData_GlobalSection.def("MaxDigitsDouble", (Standard_Integer (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::MaxDigitsDouble, "None");
cls_IGESData_GlobalSection.def("ReceiveName", (opencascade::handle<TCollection_HAsciiString> (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::ReceiveName, "Returns the name of the receiving system.");
cls_IGESData_GlobalSection.def("Scale", (Standard_Real (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::Scale, "Returns the scale used in the IGES file.");
cls_IGESData_GlobalSection.def("UnitFlag", (Standard_Integer (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::UnitFlag, "Returns the unit flag that was used to write the IGES file.");
cls_IGESData_GlobalSection.def("UnitName", (opencascade::handle<TCollection_HAsciiString> (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::UnitName, "Returns the name of the unit the IGES file was written in.");
cls_IGESData_GlobalSection.def("LineWeightGrad", (Standard_Integer (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::LineWeightGrad, "Returns the maximum number of line weight gradations.");
cls_IGESData_GlobalSection.def("MaxLineWeight", (Standard_Real (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::MaxLineWeight, "Returns the of maximum line weight width in IGES file units.");
cls_IGESData_GlobalSection.def("Date", (opencascade::handle<TCollection_HAsciiString> (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::Date, "Returns the IGES file creation date.");
cls_IGESData_GlobalSection.def("Resolution", (Standard_Real (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::Resolution, "Returns the resolution used in the IGES file.");
cls_IGESData_GlobalSection.def("MaxCoord", (Standard_Real (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::MaxCoord, "Returns the approximate maximum coordinate value found in the model.");
cls_IGESData_GlobalSection.def("HasMaxCoord", (Standard_Boolean (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::HasMaxCoord, "Returns True if the approximate maximum coordinate value found in the model is greater than 0.");
cls_IGESData_GlobalSection.def("AuthorName", (opencascade::handle<TCollection_HAsciiString> (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::AuthorName, "Returns the name of the IGES file author.");
cls_IGESData_GlobalSection.def("CompanyName", (opencascade::handle<TCollection_HAsciiString> (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::CompanyName, "Returns the name of the company where the IGES file was written.");
cls_IGESData_GlobalSection.def("IGESVersion", (Standard_Integer (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::IGESVersion, "Returns the IGES version that the IGES file was written in.");
cls_IGESData_GlobalSection.def("DraftingStandard", (Standard_Integer (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::DraftingStandard, "None");
cls_IGESData_GlobalSection.def("LastChangeDate", (opencascade::handle<TCollection_HAsciiString> (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::LastChangeDate, "Returns the date and time when the model was created or last modified (for IGES 5.1 and later).");
cls_IGESData_GlobalSection.def("HasLastChangeDate", (Standard_Boolean (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::HasLastChangeDate, "Returns True if the date and time when the model was created or last modified are specified, i.e. not defaulted to NULL.");
cls_IGESData_GlobalSection.def("SetLastChangeDate", (void (IGESData_GlobalSection::*)()) &IGESData_GlobalSection::SetLastChangeDate, "None");
cls_IGESData_GlobalSection.def("ApplicationProtocol", (opencascade::handle<TCollection_HAsciiString> (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::ApplicationProtocol, "None");
cls_IGESData_GlobalSection.def("HasApplicationProtocol", (Standard_Boolean (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::HasApplicationProtocol, "None");
cls_IGESData_GlobalSection.def_static("NewDateString_", [](const Standard_Integer a0, const Standard_Integer a1, const Standard_Integer a2, const Standard_Integer a3, const Standard_Integer a4, const Standard_Integer a5) -> opencascade::handle<TCollection_HAsciiString> { return IGESData_GlobalSection::NewDateString(a0, a1, a2, a3, a4, a5); });
cls_IGESData_GlobalSection.def_static("NewDateString_", (opencascade::handle<TCollection_HAsciiString> (*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &IGESData_GlobalSection::NewDateString, "Returns a string built from year, month, day, hour, minute and second values. The form of the resulting string is defined as follows: - -1: YYMMDD.HHNNSS, - 0: YYYYMMDD.HHNNSS, - 1: YYYY-MM-DD:HH-NN-SS, where: - YYYY or YY is 4 or 2 digit year, - HH is hour (00-23), - MM is month (01-12), - NN is minute (00-59) - DD is day (01-31), - SS is second (00-59).", py::arg("year"), py::arg("month"), py::arg("day"), py::arg("hour"), py::arg("minut"), py::arg("second"), py::arg("mode"));
cls_IGESData_GlobalSection.def_static("NewDateString_", [](const opencascade::handle<TCollection_HAsciiString> & a0) -> opencascade::handle<TCollection_HAsciiString> { return IGESData_GlobalSection::NewDateString(a0); });
cls_IGESData_GlobalSection.def_static("NewDateString_", (opencascade::handle<TCollection_HAsciiString> (*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer)) &IGESData_GlobalSection::NewDateString, "Converts the string given in the form YYMMDD.HHNNSS or YYYYMMDD.HHNNSS to either YYMMDD.HHNNSS, YYYYMMDD.HHNNSS or YYYY-MM-DD:HH-NN-SS.", py::arg("date"), py::arg("mode"));
cls_IGESData_GlobalSection.def("UnitValue", (Standard_Real (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::UnitValue, "Returns the unit value (in meters) that the IGES file was written in.");
cls_IGESData_GlobalSection.def("SetSeparator", (void (IGESData_GlobalSection::*)(const Standard_Character)) &IGESData_GlobalSection::SetSeparator, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetEndMark", (void (IGESData_GlobalSection::*)(const Standard_Character)) &IGESData_GlobalSection::SetEndMark, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetSendName", (void (IGESData_GlobalSection::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IGESData_GlobalSection::SetSendName, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetFileName", (void (IGESData_GlobalSection::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IGESData_GlobalSection::SetFileName, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetSystemId", (void (IGESData_GlobalSection::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IGESData_GlobalSection::SetSystemId, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetInterfaceVersion", (void (IGESData_GlobalSection::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IGESData_GlobalSection::SetInterfaceVersion, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetIntegerBits", (void (IGESData_GlobalSection::*)(const Standard_Integer)) &IGESData_GlobalSection::SetIntegerBits, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetMaxPower10Single", (void (IGESData_GlobalSection::*)(const Standard_Integer)) &IGESData_GlobalSection::SetMaxPower10Single, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetMaxDigitsSingle", (void (IGESData_GlobalSection::*)(const Standard_Integer)) &IGESData_GlobalSection::SetMaxDigitsSingle, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetMaxPower10Double", (void (IGESData_GlobalSection::*)(const Standard_Integer)) &IGESData_GlobalSection::SetMaxPower10Double, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetMaxDigitsDouble", (void (IGESData_GlobalSection::*)(const Standard_Integer)) &IGESData_GlobalSection::SetMaxDigitsDouble, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetReceiveName", (void (IGESData_GlobalSection::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IGESData_GlobalSection::SetReceiveName, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetScale", (void (IGESData_GlobalSection::*)(const Standard_Real)) &IGESData_GlobalSection::SetScale, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetUnitFlag", (void (IGESData_GlobalSection::*)(const Standard_Integer)) &IGESData_GlobalSection::SetUnitFlag, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetUnitName", (void (IGESData_GlobalSection::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IGESData_GlobalSection::SetUnitName, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetLineWeightGrad", (void (IGESData_GlobalSection::*)(const Standard_Integer)) &IGESData_GlobalSection::SetLineWeightGrad, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetMaxLineWeight", (void (IGESData_GlobalSection::*)(const Standard_Real)) &IGESData_GlobalSection::SetMaxLineWeight, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetDate", (void (IGESData_GlobalSection::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IGESData_GlobalSection::SetDate, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetResolution", (void (IGESData_GlobalSection::*)(const Standard_Real)) &IGESData_GlobalSection::SetResolution, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetMaxCoord", [](IGESData_GlobalSection &self) -> void { return self.SetMaxCoord(); });
cls_IGESData_GlobalSection.def("SetMaxCoord", (void (IGESData_GlobalSection::*)(const Standard_Real)) &IGESData_GlobalSection::SetMaxCoord, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("MaxMaxCoord", [](IGESData_GlobalSection &self) -> void { return self.MaxMaxCoord(); });
cls_IGESData_GlobalSection.def("MaxMaxCoord", (void (IGESData_GlobalSection::*)(const Standard_Real)) &IGESData_GlobalSection::MaxMaxCoord, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("MaxMaxCoords", (void (IGESData_GlobalSection::*)(const gp_XYZ &)) &IGESData_GlobalSection::MaxMaxCoords, "None", py::arg("xyz"));
cls_IGESData_GlobalSection.def("SetAuthorName", (void (IGESData_GlobalSection::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IGESData_GlobalSection::SetAuthorName, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetCompanyName", (void (IGESData_GlobalSection::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IGESData_GlobalSection::SetCompanyName, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetIGESVersion", (void (IGESData_GlobalSection::*)(const Standard_Integer)) &IGESData_GlobalSection::SetIGESVersion, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetDraftingStandard", (void (IGESData_GlobalSection::*)(const Standard_Integer)) &IGESData_GlobalSection::SetDraftingStandard, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetLastChangeDate", (void (IGESData_GlobalSection::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IGESData_GlobalSection::SetLastChangeDate, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetApplicationProtocol", (void (IGESData_GlobalSection::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IGESData_GlobalSection::SetApplicationProtocol, "None", py::arg("val"));

// Enums

}