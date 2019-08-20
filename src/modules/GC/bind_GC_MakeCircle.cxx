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
#include <gp_Circ.hxx>
#include <gp_Ax2.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <gp_Ax1.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Circle.hxx>
#include <GC_MakeCircle.hxx>

void bind_GC_MakeCircle(py::module &mod){

py::class_<GC_MakeCircle, std::unique_ptr<GC_MakeCircle>, GC_Root> cls_GC_MakeCircle(mod, "GC_MakeCircle", "This class implements the following algorithms used to create Cirlec from Geom.");

// Constructors
cls_GC_MakeCircle.def(py::init<const gp_Circ &>(), py::arg("C"));
cls_GC_MakeCircle.def(py::init<const gp_Ax2 &, const Standard_Real>(), py::arg("A2"), py::arg("Radius"));
cls_GC_MakeCircle.def(py::init<const gp_Circ &, const Standard_Real>(), py::arg("Circ"), py::arg("Dist"));
cls_GC_MakeCircle.def(py::init<const gp_Circ &, const gp_Pnt &>(), py::arg("Circ"), py::arg("Point"));
cls_GC_MakeCircle.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"));
cls_GC_MakeCircle.def(py::init<const gp_Pnt &, const gp_Dir &, const Standard_Real>(), py::arg("Center"), py::arg("Norm"), py::arg("Radius"));
cls_GC_MakeCircle.def(py::init<const gp_Pnt &, const gp_Pnt &, const Standard_Real>(), py::arg("Center"), py::arg("PtAxis"), py::arg("Radius"));
cls_GC_MakeCircle.def(py::init<const gp_Ax1 &, const Standard_Real>(), py::arg("Axis"), py::arg("Radius"));

// Fields

// Methods
// cls_GC_MakeCircle.def_static("operator new_", (void * (*)(size_t)) &GC_MakeCircle::operator new, "None", py::arg("theSize"));
// cls_GC_MakeCircle.def_static("operator delete_", (void (*)(void *)) &GC_MakeCircle::operator delete, "None", py::arg("theAddress"));
// cls_GC_MakeCircle.def_static("operator new[]_", (void * (*)(size_t)) &GC_MakeCircle::operator new[], "None", py::arg("theSize"));
// cls_GC_MakeCircle.def_static("operator delete[]_", (void (*)(void *)) &GC_MakeCircle::operator delete[], "None", py::arg("theAddress"));
// cls_GC_MakeCircle.def_static("operator new_", (void * (*)(size_t, void *)) &GC_MakeCircle::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GC_MakeCircle.def_static("operator delete_", (void (*)(void *, void *)) &GC_MakeCircle::operator delete, "None", py::arg(""), py::arg(""));
cls_GC_MakeCircle.def("Value", (const opencascade::handle<Geom_Circle> & (GC_MakeCircle::*)() const) &GC_MakeCircle::Value, "Returns the constructed circle. Exceptions StdFail_NotDone if no circle is constructed.");

// Enums

}