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
#include <GProp_GProps.hxx>
#include <Standard.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <gp_Pnt.hxx>
#include <BRepGProp_Cinert.hxx>

void bind_BRepGProp_Cinert(py::module &mod){

py::class_<BRepGProp_Cinert, GProp_GProps> cls_BRepGProp_Cinert(mod, "BRepGProp_Cinert", "Computes the global properties of bounded curves in 3D space. The curve must have at least a continuity C1. It can be a curve as defined in the template CurveTool from package GProp. This template gives the minimum of methods required to evaluate the global properties of a curve 3D with the algorithmes of GProp.");

// Constructors
cls_BRepGProp_Cinert.def(py::init<>());
cls_BRepGProp_Cinert.def(py::init<const BRepAdaptor_Curve &, const gp_Pnt &>(), py::arg("C"), py::arg("CLocation"));

// Fields

// Methods
// cls_BRepGProp_Cinert.def_static("operator new_", (void * (*)(size_t)) &BRepGProp_Cinert::operator new, "None", py::arg("theSize"));
// cls_BRepGProp_Cinert.def_static("operator delete_", (void (*)(void *)) &BRepGProp_Cinert::operator delete, "None", py::arg("theAddress"));
// cls_BRepGProp_Cinert.def_static("operator new[]_", (void * (*)(size_t)) &BRepGProp_Cinert::operator new[], "None", py::arg("theSize"));
// cls_BRepGProp_Cinert.def_static("operator delete[]_", (void (*)(void *)) &BRepGProp_Cinert::operator delete[], "None", py::arg("theAddress"));
// cls_BRepGProp_Cinert.def_static("operator new_", (void * (*)(size_t, void *)) &BRepGProp_Cinert::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepGProp_Cinert.def_static("operator delete_", (void (*)(void *, void *)) &BRepGProp_Cinert::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepGProp_Cinert.def("SetLocation", (void (BRepGProp_Cinert::*)(const gp_Pnt &)) &BRepGProp_Cinert::SetLocation, "None", py::arg("CLocation"));
cls_BRepGProp_Cinert.def("Perform", (void (BRepGProp_Cinert::*)(const BRepAdaptor_Curve &)) &BRepGProp_Cinert::Perform, "None", py::arg("C"));

// Enums

}