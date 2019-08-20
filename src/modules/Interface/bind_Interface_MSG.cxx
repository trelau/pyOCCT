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
#include <Standard_IStream.hxx>
#include <Standard_OStream.hxx>
#include <Standard_PCharacter.hxx>
#include <Interface_MSG.hxx>

void bind_Interface_MSG(py::module &mod){

py::class_<Interface_MSG, std::unique_ptr<Interface_MSG>> cls_Interface_MSG(mod, "Interface_MSG", "This class gives a set of functions to manage and use a list of translated messages (messagery)");

// Constructors
cls_Interface_MSG.def(py::init<const Standard_CString>(), py::arg("key"));
cls_Interface_MSG.def(py::init<const Standard_CString, const Standard_Integer>(), py::arg("key"), py::arg("i1"));
cls_Interface_MSG.def(py::init<const Standard_CString, const Standard_Integer, const Standard_Integer>(), py::arg("key"), py::arg("i1"), py::arg("i2"));
cls_Interface_MSG.def(py::init<const Standard_CString, const Standard_Real>(), py::arg("key"), py::arg("r1"));
cls_Interface_MSG.def(py::init<const Standard_CString, const Standard_Real, const Standard_Integer>(), py::arg("key"), py::arg("r1"), py::arg("intervals"));
cls_Interface_MSG.def(py::init<const Standard_CString, const Standard_CString>(), py::arg("key"), py::arg("str"));
cls_Interface_MSG.def(py::init<const Standard_CString, const Standard_Integer, const Standard_CString>(), py::arg("key"), py::arg("ival"), py::arg("str"));

// Fields

// Methods
// cls_Interface_MSG.def_static("operator new_", (void * (*)(size_t)) &Interface_MSG::operator new, "None", py::arg("theSize"));
// cls_Interface_MSG.def_static("operator delete_", (void (*)(void *)) &Interface_MSG::operator delete, "None", py::arg("theAddress"));
// cls_Interface_MSG.def_static("operator new[]_", (void * (*)(size_t)) &Interface_MSG::operator new[], "None", py::arg("theSize"));
// cls_Interface_MSG.def_static("operator delete[]_", (void (*)(void *)) &Interface_MSG::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_MSG.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_MSG::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_MSG.def_static("operator delete_", (void (*)(void *, void *)) &Interface_MSG::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_MSG.def("Destroy", (void (Interface_MSG::*)()) &Interface_MSG::Destroy, "Optimised destructor (applies for additional forms of Create)");
cls_Interface_MSG.def("Value", (Standard_CString (Interface_MSG::*)() const) &Interface_MSG::Value, "Returns the translated message, in a functional form with operator () was C++ : return const");
cls_Interface_MSG.def_static("Read_", (Standard_Integer (*)(Standard_IStream &)) &Interface_MSG::Read, "Reads a list of messages from a stream, returns read count 0 means empty file, -1 means error", py::arg("S"));
cls_Interface_MSG.def_static("Read_", (Standard_Integer (*)(const Standard_CString)) &Interface_MSG::Read, "Reads a list of messages from a file defined by its name", py::arg("file"));
cls_Interface_MSG.def_static("Write_", [](Standard_OStream & a0) -> Standard_Integer { return Interface_MSG::Write(a0); });
cls_Interface_MSG.def_static("Write_", (Standard_Integer (*)(Standard_OStream &, const Standard_CString)) &Interface_MSG::Write, "Writes the list of messages recorded to be translated, to a stream. Writes all the list (Default) or only keys which begin by <rootkey>. Returns the count of written messages", py::arg("S"), py::arg("rootkey"));
cls_Interface_MSG.def_static("IsKey_", (Standard_Boolean (*)(const Standard_CString)) &Interface_MSG::IsKey, "Returns True if a given message is surely a key (according to the form adopted for keys) (before activating messages, answer is false)", py::arg("mess"));
cls_Interface_MSG.def_static("Translated_", (Standard_CString (*)(const Standard_CString)) &Interface_MSG::Translated, "Returns the item recorded for a key. Returns the key itself if : - it is not recorded (then, the trace system is activated) - MSG has been required to be hung on", py::arg("key"));
cls_Interface_MSG.def_static("Record_", (void (*)(const Standard_CString, const Standard_CString)) &Interface_MSG::Record, "Fills the dictionary with a couple (key-item) If a key is already recorded, it is possible to : - keep the last definition, and activate the trace system", py::arg("key"), py::arg("item"));
cls_Interface_MSG.def_static("SetTrace_", (void (*)(const Standard_Boolean, const Standard_Boolean)) &Interface_MSG::SetTrace, "Sets the trace system to work when activated, as follow : - if <toprint> is True, print immediately on standard output - if <torecord> is True, record it for further print", py::arg("toprint"), py::arg("torecord"));
cls_Interface_MSG.def_static("SetMode_", (void (*)(const Standard_Boolean, const Standard_Boolean)) &Interface_MSG::SetMode, "Sets the main modes for MSG : - if <running> is True, translation works normally - if <running> is False, translated item equate keys - if <raising> is True, errors (from Record or Translate) cause MSG to raise an exception - if <raising> is False, MSG runs without exception, then see also Trace Modes above", py::arg("running"), py::arg("raising"));
cls_Interface_MSG.def_static("PrintTrace_", (void (*)(Standard_OStream &)) &Interface_MSG::PrintTrace, "Prints the recorded errors (without title; can be empty, this is the normally expected case)", py::arg("S"));
cls_Interface_MSG.def_static("Intervalled_", [](const Standard_Real a0) -> Standard_Real { return Interface_MSG::Intervalled(a0); });
cls_Interface_MSG.def_static("Intervalled_", [](const Standard_Real a0, const Standard_Integer a1) -> Standard_Real { return Interface_MSG::Intervalled(a0, a1); });
cls_Interface_MSG.def_static("Intervalled_", (Standard_Real (*)(const Standard_Real, const Standard_Integer, const Standard_Boolean)) &Interface_MSG::Intervalled, "Returns an 'intervalled' value from a starting real <val> : i.e. a value which is rounded on an interval limit Interval limits are defined to be in a coarsely 'geometric' progression (two successive intervals are inside a limit ratio)", py::arg("val"), py::arg("order"), py::arg("upper"));
cls_Interface_MSG.def_static("TDate_", [](const Standard_CString a0, const Standard_Integer a1, const Standard_Integer a2, const Standard_Integer a3, const Standard_Integer a4, const Standard_Integer a5, const Standard_Integer a6) -> void { return Interface_MSG::TDate(a0, a1, a2, a3, a4, a5, a6); });
cls_Interface_MSG.def_static("TDate_", (void (*)(const Standard_CString, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_CString)) &Interface_MSG::TDate, "Codes a date as a text, from its numeric value (-> seconds) : YYYY-MM-DD:HH-MN-SS fixed format, completed by leading zeros Another format can be provided, as follows : C:%d ... C like format, preceeded by C: S:... format to call system (not yet implemented)", py::arg("text"), py::arg("yy"), py::arg("mm"), py::arg("dd"), py::arg("hh"), py::arg("mn"), py::arg("ss"), py::arg("format"));
cls_Interface_MSG.def_static("NDate_", [](const Standard_CString text, Standard_Integer & yy, Standard_Integer & mm, Standard_Integer & dd, Standard_Integer & hh, Standard_Integer & mn, Standard_Integer & ss){ Standard_Boolean rv = Interface_MSG::NDate(text, yy, mm, dd, hh, mn, ss); return std::tuple<Standard_Boolean, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(rv, yy, mm, dd, hh, mn, ss); }, "Decodes a date to numeric integer values Returns True if OK, False if text does not fit with required format. Incomplete forms are allowed (for instance, for only YYYY-MM-DD, hour is zero)", py::arg("text"), py::arg("yy"), py::arg("mm"), py::arg("dd"), py::arg("hh"), py::arg("mn"), py::arg("ss"));
cls_Interface_MSG.def_static("CDate_", (Standard_Integer (*)(const Standard_CString, const Standard_CString)) &Interface_MSG::CDate, "Returns a value about comparison of two dates 0 : equal. <0 text1 anterior. >0 text1 posterior", py::arg("text1"), py::arg("text2"));
cls_Interface_MSG.def_static("Blanks_", (Standard_CString (*)(const Standard_Integer, const Standard_Integer)) &Interface_MSG::Blanks, "Returns a blank string, of length between 0 and <max>, to fill the printing of a numeric value <val>, i.e. : If val < 10 , max-1 blanks If val between 10 and 99, max-2 blanks ... etc...", py::arg("val"), py::arg("max"));
cls_Interface_MSG.def_static("Blanks_", (Standard_CString (*)(const Standard_CString, const Standard_Integer)) &Interface_MSG::Blanks, "Returns a blank string, to complete a given string <val> up to <max> characters : If strlen(val) is 0, max blanks If strlen(val) is 5, max-5 blanks etc...", py::arg("val"), py::arg("max"));
cls_Interface_MSG.def_static("Blanks_", (Standard_CString (*)(const Standard_Integer)) &Interface_MSG::Blanks, "Returns a blank string of <count> blanks (mini 0, maxi 76)", py::arg("count"));
cls_Interface_MSG.def_static("Print_", [](Standard_OStream & a0, const Standard_CString a1, const Standard_Integer a2) -> void { return Interface_MSG::Print(a0, a1, a2); });
cls_Interface_MSG.def_static("Print_", (void (*)(Standard_OStream &, const Standard_CString, const Standard_Integer, const Standard_Integer)) &Interface_MSG::Print, "Prints a String on an Output Stream, as follows : Accompagned with blanks, to give up to <max> charis at all, justified according just : -1 (D) : left 0 : center 1 : right Maximum 76 characters", py::arg("S"), py::arg("val"), py::arg("max"), py::arg("just"));

// Enums

}