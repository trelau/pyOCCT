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
#include <GeomToIGES_GeomEntity.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <IGESGeom_Direction.hxx>
#include <Geom_Vector.hxx>
#include <Geom_VectorWithMagnitude.hxx>
#include <Geom_Direction.hxx>
#include <GeomToIGES_GeomVector.hxx>

void bind_GeomToIGES_GeomVector(py::module &mod){

py::class_<GeomToIGES_GeomVector, GeomToIGES_GeomEntity> cls_GeomToIGES_GeomVector(mod, "GeomToIGES_GeomVector", "This class implements the transfer of the Vector from Geom to IGES . These can be : . Vector * Direction * VectorWithMagnitude");

// Constructors
cls_GeomToIGES_GeomVector.def(py::init<>());
cls_GeomToIGES_GeomVector.def(py::init<const GeomToIGES_GeomEntity &>(), py::arg("GE"));

// Fields

// Methods
// cls_GeomToIGES_GeomVector.def_static("operator new_", (void * (*)(size_t)) &GeomToIGES_GeomVector::operator new, "None", py::arg("theSize"));
// cls_GeomToIGES_GeomVector.def_static("operator delete_", (void (*)(void *)) &GeomToIGES_GeomVector::operator delete, "None", py::arg("theAddress"));
// cls_GeomToIGES_GeomVector.def_static("operator new[]_", (void * (*)(size_t)) &GeomToIGES_GeomVector::operator new[], "None", py::arg("theSize"));
// cls_GeomToIGES_GeomVector.def_static("operator delete[]_", (void (*)(void *)) &GeomToIGES_GeomVector::operator delete[], "None", py::arg("theAddress"));
// cls_GeomToIGES_GeomVector.def_static("operator new_", (void * (*)(size_t, void *)) &GeomToIGES_GeomVector::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomToIGES_GeomVector.def_static("operator delete_", (void (*)(void *, void *)) &GeomToIGES_GeomVector::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomToIGES_GeomVector.def("TransferVector", (opencascade::handle<IGESGeom_Direction> (GeomToIGES_GeomVector::*)(const opencascade::handle<Geom_Vector> &)) &GeomToIGES_GeomVector::TransferVector, "Transfert a GeometryEntity which answer True to the member : BRepToIGES::IsGeomVector(Geometry). If this Entity could not be converted, this member returns a NullEntity.", py::arg("start"));
cls_GeomToIGES_GeomVector.def("TransferVector", (opencascade::handle<IGESGeom_Direction> (GeomToIGES_GeomVector::*)(const opencascade::handle<Geom_VectorWithMagnitude> &)) &GeomToIGES_GeomVector::TransferVector, "None", py::arg("start"));
cls_GeomToIGES_GeomVector.def("TransferVector", (opencascade::handle<IGESGeom_Direction> (GeomToIGES_GeomVector::*)(const opencascade::handle<Geom_Direction> &)) &GeomToIGES_GeomVector::TransferVector, "None", py::arg("start"));

// Enums

}