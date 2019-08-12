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
#include <Geom2d_Curve.hxx>
#include <Standard_OStream.hxx>
#include <Standard_IStream.hxx>
#include <TColStd_IndexedMapOfTransient.hxx>
#include <BinTools_Curve2dSet.hxx>

void bind_BinTools_Curve2dSet(py::module &mod){

py::class_<BinTools_Curve2dSet, std::unique_ptr<BinTools_Curve2dSet, Deleter<BinTools_Curve2dSet>>> cls_BinTools_Curve2dSet(mod, "BinTools_Curve2dSet", "Stores a set of Curves from Geom2d in binary format");

// Constructors
cls_BinTools_Curve2dSet.def(py::init<>());

// Fields

// Methods
// cls_BinTools_Curve2dSet.def_static("operator new_", (void * (*)(size_t)) &BinTools_Curve2dSet::operator new, "None", py::arg("theSize"));
// cls_BinTools_Curve2dSet.def_static("operator delete_", (void (*)(void *)) &BinTools_Curve2dSet::operator delete, "None", py::arg("theAddress"));
// cls_BinTools_Curve2dSet.def_static("operator new[]_", (void * (*)(size_t)) &BinTools_Curve2dSet::operator new[], "None", py::arg("theSize"));
// cls_BinTools_Curve2dSet.def_static("operator delete[]_", (void (*)(void *)) &BinTools_Curve2dSet::operator delete[], "None", py::arg("theAddress"));
// cls_BinTools_Curve2dSet.def_static("operator new_", (void * (*)(size_t, void *)) &BinTools_Curve2dSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BinTools_Curve2dSet.def_static("operator delete_", (void (*)(void *, void *)) &BinTools_Curve2dSet::operator delete, "None", py::arg(""), py::arg(""));
cls_BinTools_Curve2dSet.def("Clear", (void (BinTools_Curve2dSet::*)()) &BinTools_Curve2dSet::Clear, "Clears the content of the set.");
cls_BinTools_Curve2dSet.def("Add", (Standard_Integer (BinTools_Curve2dSet::*)(const opencascade::handle<Geom2d_Curve> &)) &BinTools_Curve2dSet::Add, "Incorporate a new Curve in the set and returns its index.", py::arg("C"));
cls_BinTools_Curve2dSet.def("Curve2d", (opencascade::handle<Geom2d_Curve> (BinTools_Curve2dSet::*)(const Standard_Integer) const) &BinTools_Curve2dSet::Curve2d, "Returns the Curve of index <I>.", py::arg("I"));
cls_BinTools_Curve2dSet.def("Index", (Standard_Integer (BinTools_Curve2dSet::*)(const opencascade::handle<Geom2d_Curve> &) const) &BinTools_Curve2dSet::Index, "Returns the index of <L>.", py::arg("C"));
// cls_BinTools_Curve2dSet.def("Dump", (void (BinTools_Curve2dSet::*)(Standard_OStream &) const) &BinTools_Curve2dSet::Dump, "Dumps the content of me on the stream <OS>.", py::arg("OS"));
cls_BinTools_Curve2dSet.def("Write", (void (BinTools_Curve2dSet::*)(Standard_OStream &) const) &BinTools_Curve2dSet::Write, "Writes the content of me on the stream <OS> in a format that can be read back by Read.", py::arg("OS"));
cls_BinTools_Curve2dSet.def("Read", (void (BinTools_Curve2dSet::*)(Standard_IStream &)) &BinTools_Curve2dSet::Read, "Reads the content of me from the stream <IS>. me is first cleared.", py::arg("IS"));
cls_BinTools_Curve2dSet.def_static("WriteCurve2d_", (void (*)(const opencascade::handle<Geom2d_Curve> &, Standard_OStream &)) &BinTools_Curve2dSet::WriteCurve2d, "Dumps the curve on the binary stream, that can be read back.", py::arg("C"), py::arg("OS"));
cls_BinTools_Curve2dSet.def_static("ReadCurve2d_", (Standard_IStream & (*)(Standard_IStream &, opencascade::handle<Geom2d_Curve> &)) &BinTools_Curve2dSet::ReadCurve2d, "Reads the curve from the stream. The curve is assumed to have been written with the Write method.", py::arg("IS"), py::arg("C"));

// Enums

}