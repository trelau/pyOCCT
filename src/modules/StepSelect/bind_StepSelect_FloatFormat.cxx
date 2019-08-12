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
#include <StepSelect_FileModifier.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_AsciiString.hxx>
#include <IFSelect_ContextWrite.hxx>
#include <StepData_StepWriter.hxx>
#include <Standard_Handle.hxx>
#include <StepSelect_FloatFormat.hxx>
#include <Standard_Type.hxx>

void bind_StepSelect_FloatFormat(py::module &mod){

py::class_<StepSelect_FloatFormat, opencascade::handle<StepSelect_FloatFormat>, StepSelect_FileModifier> cls_StepSelect_FloatFormat(mod, "StepSelect_FloatFormat", "This class gives control out format for floatting values : ZeroSuppress or no, Main Format, Format in Range (for values around 1.), as StepWriter allows to manage it. Formats are given under C-printf form");

// Constructors
cls_StepSelect_FloatFormat.def(py::init<>());

// Fields

// Methods
cls_StepSelect_FloatFormat.def("SetDefault", [](StepSelect_FloatFormat &self) -> void { return self.SetDefault(); });
cls_StepSelect_FloatFormat.def("SetDefault", (void (StepSelect_FloatFormat::*)(const Standard_Integer)) &StepSelect_FloatFormat::SetDefault, "Sets FloatFormat to default value (see Create) but if <digits> is given positive, it commands Formats (main and range) to ensure <digits> significant digits to be displayed", py::arg("digits"));
cls_StepSelect_FloatFormat.def("SetZeroSuppress", (void (StepSelect_FloatFormat::*)(const Standard_Boolean)) &StepSelect_FloatFormat::SetZeroSuppress, "Sets ZeroSuppress mode to a new value", py::arg("mode"));
cls_StepSelect_FloatFormat.def("SetFormat", [](StepSelect_FloatFormat &self) -> void { return self.SetFormat(); });
cls_StepSelect_FloatFormat.def("SetFormat", (void (StepSelect_FloatFormat::*)(const Standard_CString)) &StepSelect_FloatFormat::SetFormat, "Sets Main Format to a new value Remark : SetFormat, SetZeroSuppress and SetFormatForRange are independant", py::arg("format"));
cls_StepSelect_FloatFormat.def("SetFormatForRange", [](StepSelect_FloatFormat &self) -> void { return self.SetFormatForRange(); });
cls_StepSelect_FloatFormat.def("SetFormatForRange", [](StepSelect_FloatFormat &self, const Standard_CString a0) -> void { return self.SetFormatForRange(a0); });
cls_StepSelect_FloatFormat.def("SetFormatForRange", [](StepSelect_FloatFormat &self, const Standard_CString a0, const Standard_Real a1) -> void { return self.SetFormatForRange(a0, a1); });
cls_StepSelect_FloatFormat.def("SetFormatForRange", (void (StepSelect_FloatFormat::*)(const Standard_CString, const Standard_Real, const Standard_Real)) &StepSelect_FloatFormat::SetFormatForRange, "Sets Format for Range to a new value with its range of application. To cancel it, give format as '' (empty string) Remark that if the condition (0. < Rmin < Rmax) is not verified, this secondary format will be ignored. Moreover, this secondary format is intended to be used in a range around 1.", py::arg("format"), py::arg("Rmin"), py::arg("Rmax"));
cls_StepSelect_FloatFormat.def("Format", [](StepSelect_FloatFormat &self, Standard_Boolean & zerosup, TCollection_AsciiString & mainform, Standard_Boolean & hasrange, TCollection_AsciiString & forminrange, Standard_Real & rangemin, Standard_Real & rangemax){ self.Format(zerosup, mainform, hasrange, forminrange, rangemin, rangemax); return std::tuple<Standard_Boolean &, Standard_Boolean &, Standard_Real &, Standard_Real &>(zerosup, hasrange, rangemin, rangemax); }, "Returns all recorded parameters : zerosup : ZeroSuppress status mainform : Main Format (which applies out of the range, or for every real if no range is set) hasrange : True if a FormatInRange is set, False else (following parameters do not apply if it is False) forminrange : Secondary Format (it applies inside the range) rangemin, rangemax : the range in which the secondary format applies", py::arg("zerosup"), py::arg("mainform"), py::arg("hasrange"), py::arg("forminrange"), py::arg("rangemin"), py::arg("rangemax"));
cls_StepSelect_FloatFormat.def("Perform", (void (StepSelect_FloatFormat::*)(IFSelect_ContextWrite &, StepData_StepWriter &) const) &StepSelect_FloatFormat::Perform, "Sets the Floatting Formats of StepWriter to the recorded parameters", py::arg("ctx"), py::arg("writer"));
cls_StepSelect_FloatFormat.def("Label", (TCollection_AsciiString (StepSelect_FloatFormat::*)() const) &StepSelect_FloatFormat::Label, "Returns specific Label : for instance, 'Float Format [ZeroSuppress] %E [, in range R1-R2 %f]'");
cls_StepSelect_FloatFormat.def_static("get_type_name_", (const char * (*)()) &StepSelect_FloatFormat::get_type_name, "None");
cls_StepSelect_FloatFormat.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepSelect_FloatFormat::get_type_descriptor, "None");
cls_StepSelect_FloatFormat.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepSelect_FloatFormat::*)() const) &StepSelect_FloatFormat::DynamicType, "None");

// Enums

}