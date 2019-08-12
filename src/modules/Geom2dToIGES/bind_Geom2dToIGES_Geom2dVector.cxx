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
#include <IGESGeom_Direction.hxx>
#include <Geom2d_Vector.hxx>
#include <Geom2d_VectorWithMagnitude.hxx>
#include <Geom2d_Direction.hxx>
#include <Geom2dToIGES_Geom2dVector.hxx>

void bind_Geom2dToIGES_Geom2dVector(py::module &mod){

py::class_<Geom2dToIGES_Geom2dVector, std::unique_ptr<Geom2dToIGES_Geom2dVector, Deleter<Geom2dToIGES_Geom2dVector>>, Geom2dToIGES_Geom2dEntity> cls_Geom2dToIGES_Geom2dVector(mod, "Geom2dToIGES_Geom2dVector", "This class implements the transfer of the Vector from Geom2d to IGES . These can be : . Vector * Direction * VectorWithMagnitude");

// Constructors
cls_Geom2dToIGES_Geom2dVector.def(py::init<>());
cls_Geom2dToIGES_Geom2dVector.def(py::init<const Geom2dToIGES_Geom2dEntity &>(), py::arg("G2dE"));

// Fields

// Methods
// cls_Geom2dToIGES_Geom2dVector.def_static("operator new_", (void * (*)(size_t)) &Geom2dToIGES_Geom2dVector::operator new, "None", py::arg("theSize"));
// cls_Geom2dToIGES_Geom2dVector.def_static("operator delete_", (void (*)(void *)) &Geom2dToIGES_Geom2dVector::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dToIGES_Geom2dVector.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dToIGES_Geom2dVector::operator new[], "None", py::arg("theSize"));
// cls_Geom2dToIGES_Geom2dVector.def_static("operator delete[]_", (void (*)(void *)) &Geom2dToIGES_Geom2dVector::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dToIGES_Geom2dVector.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dToIGES_Geom2dVector::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dToIGES_Geom2dVector.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dToIGES_Geom2dVector::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dToIGES_Geom2dVector.def("Transfer2dVector", (opencascade::handle<IGESGeom_Direction> (Geom2dToIGES_Geom2dVector::*)(const opencascade::handle<Geom2d_Vector> &)) &Geom2dToIGES_Geom2dVector::Transfer2dVector, "Transfert a GeometryEntity which answer True to the member : BRepToIGES::IsGeomVector(Geometry). If this Entity could not be converted, this member returns a NullEntity.", py::arg("start"));
cls_Geom2dToIGES_Geom2dVector.def("Transfer2dVector", (opencascade::handle<IGESGeom_Direction> (Geom2dToIGES_Geom2dVector::*)(const opencascade::handle<Geom2d_VectorWithMagnitude> &)) &Geom2dToIGES_Geom2dVector::Transfer2dVector, "None", py::arg("start"));
cls_Geom2dToIGES_Geom2dVector.def("Transfer2dVector", (opencascade::handle<IGESGeom_Direction> (Geom2dToIGES_Geom2dVector::*)(const opencascade::handle<Geom2d_Direction> &)) &Geom2dToIGES_Geom2dVector::Transfer2dVector, "None", py::arg("start"));

// Enums

}