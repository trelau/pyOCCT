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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <RWStl_Reader.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <Message_ProgressIndicator.hxx>
#include <Standard_IStream.hxx>
#include <gp_XYZ.hxx>

void bind_RWStl_Reader(py::module &mod){

py::class_<RWStl_Reader, opencascade::handle<RWStl_Reader>, Standard_Transient> cls_RWStl_Reader(mod, "RWStl_Reader", "An abstract class implementing procedure to read STL file.");

// Fields

// Methods
cls_RWStl_Reader.def_static("get_type_name_", (const char * (*)()) &RWStl_Reader::get_type_name, "None");
cls_RWStl_Reader.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &RWStl_Reader::get_type_descriptor, "None");
cls_RWStl_Reader.def("DynamicType", (const opencascade::handle<Standard_Type> & (RWStl_Reader::*)() const) &RWStl_Reader::DynamicType, "None");
cls_RWStl_Reader.def("Read", (Standard_Boolean (RWStl_Reader::*)(const char *, const opencascade::handle<Message_ProgressIndicator> &)) &RWStl_Reader::Read, "Reads data from STL file (either binary or Ascii). This function supports reading multi-domain STL files formed by concatenation of several 'plain' files. The mesh nodes are not merged between domains. Unicode paths can be given in UTF-8 encoding. Format is recognized automatically by analysis of the file header. Returns true if success, false on error or user break.", py::arg("theFile"), py::arg("theProgress"));
cls_RWStl_Reader.def("IsAscii", (Standard_Boolean (RWStl_Reader::*)(Standard_IStream &)) &RWStl_Reader::IsAscii, "Guess whether the stream is an Ascii STL file, by analysis of the first bytes (~200). The function attempts to put back the read symbols to the stream which thus must support ungetc(). Returns true if the stream seems to contain Ascii STL.", py::arg("theStream"));
cls_RWStl_Reader.def("ReadBinary", (Standard_Boolean (RWStl_Reader::*)(Standard_IStream &, const opencascade::handle<Message_ProgressIndicator> &)) &RWStl_Reader::ReadBinary, "Reads STL data from binary stream. The stream must be opened in binary mode. Stops after reading the number of triangles recorded in the file header. Returns true if success, false on error or user break.", py::arg("theStream"), py::arg("theProgress"));
cls_RWStl_Reader.def("ReadAscii", (Standard_Boolean (RWStl_Reader::*)(Standard_IStream &, const std::streampos, const opencascade::handle<Message_ProgressIndicator> &)) &RWStl_Reader::ReadAscii, "Reads data from the stream assumed to contain Ascii STL data. The stream can be opened either in binary or in Ascii mode. Reading stops at the position specified by theUntilPos, or end of file is reached, or when keyword 'endsolid' is found. Empty lines are not supported and will read to reading failure. If theUntilPos is non-zero, reads not more than until that position. Returns true if success, false on error or user break.", py::arg("theStream"), py::arg("theUntilPos"), py::arg("theProgress"));
cls_RWStl_Reader.def("AddNode", (Standard_Integer (RWStl_Reader::*)(const gp_XYZ &)) &RWStl_Reader::AddNode, "Callback function to be implemented in descendant. Should create new node with specified coordinates in the target model, and return its ID as integer.", py::arg("thePnt"));
cls_RWStl_Reader.def("AddTriangle", (void (RWStl_Reader::*)(Standard_Integer, Standard_Integer, Standard_Integer)) &RWStl_Reader::AddTriangle, "Callback function to be implemented in descendant. Should create new triangle built on specified nodes in the target model.", py::arg("theN1"), py::arg("theN2"), py::arg("theN3"));

// Enums

}