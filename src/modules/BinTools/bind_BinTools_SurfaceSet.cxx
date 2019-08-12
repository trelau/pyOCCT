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
#include <TColStd_IndexedMapOfTransient.hxx>
#include <BinTools_SurfaceSet.hxx>

void bind_BinTools_SurfaceSet(py::module &mod){

py::class_<BinTools_SurfaceSet, std::unique_ptr<BinTools_SurfaceSet, Deleter<BinTools_SurfaceSet>>> cls_BinTools_SurfaceSet(mod, "BinTools_SurfaceSet", "Stores a set of Surfaces from Geom in binary format.");

// Constructors
cls_BinTools_SurfaceSet.def(py::init<>());

// Fields

// Methods
// cls_BinTools_SurfaceSet.def_static("operator new_", (void * (*)(size_t)) &BinTools_SurfaceSet::operator new, "None", py::arg("theSize"));
// cls_BinTools_SurfaceSet.def_static("operator delete_", (void (*)(void *)) &BinTools_SurfaceSet::operator delete, "None", py::arg("theAddress"));
// cls_BinTools_SurfaceSet.def_static("operator new[]_", (void * (*)(size_t)) &BinTools_SurfaceSet::operator new[], "None", py::arg("theSize"));
// cls_BinTools_SurfaceSet.def_static("operator delete[]_", (void (*)(void *)) &BinTools_SurfaceSet::operator delete[], "None", py::arg("theAddress"));
// cls_BinTools_SurfaceSet.def_static("operator new_", (void * (*)(size_t, void *)) &BinTools_SurfaceSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BinTools_SurfaceSet.def_static("operator delete_", (void (*)(void *, void *)) &BinTools_SurfaceSet::operator delete, "None", py::arg(""), py::arg(""));
cls_BinTools_SurfaceSet.def("Clear", (void (BinTools_SurfaceSet::*)()) &BinTools_SurfaceSet::Clear, "Clears the content of the set.");
cls_BinTools_SurfaceSet.def("Add", (Standard_Integer (BinTools_SurfaceSet::*)(const opencascade::handle<Geom_Surface> &)) &BinTools_SurfaceSet::Add, "Incorporate a new Surface in the set and returns its index.", py::arg("S"));
cls_BinTools_SurfaceSet.def("Surface", (opencascade::handle<Geom_Surface> (BinTools_SurfaceSet::*)(const Standard_Integer) const) &BinTools_SurfaceSet::Surface, "Returns the Surface of index <I>.", py::arg("I"));
cls_BinTools_SurfaceSet.def("Index", (Standard_Integer (BinTools_SurfaceSet::*)(const opencascade::handle<Geom_Surface> &) const) &BinTools_SurfaceSet::Index, "Returns the index of <L>.", py::arg("S"));
cls_BinTools_SurfaceSet.def("Write", (void (BinTools_SurfaceSet::*)(Standard_OStream &) const) &BinTools_SurfaceSet::Write, "Writes the content of me on the stream <OS> in binary format that can be read back by Read.", py::arg("OS"));
cls_BinTools_SurfaceSet.def("Read", (void (BinTools_SurfaceSet::*)(Standard_IStream &)) &BinTools_SurfaceSet::Read, "Reads the content of me from the stream <IS>. me is first cleared.", py::arg("IS"));
cls_BinTools_SurfaceSet.def_static("WriteSurface_", (void (*)(const opencascade::handle<Geom_Surface> &, Standard_OStream &)) &BinTools_SurfaceSet::WriteSurface, "Dumps the surface on the stream in binary format that can be read back.", py::arg("S"), py::arg("OS"));
cls_BinTools_SurfaceSet.def_static("ReadSurface_", (Standard_IStream & (*)(Standard_IStream &, opencascade::handle<Geom_Surface> &)) &BinTools_SurfaceSet::ReadSurface, "Reads the surface from the stream. The surface is assumed to have been written with the Write method.", py::arg("IS"), py::arg("S"));

// Enums

}