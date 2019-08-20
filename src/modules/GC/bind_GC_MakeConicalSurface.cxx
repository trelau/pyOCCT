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
#include <GC_Root.hxx>
#include <Standard.hxx>
#include <gp_Ax2.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Cone.hxx>
#include <gp_Pnt.hxx>
#include <Standard_Handle.hxx>
#include <Geom_ConicalSurface.hxx>
#include <GC_MakeConicalSurface.hxx>

void bind_GC_MakeConicalSurface(py::module &mod){

py::class_<GC_MakeConicalSurface, std::unique_ptr<GC_MakeConicalSurface>, GC_Root> cls_GC_MakeConicalSurface(mod, "GC_MakeConicalSurface", "This class implements the following algorithms used to create a ConicalSurface from Geom. * Create a ConicalSurface parallel to another and passing through a point. * Create a ConicalSurface parallel to another at a distance <Dist>. * Create a ConicalSurface by 4 points. * Create a ConicalSurface by its axis and 2 points. * Create a ConicalSurface by 2 points and 2 radius. The local coordinate system of the ConicalSurface is defined with an axis placement (see class ElementarySurface).");

// Constructors
cls_GC_MakeConicalSurface.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real>(), py::arg("A2"), py::arg("Ang"), py::arg("Radius"));
cls_GC_MakeConicalSurface.def(py::init<const gp_Cone &>(), py::arg("C"));
cls_GC_MakeConicalSurface.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("P4"));
cls_GC_MakeConicalSurface.def(py::init<const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real>(), py::arg("P1"), py::arg("P2"), py::arg("R1"), py::arg("R2"));

// Fields

// Methods
// cls_GC_MakeConicalSurface.def_static("operator new_", (void * (*)(size_t)) &GC_MakeConicalSurface::operator new, "None", py::arg("theSize"));
// cls_GC_MakeConicalSurface.def_static("operator delete_", (void (*)(void *)) &GC_MakeConicalSurface::operator delete, "None", py::arg("theAddress"));
// cls_GC_MakeConicalSurface.def_static("operator new[]_", (void * (*)(size_t)) &GC_MakeConicalSurface::operator new[], "None", py::arg("theSize"));
// cls_GC_MakeConicalSurface.def_static("operator delete[]_", (void (*)(void *)) &GC_MakeConicalSurface::operator delete[], "None", py::arg("theAddress"));
// cls_GC_MakeConicalSurface.def_static("operator new_", (void * (*)(size_t, void *)) &GC_MakeConicalSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GC_MakeConicalSurface.def_static("operator delete_", (void (*)(void *, void *)) &GC_MakeConicalSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_GC_MakeConicalSurface.def("Value", (const opencascade::handle<Geom_ConicalSurface> & (GC_MakeConicalSurface::*)() const) &GC_MakeConicalSurface::Value, "Returns the constructed cone. Exceptions StdFail_NotDone if no cone is constructed.");

// Enums

}