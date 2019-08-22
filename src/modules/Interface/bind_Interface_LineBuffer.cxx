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
#include <TCollection_AsciiString.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <NCollection_Array1.hxx>
#include <Interface_LineBuffer.hxx>

void bind_Interface_LineBuffer(py::module &mod){

py::class_<Interface_LineBuffer> cls_Interface_LineBuffer(mod, "Interface_LineBuffer", "Simple Management of a Line Buffer, to be used by Interface File Writers. While a String is suitable to do that, this class ensures an optimised Memory Management, because this is a hard point of File Writing.");

// Constructors
cls_Interface_LineBuffer.def(py::init<>());
cls_Interface_LineBuffer.def(py::init<const Standard_Integer>(), py::arg("size"));

// Fields

// Methods
// cls_Interface_LineBuffer.def_static("operator new_", (void * (*)(size_t)) &Interface_LineBuffer::operator new, "None", py::arg("theSize"));
// cls_Interface_LineBuffer.def_static("operator delete_", (void (*)(void *)) &Interface_LineBuffer::operator delete, "None", py::arg("theAddress"));
// cls_Interface_LineBuffer.def_static("operator new[]_", (void * (*)(size_t)) &Interface_LineBuffer::operator new[], "None", py::arg("theSize"));
// cls_Interface_LineBuffer.def_static("operator delete[]_", (void (*)(void *)) &Interface_LineBuffer::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_LineBuffer.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_LineBuffer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_LineBuffer.def_static("operator delete_", (void (*)(void *, void *)) &Interface_LineBuffer::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_LineBuffer.def("SetMax", (void (Interface_LineBuffer::*)(const Standard_Integer)) &Interface_LineBuffer::SetMax, "Changes Maximum allowed size of Buffer. If <max> is Zero, Maximum size is set to the initial size.", py::arg("max"));
cls_Interface_LineBuffer.def("SetInitial", (void (Interface_LineBuffer::*)(const Standard_Integer)) &Interface_LineBuffer::SetInitial, "Sets an Initial reservation for Blank characters (this reservation is counted in the size of the current Line)", py::arg("initial"));
cls_Interface_LineBuffer.def("SetKeep", (void (Interface_LineBuffer::*)()) &Interface_LineBuffer::SetKeep, "Sets a Keep Status at current Length. It means that at next Move, the new line will begin by characters between Keep + 1 and current Length");
cls_Interface_LineBuffer.def("CanGet", (Standard_Boolean (Interface_LineBuffer::*)(const Standard_Integer)) &Interface_LineBuffer::CanGet, "Returns True if there is room enough to add <more> characters Else, it is required to Dump the Buffer before refilling it <more> is recorded to manage SetKeep status", py::arg("more"));
cls_Interface_LineBuffer.def("Content", (Standard_CString (Interface_LineBuffer::*)() const) &Interface_LineBuffer::Content, "Returns the Content of the LineBuffer");
cls_Interface_LineBuffer.def("Length", (Standard_Integer (Interface_LineBuffer::*)() const) &Interface_LineBuffer::Length, "Returns the Length of the LineBuffer");
cls_Interface_LineBuffer.def("Clear", (void (Interface_LineBuffer::*)()) &Interface_LineBuffer::Clear, "Clears completely the LineBuffer");
cls_Interface_LineBuffer.def("FreezeInitial", (void (Interface_LineBuffer::*)()) &Interface_LineBuffer::FreezeInitial, "Inhibits effect of SetInitial until the next Move (i.e. Keep) Then Prepare will not insert initial blanks, but further ones will. This allows to cancel initial blanks on an internal Split A call to SetInitial has no effect on this until Move");
cls_Interface_LineBuffer.def("Move", (void (Interface_LineBuffer::*)(TCollection_AsciiString &)) &Interface_LineBuffer::Move, "Fills a AsciiString <str> with the Content of the Line Buffer, then Clears the LineBuffer", py::arg("str"));
cls_Interface_LineBuffer.def("Move", (void (Interface_LineBuffer::*)(const opencascade::handle<TCollection_HAsciiString> &)) &Interface_LineBuffer::Move, "Same as above, but <str> is known through a Handle", py::arg("str"));
cls_Interface_LineBuffer.def("Moved", (opencascade::handle<TCollection_HAsciiString> (Interface_LineBuffer::*)()) &Interface_LineBuffer::Moved, "Same as above, but generates the HAsciiString");
cls_Interface_LineBuffer.def("Add", (void (Interface_LineBuffer::*)(const Standard_CString)) &Interface_LineBuffer::Add, "Adds a text as a CString. Its Length is evaluated from the text (by C function strlen)", py::arg("text"));
cls_Interface_LineBuffer.def("Add", (void (Interface_LineBuffer::*)(const Standard_CString, const Standard_Integer)) &Interface_LineBuffer::Add, "Adds a text as a CString. Its length is given as <lntext>", py::arg("text"), py::arg("lntext"));
cls_Interface_LineBuffer.def("Add", (void (Interface_LineBuffer::*)(const TCollection_AsciiString &)) &Interface_LineBuffer::Add, "Adds a text as a AsciiString from TCollection", py::arg("text"));
cls_Interface_LineBuffer.def("Add", (void (Interface_LineBuffer::*)(const Standard_Character)) &Interface_LineBuffer::Add, "Adds a text made of only ONE Character", py::arg("text"));

// Enums

}