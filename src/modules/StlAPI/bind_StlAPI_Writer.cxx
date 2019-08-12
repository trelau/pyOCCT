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
#include <TopoDS_Shape.hxx>
#include <StlAPI_Writer.hxx>

void bind_StlAPI_Writer(py::module &mod){

py::class_<StlAPI_Writer, std::unique_ptr<StlAPI_Writer, Deleter<StlAPI_Writer>>> cls_StlAPI_Writer(mod, "StlAPI_Writer", "This class creates and writes STL files from Open CASCADE shapes. An STL file can be written to an existing STL file or to a new one.");

// Constructors
cls_StlAPI_Writer.def(py::init<>());

// Fields

// Methods
// cls_StlAPI_Writer.def_static("operator new_", (void * (*)(size_t)) &StlAPI_Writer::operator new, "None", py::arg("theSize"));
// cls_StlAPI_Writer.def_static("operator delete_", (void (*)(void *)) &StlAPI_Writer::operator delete, "None", py::arg("theAddress"));
// cls_StlAPI_Writer.def_static("operator new[]_", (void * (*)(size_t)) &StlAPI_Writer::operator new[], "None", py::arg("theSize"));
// cls_StlAPI_Writer.def_static("operator delete[]_", (void (*)(void *)) &StlAPI_Writer::operator delete[], "None", py::arg("theAddress"));
// cls_StlAPI_Writer.def_static("operator new_", (void * (*)(size_t, void *)) &StlAPI_Writer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StlAPI_Writer.def_static("operator delete_", (void (*)(void *, void *)) &StlAPI_Writer::operator delete, "None", py::arg(""), py::arg(""));
cls_StlAPI_Writer.def("ASCIIMode", (Standard_Boolean & (StlAPI_Writer::*)()) &StlAPI_Writer::ASCIIMode, "Returns the address to the flag defining the mode for writing the file. This address may be used to either read or change the flag. If the mode returns True (default value) the generated file is an ASCII file. If the mode returns False, the generated file is a binary file.");
cls_StlAPI_Writer.def("Write", (Standard_Boolean (StlAPI_Writer::*)(const TopoDS_Shape &, const Standard_CString)) &StlAPI_Writer::Write, "Converts a given shape to STL format and writes it to file with a given filename.", py::arg("theShape"), py::arg("theFileName"));

// Enums

}