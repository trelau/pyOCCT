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
#include <Law_BSpFunc.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Law_S.hxx>
#include <Standard_Type.hxx>

void bind_Law_S(py::module &mod){

py::class_<Law_S, opencascade::handle<Law_S>, Law_BSpFunc> cls_Law_S(mod, "Law_S", "Describes an 'S' evolution law.");

// Constructors
cls_Law_S.def(py::init<>());

// Fields

// Methods
cls_Law_S.def("Set", (void (Law_S::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Law_S::Set, "Defines this S evolution law by assigning both: - the bounds Pdeb and Pfin of the parameter, and - the values Valdeb and Valfin of the function at these two parametric bounds. The function is assumed to have the first derivatives equal to 0 at the two parameter points Pdeb and Pfin.", py::arg("Pdeb"), py::arg("Valdeb"), py::arg("Pfin"), py::arg("Valfin"));
cls_Law_S.def("Set", (void (Law_S::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Law_S::Set, "Defines this S evolution law by assigning - the bounds Pdeb and Pfin of the parameter, - the values Valdeb and Valfin of the function at these two parametric bounds, and - the values Ddeb and Dfin of the first derivative of the function at these two parametric bounds.", py::arg("Pdeb"), py::arg("Valdeb"), py::arg("Ddeb"), py::arg("Pfin"), py::arg("Valfin"), py::arg("Dfin"));
cls_Law_S.def_static("get_type_name_", (const char * (*)()) &Law_S::get_type_name, "None");
cls_Law_S.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Law_S::get_type_descriptor, "None");
cls_Law_S.def("DynamicType", (const opencascade::handle<Standard_Type> & (Law_S::*)() const) &Law_S::DynamicType, "None");

// Enums

}