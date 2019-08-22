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
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Type.hxx>
#include <TColStd_HSequenceOfTransient.hxx>
#include <TCollection_HAsciiString.hxx>
#include <TCollection_AsciiString.hxx>
#include <TCollection_HExtendedString.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TColStd_HSequenceOfHAsciiString.hxx>
#include <TColStd_HSequenceOfHExtendedString.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_HSequenceOfShape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TColStd_HSequenceOfInteger.hxx>
#include <XSControl_Utils.hxx>

void bind_XSControl_Utils(py::module &mod){

py::class_<XSControl_Utils> cls_XSControl_Utils(mod, "XSControl_Utils", "This class provides various useful utility routines, to facilitate handling of most common data structures : transients (type, type name ...), strings (ascii or extended, pointed or handled or ...), shapes (reading, writing, testing ...), sequences & arrays (of strings, of transients, of shapes ...), ...");

// Constructors
cls_XSControl_Utils.def(py::init<>());

// Fields

// Methods
// cls_XSControl_Utils.def_static("operator new_", (void * (*)(size_t)) &XSControl_Utils::operator new, "None", py::arg("theSize"));
// cls_XSControl_Utils.def_static("operator delete_", (void (*)(void *)) &XSControl_Utils::operator delete, "None", py::arg("theAddress"));
// cls_XSControl_Utils.def_static("operator new[]_", (void * (*)(size_t)) &XSControl_Utils::operator new[], "None", py::arg("theSize"));
// cls_XSControl_Utils.def_static("operator delete[]_", (void (*)(void *)) &XSControl_Utils::operator delete[], "None", py::arg("theAddress"));
// cls_XSControl_Utils.def_static("operator new_", (void * (*)(size_t, void *)) &XSControl_Utils::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_XSControl_Utils.def_static("operator delete_", (void (*)(void *, void *)) &XSControl_Utils::operator delete, "None", py::arg(""), py::arg(""));
cls_XSControl_Utils.def("TraceLine", (void (XSControl_Utils::*)(const Standard_CString) const) &XSControl_Utils::TraceLine, "Just prints a line into the current Trace File. This allows to better characterise the various trace outputs, as desired.", py::arg("line"));
cls_XSControl_Utils.def("TraceLines", (void (XSControl_Utils::*)(const opencascade::handle<Standard_Transient> &) const) &XSControl_Utils::TraceLines, "Just prints a line or a set of lines into the current Trace File. <lines> can be a HAscii/ExtendedString (produces a print without ending line) or a HSequence or HArray1 Of .. (one new line per item)", py::arg("lines"));
cls_XSControl_Utils.def("IsKind", (Standard_Boolean (XSControl_Utils::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Type> &) const) &XSControl_Utils::IsKind, "None", py::arg("item"), py::arg("what"));
cls_XSControl_Utils.def("TypeName", [](XSControl_Utils &self, const opencascade::handle<Standard_Transient> & a0) -> Standard_CString { return self.TypeName(a0); });
cls_XSControl_Utils.def("TypeName", (Standard_CString (XSControl_Utils::*)(const opencascade::handle<Standard_Transient> &, const Standard_Boolean) const) &XSControl_Utils::TypeName, "Returns the name of the dynamic type of an object, i.e. : If it is a Type, its Name If it is a object not a type, the Name of its DynamicType If it is Null, an empty string If <nopk> is False (D), gives complete name If <nopk> is True, returns class name without package", py::arg("item"), py::arg("nopk"));
cls_XSControl_Utils.def("TraValue", (opencascade::handle<Standard_Transient> (XSControl_Utils::*)(const opencascade::handle<Standard_Transient> &, const Standard_Integer) const) &XSControl_Utils::TraValue, "None", py::arg("list"), py::arg("num"));
cls_XSControl_Utils.def("NewSeqTra", (opencascade::handle<TColStd_HSequenceOfTransient> (XSControl_Utils::*)() const) &XSControl_Utils::NewSeqTra, "None");
cls_XSControl_Utils.def("AppendTra", (void (XSControl_Utils::*)(const opencascade::handle<TColStd_HSequenceOfTransient> &, const opencascade::handle<Standard_Transient> &) const) &XSControl_Utils::AppendTra, "None", py::arg("seqval"), py::arg("traval"));
cls_XSControl_Utils.def("DateString", (Standard_CString (XSControl_Utils::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer) const) &XSControl_Utils::DateString, "None", py::arg("yy"), py::arg("mm"), py::arg("dd"), py::arg("hh"), py::arg("mn"), py::arg("ss"));
cls_XSControl_Utils.def("DateValues", [](XSControl_Utils &self, const Standard_CString text, Standard_Integer & yy, Standard_Integer & mm, Standard_Integer & dd, Standard_Integer & hh, Standard_Integer & mn, Standard_Integer & ss){ self.DateValues(text, yy, mm, dd, hh, mn, ss); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(yy, mm, dd, hh, mn, ss); }, "None", py::arg("text"), py::arg("yy"), py::arg("mm"), py::arg("dd"), py::arg("hh"), py::arg("mn"), py::arg("ss"));
cls_XSControl_Utils.def("ToCString", (Standard_CString (XSControl_Utils::*)(const opencascade::handle<TCollection_HAsciiString> &) const) &XSControl_Utils::ToCString, "None", py::arg("strval"));
cls_XSControl_Utils.def("ToCString", (Standard_CString (XSControl_Utils::*)(const TCollection_AsciiString &) const) &XSControl_Utils::ToCString, "None", py::arg("strval"));
cls_XSControl_Utils.def("ToHString", (opencascade::handle<TCollection_HAsciiString> (XSControl_Utils::*)(const Standard_CString) const) &XSControl_Utils::ToHString, "None", py::arg("strcon"));
cls_XSControl_Utils.def("ToAString", (TCollection_AsciiString (XSControl_Utils::*)(const Standard_CString) const) &XSControl_Utils::ToAString, "None", py::arg("strcon"));
cls_XSControl_Utils.def("ToEString", (Standard_ExtString (XSControl_Utils::*)(const opencascade::handle<TCollection_HExtendedString> &) const) &XSControl_Utils::ToEString, "None", py::arg("strval"));
cls_XSControl_Utils.def("ToEString", (Standard_ExtString (XSControl_Utils::*)(const TCollection_ExtendedString &) const) &XSControl_Utils::ToEString, "None", py::arg("strval"));
cls_XSControl_Utils.def("ToHString", (opencascade::handle<TCollection_HExtendedString> (XSControl_Utils::*)(const Standard_ExtString) const) &XSControl_Utils::ToHString, "None", py::arg("strcon"));
cls_XSControl_Utils.def("ToXString", (TCollection_ExtendedString (XSControl_Utils::*)(const Standard_ExtString) const) &XSControl_Utils::ToXString, "None", py::arg("strcon"));
cls_XSControl_Utils.def("AsciiToExtended", (Standard_ExtString (XSControl_Utils::*)(const Standard_CString) const) &XSControl_Utils::AsciiToExtended, "None", py::arg("str"));
cls_XSControl_Utils.def("IsAscii", (Standard_Boolean (XSControl_Utils::*)(const Standard_ExtString) const) &XSControl_Utils::IsAscii, "None", py::arg("str"));
cls_XSControl_Utils.def("ExtendedToAscii", (Standard_CString (XSControl_Utils::*)(const Standard_ExtString) const) &XSControl_Utils::ExtendedToAscii, "None", py::arg("str"));
cls_XSControl_Utils.def("CStrValue", (Standard_CString (XSControl_Utils::*)(const opencascade::handle<Standard_Transient> &, const Standard_Integer) const) &XSControl_Utils::CStrValue, "None", py::arg("list"), py::arg("num"));
cls_XSControl_Utils.def("EStrValue", (Standard_ExtString (XSControl_Utils::*)(const opencascade::handle<Standard_Transient> &, const Standard_Integer) const) &XSControl_Utils::EStrValue, "None", py::arg("list"), py::arg("num"));
cls_XSControl_Utils.def("NewSeqCStr", (opencascade::handle<TColStd_HSequenceOfHAsciiString> (XSControl_Utils::*)() const) &XSControl_Utils::NewSeqCStr, "None");
cls_XSControl_Utils.def("AppendCStr", (void (XSControl_Utils::*)(const opencascade::handle<TColStd_HSequenceOfHAsciiString> &, const Standard_CString) const) &XSControl_Utils::AppendCStr, "None", py::arg("seqval"), py::arg("strval"));
cls_XSControl_Utils.def("NewSeqEStr", (opencascade::handle<TColStd_HSequenceOfHExtendedString> (XSControl_Utils::*)() const) &XSControl_Utils::NewSeqEStr, "None");
cls_XSControl_Utils.def("AppendEStr", (void (XSControl_Utils::*)(const opencascade::handle<TColStd_HSequenceOfHExtendedString> &, const Standard_ExtString) const) &XSControl_Utils::AppendEStr, "None", py::arg("seqval"), py::arg("strval"));
cls_XSControl_Utils.def("CompoundFromSeq", (TopoDS_Shape (XSControl_Utils::*)(const opencascade::handle<TopTools_HSequenceOfShape> &) const) &XSControl_Utils::CompoundFromSeq, "Converts a list of Shapes to a Compound (a kind of Shape)", py::arg("seqval"));
cls_XSControl_Utils.def("ShapeType", (TopAbs_ShapeEnum (XSControl_Utils::*)(const TopoDS_Shape &, const Standard_Boolean) const) &XSControl_Utils::ShapeType, "Returns the type of a Shape : true type if <compound> is False If <compound> is True and <shape> is a Compound, iterates on its items. If all are of the same type, returns this type. Else, returns COMPOUND. If it is empty, returns SHAPE For a Null Shape, returns SHAPE", py::arg("shape"), py::arg("compound"));
cls_XSControl_Utils.def("SortedCompound", (TopoDS_Shape (XSControl_Utils::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const Standard_Boolean, const Standard_Boolean) const) &XSControl_Utils::SortedCompound, "From a Shape, builds a Compound as follows : explores it level by level If <explore> is False, only COMPOUND items. Else, all items Adds to the result, shapes which comply to <type> + if <type> is WIRE, considers free edges (and makes wires) + if <type> is SHELL, considers free faces (and makes shells) If <compound> is True, gathers items in compounds which correspond to starting COMPOUND,SOLID or SHELL containers, or items directly contained in a Compound", py::arg("shape"), py::arg("type"), py::arg("explore"), py::arg("compound"));
cls_XSControl_Utils.def("ShapeValue", (TopoDS_Shape (XSControl_Utils::*)(const opencascade::handle<TopTools_HSequenceOfShape> &, const Standard_Integer) const) &XSControl_Utils::ShapeValue, "None", py::arg("seqv"), py::arg("num"));
cls_XSControl_Utils.def("NewSeqShape", (opencascade::handle<TopTools_HSequenceOfShape> (XSControl_Utils::*)() const) &XSControl_Utils::NewSeqShape, "None");
cls_XSControl_Utils.def("AppendShape", (void (XSControl_Utils::*)(const opencascade::handle<TopTools_HSequenceOfShape> &, const TopoDS_Shape &) const) &XSControl_Utils::AppendShape, "None", py::arg("seqv"), py::arg("shape"));
cls_XSControl_Utils.def("ShapeBinder", [](XSControl_Utils &self, const TopoDS_Shape & a0) -> opencascade::handle<Standard_Transient> { return self.ShapeBinder(a0); });
cls_XSControl_Utils.def("ShapeBinder", (opencascade::handle<Standard_Transient> (XSControl_Utils::*)(const TopoDS_Shape &, const Standard_Boolean) const) &XSControl_Utils::ShapeBinder, "Creates a Transient Object from a Shape : it is either a Binder (used by functions which require a Transient but can process a Shape, such as viewing functions) or a HShape (according to hs) Default is a HShape", py::arg("shape"), py::arg("hs"));
cls_XSControl_Utils.def("BinderShape", (TopoDS_Shape (XSControl_Utils::*)(const opencascade::handle<Standard_Transient> &) const) &XSControl_Utils::BinderShape, "From a Transient, returns a Shape. In fact, recognizes ShapeBinder ShapeMapper and HShape", py::arg("tr"));
cls_XSControl_Utils.def("SeqLength", (Standard_Integer (XSControl_Utils::*)(const opencascade::handle<Standard_Transient> &) const) &XSControl_Utils::SeqLength, "None", py::arg("list"));
cls_XSControl_Utils.def("SeqToArr", [](XSControl_Utils &self, const opencascade::handle<Standard_Transient> & a0) -> opencascade::handle<Standard_Transient> { return self.SeqToArr(a0); });
cls_XSControl_Utils.def("SeqToArr", (opencascade::handle<Standard_Transient> (XSControl_Utils::*)(const opencascade::handle<Standard_Transient> &, const Standard_Integer) const) &XSControl_Utils::SeqToArr, "None", py::arg("seq"), py::arg("first"));
cls_XSControl_Utils.def("ArrToSeq", (opencascade::handle<Standard_Transient> (XSControl_Utils::*)(const opencascade::handle<Standard_Transient> &) const) &XSControl_Utils::ArrToSeq, "None", py::arg("arr"));
cls_XSControl_Utils.def("SeqIntValue", (Standard_Integer (XSControl_Utils::*)(const opencascade::handle<TColStd_HSequenceOfInteger> &, const Standard_Integer) const) &XSControl_Utils::SeqIntValue, "None", py::arg("list"), py::arg("num"));

// Enums

}