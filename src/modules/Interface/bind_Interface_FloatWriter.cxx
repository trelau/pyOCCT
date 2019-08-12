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
#include <Interface_FloatWriter.hxx>

void bind_Interface_FloatWriter(py::module &mod){

py::class_<Interface_FloatWriter, std::unique_ptr<Interface_FloatWriter, Deleter<Interface_FloatWriter>>> cls_Interface_FloatWriter(mod, "Interface_FloatWriter", "This class converts a floting number (Real) to a string It can be used if the standard C-C++ output functions (sprintf or cout<<) are not convenient. That is to say : - to suppress trailing '0' and 'E+00' (if desired) - to control exponant output and floating point output");

// Constructors
cls_Interface_FloatWriter.def(py::init<>());
cls_Interface_FloatWriter.def(py::init<const Standard_Integer>(), py::arg("chars"));

// Fields

// Methods
// cls_Interface_FloatWriter.def_static("operator new_", (void * (*)(size_t)) &Interface_FloatWriter::operator new, "None", py::arg("theSize"));
// cls_Interface_FloatWriter.def_static("operator delete_", (void (*)(void *)) &Interface_FloatWriter::operator delete, "None", py::arg("theAddress"));
// cls_Interface_FloatWriter.def_static("operator new[]_", (void * (*)(size_t)) &Interface_FloatWriter::operator new[], "None", py::arg("theSize"));
// cls_Interface_FloatWriter.def_static("operator delete[]_", (void (*)(void *)) &Interface_FloatWriter::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_FloatWriter.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_FloatWriter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_FloatWriter.def_static("operator delete_", (void (*)(void *, void *)) &Interface_FloatWriter::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_FloatWriter.def("SetFormat", [](Interface_FloatWriter &self, const Standard_CString a0) -> void { return self.SetFormat(a0); });
cls_Interface_FloatWriter.def("SetFormat", (void (Interface_FloatWriter::*)(const Standard_CString, const Standard_Boolean)) &Interface_FloatWriter::SetFormat, "Sets a specific Format for Sending Reals (main format) (Default from Creation is '%E') If <reset> is given True (default), this call clears effects of former calls to SetFormatForRange and SetZeroSuppress", py::arg("form"), py::arg("reset"));
cls_Interface_FloatWriter.def("SetFormatForRange", (void (Interface_FloatWriter::*)(const Standard_CString, const Standard_Real, const Standard_Real)) &Interface_FloatWriter::SetFormatForRange, "Sets a secondary Format for Real, to be applied between R1 and R2 (in absolute values). A Call to SetRealForm cancels this secondary form if <reset> is True. (Default from Creation is '%f' between 0.1 and 1000.) Warning : if the condition (0. <= R1 < R2) is not fulfilled, this secondary form is canceled.", py::arg("form"), py::arg("R1"), py::arg("R2"));
cls_Interface_FloatWriter.def("SetZeroSuppress", (void (Interface_FloatWriter::*)(const Standard_Boolean)) &Interface_FloatWriter::SetZeroSuppress, "Sets Sending Real Parameters to suppress trailing Zeros and Null Exponant ('E+00'), if <mode> is given True, Resets this mode if <mode> is False (in addition to Real Forms) A call to SetRealFrom resets this mode to False ig <reset> is given True (Default from Creation is True)", py::arg("mode"));
cls_Interface_FloatWriter.def("SetDefaults", [](Interface_FloatWriter &self) -> void { return self.SetDefaults(); });
cls_Interface_FloatWriter.def("SetDefaults", (void (Interface_FloatWriter::*)(const Standard_Integer)) &Interface_FloatWriter::SetDefaults, "Sets again options to the defaults given by Create", py::arg("chars"));
cls_Interface_FloatWriter.def("Options", [](Interface_FloatWriter &self, Standard_Boolean & zerosup, Standard_Boolean & range, Standard_Real & R1, Standard_Real & R2){ self.Options(zerosup, range, R1, R2); return std::tuple<Standard_Boolean &, Standard_Boolean &, Standard_Real &, Standard_Real &>(zerosup, range, R1, R2); }, "Returns active options : <zerosup> is the option ZeroSuppress, <range> is True if a range is set, False else R1,R2 give the range (if it is set)", py::arg("zerosup"), py::arg("range"), py::arg("R1"), py::arg("R2"));
cls_Interface_FloatWriter.def("MainFormat", (Standard_CString (Interface_FloatWriter::*)() const) &Interface_FloatWriter::MainFormat, "Returns the main format was C++ : return const");
cls_Interface_FloatWriter.def("FormatForRange", (Standard_CString (Interface_FloatWriter::*)() const) &Interface_FloatWriter::FormatForRange, "Returns the format for range, if set Meaningful only if <range> from Options is True was C++ : return const");
cls_Interface_FloatWriter.def("Write", (Standard_Integer (Interface_FloatWriter::*)(const Standard_Real, const Standard_CString) const) &Interface_FloatWriter::Write, "Writes a Real value <val> to a string <text> by using the options. Returns the useful Length of produced string. It calls the class method Convert. Warning : <text> is assumed to be wide enough (20-30 is correct) And, even if declared in, its content will be modified", py::arg("val"), py::arg("text"));
cls_Interface_FloatWriter.def_static("Convert_", (Standard_Integer (*)(const Standard_Real, const Standard_CString, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_CString, const Standard_CString)) &Interface_FloatWriter::Convert, "This class method converts a Real Value to a string, given options given as arguments. It can be called independantly. Warning : even if declared in, content of <text> will be modified", py::arg("val"), py::arg("text"), py::arg("zerosup"), py::arg("Range1"), py::arg("Range2"), py::arg("mainform"), py::arg("rangeform"));

// Enums

}