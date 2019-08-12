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
#include <IGESData_LineFontEntity.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESGraph_LineFontDefPattern.hxx>
#include <Standard_Type.hxx>

void bind_IGESGraph_LineFontDefPattern(py::module &mod){

py::class_<IGESGraph_LineFontDefPattern, opencascade::handle<IGESGraph_LineFontDefPattern>, IGESData_LineFontEntity> cls_IGESGraph_LineFontDefPattern(mod, "IGESGraph_LineFontDefPattern", "defines IGESLineFontDefPattern, Type <304> Form <2> in package IGESGraph");

// Constructors
cls_IGESGraph_LineFontDefPattern.def(py::init<>());

// Fields

// Methods
cls_IGESGraph_LineFontDefPattern.def("Init", (void (IGESGraph_LineFontDefPattern::*)(const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TCollection_HAsciiString> &)) &IGESGraph_LineFontDefPattern::Init, "This method is used to set the fields of the class LineFontDefPattern - allSegLength : Containing lengths of respective segments - aPattern : HAsciiString indicating visible-blank segments", py::arg("allSegLength"), py::arg("aPattern"));
cls_IGESGraph_LineFontDefPattern.def("NbSegments", (Standard_Integer (IGESGraph_LineFontDefPattern::*)() const) &IGESGraph_LineFontDefPattern::NbSegments, "returns the number of segments in the visible-blank pattern");
cls_IGESGraph_LineFontDefPattern.def("Length", (Standard_Real (IGESGraph_LineFontDefPattern::*)(const Standard_Integer) const) &IGESGraph_LineFontDefPattern::Length, "returns the Length of Index'th segment of the basic pattern raises exception if Index <= 0 or Index > NbSegments", py::arg("Index"));
cls_IGESGraph_LineFontDefPattern.def("DisplayPattern", (opencascade::handle<TCollection_HAsciiString> (IGESGraph_LineFontDefPattern::*)() const) &IGESGraph_LineFontDefPattern::DisplayPattern, "returns the string indicating which segments of the basic pattern are visible and which are blanked. e.g: theNbSegments = 5 and if Bit Pattern = 10110, which means that segments 2, 3 and 5 are visible, whereas segments 1 and 4 are blank. The method returns '2H16' as the HAsciiString. Note: The bits are right justified. (16h = 10110)");
cls_IGESGraph_LineFontDefPattern.def("IsVisible", (Standard_Boolean (IGESGraph_LineFontDefPattern::*)(const Standard_Integer) const) &IGESGraph_LineFontDefPattern::IsVisible, "The Display Pattern is decrypted to return True if the Index'th basic pattern is Visible, False otherwise. If Index > NbSegments or Index <= 0 then return value is False.", py::arg("Index"));
cls_IGESGraph_LineFontDefPattern.def_static("get_type_name_", (const char * (*)()) &IGESGraph_LineFontDefPattern::get_type_name, "None");
cls_IGESGraph_LineFontDefPattern.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGraph_LineFontDefPattern::get_type_descriptor, "None");
cls_IGESGraph_LineFontDefPattern.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGraph_LineFontDefPattern::*)() const) &IGESGraph_LineFontDefPattern::DynamicType, "None");

// Enums

}