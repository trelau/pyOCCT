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
#include <TopAbs_ShapeEnum.hxx>
#include <BOPDS_Tools.hxx>

void bind_BOPDS_Tools(py::module &mod){

py::class_<BOPDS_Tools, std::unique_ptr<BOPDS_Tools>> cls_BOPDS_Tools(mod, "BOPDS_Tools", "The class BOPDS_Tools contains a set auxiliary static functions of the package BOPDS");

// Constructors

// Fields

// Methods
// cls_BOPDS_Tools.def_static("operator new_", (void * (*)(size_t)) &BOPDS_Tools::operator new, "None", py::arg("theSize"));
// cls_BOPDS_Tools.def_static("operator delete_", (void (*)(void *)) &BOPDS_Tools::operator delete, "None", py::arg("theAddress"));
// cls_BOPDS_Tools.def_static("operator new[]_", (void * (*)(size_t)) &BOPDS_Tools::operator new[], "None", py::arg("theSize"));
// cls_BOPDS_Tools.def_static("operator delete[]_", (void (*)(void *)) &BOPDS_Tools::operator delete[], "None", py::arg("theAddress"));
// cls_BOPDS_Tools.def_static("operator new_", (void * (*)(size_t, void *)) &BOPDS_Tools::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPDS_Tools.def_static("operator delete_", (void (*)(void *, void *)) &BOPDS_Tools::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPDS_Tools.def_static("TypeToInteger_", (Standard_Integer (*)(const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &BOPDS_Tools::TypeToInteger, "Converts the conmbination of two types of shape <theT1>,<theT2> to the one integer value, that is returned", py::arg("theT1"), py::arg("theT2"));
cls_BOPDS_Tools.def_static("TypeToInteger_", (Standard_Integer (*)(const TopAbs_ShapeEnum)) &BOPDS_Tools::TypeToInteger, "Converts the type of shape <theT>, to integer value, that is returned", py::arg("theT"));
cls_BOPDS_Tools.def_static("HasBRep_", (Standard_Boolean (*)(const TopAbs_ShapeEnum)) &BOPDS_Tools::HasBRep, "Returns true if the type <theT> correspond to a shape having boundary representation", py::arg("theT"));
cls_BOPDS_Tools.def_static("IsInterfering_", (Standard_Boolean (*)(const TopAbs_ShapeEnum)) &BOPDS_Tools::IsInterfering, "Returns true if the type <theT> can be participant of an interference", py::arg("theT"));

// Enums

}