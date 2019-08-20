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
#include <BRepPrim_GWedge.hxx>
#include <Standard.hxx>
#include <gp_Ax2.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepPrim_Wedge.hxx>

void bind_BRepPrim_Wedge(py::module &mod){

py::class_<BRepPrim_Wedge, std::unique_ptr<BRepPrim_Wedge>, BRepPrim_GWedge> cls_BRepPrim_Wedge(mod, "BRepPrim_Wedge", "Provides constructors without Builders.");

// Constructors
cls_BRepPrim_Wedge.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Axes"), py::arg("dx"), py::arg("dy"), py::arg("dz"));
cls_BRepPrim_Wedge.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Axes"), py::arg("dx"), py::arg("dy"), py::arg("dz"), py::arg("ltx"));
cls_BRepPrim_Wedge.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Axes"), py::arg("xmin"), py::arg("ymin"), py::arg("zmin"), py::arg("z2min"), py::arg("x2min"), py::arg("xmax"), py::arg("ymax"), py::arg("zmax"), py::arg("z2max"), py::arg("x2max"));

// Fields

// Methods
// cls_BRepPrim_Wedge.def_static("operator new_", (void * (*)(size_t)) &BRepPrim_Wedge::operator new, "None", py::arg("theSize"));
// cls_BRepPrim_Wedge.def_static("operator delete_", (void (*)(void *)) &BRepPrim_Wedge::operator delete, "None", py::arg("theAddress"));
// cls_BRepPrim_Wedge.def_static("operator new[]_", (void * (*)(size_t)) &BRepPrim_Wedge::operator new[], "None", py::arg("theSize"));
// cls_BRepPrim_Wedge.def_static("operator delete[]_", (void (*)(void *)) &BRepPrim_Wedge::operator delete[], "None", py::arg("theAddress"));
// cls_BRepPrim_Wedge.def_static("operator new_", (void * (*)(size_t, void *)) &BRepPrim_Wedge::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepPrim_Wedge.def_static("operator delete_", (void (*)(void *, void *)) &BRepPrim_Wedge::operator delete, "None", py::arg(""), py::arg(""));

// Enums

}