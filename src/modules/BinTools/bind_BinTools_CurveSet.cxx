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
#include <Geom_Curve.hxx>
#include <Standard_OStream.hxx>
#include <Standard_IStream.hxx>
#include <TColStd_IndexedMapOfTransient.hxx>
#include <BinTools_CurveSet.hxx>

void bind_BinTools_CurveSet(py::module &mod){

py::class_<BinTools_CurveSet, std::unique_ptr<BinTools_CurveSet>> cls_BinTools_CurveSet(mod, "BinTools_CurveSet", "Stores a set of Curves from Geom in binary format.");

// Constructors
cls_BinTools_CurveSet.def(py::init<>());

// Fields

// Methods
// cls_BinTools_CurveSet.def_static("operator new_", (void * (*)(size_t)) &BinTools_CurveSet::operator new, "None", py::arg("theSize"));
// cls_BinTools_CurveSet.def_static("operator delete_", (void (*)(void *)) &BinTools_CurveSet::operator delete, "None", py::arg("theAddress"));
// cls_BinTools_CurveSet.def_static("operator new[]_", (void * (*)(size_t)) &BinTools_CurveSet::operator new[], "None", py::arg("theSize"));
// cls_BinTools_CurveSet.def_static("operator delete[]_", (void (*)(void *)) &BinTools_CurveSet::operator delete[], "None", py::arg("theAddress"));
// cls_BinTools_CurveSet.def_static("operator new_", (void * (*)(size_t, void *)) &BinTools_CurveSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BinTools_CurveSet.def_static("operator delete_", (void (*)(void *, void *)) &BinTools_CurveSet::operator delete, "None", py::arg(""), py::arg(""));
cls_BinTools_CurveSet.def("Clear", (void (BinTools_CurveSet::*)()) &BinTools_CurveSet::Clear, "Clears the content of the set.");
cls_BinTools_CurveSet.def("Add", (Standard_Integer (BinTools_CurveSet::*)(const opencascade::handle<Geom_Curve> &)) &BinTools_CurveSet::Add, "Incorporate a new Curve in the set and returns its index.", py::arg("C"));
cls_BinTools_CurveSet.def("Curve", (opencascade::handle<Geom_Curve> (BinTools_CurveSet::*)(const Standard_Integer) const) &BinTools_CurveSet::Curve, "Returns the Curve of index <I>.", py::arg("I"));
cls_BinTools_CurveSet.def("Index", (Standard_Integer (BinTools_CurveSet::*)(const opencascade::handle<Geom_Curve> &) const) &BinTools_CurveSet::Index, "Returns the index of <L>.", py::arg("C"));
cls_BinTools_CurveSet.def("Write", (void (BinTools_CurveSet::*)(Standard_OStream &) const) &BinTools_CurveSet::Write, "Writes the content of me on the stream <OS> in a format that can be read back by Read.", py::arg("OS"));
cls_BinTools_CurveSet.def("Read", (void (BinTools_CurveSet::*)(Standard_IStream &)) &BinTools_CurveSet::Read, "Reads the content of me from the stream <IS>. me is first cleared.", py::arg("IS"));
cls_BinTools_CurveSet.def_static("WriteCurve_", (void (*)(const opencascade::handle<Geom_Curve> &, Standard_OStream &)) &BinTools_CurveSet::WriteCurve, "Dumps the curve on the stream in binary format that can be read back.", py::arg("C"), py::arg("OS"));
cls_BinTools_CurveSet.def_static("ReadCurve_", (Standard_IStream & (*)(Standard_IStream &, opencascade::handle<Geom_Curve> &)) &BinTools_CurveSet::ReadCurve, "Reads the curve from the stream. The curve is assumed to have been written with the Write method", py::arg("IS"), py::arg("C"));

// Enums

}