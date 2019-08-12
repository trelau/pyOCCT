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
#include <math_FunctionSample.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomLib_LogSample.hxx>

void bind_GeomLib_LogSample(py::module &mod){

py::class_<GeomLib_LogSample, std::unique_ptr<GeomLib_LogSample, Deleter<GeomLib_LogSample>>, math_FunctionSample> cls_GeomLib_LogSample(mod, "GeomLib_LogSample", "None");

// Constructors
cls_GeomLib_LogSample.def(py::init<const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("A"), py::arg("B"), py::arg("N"));

// Fields

// Methods
// cls_GeomLib_LogSample.def_static("operator new_", (void * (*)(size_t)) &GeomLib_LogSample::operator new, "None", py::arg("theSize"));
// cls_GeomLib_LogSample.def_static("operator delete_", (void (*)(void *)) &GeomLib_LogSample::operator delete, "None", py::arg("theAddress"));
// cls_GeomLib_LogSample.def_static("operator new[]_", (void * (*)(size_t)) &GeomLib_LogSample::operator new[], "None", py::arg("theSize"));
// cls_GeomLib_LogSample.def_static("operator delete[]_", (void (*)(void *)) &GeomLib_LogSample::operator delete[], "None", py::arg("theAddress"));
// cls_GeomLib_LogSample.def_static("operator new_", (void * (*)(size_t, void *)) &GeomLib_LogSample::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomLib_LogSample.def_static("operator delete_", (void (*)(void *, void *)) &GeomLib_LogSample::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomLib_LogSample.def("GetParameter", (Standard_Real (GeomLib_LogSample::*)(const Standard_Integer) const) &GeomLib_LogSample::GetParameter, "Returns the value of parameter of the point of range Index : A + ((Index-1)/(NbPoints-1))*B. An exception is raised if Index<=0 or Index>NbPoints.", py::arg("Index"));

// Enums

}