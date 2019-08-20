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
#include <TCollection_ExtendedString.hxx>
#include <Standard_TypeDef.hxx>
#include <TDocStd_PathParser.hxx>

void bind_TDocStd_PathParser(py::module &mod){

py::class_<TDocStd_PathParser, std::unique_ptr<TDocStd_PathParser>> cls_TDocStd_PathParser(mod, "TDocStd_PathParser", "parse an OS path");

// Constructors
cls_TDocStd_PathParser.def(py::init<const TCollection_ExtendedString &>(), py::arg("path"));

// Fields

// Methods
// cls_TDocStd_PathParser.def_static("operator new_", (void * (*)(size_t)) &TDocStd_PathParser::operator new, "None", py::arg("theSize"));
// cls_TDocStd_PathParser.def_static("operator delete_", (void (*)(void *)) &TDocStd_PathParser::operator delete, "None", py::arg("theAddress"));
// cls_TDocStd_PathParser.def_static("operator new[]_", (void * (*)(size_t)) &TDocStd_PathParser::operator new[], "None", py::arg("theSize"));
// cls_TDocStd_PathParser.def_static("operator delete[]_", (void (*)(void *)) &TDocStd_PathParser::operator delete[], "None", py::arg("theAddress"));
// cls_TDocStd_PathParser.def_static("operator new_", (void * (*)(size_t, void *)) &TDocStd_PathParser::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TDocStd_PathParser.def_static("operator delete_", (void (*)(void *, void *)) &TDocStd_PathParser::operator delete, "None", py::arg(""), py::arg(""));
cls_TDocStd_PathParser.def("Parse", (void (TDocStd_PathParser::*)()) &TDocStd_PathParser::Parse, "None");
cls_TDocStd_PathParser.def("Trek", (TCollection_ExtendedString (TDocStd_PathParser::*)() const) &TDocStd_PathParser::Trek, "None");
cls_TDocStd_PathParser.def("Name", (TCollection_ExtendedString (TDocStd_PathParser::*)() const) &TDocStd_PathParser::Name, "None");
cls_TDocStd_PathParser.def("Extension", (TCollection_ExtendedString (TDocStd_PathParser::*)() const) &TDocStd_PathParser::Extension, "None");
cls_TDocStd_PathParser.def("Path", (TCollection_ExtendedString (TDocStd_PathParser::*)() const) &TDocStd_PathParser::Path, "None");
cls_TDocStd_PathParser.def("Length", (Standard_Integer (TDocStd_PathParser::*)() const) &TDocStd_PathParser::Length, "None");

// Enums

}