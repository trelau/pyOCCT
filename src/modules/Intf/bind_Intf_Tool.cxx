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
#include <gp_Lin2d.hxx>
#include <Bnd_Box2d.hxx>
#include <gp_Hypr2d.hxx>
#include <gp_Parab2d.hxx>
#include <gp_Lin.hxx>
#include <Bnd_Box.hxx>
#include <gp_Hypr.hxx>
#include <gp_Parab.hxx>
#include <Standard_TypeDef.hxx>
#include <Intf_Tool.hxx>

void bind_Intf_Tool(py::module &mod){

py::class_<Intf_Tool> cls_Intf_Tool(mod, "Intf_Tool", "Provides services to create box for infinites lines in a given contexte.");

// Constructors
cls_Intf_Tool.def(py::init<>());

// Fields

// Methods
// cls_Intf_Tool.def_static("operator new_", (void * (*)(size_t)) &Intf_Tool::operator new, "None", py::arg("theSize"));
// cls_Intf_Tool.def_static("operator delete_", (void (*)(void *)) &Intf_Tool::operator delete, "None", py::arg("theAddress"));
// cls_Intf_Tool.def_static("operator new[]_", (void * (*)(size_t)) &Intf_Tool::operator new[], "None", py::arg("theSize"));
// cls_Intf_Tool.def_static("operator delete[]_", (void (*)(void *)) &Intf_Tool::operator delete[], "None", py::arg("theAddress"));
// cls_Intf_Tool.def_static("operator new_", (void * (*)(size_t, void *)) &Intf_Tool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Intf_Tool.def_static("operator delete_", (void (*)(void *, void *)) &Intf_Tool::operator delete, "None", py::arg(""), py::arg(""));
cls_Intf_Tool.def("Lin2dBox", (void (Intf_Tool::*)(const gp_Lin2d &, const Bnd_Box2d &, Bnd_Box2d &)) &Intf_Tool::Lin2dBox, "None", py::arg("theLin2d"), py::arg("bounding"), py::arg("boxLin"));
cls_Intf_Tool.def("Hypr2dBox", (void (Intf_Tool::*)(const gp_Hypr2d &, const Bnd_Box2d &, Bnd_Box2d &)) &Intf_Tool::Hypr2dBox, "None", py::arg("theHypr2d"), py::arg("bounding"), py::arg("boxHypr"));
cls_Intf_Tool.def("Parab2dBox", (void (Intf_Tool::*)(const gp_Parab2d &, const Bnd_Box2d &, Bnd_Box2d &)) &Intf_Tool::Parab2dBox, "None", py::arg("theParab2d"), py::arg("bounding"), py::arg("boxHypr"));
cls_Intf_Tool.def("LinBox", (void (Intf_Tool::*)(const gp_Lin &, const Bnd_Box &, Bnd_Box &)) &Intf_Tool::LinBox, "None", py::arg("theLin"), py::arg("bounding"), py::arg("boxLin"));
cls_Intf_Tool.def("HyprBox", (void (Intf_Tool::*)(const gp_Hypr &, const Bnd_Box &, Bnd_Box &)) &Intf_Tool::HyprBox, "None", py::arg("theHypr"), py::arg("bounding"), py::arg("boxHypr"));
cls_Intf_Tool.def("ParabBox", (void (Intf_Tool::*)(const gp_Parab &, const Bnd_Box &, Bnd_Box &)) &Intf_Tool::ParabBox, "None", py::arg("theParab"), py::arg("bounding"), py::arg("boxHypr"));
cls_Intf_Tool.def("NbSegments", (Standard_Integer (Intf_Tool::*)() const) &Intf_Tool::NbSegments, "None");
cls_Intf_Tool.def("BeginParam", (Standard_Real (Intf_Tool::*)(const Standard_Integer) const) &Intf_Tool::BeginParam, "None", py::arg("SegmentNum"));
cls_Intf_Tool.def("EndParam", (Standard_Real (Intf_Tool::*)(const Standard_Integer) const) &Intf_Tool::EndParam, "None", py::arg("SegmentNum"));

// Enums

}