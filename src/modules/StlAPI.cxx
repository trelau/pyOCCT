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
#include <StlAPI.hxx>
#include <StlAPI_Reader.hxx>
#include <StlAPI_Writer.hxx>

PYBIND11_MODULE(StlAPI, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");

// CLASS: STLAPI
py::class_<StlAPI> cls_StlAPI(mod, "StlAPI", "Offers the API for STL data manipulation.");

// Constructors
cls_StlAPI.def(py::init<>());

// Methods
// cls_StlAPI.def_static("operator new_", (void * (*)(size_t)) &StlAPI::operator new, "None", py::arg("theSize"));
// cls_StlAPI.def_static("operator delete_", (void (*)(void *)) &StlAPI::operator delete, "None", py::arg("theAddress"));
// cls_StlAPI.def_static("operator new[]_", (void * (*)(size_t)) &StlAPI::operator new[], "None", py::arg("theSize"));
// cls_StlAPI.def_static("operator delete[]_", (void (*)(void *)) &StlAPI::operator delete[], "None", py::arg("theAddress"));
// cls_StlAPI.def_static("operator new_", (void * (*)(size_t, void *)) &StlAPI::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StlAPI.def_static("operator delete_", (void (*)(void *, void *)) &StlAPI::operator delete, "None", py::arg(""), py::arg(""));
cls_StlAPI.def_static("Write_", [](const TopoDS_Shape & a0, const Standard_CString a1) -> Standard_Boolean { return StlAPI::Write(a0, a1); });
cls_StlAPI.def_static("Write_", (Standard_Boolean (*)(const TopoDS_Shape &, const Standard_CString, const Standard_Boolean)) &StlAPI::Write, "Convert and write shape to STL format. File is written in binary if aAsciiMode is False otherwise it is written in Ascii (by default).", py::arg("theShape"), py::arg("theFile"), py::arg("theAsciiMode"));
cls_StlAPI.def_static("Read_", (Standard_Boolean (*)(TopoDS_Shape &, const Standard_CString)) &StlAPI::Read, "None", py::arg("theShape"), py::arg("aFile"));

// CLASS: STLAPI_READER
py::class_<StlAPI_Reader> cls_StlAPI_Reader(mod, "StlAPI_Reader", "Reading from stereolithography format.");

// Constructors
cls_StlAPI_Reader.def(py::init<>());

// Methods
cls_StlAPI_Reader.def("Read", (Standard_Boolean (StlAPI_Reader::*)(TopoDS_Shape &, const Standard_CString)) &StlAPI_Reader::Read, "Reads STL file to the TopoDS_Shape (each triangle is converted to the face).", py::arg("theShape"), py::arg("theFileName"));

// CLASS: STLAPI_WRITER
py::class_<StlAPI_Writer> cls_StlAPI_Writer(mod, "StlAPI_Writer", "This class creates and writes STL files from Open CASCADE shapes. An STL file can be written to an existing STL file or to a new one.");

// Constructors
cls_StlAPI_Writer.def(py::init<>());

// Methods
// cls_StlAPI_Writer.def_static("operator new_", (void * (*)(size_t)) &StlAPI_Writer::operator new, "None", py::arg("theSize"));
// cls_StlAPI_Writer.def_static("operator delete_", (void (*)(void *)) &StlAPI_Writer::operator delete, "None", py::arg("theAddress"));
// cls_StlAPI_Writer.def_static("operator new[]_", (void * (*)(size_t)) &StlAPI_Writer::operator new[], "None", py::arg("theSize"));
// cls_StlAPI_Writer.def_static("operator delete[]_", (void (*)(void *)) &StlAPI_Writer::operator delete[], "None", py::arg("theAddress"));
// cls_StlAPI_Writer.def_static("operator new_", (void * (*)(size_t, void *)) &StlAPI_Writer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StlAPI_Writer.def_static("operator delete_", (void (*)(void *, void *)) &StlAPI_Writer::operator delete, "None", py::arg(""), py::arg(""));
cls_StlAPI_Writer.def("ASCIIMode", (Standard_Boolean & (StlAPI_Writer::*)()) &StlAPI_Writer::ASCIIMode, "Returns the address to the flag defining the mode for writing the file. This address may be used to either read or change the flag. If the mode returns True (default value) the generated file is an ASCII file. If the mode returns False, the generated file is a binary file.");
cls_StlAPI_Writer.def("Write", (Standard_Boolean (StlAPI_Writer::*)(const TopoDS_Shape &, const Standard_CString)) &StlAPI_Writer::Write, "Converts a given shape to STL format and writes it to file with a given filename.", py::arg("theShape"), py::arg("theFileName"));


}
