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
#include <GeomToStep_Root.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Geom_SphericalSurface.hxx>
#include <StepGeom_SphericalSurface.hxx>
#include <GeomToStep_MakeSphericalSurface.hxx>

void bind_GeomToStep_MakeSphericalSurface(py::module &mod){

py::class_<GeomToStep_MakeSphericalSurface, std::unique_ptr<GeomToStep_MakeSphericalSurface>, GeomToStep_Root> cls_GeomToStep_MakeSphericalSurface(mod, "GeomToStep_MakeSphericalSurface", "This class implements the mapping between class SphericalSurface from Geom and the class SphericalSurface from StepGeom which describes a spherical_surface from Prostep");

// Constructors
cls_GeomToStep_MakeSphericalSurface.def(py::init<const opencascade::handle<Geom_SphericalSurface> &>(), py::arg("CSurf"));

// Fields

// Methods
// cls_GeomToStep_MakeSphericalSurface.def_static("operator new_", (void * (*)(size_t)) &GeomToStep_MakeSphericalSurface::operator new, "None", py::arg("theSize"));
// cls_GeomToStep_MakeSphericalSurface.def_static("operator delete_", (void (*)(void *)) &GeomToStep_MakeSphericalSurface::operator delete, "None", py::arg("theAddress"));
// cls_GeomToStep_MakeSphericalSurface.def_static("operator new[]_", (void * (*)(size_t)) &GeomToStep_MakeSphericalSurface::operator new[], "None", py::arg("theSize"));
// cls_GeomToStep_MakeSphericalSurface.def_static("operator delete[]_", (void (*)(void *)) &GeomToStep_MakeSphericalSurface::operator delete[], "None", py::arg("theAddress"));
// cls_GeomToStep_MakeSphericalSurface.def_static("operator new_", (void * (*)(size_t, void *)) &GeomToStep_MakeSphericalSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomToStep_MakeSphericalSurface.def_static("operator delete_", (void (*)(void *, void *)) &GeomToStep_MakeSphericalSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomToStep_MakeSphericalSurface.def("Value", (const opencascade::handle<StepGeom_SphericalSurface> & (GeomToStep_MakeSphericalSurface::*)() const) &GeomToStep_MakeSphericalSurface::Value, "None");

// Enums

}