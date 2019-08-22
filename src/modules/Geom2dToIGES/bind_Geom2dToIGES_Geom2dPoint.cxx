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
#include <Geom2dToIGES_Geom2dEntity.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <IGESGeom_Point.hxx>
#include <Geom2d_Point.hxx>
#include <Geom2d_CartesianPoint.hxx>
#include <Geom2dToIGES_Geom2dPoint.hxx>

void bind_Geom2dToIGES_Geom2dPoint(py::module &mod){

py::class_<Geom2dToIGES_Geom2dPoint, Geom2dToIGES_Geom2dEntity> cls_Geom2dToIGES_Geom2dPoint(mod, "Geom2dToIGES_Geom2dPoint", "This class implements the transfer of the Point Entity from Geom2d to IGES . These are : . 2dPoint * 2dCartesianPoint");

// Constructors
cls_Geom2dToIGES_Geom2dPoint.def(py::init<>());
cls_Geom2dToIGES_Geom2dPoint.def(py::init<const Geom2dToIGES_Geom2dEntity &>(), py::arg("G2dE"));

// Fields

// Methods
// cls_Geom2dToIGES_Geom2dPoint.def_static("operator new_", (void * (*)(size_t)) &Geom2dToIGES_Geom2dPoint::operator new, "None", py::arg("theSize"));
// cls_Geom2dToIGES_Geom2dPoint.def_static("operator delete_", (void (*)(void *)) &Geom2dToIGES_Geom2dPoint::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dToIGES_Geom2dPoint.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dToIGES_Geom2dPoint::operator new[], "None", py::arg("theSize"));
// cls_Geom2dToIGES_Geom2dPoint.def_static("operator delete[]_", (void (*)(void *)) &Geom2dToIGES_Geom2dPoint::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dToIGES_Geom2dPoint.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dToIGES_Geom2dPoint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dToIGES_Geom2dPoint.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dToIGES_Geom2dPoint::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dToIGES_Geom2dPoint.def("Transfer2dPoint", (opencascade::handle<IGESGeom_Point> (Geom2dToIGES_Geom2dPoint::*)(const opencascade::handle<Geom2d_Point> &)) &Geom2dToIGES_Geom2dPoint::Transfer2dPoint, "Transfert a Point from Geom to IGES. If this Entity could not be converted, this member returns a NullEntity.", py::arg("start"));
cls_Geom2dToIGES_Geom2dPoint.def("Transfer2dPoint", (opencascade::handle<IGESGeom_Point> (Geom2dToIGES_Geom2dPoint::*)(const opencascade::handle<Geom2d_CartesianPoint> &)) &Geom2dToIGES_Geom2dPoint::Transfer2dPoint, "Transfert a CartesianPoint from Geom to IGES. If this Entity could not be converted, this member returns a NullEntity.", py::arg("start"));

// Enums

}