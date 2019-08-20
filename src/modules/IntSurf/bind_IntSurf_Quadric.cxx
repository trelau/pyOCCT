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
#include <gp_Pln.hxx>
#include <gp_Cylinder.hxx>
#include <gp_Sphere.hxx>
#include <gp_Cone.hxx>
#include <gp_Torus.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <GeomAbs_SurfaceType.hxx>
#include <gp_Ax3.hxx>
#include <gp_Lin.hxx>
#include <IntSurf_Quadric.hxx>

void bind_IntSurf_Quadric(py::module &mod){

py::class_<IntSurf_Quadric, std::unique_ptr<IntSurf_Quadric>> cls_IntSurf_Quadric(mod, "IntSurf_Quadric", "None");

// Constructors
cls_IntSurf_Quadric.def(py::init<>());
cls_IntSurf_Quadric.def(py::init<const gp_Pln &>(), py::arg("P"));
cls_IntSurf_Quadric.def(py::init<const gp_Cylinder &>(), py::arg("C"));
cls_IntSurf_Quadric.def(py::init<const gp_Sphere &>(), py::arg("S"));
cls_IntSurf_Quadric.def(py::init<const gp_Cone &>(), py::arg("C"));
cls_IntSurf_Quadric.def(py::init<const gp_Torus &>(), py::arg("T"));

// Fields

// Methods
// cls_IntSurf_Quadric.def_static("operator new_", (void * (*)(size_t)) &IntSurf_Quadric::operator new, "None", py::arg("theSize"));
// cls_IntSurf_Quadric.def_static("operator delete_", (void (*)(void *)) &IntSurf_Quadric::operator delete, "None", py::arg("theAddress"));
// cls_IntSurf_Quadric.def_static("operator new[]_", (void * (*)(size_t)) &IntSurf_Quadric::operator new[], "None", py::arg("theSize"));
// cls_IntSurf_Quadric.def_static("operator delete[]_", (void (*)(void *)) &IntSurf_Quadric::operator delete[], "None", py::arg("theAddress"));
// cls_IntSurf_Quadric.def_static("operator new_", (void * (*)(size_t, void *)) &IntSurf_Quadric::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntSurf_Quadric.def_static("operator delete_", (void (*)(void *, void *)) &IntSurf_Quadric::operator delete, "None", py::arg(""), py::arg(""));
cls_IntSurf_Quadric.def("SetValue", (void (IntSurf_Quadric::*)(const gp_Pln &)) &IntSurf_Quadric::SetValue, "None", py::arg("P"));
cls_IntSurf_Quadric.def("SetValue", (void (IntSurf_Quadric::*)(const gp_Cylinder &)) &IntSurf_Quadric::SetValue, "None", py::arg("C"));
cls_IntSurf_Quadric.def("SetValue", (void (IntSurf_Quadric::*)(const gp_Sphere &)) &IntSurf_Quadric::SetValue, "None", py::arg("S"));
cls_IntSurf_Quadric.def("SetValue", (void (IntSurf_Quadric::*)(const gp_Cone &)) &IntSurf_Quadric::SetValue, "None", py::arg("C"));
cls_IntSurf_Quadric.def("SetValue", (void (IntSurf_Quadric::*)(const gp_Torus &)) &IntSurf_Quadric::SetValue, "None", py::arg("T"));
cls_IntSurf_Quadric.def("Distance", (Standard_Real (IntSurf_Quadric::*)(const gp_Pnt &) const) &IntSurf_Quadric::Distance, "None", py::arg("P"));
cls_IntSurf_Quadric.def("Gradient", (gp_Vec (IntSurf_Quadric::*)(const gp_Pnt &) const) &IntSurf_Quadric::Gradient, "None", py::arg("P"));
cls_IntSurf_Quadric.def("ValAndGrad", [](IntSurf_Quadric &self, const gp_Pnt & P, Standard_Real & Dist, gp_Vec & Grad){ self.ValAndGrad(P, Dist, Grad); return Dist; }, "None", py::arg("P"), py::arg("Dist"), py::arg("Grad"));
cls_IntSurf_Quadric.def("TypeQuadric", (GeomAbs_SurfaceType (IntSurf_Quadric::*)() const) &IntSurf_Quadric::TypeQuadric, "None");
cls_IntSurf_Quadric.def("Plane", (gp_Pln (IntSurf_Quadric::*)() const) &IntSurf_Quadric::Plane, "None");
cls_IntSurf_Quadric.def("Sphere", (gp_Sphere (IntSurf_Quadric::*)() const) &IntSurf_Quadric::Sphere, "None");
cls_IntSurf_Quadric.def("Cylinder", (gp_Cylinder (IntSurf_Quadric::*)() const) &IntSurf_Quadric::Cylinder, "None");
cls_IntSurf_Quadric.def("Cone", (gp_Cone (IntSurf_Quadric::*)() const) &IntSurf_Quadric::Cone, "None");
cls_IntSurf_Quadric.def("Torus", (gp_Torus (IntSurf_Quadric::*)() const) &IntSurf_Quadric::Torus, "None");
cls_IntSurf_Quadric.def("Value", (gp_Pnt (IntSurf_Quadric::*)(const Standard_Real, const Standard_Real) const) &IntSurf_Quadric::Value, "None", py::arg("U"), py::arg("V"));
cls_IntSurf_Quadric.def("D1", (void (IntSurf_Quadric::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &IntSurf_Quadric::D1, "None", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"));
cls_IntSurf_Quadric.def("DN", (gp_Vec (IntSurf_Quadric::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer) const) &IntSurf_Quadric::DN, "None", py::arg("U"), py::arg("V"), py::arg("Nu"), py::arg("Nv"));
cls_IntSurf_Quadric.def("Normale", (gp_Vec (IntSurf_Quadric::*)(const Standard_Real, const Standard_Real) const) &IntSurf_Quadric::Normale, "None", py::arg("U"), py::arg("V"));
cls_IntSurf_Quadric.def("Parameters", [](IntSurf_Quadric &self, const gp_Pnt & P, Standard_Real & U, Standard_Real & V){ self.Parameters(P, U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "None", py::arg("P"), py::arg("U"), py::arg("V"));
cls_IntSurf_Quadric.def("Normale", (gp_Vec (IntSurf_Quadric::*)(const gp_Pnt &) const) &IntSurf_Quadric::Normale, "None", py::arg("P"));

// Enums

}