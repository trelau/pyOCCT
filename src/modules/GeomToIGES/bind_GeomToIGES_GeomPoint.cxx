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
#include <IGESGeom_Point.hxx>
#include <Geom_Point.hxx>
#include <Geom_CartesianPoint.hxx>
#include <GeomToIGES_GeomPoint.hxx>

void bind_GeomToIGES_GeomPoint(py::module &mod){

py::class_<GeomToIGES_GeomPoint, std::unique_ptr<GeomToIGES_GeomPoint, Deleter<GeomToIGES_GeomPoint>>, GeomToIGES_GeomEntity> cls_GeomToIGES_GeomPoint(mod, "GeomToIGES_GeomPoint", "This class implements the transfer of the Point Entity from Geom to IGES . These are : . Point * CartesianPoint");

// Constructors
cls_GeomToIGES_GeomPoint.def(py::init<>());
cls_GeomToIGES_GeomPoint.def(py::init<const GeomToIGES_GeomEntity &>(), py::arg("GE"));

// Fields

// Methods
// cls_GeomToIGES_GeomPoint.def_static("operator new_", (void * (*)(size_t)) &GeomToIGES_GeomPoint::operator new, "None", py::arg("theSize"));
// cls_GeomToIGES_GeomPoint.def_static("operator delete_", (void (*)(void *)) &GeomToIGES_GeomPoint::operator delete, "None", py::arg("theAddress"));
// cls_GeomToIGES_GeomPoint.def_static("operator new[]_", (void * (*)(size_t)) &GeomToIGES_GeomPoint::operator new[], "None", py::arg("theSize"));
// cls_GeomToIGES_GeomPoint.def_static("operator delete[]_", (void (*)(void *)) &GeomToIGES_GeomPoint::operator delete[], "None", py::arg("theAddress"));
// cls_GeomToIGES_GeomPoint.def_static("operator new_", (void * (*)(size_t, void *)) &GeomToIGES_GeomPoint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomToIGES_GeomPoint.def_static("operator delete_", (void (*)(void *, void *)) &GeomToIGES_GeomPoint::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomToIGES_GeomPoint.def("TransferPoint", (opencascade::handle<IGESGeom_Point> (GeomToIGES_GeomPoint::*)(const opencascade::handle<Geom_Point> &)) &GeomToIGES_GeomPoint::TransferPoint, "Transfert a Point from Geom to IGES. If this Entity could not be converted, this member returns a NullEntity.", py::arg("start"));
cls_GeomToIGES_GeomPoint.def("TransferPoint", (opencascade::handle<IGESGeom_Point> (GeomToIGES_GeomPoint::*)(const opencascade::handle<Geom_CartesianPoint> &)) &GeomToIGES_GeomPoint::TransferPoint, "Transfert a CartesianPoint from Geom to IGES. If this Entity could not be converted, this member returns a NullEntity.", py::arg("start"));

// Enums

}