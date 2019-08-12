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
#include <IGESData_IGESEntity.hxx>
#include <Standard_Handle.hxx>
#include <IGESSolid_Shell.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESSolid_HArray1OfShell.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <IGESSolid_ManifoldSolid.hxx>
#include <Standard_Type.hxx>

void bind_IGESSolid_ManifoldSolid(py::module &mod){

py::class_<IGESSolid_ManifoldSolid, opencascade::handle<IGESSolid_ManifoldSolid>, IGESData_IGESEntity> cls_IGESSolid_ManifoldSolid(mod, "IGESSolid_ManifoldSolid", "defines ManifoldSolid, Type <186> Form Number <0> in package IGESSolid A manifold solid is a bounded, closed, and finite volume in three dimensional Euclidean space");

// Constructors
cls_IGESSolid_ManifoldSolid.def(py::init<>());

// Fields

// Methods
cls_IGESSolid_ManifoldSolid.def("Init", (void (IGESSolid_ManifoldSolid::*)(const opencascade::handle<IGESSolid_Shell> &, const Standard_Boolean, const opencascade::handle<IGESSolid_HArray1OfShell> &, const opencascade::handle<TColStd_HArray1OfInteger> &)) &IGESSolid_ManifoldSolid::Init, "This method is used to set the fields of the class ManifoldSolid - aShell : pointer to the shell - shellflag : orientation flag of shell - voidShells : the void shells - voidShellFlags : orientation of the void shells raises exception if length of voidShells and voidShellFlags do not match", py::arg("aShell"), py::arg("shellflag"), py::arg("voidShells"), py::arg("voidShellFlags"));
cls_IGESSolid_ManifoldSolid.def("Shell", (opencascade::handle<IGESSolid_Shell> (IGESSolid_ManifoldSolid::*)() const) &IGESSolid_ManifoldSolid::Shell, "returns the Shell entity which is being referred");
cls_IGESSolid_ManifoldSolid.def("OrientationFlag", (Standard_Boolean (IGESSolid_ManifoldSolid::*)() const) &IGESSolid_ManifoldSolid::OrientationFlag, "returns the orientation flag of the shell");
cls_IGESSolid_ManifoldSolid.def("NbVoidShells", (Standard_Integer (IGESSolid_ManifoldSolid::*)() const) &IGESSolid_ManifoldSolid::NbVoidShells, "returns the number of void shells");
cls_IGESSolid_ManifoldSolid.def("VoidShell", (opencascade::handle<IGESSolid_Shell> (IGESSolid_ManifoldSolid::*)(const Standard_Integer) const) &IGESSolid_ManifoldSolid::VoidShell, "returns Index'th void shell. raises exception if Index <= 0 or Index > NbVoidShells()", py::arg("Index"));
cls_IGESSolid_ManifoldSolid.def("VoidOrientationFlag", (Standard_Boolean (IGESSolid_ManifoldSolid::*)(const Standard_Integer) const) &IGESSolid_ManifoldSolid::VoidOrientationFlag, "returns Index'th orientation flag. raises exception if Index <= 0 or Index > NbVoidShells()", py::arg("Index"));
cls_IGESSolid_ManifoldSolid.def_static("get_type_name_", (const char * (*)()) &IGESSolid_ManifoldSolid::get_type_name, "None");
cls_IGESSolid_ManifoldSolid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_ManifoldSolid::get_type_descriptor, "None");
cls_IGESSolid_ManifoldSolid.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_ManifoldSolid::*)() const) &IGESSolid_ManifoldSolid::DynamicType, "None");

// Enums

}