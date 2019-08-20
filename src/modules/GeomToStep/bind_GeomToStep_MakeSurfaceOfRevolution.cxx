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
#include <Geom_SurfaceOfRevolution.hxx>
#include <StepGeom_SurfaceOfRevolution.hxx>
#include <GeomToStep_MakeSurfaceOfRevolution.hxx>

void bind_GeomToStep_MakeSurfaceOfRevolution(py::module &mod){

py::class_<GeomToStep_MakeSurfaceOfRevolution, std::unique_ptr<GeomToStep_MakeSurfaceOfRevolution>, GeomToStep_Root> cls_GeomToStep_MakeSurfaceOfRevolution(mod, "GeomToStep_MakeSurfaceOfRevolution", "This class implements the mapping between class SurfaceOfRevolution from Geom and the class SurfaceOfRevolution from StepGeom which describes a surface_of_revolution from Prostep");

// Constructors
cls_GeomToStep_MakeSurfaceOfRevolution.def(py::init<const opencascade::handle<Geom_SurfaceOfRevolution> &>(), py::arg("RevSurf"));

// Fields

// Methods
// cls_GeomToStep_MakeSurfaceOfRevolution.def_static("operator new_", (void * (*)(size_t)) &GeomToStep_MakeSurfaceOfRevolution::operator new, "None", py::arg("theSize"));
// cls_GeomToStep_MakeSurfaceOfRevolution.def_static("operator delete_", (void (*)(void *)) &GeomToStep_MakeSurfaceOfRevolution::operator delete, "None", py::arg("theAddress"));
// cls_GeomToStep_MakeSurfaceOfRevolution.def_static("operator new[]_", (void * (*)(size_t)) &GeomToStep_MakeSurfaceOfRevolution::operator new[], "None", py::arg("theSize"));
// cls_GeomToStep_MakeSurfaceOfRevolution.def_static("operator delete[]_", (void (*)(void *)) &GeomToStep_MakeSurfaceOfRevolution::operator delete[], "None", py::arg("theAddress"));
// cls_GeomToStep_MakeSurfaceOfRevolution.def_static("operator new_", (void * (*)(size_t, void *)) &GeomToStep_MakeSurfaceOfRevolution::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomToStep_MakeSurfaceOfRevolution.def_static("operator delete_", (void (*)(void *, void *)) &GeomToStep_MakeSurfaceOfRevolution::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomToStep_MakeSurfaceOfRevolution.def("Value", (const opencascade::handle<StepGeom_SurfaceOfRevolution> & (GeomToStep_MakeSurfaceOfRevolution::*)() const) &GeomToStep_MakeSurfaceOfRevolution::Value, "None");

// Enums

}