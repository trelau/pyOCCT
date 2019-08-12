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
#include <Standard_Handle.hxx>
#include <TColStd_HSequenceOfHAsciiString.hxx>
#include <IFSelect_ContextWrite.hxx>
#include <IGESData_IGESWriter.hxx>
#include <TCollection_AsciiString.hxx>
#include <IGESSelect_AddFileComment.hxx>
#include <Standard_Type.hxx>

void bind_IGESSelect_AddFileComment(py::module &mod){

py::class_<IGESSelect_AddFileComment, opencascade::handle<IGESSelect_AddFileComment>, IGESSelect_FileModifier> cls_IGESSelect_AddFileComment(mod, "IGESSelect_AddFileComment", "This class allows to add comment lines on writing an IGES File These lines are added to Start Section, instead of the only one blank line written by default.");

// Constructors
cls_IGESSelect_AddFileComment.def(py::init<>());

// Fields

// Methods
cls_IGESSelect_AddFileComment.def("Clear", (void (IGESSelect_AddFileComment::*)()) &IGESSelect_AddFileComment::Clear, "Clears the list of file comment lines already stored");
cls_IGESSelect_AddFileComment.def("AddLine", (void (IGESSelect_AddFileComment::*)(const Standard_CString)) &IGESSelect_AddFileComment::AddLine, "Adds a line for file comment Remark : Lines are limited to 72 useful char.s . A line of more than 72 char.s will be splited into several ones of 72 max each.", py::arg("line"));
cls_IGESSelect_AddFileComment.def("AddLines", (void (IGESSelect_AddFileComment::*)(const opencascade::handle<TColStd_HSequenceOfHAsciiString> &)) &IGESSelect_AddFileComment::AddLines, "Adds a list of lines for file comment Each of them must comply with demand of AddLine", py::arg("lines"));
cls_IGESSelect_AddFileComment.def("NbLines", (Standard_Integer (IGESSelect_AddFileComment::*)() const) &IGESSelect_AddFileComment::NbLines, "Returns the count of stored lines");
cls_IGESSelect_AddFileComment.def("Line", (Standard_CString (IGESSelect_AddFileComment::*)(const Standard_Integer) const) &IGESSelect_AddFileComment::Line, "Returns a stored line given its rank", py::arg("num"));
cls_IGESSelect_AddFileComment.def("Lines", (opencascade::handle<TColStd_HSequenceOfHAsciiString> (IGESSelect_AddFileComment::*)() const) &IGESSelect_AddFileComment::Lines, "Returns the complete list of lines in once");
cls_IGESSelect_AddFileComment.def("Perform", (void (IGESSelect_AddFileComment::*)(IFSelect_ContextWrite &, IGESData_IGESWriter &) const) &IGESSelect_AddFileComment::Perform, "Sends the comment lines to the file (Start Section)", py::arg("ctx"), py::arg("writer"));
cls_IGESSelect_AddFileComment.def("Label", (TCollection_AsciiString (IGESSelect_AddFileComment::*)() const) &IGESSelect_AddFileComment::Label, "Returns specific Label, which is 'Add <nn> Comment Lines (Start Section)'");
cls_IGESSelect_AddFileComment.def_static("get_type_name_", (const char * (*)()) &IGESSelect_AddFileComment::get_type_name, "None");
cls_IGESSelect_AddFileComment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_AddFileComment::get_type_descriptor, "None");
cls_IGESSelect_AddFileComment.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_AddFileComment::*)() const) &IGESSelect_AddFileComment::DynamicType, "None");

// Enums

}