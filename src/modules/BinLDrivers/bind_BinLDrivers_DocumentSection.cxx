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
#include <TCollection_AsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_OStream.hxx>
#include <BinLDrivers_DocumentSection.hxx>
#include <Standard_IStream.hxx>

void bind_BinLDrivers_DocumentSection(py::module &mod){

py::class_<BinLDrivers_DocumentSection, std::unique_ptr<BinLDrivers_DocumentSection>> cls_BinLDrivers_DocumentSection(mod, "BinLDrivers_DocumentSection", "More or less independent part of the saved/restored document that is distinct from OCAF data themselves but may be referred by them.");

// Constructors
cls_BinLDrivers_DocumentSection.def(py::init<>());
cls_BinLDrivers_DocumentSection.def(py::init<const TCollection_AsciiString &, const Standard_Boolean>(), py::arg("theName"), py::arg("isPostRead"));

// Fields

// Methods
// cls_BinLDrivers_DocumentSection.def_static("operator new_", (void * (*)(size_t)) &BinLDrivers_DocumentSection::operator new, "None", py::arg("theSize"));
// cls_BinLDrivers_DocumentSection.def_static("operator delete_", (void (*)(void *)) &BinLDrivers_DocumentSection::operator delete, "None", py::arg("theAddress"));
// cls_BinLDrivers_DocumentSection.def_static("operator new[]_", (void * (*)(size_t)) &BinLDrivers_DocumentSection::operator new[], "None", py::arg("theSize"));
// cls_BinLDrivers_DocumentSection.def_static("operator delete[]_", (void (*)(void *)) &BinLDrivers_DocumentSection::operator delete[], "None", py::arg("theAddress"));
// cls_BinLDrivers_DocumentSection.def_static("operator new_", (void * (*)(size_t, void *)) &BinLDrivers_DocumentSection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BinLDrivers_DocumentSection.def_static("operator delete_", (void (*)(void *, void *)) &BinLDrivers_DocumentSection::operator delete, "None", py::arg(""), py::arg(""));
cls_BinLDrivers_DocumentSection.def("Name", (const TCollection_AsciiString & (BinLDrivers_DocumentSection::*)() const) &BinLDrivers_DocumentSection::Name, "Query the name of the section.");
cls_BinLDrivers_DocumentSection.def("IsPostRead", (Standard_Boolean (BinLDrivers_DocumentSection::*)() const) &BinLDrivers_DocumentSection::IsPostRead, "Query the status: if the Section should be read after OCAF; False means that the Section is read before starting to read OCAF data.");
cls_BinLDrivers_DocumentSection.def("Offset", (uint64_t (BinLDrivers_DocumentSection::*)() const) &BinLDrivers_DocumentSection::Offset, "Query the offset of the section in the persistent file");
cls_BinLDrivers_DocumentSection.def("SetOffset", (void (BinLDrivers_DocumentSection::*)(const uint64_t)) &BinLDrivers_DocumentSection::SetOffset, "Set the offset of the section in the persistent file", py::arg("theOffset"));
cls_BinLDrivers_DocumentSection.def("Length", (uint64_t (BinLDrivers_DocumentSection::*)() const) &BinLDrivers_DocumentSection::Length, "Query the length of the section in the persistent file");
cls_BinLDrivers_DocumentSection.def("SetLength", (void (BinLDrivers_DocumentSection::*)(const uint64_t)) &BinLDrivers_DocumentSection::SetLength, "Set the length of the section in the persistent file", py::arg("theLength"));
cls_BinLDrivers_DocumentSection.def("WriteTOC", (void (BinLDrivers_DocumentSection::*)(Standard_OStream &)) &BinLDrivers_DocumentSection::WriteTOC, "Create a Section entry in the Document TOC (list of sections)", py::arg("theOS"));
cls_BinLDrivers_DocumentSection.def("Write", (void (BinLDrivers_DocumentSection::*)(Standard_OStream &, const uint64_t)) &BinLDrivers_DocumentSection::Write, "Save Offset and Length data into the Section entry in the Document TOC (list of sections)", py::arg("theOS"), py::arg("theOffset"));
cls_BinLDrivers_DocumentSection.def_static("ReadTOC_", (void (*)(BinLDrivers_DocumentSection &, Standard_IStream &)) &BinLDrivers_DocumentSection::ReadTOC, "Fill a DocumentSection instance from the data that are read from TOC.", py::arg("theSection"), py::arg("theIS"));

// Enums

}