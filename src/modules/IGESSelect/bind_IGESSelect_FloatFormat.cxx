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
#include <IGESSelect_FileModifier.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_AsciiString.hxx>
#include <IFSelect_ContextWrite.hxx>
#include <IGESData_IGESWriter.hxx>
#include <Standard_Handle.hxx>
#include <IGESSelect_FloatFormat.hxx>
#include <Standard_Type.hxx>

void bind_IGESSelect_FloatFormat(py::module &mod){

py::class_<IGESSelect_FloatFormat, opencascade::handle<IGESSelect_FloatFormat>, IGESSelect_FileModifier> cls_IGESSelect_FloatFormat(mod, "IGESSelect_FloatFormat", "This class gives control out format for floatting values : ZeroSuppress or no, Main Format, Format in Range (for values around 1.), as IGESWriter allows to manage it. Formats are given under C-printf form");

// Constructors
cls_IGESSelect_FloatFormat.def(py::init<>());

// Fields

// Methods
cls_IGESSelect_FloatFormat.def("SetDefault", [](IGESSelect_FloatFormat &self) -> void { return self.SetDefault(); });
cls_IGESSelect_FloatFormat.def("SetDefault", (void (IGESSelect_FloatFormat::*)(const Standard_Integer)) &IGESSelect_FloatFormat::SetDefault, "Sets FloatFormat to default value (see Create) but if <digits> is given positive, it commands Formats (main and range) to ensure <digits> significant digits to be displayed", py::arg("digits"));
cls_IGESSelect_FloatFormat.def("SetZeroSuppress", (void (IGESSelect_FloatFormat::*)(const Standard_Boolean)) &IGESSelect_FloatFormat::SetZeroSuppress, "Sets ZeroSuppress mode to a new value", py::arg("mode"));
cls_IGESSelect_FloatFormat.def("SetFormat", [](IGESSelect_FloatFormat &self) -> void { return self.SetFormat(); });
cls_IGESSelect_FloatFormat.def("SetFormat", (void (IGESSelect_FloatFormat::*)(const Standard_CString)) &IGESSelect_FloatFormat::SetFormat, "Sets Main Format to a new value Remark : SetFormat, SetZeroSuppress and SetFormatForRange are independant", py::arg("format"));
cls_IGESSelect_FloatFormat.def("SetFormatForRange", [](IGESSelect_FloatFormat &self) -> void { return self.SetFormatForRange(); });
cls_IGESSelect_FloatFormat.def("SetFormatForRange", [](IGESSelect_FloatFormat &self, const Standard_CString a0) -> void { return self.SetFormatForRange(a0); });
cls_IGESSelect_FloatFormat.def("SetFormatForRange", [](IGESSelect_FloatFormat &self, const Standard_CString a0, const Standard_Real a1) -> void { return self.SetFormatForRange(a0, a1); });
cls_IGESSelect_FloatFormat.def("SetFormatForRange", (void (IGESSelect_FloatFormat::*)(const Standard_CString, const Standard_Real, const Standard_Real)) &IGESSelect_FloatFormat::SetFormatForRange, "Sets Format for Range to a new value with its range of application. To cancel it, give format as '' (empty string) Remark that if the condition (0. < Rmin < Rmax) is not verified, this secondary format will be ignored. Moreover, this secondary format is intended to be used in a range around 1.", py::arg("format"), py::arg("Rmin"), py::arg("Rmax"));
cls_IGESSelect_FloatFormat.def("Format", [](IGESSelect_FloatFormat &self, Standard_Boolean & zerosup, TCollection_AsciiString & mainform, Standard_Boolean & hasrange, TCollection_AsciiString & forminrange, Standard_Real & rangemin, Standard_Real & rangemax){ self.Format(zerosup, mainform, hasrange, forminrange, rangemin, rangemax); return std::tuple<Standard_Boolean &, Standard_Boolean &, Standard_Real &, Standard_Real &>(zerosup, hasrange, rangemin, rangemax); }, "Returns all recorded parameters : zerosup : ZeroSuppress status mainform : Main Format (which applies out of the range, or for every real if no range is set) hasrange : True if a FormatInRange is set, False else (following parameters do not apply if it is False) forminrange : Secondary Format (it applies inside the range) rangemin, rangemax : the range in which the secondary format applies", py::arg("zerosup"), py::arg("mainform"), py::arg("hasrange"), py::arg("forminrange"), py::arg("rangemin"), py::arg("rangemax"));
cls_IGESSelect_FloatFormat.def("Perform", (void (IGESSelect_FloatFormat::*)(IFSelect_ContextWrite &, IGESData_IGESWriter &) const) &IGESSelect_FloatFormat::Perform, "Sets the Floatting Formats of IGESWriter to the recorded parameters", py::arg("ctx"), py::arg("writer"));
cls_IGESSelect_FloatFormat.def("Label", (TCollection_AsciiString (IGESSelect_FloatFormat::*)() const) &IGESSelect_FloatFormat::Label, "Returns specific Label : for instance, 'Float Format [ZeroSuppress] %E [, in range R1-R2 %f]'");
cls_IGESSelect_FloatFormat.def_static("get_type_name_", (const char * (*)()) &IGESSelect_FloatFormat::get_type_name, "None");
cls_IGESSelect_FloatFormat.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_FloatFormat::get_type_descriptor, "None");
cls_IGESSelect_FloatFormat.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_FloatFormat::*)() const) &IGESSelect_FloatFormat::DynamicType, "None");

// Enums

}