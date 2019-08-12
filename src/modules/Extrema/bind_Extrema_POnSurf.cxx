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
#include <gp_Pnt.hxx>
#include <Extrema_POnSurf.hxx>

void bind_Extrema_POnSurf(py::module &mod){

py::class_<Extrema_POnSurf, std::unique_ptr<Extrema_POnSurf, Deleter<Extrema_POnSurf>>> cls_Extrema_POnSurf(mod, "Extrema_POnSurf", "Definition of a point on surface.");

// Constructors
cls_Extrema_POnSurf.def(py::init<>());
cls_Extrema_POnSurf.def(py::init<const Standard_Real, const Standard_Real, const gp_Pnt &>(), py::arg("U"), py::arg("V"), py::arg("P"));

// Fields

// Methods
// cls_Extrema_POnSurf.def_static("operator new_", (void * (*)(size_t)) &Extrema_POnSurf::operator new, "None", py::arg("theSize"));
// cls_Extrema_POnSurf.def_static("operator delete_", (void (*)(void *)) &Extrema_POnSurf::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_POnSurf.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_POnSurf::operator new[], "None", py::arg("theSize"));
// cls_Extrema_POnSurf.def_static("operator delete[]_", (void (*)(void *)) &Extrema_POnSurf::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_POnSurf.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_POnSurf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_POnSurf.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_POnSurf::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_POnSurf.def("Value", (const gp_Pnt & (Extrema_POnSurf::*)() const) &Extrema_POnSurf::Value, "Returns the 3d point.");
cls_Extrema_POnSurf.def("SetParameters", (void (Extrema_POnSurf::*)(const Standard_Real, const Standard_Real, const gp_Pnt &)) &Extrema_POnSurf::SetParameters, "Sets the params of current POnSurf instance. (e.g. to the point to be projected).", py::arg("theU"), py::arg("theV"), py::arg("thePnt"));
cls_Extrema_POnSurf.def("Parameter", [](Extrema_POnSurf &self, Standard_Real & U, Standard_Real & V){ self.Parameter(U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "Returns the parameter values on the surface.", py::arg("U"), py::arg("V"));

// Enums

}