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
#include <Standard_TypeDef.hxx>
#include <IGESData_ParamCursor.hxx>

void bind_IGESData_ParamCursor(py::module &mod){

py::class_<IGESData_ParamCursor, std::unique_ptr<IGESData_ParamCursor>> cls_IGESData_ParamCursor(mod, "IGESData_ParamCursor", "Auxiliary class for ParamReader. It stores commands for a ParamReader to manage the current parameter number. Used by methods Read... from ParamReader. It allows to define the following commands : - read a parameter specified by a precise Number (basic case) - read a parameter then set Current Number to follow its number - read the current parameter (with Current Number) then advance Current Number by one - idem with several : read 'nb' parameters from one specified, included, with or without setting Current Number to follow last parameter read - read several parameter from the current one, then advance Current Number to follow the last one read - Read several parameters (as above) but in interlaced lists, i.e. from complex items (each one including successively for instance, an Integer, a Real, an Entity ...)");

// Constructors
cls_IGESData_ParamCursor.def(py::init<const Standard_Integer>(), py::arg("num"));
cls_IGESData_ParamCursor.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("num"), py::arg("nb"));
cls_IGESData_ParamCursor.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("num"), py::arg("nb"), py::arg("size"));

// Fields

// Methods
// cls_IGESData_ParamCursor.def_static("operator new_", (void * (*)(size_t)) &IGESData_ParamCursor::operator new, "None", py::arg("theSize"));
// cls_IGESData_ParamCursor.def_static("operator delete_", (void (*)(void *)) &IGESData_ParamCursor::operator delete, "None", py::arg("theAddress"));
// cls_IGESData_ParamCursor.def_static("operator new[]_", (void * (*)(size_t)) &IGESData_ParamCursor::operator new[], "None", py::arg("theSize"));
// cls_IGESData_ParamCursor.def_static("operator delete[]_", (void (*)(void *)) &IGESData_ParamCursor::operator delete[], "None", py::arg("theAddress"));
// cls_IGESData_ParamCursor.def_static("operator new_", (void * (*)(size_t, void *)) &IGESData_ParamCursor::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESData_ParamCursor.def_static("operator delete_", (void (*)(void *, void *)) &IGESData_ParamCursor::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESData_ParamCursor.def("SetTerm", [](IGESData_ParamCursor &self, const Standard_Integer a0) -> void { return self.SetTerm(a0); });
cls_IGESData_ParamCursor.def("SetTerm", (void (IGESData_ParamCursor::*)(const Standard_Integer, const Standard_Boolean)) &IGESData_ParamCursor::SetTerm, "Defines the size of a term to read in the item : this commands ParamReader to read 'size' parameters for each item, then skip the remainder of the item to the same term of next Item (that is, skip 'item size' - 'term size')", py::arg("size"), py::arg("autoadv"));
cls_IGESData_ParamCursor.def("SetOne", [](IGESData_ParamCursor &self) -> void { return self.SetOne(); });
cls_IGESData_ParamCursor.def("SetOne", (void (IGESData_ParamCursor::*)(const Standard_Boolean)) &IGESData_ParamCursor::SetOne, "Defines a term of one Parameter (very current case)", py::arg("autoadv"));
cls_IGESData_ParamCursor.def("SetXY", [](IGESData_ParamCursor &self) -> void { return self.SetXY(); });
cls_IGESData_ParamCursor.def("SetXY", (void (IGESData_ParamCursor::*)(const Standard_Boolean)) &IGESData_ParamCursor::SetXY, "Defines a term of two Parameters for a XY (current case)", py::arg("autoadv"));
cls_IGESData_ParamCursor.def("SetXYZ", [](IGESData_ParamCursor &self) -> void { return self.SetXYZ(); });
cls_IGESData_ParamCursor.def("SetXYZ", (void (IGESData_ParamCursor::*)(const Standard_Boolean)) &IGESData_ParamCursor::SetXYZ, "Defines a term of three Parameters for XYZ (current case)", py::arg("autoadv"));
cls_IGESData_ParamCursor.def("SetAdvance", (void (IGESData_ParamCursor::*)(const Standard_Boolean)) &IGESData_ParamCursor::SetAdvance, "Changes command to advance current cursor after reading parameters. If 'advance' True, sets advance, if 'False', resets it. ParamCursor is created by default with True.", py::arg("advance"));
cls_IGESData_ParamCursor.def("Start", (Standard_Integer (IGESData_ParamCursor::*)() const) &IGESData_ParamCursor::Start, "Returns (included) starting number for reading parameters");
cls_IGESData_ParamCursor.def("Limit", (Standard_Integer (IGESData_ParamCursor::*)() const) &IGESData_ParamCursor::Limit, "Returns (excluded) upper limit number for reading parameters");
cls_IGESData_ParamCursor.def("Count", (Standard_Integer (IGESData_ParamCursor::*)() const) &IGESData_ParamCursor::Count, "Returns required count of items to be read");
cls_IGESData_ParamCursor.def("ItemSize", (Standard_Integer (IGESData_ParamCursor::*)() const) &IGESData_ParamCursor::ItemSize, "Returns length of item (count of parameters per item)");
cls_IGESData_ParamCursor.def("TermSize", (Standard_Integer (IGESData_ParamCursor::*)() const) &IGESData_ParamCursor::TermSize, "Returns length of current term (count of parameters) in item");
cls_IGESData_ParamCursor.def("Offset", (Standard_Integer (IGESData_ParamCursor::*)() const) &IGESData_ParamCursor::Offset, "Returns offset from which current term must be read in item");
cls_IGESData_ParamCursor.def("Advance", (Standard_Boolean (IGESData_ParamCursor::*)() const) &IGESData_ParamCursor::Advance, "Returns True if Advance command has been set");

// Enums

}