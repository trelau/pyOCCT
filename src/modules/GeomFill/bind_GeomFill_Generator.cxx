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
#include <GeomFill_Profiler.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <GeomFill_Generator.hxx>

void bind_GeomFill_Generator(py::module &mod){

py::class_<GeomFill_Generator, GeomFill_Profiler> cls_GeomFill_Generator(mod, "GeomFill_Generator", "Create a surface using generating lines. Inherits profiler. The surface will be a BSplineSurface passing by all the curves described in the generator. The VDegree of the resulting surface is 1.");

// Constructors
cls_GeomFill_Generator.def(py::init<>());

// Fields

// Methods
// cls_GeomFill_Generator.def_static("operator new_", (void * (*)(size_t)) &GeomFill_Generator::operator new, "None", py::arg("theSize"));
// cls_GeomFill_Generator.def_static("operator delete_", (void (*)(void *)) &GeomFill_Generator::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_Generator.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_Generator::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_Generator.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_Generator::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_Generator.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_Generator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_Generator.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_Generator::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_Generator.def("Perform", (void (GeomFill_Generator::*)(const Standard_Real)) &GeomFill_Generator::Perform, "Converts all curves to BSplineCurves. Set them to the common profile. Compute the surface (degv = 1). <PTol> is used to compare 2 knots.", py::arg("PTol"));
cls_GeomFill_Generator.def("Surface", (const opencascade::handle<Geom_Surface> & (GeomFill_Generator::*)() const) &GeomFill_Generator::Surface, "None");

// Enums

}