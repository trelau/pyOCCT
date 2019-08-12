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
#include <Geom_Surface.hxx>
#include <StepGeom_Surface.hxx>
#include <GeomToStep_MakeSurface.hxx>

void bind_GeomToStep_MakeSurface(py::module &mod){

py::class_<GeomToStep_MakeSurface, std::unique_ptr<GeomToStep_MakeSurface, Deleter<GeomToStep_MakeSurface>>, GeomToStep_Root> cls_GeomToStep_MakeSurface(mod, "GeomToStep_MakeSurface", "This class implements the mapping between classes Surface from Geom and the class Surface from StepGeom which describes a Surface from prostep. As Surface is an abstract Surface this class is an access to the sub-class required.");

// Constructors
cls_GeomToStep_MakeSurface.def(py::init<const opencascade::handle<Geom_Surface> &>(), py::arg("C"));

// Fields

// Methods
// cls_GeomToStep_MakeSurface.def_static("operator new_", (void * (*)(size_t)) &GeomToStep_MakeSurface::operator new, "None", py::arg("theSize"));
// cls_GeomToStep_MakeSurface.def_static("operator delete_", (void (*)(void *)) &GeomToStep_MakeSurface::operator delete, "None", py::arg("theAddress"));
// cls_GeomToStep_MakeSurface.def_static("operator new[]_", (void * (*)(size_t)) &GeomToStep_MakeSurface::operator new[], "None", py::arg("theSize"));
// cls_GeomToStep_MakeSurface.def_static("operator delete[]_", (void (*)(void *)) &GeomToStep_MakeSurface::operator delete[], "None", py::arg("theAddress"));
// cls_GeomToStep_MakeSurface.def_static("operator new_", (void * (*)(size_t, void *)) &GeomToStep_MakeSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomToStep_MakeSurface.def_static("operator delete_", (void (*)(void *, void *)) &GeomToStep_MakeSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomToStep_MakeSurface.def("Value", (const opencascade::handle<StepGeom_Surface> & (GeomToStep_MakeSurface::*)() const) &GeomToStep_MakeSurface::Value, "None");

// Enums

}