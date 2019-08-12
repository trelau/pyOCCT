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
#include <Message_ProgressIndicator.hxx>
#include <TColStd_IndexedMapOfTransient.hxx>
#include <GeomTools_Curve2dSet.hxx>

void bind_GeomTools_Curve2dSet(py::module &mod){

py::class_<GeomTools_Curve2dSet, std::unique_ptr<GeomTools_Curve2dSet, Deleter<GeomTools_Curve2dSet>>> cls_GeomTools_Curve2dSet(mod, "GeomTools_Curve2dSet", "Stores a set of Curves from Geom2d.");

// Constructors
cls_GeomTools_Curve2dSet.def(py::init<>());

// Fields

// Methods
// cls_GeomTools_Curve2dSet.def_static("operator new_", (void * (*)(size_t)) &GeomTools_Curve2dSet::operator new, "None", py::arg("theSize"));
// cls_GeomTools_Curve2dSet.def_static("operator delete_", (void (*)(void *)) &GeomTools_Curve2dSet::operator delete, "None", py::arg("theAddress"));
// cls_GeomTools_Curve2dSet.def_static("operator new[]_", (void * (*)(size_t)) &GeomTools_Curve2dSet::operator new[], "None", py::arg("theSize"));
// cls_GeomTools_Curve2dSet.def_static("operator delete[]_", (void (*)(void *)) &GeomTools_Curve2dSet::operator delete[], "None", py::arg("theAddress"));
// cls_GeomTools_Curve2dSet.def_static("operator new_", (void * (*)(size_t, void *)) &GeomTools_Curve2dSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomTools_Curve2dSet.def_static("operator delete_", (void (*)(void *, void *)) &GeomTools_Curve2dSet::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomTools_Curve2dSet.def("Clear", (void (GeomTools_Curve2dSet::*)()) &GeomTools_Curve2dSet::Clear, "Clears the content of the set.");
cls_GeomTools_Curve2dSet.def("Add", (Standard_Integer (GeomTools_Curve2dSet::*)(const opencascade::handle<Geom2d_Curve> &)) &GeomTools_Curve2dSet::Add, "Incorporate a new Curve in the set and returns its index.", py::arg("C"));
cls_GeomTools_Curve2dSet.def("Curve2d", (opencascade::handle<Geom2d_Curve> (GeomTools_Curve2dSet::*)(const Standard_Integer) const) &GeomTools_Curve2dSet::Curve2d, "Returns the Curve of index <I>.", py::arg("I"));
cls_GeomTools_Curve2dSet.def("Index", (Standard_Integer (GeomTools_Curve2dSet::*)(const opencascade::handle<Geom2d_Curve> &) const) &GeomTools_Curve2dSet::Index, "Returns the index of <L>.", py::arg("C"));
cls_GeomTools_Curve2dSet.def("Dump", (void (GeomTools_Curve2dSet::*)(Standard_OStream &) const) &GeomTools_Curve2dSet::Dump, "Dumps the content of me on the stream <OS>.", py::arg("OS"));
cls_GeomTools_Curve2dSet.def("Write", (void (GeomTools_Curve2dSet::*)(Standard_OStream &) const) &GeomTools_Curve2dSet::Write, "Writes the content of me on the stream <OS> in a format that can be read back by Read.", py::arg("OS"));
cls_GeomTools_Curve2dSet.def("Read", (void (GeomTools_Curve2dSet::*)(Standard_IStream &)) &GeomTools_Curve2dSet::Read, "Reads the content of me from the stream <IS>. me is first cleared.", py::arg("IS"));
cls_GeomTools_Curve2dSet.def_static("PrintCurve2d_", [](const opencascade::handle<Geom2d_Curve> & a0, Standard_OStream & a1) -> void { return GeomTools_Curve2dSet::PrintCurve2d(a0, a1); });
cls_GeomTools_Curve2dSet.def_static("PrintCurve2d_", (void (*)(const opencascade::handle<Geom2d_Curve> &, Standard_OStream &, const Standard_Boolean)) &GeomTools_Curve2dSet::PrintCurve2d, "Dumps the curve on the stream, if compact is True use the compact format that can be read back.", py::arg("C"), py::arg("OS"), py::arg("compact"));
cls_GeomTools_Curve2dSet.def_static("ReadCurve2d_", (opencascade::handle<Geom2d_Curve> (*)(Standard_IStream &)) &GeomTools_Curve2dSet::ReadCurve2d, "Reads the curve from the stream. The curve is assumed to have been written with the Print method (compact = True).", py::arg("IS"));
cls_GeomTools_Curve2dSet.def("SetProgress", (void (GeomTools_Curve2dSet::*)(const opencascade::handle<Message_ProgressIndicator> &)) &GeomTools_Curve2dSet::SetProgress, "None", py::arg("PR"));
cls_GeomTools_Curve2dSet.def("GetProgress", (opencascade::handle<Message_ProgressIndicator> (GeomTools_Curve2dSet::*)() const) &GeomTools_Curve2dSet::GetProgress, "None");

// Enums

}