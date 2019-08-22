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
#include <Geom_Surface.hxx>
#include <Standard_OStream.hxx>
#include <Standard_IStream.hxx>
#include <Message_ProgressIndicator.hxx>
#include <TColStd_IndexedMapOfTransient.hxx>
#include <GeomTools_SurfaceSet.hxx>

void bind_GeomTools_SurfaceSet(py::module &mod){

py::class_<GeomTools_SurfaceSet> cls_GeomTools_SurfaceSet(mod, "GeomTools_SurfaceSet", "Stores a set of Surfaces from Geom.");

// Constructors
cls_GeomTools_SurfaceSet.def(py::init<>());

// Fields

// Methods
// cls_GeomTools_SurfaceSet.def_static("operator new_", (void * (*)(size_t)) &GeomTools_SurfaceSet::operator new, "None", py::arg("theSize"));
// cls_GeomTools_SurfaceSet.def_static("operator delete_", (void (*)(void *)) &GeomTools_SurfaceSet::operator delete, "None", py::arg("theAddress"));
// cls_GeomTools_SurfaceSet.def_static("operator new[]_", (void * (*)(size_t)) &GeomTools_SurfaceSet::operator new[], "None", py::arg("theSize"));
// cls_GeomTools_SurfaceSet.def_static("operator delete[]_", (void (*)(void *)) &GeomTools_SurfaceSet::operator delete[], "None", py::arg("theAddress"));
// cls_GeomTools_SurfaceSet.def_static("operator new_", (void * (*)(size_t, void *)) &GeomTools_SurfaceSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomTools_SurfaceSet.def_static("operator delete_", (void (*)(void *, void *)) &GeomTools_SurfaceSet::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomTools_SurfaceSet.def("Clear", (void (GeomTools_SurfaceSet::*)()) &GeomTools_SurfaceSet::Clear, "Clears the content of the set.");
cls_GeomTools_SurfaceSet.def("Add", (Standard_Integer (GeomTools_SurfaceSet::*)(const opencascade::handle<Geom_Surface> &)) &GeomTools_SurfaceSet::Add, "Incorporate a new Surface in the set and returns its index.", py::arg("S"));
cls_GeomTools_SurfaceSet.def("Surface", (opencascade::handle<Geom_Surface> (GeomTools_SurfaceSet::*)(const Standard_Integer) const) &GeomTools_SurfaceSet::Surface, "Returns the Surface of index <I>.", py::arg("I"));
cls_GeomTools_SurfaceSet.def("Index", (Standard_Integer (GeomTools_SurfaceSet::*)(const opencascade::handle<Geom_Surface> &) const) &GeomTools_SurfaceSet::Index, "Returns the index of <L>.", py::arg("S"));
cls_GeomTools_SurfaceSet.def("Dump", (void (GeomTools_SurfaceSet::*)(Standard_OStream &) const) &GeomTools_SurfaceSet::Dump, "Dumps the content of me on the stream <OS>.", py::arg("OS"));
cls_GeomTools_SurfaceSet.def("Write", (void (GeomTools_SurfaceSet::*)(Standard_OStream &) const) &GeomTools_SurfaceSet::Write, "Writes the content of me on the stream <OS> in a format that can be read back by Read.", py::arg("OS"));
cls_GeomTools_SurfaceSet.def("Read", (void (GeomTools_SurfaceSet::*)(Standard_IStream &)) &GeomTools_SurfaceSet::Read, "Reads the content of me from the stream <IS>. me is first cleared.", py::arg("IS"));
cls_GeomTools_SurfaceSet.def_static("PrintSurface_", [](const opencascade::handle<Geom_Surface> & a0, Standard_OStream & a1) -> void { return GeomTools_SurfaceSet::PrintSurface(a0, a1); });
cls_GeomTools_SurfaceSet.def_static("PrintSurface_", (void (*)(const opencascade::handle<Geom_Surface> &, Standard_OStream &, const Standard_Boolean)) &GeomTools_SurfaceSet::PrintSurface, "Dumps the surface on the stream, if compact is True use the compact format that can be read back.", py::arg("S"), py::arg("OS"), py::arg("compact"));
cls_GeomTools_SurfaceSet.def_static("ReadSurface_", (opencascade::handle<Geom_Surface> (*)(Standard_IStream &)) &GeomTools_SurfaceSet::ReadSurface, "Reads the surface from the stream. The surface is assumed to have been written with the Print method (compact = True).", py::arg("IS"));
cls_GeomTools_SurfaceSet.def("SetProgress", (void (GeomTools_SurfaceSet::*)(const opencascade::handle<Message_ProgressIndicator> &)) &GeomTools_SurfaceSet::SetProgress, "None", py::arg("PR"));
cls_GeomTools_SurfaceSet.def("GetProgress", (opencascade::handle<Message_ProgressIndicator> (GeomTools_SurfaceSet::*)() const) &GeomTools_SurfaceSet::GetProgress, "None");

// Enums

}